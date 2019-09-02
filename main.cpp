#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
void animation();
int time();
void search_id();
void search_seat();
void ventury();
void box();
void box1();
void show_entry();
void lbox();
void wbox();
void book();
void search_name();
void booked();
void SHOWS();
void book_show();
void main_menu();
void BOOKED_REPORT();
void main_box();
void welcome();
void sHOW_list();
void search();

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;
struct seats
{
	char seat_name[50];
	char number_seats[3];
	float total;
	char price_ps[8];
	char movie_name[30];
 }temp;
FILE *ptr;

char a[10];
struct show
{
	int show_id;
	char show_name[25];
	char date[20];
	char time[11];

}temp1;
//=========================Time & Date ====================
int time(void)
{


    time_t t = time(0);
    struct tm * now = localtime( & t );

	gotoxy(55,46);
	printf("Date: %d-%d-%d ",now->tm_mday,now->tm_mon+1,now->tm_year-100);
	gotoxy(55,48);
	printf("Time: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
	return 0;
}
//=======================Animation ==========================
void animation()
{
	for (i=45; i>=1; i--)
	{
		Sleep(20);
		gotoxy(1,i);

	}
	for (i=1; i<=20; i++)
	{
      	Sleep(30);
		gotoxy(1,i);
	}
}
//=========================== validation =========================
void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;

		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;

		}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;

		}
	}

	t[i]='\0';
}
//============================================================================
void box()
{
   for(i=3;i<=79;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
		gotoxy(78,45);
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=3;i<=45;i++)
	{
		gotoxy(3,i);
		printf("%c",219);
		gotoxy(79,i);
		printf("%c",219);
	}
}
void wbox()
{
	for(i=5;i<=75;i++)
	{
		gotoxy(i,5);
		printf("%c",219);
		gotoxy(74,40);
		printf("%c",219);
		gotoxy(i,40);
		printf("%c",219);
	}

	for(i=5;i<=40;i++)
	{
		gotoxy(5,i);
		printf("%c",219);
		gotoxy(75,i);
		printf("%c",219);
	}
}
//=========================welcome screen ==============
void welcome()
{
  system("cls");
	for(int m=0;m<16;m++)
	{	wbox();
	for(i=0;i<16;i++)
	{
		gotoxy(35,20);
		printf("WELCOME");
        gotoxy(38,22);
		printf("TO");
    	gotoxy(28,24);
		printf("MOVIE BOOKING SYSTEM");
		gotoxy(52,45);
		printf("Loading......");
		Sleep(10);
	}	} }
