%����ͼ�񲢽��лҶ�ת�� 
I=imread('pears.jpeg'); 
imshow(I) 
IBM=im2bw(I); 
[m,n]=size(IBM); 
%��������RLEcode,����Ԫ��������ʽΪ[�г���ʼ�����ꡢ�г������ꡢ�Ҷ�ֵ] 
c=I(1,1);RLEcode(1,1:3)=[1 1 c]; 
t=2; 
% �����г̱��� 
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