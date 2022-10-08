#include "mechanic.h"
#include "customer.h"
#include "person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void mechanic::setcounter(int c)
{
	counter = c;
}
int mechanic::getcounter()
{
	return counter;
}
bool mechanic::isAvailable(int h, int m)
{
	if (mechanicappointments.size() == 0)
		return true;

	else
	{ 
		for (int i = 0; i < mechanicappointments.size(); i++)
		{
			if (mechanicappointments[i].gethour()==h && mechanicappointments[i].getminute()==m)
			return false;
		}
		return true;
	}
	
}
void mechanic::appbook(int h, int m)
{
	Appointment x(h,m);
	mechanicappointments.push_back(x);
}
