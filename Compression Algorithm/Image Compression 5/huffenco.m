function [avlen,END,H,P,L]=huffenco(A)
A=fliplr(sort(A));%����������
T=A;
[m,n]=size(A);
B=zeros(n,n-1);%�յı��������
for i=1:n
    B(i,1)=T(i);%���ɱ����ĵ�һ��
end
r=B(i,1)+B(i-1,1);%�������Ԫ�����
T(n-1)=r;
T(n)=0;
T=fliplr(sort(T));
t=n-1;
for j=2:n-1%���ɱ�������������
    for i=1:t
        B(i,j)=T(i);
    end
        K=find(T==r);
        B(n,j)=K(end);%�ӵڶ��п�ʼ��ÿ�е����һ��Ԫ�ؼ�¼����Ԫ����
%���е�λ��
        r=(B(t-1,j)+B(t,j));%�������Ԫ�����
        T(t-1)=r;
        T(t)=0;
        T=fliplr(sort(T)); 
        t=t-1;
end
B;%��������
END=sym('[0,1]');%�����һ�е�Ԫ�ر���
t=2;
for j=n-2:-1:1%�ӵ����ڶ��п�ʼ���ζԸ���Ԫ�ر���
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
avlen=sum(L.*A)%ƽ���볤  
H1=log2(A);
H=-A*(H1')%��
P=H/avlen%����Ч��
