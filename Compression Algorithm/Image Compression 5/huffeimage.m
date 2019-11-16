clear all;
clc;
I=imread('lena2.bmp');
x=isrgb(I);
if x==1
    I=rgb2gray(I);
else
end
i=double(I);
[m,n]=size(I);
len=m*n;
for p=1:256;
    j=find(i==p-1);
    u(p)=length(j);
end
stem(u);
r=find(u>0);
k=length(r);
F(1,:)=r-1;
v=u(r);
A=v/sum(v);
F(2,:)=A;
B=F';
B=sortrows(B,2);
B=B';
B=fliplr(B);
A=B(2,:);
[avlen,END,H,P,L]=huffenco(A);
B=sym(B);
B(3,:)=END;
q=double(1/(sum(L.*(sum(v)*B(2,:)))/len/8));