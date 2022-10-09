#include "customer.h"
#include "person.h"
#include "mechanic.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <list>
#include "queue.h"
using namespace std;

int main()
{
	queue<customer> customerz;

	//-----------------------mechanic info-----------------------
	mechanic Ahmed;
	ahmed.setname("Ahmed");
	ahmed.setage(18);
	ahmed.setid(101);

	mechanic Khaled;
	khaled.setname("Khaled");
	khaled.setage(38);
	khaled.setid(102);

	mechanic mai;
	mai.setname("Mai");
	mai.setage(27);
	mai.setid(103);

	vector <mechanic> todaysmechanics;
	todaysmechanics.push_back(Ahmed);
	todaysmechanics.push_back(Khaled);
	todaysmechanics.push_back(Mai);

	//---------------------------customer info-----------------------
	ifstream customerlist("customers.txt");

	string line;
	string cname;
	int cid;
	int cage;
	int cnum;
	int chour, cminute;

	//cout << "Please enter the number of customers joining us today: ";
	//cin>>cnum;

	customerlist >> cnum;
	vector <customer> todayscustomers(cnum);

	for (int i = 0; i < cnum; i++)
	{
		//cout << "\nenter the name of customer " << i+1 << ": ";
		//cin >> cname;

		customerlist >> cname;
		todayscustomers[i].setname(cname);


		//cout << "enter the age of customer " << i + 1 << ": ";
		//cin>>cage;

		customerlist >> cage;
		todayscustomers[i].setage(cage);

		//cout << "enter the id of customer " << i + 1 << ": ";
		//cin>>cid;

		customerlist >> cid;
		todayscustomers[i].setid(cid);

		//cout << "enter the desired hour of customer " << i + 1 << "'s appointment: ";
		//cin >> chour;

		customerlist >> chour;

		//cout << "enter the desired minute of customer " << i + 1 << "'s appointment: ";
		//cin>>cminute;

		customerlist >> cminute;
		todayscustomers[i].setappointment(chour, cminute);


	} customerlist.close();

	//------------------------assigning customers to mechanics-------------------------------
	int nextmech = 0;
	for (int c = 0; c < cnum; c++)
	{ 
		
		for (int m = nextmech; m < todaysmechanics.size() && todayscustomers[c].hasAppointment==false; m++)
		{

			if (todaysmechanics[m].isAvailable(todayscustomers[c].getappointment_h(), todayscustomers[c].getappointment_m()))	
			{
				todaysmechanics[m].appbook(todayscustomers[c].getappointment_h(), todayscustomers[c].getappointment_m());
				todaysmechanics[m].setcounter(todaysmechanics[m].getcounter() + 1);
				todayscustomers[c].setmechanicID(todaysmechanics[m].getid());
				todayscustomers[c].setmechanicname(todaysmechanics[m].getname());
				todayscustomers[c].hasAppointment = true;
			}

		}
	
		if (nextmech == 2)
			nextmech = 0;
		else
			nextmech++;


	}

	//----------------------------output unordered appointment requests--------------------
	cout << "Appointmnet requests with availible mechanics: " << endl << endl;
	for (int i = 0; i < todayscustomers.size(); i++)
	{
		cout << todayscustomers[i].getname() << " requesting appointment at " << todayscustomers[i].getappointment_h() << ":"
			<< setw(2) << setfill('0') << todayscustomers[i].getappointment_m() << " with " << todayscustomers[i].getmechanicname() << endl;
	}

	cout << endl;

	for (int c = 0; c < cnum; c++)  //output of unavailable appointments
	{
		if (todayscustomers[c].hasAppointment==0)
			cout<<"\ncould not allocate an appointment for " << todayscustomers[c].getname() << " at time: " << todayscustomers[c].getappointment_h() << ":"
			<< setw(2) << setfill('0') << todayscustomers[c].getappointment_m() << endl;
	}
	cout << endl;

	
	//---------------------------ordering appointments---------------------
	customer temp;


	for (int i=0; i< todayscustomers.size() -1; i++)
		{
		for (int j = 0; j < todayscustomers.size() - i-1; j++)
			{
				if (todayscustomers[j] > todayscustomers[j+1]) 
				{
					temp = todayscustomers[j];
					todayscustomers[j] = todayscustomers[j+1];
					todayscustomers[j+1] = temp;

				}
			}
		}

	//--------------------output ordered appoinments (USING TEMPLATE QUEUE SYSTEM)---------------------------
	for (int i = 0; i < todayscustomers.size(); i++)
		customerz.push(todayscustomers[i]);

	cout << "Ordered queue of appointments:  " << endl << endl;

	for (int i = 0; i < todayscustomers.size(); i++)
	{
		if (todayscustomers[i].hasAppointment == 1)
		{
		
			cout << customerz.returnfront().getname() << " has an appointment at " << customerz.returnfront().getappointment_h() << ":"
			<< setw(2) << setfill('0') << customerz.returnfront().getappointment_m() << " with " << customerz.returnfront().getmechanicname() << endl;
		}
		customerz.pop();
		
	}

}
