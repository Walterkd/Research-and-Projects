function [avlen,END,H,P,L]=huffenco(A)
A=fliplr(sort(A));%按降序排列
T=A;
[m,n]=size(A);
B=zeros(n,n-1);%空的编码表（矩阵）
for i=1:n
    B(i,1)=T(i);%生成编码表的第一列
end
r=B(i,1)+B(i-1,1);%最后两个元素相加
T(n-1)=r;
T(n)=0;
T=fliplr(sort(T));
t=n-1;
for j=2:n-1%生成编码表的其他各列
    for i=1:t
        B(i,j)=T(i);
    end
        K=find(T==r);
        B(n,j)=K(end);%从第二列开始，每列的最后一个元素记录特征元素在
%该列的位置
        r=(B(t-1,j)+B(t,j));%最后两个元素相加
        T(t-1)=r;
        T(t)=0;
        T=fliplr(sort(T)); 
        t=t-1;
end
B;%输出编码表
END=sym('[0,1]');%给最后一列的元素编码
t=2;
for j=n-2:-1:1%从倒数第二列开始依次对各列元素编码
    y=B(n,j+1);
    if y~=n-j
        temp=END(y);
        for i=y:(n-j)-1
    END(i)=END(i+1);  
        end
    END(i+1)=temp;
    end
    temp1=END(t);    
    END(t)=[char(temp1),'0'];
    END(t+1)=[char(temp1),'1'];
    t=t+1;
end
END

for i=1:n
    [a,b]=size(char(END(i)));
    L(i)=b;
end
L
avlen=sum(L.*A)%平均码长  
H1=log2(A);
H=-A*(H1')%熵
P=H/avlen%编码效率
