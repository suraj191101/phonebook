#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    char mble_no[12];
    char sex[8];
};
void menu();
void start();
void back();
void addrecord();
void showlistrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t**********WELCOME TO PHONEBOOK*************");
printf("\n\n\t\t\t  MAIN MENU\t\t\n\n");
printf("\t1.Add New   \t2.Show List   \t3.Modify  \t4.Search \t5.Delete \t6.EXIT\t\n");
switch(getch())
{
    case '1':
        addrecord();
        break;
    case '2':
        showlistrecord();
        break;
    case '3':
        modifyrecord();
        break;
    case '4':
        searchrecord();
        break;
    case '5':
        deleterecord();
        break;
    case '6':
        exit(0);
        break;
    default:
        system("cls");
        printf("\nEnter 1 to 6 only");
        printf("\n Enter any key");
        getch();
menu();
}
}
void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("phonebook.txt","ab+");
        printf("\n Enter name: ");
        gets(p.name);
        printf("\nEnter the address: ");
        gets(p.address);
        printf("\nEnter father's name: ");
        gets(p.father_name);
        printf("\nEnter mother's name: ");
        gets(p.mother_name);
        printf("\nEnter phone no.: +91 ");
        gets(p.mble_no);
        printf("Enter sex:");
        gets(p.sex);
        fwrite(&p,sizeof(p),1,f);
fflush(stdin);
    printf("\nrecord saved");
fclose(f);
    printf("\n\nEnter any key");
    getch();
    system("cls");
    menu();
}
void showlistrecord()
{
struct person p;
FILE *f;
f=fopen("phonebook.txt","rb");
if(f==NULL)
{
printf("\nfile opening error in the list!!\n");
exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
    printf("\n\n\n YOUR RECORD IS\n\n ");
    printf("\nName=%s\nAddress=%s\nFather's name=%s\nMother's name=%s\nMobile no=+91 %s\nSex=%s\n",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex);
    getch();
}
fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
menu();
}
void modifyrecord()
{
int c;
FILE *f;
int flag=0;
struct person p,s;
char  name[50];
f=fopen("phonebook.txt","rb+");
if(f==NULL)
{

    printf("\nCONTACT'S DATA NOT ADDED YET.\n");
    exit(1);
}
else
{
    system("cls");
	printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
    gets(name);
    while(fread(&p,sizeof(p),1,f)==1)
    {
        if(strcmp(name,p.name)==0)
        {
            printf("\n Enter name:");
            gets(s.name);
            printf("\nEnter the address:");
            gets(s.address);
            printf("\nEnter father's name:");
            gets(s.father_name);
            printf("\nEnter mother's name:");
            gets(s.mother_name);
            printf("\nEnter phone no: +91 ");
            gets(s.mble_no);
            printf("\nEnter sex:");
            gets(s.sex);
            fseek(f,-sizeof(p),SEEK_CUR);
            fwrite(&s,sizeof(p),1,f);
            flag=1;
            break;
        }
        fflush(stdin);
    }
    if(flag==1)
    {
        printf("\n your data id modified");
    }
    else
    {
        printf(" \n data is not found");
    }
fclose(f);
}
printf("\n Enter any key");
getch();
system("cls");
menu();
}
void searchrecord()
{
struct person p;
FILE *f;
char name[100];
f=fopen("phonebook.txt","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);
}
printf("\nEnter name of person to search\n");
gets(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\nAddress:%s\nFather's name:%s\nMother's name:%s\nMobile no:+91 %s\nSex:%s\n\n",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex);
    }
else
    {
        printf("file not found");
    }
}
 fclose(f);
  printf("\n Enter any key");
	 getch();
    system("cls");
menu();
}
void deleterecord()
{
struct person p;
FILE *f,*ft;
int flag;
char name[100];
f=fopen("phonebook.txt","rb");
if(f==NULL)
    {
        printf("\nCONTACT'S DATA NOT ADDED YET.\n");
	}
	else
	{
		ft=fopen("phonebook.txt","wb+");
		if(ft==NULL)
            printf("file opening error");
		else
        {
            printf("Enter CONTACT'S NAME:");
            gets(name);
            fflush(stdin);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(p.name,name)!=0)
                    fwrite(&p,sizeof(p),1,ft);
                if(strcmp(p.name,name)==0)
                    flag=1;
		}
        fclose(f);
        fclose(ft);
        if(flag!=1)
        {
            printf("\nNO CONACT'S RECORD TO DELETE.\n");
            remove("temp.txt");
        }
		else
		{
			remove("phonebook.txt");
			rename("temp.txt","phonebook.txt");
			printf("\nRECORD DELETED SUCCESSFULLY.\n");
		}
	}
}
 printf("\n Enter any key");
getch();
system("cls");
menu();
}
