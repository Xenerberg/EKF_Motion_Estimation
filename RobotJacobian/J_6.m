function J_i = J_6(in1)
%J_6
%    J_I = J_6(IN1)

%    This function was generated by the Symbolic Math Toolbox version 6.2.
%    21-Feb-2017 14:26:02

q_1 = in1(:,1);
q_2 = in1(:,2);
q_3 = in1(:,3);
q_4 = in1(:,4);
q_5 = in1(:,5);
q_6 = in1(:,6);
t2 = pi.*q_1.*(1.0./1.8e2);
t3 = cos(t2);
t4 = pi.*q_3.*(1.0./1.8e2);
t5 = q_2+9.0e1;
t6 = pi.*t5.*(1.0./1.8e2);
t7 = q_4+9.0e1;
t8 = pi.*t7.*(1.0./1.8e2);
t9 = cos(t4);
t10 = cos(t6);
t11 = sin(t4);
t12 = sin(t6);
t13 = pi.*q_6.*(1.0./1.8e2);
t14 = cos(t8);
t15 = t3.*t9.*t10;
t38 = t3.*t11.*t12;
t16 = t15-t38;
t17 = sin(t8);
t18 = t3.*t9.*t12;
t19 = t3.*t10.*t11;
t20 = t18+t19;
t21 = q_5+1.8e2;
t22 = pi.*t21.*(1.0./1.8e2);
t23 = cos(t13);
t24 = sin(t22);
t25 = t9.^2;
t26 = t23.^2;
t27 = t10.^2;
t28 = cos(t22);
t29 = t14.^2;
t30 = t28.^2;
t31 = sin(t13);
t32 = t17.^2;
t33 = t24.^2;
t34 = t12.^2;
t35 = t31.^2;
t36 = t11.^2;
t37 = t14.*t20;
t39 = t16.*t17;
t40 = t37+t39;
t41 = t14.*t16;
t235 = t17.*t20;
t42 = t41-t235;
t43 = t28.*t42;
t44 = sin(t2);
t45 = t24.*t44;
t46 = t43+t45;
t47 = t25.*t26.*t27.*t29.*t33;
t48 = t25.*t26.*t27.*t30.*t32;
t49 = t25.*t26.*t29.*t30.*t34;
t50 = t25.*t27.*t29.*t30.*t35;
t51 = t26.*t27.*t29.*t30.*t36;
t52 = t25.*t26.*t27.*t32.*t33;
t53 = t25.*t26.*t29.*t33.*t34;
t54 = t25.*t26.*t30.*t32.*t34;
t55 = t25.*t27.*t29.*t33.*t35;
t56 = t25.*t27.*t30.*t32.*t35;
t57 = t25.*t29.*t30.*t34.*t35;
t58 = t26.*t27.*t29.*t33.*t36;
t59 = t26.*t27.*t30.*t32.*t36;
t60 = t26.*t29.*t30.*t34.*t36;
t61 = t27.*t29.*t30.*t35.*t36;
t62 = t25.*t26.*t32.*t33.*t34;
t63 = t25.*t27.*t32.*t33.*t35;
t64 = t25.*t29.*t33.*t34.*t35;
t65 = t25.*t30.*t32.*t34.*t35;
t66 = t26.*t27.*t32.*t33.*t36;
t67 = t26.*t29.*t33.*t34.*t36;
t68 = t26.*t30.*t32.*t34.*t36;
t69 = t27.*t29.*t33.*t35.*t36;
t70 = t27.*t30.*t32.*t35.*t36;
t71 = t29.*t30.*t34.*t35.*t36;
t72 = t25.*t32.*t33.*t34.*t35;
t73 = t26.*t32.*t33.*t34.*t36;
t74 = t27.*t32.*t33.*t35.*t36;
t75 = t29.*t33.*t34.*t35.*t36;
t76 = t30.*t32.*t34.*t35.*t36;
t77 = t32.*t33.*t34.*t35.*t36;
t78 = t25.*t26.*t27.*t29.*t30;
t79 = t47+t48+t49+t50+t51+t52+t53+t54+t55+t56+t57+t58+t59+t60+t61+t62+t63+t64+t65+t66+t67+t68+t69+t70+t71+t72+t73+t74+t75+t76+t77+t78;
t80 = 1.0./t79;
t81 = t9.*t12.*t44;
t82 = t10.*t11.*t44;
t83 = t81+t82;
t84 = t9.*t10.*t44;
t128 = t11.*t12.*t44;
t85 = t84-t128;
t86 = t9.*t17.*t23.*t33.*t34.*4.251e3;
t87 = t11.*t14.*t23.*t33.*t34.*4.251e3;
t88 = t17.*t23.*t25.*t27.*t30.*3.922e3;
t89 = t17.*t23.*t27.*t30.*t36.*3.922e3;
t90 = t17.*t23.*t25.*t27.*t33.*3.922e3;
t91 = t17.*t23.*t25.*t30.*t34.*3.922e3;
t92 = t11.*t12.*t17.*t28.*t31.*7.46e2;
t93 = t17.*t23.*t27.*t33.*t36.*3.922e3;
t94 = t17.*t23.*t30.*t34.*t36.*3.922e3;
t95 = t17.*t23.*t25.*t33.*t34.*3.922e3;
t96 = t17.*t23.*t33.*t34.*t36.*3.922e3;
t97 = t23.*t25.*t27.*t29.*t30.*9.48e2;
t98 = t9.*t12.*t17.*t23.*t30.*7.46e2;
t99 = t10.*t11.*t17.*t23.*t30.*7.46e2;
t100 = t11.*t12.*t14.*t23.*t30.*7.46e2;
t101 = t23.*t27.*t29.*t30.*t36.*9.48e2;
t102 = t23.*t25.*t27.*t29.*t33.*9.48e2;
t103 = t23.*t25.*t27.*t30.*t32.*9.48e2;
t104 = t23.*t25.*t29.*t30.*t34.*9.48e2;
t105 = t9.*t12.*t17.*t23.*t33.*7.46e2;
t106 = t10.*t11.*t17.*t23.*t33.*7.46e2;
t107 = t11.*t12.*t14.*t23.*t33.*7.46e2;
t108 = t11.*t17.*t27.*t28.*t31.*4.251e3;
t109 = t23.*t27.*t29.*t33.*t36.*9.48e2;
t110 = t23.*t27.*t30.*t32.*t36.*9.48e2;
t111 = t23.*t29.*t30.*t34.*t36.*9.48e2;
t112 = t23.*t25.*t27.*t32.*t33.*9.48e2;
t113 = t23.*t25.*t29.*t33.*t34.*9.48e2;
t114 = t23.*t25.*t30.*t32.*t34.*9.48e2;
t115 = t11.*t17.*t28.*t31.*t34.*4.251e3;
t116 = t23.*t27.*t32.*t33.*t36.*9.48e2;
t117 = t23.*t29.*t33.*t34.*t36.*9.48e2;
t118 = t23.*t30.*t32.*t34.*t36.*9.48e2;
t119 = t23.*t25.*t32.*t33.*t34.*9.48e2;
t120 = t23.*t32.*t33.*t34.*t36.*9.48e2;
t121 = t9.*t17.*t23.*t27.*t30.*4.251e3;
t122 = t11.*t14.*t23.*t27.*t30.*4.251e3;
t123 = t9.*t17.*t23.*t27.*t33.*4.251e3;
t124 = t9.*t17.*t23.*t30.*t34.*4.251e3;
t125 = t11.*t14.*t23.*t30.*t34.*4.251e3;
t126 = t11.*t14.*t23.*t27.*t33.*4.251e3;
t197 = t14.*t28.*t31.*t34.*t36.*3.922e3;
t198 = t9.*t10.*t17.*t28.*t31.*7.46e2;
t199 = t9.*t12.*t14.*t28.*t31.*7.46e2;
t200 = t10.*t11.*t14.*t28.*t31.*7.46e2;
t201 = t24.*t25.*t27.*t29.*t31.*1.1e3;
t202 = t24.*t25.*t27.*t31.*t32.*1.1e3;
t203 = t24.*t25.*t29.*t31.*t34.*1.1e3;
t204 = t24.*t27.*t29.*t31.*t36.*1.1e3;
t205 = t24.*t25.*t31.*t32.*t34.*1.1e3;
t206 = t24.*t27.*t31.*t32.*t36.*1.1e3;
t207 = t24.*t29.*t31.*t34.*t36.*1.1e3;
t208 = t9.*t10.*t14.*t23.*t30.*7.46e2;
t209 = t24.*t31.*t32.*t34.*t36.*1.1e3;
t210 = t9.*t10.*t14.*t23.*t33.*7.46e2;
t211 = t9.*t14.*t27.*t28.*t31.*4.251e3;
t212 = t9.*t14.*t28.*t31.*t34.*4.251e3;
t213 = t14.*t25.*t27.*t28.*t31.*3.922e3;
t214 = t14.*t25.*t28.*t31.*t34.*3.922e3;
t215 = t14.*t27.*t28.*t31.*t36.*3.922e3;
t127 = t86+t87+t88+t89+t90+t91+t92+t93+t94+t95+t96+t97+t98+t99+t100+t101+t102+t103+t104+t105+t106+t107+t108+t109+t110+t111+t112+t113+t114+t115+t116+t117+t118+t119+t120+t121+t122+t123+t124+t125+t126-t197-t198-t199-t200-t201-t202-t203-t204-t205-t206-t207-t208-t209-t210-t211-t212-t213-t214-t215;
t129 = t14.*t85;
t227 = t17.*t83;
t130 = t129-t227;
t131 = t3.*t24;
t228 = t28.*t130;
t132 = t131-t228;
t133 = t14.*t83;
t134 = t17.*t85;
t135 = t133+t134;
t136 = t9.*t17.*t27.*t31.*t33.*4.251e3;
t137 = t9.*t17.*t30.*t31.*t34.*4.251e3;
t138 = t11.*t14.*t30.*t31.*t34.*4.251e3;
t139 = t11.*t14.*t27.*t31.*t33.*4.251e3;
t140 = t9.*t17.*t31.*t33.*t34.*4.251e3;
t141 = t11.*t14.*t31.*t33.*t34.*4.251e3;
t142 = t9.*t10.*t17.*t23.*t28.*7.46e2;
t143 = t9.*t12.*t14.*t23.*t28.*7.46e2;
t144 = t10.*t11.*t14.*t23.*t28.*7.46e2;
t145 = t23.*t24.*t25.*t27.*t29.*1.1e3;
t146 = t23.*t24.*t27.*t29.*t36.*1.1e3;
t147 = t23.*t24.*t25.*t27.*t32.*1.1e3;
t148 = t23.*t24.*t25.*t29.*t34.*1.1e3;
t149 = t17.*t25.*t27.*t30.*t31.*3.922e3;
t150 = t23.*t24.*t27.*t32.*t36.*1.1e3;
t151 = t23.*t24.*t29.*t34.*t36.*1.1e3;
t152 = t23.*t24.*t25.*t32.*t34.*1.1e3;
t153 = t17.*t25.*t27.*t31.*t33.*3.922e3;
t154 = t17.*t25.*t30.*t31.*t34.*3.922e3;
t155 = t17.*t27.*t30.*t31.*t36.*3.922e3;
t156 = t23.*t24.*t32.*t34.*t36.*1.1e3;
t157 = t17.*t25.*t31.*t33.*t34.*3.922e3;
t158 = t17.*t27.*t31.*t33.*t36.*3.922e3;
t159 = t17.*t30.*t31.*t34.*t36.*3.922e3;
t160 = t9.*t14.*t23.*t27.*t28.*4.251e3;
t161 = t17.*t31.*t33.*t34.*t36.*3.922e3;
t162 = t9.*t14.*t23.*t28.*t34.*4.251e3;
t163 = t25.*t27.*t29.*t30.*t31.*9.48e2;
t164 = t9.*t12.*t17.*t30.*t31.*7.46e2;
t165 = t10.*t11.*t17.*t30.*t31.*7.46e2;
t166 = t11.*t12.*t14.*t30.*t31.*7.46e2;
t167 = t25.*t27.*t29.*t31.*t33.*9.48e2;
t168 = t25.*t27.*t30.*t31.*t32.*9.48e2;
t169 = t25.*t29.*t30.*t31.*t34.*9.48e2;
t170 = t27.*t29.*t30.*t31.*t36.*9.48e2;
t171 = t9.*t12.*t17.*t31.*t33.*7.46e2;
t172 = t10.*t11.*t17.*t31.*t33.*7.46e2;
t173 = t11.*t12.*t14.*t31.*t33.*7.46e2;
t174 = t25.*t27.*t31.*t32.*t33.*9.48e2;
t175 = t25.*t29.*t31.*t33.*t34.*9.48e2;
t176 = t25.*t30.*t31.*t32.*t34.*9.48e2;
t177 = t27.*t29.*t31.*t33.*t36.*9.48e2;
t178 = t27.*t30.*t31.*t32.*t36.*9.48e2;
t179 = t29.*t30.*t31.*t34.*t36.*9.48e2;
t180 = t25.*t31.*t32.*t33.*t34.*9.48e2;
t181 = t27.*t31.*t32.*t33.*t36.*9.48e2;
t182 = t29.*t31.*t33.*t34.*t36.*9.48e2;
t183 = t30.*t31.*t32.*t34.*t36.*9.48e2;
t184 = t14.*t23.*t25.*t27.*t28.*3.922e3;
t185 = t31.*t32.*t33.*t34.*t36.*9.48e2;
t186 = t14.*t23.*t27.*t28.*t36.*3.922e3;
t187 = t14.*t23.*t25.*t28.*t34.*3.922e3;
t188 = t9.*t17.*t27.*t30.*t31.*4.251e3;
t189 = t14.*t23.*t28.*t34.*t36.*3.922e3;
t190 = t11.*t14.*t27.*t30.*t31.*4.251e3;
t222 = t11.*t12.*t17.*t23.*t28.*7.46e2;
t223 = t9.*t10.*t14.*t30.*t31.*7.46e2;
t224 = t9.*t10.*t14.*t31.*t33.*7.46e2;
t225 = t11.*t17.*t23.*t27.*t28.*4.251e3;
t226 = t11.*t17.*t23.*t28.*t34.*4.251e3;
t191 = t136+t137+t138+t139+t140+t141+t142+t143+t144+t145+t146+t147+t148+t149+t150+t151+t152+t153+t154+t155+t156+t157+t158+t159+t160+t161+t162+t163+t164+t165+t166+t167+t168+t169+t170+t171+t172+t173+t174+t175+t176+t177+t178+t179+t180+t181+t182+t183+t184+t185+t186+t187+t188+t189+t190-t222-t223-t224-t225-t226;
t192 = t9.*t12;
t193 = t10.*t11;
t194 = t192+t193;
t195 = t9.*t10;
t216 = t11.*t12;
t196 = t195-t216;
t217 = t14.*t196;
t218 = t217-t17.*t194;
t219 = t14.*t194;
t220 = t17.*t196;
t221 = t219+t220;
t229 = pi.*t23.*t132.*(1.0./1.8e2);
t230 = t229-pi.*t31.*t135.*(1.0./1.8e2);
t231 = pi.*t31.*t132.*(1.0./1.8e2);
t232 = pi.*t23.*t135.*(1.0./1.8e2);
t233 = t231+t232;
t234 = pi.*t23.*t40.*(1.0./1.8e2);
t258 = pi.*t31.*t46.*(1.0./1.8e2);
t236 = t234-t258;
t237 = t9.*t10.*t17.*t23.*t28;
t238 = t9.*t12.*t14.*t23.*t28;
t239 = t10.*t11.*t14.*t23.*t28;
t240 = t9.*t12.*t17.*t30.*t31;
t241 = t10.*t11.*t17.*t30.*t31;
t242 = t11.*t12.*t14.*t30.*t31;
t243 = t9.*t12.*t17.*t31.*t33;
t244 = t10.*t11.*t17.*t31.*t33;
t245 = t11.*t12.*t14.*t31.*t33;
t246 = t237+t238+t239+t240+t241+t242+t243+t244+t245-t11.*t12.*t17.*t23.*t28-t9.*t10.*t14.*t30.*t31-t9.*t10.*t14.*t31.*t33;
t247 = pi.*t31.*t40.*(1.0./1.8e2);
t248 = pi.*t23.*t46.*(1.0./1.8e2);
t249 = t247+t248;
t250 = t11.*t12.*t17.*t28.*t31;
t251 = t9.*t12.*t17.*t23.*t30;
t252 = t10.*t11.*t17.*t23.*t30;
t253 = t11.*t12.*t14.*t23.*t30;
t254 = t9.*t12.*t17.*t23.*t33;
t255 = t10.*t11.*t17.*t23.*t33;
t256 = t11.*t12.*t14.*t23.*t33;
t257 = t250+t251+t252+t253+t254+t255+t256-t9.*t10.*t14.*t23.*t30-t9.*t10.*t14.*t23.*t33-t9.*t12.*t14.*t28.*t31-t10.*t11.*t14.*t28.*t31-t9.*t10.*t17.*t28.*t31;
t259 = t3.^2;
t260 = t44.^2;
t261 = t25.*t26.*t32.*t33.*t34.*t259;
t262 = t25.*t27.*t32.*t33.*t35.*t259;
t263 = t25.*t29.*t33.*t34.*t35.*t259;
t264 = t25.*t30.*t32.*t34.*t35.*t259;
t265 = t26.*t27.*t32.*t33.*t36.*t259;
t266 = t26.*t29.*t33.*t34.*t36.*t259;
t267 = t26.*t30.*t32.*t34.*t36.*t259;
t268 = t27.*t29.*t33.*t35.*t36.*t259;
t269 = t27.*t30.*t32.*t35.*t36.*t259;
t270 = t29.*t30.*t34.*t35.*t36.*t259;
t271 = t25.*t26.*t27.*t32.*t33.*t260;
t272 = t25.*t26.*t29.*t33.*t34.*t260;
t273 = t25.*t26.*t30.*t32.*t34.*t260;
t274 = t25.*t27.*t29.*t33.*t35.*t260;
t275 = t25.*t27.*t30.*t32.*t35.*t260;
t276 = t25.*t29.*t30.*t34.*t35.*t260;
t277 = t26.*t27.*t29.*t33.*t36.*t260;
t278 = t26.*t27.*t30.*t32.*t36.*t260;
t279 = t26.*t29.*t30.*t34.*t36.*t260;
t280 = t27.*t29.*t30.*t35.*t36.*t260;
t281 = t25.*t32.*t33.*t34.*t35.*t259;
t282 = t26.*t32.*t33.*t34.*t36.*t259;
t283 = t27.*t32.*t33.*t35.*t36.*t259;
t284 = t29.*t33.*t34.*t35.*t36.*t259;
t285 = t30.*t32.*t34.*t35.*t36.*t259;
t286 = t25.*t26.*t32.*t33.*t34.*t260;
t287 = t25.*t27.*t32.*t33.*t35.*t260;
t288 = t25.*t29.*t33.*t34.*t35.*t260;
t289 = t25.*t30.*t32.*t34.*t35.*t260;
t290 = t26.*t27.*t32.*t33.*t36.*t260;
t291 = t26.*t29.*t33.*t34.*t36.*t260;
t292 = t26.*t30.*t32.*t34.*t36.*t260;
t293 = t27.*t29.*t33.*t35.*t36.*t260;
t294 = t27.*t30.*t32.*t35.*t36.*t260;
t295 = t29.*t30.*t34.*t35.*t36.*t260;
t296 = t32.*t33.*t34.*t35.*t36.*t259;
t297 = t25.*t32.*t33.*t34.*t35.*t260;
t298 = t26.*t32.*t33.*t34.*t36.*t260;
t299 = t27.*t32.*t33.*t35.*t36.*t260;
t300 = t29.*t33.*t34.*t35.*t36.*t260;
t301 = t30.*t32.*t34.*t35.*t36.*t260;
t302 = t32.*t33.*t34.*t35.*t36.*t260;
t303 = t25.*t26.*t27.*t29.*t30.*t259;
t304 = t25.*t26.*t27.*t29.*t33.*t259;
t305 = t25.*t26.*t27.*t30.*t32.*t259;
t306 = t25.*t26.*t29.*t30.*t34.*t259;
t307 = t25.*t27.*t29.*t30.*t35.*t259;
t308 = t26.*t27.*t29.*t30.*t36.*t259;
t309 = t25.*t26.*t27.*t29.*t30.*t260;
t310 = t25.*t26.*t27.*t32.*t33.*t259;
t311 = t25.*t26.*t29.*t33.*t34.*t259;
t312 = t25.*t26.*t30.*t32.*t34.*t259;
t313 = t25.*t27.*t29.*t33.*t35.*t259;
t314 = t25.*t27.*t30.*t32.*t35.*t259;
t315 = t25.*t29.*t30.*t34.*t35.*t259;
t316 = t26.*t27.*t29.*t33.*t36.*t259;
t317 = t26.*t27.*t30.*t32.*t36.*t259;
t318 = t26.*t29.*t30.*t34.*t36.*t259;
t319 = t27.*t29.*t30.*t35.*t36.*t259;
t320 = t25.*t26.*t27.*t29.*t33.*t260;
t321 = t25.*t26.*t27.*t30.*t32.*t260;
t322 = t25.*t26.*t29.*t30.*t34.*t260;
t323 = t25.*t27.*t29.*t30.*t35.*t260;
t324 = t26.*t27.*t29.*t30.*t36.*t260;
t325 = t261+t262+t263+t264+t265+t266+t267+t268+t269+t270+t271+t272+t273+t274+t275+t276+t277+t278+t279+t280+t281+t282+t283+t284+t285+t286+t287+t288+t289+t290+t291+t292+t293+t294+t295+t296+t297+t298+t299+t300+t301+t302+t303+t304+t305+t306+t307+t308+t309+t310+t311+t312+t313+t314+t315+t316+t317+t318+t319+t320+t321+t322+t323+t324;
t326 = 1.0./t325;
J_i = [t80.*t127.*t249.*1.0e-4-t80.*t191.*t236.*1.0e-4;t80.*t127.*t230.*(-1.0e-4)-t80.*t191.*t233.*1.0e-4;t80.*t127.*(pi.*t31.*t218.*(1.0./1.8e2)-pi.*t23.*t28.*t221.*(1.0./1.8e2)).*(-1.0e-4)+t80.*t191.*(pi.*t23.*t218.*(1.0./1.8e2)+pi.*t28.*t31.*t221.*(1.0./1.8e2)).*1.0e-4;-t80.*t233.*t246-t80.*t230.*t257;t80.*t236.*t246-t80.*t249.*t257;t236.*t326.*(-t9.*t10.*t14.*t23.*t28.*t44+t3.*t23.*t24.*t25.*t27.*t29+t11.*t12.*t14.*t23.*t28.*t44+t9.*t12.*t17.*t23.*t28.*t44+t10.*t11.*t17.*t23.*t28.*t44+t3.*t23.*t24.*t25.*t27.*t32+t3.*t23.*t24.*t25.*t29.*t34-t9.*t12.*t14.*t30.*t31.*t44-t10.*t11.*t14.*t30.*t31.*t44+t3.*t23.*t24.*t25.*t32.*t34-t9.*t10.*t17.*t30.*t31.*t44+t3.*t23.*t24.*t27.*t29.*t36-t9.*t12.*t14.*t31.*t33.*t44-t10.*t11.*t14.*t31.*t33.*t44-t9.*t10.*t17.*t31.*t33.*t44+t3.*t23.*t24.*t27.*t32.*t36+t11.*t12.*t17.*t30.*t31.*t44+t11.*t12.*t17.*t31.*t33.*t44+t3.*t23.*t24.*t29.*t34.*t36+t3.*t23.*t24.*t32.*t34.*t36)+t249.*t326.*(t9.*t12.*t14.*t23.*t30.*t44+t10.*t11.*t14.*t23.*t30.*t44+t9.*t10.*t17.*t23.*t30.*t44+t9.*t12.*t14.*t23.*t33.*t44+t10.*t11.*t14.*t23.*t33.*t44-t9.*t10.*t14.*t28.*t31.*t44+t9.*t10.*t17.*t23.*t33.*t44-t11.*t12.*t17.*t23.*t30.*t44+t3.*t24.*t25.*t27.*t29.*t31+t11.*t12.*t14.*t28.*t31.*t44-t11.*t12.*t17.*t23.*t33.*t44+t9.*t12.*t17.*t28.*t31.*t44+t10.*t11.*t17.*t28.*t31.*t44+t3.*t24.*t25.*t27.*t31.*t32+t3.*t24.*t25.*t29.*t31.*t34+t3.*t24.*t25.*t31.*t32.*t34+t3.*t24.*t27.*t29.*t31.*t36+t3.*t24.*t27.*t31.*t32.*t36+t3.*t24.*t29.*t31.*t34.*t36+t3.*t24.*t31.*t32.*t34.*t36)];