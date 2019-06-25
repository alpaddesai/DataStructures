# SuperMarketLine
SuperMarketLineRewardsMember

## Synopsis of the Project

The project consists of a custom linkedlist coded in C++, for a super market line. Please reference the .cpp file for details.

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
	
customers.removeFromFront("Person Urgent");
customers.removeFromFront("Alpa");
customers.removeFromFront("Joe");
customers.removeFromFront("Heather");
customers.removeFromFront("Kim");
customers.removeFromFront("Alan");

customers.print();

return 0;

}

