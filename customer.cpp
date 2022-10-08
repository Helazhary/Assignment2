#include "customer.h"
#include "person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//--------------------cosntructor---------------------------
customer::customer()
{
	mechanicID = 0;
	appointment.sethour(0);
	appointment.setminute(0);
}

//------------------------setters-----------------------------
void customer::setmechanicID(int i)
{
	mechanicID = i;
}
void customer::setappointment(int h , int m )
{
	appointment.sethour(h);
	appointment.setminute(m);
}
void customer::setmechanicname(string n)
{
	mechanicname = n;
}
//------------------------getters-----------------------------
int customer::getmechanicID()
{
	return mechanicID;
}
int customer::getappointment_h()
{
	return appointment.gethour();
}
int customer::getappointment_m()
{
	return appointment.getminute();
}
string customer::getmechanicname()
{
	return mechanicname;
}

bool customer::operator > (customer& c)
{
	if (this->getappointment_h() > c.getappointment_h())
		return true;
	else if (this->getappointment_h() == c.getappointment_h()&& this->getappointment_m() > c.getappointment_m())
		return true;
	return false;
}

bool customer::operator < (customer& c)
{
	if (this->getappointment_h() < c.getappointment_h())
		return true;
	else if (this->getappointment_h() == c.getappointment_h() && this->getappointment_m() < c.getappointment_m())
		return true;
	return false;
}

bool customer::operator == (customer& c)
{
	if (this->getappointment_h() == c.getappointment_h() && this->getappointment_m() == c.getappointment_m())
			return true;
	return false;
}