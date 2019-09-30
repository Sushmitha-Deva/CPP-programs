#include<iostream>
using namespace std;
class buck
{
    public:int rno;
           int marks;
           char name[20];
           buck *nptr;
           int max(int );
           void insert(buck &a);
           int hash(int );
           void show();
        
};
buck *h[10]={NULL};
buck a[20];
buck *tptr[10]={NULL};
int k=0,n;
int main()
{
  cout<<" enter the no. of records"<<endl;
  cin>>n;
  cout<<"enter the name,rno,marks"<<endl;
   for(int i=0;i<n;i++)
    {
     cin>>a[i].name;
     cin>>a[i].rno;
     cin>>a[i].marks;
    
    }
    /*for(int i=0;i<n;i++)
       k=a[i].max(a[i].rno);
     cout<<k;*/
   cout<<" enter the k value"<<endl;
    cin>>k;
    for(int i=0;i<n;i++)
      a[i].insert(a[i]);
   buck ob;
    ob.show();
return 0;
} 
int buck::max(int a)
 {
   if(k>a)
    return k;
   else 
     return a;

}
int buck::hash(int a)
{
   return(a%k);
}
void buck::insert(buck &a)
{
 
 int h1=hash(a.rno);
   buck *temp=&a;
 
  if(h[h1]==NULL)
   {
    temp->nptr=h[h1];
    h[h1]=temp;
    tptr[h1]=temp;
    }
  else
      {
       temp->nptr=tptr[h1]->nptr;
       tptr[h1]->nptr=temp;
        tptr[h1]=temp;   
      }
   
}
void buck::show()
{
  for(int i=0;i<k;i++)
  {
    if(h[i]!=NULL)
    {
     buck *tptr=h[i];
         while(tptr!=NULL)
          { cout<<tptr->name<<" ";
            cout<<tptr->rno<<" ";
            cout<<tptr->marks<<endl; tptr= tptr->nptr;
           }
     }
   }

}
