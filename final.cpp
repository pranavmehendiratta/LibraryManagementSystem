/*---------------------------------------------------------------
		HEADER FILES USED IN PROJECT
  ---------------------------------------------------------------*/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<ctype.h>
#include<time.h>

void admin_menu();

/*---------------------------------------------------------------
		DISPLAY FUNCTION
  ---------------------------------------------------------------*/

	void display()
{
	gotoxy(25,1);
	cout<<"-----------------------------";
	gotoxy(25,3);
	cout<<"-----------------------------";
}

/*---------------------------------------------------------------
		WELCOME SCREEN FUNCTION
  ---------------------------------------------------------------*/

	void welcome()
{
	clrscr();
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	cout<<"@                                                              @"<<endl;
	cout<<"@                   #####  #       # #####                     @"<<endl;
	cout<<"@                   #    #  #     #  #    #                    @"<<endl;
	cout<<"@                   #    #   #   #   #    #                    @"<<endl;
	cout<<"@                   #    #    # #    #    #                    @"<<endl;
	cout<<"@                   #####      #     #####                     @"<<endl;
	cout<<"@                                                              @"<<endl;
	cout<<"@                                                              @"<<endl;
	cout<<"@     #      ####### #####  #####   ####  #####  #       #     @"<<endl;
	cout<<"@     #         #    #    # #    # #    # #    #   #   #       @"<<endl;
	cout<<"@     #         #    #####  #####  ###### #####      #         @"<<endl;
	cout<<"@     #         #    #    # #  #   #    # #  #       #         @"<<endl;
	cout<<"@     ###### ####### #####  #    # #    # #    #     #         @"<<endl;
	cout<<"@                                                              @"<<endl;
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;;

}

/*---------------------------------------------------------------
		CLASSES USED IN THE PROJECT
  ---------------------------------------------------------------*/
class dvd
{
	char cno[6];
	char cname[50];
	char fname[20];
	int num;
	public:

	void create_dvd()
{
		clrscr();
		display();
		gotoxy(30,2);
		cout<<" NEW CD/DVD ENTRY    ";
		gotoxy(1,4);
		cout<<"ENTER THE CD/DVD NUMBER         : ";
		gotoxy(1,5);
		cout<<"ENTER THE NAME OF CD/DVD        : ";
		gotoxy(1,6);
		cout<<"ENTER THE PRODUCTION HOUSE NAME : ";
		gotoxy(35,4);
		cin>>cno;
		gotoxy(35,5);
		gets(cname);
		gotoxy(35,6);
		gets(fname);
		gotoxy(20,8);
		cout<<"CD/DVD RECORD IS SUCCESSFULLY CREATED";
}

	void show_dvd()
{
		cout<<"\nCD/DVD NUMBER             : "<<cno;
		cout<<"\nCD/DVD NAME               : ";
		puts(cname);
		cout<<"PRODUCTION HOUSE NAME     : ";
		puts(fname);
}

	void mod_dvd()
{
		cout<<"\nNEW CD/DVD NUMBER         : ";
		cout<<"\nNEW CD'D/DVD'S NAME       : ";
		cout<<"\nNEW PRODUCTION HOUSE NAME : ";
		gotoxy(29,10);
		cin>>cno;
		gotoxy(29,11);
		gets(cname);
		gotoxy(29,12);
		gets(fname);
}

	char* retcno()
{
	return cno;
}

	void report()
{
	cout<<setw(5)<<cno<<setw(25)<<'\t'<<cname<<setw(20)<<'\t'<<fname<<endl;
}
};

	class student
{
	char admno[6];
	char name[20];
	char stcno[6];
	int token;
	int first_day, second_day;
	int first_month, second_month;
	int first_year, second_year;
	public:

	void create_student()
{
		clrscr();
		display();
		gotoxy(30,2);
		cout<<"NEW STUDENT ENTRY    \n";
		gotoxy(1,4);
		cout<<"ENTER THE ADMISSION NUMBER OF THE STUDENT : ";
		gotoxy(1,5);
		cout<<"ENTER THE NAME OF THE STUDENT             : ";
		gotoxy(45,4);
		cin>>admno;
		gotoxy(45,5);
		gets(name);
		token=0;
		stcno[0]='/0';
		gotoxy(22,7);
		cout<<"STUDENT RECORD IS SUCCESSFULLY CREATED";
}

	void show_student()
{
		cout<<"\n\nADMISSION NUMBER        : "<<admno;
		cout<<"\nSTUDENTS'S NAME         : ";
		puts(name);
		cout<<"NUMBER OF CD/DVD ISSUED : "<<token;
		if(token>=1)
		cout<<"\nCD/DVD NUMBER "<<stcno;
}

	void mod_student()
{
		cout<<"\nNEW ADMISSION NUMBER   : ";
		cout<<"\nNEW STUDENTS'S NAME    : ";
		gotoxy(26,10);
		cin>>admno;
		gotoxy(26,11);
		gets(name);
}

	char* retadmno()
{
	return admno;
}

	char* retstcno()
{
	return stcno;
}

	int rettoken()
{
	return token;
}

	void addtoken()
{
	token=1;
}

	void resettoken()
{
	token=0;
}

	void getstcno(char t[])
{
	strcpy(stcno,t);
}

	void report()
{
	cout<<"\t"<<admno<<setw(30)<<name<<setw(25)<<token<<endl;
}

};

class date
 {
  public:
  unsigned int DD,MM,YYYY;
 void datei()
  {time_t t = time(NULL);                    //Get time now
	struct tm * now = localtime( & t );
	DD=now->tm_mday-1;
	MM=(now->tm_mon+1);
	YYYY=(now->tm_year+1900);
  }
  void dated();
 };
 void date::dated()
{time_t t = time(NULL);                    //Get time now
	struct tm * now = localtime( & t );
	DD=now->tm_mday-1;
	MM=(now->tm_mon+1);
	YYYY=(now->tm_year+1900);
  }
int calc_days(date d1,date d2)
 {
  int days_in_months[]={31,28,31,30,31,30,31,31,30,31,30,31};
  int years_difference, days_difference;
  int months_total;
  int reg_year = 365;
  /////////////////////////////Years///////////////////////////////
  if(d1.YYYY == d2.YYYY)
  years_difference = 0;
  else
  {
	if(d1.YYYY % 4 == 0 && d1.YYYY % 100 != 0 || d1.YYYY % 400 == 0)
	{
	 if(d2.YYYY % 4 == 0 && d2.YYYY % 100 != 0 || d2.YYYY % 400 == 0)
	 {
	  if(d1.YYYY > d2.YYYY)
	  years_difference = (d1.YYYY - d2.YYYY) * (reg_year) + 2;
	  else
	  years_difference = (d2.YYYY - d1.YYYY) * (reg_year) + 2;

	  if(d2.MM > d1.MM)
	  {
		if(days_in_months[d1.MM - 1] > days_in_months[1])
		--years_difference;
	  }
	 }
	 else
	 {
	  if(d1.YYYY > d2.YYYY)
	  years_difference = (d1.YYYY - d2.YYYY) * (reg_year) + 1;
	  else
	  years_difference = (d2.YYYY - d1.YYYY) * (reg_year) + 1;

	  if(d1.MM > d2.MM)
	  {
		if(days_in_months[d2.MM - 1] > days_in_months[1])
		--years_difference;
	  }
	 }
	}
	else
	{
	 if(d1.YYYY > d2.YYYY)
	 years_difference = (d1.YYYY - d2.YYYY) * (reg_year);
	 else
	 years_difference = (d2.YYYY - d1.YYYY) * (reg_year);
	}
  }
  /////////////////////////////Months/////////////////////////////////
  if(d1.MM == d2.MM)
  months_total = 0;
  else
  {
	if(d1.MM > d2.MM)
	{
	 for(int i = (d1.MM - 1); i > (d2.MM - 1); i--)
	 {
	  static int months_total_temp = 0;
	  months_total_temp += days_in_months[i];
	  months_total = months_total_temp;
	 }
	}
	else
	{
	 for(int i = (d1.MM - 1); i < (d2.MM - 1); i++)
	 {
	  static int months_total_temp = 0;
	  months_total_temp += days_in_months[i];
	  months_total = months_total_temp;
	 }
	}
  }
  ////////////////////////////Days//////////////////////////////////
  int days_total;
  if (d1.DD == d2.DD)
  {
	days_difference = 0;
	days_total = (years_difference + months_total) - days_difference;
  }
  else
  {
	if(d1.DD > d2.DD)
	{
	 days_difference = d1.DD - d2.DD;
	 days_total = (years_difference + months_total) - days_difference;
	}
	else
	{
	 days_difference = d2.DD - d1.DD;
	 days_total = (years_difference + months_total) + days_difference;
	}
  }
  //////////////////////////In Between Leap Years//////////////////////
  if(d1.YYYY == d2.YYYY)
  {
  }
  else
  {
	if(d1.YYYY > d2.YYYY)
	{
	 for(int i = (d2.YYYY + 1); i < d1.YYYY; i++)
	 {
	  if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
	  ++days_total;
	 }
	}
	else
	{
	 for(int i = (d1.YYYY + 1); i < d2.YYYY; i++)
	 {
	  if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
	  ++days_total;
	 }
	}
  }
  return days_total;
 }


