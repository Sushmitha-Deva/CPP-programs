#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>

using namespace std;
class med
{
  public:int rno,ctc;
  char name[20];
  void create();
         
};
int f[26],c[26];
 int op[100];
med ob2[20];
int fm(int ob[],int n);
         int kelement(int ob[],int l,int r,int k);
         void swap(int *a,int *b);
         int partition(int ob[],int l,int r,int x);
void cs(int ob[],int n,int p);
//void rad(int ob[],int n);
//void cs(int ob[],int n,int p);

int main()
{
 int n;
cout<<"Enter the no. of ppl\n";
cin>>n;
cout<<"Enter rno,name,ctc of"<<n<<" values\n";
for(int i=0;i<n;i++)
 ob2[i].create();
int ob[100];
for(int i=0;i<n;i++)
 ob[i]=ob2[i].ctc;
for(int i=0;i<n;i++)
 cout<<ob[i]<<" ";
//rad(ob,n);
//cout<<"median:"<<ob[n/2];
//cout<<"min:"<<ob[0];
//cout<<"max:"<<ob[n-1];

  cout<<kelement(ob,0,n-1,(n+1)/2);
cout<<"max:\n";
 cout<<kelement(ob,0,n-1,n);
cout<<"min:\n";
cout<<kelement(ob,0,n-1,1);

return 0;
}
/*void rad(int ob[],int n)
{
  for(int i=1;i<3;i++)
  {int m=pow(10,i-1); cs(ob,n,m);
  
}*/
void med::create()
{
 cin>>rno>>name>>ctc;
  
}
int fm(int ob[],int n)
{
   sort(ob,ob+n);
   return(ob[n/2]);

}
int kelement(int ob[],int l,int r,int k)
{
   if(k>0&&k<=r-l+1)
   {
     int n=r-l+1;
    int i,m[(n+4)/5];
    for(i=0;i<n/5;i++)
     m[i]=fm(ob+l+i*5,5);
     if(i*5<n)
     { m[i]=fm(ob+l+i*5,n%5);i++;}
    int mom=(i==1)?m[i-1]:
        kelement(m,0,i-1,i/2);
       
      int pos=partition(ob,l,r,mom);
     if(pos-l==k-1)
      return(ob[pos]);
      if(pos-l>k-1)
      return(kelement(ob,l,pos-1,k));
        return(kelement(ob,pos+1,r,k-pos+l-1));
      
   }
  return INT_MAX;
} 
int partition(int ob[],int l,int r,int x)
{
  int i;
  for(i=l;i<r;i++)
   {
    if(ob[i]==x)
      break;
   }
   swap(&ob[i],&ob[r]);
      i=l;
  for(int j=l;j<=r-1;j++)
  {
    if(ob[j]<=x)
     {
      swap(&ob[i],&ob[j]);i++;
     }

  }
 swap(&ob[i],&ob[r]);
  return i;
}
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;

}
/*(void cs(int ob[],int n,int p)
{
  for(int i=0;i<100;i++)
   f[i]=c[i]=0;
  for(int i=0;i<n;i++)
   f[(ob[i]/p)%10]++;
  c[0]=f[0];
  for(int i=1;i<100;i++)
     {c[i]=c[i-1]+f[i];}
  for(int i=n-1;i>=0;i--)
  {
     op[(c[ob[i]/p%10])-1]=ob[i];
     c[ob[i]/p%10]--;

   }
 for(int i=0;i<n;i++)
   ob[i]=op[i];
    
}*/
