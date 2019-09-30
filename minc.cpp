#include<iostream>
#include<cstring>
using namespace std;
struct node
{
  char a[100][100];
};
struct node s[100];
void minic();
int n,m,y=1;
int main()
{

   
   cout<<"Enter no. of dependencies\n";
   cin>>n;
   /*cout<<"Enter the no. of attributes\n";
   cin>>m;
   cout<<"Enter the attributes\n";
   for(int i=0;i<m;i++)
    cin>>b[i][0];
   for(int i=0;i<m;i++)
       b[i][1]='0';*/
  
   for(int i=0;i<100;i++)
    {
     for(int j=0;j<n;j++)
      { 
        strcpy(s[i].a[j],"xxxxx"); 
       }
     }
   cout<<"Enter the dependencies\n";
   for(int i=0;i<n;i++)
      cin>>s[0].a[i];
   cout<<"Display:\n";
   for(int i=0;i<n;i++)
      cout<<"\t"<<s[0].a[i]<<endl;
   minic();
  return 0;
}
void minic()
{
 cout<<"After minimal cover\n";
    for(int i=0;i<n;i++)
    {
     int j;
     int flag=0,cou=0,cou1=0,p=0,r=0;
     char ls[20],lhs[20];
       for(j=0;s[0].a[i][j]!='\0';j++)
        {
          if(s[0].a[i][j]=='-')
           {
            flag=1;lhs[p]='-';
           }
          else if(flag==1)
            {
               int q=0;
               char rhs[20];
               rhs[q]=s[0].a[i][j];
               cout<<rhs[q];
               cout<<lhs<<endl;
               strcpy(ls,lhs);
               strcat(ls,rhs);
               strcpy(s[y].a[r],ls);
               y++;
               cout<<ls<<endl;
             }
          else
            {
               cou1++;
               lhs[p]=s[0].a[i][j];
               p++;  

             }
         }
        strcpy(s[0].a[i],"xxxxx");
     }
  for(int i=0;i<y;i++)
  {
    cout<<" Table "<<i+1<<":"<<endl;
    for(int j=0;j<n;j++)
    {
      if(strcmp(s[i].a[j],"xxxxx")!=0)
      cout<<"\t"<<s[i].a[j]<<" ";
    }
    cout<<endl;
  }

} 
