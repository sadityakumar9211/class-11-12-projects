

//Project on Bank Management System...

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

//Global variables & functions...

char pass1[20],ch,q;
int num,pos,entrance,option = 0,allow = 0;
void intro();
void password();
void home();
void m_pass();

class account
{
	private:
		unsigned long int acno;
		char name[20],pass[20],type,dob[10],add[20],mart,email[30];
		double deposite;
		char pno[10];
	public:
		void create_account();
		void show_account();
		void modify();
		void show_all();
		void dep(double);
		void draw(double);
		int retacno();
		char rettype();
		double retdep();
		char *retpass();
		char *retname();

};
account ac;
void account::create_account()
{
	textcolor(YELLOW);
	clrscr();
	cout<<"\nEnter Account Number : ";
	cin>>acno;
	cout<<"\nEnter Account Holder's Name : ";
	gets(name);
	cout<<"\nEnter DOB (dd/mm/yyyy) : ";
	gets(dob);
	cout<<"\nEnter Phone Number : ";
	gets(pno);
	cout<<"\nEnter Martial status(M/U) : ";
	cin>>mart;
	cout<<"\nEnter E - mail Id : ";
	gets(email);
	cout<<"\nSet Password for Safe login : ";
	gets(pass);
	cout<<"\nEnter Address(name of district) : ";
	gets(add);
	mart = toupper(mart);
	cout<<"\nEnter Account Type(C/S) : ";
	cin>>type;
	type = toupper(type);
	cout<<"\nEnter Initial Amount(>=500 for Savings OR >=1000 for Current) : ";
	cin>>deposite;
	clrscr();
	if(deposite<500&&type=='S'||deposite<1000&&type=='C')
	{
		textcolor(BLINK+RED);
		cout<<"\n\n\n\n\n";
		cprintf("\nAccount Can not Be created ...");
		cout<<"\n\n";
		cprintf("\nREASON : Insufficient Initial Amount...");
	}
	else
	{
		allow = 1;
		textcolor(GREEN);
		cout<<"\n\n\n\n\n";
		printf("\n\t\t\tAccount Opened...");
	}
	delay(2000);
}
void account::show_account()
{
	cout<<"\nDetails are as under :-\n";
	cout<<"\n\n\tAccount Number : "<<acno;
	cout<<"\n\n\tAccount Type : "<<type;
	cout<<"\n\n\tAccount Holders Name : "<<name;
	cout<<"\n\n\tPhone Number : "<<pno;
	cout<<"\n\n\tE - mail ID : "<<email;
	cout<<"\n\n\tPassword : "<<pass;
	cout<<"\n\n\tAddress : "<<add;
	cout<<"\n\n\tDOB : ";
	for(int i=0;i<10;i++)
		cout<<dob[i];
	cout<<"\n\n\tMartial status : "<<mart;
	cout<<"\n\n\tTotal balance: "<<deposite;
	if(deposite<=500 && type=='S')
		cout<<"\n\nYou Have InSufficient Balance...";
	else if(deposite<=1000 && type=='C')
		cout<<"\n\nYou HaveInsufficient Balance...";
	else
		cout<<"\n\nYou Have Sufficient Balance...";
}
void account::modify()
{
	cout<<"Account Number : "<<acno;
	cout<<"\n\nEnter the modified Details :-\n";
	cout<<"\nName : ";
	gets(name);
	cout<<"\nPhone Number : ";
	cin>>pno;
	cout<<"\nDOB : ";
	gets(dob);
	cout<<"\nE - mail Id : ";
	gets(email);
	cout<<"\nPassword : ";
	gets(pass);
	cout<<"\nAddress : ";
	gets(add);
	cout<<"\nMartial status : ";
	cin>>mart;
	draw(100);
}
void account::dep(double x)
{
	deposite+=x;
}
void account::draw(double x)
{
	deposite-=x;
}
void account::show_all()
{
	cout<<setw(8)<<acno<<setw(15)<<" "<<name<<setw(10)<<" "<<type<<"\t"<<deposite<<endl;
}
int account::retacno()
{
	return acno;
}
char account::rettype()
{
	return type;
}

double account::retdep()
{
	return deposite;
}
char *account::retpass()
{
	return(pass);
}
char *account::retname()
{
	return(name);
}

// Functions to store data in Permanent Memory...

