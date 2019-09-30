#include<iostream>
using namespace std;
int main()
{
 int n,msum=0;
 int csum=0,p,q;
cout<<"Enter the no. of values"<<endl;
cin>>n;
int a[n];
 cout<<"enter "<<n<<" values"<<endl;
 for(int i=1;i<=n;i++)
  cin>>a[i];
for(int i=1;i<=n;i++)
 {
  for(int j=i;j<=n;j++)
  {
    csum=0;
   for(int k=i;k<=j;k++)
    { 
      csum=csum+a[k];
      if(msum<csum)
       { p=i;q=j; msum=csum;}
     }
   }
}
for(int s=p;s<=q;s++)
  cout<<a[s]<<" ";
 cout<<endl<<msum<<endl;
return 0;
}
