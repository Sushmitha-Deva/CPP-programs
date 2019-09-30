#include<iostream>
#include<cstring>
using namespace std;

struct node
{
char l[10];
char c;
char d;
char r[10];
};
int n,f;
char c[20];
char d[20];
struct node a[20];
struct node b[20];
struct node e[20];

int search(char g,char h)
{cout<<g<<" "<<h<<endl;
for(int i=0;i<10;i++)
{
if(b[i].l[0]==g)
{
cout<<i<<endl;
return i;
}
else
return 0;
}


}

int main()
{
char t[20];
char ck[20];
int i;
cout<<"Enter no of attributes";
cin>>n;
cout<<"ENter attributes";
for(int i=0;i<n;i++)
{
cin>>c[i];
d[i]=c[i];
}
cout<<"Enter no of Fds";
cin>>f;
cout<<"Enter fds";
for(int i=0;i<f;i++)
{
cin>>a[i].l;
cin>>a[i].c;
cin>>a[i].d;
cin>>a[i].r;
}
int j=0,k=0;
for(i=0;i<f;i++)
{
if(strlen(a[i].r)>1)
{k=0;
while( k<strlen(a[i].r))
{
strcpy(b[j].l,a[i].l);
b[j].r[0]=a[i].r[k];
j++;
k++;
}
}
else
{
strcpy(b[j].l,a[i].l);

strcpy(b[j].r,a[i].r);
j++;
}

}
//e=b;
for(i=0;i<f;i++)
{
if(strlen(b[i].l)>1)
{
for(int k=0;k<strlen(b[i].l);k++)
{
if (search(b[i].l[k],b[i].r[0])!=0)
{

b[i]=b[search(b[i].l[k],b[i].r[0])];
cout<<b;
}
}
}

}
cout<<"MInimal:"<<endl;
for(int i=0;i<10;i++)
{
if(b[i].l!=NULL||b[i].r!=NULL)
cout<<b[i].l<<"-"<<">"<<b[i].r<<endl;
}
}