/*---------------------------------------------------------------
		GLOBAL DECLARATION FOR VARIABLES
  ---------------------------------------------------------------*/

	fstream fp,fp1,fp2;
	dvd c;
	student s;
	date i,d;

/*---------------------------------------------------------------
		FUNCTION TO WRITE CD/DVD RECORD
  ---------------------------------------------------------------*/

	void write_dvd()
{
	char ch;
	fp.open("cd.dat",ios::app|ios::binary);
	do
{
	clrscr();
	c.create_dvd();
	fp.write((char*)&c,sizeof(c));
	gotoxy(20,10);
	cout<<"DO YOU WANT TO ADD MORE RECORDS (Y/N)? ";
	cin>>ch;
}
	while(ch=='y'||ch=='Y');
	fp.close();
}

/*---------------------------------------------------------------
		FUNCTION TO WRITE STUDENT RECORD
  ---------------------------------------------------------------*/

	void write_student()
{
	char ch;
	fp.open("student.dat",ios::app|ios::binary);
	do
{
	s.create_student();
	fp.write((char*)&s,sizeof(student));
	gotoxy(1,9);
	cout<<"DO YOU WANT TO ADD MORE RECORDS (Y/N)? ";
	cin>>ch;
}
	while(ch=='y'||ch=='Y');
	fp.close();
}

/*---------------------------------------------------------------
	  FUNCTION TO READ SPECIFIC CD/DVD RECORD FROM FILE
  ---------------------------------------------------------------*/

	void display_spc(char n[])
{
	clrscr();
	display();
	gotoxy(30,2);
	cout<<"CD'S/DVD'S DETAILS    \n";
	int check=0;
	fp.open("cd.dat",ios::in);
	while(fp.read((char*)&c,sizeof(c)))
{
	if((strcmp(c.retcno(),n)==0))
{
	c.show_dvd();
	check=1;
}
}

	fp.close();
	if(check==0)
	cout<<"\nCD'S\DVD'S RECORD DOES NOT EXISTS";
	getch();
}

/*-------------------------------------------------------------
		FUNCTION DECLARATION FOR ADMINISTRATOR MENU
---------------------------------------------------------------*/

	void admin_menu();

/*---------------------------------------------------------------
	  FUNCTION TO READ SPECIFIC STUDENT RECORD FROM FILE
  ---------------------------------------------------------------*/

	void display_sps(char n[])
{
	clrscr();
	display();
	gotoxy(30,2);
	cout<<"STUDENT'S DETAILS    \n";
	int check=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&s,sizeof(s)))
{
	if((strcmp(s.retadmno(),n)==0))
{
	s.show_student();
	check=1;
}
}

	fp.close();
	if(check==0)
	cout<<"\nSTUDENTS'S RECORD DOES NOT EXISTS";
	getch();
}

/*---------------------------------------------------------------
		FUNCTION TO MODIFY CD/DVD RECORD
  ---------------------------------------------------------------*/

	void modify_dvd()
{
	char n[6],ch;
	do
{
	int found=0;
	clrscr();
	display();
	gotoxy(27,2);
	cout<<"MODIFY CD/DVD RECORD    \n";
	cout<<"\nENTER THE CD/DVD NUMBER OF THE CD/DVD YOU WANT MODIFY : ";
	cin>>n;
	fp.open("cd.dat",ios::in|ios::out);
	while(fp.read((char*)&c,sizeof(c)) && found==0)
{
	if(strcmp(c.retcno(),n)==0)
{
	clrscr();
	display();
	gotoxy(26,2);
	cout<<"OLD DETAILS OF THE CD/DVD    \n";
	c.show_dvd();
	gotoxy(25,7);
	cout<<"----------------------------";
	gotoxy(26,8);
	cout<<"NEW DETAILS OF THE CD/DVD    \n";
	gotoxy(25,9);
	cout<<"----------------------------";
	c.mod_dvd();
	int pos=-1*sizeof(c);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&c,sizeof(c));
	gotoxy(22,14);
	cout<<"RECORD IS SUCCESSFULLY UPDATED";
	found=1;
}
}
	fp.close();
	if(found==0)
{
	gotoxy(27,14);
	cout<<"RECORD NOT FOUND ";
}
	gotoxy(20,16);
	cout<<"DO YOU WANT TO MODIFY MORE RECORDS? : ";
	cin>>ch;
}while(ch=='y' || ch=='Y');
}

