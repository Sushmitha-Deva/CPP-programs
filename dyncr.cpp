#include<iostream>
using namespace std;
int ncr(int n,int r);
int main()
{
  int n,r;
 cout<<"Enter the value of n,r"<<endl;
 cin>>n>>r;
 int a[20][20];
  a[0][0]=1;
  for(int i=0;i<=n;i++)
   {
     for(int j=0;j<=n;j++)
      {
         if(i>=j)
          {
             if(j==0||i==j)
              a[i][j]=1;
             else if(j==1)
               a[i][j]=i;
             else
                a[i][j]=a[i-1][j]+a[i-1][j-1];
          }
       
       }
   }

  cout<<a[n][r];
return 0;
}
