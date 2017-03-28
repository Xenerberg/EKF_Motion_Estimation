clear all;
a = 0*pi/180;
b = 0:0.001:pi/2;
b = [b,-fliplr(b)];
b = [b,b];
c = 0*pi/180;
plot(b);
for iCount = 1:length(b)
   if abs(abs(b(iCount)) -pi/2) < 1e-1
      if b(iCount) < 0
        temp = ExtEulDCM([0,-pi/2,a+c],'XYZ','int');
      else
        temp = ExtEulDCM([0,pi/2,a+c],'XYZ','int');
      end
   else
      temp = ExtEulDCM([a,b(iCount),c],'XYZ','int');
   end
   quat(iCount,:) = temp(1:3,3)';%dcm2quat(temp);
end
plot(quat);