/*---------------------------------------------------------------
		FUNCTION TO MODIFY STUDENT RECORD
  ---------------------------------------------------------------*/

	void modify_student()
{
	char n[6],ch;
	do
{
	int found=0;
	clrscr();
	display();
	gotoxy(29,2);
	cout<<"MODIFY STUDENT RECORD    \n";
	cout<<"\nENTER THE ADMISSION NUMBER OF THE STUDENT YOU WANT MODIFY : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&s,sizeof(s)) && found==0)
{
	if(strcmp(s.retadmno(),n)==0)
{
	clrscr();
	display();
	gotoxy(26,2);
	cout<<"OLD DETAILS OF THE STUDENT    \n";
	s.show_student();
	gotoxy(25,7);
	cout<<"----------------------------";
	gotoxy(26,8);
	cout<<"NEW DETAILS OF THE STUDENT    \n";
	gotoxy(25,9);
	cout<<"----------------------------";
	s.mod_student();
	int pos=-1*sizeof(s);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&s,sizeof(s));
	gotoxy(22,14);
	cout<<"RECORD IS SUCCESSFULLY UPDATED";
	found=1;
	gotoxy(20,16);
	cout<<"DO YOU WANT TO MODIFY MORE RECORDS? : ";
	cin>>ch;
}
}
	fp.close();
	if(found==0)
{
	gotoxy(27,6);
	cout<<"RECORD NOT FOUND ";
	gotoxy(20,8);
	cout<<"DO YOU WANT TO MODIFY MORE RECORDS? : ";
	cin>>ch;
}
}while(ch=='y' || ch=='Y');
}

/*---------------------------------------------------------------
		FUNCTION TO DELETE STUDENT RECORD
  ---------------------------------------------------------------*/

	void delete_student()
{
	char n[6],ch;
	do
{
	int check=0;
	clrscr();
	display();
	gotoxy(28,2);
	cout<<"DELETE STUDENT RECORD    \n";
	cout<<"\n\nENTER THE ADMISSION NUMBER OF THE STUDENT YOU WANT TO DELETE : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&s,sizeof(s)))
{
	if(strcmp(s.retadmno(),n)!=0)
	fp2.write((char*)&s,sizeof(s));
	else
	check=1;
}

	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(check==1)
{
	gotoxy(24,7);
	cout<<"RECORD IS SUCCESSFULLY DELETED";
}
	else
{
	gotoxy(30,7);
	cout<<"RECORD NOT FOUND";
}
	gotoxy(22,9);
	cout<<"DO YOU WANT TO DELETE MORE RECORDS? : ";
	cin>>ch;
}while(ch=='y' || ch=='Y');
}

/*---------------------------------------------------------------
		FUNCTION TO DELETE CD/DVD RECORD
  ---------------------------------------------------------------*/

	void delete_dvd()
{
	char n[6],ch;
	do
{
	int check=0;
	clrscr();
	display();
	gotoxy(28,2);
	cout<<"DELETE CD/DVD RECORD    \n";
	cout<<"\n\nENTER THE CD/DVD NUMBER OF THE CD/DVD YOU WANT TO DELETE : ";
	cin>>n;
	fp.open("cd.dat",ios::in|ios::out);
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&c,sizeof(c)))
{
	if(strcmp(c.retcno(),n)!=0)
	fp2.write((char*)&c,sizeof(c));
	else
	check=1;
}

	fp2.close();
	fp.close();
	remove("cd.dat");
	rename("Temp.dat","cd.dat");
	if(check==1)
{
	gotoxy(24,7);
	cout<<"RECORD IS SUCCESSFULLY DELETED";
}
	else
{
	gotoxy(30,7);
	cout<<"RECORD NOT FOUND";
}
	gotoxy(22,9);
	cout<<"DO YOU WANT TO DELETE MORE RECORDS? : ";
	cin>>ch;
}while(ch=='y' || ch=='Y');
}


/*---------------------------------------------------------------
		MAIN MENU FUNCTION DECLARATION
  ---------------------------------------------------------------*/

	void main_menu();

