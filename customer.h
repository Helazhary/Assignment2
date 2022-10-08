#pragma once
#include "person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class customer : public person
{

private:
	//---------------------member variables-------------------
	int mechanicID;
	string mechanicname;
	Appointment appointment;
	

public:
	//------------------------setters-----------------------------
	customer();
	void setmechanicID(int i);
	void setappointment(int h = 0, int m = 0);
	void setmechanicname(string n);

	//------------------------getters-----------------------------
	int getmechanicID();
	int getappointment_h();
	int getappointment_m();
	string getmechanicname();
	bool hasAppointment = false; //checks in the end if the customer has an appointment or couldn't find an avaialble mechanic

	bool operator > (customer& c);
	bool operator < (customer& c);
	bool operator == (customer& c);

	


};

