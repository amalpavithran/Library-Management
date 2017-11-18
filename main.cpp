#include<iostream.h>                                                                                                                                                                                                                                                              #include<iostream.h>
#include<string.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>
long speedglobal=4500;
void mainmenu();
void searchID();
void searchname();
void membermainmenu();
void searchmembers();
void displaymembers();
void addmembers();
void addbooks();
void displaybooks();
void searchbooks();
void searchBookID();
void searchBookname();
void searchBookauthor();

void main()
{
	mainmenu();
}
void membermainmenu()
{
	clrscr();
	for(int i=17;i<=52;i++)
	{
		gotoxy(i,0);
		cout<<"*";
	}
	for(i=0;i<=11;i++)
	{
		gotoxy(17,i);
		cout<<"*";
	}
	for(i=17;i<=52;i++)
	{
		gotoxy(i,11);
		cout<<"*";
	}
	for(i=0;i<=11;i++)
	{
		gotoxy(52,i);
		cout<<"*";
	}

gotoxy(25,2);
cout<<"MEMBER ADMINISTRATION"<<endl;
int option;
gotoxy(20,4);
cout<<"1. ADD NEW MEMBERS"<<endl;
gotoxy(20,5);
cout<<"2.SEARCH MEMBERS"<<endl;
gotoxy(20,6);
cout<<"3.Display details of all members"<<endl;
gotoxy(20,7);
cout<<"4.EXIT"<<endl;
gotoxy(20,10);
cout<<"CHOOSE AN OPTION ABOVE:"<<" ";
cin>>option;
char wait;
switch(option)
{
case 1:clrscr();
addmembers();
break;
case 2:clrscr();
searchmembers();
break;
case 3:clrscr();
displaymembers();
break;
case 4: clrscr();
mainmenu();
break;
default:clrscr();
gotoxy(25,10);
cout<<"INVALID CHOICE";
gotoxy(25,12);
cout<<"CHOOSE AGAIN";
gotoxy(18,14);
cout<<"ENTER any key to continue";
cin>>wait;
membermainmenu();
break;
}
}

class Member                   //Basic class for MEMBERS of the system
{
public:
char Name[20];
long Telno ;
float fee;
float payment;
int MemID;
void getmembers();
void showmembers();
};

void addmembers()                        //Function to Add new members
 {
 clrscr();
 char ch;
ofstream fout;
Member m;
int i,n;
fout.open("members.dat",ios::binary|ios::app);
cout<<"Enter the number of members you want to Add"<<endl;
cin>>n;
for(i=0;i<n;i++)
{
clrscr();
cout<<"Enter the details of the new member";
cout<<endl;
m.getmembers();
fout.write((char*)&m,sizeof(m));
cout<<"Member Added";
cout<<endl;
}
fout.close();
cout<<"Do you want to add more members?(Y/N)";
cin>> ch;
if(ch=='Y' || ch=='y')
addmembers();
else
membermainmenu();
}
void Member :: getmembers()              //Member Function to obtain intial details of members
 {
 cout<<"Enter Member ID";
 cin>>MemID;
 cout<<"Enter NAME:";
 gets(Name);
 cout<<"Enter Telephone number";
 cin>> Telno;
cout<< "Membership Package (BD-5/month (3 books/week),BD-3/month(2 books/week),BD-1/month(1 books/week)) enter the price of the package required"<<" "<<"BD";
cin>>fee;
 }
 void Member :: showmembers()            //Member Function to show intial details of members
 {
cout<<"Member Details";
cout<<endl;
cout<<"Member ID:"<<" "<<MemID;
cout<<endl;
cout<<"Name:"<<""<<Name;
cout<<endl;
cout<<"Telephone Number:"<<" "<<Telno;
cout<<endl;
cout<<"Membership package:"<<"BD-"<<fee;
cout<<endl;
}
void displaymembers()
{ char wait;
clrscr();
ifstream fin;
fin.open("members.dat",ios::binary|ios::in);
Member M;
while(fin.read((char*)&M,sizeof(M)))
{
M.showmembers();
cout<<endl;
}
fin.close();
cout<<endl;
cout<<"\nENTER any key to continue:"<<" ";
cin>>wait;
membermainmenu();
}