/*---------------------------------------------------------------
		FUNCTION TO DISPLAY ALL STUDENTS LIST
  ---------------------------------------------------------------*/

	void display_alls()
{
	clrscr();
	fp.open("student.dat",ios::in);
	if(!fp)
{
	cout<<"ERROR. FILE COULD NOT BE OPENED. ";
	getch();
	return;
}
	clrscr();
	display();
	gotoxy(32,2);
	cout<<"STUDENT LIST\n\n\n";
	cout<<"-------------------------------------------------------------------------\n";
	gotoxy(7,6);
	cout<<"ADMISSION NUMBER"<<setw(19)<<"NAME"<<setw(30)<<"CD/DVD ISSUED\n";
	cout<<"-------------------------------------------------------------------------\n";
	while(fp.read((char*)&s,sizeof(s)))
{
	s.report();
}
	fp.close();
	getch();
}

/*---------------------------------------------------------------
		FUNCTION TO DISPLAY CD'S OR DVD'S LIST
  ---------------------------------------------------------------*/

void display_allc()
{
	clrscr();
	fp.open("cd.dat",ios::in);
	if(!fp)
{
	cout<<"ERROR. FILE COULD NOT BE OPENED. ";
	getch();
	return;
}
	display();
	gotoxy(32,2);
	cout<<"CD'S/DVD'S LIST\n\n\n";
	cout<<"--------------------------------------------------------------------------------\n";
	gotoxy(2,6);
	cout<<"CD/DVD NUMBER"<<setw(32)<<"CD/DVD NAME"<<setw(34)<<"PRODUCTION HOUSE\n";
	cout<<"--------------------------------------------------------------------------------\n";
	while(fp.read((char*)&c,sizeof(c)))
{
	c.report();
}
	fp.close();
	getch();
	main_menu();
}

/*---------------------------------------------------------------
		FUNCTION TO ISSUE CD/DVD
  ---------------------------------------------------------------*/
	void dvd_issue()
{
	char sn[6],cn[6];
	int found=0,flag=0;
	clrscr();
	display();
	gotoxy(30,2);
	cout<<"NEW CD/DVD ISSUE";
	cout<<"\n\nENTER THE STUDENTS ADMISSION NUMBER : ";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("cd.dat",ios::in|ios::out);
	while(fp.read((char*)&s,sizeof(student)) && found==0)
			{
	if(strcmp(s.retadmno(),sn)==0)
{
	found=1;
	if(s.rettoken()==0)
{
	cout<<"\n\n\tENTER THE DVD NUMBER: ";
	cin>>cn;
	while(fp1.read((char*)&c,sizeof(dvd))&& flag==0)
{
	if(strcmpi(c.retcno(),cn)==0)
{
	s.show_student();
	cout<<endl;
	c.show_dvd();
	flag=1;
	s.addtoken();
	s.getstcno(c.retcno());
	int pos=-1*sizeof(s);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&s,sizeof(student));
	cout<<"\nCD/DVD IS SUCCESSFULLY ISSUED.";
	cout<<"\nPLEASE PAY RS 100 AS RENT AT THE TIME OF RETUNING THE DVD";
	cout<<"\nPLEASE NOTE: RETURN THE";
	cout<<" CD/DVD WITHIN 2 WEEKS FROM ISSUING DATE ELSE YOU";
	cout<<"\nWOULD BE CHARGED Rs.5 EACH DAY AS A FINE AFTER 2 WEEKS PERIOD.\n\n";
	i.datei();
}
}
	if(flag==0)
	cout<<"CD/DVD DOES NOT EXISTS";
}
	else
	cout<<"YOU HAVE NOT RETURNED YOUR LAST CD/DVD";
}
}
	if(found==0)
	cout<<"STUDENT RECORD DOES NOT EXISTS";
	getch();
	fp.close();
	fp1.close();
}


