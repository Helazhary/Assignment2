#pragma once
#include "customer.h"
#include "person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class mechanic : public person
{
private:
	int counter=0;
	vector <Appointment> mechanicappointments;

public:
	bool isAvailable(int h, int m);
	void setcounter(int c);
	int getcounter();
	void appbook(int h, int m);

};