void searchmembers()
{
int op;
cout<<"How would you like to search for the member?"<<endl;
gotoxy(25,3);
cout<<"1.By Member ID";
gotoxy(25,4);
cout<<"2.By Name";
gotoxy(25,5);
cout<<"3.Back";
gotoxy(15,7);
cout<<"CHOOSE AN OPTION:"<<"";
cin>>op;
switch(op)
{
case 1:clrscr();
 searchID();
break;
case 2: clrscr();
searchname();
break;
case 3: clrscr();
membermainmenu();
break;
}
}
void searchID()
{
ifstream fin;
fin.open("members.dat",ios::binary|ios::in);
Member S;
int j=0;
char wait;
int ID;
cout<<"Enter the Member ID "<<endl;
cin>>ID;
while(fin.read((char*)&S,sizeof(S)) )
if(ID==S.MemID)
{
S.showmembers();
j=1;
}
if(j==0)
{
clrscr();
cout<<ID;
cout<<" "<<"DOES NOT EXIST"<<endl;
cout<<endl;
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
membermainmenu();
}
else
{
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
membermainmenu();
}
}
void searchname()
{
char wait;
int j=0;
ifstream fin;
fin.open("members.dat",ios::binary|ios::in);
Member S;
char name[20];
cout<<"Enter the Member’s name "<<endl;
gets(name);
while(fin.read((char*)&S,sizeof(S)))
if(strcmp(S.Name,name)==0)
{
S.showmembers();
j=1;
}
if(j==0)
{
clrscr();
cout<<name<<" "<<"DOES NOT EXIST"<<endl;
cout<<endl;
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
membermainmenu();
}
else
{
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
membermainmenu();
}
}


class Book
{
 public:
 long bookID;
 char Title[50];
 char Author[50];
 float price;
 int Qty;
 int Qtyavailable;
 void getbookdata();
 void showbookdata();

};
void Book:: getbookdata()				 //Member Function to obtain intial details of books
 {
 cout<<"Enter Book ID:"<<endl;
 cin>>bookID;
 cout<<"Enter NAME:"<<endl;
 gets(Title);
 cout<<"Enter Author’s name:"<<endl;
gets(Author);
cout<<"Enter price of this book"<<endl;
cin>>price;
cout<<"Enter the no of this book the library owns"<<endl;
cin>>Qty;
Qtyavailable=Qty;
}

 void Book :: showbookdata()            //Member Function to show intial details of books
 {
cout<<"Book Details";
cout<<endl;
cout<<"Book ID:"<<" "<<bookID;
cout<<endl;
cout<<"Name:"<<" "<<Title;
cout<<endl;
cout<<"Author"<<" "<<Author;
cout<<endl;
cout<<"Price of this book:"<<" "<<"BD-"<<price;
cout<<endl;
cout<<"Quantity of this book the library owns:"<<" "<<Qty;
cout<<endl;
cout<<"Quantity of the book available:"<<" "<<Qtyavailable;
cout<<endl;
 }
 void bookmainmenu()
{
clrscr();
for(int i=17;i<=52;i++)
{gotoxy(i,0);
cout<<"*";
}
for(i=0;i<=11;i++)
{gotoxy(17,i);
cout<<"*";
}
for(i=17;i<=52;i++)
{gotoxy(i,11);
cout<<"*";
}
for(i=0;i<=11;i++)
{gotoxy(52,i);
cout<<"*";
}

gotoxy(25,2);
cout<<"BOOK ADMINISTRATION"<<endl;
int option;
gotoxy(20,4);
cout<<"1.ADD NEW BOOKS"<<endl;
gotoxy(20,5);
cout<<"2.SEARCH BOOKS"<<endl;
gotoxy(20,6);
cout<<"3.Display details of all books"<<endl;
gotoxy(20,7);
cout<<"4.EXIT"<<endl;
gotoxy(20,10);
cout<<"CHOOSE AN OPTION ABOVE:"<<" ";
cin>>option;
char wait;
switch(option)
{
case 1:clrscr();
addbooks();
break;
case 2:clrscr();
searchbooks();
break;
case 3:clrscr();
displaybooks();
break;
case 4: clrscr();
mainmenu();
break;
default:clrscr();
gotoxy(25,10);
cout<<"INVALID CHOICE";
gotoxy(25,12);
cout<<"CHOOSE AGAIN";
gotoxy(18,14);
cout<<"ENTER any key to continue";
cin>>wait;
bookmainmenu();
break;
}
}

