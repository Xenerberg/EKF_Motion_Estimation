% -------------------------------------------------------------------
%  Generated by MATLAB on 2-Aug-2016 02:37:52
%  MATLAB version: 8.5.0.197613 (R2015a)
% -------------------------------------------------------------------
                                                 

Cov_nu = ...
  [0.005 0 0 0;
   0 0.005 0 0;
   0 0 0.005 0;
   0 0 0 0.005];

Cov_r = ...
  [0.003 0 0;
   0 0.003 0;
   0 0 0.003];
i_xx = 4;

i_yy = 8;

i_zz = 5;

ita = [0.5;0.5;0.5;0.5];
rho_c = [-0.00036;   -0.9865;   -0.1854];
rho = [0.04;0;0.3];
ieps = [-0.7071;0;0;0.7071];
n = 0.00;


om = struct;
om.omega_x = 0;
om.omega_y = 0;
om.omega_z = 0;

om_x_0 = 0;

om_y_0 = 0;

om_z_0 = 0;

p = [0.75; 0.125; -0.8];

p_x = 0.75;

p_x_0 = 2;

p_y = 0.125;

p_y_0 = -0.5;

p_z = -0.8;

p_z_0 = -2;

parameter_gravitation = 3.986005E+14;

q = struct;
q.q_1 = 0;
q.q_2 = 0;
q.q_3 = 0;
q.q_0 = 1;

q_0_0 = 1;

q_1_0 = 0;

q_2_0 = 0;

q_3_0 = 0;



r = struct;
r.r_x = 0;
r.r_y = 0;
r.r_z = 0;

r_dot = struct;
r_dot.r_x_dot = 0;
r_dot.r_y_dot = 0;
r_dot.r_z_dot = 0;

r_dot_x_0 = 0;

r_dot_y_0 = 0;

r_dot_z_0 = 0;

r_x_0 = 0;

r_y_0 = 0;

r_z_0 = 0;


sig_f = 2E-6;

sig_p = 0.0001;

sig_tau = 2.5E-5;

sig_theta = 1E-6;

t_Kalman = 0.005;

t_Sim = 0.001;

t_delay = 0;

t_delta = 0.1;

tau_1 = 0;

tau_2 = 0;

tau_3 = 0;

totalSimulationTime = 100;

X_a_0 = [0; 0; 0; 1; 0; 0; 0; 0; 0; 0; 0; 0; 0;rho_c;ieps];
X_a_0 = [0;0;0.707000000000000;0.707000000000000;0.200000000000000;-0.0200000000000000;0.000100000000000000;0.0200000000000000;-1.80000000000000;0.500000000000000;-0.0100000000000000;0.000100000000000000;0;rho_c;ieps];

X_a_0_bus = struct;
X_a_0_bus.block = [];
X_a_0_bus.busName = 'slBus5';

X_a_0_sim = struct;
X_a_0_sim.X_a_0_Model_02 = [0; 0.562543950463012; 0.78756153064821666; ...
                            0.22501758018520479; 0.1125087900926024; 0.5; ...
                            -0.1; -0.7; 2.5; 1; -1; 0.01; -0.01; 0.02];
X_a_0_sim.eulerAngles_X_a_0 = [1.9207 -0.076 2.6382];

X_a_0_struct = struct;
X_a_0_struct.q = struct;
X_a_0_struct.q.q_1 = 0;
X_a_0_struct.q.q_2 = 0;
X_a_0_struct.q.q_3 = 0;
X_a_0_struct.q.q_0 = 1;
X_a_0_struct.omega = struct;
X_a_0_struct.omega.omega_x = 0;
X_a_0_struct.omega.omega_y = 0;
X_a_0_struct.omega.omega_z = 0;
X_a_0_struct.r = struct;
X_a_0_struct.r.r_x = 0;
X_a_0_struct.r.r_y = 0;
X_a_0_struct.r.r_z = 0;
X_a_0_struct.r_dot = struct;
X_a_0_struct.r_dot.r_x_dot = 0;
X_a_0_struct.r_dot.r_y_dot = 0;
X_a_0_struct.r_dot.r_z_dot = 0;

e_force_x = 0;

e_force_y = 0;

e_force_z = 0;

W_0 = ...
  [1 0 0 0 0 0;
   0 1 0 0 0 0;
   0 0 1 0 0 0;
   0 0 0 1 0 0;
   0 0 0 0 1 0;
   0 0 0 0 0 1];

P_d = Simulink.Signal;
P_k = Simulink.Signal;
U_n_d = Simulink.Signal;
q_nominal_d = Simulink.Signal;
flag_OOSM_update = Simulink.Signal;
lastUpdate_X_a = Simulink.Signal;
last_update_timestamp = Simulink.Signal;
x_d = Simulink.Signal;
x_k = Simulink.Signal;

