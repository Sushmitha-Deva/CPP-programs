#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
  char c;
  int f;
  struct node *lptr;
  struct node *rptr;
};
struct node *hptr=NULL;
class heap
{

  public:struct node s[100];
         heap();
         int hsize;
        // void create();
         void insert(struct node &temp);
        struct node* deletemin();
	//void display
        
}h;
int n;
void huff_tree();
void swap(struct node &a,struct node &b);
struct node* insert_tree(struct node *ptr,struct node *ptr1);
//void huff_tree();
void inorder(struct node *ptr);
void string1(int a[],char ch,struct node* ptr,int val);
void code(char ch[]);
 heap::heap()
{
  for(int i=0;i<100;i++)
   {s[i].lptr=s[i].rptr=NULL;}
}
void swap(struct node &a,struct node &b)
{
  struct node temp;
  temp=a;
  a=b;
  b=temp;
}
void heap::insert(struct node &temp)
{
   hsize++;
   s[hsize]=temp;
   int i=hsize;
 while(i>1&&s[i].f<s[i/2].f)
  {
     swap(s[i],s[i/2]);
     i=i/2;
  }
}
void huff_tree()
{

struct node *T1,*T2;
 
  while(h.hsize>1)
  {  
    cout<<"\n\n";
    T1=h.deletemin();
    T2=h.deletemin();
   struct node *temp=insert_tree(T1,T2);
     h.insert(*temp);
  }
  hptr=h.deletemin();
}
struct node* heap::deletemin()
{
   struct node *temp=new struct node;
 // *temp=s[1];
   temp->lptr=s[1].lptr;
   temp->rptr=s[1].rptr;
   temp->c=s[1].c;
   temp->f=s[1].f;
 cout<<temp->c<<" "<<temp->f<<"got deleted\n";
   s[1]=s[hsize--];
   int i=1,min;
  while(2*i<=hsize)
   {
       if(2*i+1>hsize)
        min=2*i;
       else 
        {
          if(s[2*i].f>s[2*i+1].f)
           min=2*i+1;
          else
           min=2*i;
        }
      if(s[min].f<s[i].f)
       {
        swap(s[min],s[i]);   
         i=min;
       }
     else
      break;
    
    }
 
  return temp;
}
struct node* insert_tree(struct node *ptr1,struct node *ptr2)
{
  struct node *tptr=new struct node;
  tptr->lptr=ptr1;
  tptr->rptr=ptr2;
  tptr->c='$';
  tptr->f=ptr1->f+ptr2->f;
  return(tptr);
}
void inorder(struct node *ptr)
{
   if(ptr!=NULL)
  { 
    inorder(ptr->lptr);
    cout<<ptr->c<<" "<<ptr->f<<endl;
    inorder(ptr->rptr);
  }
}
void string1(int a[],char ch,struct node* ptr,int val)
{
  if(ptr->lptr!=NULL)
  {
    a[val]=1;
    string1(a,ch,ptr->lptr,val+1);
  }
  if(ptr->rptr!=NULL)
  {
    a[val]=0;
    string1(a,ch,ptr->rptr,val+1);
  }
  if((ptr->lptr==NULL)&&(ptr->rptr==NULL))
   {
     if(ptr->c==ch)
      {
       cout<<"code for "<<ptr->c<<":";
       for(int i=0;i<val;i++)
        {
          cout<<a[i];
        }
       cout<<endl;
      }
   }
}
void code(char C[])
{
	struct node *thptr=hptr;
	int i=0;
	cout<<"\nThe string for given code is: ";
	while(C[i]!='\0')
	{
		if(thptr->lptr==NULL&& thptr->rptr==NULL)
			{
				cout<<thptr->c;
				thptr=hptr;
				continue;
			}
		if(C[i]=='0')
			thptr=thptr->lptr;
		else if(C[i]=='1')
			thptr=thptr->rptr;
		else
			{
				cout<<"\n Invalid code";
				break;
			}
		i++;
	}
	if(thptr->lptr==NULL&& thptr->rptr==NULL)
		cout<<thptr->c;
	else
		cout<<"\n invalid Code";

}
int main()
{
  int x;
  char ch[50],ch1[50];
  int a[50];
 h.hsize=0;
 // ob.create();
  struct node *temp=new struct node;
  cout<<"Enter the no. of elements\n";
  cin>>n;
  cout<<n;
  cout<<"Enter character,freq\n";
  for(int i=0;i<n;i++)
  { 

     cin>>temp->c>>temp->f;
    h.insert(*temp);
  }
 for(int i=1;i<=h.hsize;i++)
   cout<<h.s[i].f<<" "<<h.s[i].c<<endl;
 
 //cout<<ob.hsize;
 //struct node *temp=ob.deletemin();
huff_tree(); 
cout<<"Inorder is\n";
 inorder(hptr);
do
{
  cout<<"Enter choice 1:code\n2:string\n";
  cin>>x;
  switch(x)
  {
   case 1:cout<<"Enter a string\n";
          cin>>ch;
          for(int i=0;ch[i]!='\0';i++)
           string1(a,ch[i],hptr,0);
           break;
   case 2:cout<<"Enter code\n";
          cin>>ch1;
          code(ch1);
          break;

  }
 }while(1);
 return 0;
}
