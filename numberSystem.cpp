//PROGRAMME ON NUMBER SYSTEM CONVERSIONS…
#include<iostream.h>
#include<conio.h>             
#include<math.h>              //for pow() .
#include<string.h>             //for strlen() .
#include<stdlib.h>             //for exit(0) .
#include<stdio.h>             //for gets .
#include<dos.h>               //for delay() function.
void dec_bin()
{
	int rem[10],num,i,count=0;
	cout<<"\n\n\nEnter the Decimal number to have its Binary Equivalent: ";
	cin>>num;
	while(num)
	{
		count++;
		rem[count] = num%2;
		num/=2;
	}
	cout<<"\n\n\nBinary Equivalant: ";
	for(i=count;i>0;i--)
	{
		cout<<rem[i];
	}
}
void dec_oct()
{
	int rem[10],i,num,count=0;
	cout<<"\n\n\nEnter the Decimal number to have its Octal Equivalent: ";
	cin>>num;
	while(num)
	{
		count++;
		rem[count] = num%8;
		num/=8;
	}
	cout<<"\n\n\nOctal equivilant: ";
	for(i=count;i>0;i--)
	{
		cout<<rem[i];
	}
}
void dec_hex()
{
	int num,rem[10],i,count=0;
	cout<<"\n\n\nEnter the Decimal number to have its Hexadecimal equivalent: ";
	cin>>num;
	while(num)
	{
		count++;
		rem[count] = num%16;
		num/=16;
	}
	cout<<"\n\n\nHexadecimal Equivalent: ";
	for(i=count;i>0;i--)
	{
		if(rem[i]==10)
		{
			cout<<"A";
		}
		else if(rem[i]==11)
		{
			cout<<"B";
		}
		else if(rem[i]==12)
		{
			cout<<"C";
		}
		else if(rem[i]==13)
		{
			cout<<"D";
		}
		else if(rem[i]==14)
		{
			cout<<"E";
		}
		else if(rem[i]==15)
		{
			cout<<"F";
		}
		else
		{
			cout<<rem[i];
		}
	}
}
void bin_dec()
{
	long int dec=0,i,num,rem;
	cout<<"\n\n\nEnter the binary number to get decimal equivalent: ";
	cin>>num;
	for(i=0;num!=0;i++)
	{
		rem = num%10;
		num/=10;
		dec+=rem*pow(2,i);
	}
	cout<<"\n\n\nDecimal Equivalent: "<<dec;
}
void bin_oct()
{
	long int num,rem1[10],rem,i,dec=0,count=0;
	cout<<"\n\n\nEnter the Binary number to have its Octal Equivalent: ";
	cin>>num;
	for(i=0;num!=0;i++)
	{
		rem = num%10;
		num/=10;
		dec+=rem*pow(2,i);
	}
	while(dec)
	{
		count++;
		rem1[count] = dec%8;
		dec/=8;
	}
	cout<<"\n\n\nOctal Equivalent: ";
	for(i=count;i>0;i--)
	{
		cout<<rem1[i];
	}
}
void bin_hex()
{
	long int dec=0,rem,num,rem1[10],i,count=0;
	cout<<"\n\n\nEnter the Binary Number to have its Hexadexcimal equivalent: ";
	cin>>num;
	for(i=0;num!=0;i++)
	{
		rem = num%10;
		num/=10;
		dec+=rem*pow(2,i);
	}
	while(dec)
	{
		count++;
		rem1[count] = dec%16;
		dec/=16;
	}
	cout<<"\n\n\nHexadecimal equivalent: ";
	for(i=count;i>0;i--)
	{
		if(rem1[i]==10)
		{
			cout<<"A";
		}
		else if(rem1[i]==11)
		{
			cout<<"B";
		}
		else if(rem1[i]==12)
		{
			cout<<"C";
		}
		else if(rem1[i]==13)
		{
			cout<<"D";
		}
		else if(rem1[i]==14)
		{
			cout<<"E";
		}
		else if(rem1[i]==15)
		{
			cout<<"F";
		}
		else
		{
			cout<<rem1[i];
		}
	}
}
void oct_dec()
{
	long int rem,num,i,dec=0;
	cout<<"\n\n\nEnter the Octal number to have its Decimal equivalent: ";
	cin>>num;
	for(i=0;num!=0;i++)
	{
		rem = num%10;
		num/=10;
		dec+=rem*pow(8,i);
	}
	cout<<"\n\n\nDecimal equivalent: "<<dec;
}
void oct_bin()
{
	long int rem,rem1[10],count=0,dec=0,num,i;
	cout<<"\n\n\nEnter the Octal number to have its Binary equivalent: ";
	cin>>num;
	for(i=0;num!=0;i++)
	{
		rem = num%10;
		num/=8;
		dec+=rem*pow(8,i);
	}
	while(dec)
	{
		count++;
		rem1[count] = dec%2;
		dec/=2;
	}
	cout<<"\n\n\nBinary equivalent: ";
	for(i=count;i>0;i--)
	{
		cout<<rem1[i];
	}
}
void oct_hex()
{
	long int rem,rem1[10],num,i,dec=0,count=0;
	cout<<"\n\n\nEnter the Octal number to have its Hexadecimal equivalent: ";
	cin>>num;
	for(i=0;num!=0;i++)
	{
		rem = num%10;
		num/=10;
		dec+=rem*pow(8,i);
	}
	while(dec)
	{
		count++;
		rem1[count] = dec%16;
		dec/=16;
	}
	cout<<"\n\n\nHexadecimal equivalent: ";
	for(i=count;i>0;i--)
	{
		if(rem1[i]==10)
		{
			cout<<"A";
		}
		else if(rem1[i]==11)
		{
			cout<<"B";
		}
		else if(rem1[i]==12)
		{
			cout<<"C";
		}
		else if(rem1[i]==13)
		{
			cout<<"D";
		}
		else if(rem1[i]==14)
		{
			cout<<"E";
		}
		else if(rem1[i]==15)
		{
			cout<<"F";
		}
		else
		{
			cout<<rem1[i];
		}
	}
}
void hex_dec()
{
	long int i,dec=0,l,base=1;
	char hex[10];
	cout<<"\n\n\nEnter Hexadecimal number to have its Decimal Equivalent: ";
	gets(hex);
	l=strlen(hex);
	for(i=l-1;i>=0;i--)
	{
		if(hex[i]>=48&&hex[i]<=57)
		{
			dec = dec+((hex[i]-48)*base);
			base*=16;
		}
		else if(hex[i]>=65&&hex[i]<=70)
		{
			dec = dec+((hex[i]-55)*base);
			base = base*16;
		}
	}
	cout<<"\n\n\nDecimal Equivalent: "<<dec;
}
void hex_bin()
{
	long int i,dec=0,l,base=1,count=0,rem[10];
	char hex[10];
	cout<<"\n\n\nEnter Hexadecimal number to have its Binary Equivalent: ";
	gets(hex);
	l=strlen(hex);
	for(i=l-1;i>=0;i--)
	{
		if(hex[i]>=48&&hex[i]<=57)
		{
			dec = dec+((hex[i]-48)*base);
			base*=16;
		}
		else if(hex[i]>=65&&hex[i]<=70)
		{
			dec = dec+((hex[i]-55)*base);
			base*=16;
		}
	}
	while(dec)
	{
		count++;
		rem[count] = dec%2;
		dec/=2;
	}
	cout<<"\n\n\nBinary Equivalent: ";
	for(i=count;i>0;i--)
	{
		cout<<rem[i];
	}
}
void hex_oct()
{
	long int i,dec=0,l,base=1,count=0,rem[10];
	char hex[10];
	cout<<"\n\n\nEnter Hexadecimal number to have its Octal Equivalent: ";
	gets(hex);
	l=strlen(hex);
	for(i=l-1;i>=0;i--)
	{
		if(hex[i]>=48&&hex[i]<=57)
		{
			dec = dec+((hex[i]-48)*base);
			base*=16;
		}
		else if(hex[i]>=65&&hex[i]<=70)
		{
			dec = dec+((hex[i]-55)*base);
			base*=16;
		}
	}
	while(dec)
	{
		count++;
		rem[count] = dec%8;
		dec/=8;
	}
	cout<<"\n\n\nOctal Equivalent: ";
	for(i=count;i>0;i--)
	{
		cout<<rem[i];
	}
}
void frt()
{
	textcolor(0);
	textbackground(14);
	clrscr();
	cout<<"\t\t\t*******************************";
	cout<<"\n\t\t\t*******************************";
	cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||\t\t  [Main_Menu]";
	cout<<"\n\t\t\t*******************************";
	cout<<"\n\t\t\t*******************************";
	cout<<"\n\nNOTE: DON'T ENTER INVALID NUMBERS AND PLEASE TURN ON YOUR 'NUM LOCK' FOR \tCOVENIENCE...OTHERWISE YOU WILL GET INVALID RESULTS...AND YOU WILL BE IN TROUBLE...";
	cout<<"\nNOTE: THIS IS ONLY RELIABLE FOR NON - FRACTIONAL VALVES....";
	cout<<"\n\nOPTIONS...\n1.Conversion From Decimal To Others...";
	cout<<"\n\n2.Conversion From Binary To Others...";
	cout<<"\n\n3.Conversion From Octal To Others...";
	cout<<"\n\n4.Conversion From Hexadecimal To Others...";
	cout<<"\n\n5.EXIT...";
}
void selection()
{
	clrscr();
	int ch,ch1,ch2,ch3,ch4;
	while(ch!=5)
	{
		clrscr();
		frt();
		cout<<"\n\n\nEnter Your Choice...";
		cin>>ch;
		if(ch==1)
		{
			textcolor(14);
			textbackground(9);
			clrscr();
			cout<<"\t\t\t\t*************";
			cout<<"\n\t\t\t\t|| WELCOME ||";
			cout<<"\n\t\t\t\t*************";
			cout<<"\n\n\n1.Decimal To Binary...";
			cout<<"\n\n2.Decimal To Octal...";
			cout<<"\n\n3.Decimal To Hexadecimal...";
			cout<<"\n\n\n\nChoose Your Choice...";
			cin>>ch1;
			if(ch1==1)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				dec_bin();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************\n";
				getch();
			}
			else if(ch1==2)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				dec_oct();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************\n";
				getch();
			}
			else if(ch1==3)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				dec_hex();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************\n";
				getch();
			}
			else
			{
				textcolor(132);
				textbackground(0);
				clrscr();
				cout<<"\n\t\t\t\t     ERROR"<<"\n\t\t\t\t    *******";
				cout<<"\n\n\n\tInvalid Choice...";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
		}
		else if(ch==2)
		{
			textcolor(14);
			textbackground(9);
			clrscr();
			cout<<"\t\t\t\t*************";
			cout<<"\n\t\t\t\t|| WELCOME ||";
			cout<<"\n\t\t\t\t*************";
			cout<<"\n\n\n1.Binary To Decimal...";
			cout<<"\n\n2.Binary To Octal...";
			cout<<"\n\n3.Binary To Hexadecimal...";
			cout<<"\n\n\n\nChoose Your Choice...";
			cin>>ch2;
			if(ch2==1)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				bin_dec();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else if(ch2==2)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				bin_oct();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else if(ch2==3)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				bin_hex();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else
			{
				textcolor(132);
				textbackground(0);
				clrscr();
				cout<<"\n\t\t\t\t     ERROR"<<"\n\t\t\t\t    *******";
				cout<<"\n\n\n\tInvalid Choice...";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
		 }
		 else if(ch==3)
		 {
			textcolor(14);
			textbackground(9);
			clrscr();
			cout<<"\t\t\t\t*************";
			cout<<"\n\t\t\t\t|| WELCOME ||";
			cout<<"\n\t\t\t\t*************";
			cout<<"\n\n\n1.Octal To Decimal...";
			cout<<"\n\n2.Octal To Binary...";
			cout<<"\n\n3.Octal To Hexadecimal...";
			cout<<"\n\n\n\nChoose Your Choice...";
			cin>>ch3;
			if(ch3==1)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				oct_dec();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else if(ch3==2)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				oct_bin();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else if(ch3==3)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				oct_hex();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else
			{
				textcolor(132);
				textbackground(0);
				clrscr();
				cout<<"\n\t\t\t\t     ERROR"<<"\n\t\t\t\t    *******";
				cout<<"\n\n\n\tInvalid Choice...";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
		 }
		 else if(ch==4)
		 {
			textcolor(14);
			textbackground(9);
			clrscr();
			cout<<"\t\t\t\t*************";
			cout<<"\n\t\t\t\t|| WELCOME ||";
			cout<<"\n\t\t\t\t*************";
			cout<<"\n\n\n1.Hexadecimal To Decimal...";
			cout<<"\n\n2.Hexadecimal To Binary...";
			cout<<"\n\n3.Hexadecimal to octal...";
			cout<<"\n\n\n\nChoose Your Choice...";
			cin>>ch4;
			if(ch4==1)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				hex_dec();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else if(ch4==2)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				hex_bin();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else if(ch4==3)
			{
				textcolor(0);
				textbackground(9);
				clrscr();
				cout<<"\n\t\t\t|| NUMBER SYSTEM CONVERSIONS ||";
				cout<<"\n\t\t\t*******************************";
				hex_oct();
				getch();
				textcolor(130);
				clrscr();
				cout<<"\n\n\n\t\t\tPress Any Key To Continue...";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
			else
			{
				textcolor(132);
				textbackground(0);
				clrscr();
				cout<<"\n\t\t\t\t     ERROR"<<"\n\t\t\t\t    *******";
				cout<<"\n\n\n\tInvalid Choice...";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key To Continue...\n";
				cout<<"\n\t\t\t*******************************";
				getch();
			}
		 }
		 else if(ch==5)
		 {
			textcolor(2);
			textbackground(0);
			clrscr();
			cout<<"\n\n\n\t\t\tTHANK YOU FOR USING !!!... \n\n\n\t\t\tI HOPE YOU HAVE GOT YOUR RESULT..!!";
			delay(2000);
			clrscr();
			exit(0);
		 }
		 else
		 {
			textcolor(132);
			textbackground(0);
			clrscr();
			cout<<"\n\t\t\t\t     ERROR"<<"\n\t\t\t\t    *******";
			cout<<"\n\n\n\tInvalid Choice...";
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key To Continue...";
			cout<<"\n\t\t\t*******************************";
			getch();
		 }
	}
	getch();
}
void main()
{
	unsigned long int i,j;
	textcolor(2);
	textbackground(0);
	clrscr();
	cout<<"\n\n\n\t\t\tPRESS ANY KEY TO START THE COUNTDOWN...";
	getch();
	textcolor(130);
	clrscr();
	cout<<"\n\n\n\t\t\t*...LOADING...3 seconds...\n\n\t\t\t\tPLEASE WAIT...*";
	delay(1000);
	clrscr();
	cout<<"\n\n\n\t\t\t*...LOADING...2 Seconds...\n\n\t\t\t\tPLEASE WAIT...*";
	delay(1000);
	clrscr();
	cout<<"\n\n\n\t\t\t*...LOADING...1 Second...\n\n\t\t\t\tPLEASE WAIT...*";
	delay(1000);
	clrscr();
	cout<<"\n\n\n\t\t\t*...LOADED...0 Second...Let's Gooooo...!!!";
	delay(3000);
	textcolor(130);
	textbackground(0);
	clrscr();
	cout<<"\n\n\t\t\t\t\tLOADED\n\n\t\t\t PRESS ANY KEY TO PROCEED FURTHER...";
	getch();
	selection();
}