//============================ label ==========
void lbox()
{
	gotoxy(25,6);
	printf("%c",201);
	for(i=26;i<55;i++)
	{
		gotoxy(i,6);
		printf("%c",205);
	}
	gotoxy(55,6);
	printf("%c",187);
	gotoxy(25,6);
	for(i=6;i<8;i++)
	{
		gotoxy(25,i+1);
		printf("%c",186);
	}
	gotoxy(25,9);
	printf("%c",200);
	for(i=26;i<55;i++)
	{
		gotoxy(i,9);
		printf("%c",205);
	}
	gotoxy(55,9);
	printf("%c",188);
	gotoxy(55,6);
	for(i=6;i<8;i++)
	{
		gotoxy(55,i+1);
		printf("%c",186);
	}
}
//============================small box ===============
void box1()
{
	gotoxy(1,3);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,3);
		printf("%c",205);
	}

	gotoxy(80,3);
	printf("%c",187);
	gotoxy(1,3);
	for(i=4;i<10;i++)
	{
		gotoxy(1,i);
		printf("%c",186);
	}
	gotoxy(1,9);
	for(i=4;i<8;i++)
	{
		gotoxy(80,i);
		printf("%c",186);
	}
}
void main_box()
{
	gotoxy(1,6);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,6);
		printf("%c",205);
	}

	gotoxy(80,6);
	printf("%c",187);
	gotoxy(1,6);
	for(i=5;i<35;i++)
	{
		gotoxy(1,2+i);
		printf("%c",186);
	}
	gotoxy(1,37);
	printf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,37);
		printf("%c",205);
	}
	gotoxy(80,37);
	printf("%c",188);
	gotoxy(80,6);
	for(i=5;i<35;i++)
	{
		gotoxy(80,2+i);
		printf("%c",186);
	}
}
void main_menu()
{
  char ch;

	do
	{
      system("cls");

		gotoxy(25,11);
        printf("* AVAILABLE SHOWS");

		gotoxy(25,14);
        printf("* BOOK SHOW");


		gotoxy(25,17);
		printf("* MY BOOKINGS");

		gotoxy(25,20);
        printf("* Exit");
		time();
		box1();
		main_box();
		gotoxy(30,5);
		printf("WELCOME TO MOVIES ");
		gotoxy(10,40);
		printf("Press ");
		gotoxy(16,40);
	printf("First Character for further Menu  ");
		ch=toupper(getche());
		switch(ch)
		{
			case 'A':SHOWS();
				 break;
			case 'B':book_show();
				 break;
			case 'M':booked();
				 break;
			case 'E':gotoxy(23,20);

			printf("Do you want to exit now? Y/N :");
			Sleep(100);
			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{
				animation();
				system("cls");

				gotoxy(35,20);
				printf(" Please wait.....");
				Sleep(2000);
				exit(0);
			}
			else
			{
				main_menu();
			}

			default:
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (M,B,A).");
			getch();
		}
	}while(ch!='E');
}
//=========================For SHOWS ===========================
void SHOWS()
{
  char ch;
	do
	{
	  system("cls");
	  gotoxy(34,3);

	  printf("--------------");
	  gotoxy(35,4);

	  printf("SHOW MENU");
	  gotoxy(34,5);

	  printf("--------------");
	  gotoxy(25,11);
      printf("Add New SHOW");


	  gotoxy(25,16);

	  printf("Search SHOW");
	  gotoxy(25,23);

	  printf("List of Existing SHOWS");
	  gotoxy(25,27);

	  printf("Main Menu");
	  main_box();

	  gotoxy(10,40);

	  printf("Press First Character for further Operation ");


	  ch=toupper(getche());
	  switch(ch)
	  {
		case 'A':animation();
			 show_entry();
			 break;

		case 'L':animation();
			 sHOW_list();
			 break;
		case 'S':search();
			 break;
		case 'M':main_menu();
			 break;
		default:
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (A,L,U,S,M).");
			getch();
	  }
	}while(ch!='M');

}
//=========================For booking show ===========================
void book_show()
{
	char ch;
	do
	{
	  system("cls");

	  gotoxy(34,3);

	  printf("----------");
	  gotoxy(35,4);
	  printf("Show Menu");
	  gotoxy(34,5);
	  printf("----------");
	  gotoxy(25,15);
	  printf("Book seat");
	  gotoxy(25,19);
	  printf("Available seats");
      gotoxy(25,24);
      printf("Shows");
	  gotoxy(25,29);
	  printf("Main Menu");
	  main_box();
	  gotoxy(10,40);

	  printf("Press First Character for further Operations  ");
 ch=toupper(getche());
	  switch(ch)
	  {
		case 'B':book();
			 break;

		case 'A':search_seat();
			 break;

		case 'M':main_menu();
			 break;

		case 'S':sHOW_list();
                break;
		default:
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (A,B,M).");
			getch();
	  }
	}while(ch!='M');

}
//=========================For booked report ===========================
void booked()
{
	char ch;
	do
	{
	  system("cls");

	  gotoxy(34,3);

	  printf("---------------");
	  gotoxy(35,4);
	  printf("booked report");
	  gotoxy(34,5);
	  printf("---------------");
	  gotoxy(25,12);

         printf("Booked Report");
         gotoxy(25,20);

	  printf("Main Menu");

	  main_box();
	  gotoxy(10,40);

	  printf("Press First Character for further Operations  ");


	  ch=toupper(getche());
	  switch(ch)
	  {

		case 'B':BOOKED_REPORT();
			 break;

		case 'M':main_menu();
			 break;
		default:
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (B,M).");
			getch();
	  }
	}while(ch!='M');

}
//============================    get show_id     =====================================================
int getshow_id()
{
  int id;
 FILE *pk;
	 pk=fopen("show.dat","r");
	 if(pk==NULL)
	 {
		gotoxy(22,15);
		printf("Data not Found.....");
		getch();
	 }
	 else
	 {
         id=100;
		rewind(pk);
		while(fscanf(pk,"%d %s %s %s ",&temp1.show_id,temp1.show_name,temp1.date,temp1.time)!=EOF)
		{
		    id=temp1.show_id;
		}
	 }
	 fclose(pk);
	 return id+1;
}
//================================FOR SHOW ENTRY=====================================================================
void show_entry()
{

 char ch;
 FILE *fp;
 system("cls");

	   fp=fopen("show.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		exit(0);
	   }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {
		system("cls");

		time();
		box();
		lbox();
		gotoxy(30,8);
		printf(" SHOW ENTRY ");
		gotoxy(8,13);

        temp1.show_id=getshow_id();
		printf("SHOW ID  :%d  ",temp1.show_id);

		gotoxy(39,13);
		printf("SHOW NAME : ");
		gotoxy(8,18);
		printf("DAY       : ");
		gotoxy(39,18);
		printf("TIME   : ");


		gotoxy(55,13);

		ventry(temp1.show_name,0);
		gotoxy(22,18);
		ventry(temp1.date,0);

		gotoxy(55,18);
		ventry(temp1.time,1);


		gotoxy(20,30);

		printf("Save");


		gotoxy(28,30);

		printf("Cancel");

		gotoxy(18,36);
		printf("Press First charecter for the operation : ");
		ch=toupper(getch());
		if(ch=='S')
		{
			fprintf(fp,"%d %s %s %s \n\n",temp1.show_id,temp1.show_name,temp1.date,temp1.time);
			fprintf(fp,"\n");
			system("cls");
			gotoxy(20,20);
			printf("SHOW Added successfully!!!!!");
			Sleep(200);
		}

        else{ SHOWS();
                           }
	   }
	   fclose(fp);

}
//=========FOR SUPPLIER DISPLAY LIST ==========
void sHOW_list()
{
 char ch;
 int j;
 FILE *ptr1;
 system("cls");
	   ptr1=fopen("show.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   box();
	   time();

           gotoxy(8,48);
	   printf("Press Anykey to go to  MENU !!!");

	   lbox();
	   gotoxy(30,8);
	   printf(" MOVIE LIST ");

	   gotoxy(5,10);
	   printf("ID.     MOVIE NAME.      DATE      TIME               ");
	   gotoxy(4,12);
	   i=14;
	   printf("=================================================================");
	   while(fscanf(ptr1,"%d %s %s %s ",&temp1.show_id,temp1.show_name,temp1.date,temp1.time)!=EOF)
	   {
		gotoxy(4,i);
		printf(" %d",temp1.show_id);
		gotoxy(9,i);
		printf(" %s",temp1.show_name);
		gotoxy(29,i);
		printf(" %s",temp1.date);
		gotoxy(41,i);
		printf(" %s",temp1.time);

		i=i+2;
	   }
	   getche();
}
//======================search supplier==================
void search()
{
  int ch;

	do
	 {
	   system("cls");

	   gotoxy(17,10);
	   printf(" Two options Available for searching ");
	   gotoxy(15,15);
	   printf("Search by ID number");

	   gotoxy(15,18);
	   printf("Search by Name");

	   gotoxy(15,21);
	   printf("Return");


	   main_box();
	   gotoxy(17,24);
	   printf("Press First character for the operation : ");
	   ch=toupper(getche());
	   switch(ch)
	   {
		case 'I':
			animation();
			search_id();

			break;
		case 'N':
			animation();
			search_name();
			break;
		case 'R':
			animation();
			show();
			break;
		default:
			gotoxy(22,18);
			printf("You entered wrong choice!!!!!");
			getch();
	   }
	   }while(ch!='R');

}
//=============================== Search by id =============================
void search_id()
{
  int id;
  FILE *fp;

	   fp=fopen("show.dat","r");
	   if(fp==NULL)
	   {
	     printf("file can't open!!!!");

	   }
	   system("cls");
	   box();
	   gotoxy(13,8);
	   printf("Enter id to be searched:");
	   scanf("%d",&id);
	   gotoxy(20,35);

	   printf("Press Any key to Return Back Menu ....");
	   gotoxy(12,14);
	   printf("ID.     MOVIE NAME.   DATE     TIME        ");
	   gotoxy(12,16);
	   i=18;
	   printf("==============================================================");
	   while(fscanf(fp,"%d %s %s %s ",&temp1.show_id,temp1.show_name,temp1.date,temp1.time)!=EOF)
	   {
		if(temp1.show_id==id)
		{
			gotoxy(10,i);
			printf(" %d",temp1.show_id);
			gotoxy(15,i);
			printf(" %s",temp1.show_name);
			gotoxy(30,i);
			printf(" %s",temp1.date);
			gotoxy(40,i);
			printf(" %s",temp1.time);

			i++;
			break;
		}
	   }
	   if(temp1.show_id!=id)
	   {
		gotoxy(20,30);
		printf("Record not found!");
	   }
	   fclose(fp);
	   getche();
}
//============================ Search by name =============================
void search_name()
{
  char name[20];
  FILE *fp;

	   fp=fopen("show.dat","r");
	   if(fp==NULL)
	   {
	     printf("file can't open!!!!");

	   }
	   system("cls");
	   box();
	   fp=fopen("show.dat","rb");
	   gotoxy(13,8);
	   printf(" Enter Show Name to be searched : ");
	   scanf("%s",&name);
	   gotoxy(20,35);

	   printf("Press Any key to Return Back Menu ....");
	   gotoxy(12,14);
	   printf("ID.     MOVIE NAME.   DATE     TIME        ");
	   gotoxy(12,16);
	   i=18;
	   printf("==============================================================");

	   while(fscanf(fp,"%d %s %s %s ",&temp1.show_id,temp1.show_name,temp1.date, temp1.time)!=EOF)
	   {
		if(strcmp(temp1.show_name,name)==0)
		{
			gotoxy(11,i);
			printf(" %d",temp1.show_id);
			gotoxy(15,i);
			printf(" %s",temp1.show_name);
			gotoxy(30,i);
			printf(" %s",temp1.date);
			gotoxy(40,i);
			printf(" %s",temp1.time);

			i++;
			break;
		}
	   }
	   if(strcmp(temp1.show_name,name)!=0)
	   {
		gotoxy(20,30);

		printf("Record not found!!!");
	   }
	   fclose(fp);
	   getche();
}
//============================ FOR BOOKING Seat    ===================
void book()
{
char ch;
    time_t t = time(0);
    struct tm * now = localtime( & t );

 FILE *fp;
 system("cls");

	   fp=fopen("seat.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		exit(0);
	   }
	   system("cls");
       ch='y';
	   while(ch=='y')
	   {
		system("cls");

		time();
		box();
		lbox();
		gotoxy(35,8);
		printf(" BOOK SEAT ");
            gotoxy(7,11);
			printf("MOVIE NAME  : ");

			gotoxy(7,16);
			printf("SEAT NAME  : ");

			gotoxy(7,26);
			printf("PRICE(1 SEAT) RS.: ");

			gotoxy(7,21);
			printf("NO. OF SEATS :  ");

       gotoxy(20,11);
       ventry(temp.movie_name,0);
		gotoxy(100,11);
        printf("check seat availability(Y/N): ");
		ch=toupper(getche());
		if(ch=='Y'){
		search_seat();}


                gotoxy(25,16);
                ventry(temp.seat_name,2);


		gotoxy(25,21);
		ventry(temp.number_seats,1);

		gotoxy(25,26);
		ventry(temp.price_ps,1);

                gotoxy(7,31);
			printf("==========================================================");
			temp.total=atof(temp.price_ps)*atof(temp.number_seats);


			gotoxy(10,33);
			printf("TOTAL  COST = Rs. %f",temp.total);

		gotoxy(20,35);
		printf("Save");

		gotoxy(28,35);
        printf("Cancel");
		gotoxy(18,38);
       printf("Press First character for the operation : ");

		ch=toupper(getche());
		if(ch=='S')
		{

      		fprintf(fp," %s %s %s %s %f\n",temp.seat_name,temp.movie_name,temp.number_seats,temp.price_ps,temp.total);
            fprintf(fp,"\n");
			system("cls");
			gotoxy(20,20);
			printf("Seat BOOKED successfully!!!!!!");
			gotoxy(20,25);
			printf("press any key to menu");


		}
	   fclose(fp);
   }
   getche();
    book_show();
}
//===================== view report =============================
void BOOKED_REPORT()
{
 char ch;
 int j;
 FILE *ptr1;
 system("cls");
	   ptr1=fopen("seat.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   box();
	   time();

           gotoxy(8,48);
	   printf("Press Anykey to go to  MENU !!!");

	   lbox();
	   gotoxy(30,8);
	   printf(" BOOKED REPORT ");

	   gotoxy(5,10);
	    printf("Seat  Movie    Number of seats     Price   Total amount ");
	   gotoxy(4,12);
	   i=14;
	   printf("==================================================================");
	   while(fscanf(ptr1,"%s %s %s %s %f",temp.seat_name,temp.movie_name,temp.number_seats,temp.price_ps,&temp.total)!=EOF)
	   {
		gotoxy(4,i);
		printf(" %s",temp.seat_name);
		gotoxy(9,i);
		printf(" %s",temp.movie_name);
		gotoxy(29,i);
		printf(" %s",temp.number_seats);
		gotoxy(41,i);
		printf(" %s",temp.price_ps);
                gotoxy(47,i);
		printf(" %f",temp.total);


		i=i+2;
	   }
	   fclose(ptr1);
	   getche();
}
//===========================main ===================
int main()
{
	char name[15];
	char pass[15];
	int count=0,i;

	system("cls");

	start:
	wbox();
	lbox();

	gotoxy(35,8);
	printf(" LOGIN ");


	gotoxy(32,18);
	printf("Enter user name :");
	gotoxy(32,22);
	printf("Enter password  :");
	gotoxy(51,18);
	strcpy(gets(name),name);

	gotoxy(51,22);

	i=0;
	do
	{
		pass[i] = getch();
		if(pass[i] == 13 )
		{
			break;
		}
		else if(pass[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}while(pass[i]!=13);
	pass[i] = '\0';

	if(strcmp(name,"name") || strcmp(pass,"pass"))
	{
	 system("cls");
	 gotoxy(20,20);
	 printf("Please Enter valid Username & Password!!!!!");
	 count++;
	 gotoxy(20,23);
	 printf("%d chance left!!!!",3-count);
	 getch();
	 system("cls");
	 if(count==3)
	 exit(0);
	 else
	 goto start;
	}
	else
	{
	 welcome();
	 main_menu();

	}
}
void search_seat()
{
  char name[50];
  FILE *fp;

	   fp=fopen("seat.dat","r");
	   if(fp==NULL)
	   {
	     printf("file can't open!!!!");

	   }
	   system("cls");
	   box();
	   fp=fopen("show.dat","rb");
	   gotoxy(13,8);
	   printf(" Enter Seat Name to be searched : ");
	   scanf("%s",&name);
	   gotoxy(20,35);

	   printf("Press Any key to Return Back Menu ....");
	   gotoxy(12,14);
	   printf("SEAT ID   MOVIE NAME   NUMBER    COST PER SEAT     TOTAL   ");
	   gotoxy(12,16);
	   i=18;
	   printf("==============================================================");

	   while(fscanf(fp," %s %s %s %s %f",temp.seat_name,temp.movie_name,temp.number_seats,temp.price_ps,&temp.total)!=EOF)
	   {
		if(strcmp(temp.seat_name,name)==0)
		{
			gotoxy(11,i);
			printf(" %s",temp.seat_name);
			gotoxy(15,i);
			printf(" %s",temp.movie_name);
			gotoxy(30,i);
			printf(" %s",temp.number_seats);
			gotoxy(40,i);
			printf(" %s",temp.price_ps);
            gotoxy(46,i);
			printf(" %f",temp.total);

			i++;
			break;
		}
	   }
	   if(strcmp(temp.seat_name,name)!=0)
	   {
		gotoxy(20,30);

		printf("Record not found!!!");
	   }
	   fclose(fp);
	   getche();
           book_show();
}
