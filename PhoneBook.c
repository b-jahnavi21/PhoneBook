#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    long long int mble_no;
    char sex[8];
    char mail[100];
    char citizen_no[20];
};
void menu();
void display();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 9f");
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
	printf("\t\t*WELCOME TO PHONEBOOK");
	printf("\n\n\t\t\t  MENU\t\t\n\n");
	printf("\t1.Add New   \t2.List   \t3.Exit  \n\t");
	printf("4.Modify \t5.Search\t6.Delete\n\n");
	switch(getch())
	{
    	case '1':
            addrecord();
    		break;
   		case '2':
			listrecord();
    		break;
    	case '3':
			exit(0);
    		break;
    	case '4':
			modifyrecord();
    		break;
    	case '5': 
			searchrecord();
    		break;
    	case '6':
			deleterecord();
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
        f=fopen("project.txt","a+");
        printf("\n Enter name: ");
        display(p.name);
        printf("\nEnter the address: ");
        display(p.address);
        printf("\nEnter father name: ");
        display(p.father_name);
        printf("\nEnter mother name: ");
        display(p.mother_name);
        printf("\nEnter phone no.:");
        scanf("%lld",&p.mble_no);
        printf("Enter sex:");
        display(p.sex);
        printf("\nEnter e-mail:");
        display(p.mail);
        printf("\nEnter citizen no:");
        display(p.citizen_no);
        fwrite(&p,sizeof(p),1,f);
		fflush(stdin);
        printf("\nrecord saved");
		fclose(f);
		printf("\n\nEnter any key");
		getch();
    	system("cls");
    	menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
	f=fopen("project.txt","r");
	if(f==NULL)
	{
		printf("\nfile opening error in listing :");
		exit(1);
	}
	while(fread(&p,sizeof(p),1,f)==1)
	{
    	printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\n",p.name);
        printf("Father name=%s\n",p.father_name);
        printf("Adress=%s\n",p.address);
		printf("Mother name=%s\n",p.mother_name);
		printf("Mobile no=%lld\n",p.mble_no);
		printf("Sex=%s\n",p.sex);
		printf("E-mail=%s\n",p.mail);
		printf("Citizen no=%s",p.citizen_no);
		getch();
		system("cls");
	}
	fclose(f);
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
	int flag=0;
	f=fopen("project.txt","r");
	if(f==NULL)
	{
    	printf("\n error in opening\a\a\a\a");
    	exit(1);
	}
	printf("\nEnter name of person to search\n");
	display(name);
	while(fread(&p,sizeof(p),1,f)==1)
	{
    	if(strcmp(p.name,name)==0)
    	{
        	printf("\n\tDetail Information About %s",name);
        	printf("\nName=%s\n",p.name);
        	printf("Father name=%s\n",p.father_name);
        	printf("Adress=%s\n",p.address);
			printf("Mother name=%s\n",p.mother_name);
			printf("Mobile no=%lld\n",p.mble_no);
			printf("Sex=%s\n",p.sex);
			printf("E-mail=%s\n",p.mail);
			printf("Citizen no=%s",p.citizen_no);
		}
        if(strcmp(p.name,name)!=0)
        {
        	flag=1;
		}
	}
	if (flag>0)
		printf("\nData not found for the entry %s",name);
		
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
	f=fopen("project.txt","r");
	if(f==NULL)
	{
		printf("CONTACT'S DATA NOT ADDED YET.");
	}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)
			printf("file opaning error");
		else
		{
			printf("\nEnter CONTACT'S NAME:\n");
			display(name);
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
				printf("NO CONACT'S RECORD TO DELETE.");
				remove("temp.txt");
			}
			else
			{
				remove("project");
				rename("temp.txt","project");
				printf("\nRECORD DELETED SUCCESSFULLY.");
			}
		}
	}
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
	f=fopen("project.txt","r+");
	if(f==NULL)
	{	
		printf("CONTACT'S DATA NOT ADDED YET.");
		exit(1);
	}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        display(name);
        while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {
                    printf("\n Enter name:");
                    display(s.name);
                    printf("\nEnter the address:");
                    display(s.address);
                    printf("\nEnter father name:");
                    display(s.father_name);
                    printf("\nEnter mother name:");
                    display(s.mother_name);
                    printf("\nEnter phone no:");
                    scanf("%lld",&s.mble_no);
                    printf("\nEnter sex:");
                    display(s.sex);
                    printf("\nEnter e-mail:");
                    display(s.mail);
                    printf("\nEnter citizen no: ");
                    display(s.citizen_no);
                    fseek(f,sizeof(p),SEEK_CUR);
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
void display(char *name)
{
	int i=0,j;
	char c,ch;
    do
    {
        c=getch();
        if(c!=8&&c!=13)
        {
            *(name+i)=c;
            putch(c);
            i++;
        }
        if(c==8)
        {
            if(i>0)
            {
                i--;
            }
            system("cls");
            for(j=0;j<i;j++)
            {
                ch=*(name+j);
                putch(ch);
            }
		}
    }
	while(c!=13);
    *(name+i)='\0';
}
