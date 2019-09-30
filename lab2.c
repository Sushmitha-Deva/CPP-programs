#include<stdio.h>
#include<string.h>
struct student
{
 
  char name[20];
  int age;
  int rno;
  int com1;
  int com2;
  int com3;
  int com4;
  float gpa;
  float cgpa;
};
void display();
void display1();
void display2();
struct student a[5];

int main(int argc,char* argv[])
{
  int count=argc;
  printf("\n u have enterd %d arguments",count);
  printf("\n You have entered :\n");
 /* for (int i=0;i<argc;i++)
    printf("--%s--",argv[i]);*/
  if((strcmp(argv[1],"select")==0)&&(strcmp(argv[3],"from")==0)&&(strcmp(argv[4],"student.txt")==0))
  {
   if(argc==5)
     {
       if(strcmp(argv[2],"*")==0)
        display();
      else if(strcmp(argv[2],"age,rollno")==0)
        display1();
      else
          printf("\n\"Error\"");
     }
   else if(argc==8&&(strcmp(argv[2],"*")==0)&&(strcmp(argv[5],"where")==0)&&(strcmp(argv[6],"cgpa")==0)&&(strcmp(argv[7],">=8")==0))
     display2();
   else
  printf("\n error\n No such command line1");  
 }
 else
  printf("\n error\n No such command line2");
return 0;
}
void display()
{
 FILE *ptr;
 printf("\n Student details:\n");
 ptr=fopen("student.txt","r");
  for( int i=0;i<2;i++)
   {
     fscanf(ptr,"%s %d %d %d %d %d %d %f %f\n",a[i].name,&a[i].age,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa); 
     printf("%s %d %d %d %d %d %d %f %f\n",a[i].name,a[i].age,a[i].rno,a[i].com1,a[i].com2,a[i].com3,a[i].com4,a[i].gpa,a[i].cgpa); 
    }
  fclose(ptr);

}
void display1()
{
 FILE *ptr;
 printf("\n roll no.and age details:\n");
 ptr=fopen("student.txt","r");
  for( int i=0;i<2;i++)
   {
     fscanf(ptr,"%s %d %d %d %d %d %d %f %f\n",a[i].name,&a[i].age,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa); 
     printf("student %d : %d %d\n",i+1,a[i].age,a[i].rno);
    }
  fclose(ptr);
}
void display2()
{
 FILE *ptr;
 printf("\n Details of student whose cgpa is greater than 8:\n");
 ptr=fopen("student.txt","r");
  for( int i=0;i<2;i++)
   {
     fscanf(ptr,"%s %d %d %d %d %d %d %f %f\n",a[i].name,&a[i].age,&a[i].rno,&a[i].com1,&a[i].com2,&a[i].com3,&a[i].com4,&a[i].gpa,&a[i].cgpa); 
     //printf("%s %d %d %d %d %d %d %f %f\n",a[i].name,a[i].age,a[i].rno,a[i].com1,a[i].com2,a[i].com3,a[i].com4,a[i].gpa,a[i].cgpa); 
      if(a[i].cgpa>=8)
       printf("%s got cgpa %f which is >=8",a[i].name,a[i].cgpa);
    }
  fclose(ptr);
}
 
