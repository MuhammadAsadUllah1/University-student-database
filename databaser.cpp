#include "passh.h"
#include "databaseh.h"
#include<windows.h>
#include<cstdlib>
#include<ctime>
void stars(char, int);
	password::password()
	     {
		pass[10];
		user[6];
		instru[10];
		
     	 }
	void password::setpass()
	{
		
		cout << "\nEnter Username: ";
		cin >> user;
		cout << "Enter User password: ";
		cin >> pass;
		cout << "Enter User post: ";
		cin >> instru;
		}
	bool password::Enterpass()
	{
		char temp;
		string password1;
		cout << "Enter Password: ";
	while (static_cast<int>(temp = _getch()) != 13)
		{
			password1 += temp;
			cout << '*';	
	       Beep(523,400);
	}
		cout << endl;

		if (password1 == pass)
		{
			system("cls");
			cout << "\nwelcome Mr." << getusername() << "   (" << instru << ")";
		      time_t now = time(0);
              char* a = ctime(&now);
              cout<<endl;
			  cout<<"Login at: "<<a;
			  cout<<endl;
			return true;
						
		}
		else
		{
			cout << "wrong ..try again\n\n";
			return false;
		}


} 
	void password::resetingall()
	{
		char ch = ' ';
		fstream wrpasword1("pasword.dat", ios::out | ios::binary);


		wrpasword1.seekp(0);
		while (ch != 'm')
		{

			setpass();

			wrpasword1.write(reinterpret_cast<const char*>(this), sizeof(password));
			cout << "Enter m to end....." << endl;
			cin >> ch;
		}
	}
	void password::getpassword()

	{
	xy:
		fstream wrpasword("pasword.dat", ios::out | ios::in | ios::binary);
		//fstream wrdata("database.dat", ios::out | ios::in | ios::binary);
		if (!wrpasword)
		{
			cerr << "pass file has been hacked. If U r Admin or HACKER .. reset all file..  :(    \n";
			cin.get();
			resetingall();
			goto xy;
		}
	
		cout << "Enter username: ";
		system("color 3c");
		string a;
         cin >> a;	
		int i = 0;
		do
		{
			do	{
				wrpasword.seekg((i)*sizeof(this), ios::beg);
				wrpasword.read(reinterpret_cast<char*>(this), sizeof(password));
				if (user == a)
				{
					if (Enterpass() !=1 )
						goto xy;
					else
					{
						goto ok;
					}
				}
				if (user != a)
				{
					cout << "try again\n";
					goto xy;
					//	wrpasword.seekp(ios::beg);
				}

				i++;
			} while (wrpasword.tellg() >= 0);
			
		} while (wrpasword.eof()!=1);

	ok:;
	}
	string password::getusername()
	{
		return user;
	}
	//************************************************************************************
	//...................................................................................


	database::database()
	{
		street[10];city[10];province[10];country[10];
		firstname[10]; 
		lastname[10];
		degree[3]; section[2];
		mobileno[12];
		 roll=0;  cgpa=0;
		 cnic[13];
	}
	database::~database()
	{}





	//.............................................................


	void database::welcom()
	{

			char x[] = "\n**        ** ****** **      ****   **     ****   **** *******\n**        ** **     **     *     *    *   ** ** ** ** **   \n**  **    ** *****  **    *     *      *  **  **   ** ****** \n** ** **  ** **     **     *     *    *   **       ** **     \n****    **** ****** ******* ****   **     **       ** *******\n.";
			for (int i=0;x[i]!='.';i++)
{
cout << x[i];
z();

}			
			cout << "\n\n\n\n\n";
		    /*cout << "**        ** ****** **      ****   **     ****   **** *******" << endl;Sleep(500);
			cout << "**        ** **     **     *     *    *   ** ** ** ** **   " << endl;Sleep(500);
			cout << "**  **    ** *****  **    *     *      *  **  **   ** ****** " << endl;Sleep(500);
			cout << "** ** **  ** **     **     *     *    *   **       ** **     " << endl;Sleep(500);
			cout << "****    **** ****** ******* ****   **     **       ** *******" << endl;Sleep(1000);
	
	*/
			stars('*', 60);
	}


	//.......................................................



	void database::mainmenu()
	{
		
		loop:cout << "\n*************************   Main menu   ****************************  ";

		cout << "\n1: Search by name .";
		cout << "\n2: Search by roll# .";
		cout << "\n3: Change username and pass. .";
		cout << "\n4: Reseting data file. .";
		cout << "\n5: Change Password. .";
		cout << "\n6: New Entery. .";
		int choice;
		char main;
	cin >> choice;
	switch (choice)
	{
		choice = 0;
	case 1:
	{
			  diplaybyname();
			  cout << "\nEnter 'b' for main menu.. any key to exit.. :? ";
			  cin >> main;
			  if (main == 'b')
			  {
				  system("cls");
				  goto loop;
			  }break; }
	case 2:
	{
			  diplaybyroll();
			  cout << "\nEnter 'b' for main menu.. any key to exit.. :?";
			  cin >> main;
			  if (main == 'b')
			  {
				  system("cls");
				  goto loop;
			  }
			  //cout<<"Enter a to go back"<<endl;
			 
			  break; }

	case 3:
	{
			  resetingall();
			  cout << "\nEnter 'b' for main menu.. any key to exit.. :? ";
			  cin >> main;
			  if (main == 'b')
			  {
				  system("cls");
				  goto loop;
			  }
			  break; }
	case 4:
	{
			  renewentry();
			  cout << "\nEnter 'b' for main menu.. any key to exit.. :? ";
			  cin >> main;
			  if (main == 'b')
			  {
				  system("cls");
				  goto loop;
				  break;
			  }
			  	case 5:
	{
			  changepassword();
			  cout << "\nEnter 'b' for main menu.. any key to exit.. :? ";
			  cin >> main;
			  if (main == 'b')
			  {
				  system("cls");
				  goto loop;
				  break;
			  }
	}
	
			  	case 6:
	{
		newentry();
			  cout << "\nEnter 'b' for main menu.. any key to exit.. :? ";
			  cin >> main;
			  if (main == 'b')
			  {
				  system("cls");
				  goto loop;
				  break;
			  }}
	}
		stars('*', 70);
		_getch();
	
	}

	}




		//.............................................




	int database::diplaybyname()
	{
	xy:fstream dataread("database.dat", ios::out | ios::in | ios::binary);
		if (!dataread)
		{
			cerr << "file not here\a\a";
			exit(1);
		}

		cout << "\n\nEnter student's name: ";
		string a;
		cin >> a;
		int i = 0;
		
		
			do	{
				dataread.seekg((i)*sizeof(*this), ios::beg);
				dataread.read(reinterpret_cast<char*>(this), sizeof(database));
				if (firstname == a)
				{
					int s;
					cout << "\n\n1-Show information\n2-Edit the information\n3-delete student data\n";
					cin >> s;
					switch (s)
					{
					case 1:
						print(dataread,i); break;
					case 2:
						editrecord(dataread,i); break;
					case 3:
						deletrecord(dataread,i);


					}
					return 1;
					}
				
				if (firstname != a)
				{
					char r;

					cout << "No record  :xD  :\n";
					//cin >> r;
					//if (r == 'm')
						//return;
						//mainmenu(); 
					//	goto xy;

				}

				i++;
			} while (dataread.eof() != 1);
			
		//} while (dataread.eof()!=1);

	}





	//....................................................
	int database::diplaybyroll()
	{
	xy:fstream dataread("database.dat", ios::out | ios::in | ios::binary);
		if (!dataread)
		{
			cerr << "file not here";
			exit(1);
		}
		cout << "\n\nEnter student's Roll no.: ";
		int r;
		cin >> r;
		int i = 0;
		do
		{
			do	{
				dataread.seekg((i)*sizeof(*this), ios::beg);
				dataread.read(reinterpret_cast<char*>(this), sizeof(database));
				if (roll == r)
				{
					datafound(dataread,i);
				
					return 1;
				}


				i++;
			} while (dataread.tellg() >= 0);
			if (roll != r)
			{
				{
					char r;

					cout << "No record  :xD  :\n";
					
				}

			}
		} while (!dataread.eof());

	}
	
	void database::datafound(fstream &dataread,int i)
	{
	
					int s;
					cout << "\n\n1-Show information\n2-Edit the information\n3-delete student data\n4-Main menu";
					cin >> s;
					switch (s)
					{
					case 1:
						print(dataread,i); break;
					case 2:
						editrecord(dataread,i); break;
					case 3:
						deletrecord(dataread,i);
                      break;
					case 4:
						mainmenu();
					break;
					
					}
	}
	void password::changepassword()
	{
		xy:
		fstream wrpasword("pasword.dat", ios::out | ios::in | ios::binary);
		//fstream wrdata("database.dat", ios::out | ios::in | ios::binary);
		if (!wrpasword)
		{
			cerr << "pass file has been hacked. If U r Admin or HACKER .. reset all file..  :(    \n";
			cin.get();
			resetingall();
			goto xy;
		}
	
		cout << "Enter username: ";
		system("color 3c");
		string a;
         cin >> a;	
		int i = 0;
		do
		{
			do	{
				wrpasword.seekg((i)*sizeof(this), ios::beg);
				wrpasword.read(reinterpret_cast<char*>(this), sizeof(password));
				if (user == a)
				{
					if (passw() !=1 )
						goto xy;
					else
					{ 
					
						setnewpass(wrpasword,i);
						//wrpasword.seekg((i)*sizeof(this), ios::beg);
                        //wrpasword.write(reinterpret_cast<char*>(this), sizeof(password));
					}
				}
				/*if (user != a)
				{
					cout << "try again\n";
					goto xy;
					//	wrpasword.seekp(ios::beg);
				}
				*/
				i++;
			} while (wrpasword.tellg() >= 0);
			
		} while (wrpasword.eof()!=1);
	}
	//..................................
	bool password::passw()
	{
		char temp;
		string password1;
		cout << "Enter old Password: ";
	while (static_cast<int>(temp = _getch()) != 13)
		{
			password1 += temp;
			cout << '*';	
	       Beep(523,700);
	}
		cout << endl;

		if (password1 == pass)
		{

			return true;
						
		}
		else
		{
			cout << "wrong ..try again\n\n";
			return false;
		}


}
void password::setnewpass(fstream& wrpasword,int i)
{
cout<<"Enter new passpord"<<endl;
char a[10];

cin>>a;
for(int j=0;j<10;j++)
{
pass[j]=a[j];
}
wrpasword.seekg((i)*sizeof(this), ios::beg);
 wrpasword.write(reinterpret_cast<char*>(this), sizeof(password));
}

	void database::print(fstream &obj,int i)
	{

		stars('-', 80);
		cout << "\n***********************   Academic Information   **************************  ";
		stars('-', 80);
		cout << "\nName: " << firstname << " " << lastname << "\ndegree: " << degree << "\nsection: " << section
			<< "\nCGPA: " << cgpa << "\nRoll: " << roll << endl;
		stars('-', 80);
		cout << "\n************************   Personal Information:    ***********************";
		stars('-', 80);
		cout << "\nFather First-Name:" << Fatherfn <<"\nFather Last-name"<<Fatherln<<"\nC.N.I.C : " << cnic << "\nmobile # " << mobileno
			<< "\nAddress: " << street << ", " << city << ", " << province << ", " << country;
		stars('-', 80);
						  cout<<"Enter 'a' to goback"<<endl;
						  char a;
						  cin>>a;
						  if(a=='a')
						  {
                           datafound(obj,i);
						  }

	}



	//........................................................................

	void database::renewentry()
	{		char ch = ' ';
		ofstream wrdata("database.dat", ios::out);
wrdata.seekp(0);
		while (ch != 'm')
		{ 
			editacademic();
			editpersonal();
			
			wrdata.write(reinterpret_cast<const char*>(this), sizeof(database));
			cout << "Enter m to end....." << endl;
			cin >> ch;
}
	}





	void database::deletrecord(fstream& fobj,int j)
	{
		char ch;
		database blankobj;
		//cout << fobj.tellp();
		cout << "Press 'Y' to conform to delete this record: ";
		cin >> ch;
		
		if (ch == 'Y')
		{
			
			fobj.seekp((j)*sizeof(*this));
			fobj.write(reinterpret_cast<const char*>(&blankobj), sizeof(database));
		}
		else
			cout<<"\nYou dint delete";
	}





	void database::editrecord(fstream& wrdata1,int j)
	{
		//fstream wrdata("database.dat", ios::out);
		int e;
	
		cout << "\nWhat you want to change?..\n[1] change academic info\n[2] change personal info\n";
		cin >> e;
		switch (e)
		{
			
		case 1:
			acdemic();
			
			break;
		case 2:
			personal(wrdata1,j);
			
			break;
		}wrdata1.seekp((j)*sizeof(*this));
		wrdata1.write(reinterpret_cast<const char*>(this), sizeof(database));

	}
	void database::editacademic()
	{
		system("cls");
		cout << "\n _________________   Enter Academic info   _________________\n";

		cout << "Enter first name: ";
		cin >> firstname;
		cout << "Enter  last name: ";
		cin >> lastname;
		cout << "Enter Roll no.: ";
		cin >> roll;
		cout << "Enter  Degree: ";
		cin >> degree;
		cout << "Enter  section: ";
		cin >> section;
		cout << "Enter CGPA: ";
		cin >> cgpa;
	
	}void database::editpersonal()
	{
		system("cls");
		cout << " _________________   Enter personal info   _________________\n";

		cout << "\nEnter  Father First name: ";
		cin >> Fatherfn;
		cout << "Enter  Father Last name: ";
		cin >> Fatherln;
		cout << "Enter  cinc (1111111111111) ";		
		cin >> cnic;
		cout << "Enter  mobile: ";
		cin >> mobileno;
		cout << "Enter street: ";
		cin >> street;
		cout << "Enter city: ";
		cin >> city;
		cout << "Enter province: ";
		cin >> province;
		cout << "Enter Adress country: ";
		cin >> country;

	}
	void database::personal(fstream &dataread,int i)
	{
		system("cls");
		cout << " _________________   Enter personal info   _________________\n";
		int e;
		
		do{

		cout << "\nWhat you want to change?..\n[1] Father Name\n[2] Nnic\n[3] Mobile number\n[4] Street\n Nnic\n[5] City\n[6] Province\n[7] Country\n";
		cout<<"press 'o' to skip"<<endl;
		cin >> e;
		switch (e)
		{
		case 1:
			{
		cout << "\nEnter  First Father name: ";
		cin >> Fatherfn;
			}
			break;
		case 9:
			{
			cout<<"\n Enter father last name"<<endl;
			cin >> Fatherln;
			}
		case 2:
			{
		cout << "Enter  cinc (1111111111111) ";		
		cin >> cnic;
			} break;
		case 3:
			{
		cout << "Enter  mobile: ";
		cin >> mobileno;
			} break;
		case 4:
			{
		cout << "Enter street: ";
		cin >> street;
			}
			break;
		case 5:
			{
		cout << "Enter city: ";
		cin >> city;
			}
			break;
		case 6:
			{
		cout << "Enter province: ";
		cin >> province;
			} break;
		case 7:
			{
		cout << "Enter Adress country: ";
		cin >> country;
		}
		break;
		case 8:
			{

                           datafound(dataread,i);
			}
	}
		} while(e!=0);
		system("cls");
	}
		void database::acdemic()
	{
		system("cls");
		cout << "\n _________________   Enter Academic info   _________________\n";
		int a;
		do
		{
		cout << "\nWhat you want to change?..\n[1] First Name\n[2] Last Name\n[3] Roll no.\n[4] Degree\n[5] Section\n[6] Cgpa\n";
		cout<<"press 'o' to skip"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
		{
		cout << "Enter first name: ";
		cin >> firstname;
		}
		break;
		case 2:
			{
		cout << "Enter  last name: ";
		cin >> lastname;
			}
			break;
		case 3:
			{
		cout << "\nEnter Roll no.: ";
		cin >> roll;
			}
			break;
		case 4:
			{
		cout << "Enter  Degree: ";
		cin >> degree;
			}break;
		case 5:
			{
		cout << "Enter  section: ";
		cin >> section;
			} break;
		case 6:
			{
		cout << "Enter CGPA: ";
		cin >> cgpa;
			}break;
		}
		}while(a!=0);
		
	}
		void database::newentry()
		{v:
		fstream nentry("database.dat",ios::in|ios::out|ios::app);
		editacademic();
		editpersonal();
		nentry.write(reinterpret_cast<const char*>(this),sizeof(database));
	cout<<"[a] for next entry\n[b] for exit this menu\n";

	char a;
	cin >>a;
	system("cls");
	if(a=='a')
		goto v;

		}
