clear all;close all;
vrep = remApi('remoteApi');
vrep.simxFinish(-1); %Close connections that exist.
clientID = vrep.simxStart('127.0.0.1',19997,true,true,5000,5);

if clientID > -1
   [~,m_h_consoleWindow] =  vrep.simxAuxiliaryConsoleOpen(clientID,'SIMULINK-VREP console',200,31,[],[],[0 1 0],[0 0 0],vrep.simx_opmode_blocking);%Open a new console window
   [~,Objects_Scene, ~, ~, ObjectsInScene] = vrep.simxGetObjectGroupData(clientID,vrep.sim_appobj_object_type,0,vrep.simx_opmode_blocking); 
   ObjectsInScene = ObjectsInScene(:,1);
   h_cube =  Objects_Scene(13);
   vrep.simxSynchronous(clientID,true)   
   %Start simulation 
   vrep.simxStartSimulation(clientID,vrep.simx_opmode_blocking);
   b = linspace(0,4*pi,200);
   a = linspace(0,pi/3,200);
   c = fliplr(a);
   for iCount = 1:length(b)
      %vrep.simxSetObjectOrientation(clientID,h_cube,-1,[(a(iCount)),b(iCount),c(iCount)],vrep.simx_opmode_blocking);   
      vrep.simxSetObjectOrientation(clientID,h_cube,-1,[0,b(iCount),0],vrep.simx_opmode_blocking);   
      [rtrn,ee_targetAngles(iCount,:)] = vrep.simxGetObjectOrientation(clientID,h_cube,-1,vrep.simx_opmode_blocking);
      str_print = sprintf('a: %f, b: %f, c:%f\n',ee_targetAngles(iCount,1)*180/pi,ee_targetAngles(iCount,2)*180/pi,ee_targetAngles(iCount,3)*180/pi);
      vrep.simxAuxiliaryConsolePrint(clientID,m_h_consoleWindow, str_print,vrep.simx_opmode_blocking);
      %vrep.simxSynchronousTrigger(clientID); 
      %pause(0.01);
      sprintf('th: %f; ',b(iCount))
      [temp] = ExtEulDCM([ee_targetAngles(iCount,1);ee_targetAngles(iCount,2);ee_targetAngles(iCount,3)],'XYZ','int');     
      dcos(iCount,:) = [temp(1,3);temp(3,1)];
      [quat(iCount,:),s(iCount,:),tr(iCount)] = DCM2Quat_(temp);     
      %quat(iCount,:) = angle2quat(ee_targetAngles(iCount,1),ee_targetAngles(iCount,2),ee_targetAngles(iCount,3),'XYZ');
      
      %quat(iCount,:) = reshape(temp,9,1)';
   end
   %Stop simulation
   vrep.simxStopSimulation(clientID,vrep.simx_opmode_blocking);
   
   %Close connection
   vrep.simxFinish(clientID);
 
end
figure;
subplot(3,1,1);
plot(b,ee_targetAngles(:,1)*180/pi);
subplot(3,1,2)
plot(b,ee_targetAngles(:,2)*180/pi);
subplot(3,1,3);
plot(b,ee_targetAngles(:,3)*180/pi );

figure;
plot(b,quat(:,1),b,quat(:,2),b,quat(:,3),b,quat(:,4));
legend('q_1','q_2','q_3','q_0');

figure;
subplot(3,1,1);
plot(b,s(:,1));
hold all;plot(b,s(:,3));
subplot(3,1,2);
plot(b,tr);
subplot(3,1,3);
plot(b,dcos(:,1));
hold all;
plot(b,dcos(:,2));