/*---------------------------------------------------------------
		FUNCTION TO DEPOSIT CD/DVD
  ---------------------------------------------------------------*/

	void dvd_deposit()
{
	char sn[6];
	int found=0,check=0,fine,days;
	clrscr();
	display();
	gotoxy(30,2);
	cout<<"CD/DVD DEPOSIT    \n";
	cout<<"\n\nPLEASE ENTER THE STUDENTS ADMISSION NUMBER : ";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("cd.dat",ios::in|ios::out);
	while(fp.read((char*)&s,sizeof(s)) && found==0)
{
	if(strcmp(s.retadmno(),sn)==0)
{
	found=1;
	if(s.rettoken()==1)
{
	while(fp1.read((char*)&c,sizeof(c))&& check==0)
{
	if(strcmp(c.retcno(),s.retstcno())==0)
{
	s.show_student();
	cout<<endl;
	c.show_dvd();
	check=1;
	d.dated();
	cout<<endl;
	days=calc_days(i,d);
	cout<<"Total number of days you kept the dvd are: "<<days;
	if(days>7)
{
	fine=(days-7)*5;
	gotoxy(20,18);
	cout<<"\nRs. "<<fine<<" HAS TO BE DEPOSITED BY THE DEPOSITOR AS A FINE FOR LATE SUBMISSION";
	cout<<"\nOF CD/DVD.";
}
	cout<<"\n Total payment of "<<100+fine<<" has to be done for the dvd you issued.";
	cout<<"Thank you for choosing this library";
	s.resettoken();
	int pos=-1*sizeof(s);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&s,sizeof(s));
	gotoxy(20,24);
	cout<<"CD/DVD HAS BEEN SUCCESSFULLY DEPOSITED";
}
}
	if(check==0)
	cout<<"CD/DVD DOES NOT EXISTS";
}
	else
{
	cout<<"\n\t\t   NO CD/DVD IS ISSUED PLEASE CHECK AGAIN.";
}
}
}
	if(found==0)
{
	cout<<"STUDENT RECORD DOES NOT EXISTS";
}
	getch();
	fp.close();
	fp1.close();
}

/*---------------------------------------------------------------
		INTRODUCTION FUNCTION
  ---------------------------------------------------------------*/

void intro()
{
	welcome();
	cout<<"\n MADE BY  : PRANAV MEHENDIRATTA";
	cout<<"\n CLASS    : XII-A";
	cout<<"\n ROLL NO. : 19";
	cout<<"\n SCHOOL   : JASPAL KAUR PUBLIC SCHOOL";
	gotoxy(71,-20);
	getch();
}


/*---------------------------------------------------------------
		ADMIN MENU DECLARATION
  ---------------------------------------------------------------*/

void admin_menu();

/*---------------------------------------------------------------
		FUNCTION FOR LOGIN
  ---------------------------------------------------------------*/
const int n=25;
void passfunc()
{
	 clrscr();
	 char ch3;
	 int check=1;
	 do
{
	 fstream fil,f;
	 char pass[n],ch,log[n],ch2;
	 int k=1,i,q=1,w;
	 clrscr();
	 gotoxy(25,9);
	 cout<<"------------------------";
	 gotoxy(28,10);
	 cout<<"PASSWORD : ";
	 gotoxy(25,11);
	 cout<<"------------------------";
	 gotoxy(25,7);
	 cout<<"------------------------";
	 gotoxy(28,8);
	 cout<<"LOGIN ID : ";
	 gotoxy(39,8);
	 for(w=0;w<n-1;w++,q++)
{
	 log[w]=getch();
	 if(log[w]=='\r')
{
	 break;
}
	 else if(log[w]=='\b')
{
	 for(int t=39,u=8;t<100;t++)
{
	 gotoxy(t,u);
	 cout<<" ";
}
	 gotoxy(28,8);
	 q--;
	 cout<<"LOGIN ID : ";
	 gotoxy(39,8);
	 for(int a=0;a<q-1;a++)
	 cout<<log[a];
	 q--;
	 w-=2;
}
	 else
{
	 cout<<log[w];
}
}
	 int g=0;
	 f.open("login.txt",ios::in);
	 while(!f.eof())
{
	 f.get(ch2);
	 if (ch2==log[g])
	 g++;
}
	 gotoxy(39,10);
	 for(i=0;i<n-1;i++,k++)
{
	 pass[i]=getch();
	 if(pass[i]=='\r')
{
	 break;
}
	 else if(pass[i]=='\b')
{
	 for(int x=39,y=10;x<100;x++)
{
	 gotoxy(x,y);
	 cout<<" ";
}
	 gotoxy(28,10);
	 k--;
	 cout<<"PASSWORD : ";
	 gotoxy(39,10);
	 for(int j=1;j<k;j++)
	 cout<<"*";
	 k--;
	 i-=2;
}
	 else
{
	 putch('*');
}
}
	 int p=0;
	 fil.open("Password.txt",ios::in);
	 while(!fil.eof())
{
	 fil.get(ch);
	 if (ch==pass[p])
	 p++;
}
	 if(g==w)
{
	 if(p==i)
	 admin_menu();
	 else
{
	 gotoxy(29,13);
	 cout<<"WRONG PASSWORD";
}
}
	 else
{
	 gotoxy(29,13);
	 cout<<"WRONG LOGIN ID";
}
	 gotoxy(24,15);
	 cout<<"DO YOU WANT TO TRY AGAIN : ";
	 cin>>ch3;
	 if(ch3=='y' || ch3=='Y')
	 check++;
}while(ch3=='y' && check<4 || ch3=='Y' && check<4);

	if(tolower(ch3!='y'))
{
	 main_menu();
}
	if(check==4)
{
	 gotoxy(1,15);
	 cout<<"YOU HAVE INPUT THE PASSWORD WRONG FOR 3 TIMES. PLEASE TRY AGAIN LATER.";
	 getch();
	 main_menu();
}
}

