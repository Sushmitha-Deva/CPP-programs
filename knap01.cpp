#include<iostream>
using namespace std;
class knapsack
{
  int p,w;
  public:void create();
         void sort();
         void kp();

};
knapsack a[20],b[20];
int f[100],c[100];
int n,m;
void knapsack::create()
{
 cout<<"Enter no. of objects\n";
 cin>>n;
 cout<<"Enter price,weight of object\n";
 for(int i=0;i<n;i++)
  cin>>a[i].p>>a[i].w;
 cout<<"Enter the size of the bag\n";
  cin>>m;
}
void knapsack::sort()
{
  for(int i=0;i<100;i++)
    f[i]=c[i]=0;
  for(int i=0;i<n;i++)
     f[a[i].p]++;
  c[0]=f[0];
  for(int i=1;i<100;i++)
    c[i]=c[i-1]+f[i];
  for(int i=n-1;i>=0;i--)
   { b[c[a[i].p]-1]=a[i];c[a[i].p]--;}
 for(int i=0;i<n;i++)
   a[i]=b[i];
for(int i=0;i<n;i++)
 cout<<a[i].p<<" "<<a[i].w<<endl;

}
void knapsack::kp()
{
 int rm=m;
  for(int i=n;i>=0;i--)
   {
     if(rm>=a[i].w)
       rm=rm-a[i].w;   
   }
  cout<<"remaining weight "<<rm;  
}
int main()
{
  knapsack ob;
 ob.create();
 ob.sort();
 ob.kp();

 return 0;
}
