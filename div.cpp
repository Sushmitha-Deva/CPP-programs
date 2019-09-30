#include<iostream>
using namespace std;
int mcc(int a[],int beg,int end);
int max(int ,int ,int );
int main()
{
 int n,msum;
cout<<"Enter the no. of values"<<endl;
cin>>n;
int a[n];
 cout<<"enter "<<n<<" values"<<endl;
 for(int i=1;i<=n;i++)
  cin>>a[i];
msum=mcc(a,1,n);
cout<<endl<<msum<<endl;
return 0;
}
int mcc(int a[],int beg,int end)
{
  if(beg==end)
   {
     if(a[beg]>=0)
      return a[beg];
     else
      return 0;
    }
   int c=(beg+end)/2;
  int ls=mcc(a,beg,c);
  int rs=mcc(a,c+1,end);
   int lsum=0,rsum=0,csum=0;
   for(int i=c;i>=1;i--)
   {
     csum=csum+a[i];
     if(csum>lsum)
        lsum=csum;
    }
     csum=0;
    for(int i=c+1;i<=end;i++)
   {
     csum=csum+a[i];
     if(csum>rsum)
        rsum=csum;
    }
   return max(ls,rs,lsum+rsum);
}
int max(int a,int b,int c)
{
  if(a>=b&&a>=c)
   return a;
  else if(b>=a&&b>=c)
   return b;
  else if(c>=a&&c>=b)
     return c;

}
