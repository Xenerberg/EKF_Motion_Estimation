classdef SysObjVREP_1_Write < matlab.System &  matlab.system.mixin.CustomIcon & matlab.system.mixin.Propagates
% SysObjVREP - connect to VREP and execute Remote API functions
%

%#codegen 
% Copyright 2013 The MathWorks, Inc.
  properties(Nontunable)
    
    ObjectsInScene = 'default'; 
    sceneFileName= '';
    m_ControlObjects={};    
    m_InitialControllablePose = {};
  end

  properties (Access = private)
    % Pre-computed constants.
    m_NumControllableObjects=0;    
    m_vrep;
    m_clientID;
    m_h_Objects_Scene;
    m_h_consoleWindow;
    
    
  end

  
  

  
  properties (DiscreteState) 
      m_position;
      m_euler;
  end
  
  methods
    function obj = SysObjVREP_1_Write(varargin)
            
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
            obj.m_vrep = remApi('remoteApi');%With default prototype file (remoteApiProto.m)
            obj.m_vrep.simxFinish(-1);%Close already existing connections
            obj.m_clientID = obj.m_vrep.simxStart('127.0.0.1',19997,true,true,5000,5);
            if isa(obj.m_vrep,'remApi')
                disp('API library loaded...');
                if obj.m_clientID < 0
                    warning('V-REP link failed. Client ID = %d. Start V-REP.\n',obj.m_clientID);
                    %obj.m_vrep = [];
                else
                    fprintf('V-REP link successful.Client ID = %d\n',obj.m_clientID);
                    obj.m_vrep.simxAddStatusbarMessage(obj.m_clientID,'Server connected to SIMULINK',obj.m_vrep.simx_opmode_blocking);%Print to V-Rep that Client is connected
                    
                    
                    [~,obj.m_h_Objects_Scene, ~, ~, obj.ObjectsInScene] = obj.m_vrep.simxGetObjectGroupData(obj.m_clientID,obj.m_vrep.sim_appobj_object_type,0,obj.m_vrep.simx_opmode_blocking);
                    obj.ObjectsInScene = obj.ObjectsInScene(:,1);
                    modelName = bdroot;
                    
                    parentHandle = Simulink.Mask.get(strcat(modelName,'/VREP_SIMULINK_LINK'));
                    objectsParameter = parentHandle.getParameter('ObjectsInScene');
                    objectsParameter.set('TypeOptions',obj.ObjectsInScene);
                    
                    
                end
            end               
    end
    function set.sceneFileName(obj,varargin)
        obj.sceneFileName = varargin{1};
        if ~(isempty(obj.sceneFileName))
           string_filename = strcat(cd,sprintf('\\%s',obj.sceneFileName));           
           return_msg = obj.m_vrep.simxLoadScene(obj.m_clientID,string_filename,0,obj.m_vrep.simx_opmode_blocking);
           if return_msg ~= 0
              error('Problem in loading scene file. Try again.'); 
           end
        end
    end
    
    function set.m_ControlObjects(obj,varargin)
        if isempty(char(varargin{1}))
           obj.m_NumControllableObjects = 0; 
           obj.m_ControlObjects = cell(0);
        else
            if ~(size(varargin{1},2)==2)
                error('Control objects format is incorrect.');
            end

            for iCount = 1:size(varargin{1},1)
               qualifier = char(varargin{1}(iCount,2));
               switch(qualifier)
                   case 'Parent'
                   case 'Abs'
                   case 'Joint'
                   otherwise
                       error('Pose reference:(%s) is incorrect.',qualifier);
               end
            end
            obj.m_ControlObjects = varargin{1};
            obj.m_NumControllableObjects = size(varargin{1},1);
        end
        
    end
    function set.m_ObserveObjects(obj,varargin)
        if isempty(char(varargin{1}))
           obj.m_ObserveObjects  = cell(0);
           obj.m_NumObservableObjects = 0;
        else
            obj.m_ObserveObjects = varargin{1};            
            for iCount = 1:size(varargin{1},1)
               if ~(size(varargin{1},2)==2)
                %error('Observing objects format is incorrect.');
               end
               qualifier = char(varargin{1}(iCount,2));
               switch(qualifier)
                   case 'Image'
                   case 'Pose'   
                   case 'Joint'
                   otherwise
                       error('Data type of observable:(%s) is incorrect.',qualifier);
               end
            end
            obj.m_NumObservableObjects = size(varargin{1},1);
        end
    end
    function set.m_InitialControllablePose(obj,varargin)
       if (isempty((varargin{1})))
           obj.m_InitialControllablePose = cell(0);
       else
           if (obj.m_NumControllableObjects == 0)
              error('There is no controllable object to assign initial pose.'); 
           end
           for iCount = 1:length(varargin{1}(:))

              if ~isa(cell2mat(varargin{1}(iCount)),'double')
                 error('Incorrect pose datatype:%s.', mat2str(cell2mat(varargin{1}(iCount))));
              end
              if ~(length(cell2mat(varargin{1}(iCount))) == 6)
                   error('Incorrect pose: %s',mat2str(cell2mat(varargin{1}(iCount))));
              end
           end
       end

       
       
       obj.m_InitialControllablePose = varargin{1};   
    end
    
    
        
        
  end
  
  methods(Static, Access=protected)
      
      function header = getHeaderImpl
          % Define header for the System block dialog box.
            header = matlab.system.display.Header('SysObjVREP_1','Title','V-REP Client-Server link');
      end
      
      function group = getPropertyGroupsImpl(obj)
            % Define section for properties in System block dialog box.
            group = matlab.system.display.Section(mfilename('class'));
      end
  
  end
  
  methods(Access=protected)

      %% Common functions  
      
        function setupImpl(obj)
            % Implement tasks that need to be performed only once,
            % such as pre-computed constants.
             
            [~,obj.m_h_Objects_Scene, ~, ~, stringData] = obj.m_vrep.simxGetObjectGroupData(obj.m_clientID,obj.m_vrep.sim_appobj_object_type,0,obj.m_vrep.simx_opmode_blocking);
            
            
            %Set initial conditions
            qualifier = -1;
            
            for i=1:obj.m_NumControllableObjects
                string_objectname = char(obj.m_ControlObjects(i,1));
                string_mode = char(obj.m_ControlObjects(i,2));
                if strcmp(string_mode,'Parent')==1 && strcmp(string_mode,'Abs')==1
                    switch(string_mode)
                        case 'Parent'
                            qualifier = obj.m_vrep.sim_handle_parent;
                        case 'Abs'
                            qualifier = -1;
                        otherwise
                            qualifier = -1;

                    end
                    [return_msg,m_h_object] = obj.m_vrep.simxGetObjectHandle(obj.m_clientID,string_objectname,obj.m_vrep.simx_opmode_blocking);
                    if return_msg ~= 0
                       error('Error in retrieving handle for object:%s',string_objectname); 
                    end
                    initialPose = cell2mat(obj.m_InitialControllablePose(i));
                    initialOrientation = initialPose(4:6);
                    initialPosition = initialPose(1:3);
                    obj.m_vrep.simxSetObjectOrientation(obj.m_clientID,m_h_object,qualifier,initialOrientation, obj.m_vrep.simx_opmode_blocking);        
                    obj.m_vrep.simxSetObjectPosition(obj.m_clientID,m_h_object,qualifier,initialPosition, obj.m_vrep.simx_opmode_blocking);
                end
            end
            
            
            [~,obj.m_h_consoleWindow] =  obj.m_vrep.simxAuxiliaryConsoleOpen(obj.m_clientID,'SIMULINK-VREP console',200,31,[],[],[0 1 0],[0 0 0],obj.m_vrep.simx_opmode_blocking);%Open a new console window
            
            %enable synchronous mode on client    
            obj.m_vrep.simxSynchronous(obj.m_clientID,true);   
            %start simulation
            obj.m_vrep.simxStartSimulation(obj.m_clientID,obj.m_vrep.simx_opmode_blocking);
            
        end
        function releaseImpl(obj)
            obj.m_vrep.simxAuxiliaryConsoleClose(obj.m_clientID,obj.m_h_consoleWindow,obj.m_vrep.simx_opmode_blocking);%Open a new console window
            obj.m_vrep.simxStopSimulation(obj.m_clientID, obj.m_vrep.simx_opmode_blocking);
            obj.m_vrep.simxFinish(obj.m_clientID);
        end
     
      
      function [varargout] = stepImpl(obj,poseInputs,jointAngles)
            jointCount = 0;
            %obj.m_vrep.simxGetPingTime(obj.m_clientID);%Ensures data correctness throught triggers
            [cmd_time] = obj.m_vrep.simxGetLastCmdTime(obj.m_clientID);
            sim_time = get_param(bdroot,'SimulationTime');
            %Problem with Float point number comparisons. (1% of VREP
            %sampling time)
            %fprintf('LastCmdTime(VREP):%f; SimTime(SimulationTime):%f\n',cmd_time/1000,sim_time);
            if (abs(sim_time - (cmd_time/1000)) > 0.01*0.05) 
                %error('Error in simulation syncrhonization.\nLastCmdTime(VREP):%f; SimTime(SimulationTime):%f\n',cmd_time/1000,sim_time);
                
            end
            if (length(poseInputs) ~= 6*obj.m_NumControllableObjects)
               %error('Input pose and Number of controllable objets mismatch.\nInput pose: %d for Num Of Controllable objects:%d',length(poseInputs),obj.m_NumControllableObjects);
            end
            for iCount = 1:obj.m_NumControllableObjects

               
                string_objectname = char(obj.m_ControlObjects(iCount,1));                
                [return_msg,m_h_object] = obj.m_vrep.simxGetObjectHandle(obj.m_clientID,string_objectname,obj.m_vrep.simx_opmode_blocking);
                if return_msg ~= 0
                   error('Error in retrieving handle for object:%s',string_objectname); 
                end
                string_mode = char(obj.m_ControlObjects(iCount,2));
                if strcmp(string_mode,'Parent')==1 || strcmp(string_mode,'Abs')==1 
                    pose = poseInputs(iCount*6-5:iCount*6);
                    position = pose(1:3);
                    orientation = pose(4:6);
                    switch(string_mode)
                        case 'Parent'
                            qualifier = obj.m_vrep.sim_handle_parent;
                        case 'Abs'
                            qualifier = -1;
                        otherwise
                            qualifier = -1;

                    end

                    return_1 = obj.m_vrep.simxSetObjectOrientation(obj.m_clientID,m_h_object,qualifier,orientation, obj.m_vrep.simx_opmode_blocking);
                    if return_1 ~= 0
                        error('Error in assigning position for %s',string_objectname);
                    end

                    return_2 = obj.m_vrep.simxSetObjectPosition(obj.m_clientID,m_h_object,qualifier,position, obj.m_vrep.simx_opmode_blocking);
                    if return_2 ~= 0
                        error('Error in assigning orientation for %s',string_objectname);
                    end
                end
                
                if strcmp(string_mode, 'Joint')==1
                    jointCount = jointCount + 1;
                    [rtrn] = obj.m_vrep.simxSetJointTargetVelocity(obj.m_clientID,m_h_object,jointAngles(jointCount),obj.m_vrep.simx_opmode_blocking);
                    if rtrn ~= 0
                        error('Error in setting Joint velocity');
                    end
                end
            
            end
          
            obj.m_vrep.simxSynchronousTrigger(obj.m_clientID);
            if (obj.m_NumObservableObjects == 0)
                varargout = -1;
            else
                jointCount = 0;
                j_1 = zeros(6,1);
                for iCount = 1:obj.m_NumObservableObjects
                    string_objectname = char(obj.m_ObserveObjects(iCount,1));
                
                    [return_msg,m_h_object] = obj.m_vrep.simxGetObjectHandle(obj.m_clientID,string_objectname,obj.m_vrep.simx_opmode_blocking);
                    if return_msg ~= 0
                        error('Error in retrieving object handle for %s',string_objectname);
                    end
                    if strcmp(obj.m_ObserveObjects(iCount,2),'Image') == 1
                        [return_msg, res, imageOut] = obj.m_vrep.simxGetVisionSensorImage2(obj.m_clientID,m_h_object,0,obj.m_vrep.simx_opmode_blocking);
                        if return_msg ~= 0
                            error('Error in retrieving image. Error code:%d',return_msg);
                        end
                        varargout{iCount} = rgb2gray(imageOut);
                    end
                    if strcmp(obj.m_ObserveObjects(iCount,2),'Pose') == 1
                        [return_msg,m_h_object_rel] = obj.m_vrep.simxGetObjectHandle(obj.m_clientID,char(obj.m_ObserveObjects(iCount,3)),obj.m_vrep.simx_opmode_blocking);
                        [rtrn,ee_pos] = obj.m_vrep.simxGetObjectPosition(obj.m_clientID, m_h_object,m_h_object_rel,obj.m_vrep.simx_opmode_blocking);            
                        [rtrn,temp] = obj.m_vrep.simxGetObjectOrientation(obj.m_clientID, m_h_object,m_h_object_rel,obj.m_vrep.simx_opmode_blocking);                       
                        
                        if temp(1) < 0
                            %temp(1) = 2*pi + temp(1);
                        end    
                        if temp(3) < 0
                            %temp(3) = 2*pi + temp(3);
                        end 
                        if iCount == 2
                            str_print = sprintf('a: %f, b: %f, c:%f\n',temp(1)*180/pi,temp(2)*180/pi,temp(3)*180/pi);
                            obj.m_vrep.simxAuxiliaryConsolePrint(obj.m_clientID,obj.m_h_consoleWindow, str_print,obj.m_vrep.simx_opmode_blocking);
                        end
                        
                                            
                        
                        temp = angle2dcm(temp(1),temp(2),temp(3),'XYZ')';                        
                        temp = dcm2quat(temp');
                        %temp = angle2quat(temp(1),temp(2),temp(3),'XYZ');
                        if temp(1) < 0
                           temp = temp; 
                        end
                        ee_orient = [temp(2:4)';temp(1)];
                        varargout{iCount} = [ee_pos';ee_orient];
                    end
                    
                    if strcmp(obj.m_ObserveObjects(iCount,2),'Joint') == 1
                        jointCount = jointCount + 1;
                        [rtrn, j_1(jointCount)] = obj.m_vrep.simxGetJointPosition(obj.m_clientID, m_h_object, obj.m_vrep.simx_opmode_blocking);
                        varargout{iCount} = j_1(jointCount);
                    end
                    
                end
                
            end
            %y = [return_1,return_2];    
            
      end
    
      function num = getNumInputsImpl(~)
          num = 2;
      end
    
      function num = getNumOutputsImpl(obj)
          num = obj.m_NumObservableObjects;
      end

      function icon = getIconImpl(~)
          icon = sprintf('V-REP');          
      end
        
        function varargout = getInputNamesImpl(obj)
            inputCount = 2;
            for i=1:inputCount
               varargout{i} = sprintf('Control(%d)',i);
            end
        end
        function varargout = getOutputNamesImpl(obj)
           outputCount = obj.m_NumObservableObjects;
           for i=1:outputCount
               varargout{i} = sprintf('Observe(%d)',i);
           end
        end
        %Propagates Implementation
        function varargout = getOutputSizeImpl(obj)
           outputObjectCount = obj.m_NumObservableObjects;
           varargout = cell(outputObjectCount);
           varargout{1} = 6*outputObjectCount;
           if (outputObjectCount == 0)
               varargout{1} = 1;
           end
           for iCount = 1:obj.m_NumObservableObjects
              string_mode = char(obj.m_ObserveObjects(iCount,2));
              switch(string_mode)
                  case 'Image'
                      varargout{iCount} = [512,512];
                  case 'Pose'
                      varargout{iCount} = [7,1];
                  case 'Joint'
                      varargout{iCount} = [1,1];
              end
                  
           end
           
        end
        function varargout = getOutputDataTypeImpl(obj)
           outputCount = obj.m_NumObservableObjects;
           varargout= cell(outputCount);
           for i=1:outputCount
              varargout{i} = 'double'; 
           end
           for iCount = 1:obj.m_NumObservableObjects
              string_mode = char(obj.m_ObserveObjects(iCount,2));
              switch(string_mode)
                  case 'Image'
                      varargout{iCount} = 'uint8';
                  case 'Pose'
                      varargout{iCount} = 'single';   
                  case 'Joint'
                      varargout{iCount} = 'double';
              end
                  
           end
           
        end
        function varargout= isOutputComplexImpl(obj)
           outputCount = obj.m_NumObservableObjects;
           varargout= cell(outputCount);
           for i=1:outputCount
              varargout{i} = false; 
           end 
        end
        function varargout = isOutputFixedSizeImpl(obj)
           outputCount = obj.m_NumObservableObjects;
           varargout= cell(outputCount);
           for i=1:outputCount
              varargout{i} = true; 
           end  
        end
        function [sz,dt,cp] = getDiscreteStateSpecificationImpl(~,name)
           switch(name)
               case 'm_position'
                   sz = [3,1];
                   dt = 'double';
                   cp = false;
               case 'm_euler'
                   sz = [3,1];
                   dt = 'double';
                   cp = false;  
           end
        end
   
  end
end
