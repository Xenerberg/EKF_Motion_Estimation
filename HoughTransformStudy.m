clc;close all;
greyImage = rgb2gray(imread('C:\Users\Iseberg\Pictures\image_feature.jpg'));%Read image
BW = edge(greyImage,'canny');%Detect edges to obtain Binary edge-feature image
[H,T,R] = hough(BW,'RhoResolution',0.5,'ThetaResolution',0.5);%Obtain Hough transform
%H - Hough Matrix;T - Theta vector;R - Rho vector

figure;
subplot(2,1,1);
imshow(greyImage);
title('Test image of Target Satellite');
h_hough = subplot(2,1,2);
imshow(imadjust(mat2gray(H)),'XData',T,'YData',R,'InitialMagnification','fit');
xlabel('\theta');ylabel('\rho');
axis on; axis normal, hold on;
colormap(h_hough,hot);