void write_account();
void display_account(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();

void write_account()
{
	ofstream outFile;
	outFile.open("RECORD.dat",ios::binary|ios::app);
	ac.create_account();
	if(allow==1)
	{
		outFile.write((char*)&ac,sizeof(ac));
		outFile.close();
		delay(2000);
	}
}
void display_account(int acno)
{
	clrscr();
	ifstream inFile;
	inFile.open("RECORD.dat",ios::binary|ios::in);
	int found=0;
	if(!inFile)
	{
		cout<<"\nERROR : File Not Found...";
	}
	else
	{
		while(inFile.read((char*)&ac,sizeof(ac))&&found==0)
		{
			if(ac.retacno()==acno)
			{
				ac.show_account();
				found=1;
				break;
			}
		}
		if(found==0)
		{
			cout<<"\nRecord Not Found !!!";
		}
		inFile.close();
	}
	delay(3000);
	getch();
}
void modify_account(int acno)
{
	clrscr();
	int found=0,pos;
	fstream File;
	File.open("RECORD.dat",ios::in|ios::binary|ios::out);
	if(!File)
	{
		cout<<"\nERROR : File does not Exist...";
	}
	else
	{
		while(File.read((char*)&ac,sizeof(ac))&&found==0)
		{
			if(ac.retacno()==acno)
			{
				ac.show_account();
				cout<<"\n\t\t\t*** Press any Key to continue ***";
				getch();
				textcolor(GREEN);
				clrscr();
				ac.modify();
				cout<<"\nYou Will Be Charged INR 100 for Modfication ! ";
				int pos = -1*sizeof(account);
				File.seekp(pos,ios::cur);
				File.write((char*)&ac,sizeof(account));
				found=1;
				cout<<"\n\n\n\n\n\n\n\t\t\t\tRecord Updated..."<<endl;
				delay(3000);
			}
			else
			{
				File.write((char*)&ac,sizeof(account));
			}
		}
		if(found==0)
		{
			textcolor(RED);
			clrscr();
			cout<<"\n\n\n\n\n\n\t\t\tRecord Not Found...";
		}
		File.close();
	}
	delay(2000);
}
void delete_account(int acno)
{
	clrscr();
	char confirm = 'y';
	int found=0;
	ofstream outFile;
	ifstream inFile;
	outFile.open("temp.dat",ios::binary|ios::out);
	inFile.open("RECORD.dat",ios::binary|ios::in);
	if(!inFile)
	{
		cout<<"\nERROR : File does not Exist !!! " ;
	}
	else
	{
		while(inFile.read((char*)&ac,sizeof(ac)))
		{
			if(inFile.eof())
			{
				break;
			}
			else if(ac.retacno()==acno)
			{
				clrscr();
				ac.show_account();
				delay(5000);
				clrscr();
				cout<<"\n\nDo You want to delete this Account Permanently (y/n) ?\n\t\t";
				confirm = getche();
				if(confirm == 'n')
				{
					outFile.write((char *)&ac,sizeof(ac));
					cout<<"\n\nWARNING : Deletion aborted!!!!";
				}
				else
				{
					cout<<"\n\nRecord deleted from student file.";
				}
				found=1;
			}
			else
			{
				outFile.write((char *)&ac,sizeof(ac));
			}
		}
		if(found==0)
		{
			textcolor(RED+BLINK);
			clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t\tRecord Not Found...";
			delay(3000);
		}
		inFile.close();
		outFile.close();
		remove("RECORD.dat");
		rename("temp.dat","RECORD.dat");
	}
	delay(2000);
}
void display_all()
{
	clrscr();
	ifstream inFile;
	inFile.open("RECORD.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\nERROR : The File You are looking for is not been created yet...";
		cout<<"\n\nSORRY For Inconvenience ! ";
		delay(3000);
	}
	else
	{

		cout<<"\n\n\t\tACCOUNT HOLDER'S LIST\n";
		cout<<"==========================================================================\n";
	cout<<"A/c no.                 NAME         Type        Balance\n";
		cout<<"==========================================================================\n";
		int i=0;
		while(inFile.read((char *) &ac, sizeof(ac)))
		{
			ac.show_all();
			i++;
		}
		inFile.close();
		if(i==0)
			cout<<"\n\t\t\tNo Information Avaliable...";
		else
			cout<<"\n\nFor MORE Informaion Go to Corresponding account details."<<endl;
	}
}

void deposit_withdraw(int acno,int option)
{
	clrscr();
	int amt;
	int found=0;
	account ac;
	fstream File;
	File.open("RECORD.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
	}
	else
	{
		while(File.read((char *) &ac, sizeof(account))&&found==0)
		{
			if(ac.retacno()==acno)
			{
				ac.show_account();
				if(option==1)
				{
					clrscr();
					textcolor(YELLOW);
					clrscr();
					cout<<"\n\t     +++++++++++++++++++++++++++++++++++++++++++++++ ";
					cout<<"\n\t\t\t\tTO DEPOSITE AMOUNT ";
					cout<<"\n\t     +++++++++++++++++++++++++++++++++++++++++++++++";
					cout<<"\n    WELCOME "<<ac.retname();
					cout<<"\n\n\tEnter The amount to be deposited : ";
					cin>>amt;
					ac.dep(amt);
				}
				if(option==2)
				{
					textcolor(YELLOW);
					clrscr();
					cout<<"\n\t     +++++++++++++++++++++++++++++++++++++++++++++++ ";
					cout<<"\n\t\t\t\tTO WITHDRAW AMOUNT ";
					cout<<"\n\t     +++++++++++++++++++++++++++++++++++++++++++++++ ";
					cout<<"\n    WELCOME "<<ac.retname();
					cout<<"\n\nEnter The amount to be withdrawn : ";
					cin>>amt;
					int bal=ac.retdep()-amt;
					if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
						cout<<"Insufficient balance";
					else
						ac.draw(amt);
				}
				int pos=(-1)*sizeof(ac);
				File.seekp(pos,ios::cur);
				File.write((char *) &ac, sizeof(account));
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tYour Record Is Been UPDATED ...";
				found=1;
			}
		}
		File.close();
		if(found==0)
			cout<<"\n\n Record Not Found ";
	}
	delay(3000);
}
void intro()
{
	cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : Aditya Kumar Singh";
	cout<<"\n\nClass : XII A";
	cout<<"\n\nRoll Number : 03";
	cout<<"\n\nSCHOOL : DAV PUBLIC SCHOOL BARIATU";
	delay(2000);
	getch();
}
void password()
{
	clrscr();
	cout<<"\nEnter Account Number : ";
	cin>>num;
	cout<<"\nEnter Password : ";
	gets(pass1);
	ifstream inFile("RECORD.dat",ios::in);
	if(!inFile)
	{
		cout<<"\nFile does not Exist !!! ";
	}
	else
	{
		while(inFile.read((char*)&ac,sizeof(ac)))
		{
			if(strcmp(ac.retpass(),pass1)==0)
			{
				if(option==2)
					deposit_withdraw(num,1);
				else if(option==3)
					deposit_withdraw(num,2);
				else if(option==4)
					display_account(num);
				else if(option==5)
					delete_account(num);
				else if(option==6)
					modify_account(num);
				else
				{
					cout<<"\nWarning : Invalid Choice ....";
				}
			}
			else
			{
				textcolor(RED+BLINK);
				clrscr();
				cout<<"\n\n\n\t\t***** WARNING : WRONG PASSWORD **** " ;
				delay(3000);
			}
			break;
		}
	}
	option = 0;
}
void home()
{
	clrscr();
	textcolor(2);
	clrscr();
	cout<<"\t\t\t*******************************";
	cout<<"\n\t\t\t-----------------------------";
	cout<<"\n\t\t\t|| BANK MANAGEMENT SYSTEM ||\t\t[Customer Login]";
	cout<<"\n\t\t\t-----------------------------";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\n1.NEW ACCOUNT";
	cout<<"\n\n2.DEPOSIT AMOUNT";
	cout<<"\n\n3.WITHDRAW AMOUNT";
	cout<<"\n\n4.BALANCE ENQUIRY";
	cout<<"\n\n5.CLOSE AN ACCOUNT";
	cout<<"\n\n6.MODIFY AN ACCOUNT";
	cout<<"\n\n7.EXIT";
}
void main()
{
	textcolor(CYAN);
	clrscr();
	intro();
	textcolor(MAGENTA);
	clrscr();
	cout<<"\t\t\t*******************************";
	cout<<"\n\t\t\t  -----------------------------";
	cout<<"\n\t\t\t|| BANK MANAGEMENT SYSTEM ||\t\t  [Main_Menu]";
	cout<<"\n\t\t\t  -----------------------------";
	cout<<"\n\t\t\t******************************";
	cout<<"\n\n1.AUTHORISED USER login.";
	cout<<"\n\n2.Customer login.";
	cout<<"\n\nAny Other Key To EXIT.";
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tChoose Your Option : ";
	cin>>entrance;
	if(entrance==1)
	{
		textcolor(YELLOW);
		clrscr();
		cout<<"\n\t\t\t\tAUTHORISED USER";
		cout<<"\n\t\t\t**********************************";
		cout<<"\nEnter your password: ";
		char mas_pass1[9],mas_pass[] = "!@#123asd";
		gets(mas_pass1);
		if(strcmp(mas_pass1,mas_pass)==0)
		{
			display_all();
			getch();
		}
		else
		{
			sound(2000);
			textcolor(BLINK+RED);
			clrscr();
			cout<<"\n\n\n\t\tIncorrect Password...";
			delay(3000);
			nosound();
		}
	}
	else if(entrance==2)
	{
		do
		{
			home();
			cout<<"\nChoose one of the above Options(1 - 7) : ";
			cin>>option;
			switch(option)
			{
				case 1:
					write_account();
					break;
				case 7:
					textcolor(3);
					textbackground(0);
					clrscr();
					cout<<"\n\n\n\n\n\t\t## DO YOU REALLY WANT TO EXIT ?";
					cout<<"\n\n\t\t1.YES.";
					cout<<"\n\n\t\tAny Other Key For NO.\n\n";
					cout<<"\n\n\n\t\tChoice : ";
					cin>>q;
					if(q==49)
					{
						textcolor(GREEN);
						clrscr();
						cout<<"\n\n\n\n\n\n\t\tThank You For using BANK MANAGEMENT SYSTEM ";
						delay(4000);
						exit(0);
					}
					else
					{
						textcolor(GREEN+BLINK);
						clrscr();
						cout<<"\n\n\n\t\t\tFetching You Back... ";
						delay(3000);
						option = 0;
					}
				break;
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					password();
					break;
				default:
					clrscr();
					textcolor(RED+BLINK);
					clrscr();
					cout<<"\n\n\n\n\t\t\tERROR : INVALID CHOICE...";
					delay(3000);
					break;
			}

		}while(option!=7);
	}
	else
		exit(0);
}