P_d.Description = '';
P_d.DataType = 'double';
P_d.Min = [];
P_d.Max = [];
P_d.DocUnits = '';
P_d.Dimensions = [18 18];
P_d.DimensionsMode = 'auto';
P_d.Complexity = 'auto';
P_d.SampleTime = -1;
P_d.SamplingMode = 'auto';
P_d.InitialValue = '';



P_k.Description = '';
P_k.DataType = 'double';
P_k.Min = [];
P_k.Max = [];
P_k.DocUnits = '';
P_k.Dimensions = [18 18];
P_k.DimensionsMode = 'auto';
P_k.Complexity = 'auto';
P_k.SampleTime = -1;
P_k.SamplingMode = 'auto';
P_k.InitialValue = '';


U_n_d.Description = '';
U_n_d.DataType = 'double';
U_n_d.Min = [];
U_n_d.Max = [];
U_n_d.DocUnits = '';
U_n_d.Dimensions = [18 18];
U_n_d.DimensionsMode = 'auto';
U_n_d.Complexity = 'auto';
U_n_d.SampleTime = -1;
U_n_d.SamplingMode = 'auto';
U_n_d.InitialValue = '';





q_nominal_d.Description = '';
q_nominal_d.DataType = 'double';
q_nominal_d.Min = [];
q_nominal_d.Max = [];
q_nominal_d.DocUnits = '';
q_nominal_d.Dimensions = [4 1];
q_nominal_d.DimensionsMode = 'auto';
q_nominal_d.Complexity = 'auto';
q_nominal_d.SampleTime = -1;
q_nominal_d.SamplingMode = 'auto';
q_nominal_d.InitialValue = '';


flag_OOSM_update.Description = '';
flag_OOSM_update.DataType = 'boolean';
flag_OOSM_update.Min = [];
flag_OOSM_update.Max = [];
flag_OOSM_update.DocUnits = '';
flag_OOSM_update.Dimensions = 1;
flag_OOSM_update.DimensionsMode = 'auto';
flag_OOSM_update.Complexity = 'auto';
flag_OOSM_update.SampleTime = -1;
flag_OOSM_update.SamplingMode = 'auto';
flag_OOSM_update.InitialValue = '';

flag_queue = Simulink.Signal;

flag_queue.Description = '';
flag_queue.DataType = 'auto';
flag_queue.Min = [];
flag_queue.Max = [];
flag_queue.DocUnits = '';
flag_queue.Dimensions = 1;
flag_queue.DimensionsMode = 'Fixed';
flag_queue.Complexity = 'auto';
flag_queue.SampleTime = -1;
flag_queue.SamplingMode = 'auto';
flag_queue.InitialValue = '';





lastUpdate_X_a.Description = '';
lastUpdate_X_a.DataType = 'auto';
lastUpdate_X_a.Min = [];
lastUpdate_X_a.Max = [];
lastUpdate_X_a.DocUnits = '';
lastUpdate_X_a.Dimensions = -1;
lastUpdate_X_a.DimensionsMode = 'auto';
lastUpdate_X_a.Complexity = 'auto';
lastUpdate_X_a.SampleTime = -1;
lastUpdate_X_a.SamplingMode = 'auto';
lastUpdate_X_a.InitialValue = 'X_a_0';



last_update_timestamp.Description = '';
last_update_timestamp.DataType = 'double';
last_update_timestamp.Min = [];
last_update_timestamp.Max = [];
last_update_timestamp.DocUnits = '';
last_update_timestamp.Dimensions = 1;
last_update_timestamp.DimensionsMode = 'Fixed';
last_update_timestamp.Complexity = 'auto';
last_update_timestamp.SampleTime = -1;
last_update_timestamp.SamplingMode = 'auto';
last_update_timestamp.InitialValue = '0';





x_d.Description = '';
x_d.DataType = 'double';
x_d.Min = [];
x_d.Max = [];
x_d.DocUnits = '';
x_d.Dimensions = [18 1];
x_d.DimensionsMode = 'auto';
x_d.Complexity = 'auto';
x_d.SampleTime = -1;
x_d.SamplingMode = 'auto';
x_d.InitialValue = '';



x_k.Description = '';
x_k.DataType = 'double';
x_k.Min = [];
x_k.Max = [];
x_k.DocUnits = '';
x_k.Dimensions = [20 1];
x_k.DimensionsMode = 'auto';
x_k.Complexity = 'auto';
x_k.SampleTime = -1;
x_k.SamplingMode = 'auto';
x_k.InitialValue = '';

P_0 = 0.5*eye(18,18);
P_0(13:18,13:18) = 0.0005*eye(6,6);