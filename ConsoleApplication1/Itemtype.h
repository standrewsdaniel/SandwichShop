//FileName : ItemType.h
//Author: Daniel St Andrews
//Date  4/7/21
//Stack Project
//
//Purpose: This file contains the class declarations for the structure of an ItemType and the definition for a keytype.
//
//Assumptions:
//
//
//Exception Handling:
//
#ifndef Item_Type
#define Item_Type

#include <string>
using namespace std;

struct ItemType
{
	int key;                // Key for order number
	bool toasted;			// Yes/No Toasted var
	int meats;				// Num of meats
	int dressings;			// Num of dressings
	int veggies;			// Num of veggies

	int orderTime;			// Time Order is placed
	int serveTime;			// Time order is served

	int vegTime;			// Time to add veggies to order
	int dressTime;			// Time to add dressing and toast
	int finishTime;			// Time the sandwich is finished

	int toFinishTime;		// How long it takes to finish the sandwich


}; 

struct node
{
	node* next;                      //points towards the next node in the queue
	ItemType data;					 //the data in the node
};


#endif
