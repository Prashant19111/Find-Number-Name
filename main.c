#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void entry(){
  int n;
  FILE *ptr;
  char fname[50],lname[50],num[10],c;
  i:system("cls");
  printf("Adding a New Entry\n");
  ptr=fopen("contact.txt", "a");
  fflush(stdin);
  printf("Enter First Name:");
  scanf("%s",fname);
  fflush(stdin);
  printf("Enter Last Name:");
  scanf("%s",lname);
  fprintf(ptr,"\n%s %s",fname,lname);
  fflush(stdin);
  printf("Enter 10 Digit Mobile No. Number:");
  scanf("%s",num);
  fprintf(ptr,"\n%s",num);
  fclose(ptr);
  printf("\n____________________________________________________________________\n");
  j:printf("Add Anothor Entry\n1-Yes\n2-No\n");
  scanf("%d",&n);
  if(n==1)
  goto i;
  else if(n==2)
  return;
  else{
    printf("\ninvalid choice");
    goto j;

  }

}
void find_name(int i, char *s1, FILE *ptr)
{
  // char s2[20],s3[20];
  char name[50], num[12];
  int j = 1,k=0;
  while (!feof(ptr))
  {
    if (j % 2 != 0)
    {
      fgets(name, 50, ptr);
    }
    if (j % 2 == 0)
    {
      fgets(num, i+1, ptr);
      if (!strcmp(s1, num))
      {
        printf("name is %s\n",name);
        k=1;
        break;
      }
      fgets(num, 2, ptr);
    }
    j++;
  }

  if (k == 0)
    printf("enter a valid no.\n");
}
void find_number(int i, char *s1, FILE *ptr)
{
  char s2[20];
  int j = 1;
  while (!feof(ptr))
  {
    fgets(s2, i + 1, ptr);
    if (j == 0)
    {
      fgets(s2, 11, ptr);
      printf(" IS %s\n", s2);
      break;
    }

    j = strcmp(s2, s1);

    if (j == 0)
    {
      printf("PHN NO. OF %s", s2);
    }
  }
  if (j != 0)
    printf("enter a valid Name\n");
}

int main()
{
  FILE *ptr;
  int i, a,c;
  char s1[20];
  char b;
  system("cls");
  printf("***please ensure that the file you enter is correct ");
  printf("and contact details in file are given formate as given***\n");
  printf("-Name\n-Contact Number\n");
  start:printf("Press \n1-find name from the number!\n2-find number form the name!\n3-Add a new entry!\n");
  scanf("%d", &a);
  scanf("%c", &b);
  ptr = fopen("contact.txt", "r");

  if (ptr == NULL)
  {
    printf("File not found please check file name properly");
    exit(1);
  }
  
  // fflush(stdin);

  if (a == 1)
  {
    system("cls");
    printf("Enter a number\n");
    gets(s1);
    i = strlen(s1);

    find_name(i, s1, ptr);
    printf("Press 1 for exit or 2 for continue\n");
    scanf("%d",&c);
    system("cls");
    if(c==1)
    goto end;
    if(c==2)
    goto start;
  }
  if (a == 2)
  {
    system("cls");
    printf("enter a name\n");
    gets(s1);
    i = strlen(s1);

    find_number(i, s1, ptr);
    printf("Press 1 for exit or 2 for continue\n");
    scanf("%d",&c);
    system("cls");
    if(c==1)
    goto end;
    if(c==2)
    goto start;
  }
  if(a==3){
    entry();
    printf("Press 1 for exit or 2 for continue\n");
    scanf("%d",&c);
    system("cls");
    if(c==1)
    goto end;
    if(c==2)
    goto start;
  }
   if(a>3){
       printf("invalid choice\n");
       printf("Press 1 for exit or 2 for continue\n");
       scanf("%d",&c);
       if(c==1)
       goto end;
       if(c==2)
       goto start;
       goto start;
   }
  end:
  fclose(ptr);
  printf("\nTHANK YOU!!!");
  return 0;
}
