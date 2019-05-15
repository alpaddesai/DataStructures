/*
 * Customer.h
 *
 *  Created on: May 14, 2019
 *      Author: ADG
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_


//#include "SimplePersonClass.h"

template <typename SimplePerson> class CustomerList;  // forward reference  , make list a friend

#include <iostream>
#include <string>

using std::cout;
using std::endl;

//SimplePerson, duplicating the customer node, all information should be in customer node

template<typename SimplePerson>          // node type can be an int, float, double, string
class CustomerNode
{
friend class CustomerList<SimplePerson>;   // make List a friend

public:
	CustomerNode(const SimplePerson &, double &,bool);   // constructor ,  ListNode, const NODETYPE &
	SimplePerson getData() const;         // NODETYPE getData() return data in mode const
private:

	CustomerNode<SimplePerson> *nextPtr; // LISTNODE NODETYPE next node in list , nextPtr
	SimplePerson NodeData;   // another constructor within
	double CostGroceries;
	bool rewardsMembers;

};  // end class ListNode

//*************************************************************/

template<typename SimplePerson>    // class ListNode is a container (e.gvector)
CustomerNode <SimplePerson>::CustomerNode(const SimplePerson &info, double &Groceries, bool member)
{
this->NodeData=info;
this->nextPtr=0;
this->CostGroceries=Groceries;
this->rewardsMembers=member;


}

//*************************************************************/
template<typename SimplePerson>
SimplePerson CustomerNode <SimplePerson>::getData() const
{

return this->NodeData;
}

//*************************************************************/


#endif /* CUSTOMER_H_ */
