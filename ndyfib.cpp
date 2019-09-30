#include<iostream>
using namespace std;
int fib(int n);
int main()
{
  int n;
 cout<<"Enter the value of n"<<endl;
 cin>>n;
 int x=fib(n);

  cout<<x;


 return 0;
}
int fib(int n)
{
   if(n==0||n==1)
    return n;
   else
    return (fib(n-1)+fib(n-2));
}
