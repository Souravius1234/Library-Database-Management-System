#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <fstream.h>

/**
struct B_Book
{
	int B_ID;
	char Author[30];

}
**/

class lib
	{
	 	int B_ID;//Data Member
	 	char Book_name[30];//Data Member
	 	char Author[30];//Data Member
	 	char Genre[20];//Data Member
	 	char Username[30];//Data Member
	 	char Password[20];//Data Member
	 	char Password2[20];//Data Member
	 	char occupation[35];//Data Member
	 	int age;//Data Member
	 	  public:
	 	  int getbid()
	 		{
	 			return B_ID;
	 		}
	 		char *getn()
	 		{
	 			return Username;
	 		}
	 		char *getp()
	 		{
	 			return Password;
	 		}
	 		char *getb()
	 		{
	 			return Book_name;
	 		}
	 		char *getg()
	 		{
	 			return Genre;
	 		}
	 	    	void user_login_details()//Data Function
	 	    	{
	 	    		cout<<"\n\n\t\tEnter Username and Password";
	 	    		cout<<"\n\t\tEnter your Username =";
	 	    		gets(Username);
	 	    		cout<<"\n\t\tEnter your Password =";
	 	    		gets(Password);
	 	    	}
	 	    	void new_user()//Data Function
	 	    	{
	 	    		cout<<"Enter your NAME =";
	 	    		gets(Username);
	 	    		cout<<"Enter your AGE =";
	 	    		cin>>age;
	 	    		cout<<"Enter your Preferred GENRE =";
	 	    		gets(Genre);
	 	    		cout<<"Enter your OCCUPATION =";
	 	    		gets(occupation);
	 	    		cout<<"Enter a Password =";
	 	    		gets(Password);
	 	    		cout<<"Re-enter the Password =";
	 	    		gets(Password2);
	 	    		if(strcmp(Password, Password2)==0)
	 	    		cout<<"Welcome to BIBLIOTHECA, "<<Username;
	 	    	}

	 	    	void Books_GETData()//Data Function
	 	    	{
	 	    		cout<<"Enter the Details of the Book";
	 	    		cout<<"Enter BOOK ID =";
	 	    		cin>>B_ID;
	 	    		cout<<"Enter BOOK NAME =";
	 	    		gets(Book_name);
	 	    		cout<<"Enter AUTHOR NAME =";
	 	    		gets(Author);
	 	    		cout<<"Enter GENRE =";
	 	    		gets(Genre);
	 	    	}
	 	    	void Books_ShowData()//Data Function
	 	    	{
	 	    		cout<<"Book ID ="<<B_ID;
	 	    		cout<<"Book Name ="<<Book_name<<endl;
	 	    		cout<<"Author Name ="<<Author;
	 	    		cout<<"Genre ="<<Genre;
	 	    	}
	 	    	void Add_Book();
	 	    	void modify_book();
	 	    	void lib_home_pg();
	 	    	void Librarian();
	 	    	void create_newUser();
	 	    	void modify_user();
	 	    	void user_homepg();
	 	    	void User_Login();
	 	    	void Start_Page();
	 	    	void Book_Search();

	};

fstream f;
lib l;

void lib :: Add_Book()
{
	 	f.open("Bookslist.dat", ios::out|ios::binary);
	 	l.Books_GETData();
	 	f.write((char*)&l, sizeof(l));
	 	f.close();
}

void lib :: modify_book()
{
	int bn;
	char n[40]; char a[40]; char g[20];
	cout<<"Enter New Book ID =";
	cin>>bn;
	cout<<"Enter Book Name ";
	gets(n);
	cout<<"Enter Author name =";
	gets(a);
	cout<<"Enter Genre =";
	gets(g);
	l.B_ID = bn;
	strcpy(l.Book_name, n);
	strcpy(l.Author, a);
	strcpy(l.Genre, g);
}


