#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"Enter the value of n"<<endl;
 cin>>n;
 int a[n+1];
 a[0]=0;
 a[1]=1;
 int f1=a[0];
 int f2=a[1];
   for(int i=2;i<=n;i++)
   {
     int f3=f1+f2;
        f1=f2;
        f2=f3;
      a[i]=f3;
  }
cout<<"Fib of "<<n<<" is"<<a[n];

  return 0;
}