/*---------------------------------------------------------------
		FUNCTION FOR HELP MENU FOR THE VIEWER
  ---------------------------------------------------------------*/

	void help_viewer()
{
	display();
	gotoxy(29,2);
	cout<<"HELP MENU FOR VIEWER    \n";
	cout<<"\n1. To gain administrator rights please press 1 and for more information\n";
	cout<<"   on how to use administrator menu please select help menu option from \n";
	cout<<"   administrator menu.\n";
	cout<<"\n2. To view the whole list of cd/dvd currently present in the library\n ";
	cout<<"   please press 2.\n";
	cout<<"\n3. To exit the software please press 4.";
	gotoxy(22,14);
	cout<<"THANK YOU FOR CHOOSING THIS SOFTWARE.";
	getch();
	main_menu();
}

/*---------------------------------------------------------------
		FUNCTION FOR HELP MENU FOR THE ADMINISTRATOR
  ---------------------------------------------------------------*/

	void help()
{
	clrscr();
	display();
	gotoxy(26,2);
	cout<<"HELP MENU FOR ADMINISTRATOR\n";
	cout<<"\n01. To create a new student record please press 1 and enter the\n";
	cout<<"    appropriate details in the field provided.";
	cout<<"\n02. To view the whole list of students currently a member of library\n ";
	cout<<"   and the number of cd/dvd issued by the specific student please press 2.";
	cout<<"\n03. To view the details of a specific student please press 3. ";
	cout<<"\n04. To modify the details of a specific student please press 4.";
	cout<<"\n05. To delete the record of a specific student please press 5.";
	cout<<"\n06. To create a new cd/dvd record please press 6 and enter the\n";
	cout<<"    appropriate details in the field provided.";
	cout<<"\n07. To issue cd/dvd to a student please press 7.";
	cout<<"\n08. To deposit cd/dvd from a student please press 8.";
	cout<<"\n09. To view the details of a specific cd/dvd please press 9. ";
	cout<<"\n10. To modify the details of a specific cd/dvd please press 10.";
	cout<<"\n11. To delete the record of a specific cd/dvd please press 11.";
	gotoxy(22,20);
	cout<<"THANK YOU FOR CHOOSING THIS SOFTWARE.";
	getch();
	admin_menu();
}

/*---------------------------------------------------------------
		THANK YOU SCREEN
  ---------------------------------------------------------------*/

	void thankyou()
{
	clrscr();
	cout<<" ####### #    #  ####  ##    # #    #    #       #  ####  #    # \n";
	cout<<"    #    #    # #    # # #   # #  #        #   #   #    # #    # \n";
	cout<<"    #    ###### ###### #  #  # ##            #     #    # #    # \n";
	cout<<"    #    #    # #    # #   # # #  #          #     #    # #    # \n";
	cout<<"    #    #    # #    # #    ## #    #        #      ####   ####  \n";
	cout<<"\n";
	cout<<" #####  ####   ####     ##### #    #  ####   ####  ##### # ##    # #####\n";
	cout<<" #	  #	 # #	  #    #		 #	   # #	 # #	  # #		 # # #	# #\n";
	cout<<" ##### #    # ######    #     ###### #    # #    # ##### # #  #  # # ###\n";
	cout<<" #     #    # #   #     #     #    # #    # #    #     # # #   # # #   #\n";
	cout<<" #      ####  #    #    ##### #    #  ####   ####  ##### # #    ## #####\n";
	cout<<"\n";
	cout<<" ####### #    # # ######     \n";
	cout<<"    #    #    # # #          \n";
	cout<<"    #    ###### # ######     \n";
	cout<<"    #    #    # #      #     \n";
	cout<<"    #    #    # # ######     \n";
	cout<<"\n";
	cout<<" ###### ###### ###### ####### #           #  ####   ####  ######\n";
	cout<<" #      #    # #         #     #         #  #    # #    # #     \n";
	cout<<" ###### #    # ######    #      #   #   #   ###### ###### ######\n";
	cout<<"      # #    # #         #       # # # #    #    # #   #  #     \n";
	cout<<" ###### ###### #         #        #   #     #    # #    # ######\n";
	getch();
	clrscr();
	exit(0);
}

