#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class person
{
private:
	//---------------------member variables-------------------
	string name;
	int id;
	int age;

public:

	//------------------------constructor-------------------------
	person();

	//------------------------setters-----------------------------
	void setname(string n);
	void setid(int i);
	void setage(int a);

	//------------------------getters-----------------------------
	string getname();
	int getid();
	int getage();

	//-------------------------print info-----------------------
	void printinfo();

	//--------------------------appointment---------------------
	struct Appointment
	{
	private:

		int hour = 0;
		int minute = 0;

	public:
		Appointment(int h=0, int m=0)
		{
			hour = h;
			minute = m;
		}

		void sethour(int h) 
		{hour = (h >= 0 && h < 24) ? h : 0;}

		void setminute(int m) 
		{minute = (m >= 0 && m < 60) ? m : 0;}

		int gethour() {return hour;}
		int getminute() {return minute;}

	};

};

	

