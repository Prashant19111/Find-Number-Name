#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void find_name(int i,char *s1,FILE *ptr)
{
    char s2[20],s3[20];
    int j;
    while(!feof(ptr))
  {
         fgets(s2,i+1,ptr);
         j=strcmp(s2,s1);
         
        if(j>0||j<0)
      {
          strcpy(s3,s2);
          fgets(s2,8,ptr);
          strcat(s3,s2);
      }
     
      if(j==0)
      { 
        printf("Name of operator of this no. is %s",s3);
        break;
      }
      
  }
  if(j!=0)
    printf("enter a valid no.");
}
void find_number(int i, char *s1 ,FILE *ptr)
{
    char s2[20];
    int j=1;
    while(!feof(ptr))
   {
        fgets(s2,i+1,ptr);
      if(j==0)
      { 
        fgets(s2,11,ptr);
        printf(" IS %s",s2);
        break;
      }
     
      j=strcmp(s2,s1);
      
      if(j==0)
      {
        printf("PHN NO. OF %s",s2);
      }
      
   }
   if(j!=0)
   printf("enter a valid Name");
}

int main()
{
   FILE *ptr;
   int i,a;
   char s1[20];
   char b;
   
   ptr=fopen("contact.txt","r");
  printf("***please ensure that the file you enter is correct ");
  printf("and contact details in file are given formate as given***\n");
  printf("-Name\n-Contact Number\n");
   
  if(ptr==NULL)
    {
        printf("File not found please check file name properly");
        exit(1);
    }
     printf("enter 1 for find name from the number and 2 for find number form the name\n");
     scanf("%d",&a);
     scanf("%c",&b);
    // fflush(stdin);
    
  if(a==1)
   {
    printf("Enter a number\n");
    gets(s1);
    i=strlen(s1);
 
    find_name(i,s1,ptr);
   }
   if(a==2)
   {
      printf("enter a name\n");
      gets(s1);
      i=strlen(s1);
  
      find_number(i,s1,ptr);
     
   }

    return 0;
}