/*---------------------------------------------------------------
		FUNCTION FOR MAIN MENU OF THE PROGRAM
  ---------------------------------------------------------------*/

void main_menu()
{
		clrscr();
		cout<<"------------------------------------------------------------------------";
		cout<<"\n\t\t\t        MAIN MENU\n";
		cout<<"------------------------------------------------------------------------";
		cout<<"\n\n1. ADMINISTRATOR MENU ";
		cout<<"\n2. DISPLAY ALL CD/DVD RECORD";
		cout<<"\n3. HELP";
		cout<<"\n4. QUIT";
		cout<<"\n\n\t\tPLEASE CHOOSE FROM 1-3 TO PERFORM OPERATIONS ";
		cout<<"\n\t\tCHOICE : ";
		char ch;
		cin>>ch;
		switch(ch)
{
		case '1':passfunc();
					break;
		case '2':clrscr();
					display_allc();
					break;
		case '3':clrscr();
					help_viewer();
		case '4':thankyou();
		default :cout<<"\a";
}
}

/*---------------------------------------------------------------
		ADMIN MENU FUNCTION
  ---------------------------------------------------------------*/

void admin_menu()
{
	clrscr();
	int ch2;
	cout<<"------------------------------------------------------------------------";
	cout<<"\n|\t\t\t    ADMINISTRATOR MENU                         |\n";
	cout<<"------------------------------------------------------------------------\n";
	cout<<"|\t  STUDENT OPERATIONS       |         CD/DVD OPERATIONS         |\n";
	cout<<"------------------------------------------------------------------------\n";
	cout<<"|                                  |                                   |";
	cout<<"\n|1.CREATE STUDENT RECORD           | 6. CREATE CD/DVD RECORD           |";
	cout<<"\n|2.DISPLAY ALL STUDENTS RECORD     | 7. CD/DVD ISSUE                   |";
	cout<<"\n|3.DISPLAY SPECIFIC STUDENT RECORD | 8. CD/DVD DEPOSIT                 |";
	cout<<"\n|4.MODIFY STUDENT RECORD           | 9. DISPLAY SPECIFIC CD/DVD RECORD |";
	cout<<"\n|5.DELETE STUDENT RECORD           | 10.MODIFY CD/DVD RECORD           |";
	cout<<"\n|                                  | 11.DELETE CD/DVD RECORD           |";
	cout<<"\n------------------------------------------------------------------------";
	cout<<"\n|\t\t                                                       |";
	cout<<"\n|\t\tPLEASE CHOOSE 1-11 TO PERFORM OPERATIONS               |";
	cout<<"\n|\t\t                                                       |";
	cout<<"\n|PRESS 0 FOR MAIN MENU                                                 |";
	cout<<"\n|PRESS 12 FOR HELP MENU                                                |";
	cout<<"\n|\t\t                                                       |";
	cout<<"\n|\t\tCHOICE :                                               |";
	cout<<"\n------------------------------------------------------------------------";
	gotoxy(26,20);
	cin>>ch2;
	switch(ch2)
{
	case 1:clrscr();
			 write_student();
			 break;
	case 2:display_alls();
			 break;
	case 3:char num[6];
			 clrscr();
			 cout<<"\nPLEASE ENTER THE ADMISSION NUMBER : ";
			 cin>>num;
			 display_sps(num);
			 break;
	case 4:modify_student();
			 break;
	case 5:delete_student();
			 break;
	case 6:clrscr();
			 write_dvd();
			 break;
	case 7:dvd_issue();
			 break;
	case 8:dvd_deposit();
			 break;
	case 9:num[6];
			 clrscr();
			 gotoxy(1,5);
			 cout<<"PLEASE ENTER CD/DVD NUMBER : ";
			 cin>>num;
			 display_spc(num);
			 break;
	case 10:modify_dvd();
			 break;
	case 11:delete_dvd();
			  break;
	case 12: help();
				break;
	case 0:main_menu();
	default:cout<<"\a";
}
	admin_menu();
}

/*---------------------------------------------------------------
		MAIN FUNCTION OF THE PROGRAM
  ---------------------------------------------------------------*/

void main()
{
	intro();
	clrscr();
	main_menu();
}

