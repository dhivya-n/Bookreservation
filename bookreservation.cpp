//************************************************************//
//                       HEADER FILES                         //
//************************************************************//
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void login_main();
void administrator();
//************************************************************//
//        USED TO ENTER THE DETAILS OF THE BOOKS             //
//************************************************************//
class customer
{
	public:
	char password1[4],name[20],address[50],user[20];
 int age;
 long int number;	
}c;
class book
{
public:
int Serial_number,number_copies;
float price;
char author[20],book_name[20];
//************************************************************//
//                OBTAINING DETAILS OF THE BOOKS              //
//************************************************************//
 void get()
 {
 cout<<"\tEnter Serial no:";
 cin>>Serial_number;
 cout<<"\tEnter the book name:";
 cin>>book_name;
 cout<<"\tEnter the author's name:";
 cin>>author;
 cout<<"\tNumber of copies available:";
 cin>>number_copies;
 cout<<"\tEnter the Price of the book:";
 cin>>price;
 }
int return_id()
{
return Serial_number;
}
//************************************************************//
//                DISPLAYING BOOK DETAILS                  //
//************************************************************//
void put()
{
cout<<"\n\tSerial no:"<<Serial_number;
cout<<"\n\tBook name:"<<book_name;
cout<<"\n\tAuthor's name:"<<author;
cout<<"\n\tCopies available:"<<number_copies;
cout<<"\n\tPrice:"<<price<<"\n\n";
}
};
//************************************************************//
//                     ADMINISTRATOR                          //
//************************************************************//
void administrator()
{
	book a;
 int i,n;
 system("cls");
 int ch;
 do
 {
 system("cls");
cout<<"\n\t#####################################################################\n";
cout<<"\t                           WELCOME ADMINISTRATOR                 \n";
cout<<"\t#####################################################################\n";
 cout<<"\n\t1. Write details of the books..";
 cout<<"\n\t2. Display all books ..";
 cout<<"\n\t3. Display selected books ..";
 cout<<"\n\t4. Edit selected book..";
 cout<<"\n\t5. Delete book ..";
 cout<<"\n\t6.log out..\n";
 cout<<"\tEnter your choice:";
 cin>>ch;
 switch(ch)
 {
//WRITING THE DETAILS OF THE BOOK
 case 1:{
	char cont;
	 ofstream file;
	 file.open("book_details.dat",ios::app|ios::binary);
	 do{
	  a.get();
	  file.write((char *)&a,sizeof(a));
	  cout<<"\tDetails updated: \n\tPress y if you want to continue:";
	  cin>>cont;
	  }while(cont=='y'||cont=='Y');
	  file.close();
	     } break;
//DISPLAYING THE BOOK DETAILS//
	case 2:
		{
	   ifstream file1;
	   file1.open("book_details.dat",ios::binary);
	   while(file1.read((char *)&a,sizeof(a)))
	   {
	   a.put();
	   }
	   file1.close();
	     getch();
	     break;
	 }
//DISPLAYING SELECTED BOOK//
	case 3:
	{
	    unsigned long reqd_book;
					int flag=0;
					ifstream file;
					file.open("book_details.dat",ios::binary);
					cout<<"\tEnter the serial number of the book Which you like to see:";
					cin>>reqd_book;
					while(file.read((char *)&a,sizeof(a)))
					{
						if(a.return_id()==reqd_book)
						{
							flag=1;
							a.put();
						}
					}
					file.close();
					if(flag==0)
					cout<<"\tNo Such serial number is found";
				}
				getch();
				break;
//MODIFYING THE BOOK DETAILS//
	case 4:
	   {unsigned long reqd_id;

						int flag=0;
						ofstream fo;
						fo.open("temp.dat",ios::binary);
						ifstream file;
						file.open("book_details.dat",ios::in|ios::binary);
						cout<<"\tEnter the serial number of the book which you want to edit:";
						cin>>reqd_id;
						while(file.read((char *)&a,sizeof(a)))
						{
							if(a.return_id()==reqd_id)
							{
								flag=1;
								a.put();
								cout<<"\n\tEnter new details\n";
								a.get();
								fo.write((char *)&a,sizeof(a));
							}
						}
						file.close();
						file.open("book_details.dat",ios::app|ios::binary);
						if(flag)
						{
							while(file.read((char *)&a,sizeof(a)))
							{
								if(a.return_id()!=reqd_id)
								{
									fo.write((char *)&a,sizeof(a));
								}
							}
							fo.close();
							file.close();
							remove("book_details.dat");
							rename("temp.dat","book_details.dat");
						}
						if(!flag)
						cout<<"\tNo Such serial number found";
			  }
			  getch();
			  break;
//DELETING THE SELECTED BOOK//
	 case 5:
	  {
					unsigned long reqd_id;
					char ch='n';
					int flag=0,confirm=0;
					ofstream fo;
					fo.open("temp.dat",ios::binary);
					ifstream file;
					file.open("book_details.dat",ios::app|ios::binary);
					cout<<"\tEnter the serial number of the book which you like to delete:";
					cin>>reqd_id;
					while(file.read((char *)&a,sizeof(a)))
					{
						if(a.return_id()==reqd_id)
						{
							flag=1;
							a.put();
							cout<<"\nDo you want to delete?";
							cin>>ch;
							if(ch=='y'||ch=='Y')
							{
								confirm=1;
							}
						}
					}
					file.close();
					file.open("book_details.dat",ios::app|ios::binary);
					if(confirm)
					{
						while(file.read((char *)&a,sizeof(a)))
						{
							if(a.return_id()!=reqd_id)
							{
								fo.write((char *)&a,sizeof(a));
							}
						}
						fo.close();
						file.close();
						remove("book_details.dat");
						rename("temp.dat","book_details.dat");
					}
					if(!flag)
					cout<<"\tNo Such Serial number found";
			  }
			  getch();
			  break;
	//SCIENCE


	  
	  }
    }while(ch!=6);
}
//************************************************************//
//                       USER PAGE                             //
//************************************************************//
class user_page
{
private:
int copies,user_book;
long phone;
void search();
void buy();
void buy_portal();
void customer_details();
void put();
void required_book();
void confirm_page();
int return_phone();
public:
	void welcome();
}us;
char admin_user[20]={"admin"},admin_password[4]={"ssn"};
//************************************************************//
//                        LOGIN PAGE                          //
//************************************************************//
void login(char corUser[20],char corPwd[4]
{
char User[20],Pwd[4];
system("cls");
cout<<"\n\t*********************************************************************\n";
cout<<"\t                           TO LOGIN:                 \n";
cout<<"\t*********************************************************************\n";
cout<<"\tEnter user name        :";
cin>>User;
cout<<"\tEnter the password     :";
for(int i=0;i<3;i++)
{
	Pwd[i]=getch();
	cout<<"*";
}
Pwd[3]='\0';
if((strcmp(User,corUser)==0)&&(strcmp(Pwd,corPwd)==0))
{
cout<<"\n\t\tYou are Logged in";
if(strcmp(User,admin_user)==0)
{
cout<<"\n\t Welcome admin!!!!";
administrator();
}
else
us.welcome();
}
else
cout<<"\tSorry username or password is wrong";
getch();
login_main();
}
//************************************************************//
//                      REGISTRATION                         //
//************************************************************//
void registration()
{
	char password2[4],ch;
	int p;
 system("cls");
cout<<"\n\t=====================================================================\n";
cout<<"\t                          REGISTRATION               \n";
cout<<"\t====================================================================\n";
 cout<<"\n\tEnter the name                  :";
 cin>>c.name;
 cout<<"\n\tEnter user name                 :";
 cin>>c.user;
do
{
cout<<"\n\tEnter password                  :";
for(int i=0;i<3;i++)
{
	c.password1[i]=getch();
	cout<<"*";
}
c.password1[3]='\0';
cout<<"\n\n\tConfirm password                :";
for(int i=0;i<3;i++)
{
	password2[i]=getch();
	cout<<"*";
}
password2[3]='\0';
cout<<"\n";
if((strcmp(c.password1,password2)!=0))
{cout<<"\n\t Re enter the password\n";
p=0;
}
else
p=1;
}while(p==0);
cout<<"\n";
cout<<"\n\tEnter age                       :";
cin>>c.age;
cout<<"\n\tEnter contact number            :";
cin>>c.number;
cout<<"\n\tEnter address                   :";
cin>>c.address;
cout<<"\n\tYou are successfully registered";
getch();
login(c.user,c.password1);
};
void login_main()
{
int a;
system("cls");
//************************************************************//
//                        HOME PAGE                           //
//************************************************************//
cout<<"\n\t=====================================================================\n";
cout<<"\t==                       WELCOME TO BOOK STORE                     ==\n";
cout<<"\t=====================================================================\n";
cout<<"\t1.Sign up\n\t2.Sign in\n\t3.Administrator\n\t4.Quit\n\tChoose your option:";
cin>>a;
switch(a)
{
case 1:
registration();
break;
case 2:
login(c.user,c.password1);
break;
case 3:
login(admin_user,admin_password);
break;
case 4:
break;
default:
cout<<"Invalid choice\nChoose Your option only from the choice";
getch();
login_main();
break;
}
}
void user_page::search()
{
	book a;
    int i,n;
    system("cls");
     int ch;
     do
    {
    system("cls");
    cout<<"\n\t*********************************************************************\n";
    cout<<"\t                         WELCOME  $ "<<c.user<<" $       			    \n";
    cout<<"\t*********************************************************************\n";
    cout<<"\n\t1. Search by book Name...";
   cout<<"\n\t2. Search by author Name...";
   cout<<"\n\t3. Search by serial number...";
   cout<<"\n\t4. Exit..\n";
   cout<<"\tEnter your choice:";
 cin>>ch;
 switch(ch)
 {
 	case 1:
	{
	               char reqd_book[20];
					int flag=0;
					ifstream file;
					file.open("book_details.dat",ios::binary);
					cout<<"\tEnter the name of the book Which you like to see:";
					cin>>reqd_book;
					while(file.read((char *)&a,sizeof(a)))
					{
						if(strcmp(a.book_name,reqd_book)==0)
						{
							flag=1;
							a.put();
						}
					}
					file.close();
					if(flag==0)
					cout<<"No Such book is found";
				}
				getch();
				break;
				 	case 2:
	{
	               char reqd_book[20];
					int flag=0;
					ifstream file;
					file.open("book_details.dat",ios::binary);
					cout<<"\tEnter the name of the book Which you like to see:";
					cin>>reqd_book;
					while(file.read((char *)&a,sizeof(a)))
					{
						if(strcmp(a.author,reqd_book)==0)
						{
							flag=1;
							a.put();
						}
					}
					file.close();
					if(flag==0)
					cout<<"No Such author is found";
				}
				getch();
				break;
	
	case 3:
	{
	    unsigned long reqd_book;
					int flag=0;
					ifstream file;
					file.open("book_details.dat",ios::binary);
					cout<<"\tEnter the serial number of the book Which you like to see:";
					cin>>reqd_book;
					while(file.read((char *)&a,sizeof(a)))
					{
						if(a.return_id()==reqd_book)
						{
							flag=1;
							a.put();
						}
					}
					file.close();
					if(flag==0)
					cout<<"No Such serial number is found";
				}
				getch();
				break;

	  }

    }while(ch != 4);
    us.welcome();
}
void user_page::required_book()
{
	book a;
unsigned long reqd_book;
					int flag=0;
					ifstream file;
					file.open("book_details.dat",ios::binary);
					cout<<"\tEnter the serial number of the book Which you like to buy:";
					cin>>reqd_book;
					user_book=reqd_book;
					while(file.read((char *)&a,sizeof(a)))
					{
						if(a.return_id()==reqd_book)
						{
							flag=1;
							a.put();
						}
					}
					file.close();
					if(flag==0)
					cout<<"No Such serial number is found";
}
int user_page::return_phone()
{
return(phone);
}
void user_page::buy_portal()
{

      system("cls");
	  ofstream file1;
	 file1.open("customer_details.dat",ios::app|ios::binary);
	  us.customer_details();
	  file1.write((char *)&us,sizeof(us));
	  cout<<"\tYour Details are updated: \n";
	  file1.close();
	  int con_phone;
	  required_book();
	  confirm_page();
}
void user_page::confirm_page()
{
	book a;
system("cls");
cout<<"Your book details are";
int flag=0;
					ifstream file;
					file.open("book_details.dat",ios::binary);
					while(file.read((char *)&a,sizeof(a)))
					{
						if(a.return_id()==user_book)
						{
							flag=1;
							a.put();
						}
					}
					file.close();
					if(flag==0)
					cout<<"No Such serial number is found";

int flag1=0,con_phone,submit;
					ifstream file2;
					number:
					file2.open("customer_details.dat",ios::app|ios::binary);
					cout<<"\tConfirm phone number:";
					cin>>con_phone;
					while(file2.read((char *)&us,sizeof(us)))
					{
						if(us.return_phone()==con_phone)
						{
							flag1=1;
							us.put();
						}
					 }
					file2.close();
					if(flag1==0)
					{
					cout<<"Invalid phone number\n";
					goto number;
					}
					cout<<"\n\tChoose 1 to submit and 2 to re enter the details";
					cin>>submit;
					if(submit==1)
					{
					system("cls");
					cout<<"\n\n\n\n\n\t\tSUCCESS!!!!\n\n\n\tYour bill details has been sent to Your PHONE NUMBER\n\n\n\tYour books will be delivered shortly at Your Door Step.\n\n\tThanks for buying";
					}
					else
					buy_portal();
}
//************************************************************//
//              OBTAINING  CUSTOMER  DETAILS                  //
//************************************************************//
void user_page::customer_details()
{
	char name[21],address[20];
cout<<"\nBuy portal:\n";
cout<<"Enter your name:";
cin>>name;
cout<<"Enter your address:";
cin>>address;
cout<<"Enter your phone number:";
cin>>phone;
cout<<"Enter the number of copies needed:";
cin>>copies;
}
//************************************************************//
//              DISPLAYING CUSTOMER DETAILS                   //
//************************************************************//
void user_page::put()
{
cout<<"Your Bill:";
cout<<"\n\t===========================================";
cout<<"\n\t===========================================";
cout<<"\n\t  Your Name :" <<c.name;
cout<<"\n\t  Your Address :" <<c.address;
cout<<"\n\t  Your Phone number :"<<phone;
cout<<"\n\t  Copies Requested : "<<copies;
cout<<"\n\t===========================================";
cout<<"\n\t===========================================";
}
void user_page::buy()
{
	book a;
   int option,option1,b=0;
   ifstream file1;
   file1.open("book_details.dat",ios::binary);
   while((file1.read((char *)&a,sizeof(a)))&&b!=1)
     {
      a.put();
      cout<<"\n\t1.Buy..\n\t2.Next book..\n\tChoose your option: ";
      cin>>option;
      if(option==1)
      {
      b=1;
      cout<<"\n\tDo you want to buy this book?\n\t1.yes..\n\t2.no..\n\tChoose your option: ";
      cin>>option;
      if(option==1)
      {
      us.buy_portal();
      }
      else
      {
      b=0;
      }
      }
      }
   file1.close();
   cout<<"\n\tEnd of books";
   getch();
   us.welcome();
}
//************************************************************//
//                      USER HOME PAGE                       //
//************************************************************//
void user_page::welcome()
{
int option;
system("cls");
cout<<"\n\t*********************************************************************\n";
cout<<"\t                      Welcome $ "<<c.user<<" $                           \n";
cout<<"\t*********************************************************************\n";
cout<<"\n1.Search books...\n2.Buy books\n3.Buy selected books\n4.Log out...\nChoose your option:";
cin>>option;
switch(option)
{
case 1:
us.search();
break;
case 2:
us.buy();
break;
case 3:
buy_portal();
break;
case 4:
getch();
break;
default:
cout<<"Invalid choice\nChoose Your option only from the choice";
getch();
welcome();
break;
}
}
//************************************************************//
//                      MAIN  FUNCTION                        //
//************************************************************//
int main()
{
login_main();
}
