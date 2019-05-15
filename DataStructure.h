/*
 * DataStructure.h
 *
 *  Created on: May 14, 2019
 *      Author: ADG
 *      Reference "How to Program C++ , Dietel
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_


#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::iostream;
#include <ctime>
using std::time_t;

#include "Customer.h"
//#include "SimplePersonClass.h"

//*********************************************************************

template <typename SimplePerson>
class CustomerList
{
public:
	CustomerList();
	~CustomerList();
	int AddPersonToFrontofLine(const SimplePerson &, double , bool);
	int AddPersonToBackofLine(const SimplePerson &,double , bool);
	bool removeFromFront(SimplePerson &);
	bool removeFromBack(SimplePerson &);
	bool isEmpty() const;
	void print() const;

	int getCustomerInformation( );

private:
	CustomerNode<SimplePerson> *firstPtr;  // pointer to the list node
	CustomerNode<SimplePerson> *lastPtr;

	CustomerNode<SimplePerson> *getNewNode(const SimplePerson &, double ,bool );  // private function , return ListNode<NODETYPE> *ptr
};

//*****************************************************************************/

// default constructor
template<typename SimplePerson>  // template typename nodetype
CustomerList<SimplePerson>::CustomerList():firstPtr(0),lastPtr(0)
{
 // empty body, end list constructor

}

//*****************************************************************************/
// default constructor
template<typename SimplePerson>  // template typename nodetype
CustomerList<SimplePerson>::~CustomerList()
{
 // empty body, end list constructor

}


//*****************************************************************************/

template<typename SimplePerson>  // template typename nodetype
int CustomerList<SimplePerson>::AddPersonToFrontofLine(const SimplePerson &dataNode, double TotalAmount,bool RewardsMember)
{
 // empty body, end list constructor

	CustomerNode<SimplePerson> *newnodePtr = getNewNode(dataNode,TotalAmount,RewardsMember);

	if( isEmpty())
		this->firstPtr = this->lastPtr =newnodePtr;  // new list has only node
	else
	{
		newnodePtr->nextPtr = this->firstPtr;   // new node equals to the value of the previous node, container as a next pointer
		this->firstPtr = newnodePtr;  // first pointer equals to the new node
	}

return 0;
}

//*********************************************************************

template<typename SimplePerson>  // template typename nodetype
int CustomerList<SimplePerson>::AddPersonToBackofLine(const SimplePerson &dataNode, double TotalAmount,bool RewardsMember)
{

	CustomerNode<SimplePerson> *newnodePtr1;

	newnodePtr1 = getNewNode(dataNode,TotalAmount,RewardsMember);  // returns the following parameter;


if(isEmpty())
	this->firstPtr=this->lastPtr=newnodePtr1;
else
{
	this->lastPtr->nextPtr=newnodePtr1;  // update the last pointer to point to the new node next pointer
	this->lastPtr=newnodePtr1;           // new last pointer is the new node pointer, wrap around

}


return 0;
}

//*********************************************************************

template<typename SimplePerson>  // template typename nodetype
bool CustomerList<SimplePerson>::removeFromFront( SimplePerson &dataNode)
{
 // empty body, end list constructor
	if( isEmpty())                       // list is empty
			return false;
	else                                  // list is not empty
	{
	CustomerNode <SimplePerson> *tempPtr;
    tempPtr = this->firstPtr;

	if(this->firstPtr==this->lastPtr) // list has only one node
		this->firstPtr=this->lastPtr=0;
	else                                        // list is has more than one node
		this->firstPtr=this->firstPtr->nextPtr;  // the structure of node contains next pointer

	dataNode=tempPtr->NodeData;  // original first pointer's data, return data being removed. To store.

	delete tempPtr;   // it stored the first pointer location, hence deleted and first pointer points to next ptr

	return true;
	}

}

//*********************************************************************

template<typename SimplePerson>  // template typename nodetype
bool CustomerList<SimplePerson>::removeFromBack( SimplePerson &dataNode)
{
 // empty body, end list constructor

if(isEmpty())
	return false;
else
{
	CustomerNode<SimplePerson> *tempPtr = this->lastPtr;  // temporary pointer equals to the last pointer

	if (this->firstPtr==this->lastPtr) // single node
		this->firstPtr=this->lastPtr=0;
	else            // search for the second to last element, it's not straight forward
	{

		CustomerNode<SimplePerson> *currentPtr = this->firstPtr;  // temporary pointer equals to the last pointer

			while(currentPtr->nextPtr != this->lastPtr)  // where should the next pointer point to
					currentPtr=currentPtr->nextPtr;      // iterating through the list

			this->lastPtr=currentPtr; // moving the last pointer to the second last node since the next pointer is the last node
			currentPtr->nextPtr=0;  // the next pointer points to zero
	}

	dataNode=tempPtr->NodeData; // last pointer's data;
	delete tempPtr;
	return true;
}

}

//*********************************************************************

template<typename SimplePerson>  // template typename nodetype
bool CustomerList<SimplePerson>::isEmpty() const
{
  return this->firstPtr==0;

}

//*********************************************************************

template<typename SimplePerson>  // template typename nodetype
CustomerNode<SimplePerson> *CustomerList<SimplePerson>::getNewNode(const SimplePerson &dataNode,double TotalAmount, bool rewardsMember)
{
CustomerNode<SimplePerson> *newNodePtr= new CustomerNode<SimplePerson> (dataNode, TotalAmount ,rewardsMember);  //constructor for new Node

return newNodePtr;
}

//*********************************************************************

template<typename SimplePerson>  // template typename nodetype
void CustomerList<SimplePerson>::print() const
{
 // empty body, end list constructor
//	cout<<"\n Execute Print List "<<endl;

if (isEmpty())
	cout<<"\n  List is empty "<<endl;

CustomerNode<SimplePerson> *currentPtr = firstPtr;  //constructor for new Node

while (currentPtr !=0)    // in the getNewNode method  a new object to the class ListNode is created and depending on how it is inserted/removed
{
	cout<<" Cost of Groceries For Customer "<<currentPtr->NodeData<<" is $"<<currentPtr->CostGroceries<<endl;

	currentPtr = currentPtr->nextPtr;
}


}


template<typename SimplePerson>  // template typename nodetype
int CustomerList<SimplePerson>::getCustomerInformation()
{
	CustomerNode<SimplePerson> *currentPtr = firstPtr;  //constructor for new Node

	cout<<endl;

	while (currentPtr !=0)    // in the getNewNode method  a new object to the class ListNode is created and depending on how it is inserted/removed
	{

	cout<<" Name of the customer at the register is " <<currentPtr->NodeData<<endl;

	if(currentPtr->rewardsMembers)
	{
	currentPtr->CostGroceries=currentPtr->CostGroceries*0.9;
	cout<<" Person  "<<currentPtr->NodeData<<" is a rewards member hence cost of groceries with 20% discount is $"<<currentPtr->CostGroceries<<endl;
	}
	else
	{
		cout<<" Person  "<<currentPtr->NodeData<<" is a not a rewards member hence no discount and cost of groceries is $"<<currentPtr->CostGroceries<<endl;
	}

	currentPtr = currentPtr->nextPtr;
	cout<<endl;

	}


	return 0;
}



#endif /* DATASTRUCTURE_H_ */
