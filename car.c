#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

void login(void);
void menu(void);
void pass(void);
void search(void);
void list(void);
void book(void);
void report(void);
void cdetail(void);
void sdetail(void);
void sedan();
void coupe();
void hatch();
void i();

//global files
FILE *fp,*ft,*fs;
char password[10]={"123"} ;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct book
{
    int id;
    char name[20];
    char add[20];
    int ph;
    int dl;
    char cou[10];
	char sed[10];
	char ii[10];
	char h[10];
};
struct book a;

void returnfunc(void)
{
    {
	printf(" \nPress ENTER to return to main menu");
    }
    b:
    if(getch()==13) //allow only use of enter
    menu();
    else
    goto b;
}

void pass()
{
	char ch,passwd[10];
	int i=0;
	system("cls");
	gotoxy(40,5);
   	printf("***Password Protected***");
   	gotoxy(40,7);
   	printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();
	putch('*');
	if(ch!=13)
	{
	passwd[i]=ch;
	i++;
	}
   }
   passwd[i] = '\0';
   if(strcmp(passwd,password)==0)
   {	gotoxy(40,8);
	printf("Password match");
	gotoxy(40,10);
	printf("Press any key to countinue.....");
	getch();
	menu();
   }
   else
   {
	 gotoxy(15,16);
	 
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 pass();
   }
}

void login()
{
	system("COLOR 2");
	gotoxy(40,8);
	printf("SPS AUTOCARS");
	char c;
	c=getch();
	if(c=13)
	{
	pass();
	}
	else
	{
	login();
	getch();
	}
}

void menu()
{
	system("cls");
	char c,ch;
	printf("SPS AUTOCARS\n");
	printf("1. Cars\n");
	printf("2. Book A Car\n");
	printf("3. Search\n");
	printf("4. Customer Details\n");
	printf("5. Showroom Details\n");
	printf("6. Exit\n");
	c=getch();
	switch(c)
	{
		case '1': 	list();
					break;
		case '2': 	book();
					break;
		case '3': 	search();
					break;
		case '4': 	cdetail();
					break;
		case '5': 	sdetail();
					break;
		case '6':	exit(0);
					break;			
		default : 	printf("Incorrect Choice\n");
					Sleep(1000);
					menu();													 
	}
}

void list()
{	
	system("cls");
	char c;
	printf("1. Sedan\n");
	
	printf("2. Coupé\n");
	
	printf("3. Hatch");
	
	printf("4. BMWi\n");
	c=getch();
	switch(c)
	{
		case '1': 	sedan();
					break;
		case '2': 	coupe();
					break;
		case '3': 	hatch();
					break;
		case '4': 	i();
					break;
		default :	printf("Incorrect choice\n");
					Sleep(1000);
					list();										
	}
}

void book()
{
					  fp=fopen("book.txt","ab+");
					  printf("ENTER THE BOOKING NUMBER:->");
                      scanf("%d",&a.id);
                      //fflush(stdin);
                      printf("\nENTER THE NAME               :->");
                      scanf("%s",&a.name);
                      //fflush(stdin);
                      printf("\nENTER THE ADDRESS            :->");
                      scanf("%s",&a.add);
                      fwrite(&a,sizeof(a),1,fp);
                      fflush(stdin);
}

void search()
{
	int d;
    system("cls");
    fp=fopen("book.txt","ab+"); //open file for reading propose
    rewind(fp);
    printf("Enter the booking id:");
	scanf("%d",&d);
    while(fread(&a,sizeof(a),1,fp)==1)
	{
		if(strcmp(d,&a.id)==0)
		{
		    gotoxy(20,7);
		    printf("The Booking is available");
		    gotoxy(20,9);
		    printf("Booking id. :%d",a.id);
		    gotoxy(20,10);
		    printf("Name:%s",a.name);
		    gotoxy(20,11);
		    printf("Ph no.:%s ",a.ph);
		    gotoxy(20,12);
		  //findbook='t';
		}

	    }
	    if(a.id!=d)
	    //if(findbook!='t')  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    search();
	    else
	    menu();
}

void cdetail()
{
	int j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Customer List*****************************");
    gotoxy(2,2);
    printf("ID    		NAME     	PH NO.");
    j=4;
    fp=fopen("book.txt","ab+");
    while(fread(&a,sizeof(a),1,fp))
    {
		gotoxy(3,j);
		printf("%s",a.id);
		gotoxy(16,j);
		printf("%d",a.name);
		gotoxy(22,j);
		printf("%s",a.ph);
		gotoxy(50,j);
		printf("\n\n");
		j++;
    }
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}

void sdetail()
{
	system("cls");
	printf("SPS AUTOCARS\n");
	printf("Authorized dealers of BMW\n");
	printf("Contact: 8892739305");
	returnfunc();
}

void sedan()
{
}
void coupe()
{
}
void hatch()
{
}
void i()
{
}

int main()
{
	system("cls");
	login();
  	getch();
   	return 0;

}