void lib :: lib_home_pg()
{
	int x;
	read:
	clrscr();
	cout<<"\n\t\t        ********WELCOME LIBRARIAN********\n\n";
	cout<<"\t\t   <PLEASE CHOOSE ANY OF THE SUITABLE OPTIONS>";
	cout<<"\t\t\n\n\n1) Add Book";
	cout<<"\t\t\n\n\n2) Modify Book";
	cout<<"\t\t\n\n\n3) Remove Book";
	cout<<"\t\t\n\n\n4) Back to Main Menu";
	cout<<"\t\t\n\n\nEnter your CHOICE =";
	cin>>x;
	switch(x)
		{
			case 1:
			char Y;
			Redo:
			clrscr();
			Add_Book();
			cout<<"REDO ? (Y/N)"; cin>>Y;
			if(Y=='Y' || Y=='y')
			{
				goto Redo;
			}
			else
			{
				goto read;
			}
			break;
			case 2:
			clrscr();
			int count=0, pos; char bname[40];
			cout<<"Enter Book to be updated =";
			gets(bname);
			f.open("Booklist.dat", ios::in|ios::out|ios::binary);
			while(!f.eof())
			{
				pos = f.tellg();
				f.read((char*)&l, sizeof(l));
				if(strcmp(l.getb(),bname)==0)
				{
					modify_book();
					f.seekg(pos);
					f.write((char*)&l, sizeof(l));
					count++;
				}
			}
			if(count==0)
			{
				cout<<"Data not FOUND";
				getch();
			}
			f.close();
			break;
			case 3:
			clrscr();
			//Remove_book();
			cout<<"Remove Book";
			getch();
			break;
			case 4:
			clrscr();
			cout<<"Start Page";
			//Start_Page();
			break;
			default:
			cout<<"Please Choose the Right Numerical Option";
		}
}

void lib :: Librarian()
	{
	 	char pass1[21] = {"pass"}, pass[21];
	 	cout<<"Enter PASSWORD =";
		gets(pass);
	 	if(strcmp(pass, pass1)==0)
	 	lib_home_pg();
	 	else
	 	cout<<"Wrong Password";
	}

void lib :: create_newUser()
{
	 	f.open("User.dat", ios::out|ios::binary);
	 	l.new_user();
	 	f.write((char*)&l, sizeof(l));
	 	f.close();
	 	return 0;
}



void lib :: modify_user()
{
	char un[40]; char pw[40];
	cout<<"Enter new Username =";
	gets(un);
	cout<<"Enter new Password =";
	gets(pw);
	strcpy(l.Username, un);
	strcpy(l.Password, pw);
	return 0;
}

void lib :: user_homepg()
{
	int x;
	X:
	cout<<"\n\t\t           ********WELCOME USER********\n\n";
	cout<<"\t\t   <PLEASE CHOOSE ANY OF THE SUITABLE OPTIONS>";
	cout<<"\t\t\n\n\n1) Change Username and Password";
	cout<<"\t\t\n\n\n2) Borrow or Return a Book";
	cout<<"\t\t\n\n\n3) View Books Borrowed";
	cout<<"\t\t\n\n\n4) Back to Main Menu";
	cout<<"\t\t\n\n\nEnter your CHOICE =";
	switch(x)
	{
		case 1:
		clrscr();
			int count=0, pos; char uname[40]; char pword[40];
			cout<<"Enter Old Username =";
			gets(uname);
			cout<<"Enter Old Password =";
			gets(pword);
			f.open("User.dat", ios::in|ios::out|ios::binary);
			while(!f.eof())
			{
				pos = f.tellg();
				f.read((char*)&l, sizeof(l));
				if(strcmp(l.getn(),uname)==0 && strcmp(l.getp(), pword)==0)
				{
					modify_user();
					f.seekg(pos);
					f.write((char*)&l, sizeof(l));
					count++;
				}
			}
			if(count==0)
			{
				cout<<"Data not FOUND";
				getch();
			}
			f.close();
		break;
		case 2:
		Redo:
		clrscr();
		int i;
		cout<<"\n1) Borrow a Book";
		cout<<"\n\n2) Return a Book";
		cout<<"\n\n3) Return to User Page";
		cout<<"\nEnter your Choice =";
		cin>>i;
		switch(i)
		{
			case 1:
			Book_Search();
			cout<<"Do you want to borrow this book? (Y/N) ";
			char YN;
			cin>>YN;
			if(YN==Y)
			{
				f.open("borrowed_bk.dat", ios::in|ios::binary);
			}
			else
			{
		        goto Redo;
			}
			break;
			case 2:
			cout<<"Return a Book";
			break;
			case 3:
			goto X;

		}
			case 3:
			case 4: Start_Page(); break;
		default: cout<<"Enter Valid Choice";
	}
}

void lib :: User_Login()
{
	 	char name[30], pass[30];
	 	int a=0;
	 	cout<<"Enter Username =";
	 	gets(name);
	 	cout<<"Enter Password =";
	    gets(pass);
	 	f.open("User.dat", ios::in|ios::binary);
	 	if(!f)
	 	{
	 		cout<<"User not FOUND";
	 		getch();
	 	}
	 	else
	 	{
	 		f.read((char*)&l, sizeof(l));
	 		while(!f.eof())
	 		{
	 			if(strcmp(name, l.getn())==0 && strcmp(pass, l.getp())==0)
	 			{
	 			user_homepg();
	 			a++;
	 			}
	 		f.read((char*)&l, sizeof(l));
	 		}
	 	f.close();
	 }
	 if(a==0)
	 {
	 	cout<<"User not FOUND";
	    getch();
	 }
}

