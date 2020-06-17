#ifndef DATABASE_H
#define DATABASE_h
#include <fstream>
#include <string>
#include<conio.h>
#include<iostream>
using namespace std;

class password
{ protected:
	char user[6], pass[10], instru[10];
public:
	password();
	void getpassword();
	void setpass();
	bool Enterpass();
	void resetingall();
	void changepassword();
	bool passw();
	void setnewpass(fstream&,int);
	string getusername();
};

#endif