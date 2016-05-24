classdef SysObjVREP < matlab.System & matlab.system.mixin.CustomIcon
    % SysObjVREP - connect to VREP and execute Remote API functions 
    %
    % 
    
    properties
        % Public, tunable properties.
        
    end
    
    properties (Nontunable)
        % Public, non-tunable properties.
    end
    
    properties (Access = private)
        % Pre-computed constants.
        m_vrep;
        m_clientID;
        m_h_Objects_Scene;
        m_h_object;
        m_X_a_0;
        
    end
    
    properties (DiscreteState)
        m_position = zeros(3);
        m_euler = zeros(3);
    end
    
    methods
        % Constructor
        function obj = SysObjVREP(varargin)
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
            obj.m_vrep = remApi('remoteApi');%With default prototype file (remoteApiProto.m)
            obj.m_vrep.simxFinish(-1);%Close already existing connections
            obj.m_clientID = obj.m_vrep.simxStart('127.0.0.1',19997,true,true,5000,5);
            if isa(obj.m_vrep,'remApi')
                disp('API library loaded...');
                if obj.m_clientID < 0
                    fprintf('Warning: V-REP link failed. Client ID = %d. Start V-REP.\n',obj.m_clientID);
                    %obj.m_vrep = [];
                end
            end    
            
            
        end
        function delete(obj)
           obj.v_rep = []; 
        end
    end
    
    
    methods (Access = protected)
        %% Common functions        
        function matlab.system.setupImpl(obj,positionInitial,orientationInitial)
            % Implement tasks that need to be performed only once,
            % such as pre-computed constants.
            [~,obj.m_h_Objects_Scene, ~, ~, stringData] = obj.m_vrep.simxGetObjectGroupData(obj.m_clientID,obj.m_vrep.sim_appobj_object_type,0,obj.m_vrep.simx_opmode_blocking);
            obj.m_h_object = obj.m_h_Objects_Scene(16);
            obj.m_X_a_0 = load('X_a_0_Model_02');
            %Set initial conditions
            initialOrientation = [1.9207,-0.0760,2.6382];
            initialPosition = obj.m_X_a_0.X_a_0_Model_02(9:11);
            vrep.simxSetObjectOrientation(clientID,h_object,-1,initialOrientation, vrep.simx_opmode_blocking);
            vrep.simxSetObjectPosition(clientID,h_object,vrep.sim_handle_parent,initialPosition, vrep.simx_opmode_blocking);

            
        end
        
        function [] = stepImpl(obj,position,orientation)
            vrep.simxSynchronousTrigger(clientID);
            vrep.simxGetPingTime(clientID);%Ensures data correctness throught triggers
            return_1 = vrep.simxSetObjectOrientation(clientID,h_object,-1,orientation, vrep.simx_opmode_blocking);
            return_2 = vrep.simxSetObjectPosition(clientID,h_object,vrep.sim_handle_parent,position, vrep.simx_opmode_blocking);
            %y = [return_1,return_2];    
        end
        
        
   
        
        function flag = isInputSizeLockedImpl(obj,index)
            % Set true when the input size is allowed to change while the
            % system is running.
            flag = false;
        end
        function num = getNumInputsImpl(~)
            num = 3;
        end
        function num = getNumOutputsImpl(~)
            num = 0;
        end
        function [name1,name2] = getInputNamesImpl(~)
            name1 = 'Position';
            name2 = 'Orientation';
        end
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'V-REP';
        end
    end
    
    methods(Static, Access = protected)
        %% Simulink customization functions
        function header = getHeaderImpl(obj)
            % Define header for the System block dialog box.
            header = matlab.system.display.Header('SysObjVREP','Title','V-REP Client-Server link');
        end
        
        function group = getPropertyGroupsImpl(obj)
            % Define section for properties in System block dialog box.
            group = matlab.system.display.Section(mfilename('class'));
        end
    end
end
