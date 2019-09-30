#include<iostream>
using namespace std;
int ncr(int n,int r);
int main()
{
  int n,r;
 cout<<"Enter the value of n,r"<<endl;
 cin>>n>>r;
 int x=ncr(n,r);

  cout<<x;


 return 0;
}
int ncr(int n,int r)
{
  if(n>=r)
   {
      if(r==0||n==r)
       return 1;
      else if(r==1)
        return n;
      else 
        return(ncr(n-1,r)+ncr(n-1,r-1));
    }
}
