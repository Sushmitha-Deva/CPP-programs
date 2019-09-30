#include<iostream>
using namespace std;
class graph
{
 
  public:
         void addedge();
         


};
void minspantree();
int min();
int cyclecheck(int p,int q);
void check();
int root(int x);
int n,m;
void del(int ,int );
 int a[20][20];
 int b[20][3];
 int k=1;
 int p,q;
 int u[50];
int main()
{
 
 cout<<"Enter no. of vertices\n";
  cin>>n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   a[i][j]=0;
  graph ob;
  ob.addedge();
 cout<<"Input graph:\n"; 
 for(int i=1;i<=n;i++)
 { 
  for(int j=1;j<=n;j++)
   cout<<a[i][j]<<" ";
   cout<<endl;
  }
 for(int i=1;i<=50;i++)
   u[i]=-1;
 
minspantree();
 cout<<"output array\n";
  for(int i=1;i<=k-1;i++)
   {
   for(int j=1;j<=3;j++)
    cout<<b[i][j];
    cout<<endl; 
   }

  int y=0;
  for(int i=1;i<=k-1;i++)
   y=y+b[i][3];
 cout<<"min cost is:"<<y<<endl;

 return 0;
}
void graph::addedge()
{
 int v1,v2,c;
 cout<<"Enter no.of pairs\n";
  cin>>m;
  cout<<"Enter v1,v2,cost\n";
  for(int i=0;i<m;i++)
 { 
  cin>>v1>>v2>>c;
  a[v1][v2]=c;
  a[v2][v1]=c;
 }
}
int min()
{
  int min=344;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
     {
        if(min>a[i][j]&&a[i][j]!=0)
        {
           p=i;
           q=j;
           min=a[i][j];
         }
      }
  return min;
}
void del(int p,int q)
{
  a[p][q]=0;
  a[q][p]=0;
}
int cyclecheck(int p,int q)
{
  int i=root(p);
  int j=root(q);
//  cout<<"root"<<i<<j;

  if(u[i]!=u[j]||(u[i]==-1&&u[j]==-1)) 
   {
     if(-u[i]>-u[j])
      {
        u[j]=i;
        u[i]=u[i]-1;
        cout<<"u[i] is "<<u[i]<<endl;
      }
     else
       {
         u[i]=j;
        u[j]=u[j]-1;
        cout<<"u[j] is "<<u[j]<<endl;

        }
     return 1;
   }
  else
   return 0;
}
int root(int x)
{
  while(u[x]>=0)
   {
     x=u[x];    
   }
  cout<<"x is:"<<x<<endl;

 return x;
}
void minspantree()
{
 int r,x;
  while(k<=n-1&&m>0) 
  {
     r=min();
     del(p,q);
     m--;
     x=cyclecheck(p,q);
     cout<<"x is "<<x<<endl;
     if(x==1)
      {
        b[k][1]=p;
        b[k][2]=q;
        b[k][3]=r;
        k++;
      } 
       
  }
}
