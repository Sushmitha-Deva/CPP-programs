#include<iostream>
#define k 50
using namespace std;
class count
{
  public:int a[20],b[20];
         int n;
         void create();
         int f[k+1],c[k+1];
         void sort();
         count()
        { for(int i=0;i<k+1;i++)
           { f[i]=c[i]=0;}
        }
         int cou(int ,int );
        


};
int main()
{
  int a,b;
  
  count ob;
  ob.create();
  ob.sort();
  cout<<"enter the range a,b"<<endl;
    cin>>a>>b;
  int n;
    n=ob.cou(a,b);
  cout<<" there are "<<n<<" no.s btwn a,b"<<endl;
  
return 0;
}
int count::cou(int a,int b)
{
  return(c[b]-c[a-1]);

}
void count::create()
{
 cout<<"enter no. of values"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
   cin>>a[i];
}
void count::sort()
{
 for(int i=0;i<n;i++)
   f[a[i]]++;
 c[0]=f[0];
 for(int i=1;i<k+1;i++)
   c[i]=c[i-1]+f[i];
 for(int i=n-1;i>=0;i--)
    {    
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;     
    }
 for(int i=0;i<n;i++)
   cout<<b[i]<<" ";

}
