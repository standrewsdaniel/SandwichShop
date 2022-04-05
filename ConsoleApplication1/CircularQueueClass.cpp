#include "CircularQueueClass.h"
#include "Exceptions.h"



CircularQueueClass::CircularQueueClass()
{
	back = nullptr;
	size = 0;
}


CircularQueueClass::~CircularQueueClass()
{
	Clear();
}


void CircularQueueClass::EnQueue(ItemType newItem)
{
	if (back == nullptr)                                  //if the list is empty
	{
		back = Allocate();
		back->data = newItem;
		back->next = back;
	}
	else
	{
		node* temp = Allocate();
		temp->data = newItem;
		temp->next = back->next;
		back->next = temp;
		back = temp;
	}
	size++;
}

ItemType CircularQueueClass::DeQueue()
{
	ItemType result;
	if (IsEmpty())
		throw(QueueEmptyException());
	else if (back->next == back)                                          // if there is only one item in the queue
	{
		result = back->data;
		delete back;
		back = nullptr;
	}
	else
	{
		node* temp = back->next;
		result = temp->data;
		back->next = temp->next;
		delete temp;
	}
	size--;
	return (result);
}

void CircularQueueClass::Clear()
{
	while (back != nullptr)          //while the list is not empty, call DeQueue
	{
		DeQueue();
	}
}

bool CircularQueueClass::IsEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CircularQueueClass::IsFull()
{
	return false;
}

ItemType CircularQueueClass::Retrieve()                  //may need to change this datatype based on ItemType
{
	if (IsEmpty())
		throw(QueueEmptyException());
	else
		return(back->next->data);
}

void CircularQueueClass::Print()
{
	if (IsEmpty())
		throw(QueueEmptyException());
	else
	{
		node* temp = back->next;
		while (temp != back)                         //while temp isn't back, print the queue
		{
			cout << temp->data.key << endl;
			temp = temp->next;
		}
	}
}

int CircularQueueClass::GetSize()
{
	return size;
}

node* CircularQueueClass::Allocate()
{
	node* temp = new node;
	temp->next = nullptr;
	return temp;
}