/*
				SUMMARY OF METHODS

public methods:

	CircularQueueClass() - default constructor, initializes class with default values
	~CirculatQueueClass() - destructor, clears the queue
	CircularQueueClass(const CircularQueueClass& otherQueue) - copy constructor, creates a copy of otherQueue
	void EnQueue(ItemType newItem) - adds items to the back of the queue
	ItemType DeQueue() - removes and returns items from the front of the queue
	void Clear() - removes all items from the queue
	bool IsFull() - returns true if the queue is full, false otherwise
	bool IsEmpty() - returns true if the queue is empty, false otherwise
	ItemType Retrieve() - returns the item at the front of the queue
	void Print() - prints the key of all of the items in the queue
	int GetSize() - returns the size of the queue

private methods:

	node* Allocate() - allocates a new node

*/
#pragma once
#include "Itemtype.h"
#include <iostream>

//constant declaration

class CircularQueueClass
{
public:

	CircularQueueClass();	//O(1)
	//Pre: Queue has been instantiated
	//Post: Queue has been initialized
	//Purpose: Default constructor, initializes a queue with default values

	~CircularQueueClass();	//O(N)
	//Pre: Queue exists
	//Post: Queue has been cleared
	//Purpose: Destructor, clears the list

//	CircularQueueClass(const CircularQueueClass& otherQueue);	//O(N)
	//Pre: otherQueue exists
	//Post: Queue is a copy of otherQueue
	//Purpose: Copy constructor, creates a copy of otherQueue

	void EnQueue(ItemType newItem);	//O(1)
	//Pre: Queue has been initialized
	//Post: newItem has been added to the back of the queue
	//Purpose: to add items to the queue

	ItemType DeQueue();	//O(N)
	//Pre: Queue has been initialized, there is at least one item in the queue
	//Post: the item at the front of the queue has been removed
	//Purpose: to remove items from the queue

	void Clear();	//O(N)
	//Pre: queue has been instantiated and filled
	//Post: queue has been emptied of all items
	//Purpose: to remove all items from the list

	bool IsFull();	//O(1)
	//Pre: Queue exists
	//Post: true has been returned if the queue is full, false otherwise
	//Purpose: to determine if the queue is full or not

	bool IsEmpty();	//O(1)
	//Pre: Queue exists
	//Post: true has been returned if the queue is empty, false otherwise
	//Purpose: to determine if the queue is empty or not

	ItemType Retrieve();	//O(1)
	//Pre: Queue exists, there is at least one item in the queue
	//Post: the data in the front of the queue has been returned
	//Purpose: to return the data at the front of the queue

	void Print();	//O(N)
	//Pre: Queue exists, there is at least one item in the queue
	//Post: all of the data in the queue has been printed
	//Purpose: to print all of the data in the queue

	int GetSize();	//O(1)
	//Pre: Queue has been initialized
	//Post: size has been returned
	//Purpose: to check the size of the queue


private:
	node* back;                      //this points to the newest item in the list, the "back" of the queue
	int size;                        //the number of items in the queue

	node* Allocate();
	//Pre: Queue has been initialized
	//Post: a new node has been allocated for use
	//Purpose: to allocate a new node

};

