#include<iostream>
using namespace std;
class knapsack
{
  float p,w;
  float pw; 
  public:void create();
         void sort();
         void kp();

};
knapsack a[20],b[20];
int n,m;
void knapsack::create()
{
 cout<<"Enter no. of objects\n";
 cin>>n;
 cout<<"Enter price,weight of object\n";
 for(int i=0;i<n;i++)
  cin>>a[i].p>>a[i].w;
 for(int i=0;i<n;i++)
  a[i].pw=(a[i].p/a[i].w);
 cout<<"Enter the size of the bag\n";
  cin>>m;
}
void knapsack::sort()
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j].pw>a[j+1].pw)
          {
            knapsack temp;
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           
           }
     }
  }
for(int i=0;i<n;i++)
 cout<<a[i].p<<" "<<a[i].w<<endl;

}
void knapsack::kp()
{
 int rm=m;
 float p=0;
  for(int i=n-1;i>=0;i--)
   {
     if(rm>=a[i].w)
       { cout<<a[i].p<<" "<<a[i].w<<"if"<<endl;
        p=p+a[i].p;
         rm=rm-a[i].w;
        }
     else
        {cout<<a[i].p<<" "<<a[i].w<<endl;
          p=p+(a[i].pw*rm);
          break;
        }   
   }
  cout<<"profit is"<<p;  
}
int main()
{
  knapsack ob;
 ob.create();
 ob.sort();
 ob.kp();

 return 0;
}
