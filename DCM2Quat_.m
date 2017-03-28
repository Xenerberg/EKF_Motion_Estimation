function [q,s_all,tr] = DCM2Quat_(DCM)
    q = [0;0;0;1];
    tr = trace(DCM);    
    s_1 = 1+tr;
    s_2 =  1.0 + DCM(1,1) - DCM(2,2) - DCM(3,3);
    s_3 = (1.0 + DCM(2,2) - DCM(1,1) - DCM(3,3));
    s_4 = ( 1.0 + DCM(3,3) - DCM(1,1) - DCM(2,2) );
    s_all = [s_1;s_2;s_3;s_4];
    %fprintf('s_1: %f, s_2: %f, s_3: %f, s_4:%f, DCM(1): %f, DCM(2): %f, DCM(3): %f \n',s_1,s_2,s_3,s_4,DCM(1,1),DCM(2,2),DCM(3,3));
    q(4) = sqrt(max([1+tr,0]))/2;
    q(1) = sqrt(max([1+DCM(1,1)-DCM(2,2)-DCM(3,3),0]))/2;
    q(2) = sqrt(max([1-DCM(1,1)+DCM(2,2)-DCM(3,3),0]))/2;
    q(3) = sqrt(max([1-DCM(1,1)-DCM(2,2)+DCM(3,3),0]))/2;
    if sign((DCM(3,2)) - (DCM(2,3))) == -1
        q(1) = -q(1);        
    end
    if sign((DCM(1,3)) - (DCM(3,1))) == -1
        q(2) = -q(2);
        
    end
    if sign(DCM(2,1) - DCM(1,2)) == -1
        q(3) = -q(3);
    end
    
    
    
     % I changed M_EPSILON to 0
        
    
    if( tr > 0 )
        s = sqrt(tr+ 1.0);
        q(4) = 0.5*s;
        q(1) = ( DCM(3,2) - DCM(2,3) )/(4*q(4));
        q(2) = ( DCM(1,3) - DCM(3,1) )/(4*q(4));
        q(3) = ( DCM(2,1) - DCM(1,2) )/(4*q(4));
    else
        if( DCM(1,1) > DCM(2,2) && DCM(1,1) > DCM(3,3) )
            s = sqrt( 1.0 + DCM(1,1) - DCM(2,2) - DCM(3,3));            
            q(1) = 0.5 * s;
            q(4) = (DCM(3,2) - DCM(2,3) ) / (4*q(1));
            q(2) = (DCM(1,2) + DCM(2,1) ) / (4*q(1));
            q(3) = (DCM(1,3) + DCM(3,1) ) / (4*q(1));

        elseif (DCM(2,2) > DCM(3,3) && DCM(2,2) > DCM(1,1)) 
            s = sqrt(1.0 + DCM(2,2) - DCM(1,1) - DCM(3,3));
            q(2) = 0.5 * s;
            q(4) = (DCM(1,3) - DCM(3,1) ) / (4*q(2));
            q(1) = (DCM(1,2) + DCM(2,1) ) / (4*q(2));            
            q(3) = (DCM(2,3) + DCM(3,2) ) / (4*q(2));

        elseif (DCM(3,3) > DCM(2,2) && DCM(3,3) > DCM(1,1))
            s = sqrt( 1.0 + DCM(3,3) - DCM(1,1) - DCM(2,2) );
            q(3) = 0.5 * s;
            q(4) = (DCM(2,1) - DCM(1,2) ) / (4*q(3));
            q(1) = (DCM(1,3) + DCM(3,1) ) / (4*q(3));
            q(2) = (DCM(2,3) + DCM(3,2) ) / (4*q(3));
            
        end    
        
    end

end