function J_i = J_5(in1)
%J_5
%    J_I = J_5(IN1)

%    This function was generated by the Symbolic Math Toolbox version 6.2.
%    21-Feb-2017 15:56:57

q_1 = in1(:,1);
q_2 = in1(:,2);
q_3 = in1(:,3);
q_4 = in1(:,4);
q_5 = in1(:,5);
q_6 = in1(:,6);
t2 = pi.*q_1.*(1.0./1.8e2);
t3 = cos(t2);
t4 = sin(t2);
t5 = pi.*q_3.*(1.0./1.8e2);
t6 = cos(t5);
t7 = sin(t5);
t8 = pi.*q_6.*(1.0./1.8e2);
t9 = cos(t8);
t10 = sin(t8);
t11 = q_4+9.0e1;
t12 = pi.*t11.*(1.0./1.8e2);
t13 = cos(t12);
t14 = sin(t12);
t15 = q_5+1.8e2;
t16 = pi.*t15.*(1.0./1.8e2);
t17 = cos(t16);
t18 = sin(t16);
t19 = t6.^2;
t20 = t7.^2;
t21 = t19+t20;
t22 = 1.0./t21;
t23 = t9.^2;
t24 = t10.^2;
t25 = t23+t24;
t26 = 1.0./t25;
t27 = t13.^2;
t28 = t14.^2;
t29 = t27+t28;
t30 = 1.0./t29;
t31 = t17.^2;
t32 = t18.^2;
t33 = t31+t32;
t34 = 1.0./t33;
t35 = q_2+9.0e1;
t36 = pi.*t35.*(1.0./1.8e2);
t37 = cos(t36);
t38 = sin(t36);
t39 = t37.^2;
t40 = t38.^2;
t41 = t39+t40;
t42 = 1.0./t41;
t43 = t3.^2;
t44 = t4.^2;
t45 = t43+t44;
t46 = 1.0./t45;
t47 = pi.*t6.*t9.*t14.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t48 = pi.*t7.*t9.*t13.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t49 = t47+t48;
t50 = pi.*t6.*t9.*t13.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t52 = pi.*t7.*t9.*t14.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t51 = t50-t52;
t53 = t38.*t42.*t49;
t120 = t37.*t42.*t51;
t54 = t53-t120;
t55 = t38.*4.251e-1;
t56 = t6.*t38.*3.922e-1;
t57 = t7.*t37.*3.922e-1;
t58 = t6.*t14.*t38.*9.48e-2;
t59 = t7.*t14.*t37.*9.48e-2;
t60 = t7.*t13.*t38.*9.48e-2;
t61 = t6.*t14.*t18.*t37.*(3.0./4.0e1);
t62 = t6.*t13.*t18.*t38.*(3.0./4.0e1);
t63 = t7.*t13.*t18.*t37.*(3.0./4.0e1);
t100 = t6.*t13.*t37.*9.48e-2;
t101 = t7.*t14.*t18.*t38.*(3.0./4.0e1);
t64 = t55+t56+t57+t58+t59+t60+t61+t62+t63-t100-t101+7.46e-2;
t65 = pi.*t6.*t10.*t13.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t78 = pi.*t7.*t10.*t14.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t66 = t65-t78;
t67 = pi.*t6.*t10.*t14.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t68 = pi.*t7.*t10.*t13.*t18.*t22.*t26.*t30.*t34.*(1.0./1.8e2);
t69 = t67+t68;
t70 = t3.*t17.*(3.0./4.0e1);
t71 = t4.*t37.*4.251e-1;
t72 = t4.*t6.*t37.*3.922e-1;
t73 = t4.*t6.*t14.*t37.*9.48e-2;
t74 = t4.*t6.*t13.*t38.*9.48e-2;
t75 = t4.*t7.*t13.*t37.*9.48e-2;
t76 = t4.*t6.*t13.*t18.*t37.*(3.0./4.0e1);
t89 = t3.*(1.1e1./1.0e2);
t90 = t4.*t7.*t38.*3.922e-1;
t91 = t4.*t7.*t14.*t38.*9.48e-2;
t92 = t4.*t6.*t14.*t18.*t38.*(3.0./4.0e1);
t93 = t4.*t7.*t14.*t18.*t37.*(3.0./4.0e1);
t94 = t4.*t7.*t13.*t18.*t38.*(3.0./4.0e1);
t77 = t70+t71+t72+t73+t74+t75+t76-t89-t90-t91-t92-t93-t94;
t79 = t37.*t42.*t66;
t114 = t38.*t42.*t69;
t80 = t79-t114;
t81 = t4.*(1.1e1./1.0e2);
t82 = t3.*t37.*4.251e-1;
t83 = t3.*t6.*t37.*3.922e-1;
t84 = t3.*t6.*t14.*t37.*9.48e-2;
t85 = t3.*t6.*t13.*t38.*9.48e-2;
t86 = t3.*t7.*t13.*t37.*9.48e-2;
t87 = t3.*t6.*t13.*t18.*t37.*(3.0./4.0e1);
t105 = t4.*t17.*(3.0./4.0e1);
t106 = t3.*t7.*t38.*3.922e-1;
t107 = t3.*t7.*t14.*t38.*9.48e-2;
t108 = t3.*t6.*t14.*t18.*t38.*(3.0./4.0e1);
t109 = t3.*t7.*t14.*t18.*t37.*(3.0./4.0e1);
t110 = t3.*t7.*t13.*t18.*t38.*(3.0./4.0e1);
t88 = t81+t82+t83+t84+t85+t86+t87-t105-t106-t107-t108-t109-t110;
t95 = pi.*t6.*t14.*t17.*t22.*t30.*t34.*(1.0./1.8e2);
t96 = pi.*t7.*t13.*t17.*t22.*t30.*t34.*(1.0./1.8e2);
t97 = t95+t96;
t98 = pi.*t6.*t13.*t17.*t22.*t30.*t34.*(1.0./1.8e2);
t102 = pi.*t7.*t14.*t17.*t22.*t30.*t34.*(1.0./1.8e2);
t99 = t98-t102;
t103 = t38.*t42.*t97;
t104 = t103-t37.*t42.*t99;
t111 = t37.*t42.*t69;
t112 = t38.*t42.*t66;
t113 = t111+t112;
t115 = t3.*t46.*t80;
t116 = t115-pi.*t4.*t10.*t17.*t26.*t34.*t46.*(1.0./1.8e2);
t117 = t4.*t46.*t80;
t118 = pi.*t3.*t10.*t17.*t26.*t34.*t46.*(1.0./1.8e2);
t119 = t117+t118;
t121 = t4.*t46.*t54;
t122 = t4.*t6.*t14.*t18.*t38;
t123 = t4.*t7.*t14.*t18.*t37;
t124 = t4.*t7.*t13.*t18.*t38;
t125 = t122+t123+t124-t3.*t17-t4.*t6.*t13.*t18.*t37;
t142 = pi.*t3.*t9.*t17.*t26.*t34.*t46.*(1.0./1.8e2);
t126 = t121-t142;
t127 = t3.*t46.*t54;
t128 = pi.*t4.*t9.*t17.*t26.*t34.*t46.*(1.0./1.8e2);
t129 = t4.*t17;
t130 = t3.*t6.*t14.*t18.*t38;
t131 = t3.*t7.*t14.*t18.*t37;
t132 = t3.*t7.*t13.*t18.*t38;
t133 = t129+t130+t131+t132-t3.*t6.*t13.*t18.*t37;
t134 = t127+t128;
t135 = t37.*t42.*t49;
t136 = t38.*t42.*t51;
t137 = t135+t136;
t138 = t6.*t14.*t18.*t37;
t139 = t6.*t13.*t18.*t38;
t140 = t7.*t13.*t18.*t37;
t141 = t138+t139+t140-t7.*t14.*t18.*t38;
J_i = [-t64.*t137+t77.*t126+t88.*t134+t37.*t42.*t49.*7.46e-2+t38.*t42.*t51.*7.46e-2-pi.*t9.*t17.*t26.*t34.*6.111111111111111e-4+pi.*t9.*t13.*t18.*t26.*t30.*t34.*2.178888888888889e-3+pi.*t6.*t9.*t13.*t18.*t22.*t26.*t30.*t34.*2.361666666666667e-3-pi.*t7.*t9.*t14.*t18.*t22.*t26.*t30.*t34.*2.361666666666667e-3;t64.*t113+t77.*t119+t88.*t116-t38.*t42.*t66.*7.46e-2-t37.*t42.*t69.*7.46e-2+pi.*t10.*t17.*t26.*t34.*6.111111111111111e-4-pi.*t10.*t13.*t18.*t26.*t30.*t34.*2.178888888888889e-3-pi.*t6.*t10.*t13.*t18.*t22.*t26.*t30.*t34.*2.361666666666667e-3+pi.*t7.*t10.*t14.*t18.*t22.*t26.*t30.*t34.*2.361666666666667e-3;-t77.*(t4.*t46.*t104+pi.*t3.*t18.*t34.*t46.*(1.0./1.8e2))-t88.*(t3.*t46.*t104-pi.*t4.*t18.*t34.*t46.*(1.0./1.8e2))+t64.*(t37.*t42.*t97+t38.*t42.*t99)-pi.*t18.*t34.*6.111111111111111e-4-t37.*t42.*t97.*7.46e-2-t38.*t42.*t99.*7.46e-2-pi.*t13.*t17.*t30.*t34.*2.178888888888889e-3-pi.*t6.*t13.*t17.*t22.*t30.*t34.*2.361666666666667e-3+pi.*t7.*t14.*t17.*t22.*t30.*t34.*2.361666666666667e-3;t119.*t125+t116.*t133-t113.*t141;-t125.*t126-t133.*t134-t137.*t141;-t137.*(t6.*t9.*t13.*t37-t6.*t9.*t14.*t38-t7.*t9.*t13.*t38-t7.*t9.*t14.*t37+t6.*t10.*t13.*t17.*t38+t6.*t10.*t14.*t17.*t37+t7.*t10.*t13.*t17.*t37-t7.*t10.*t14.*t17.*t38)-t126.*(t3.*t10.*t18+t4.*t6.*t9.*t13.*t38+t4.*t6.*t9.*t14.*t37+t4.*t7.*t9.*t13.*t37-t4.*t7.*t9.*t14.*t38-t4.*t6.*t10.*t13.*t17.*t37+t4.*t6.*t10.*t14.*t17.*t38+t4.*t7.*t10.*t13.*t17.*t38+t4.*t7.*t10.*t14.*t17.*t37)-t134.*(-t4.*t10.*t18+t3.*t6.*t9.*t13.*t38+t3.*t6.*t9.*t14.*t37+t3.*t7.*t9.*t13.*t37-t3.*t7.*t9.*t14.*t38-t3.*t6.*t10.*t13.*t17.*t37+t3.*t6.*t10.*t14.*t17.*t38+t3.*t7.*t10.*t13.*t17.*t38+t3.*t7.*t10.*t14.*t17.*t37)];
