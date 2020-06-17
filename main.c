#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<process.h>
struct login
{
    char username[30];
    char passward [30];
}l;
struct phonebook
{
    char FirstName[30];
    char LastName[30];
    char MobileNumber[30]

}p;
struct content
{
  char FirstName[30];
    char LastName[30];
    char MobileNumber[30];
}c;
void gotoxy(int x,int y);
void ADDENTRY();
void DISPLAY();
void SEARCH_by_FIRSTNAME(char []);
void SEARCH_by_LASTNAME(char []);
void REMOVE(FILE *fp);
void passward();
int main()
{
     char filename[100];
    char str[100];
    FILE *fp1,*fp2;
    int del_line_no;
    int line_no=0;
     int r,q;
     int option;
    passward();

    do
      {
          system("cls");
   printf("\nWHAT OPTION DO YOU WANT");
   printf("\n>>PRESS 1 TO ENTRY DATA");
   printf("\n>>PRESS 2 TO DISPLAY DATA");
   printf("\n>>PRESS 3 TO SEARCH BY FITSTNAME DATA");
   printf("\n>>PRESS 4 TO SEARCH BY LASTNAME DATA");
   printf("\n>>PRESS 5 TO SEARCH BY MOBILENUMBER DATA");
   printf("\n>>PRESS 6 TO REMOVE DATA");
   printf("\n>>PRESS 7 TO EXIT");
    printf("\nCHOOSE OPTION:");
   scanf("%d",&option);
   if(option>=1 && option<=7)
   {
      switch(option)
   {
   case 1:
       system("cls");
    ADDENTRY();
    break;
   case 2:
    system("cls");
    DISPLAY();
    break;
   case 3:
       system("cls");
       printf("\nENTER FIRST_NAME:");
	char name1 [10];
	fflush(stdin);
	gets(name1);
	SEARCH_by_FIRSTNAME(name1);
    break;
   case 4:
       system("cls");
       printf("\nENTER LAST_NAME:");
	char name2[10];
	fflush(stdin);
	gets(name2);
	SEARCH_by_LASTNAME(name2);
	break;
   case 5:
    system("cls");
       printf("\nENTER MOBILE_NUMBER:");
	char number1[10];
	fflush(stdin);
	gets(number1);
	SEARCH_by_MOBILENUMBER(number1);
	break;
   case 6:
       system("cls");
    printf("ENTER THE FILE:");
    scanf("%s",filename);

    fp1=fopen(filename,"r");
    printf("\nCONECT OF FILE BEFORE DELET:\n");
    REMOVE(fp1);
    rewind(fp1);

   fp2=fopen("P.txt","w");
    printf("\nENTER THE no.OF THE LINE TO BE DELET:");
    scanf("%d",&del_line_no);

    while(fgets(str,99,fp1)!=NULL)
    {
        line_no++;
        if(line_no!=del_line_no)
        {
            fputs(str,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    remove(filename);
    rename("P.txt", filename);

    fp1=fopen(filename,"r");
    printf("\nCONECT OF FILE AFTER REMOVE:\n");
    REMOVE(fp1);
    //line_no--;
    fclose(fp1);
   break;
   case 7:
    exit(0);
   }
   }


else
    printf("INVALID PRESS!!!!!!");
    printf("\nDO YOU WHAT CONTINUE y/n");
    option=getch();

      }
      while(option=='y');
return 0;
}
void passward()
{
 	int i=0;
 	char ch;
l1:
    printf("\n\n\n\n\t\t\tENTER THE USER NAME:");
    scanf("%s",l.username);

if(strcmp(l.username,"azi")==0)
    {
        goto l2;
    }

    else
    {
         printf("INCORRENT USER NAME!!!");
         goto l1;

    }
l2:
        printf("\n\n\t\t\tENTER PASSWARD:");
          while (1){

      ch = getch();

      if (ch == 13)
         {
             l.passward[i]='\0';
             break;
         }
      if (ch == 8)
      {
         if(i>0){
         i--;
         printf("\b \b");
         }
         continue;
      }
      else
      {
      l.passward[i++]=ch;
      ch = '*';
      putch(ch);
      }
   }



    if(strcmp(l.passward,"azi")==0)
       {
           goto end;
       }
       else
       {
            printf("\n\t\t\tINCORRENT PASSWARD!!!");
            goto l2;

       }

    end:
      exit;

}

void ADDENTRY()
{

    FILE *fp;
    printf("\nENTER THE FIRST_NAME:");
    scanf("%s",p.FirstName);
    printf("\nENTER THE LAST_NAME:");
    scanf("%s",p.LastName);
    printf("\nENTER THE MOBILE_NUMBER:");
    scanf("%s",p.MobileNumber);

    fp=fopen("PHONE_BOOK.txt","a");
    fprintf(fp,"%s %s %s\n",p.FirstName,p.LastName,p.MobileNumber);
    fclose(fp);
}
void DISPLAY()
{

    FILE *fp;

    fp=fopen("PHONE_BOOK.txt","r");

     if(fp==NULL)
    {
        printf("\nFILE NOT FIND");
        return;
    }

    while(fscanf(fp,"%s %s %s",c.FirstName,c.LastName,c.MobileNumber)!=EOF)
    {

            printf("\nFIRST NAME:%s",c.FirstName);
            printf("\nLAST_NAME:%s",c.LastName);
            printf("\nMOBILE_NUMBER:%s",c.MobileNumber);


    }
     fclose(fp);
}
void SEARCH_by_FIRSTNAME(char name[])
{

    FILE *fp;
    int r;
    fp=fopen("PHONE_BOOK.txt","r");

     if(fp==NULL)
    {
        printf("\nFILE NOT FIND");
        return;
    }

    while(fscanf(fp,"%s %s %s",c.FirstName,c.LastName,c.MobileNumber)!=EOF)
    {
        r=strcmp(c.FirstName,name);
        if(r==0)
        {
            printf("\nFIRST_NAME:%s",c.FirstName);
            printf("\nLAST_NAME:%s",c.LastName);
            printf("\nMOBILE_NUMBER:%s",c.MobileNumber);

        }

    }
 fclose(fp);

}
void SEARCH_by_LASTNAME(char name[])
{

    FILE *fp;
    int r;
    fp=fopen("PHONE_BOOK.txt","r");

     if(fp==NULL)
    {
        printf("\nFILE NOT FIND");
        return;
    }

    while(fscanf(fp,"%s %s %s",c.FirstName,c.LastName,c.MobileNumber)!=EOF)
    {
        r=strcmp(c.LastName,name);
        if(r==0)
        {
            printf("\nFIRST_NAME:%s",c.FirstName);
            printf("\nLAST_NAME:%s",c.LastName);
            printf("\nMOBILE_NUMBER:%s",c.MobileNumber);

        }

    }
 fclose(fp);

}
void SEARCH_by_MOBILENUMBER(char number[])
{

    FILE *fp;
    int r;
    fp=fopen("PHONE_BOOK.txt","r");

     if(fp==NULL)
    {
        printf("\nFILE NOT FIND");
        return;
    }

    while(fscanf(fp,"%s %s %s",c.FirstName,c.LastName,c.MobileNumber)!=EOF)
    {
        r=strcmp(c.MobileNumber,number);
        if(r==0)
        {
            printf("\nFIRST_NAME:%s",c.FirstName);
            printf("\nLAST_NAME:%s",c.LastName);
            printf("\nMOBILE_NUMBER:%s",c.MobileNumber);

        }

    }
 fclose(fp);

}

void REMOVE(FILE *fp)
{

     char ch;
    while((ch =fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
}




