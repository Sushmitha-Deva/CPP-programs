
#include<stdio.h>
#include<string.h>
struct record
{
  char name[20];
  int rno;
  int com1;
  int com2;
  int com3;
  int com4;
  float gpa;
  float cgpa;
};

int main()
{
  struct record a[5],b[5],c[5],d[5];
  int i,sem,sub;
  char name[20];
  FILE *p,*q,*r,*s;
  printf("\n 1st sem");
  p=fopen("sem1.txt","w");
   for(i=0;i<2;i++)
   {
    printf("\nenter name,roll no.,4grades of student %d\n",i+1);
    scanf("%s %d %d %d %d %d",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4);
   
    a[i].gpa=(a[i].com1+a[i].com2+a[i].com3+a[i].com4)/(4.0);
    a[i].cgpa=a[i].gpa;
  
  
 fprintf(p,"%s %d %d %d %d %d %f %f\n",a[i].name,a[i].rno,a[i].com1,a[i].com2,a[i].com3,a[i].com4,a[i].gpa,a[i].cgpa); 
   }
   fclose(p);

   printf("\n Second sem");
   p=fopen("sem1.txt","r");
   q=fopen("sem2.txt","w");
    for(i=0;i<2;i++)
     {
      printf("\nenter 4grades of student %d\n",i+1);
      scanf("%d %d %d %d",&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4);
      a[i].gpa=(a[i].com1+a[i].com2+a[i].com3+a[i].com4)/(4.0);
  
      fscanf(p,"%s %d %d %d %d %d %f %f",b[i].name,&b[i].rno,&b[i].com1,&b[i].com2,&b[i].com3,&b[i].com4,&b[i].gpa,&b[i].cgpa);
      a[i].cgpa=((b[i].cgpa+a[i].gpa)/2.0);
     
      fprintf(q,"%s %d %d %d %d %d %f %f\n",a[i].name,a[i].rno,a[i].com1,a[i].com2,a[i].com3,a[i].com4,a[i].gpa,a[i].cgpa); 
   }
   fclose(q);
   fclose(p);
 
 
   p=fopen("sem1.txt","r");
   q=fopen("sem2.txt","r");
   printf("\n Third sem");
   r=fopen("sem3.txt","w");
    for(i=0;i<2;i++)
     {
       printf("\nenter 4grades of student %d\n",i+1);
       scanf("%d %d %d %d",&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4);
       a[i].gpa=(a[i].com1+a[i].com2+a[i].com3+a[i].com4)/(4.0);
    
   fscanf(p,"%s %d %d %d %d %d %f %f",b[i].name,&b[i].rno,&b[i].com1,&b[i].com2,&b[i].com3,&b[i].com4,&b[i].gpa,&b[i].cgpa);
   fscanf(q,"%s %d %d %d %d %d %f %f",c[i].name,&c[i].rno,&c[i].com1,&c[i].com2,&c[i].com3,&c[i].com4,&c[i].gpa,&c[i].cgpa);

    a[i].cgpa=((b[i].gpa+a[i].gpa+c[i].gpa)/3.0);
  
 fprintf(r,"%s %d %d %d %d %d %f %f\n",a[i].name,a[i].rno,a[i].com1,a[i].com2,a[i].com3,a[i].com4,a[i].gpa,a[i].cgpa); 
   }
   fclose(r);
   fclose(q);
   fclose(p);

   p=fopen("sem1.txt","r");
   q=fopen("sem2.txt","r");
   printf("\n Fourth sem");
   r=fopen("sem3.txt","r");
   s=fopen("sem4.txt","w");
 

  for(i=0;i<2;i++)
     {
       printf("\nenter 4grades of student %d\n",i+1);
       scanf("%d %d %d %d",&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4);
       a[i].gpa=(a[i].com1+a[i].com2+a[i].com3+a[i].com4)/(4.0);
    
   fscanf(p,"%s %d %d %d %d %d %f %f",b[i].name,&b[i].rno,&b[i].com1,&b[i].com2,&b[i].com3,&b[i].com4,&b[i].gpa,&b[i].cgpa);
   fscanf(q,"%s %d %d %d %d %d %f %f",c[i].name,&c[i].rno,&c[i].com1,&c[i].com2,&c[i].com3,&c[i].com4,&c[i].gpa,&c[i].cgpa);
   fscanf(r,"%s %d %d %d %d %d %f %f",d[i].name,&d[i].rno,&d[i].com1,&d[i].com2,&d[i].com3,&d[i].com4,&d[i].gpa,&d[i].cgpa);

    a[i].cgpa=((b[i].gpa+a[i].gpa+c[i].gpa+d[i].gpa)/4.0);
  
    fprintf(s,"%s %d %d %d %d %d %f %f\n",a[i].name,a[i].rno,a[i].com1,a[i].com2,a[i].com3,a[i].com4,a[i].gpa,a[i].cgpa); 
   }

   fclose(r);
   fclose(s);
   fclose(q);
   fclose(p);
s=fopen("sem4.txt","r");
int flag=0;
 for(i=0;i<2;i++)
{
  fscanf(s,"%s %d %d %d %d %d %f %f\n",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa);
  if(a[i].cgpa>=7.5)
   {
    printf("\nCGPA Check:\n%s has cgpa greater than 7.5",a[i].name);
    flag=1;
    }
   }
if(flag==0)
 printf("\n Sadly noone have secured 7.5 cgpa :(");
fclose(s);
printf("\n S grade check:\nWhich sem:");
scanf("%d",&sem);
printf("\n Which subject:");
scanf("%d",&sub);
switch(sem)
{
  case 1:p=fopen("sem1.txt","r");
   for(i=0;i<2;i++)
    {
  fscanf(p,"%s %d %d %d %d %d %f %f\n",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa);
  if(sub==1&&a[i].com1>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==2&&a[i].com2>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==3&&a[i].com3>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==4&&a[i].com4>=9)
   printf("\n %s got S grade",a[i].name);
   }fclose(p);break;
 case 2:p=fopen("sem2.txt","r");
   for(i=0;i<2;i++)
    {
  fscanf(p,"%s %d %d %d %d %d %f %f\n",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa);
  if(sub==1&&a[i].com1>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==2&&a[i].com2>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==3&&a[i].com3>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==4&&a[i].com4>=9)
   printf("\n %s got S grade",a[i].name);
   }fclose(p);break;
 case 3:p=fopen("sem3.txt","r");
   for(i=0;i<2;i++)
    {
  fscanf(p,"%s %d %d %d %d %d %f %f\n",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa);
  if(sub==1&&a[i].com1>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==2&&a[i].com2>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==3&&a[i].com3>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==4&&a[i].com4>=9)
   printf("\n %s got S grade",a[i].name);
   }fclose(p);break;
case 4:p=fopen("sem4.txt","r");
   for(i=0;i<2;i++)
    {
  fscanf(p,"%s %d %d %d %d %d %f %f\n",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa);
  if(sub==1&&a[i].com1>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==2&&a[i].com2>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==3&&a[i].com3>=9)
   printf("\n %s got S grade",a[i].name);
   if(sub==4&&a[i].com4>=9)
   printf("\n %s got S grade",a[i].name);
   }fclose(p);break;
}
p=fopen("sem1.txt","r");
char ss1[3],ss2[3];
printf("\nWild Card Check\n Enter the first two characters:");
scanf("%s",ss1);
char *ptr;
for(i=0;i<2;i++)
{
  fscanf(p,"%s %d %d %d %d %d %f %f\n",a[i].name,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa);
 ss2[0]=a[i].name[0];
 ss2[1]=a[i].name[1];
 ptr=strstr(ss1,ss2);
 if(ptr==NULL)
   printf("\n%s Not Present in %s",ss1,a[i].name);
 else
   printf("\n%s has the given string %s",a[i].name,ss1); 

}
return 0;
}