void lib :: Start_Page()
{
     int i;
     cout<<"\n\t\t********WELCOME TO THE BIBLIOTHECA********\n\n";
 	 cout<<"\t  By Sourav Ghosh, Syed Taha Zayd and Siddharth Shekhar";
 	 cout<<"\t\t\t\t\t<PLEASE CHOOSE ANY OF THE SUITABLE OPTIONS>";
 	 cout<<"\t\t\n\n\n1) User Login ";
     cout<<"\t\t\n\n2) New User ";
	 cout<<"\t\t\n\n3)Librarian Login";
	 cout<<"\t\t\n\n4) Exit Program";
 	 cout<<"\t\t\n\nEnter your CHOICE =";
 	 cin>> i;
 	 switch(i)
 	    {
 	 	  	case 1:
	 	   	clrscr();
	 	   	User_Login();
	     	break;
		   	case 2:
	 	   	clrscr();
	 	   	create_newUser();
	 	   	break;
	 	   	case 3:
	 	   	clrscr();
	 	   	Librarian();
	 	   	case 4:
	 	   	exit(0);
	 	   	break;
	 	   	default:
	 	   	cout<<"Please Choose the Right Numerical Option";
        }
        return 0;
}

/**void  lib :: Book_Search()
{
	 	char n[80]; int bid; int x; char g[20];
	 	int count=0;
	 	cout<<"\n\t\t     ********SEARCH BOOK MENU********\n\n";
 	 	cout<<"\t\t<PLEASE CHOOSE ANY OF THE SUITABLE OPTIONS>";
 	 	cout<<"\t\t\n\n\n1) Search Book by Name";
     	cout<<"\t\t\n\n2) Search Book by Book ID";
		cout<<"\t\t\n\n3) Search Book by Genre";
	 	cout<<"\t\t\n\n4)Back to Main Menu";
 	 	cout<<"\t\t\n\nEnter your CHOICE =";
	 	switch(x)
	 	{
	 		case 1:
	 			cout<<"Enter Book to be searched =";
	 			gets(n);
	 			f.open("Bookslist.dat", ios::in|ios::binary);
	 			if(!f)
	 			{
	 				cout<<"Book not FOUND";
	 				getch();
	 			}
	 			else
	 			{
	 				f.read((char*)&l, sizeof(l));
	 				while(!f.eof())
	 				{
	 					if(strcmp(n, l.getb())==0)
	 					{
	 						l.Books_ShowData();
	 						count++;
	 					}
	 					f.read((char*)&l, sizeof(l));
	 				}
	 				f.close();
	 			}
	 		break;
	 		case 2:
	 			cout<<"Enter Book ID to be searched =";
	 			cin>>bid;
	 			f.open("Bookslist.dat", ios::in|ios::binary);
	 			if(!f)
	 			{
	 				cout<<"Book not FOUND";
	 				getch();
	 			}
	 			else
	 			{
	 				f.read((char*)&l, sizeof(l));
	 				while(!f.eof())
	 				{
	 					if(bid==l.getbid())
	 					{
	 						l.Books_ShowData();
	 						count++;
	 					}
	 					f.read((char*)&l, sizeof(l));
	 				}
	 				f.close();
	 			}
	 		break;
	 		case 3:
	 			cout<<"Enter Genre of the Books =";
	 			gets(g);
	 			f.open("Bookslist.dat", ios::in|ios::binary);
	 			if(!f)
	 			{
	 				cout<<"Book not FOUND";
	 				getch();
	 			}
	 			else
	 			{
	 				f.read((char*)&l, sizeof(l));
	 				while(!f.eof())
	 				{
	 					if(strcmp(g, l.getg())==0)
	 					{
	 						l.Books_ShowData();
	 						count++;
	 					}
	 					f.read((char*)&l, sizeof(l));
	 				}
	 				f.close();
	 			}
	 		case 4:
	 		Start_Page();
	 		break;
	 		default:cout<<"Choose a Valid Option...";
	 	}
	 	if(count==0)
	 	{
			cout<<"Book not FOUND";
 			getch();
 		}
 		return 0;
}**/






void main()
{
	clrscr();
	Start_Page();
	getch();
}
