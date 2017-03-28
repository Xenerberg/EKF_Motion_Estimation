function [R_DCM] = EulDCM(angles,flag,flag_typ)
    a = angles(1);
    b = angles(2);
    c = angles(3);
    flag = lower(flag);
    flag_typ = lower(flag_typ);
    switch flag_typ
        case 'int'
            switch(flag)
            case 'xyz'
                R_DCM = RotMat(c,'Z')*RotMat(b,'Y')*RotMat(a,'X');
            end
        case 'ext'
            switch(flag)
            case 'xyz'
                R_DCM = RotMat(a,'X')*RotMat(b,'Y')*RotMat(c,'Z');
            end
    end
    
end