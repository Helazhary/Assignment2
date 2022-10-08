#include "person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------constructor-------------------------
person::person()
{
	name = "";
	id = 0;
	age = 0;
}

//------------------------setters-----------------------------
void person::setname(string n)
{
	name = n;
}
void person::setid(int i)
{
	id = i;
}
void person::setage(int a)
{
	age = a;
}

//------------------------getters-----------------------------
string person::getname()
{
	return name;
}
int person::getid()
{
	return id;
}
int person::getage()
{
	return age;
}

//-------------------------print info-----------------------
void person::printinfo()
{
	cout << "\nName: " << getname() << endl;
	cout << "Age: " << getage() << endl;
	cout << "ID: " << getid() << endl;
	cout << endl;

}


