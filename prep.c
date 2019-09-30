#include<mysql.h>
#include<stdio.h>
 
void main()
{
  MYSQL_*conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  
 char *server="localhost";
 char *user="root";
 char *password="sudeeshna12";
 char *database="COMPANY";

 conn=mysql_init(NULL);
 if(!mysql_real_connect(conn,server,user,password,0,NULL,0))
   {
     fprintf(stderr,"%s\n",mysql_error(conn));
     exit(1);

    }
//create table
 if(mysql_query(conn,"create table employee (name varchar(48))"))
  {
    fprintf(stderr,"%s\n",mysql_error(conn));
    exit(1);
  }
 if(mysql_query(conn,"alter table employee add primary key(ssn)"))
  {
    fprintf(stderr,"%s\n",mysql_error(conn));
    exit(1);
  }
 if(mysql_query(conn,"select * from employee"))
   {
     fprintf(stderr,"%s\n",mysql_error(conn));
      exit(1);

   }
  res=mysql_use_result(conn);
 while((row=mysql_fetch_row(res))!=NULL)
    printf("%s",row[0]);
mysql_free_result(res);
}