void addbooks()                        //Function to Add new members
 {
 clrscr();
 char ch;
ofstream fout;
Book b;
int i,n;
fout.open("books.dat",ios::binary|ios::app);
cout<<"Enter the different number of Books you want to Add"<<endl;
cin>>n;
for(i=0;i<n;i++)
{
clrscr();
cout<<"Enter the details of the new Book";
cout<<endl;
b.getbookdata();
fout.write((char*)&b,sizeof(b));
cout<<"Book Added";
cout<<endl;
}
fout.close();
cout<<"Do you want to add more books?(Y/N)";
cin>> ch;
if(ch=='Y' || ch=='y')
addbooks();
else
bookmainmenu();

}

void displaybooks()
{
char wait;
clrscr();
ifstream fin;
fin.open("books.dat",ios::binary|ios::in);
Book b;
while(fin.read((char*)&b,sizeof(b)))
{
b.showbookdata();
cout<<endl;
}
fin.close();
cout<<endl;
cout<<"\nENTER any key to continue:"<<" ";
cin>>wait;
bookmainmenu();
}

void searchbooks()
{
int op;
cout<<"How would you like to search for the member?"<<endl;
gotoxy(25,3);
cout<<"1.By Book ID";
gotoxy(25,4);
cout<<"2.By Name";
gotoxy(25,5);
cout<<"3.By Author";
gotoxy(25,6);
cout<<"4.BACK";
gotoxy(15,8);
cout<<"CHOOSE AN OPTION:"<<"";
cin>>op;
switch(op)
{
case 1:clrscr();
 searchBookID();
break;
case 2: clrscr();
searchBookname();
break;
case 3: clrscr();
searchBookauthor();
break;
case 4: clrscr();
bookmainmenu();
break;
}
}
void searchBookID()
{
ifstream fin;
fin.open("books.dat",ios::binary|ios::in);
Book B;
int j=0;
char wait;
int ID;
cout<<"Enter the Book ID "<<endl;
cin>>ID;
while(fin.read((char*)&B,sizeof(B)) )
if(ID==B.bookID)
{
B.showbookdata();
j=1;
}
fin.close();
if(j==0)
{
clrscr();
cout<<ID;
cout<<" "<<"DOES NOT EXIST"<<endl;
cout<<endl;
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
bookmainmenu();
}
else
{
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
bookmainmenu();
}
}
void searchBookname()
{
char wait;
int j=0;
ifstream fin;
fin.open("books.dat",ios::binary|ios::in);
Book B;
char name[20];
cout<<"Enter the Book’s name:"<<" ";
gets(name);
cout<<endl;
while(fin.read((char*)&B,sizeof(B)))
if(strcmp(B.Title,name)==0)
{
B.showbookdata();
j=1;
}
fin.close();
if(j==0)
{
clrscr();
cout<<name<<" "<<"IS NOT OWNED BY US"<<endl;
cout<<endl;
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
bookmainmenu();
}
else
{
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
membermainmenu();
}
}
void searchBookauthor()
{
char wait;
int j=0;
ifstream fin;
fin.open("books.dat",ios::binary|ios::in);
Book B;
char name[20];
cout<<"Enter the Author's name "<<endl;
gets(name);
while(fin.read((char*)&B,sizeof(B)))
if(strcmp(B.Author,name)==0)
{
B.showbookdata();
j=1;
}
fin.close();
if(j==0)
{
clrscr();
cout<<name<<"'s"<<" " <<"IS NOT OWNED BY US"<<endl;
cout<<endl;
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
bookmainmenu();
}
else
{
cout<<"ENTER any key to continue:"<<" ";
cin>>wait;
bookmainmenu();
}
}
void mainmenu()
{
clrscr();
for(int i=17;i<=52;i++)
{gotoxy(i,0);
cout<<"*";
}
for(i=0;i<=11;i++)
{gotoxy(17,i);
cout<<"*";
}
for(i=17;i<=52;i++)
{gotoxy(i,11);
cout<<"*";
}
for(i=0;i<=11;i++)
{gotoxy(52,i);
cout<<"*";
}

gotoxy(25,2);
cout<<"LIBRARY MENU"<<endl;
int option;
gotoxy(20,4);
cout<<"1.MEMBER ADMINISTRATION"<<endl;
gotoxy(20,5);
cout<<"2.BOOK ADMINISTRATION"<<endl;
gotoxy(20,6);
cout<<"3.EXIT"<<endl;
gotoxy(20,9);
cout<<"CHOOSE AN OPTION ABOVE:"<<" ";
cin>>option;
char wait;
switch(option)
{
case 1:clrscr();
membermainmenu();
break;
case 2:clrscr();
bookmainmenu();
break;
case 3:clrscr();
break;
}
}
