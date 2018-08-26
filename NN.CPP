#include<stdio.h>
#include<iostream.h>
#include<conio.h>
void main()
{
float o=0.2;
float a=0.5,x1[4],x2[4],y[4];
float w1=0,w2=0,b=0,t[150][10],column=0;
clrscr();
for(int i=0;i<4;i++)
{
cin>>x1[i]>>x2[i]>>y[i];
}
int j=0;
cout<<endl<<endl<<"EPOCH   1"<<endl<<endl;
for(i=0;;i++)
{

t[i][0]=x1[j];
t[i][1]=x2[j];
t[i][2]=y[j];
t[i][3]=w1*t[i][0]+w2*t[i][1]+b;
if(t[i][3]>o)
t[i][3]=1;
else if(t[i][3]>=-o&&t[i][3]<=o)
t[i][3]=0;
else if(t[i][3]<-o)
t[i][3]=-1;
if(t[i][3]==t[i][2])
{
t[i][4]=w1;
t[i][5]=w2;
t[i][6]=b;
t[i][7]=0;
t[i][8]=0;
t[i][9]=0;
goto skip;
}


float temp;
temp=w1+t[i][0]*t[i][2]*a;
t[i][7]=temp-w1;
w1=temp;
t[i][4]=w1;
temp=w2+t[i][1]*t[i][2]*a;
t[i][8]=temp-w2;
w2=temp;
t[i][5]=w2;
temp=b+t[i][2]*a;
t[i][9]=temp-b;
b=temp;
t[i][6]=temp;


temp=w1*t[i][0]+w2*t[i][1]+b;
if(temp>o)
temp=1;
else if(temp>=-o&&temp<=o)
temp=0;
else if(temp<-o)
temp=-1;

//if(temp==y[j])
skip:
for(int k=0;k<10;k++)
 cout<<t[i][k]<<"    ";
 cout<<endl;
//cout<<w1<<"   "<<w2<<"   "<<b<<endl;
char ch = getch();
int f=0;
for(k=0;k<4;k++)
{
temp=x1[k]*w1+x2[k]*w2+b;
if(temp>o)
temp=1;
else if(temp>=-o&&temp<=o)
temp=0;
else if(temp<-o)
temp=-1;

if(temp==y[k])
f--;

}

if(f==0&&i>=3)
break;

j++;
if(j==4)
{j=0;
 cout<<endl<<endl<<endl;
 cout<<"EPOCH  "<<(i+1)/4+1<<endl;
 }
if(ch=='n')
break;

}
column=i;
cout<<"\n\n\n";
for(i=0;i<=column;i++)
{for(j=0;j<10;j++)
 cout<<t[i][j]<<"    ";
 cout<<endl;
 }

while(getch()=='n');
}