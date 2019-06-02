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

Output of the project:

 Super Market Customer Line Consists of 
 
 Cost of Groceries For Customer Person Urgent is $85
 Cost of Groceries For Customer Alpa is $120
 Cost of Groceries For Customer Joe is $150
 Cost of Groceries For Customer Heather is $80
 Cost of Groceries For Customer Kim is $60
 Cost of Groceries For Customer Alan is $90


 Name of the customer at the register is Person Urgent
 
 Person  Person Urgent is a rewards member hence cost of groceries with 20% discount is $76.5


 Name of the customer at the register is Alpa
 
 Person  Alpa is a rewards member hence cost of groceries with 20% discount is $108


 Name of the customer at the register is Joe
 
 Person  Joe is a rewards member hence cost of groceries with 20% discount is $135

 Name of the customer at the register is Heather
 
 Person  Heather is a not a rewards member hence no discount and cost of groceries is $80


 Name of the customer at the register is Kim
 
 Person  Kim is a rewards member hence cost of groceries with 20% discount is $54


 Name of the customer at the register is Alan
 
 Person  Alan is a not a rewards member hence no discount and cost of groceries is $90
