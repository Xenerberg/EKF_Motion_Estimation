function J_i = J_1(in1)
%J_1
%    J_I = J_1(IN1)

%    This function was generated by the Symbolic Math Toolbox version 6.2.
%    21-Feb-2017 15:55:14

q_1 = in1(:,1);
q_2 = in1(:,2);
q_3 = in1(:,3);
q_4 = in1(:,4);
q_5 = in1(:,5);
q_6 = in1(:,6);
t2 = pi.*q_1.*(1.0./1.8e2);
t3 = cos(t2);
t4 = sin(t2);
t5 = pi.*q_6.*(1.0./1.8e2);
t6 = cos(t5);
t7 = sin(t5);
t8 = q_4+9.0e1;
t9 = pi.*t8.*(1.0./1.8e2);
t10 = cos(t9);
t11 = sin(t9);
t12 = t6.^2;
t13 = t7.^2;
t14 = t12+t13;
t15 = 1.0./t14;
t16 = t10.^2;
t17 = t11.^2;
t18 = t16+t17;
t19 = 1.0./t18;
t20 = q_5+1.8e2;
t21 = pi.*t20.*(1.0./1.8e2);
t22 = cos(t21);
t23 = sin(t21);
t24 = pi.*q_3.*(1.0./1.8e2);
t25 = cos(t24);
t26 = sin(t24);
t27 = t22.^2;
t28 = t23.^2;
t29 = t27+t28;
t30 = 1.0./t29;
t31 = t25.^2;
t32 = t26.^2;
t33 = t31+t32;
t34 = 1.0./t33;
t35 = q_2+9.0e1;
t36 = pi.*t35.*(1.0./1.8e2);
t37 = cos(t36);
t38 = sin(t36);
t39 = t7.*t10.*t15.*t19;
t53 = t6.*t11.*t15.*t19.*t22.*t30;
t40 = t39-t53;
t41 = t7.*t11.*t15.*t19;
t42 = t6.*t10.*t15.*t19.*t22.*t30;
t43 = t41+t42;
t44 = t37.^2;
t45 = t38.^2;
t46 = t44+t45;
t47 = 1.0./t46;
t48 = t3.^2;
t49 = t4.^2;
t50 = t48+t49;
t51 = 1.0./t50;
t52 = t25.*t34.*t43;
t54 = t26.*t34.*t40;
t55 = t52+t54;
t56 = t37.*t47.*t55;
t57 = t25.*t34.*t40;
t116 = t26.*t34.*t43;
t58 = t57-t116;
t59 = t38.*t47.*t58;
t60 = t56+t59;
t61 = t6.*t10.*t15.*t19;
t62 = t7.*t11.*t15.*t19.*t22.*t30;
t63 = t61+t62;
t64 = t6.*t11.*t15.*t19;
t74 = t7.*t10.*t15.*t19.*t22.*t30;
t65 = t64-t74;
t66 = t3.*t22.*(3.0./4.0e1);
t67 = t4.*t37.*4.251e-1;
t68 = t4.*t25.*t37.*3.922e-1;
t69 = t4.*t11.*t25.*t37.*9.48e-2;
t70 = t4.*t10.*t25.*t38.*9.48e-2;
t71 = t4.*t10.*t26.*t37.*9.48e-2;
t72 = t4.*t10.*t23.*t25.*t37.*(3.0./4.0e1);
t91 = t3.*(1.1e1./1.0e2);
t92 = t4.*t26.*t38.*3.922e-1;
t93 = t4.*t11.*t26.*t38.*9.48e-2;
t94 = t4.*t11.*t23.*t25.*t38.*(3.0./4.0e1);
t95 = t4.*t11.*t23.*t26.*t37.*(3.0./4.0e1);
t96 = t4.*t10.*t23.*t26.*t38.*(3.0./4.0e1);
t73 = t66+t67+t68+t69+t70+t71+t72-t91-t92-t93-t94-t95-t96;
t75 = t25.*t34.*t65;
t76 = t26.*t34.*t63;
t77 = t75+t76;
t78 = t37.*t47.*t77;
t79 = t25.*t34.*t63;
t110 = t26.*t34.*t65;
t80 = t79-t110;
t81 = t38.*t47.*t80;
t82 = t78+t81;
t83 = t4.*(1.1e1./1.0e2);
t84 = t3.*t37.*4.251e-1;
t85 = t3.*t25.*t37.*3.922e-1;
t86 = t3.*t11.*t25.*t37.*9.48e-2;
t87 = t3.*t10.*t25.*t38.*9.48e-2;
t88 = t3.*t10.*t26.*t37.*9.48e-2;
t89 = t3.*t10.*t23.*t25.*t37.*(3.0./4.0e1);
t104 = t4.*t22.*(3.0./4.0e1);
t105 = t3.*t26.*t38.*3.922e-1;
t106 = t3.*t11.*t26.*t38.*9.48e-2;
t107 = t3.*t11.*t23.*t25.*t38.*(3.0./4.0e1);
t108 = t3.*t11.*t23.*t26.*t37.*(3.0./4.0e1);
t109 = t3.*t10.*t23.*t26.*t38.*(3.0./4.0e1);
t90 = t83+t84+t85+t86+t87+t88+t89-t104-t105-t106-t107-t108-t109;
t97 = t10.*t19.*t23.*t25.*t30.*t34;
t98 = t97-t11.*t19.*t23.*t26.*t30.*t34;
t99 = t37.*t47.*t98;
t100 = t11.*t19.*t23.*t25.*t30.*t34;
t101 = t10.*t19.*t23.*t26.*t30.*t34;
t102 = t100+t101;
t103 = t99-t38.*t47.*t102;
t111 = pi.*t3.*t51.*t82.*(1.0./1.8e2);
t112 = t111-pi.*t4.*t7.*t15.*t23.*t30.*t51.*(1.0./1.8e2);
t113 = pi.*t4.*t51.*t82.*(1.0./1.8e2);
t114 = pi.*t3.*t7.*t15.*t23.*t30.*t51.*(1.0./1.8e2);
t115 = t113+t114;
t117 = pi.*t3.*t51.*t60.*(1.0./1.8e2);
t118 = pi.*t4.*t6.*t15.*t23.*t30.*t51.*(1.0./1.8e2);
t119 = t117+t118;
t120 = t4.*t11.*t23.*t25.*t38;
t121 = t4.*t11.*t23.*t26.*t37;
t122 = t4.*t10.*t23.*t26.*t38;
t123 = t120+t121+t122-t3.*t22-t4.*t10.*t23.*t25.*t37;
t124 = pi.*t4.*t51.*t60.*(1.0./1.8e2);
t131 = pi.*t3.*t6.*t15.*t23.*t30.*t51.*(1.0./1.8e2);
t125 = t124-t131;
t126 = t4.*t22;
t127 = t3.*t11.*t23.*t25.*t38;
t128 = t3.*t11.*t23.*t26.*t37;
t129 = t3.*t10.*t23.*t26.*t38;
t130 = t126+t127+t128+t129-t3.*t10.*t23.*t25.*t37;
J_i = [t73.*t119-t90.*t125;t73.*t112-t90.*t115;t73.*(pi.*t3.*t51.*t103.*(1.0./1.8e2)-pi.*t4.*t22.*t30.*t51.*(1.0./1.8e2))-t90.*(pi.*t4.*t51.*t103.*(1.0./1.8e2)+pi.*t3.*t22.*t30.*t51.*(1.0./1.8e2));t112.*t123-t115.*t130;-t119.*t123+t125.*t130;-t119.*(t3.*t7.*t23+t4.*t6.*t10.*t25.*t38+t4.*t6.*t10.*t26.*t37+t4.*t6.*t11.*t25.*t37-t4.*t6.*t11.*t26.*t38-t4.*t7.*t10.*t22.*t25.*t37+t4.*t7.*t10.*t22.*t26.*t38+t4.*t7.*t11.*t22.*t25.*t38+t4.*t7.*t11.*t22.*t26.*t37)+t125.*(-t4.*t7.*t23+t3.*t6.*t10.*t25.*t38+t3.*t6.*t10.*t26.*t37+t3.*t6.*t11.*t25.*t37-t3.*t6.*t11.*t26.*t38-t3.*t7.*t10.*t22.*t25.*t37+t3.*t7.*t10.*t22.*t26.*t38+t3.*t7.*t11.*t22.*t25.*t38+t3.*t7.*t11.*t22.*t26.*t37)];
