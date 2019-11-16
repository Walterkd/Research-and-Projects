%读入图像并进行灰度转换 
I=imread('pears.jpeg'); 
imshow(I) 
IBM=im2bw(I); 
[m,n]=size(IBM); 
%建立数组RLEcode,其中元素排列形式为[行程起始行坐标、行程列坐标、灰度值] 
c=I(1,1);RLEcode(1,1:3)=[1 1 c]; 
t=2; 
% 进行行程编码 
for k=1: m 
for j=1: n 
if(not(and(k==1,j==1))) 
if(not(IBM(k,j)==c)) 
RLEcode(t,1:3)=[k j IBM(k,j)]; 
c=IBM(k,j); 
t=t+1; 
end 
end 
end 
end 