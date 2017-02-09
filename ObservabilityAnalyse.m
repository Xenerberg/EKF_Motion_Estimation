syms q_0 q_1 q_2 q_3
q_v = [q_1;q_2;q_3];
R = (2*q_0^2 - 1)*eye(3,3) + 2*q_0*fn_VectorToSkewSymmetricTensor(q_v) + 2*q_v*q_v.';
