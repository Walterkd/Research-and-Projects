addpath('G:\Í¼ÏñÑ¹Ëõ\samples');
I=imread('pears.png');  
imshow(I);  
IBW=im2bw(I);  
[m n]=size(IBW);  
c=I(1,1);RLEcode(1,1:3)=[1 1 c];  
t=2;  
for k=1:m  
    for j=1:n  
        if(not(and(k==1,j==1)))  
            if(not(I(k,j)==c))  
                RLEcode(t,1:3)=[k j IBW(k,j)];  
                c=IBW(k,j);  
                t=t+1;  
            end  
        end  
    end  
end      

