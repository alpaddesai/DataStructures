/*
 * TestCaseMain.cpp
 *
 *  Created on: May 14, 2019
 *      Author: ADG
 */


#include "Customer.h"
#include "DataStructure.h"
//#include "SimplePersonClass.h"


int main()
{

	CustomerList <string> customers;

	customers.AddPersonToBackofLine("Alpa",120,1);
	customers.AddPersonToBackofLine("Joe",150,1);
	customers.AddPersonToBackofLine("Heather",80,0);
	customers.AddPersonToBackofLine("Kim",60,1);
	customers.AddPersonToFrontofLine("Person Urgent",85,1);
	customers.AddPersonToBackofLine("Alan",90,0);

cout<<" Super Market Customer Line Consists of "<<endl;

customers.print();

 customers.getCustomerInformation();



return 0;

}


