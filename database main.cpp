#include"passh.h"
#include"databaseh.h"
void stars(char, int);

void main()
{

	password passobject;
	database dataobject;
	char main;
	passobject.getpassword();
	dataobject.welcom();
	dataobject.mainmenu();

	}
void stars(char s,int a)
{	cout << endl;
	for (int i = 0; i < a; i++)
		cout << s;
}