#ifndef DATABASE_H
 #define DATABASE_h
#include <fstream>
#include <string>
#include<conio.h>
#include<iostream>
#include <windows.h>
using namespace std;

class database:public password
{
	char firstname[10], lastname[10], degree[3], section[2];
	char Fatherfn[10],Fatherln[10],street[10], city[10], province[10], country[10];
    char mobileno[12];
	char cnic[13];
	
	int roll;float cgpa;
public:
	database();

	~database();
	void print(fstream&,int);
	void newentry();
	void editrecord(fstream&,int);
	void deletrecord(fstream&,int);
	void welcom();
	void datafound(fstream&,int);
	void renewentry();
	int diplaybyname();
	int diplaybyroll();
	void getdata();
	void mainmenu();
	void editacademic();
	void editpersonal();
	void z() {Sleep(50);}
	void acdemic();
	void personal(fstream&,int);
};
#endif
