addpath('G:\Í¼ÏñÑ¹Ëõ\samples');
I=imread('pears.jpeg');  
imshow(I);  
IGRAY=rgb2gray(I);  
[m,n]=size(IGRAY);  
c=I(1,1);RLEcode(1,1:3)=[1 1 c];  
t=2;  
tic  
for k=1:m  
    for j=1:n  
        if(not(and(k==1,j==1)))  
            if(not(I(k,j)==c))  
                RLEcode(t,1:3)=[k j I(k,j)];  
                c=I(k,j);  
                t=t+1;  
            end  
        end  
    end  
end   
