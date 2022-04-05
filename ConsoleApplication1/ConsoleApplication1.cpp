//FileName : ConsoleApplication1.cpp
//Author: Daniel St Andrews
//Date 4/19/2021
//Project SandWichShop
//
// Note: This project is not in a finished state. It is completed to the
//			best of my ability within my time constraints. It was working 
//			at one point but errors continued after a change 
//			until I couldn't keep working.
//
//Purpose: This file contains the client side code for an array based stack. 
//
//Assumptions:
//
//
//Exception Handling:
//This class can throw the following 3 exceptions:
// On an empty stack the program prints to the screen that nothing can be popped.
// On a full stack the program prints to the screen that nothing can be pushed on.
#pragma once
#include "StackClass.h";
#include "CircularQueueClass.h"
#include <fstream>
using namespace std;

void PrintResults(int time, int weekDay, bool& printed, int served, ItemType currOrd, ofstream& dout);
//Pre: Needs required variables to contain a value
//Post: Prints the results of the day to the output file
//Purpose: Print the summary of the sales of the day to the file specified by dout
void PlaceOrd(int temp, int& tempInt, ItemType& newOrd, int& ordNum, int& time, CircularQueueClass& newQueue);
//Pre: Needs a queue calss instantiated and declared as well as remaining variables.
//Post:	Queues an order and sub associated with it into the queue.
//Purpose:	Place an order for a customer and queue them into the line.
int main()
{
	ofstream dout;				// Output file keyword declaration
	srand(83115);				// Rand Seed
	dout.open("results.txt");	// Output file

	StackClass MeatStack;		// Meat robot stack obj
	StackClass VegStack;		// Veggie robot stack obj
	StackClass DresStack;		// Dressing robot stack obj

	ItemType newOrd;			// New Order declaration
	ItemType temp;				// Temp order of itemtype for cleaner calls later

	CircularQueueClass queue;	// Customer Line

	int time = 0;				// Seconds since the shop opens
	int ordNum = 1;				// Number of orders placed during the day
	int served = 0;				// Customer served during the day
	int wait = 0;				// Time to wait in seconds
	int walkOut = 0;			// Number of customers who walked out
	int yelpStars = 0;			// Total number of stars left by reviewers
	int tempNum = 0;			// Used for customer numbers
	int tempInt = 0;			// Also used for customer numbers
	bool printed = false;		// Whether or not current day was printed

	int weekDay = 1;			// Day of the week starting on monday through saturday accordingly

	// Weekly Sales Represented by while loop for day to day
	while (weekDay < 6)
	{
		// Makes sure the shop is open and accepting orders
		if (time < 36000)
		{
			// Checks for time of day to differ number of customers.
			if ((time < 7200 || time > 28800) && time % 300 == 0)
			{
				tempInt = 5;
				PlaceOrd(tempNum, tempInt, newOrd, ordNum, time, queue);
			}
			else if ((time < 36000 || time >= 7200) && time % 300 == 0)
			{
				tempInt = 1;
				PlaceOrd(tempNum, tempInt, newOrd, ordNum, time, queue);
			}
		}

		// Tests if room in MeatStack
		if (MeatStack.IsFull() == false)
		{
			if (queue.IsEmpty() == false)
			{
				temp = queue.Retrieve(); // Gets the customers order
				temp.orderTime = time;	// Records the time that the customer places the order
				MeatStack.Push(temp);	// Adds order to MeatStack
				queue.DeQueue();		// Removes Customer From line
			}
		}

		// Grabs sandwich off meat stack to be moved to veggies
		temp = MeatStack.Ret();

		// Sandwich can be moved to Veggie robot
		if ((MeatStack.IsEmpty() == false) && temp.vegTime == temp.meats * 20)
		{
			if (VegStack.IsFull() == false)
			{
				// Resets time
				temp.dressTime = 0;
				temp.vegTime = 0;
				temp.toFinishTime = 0;	

				// Moves sandwich to next robot
				VegStack.Push(temp);	

				// Pops current sandwich off the meat robot
				MeatStack.Pop();		
			}
		}

		// Keep waiting
		else if (MeatStack.IsEmpty() == false)
		{
			temp.vegTime++;
		}

		// Stores current item on top of veg stack for easy access
		temp = VegStack.Ret();

		// Sandwich can be moved to dressing robot
		if (VegStack.IsEmpty() == false)
		{
			if (temp.dressTime == temp.veggies * 20)
			{
				if (DresStack.IsFull() == false)
				{
					temp.dressTime = 0;
					temp.vegTime = 0;
					temp.toFinishTime = 0;
					DresStack.Push(temp);
					VegStack.Pop();
				}
			}
		}
		// Keep waiting
		else if (VegStack.IsEmpty() == false)
		{
			temp.dressTime++;
		}

		// Stores current item on top of dress stack for easy access
		temp = DresStack.Ret();

		// Check if DressStack Has room
		if (DresStack.IsEmpty() == false)
		{
			if (temp.toFinishTime == (temp.dressings * 10) + temp.toasted * 40)
			{
				temp.serveTime = 
					(temp.toasted * 40) +
					(temp.dressings * 10) +
					(temp.meats * 20) +
					(temp.veggies * 20);

				served++;
				PrintResults(time, weekDay, printed, served, temp, dout);

				temp.dressTime = 0;
				temp.vegTime = 0;
				temp.toFinishTime = 0;

				wait = wait + (time - temp.orderTime);

				DresStack.Pop();
			}
			// Keep waiting
			else
			{
				temp.toFinishTime++;
			}
		}

		// Increments total time open in seconds
		time++;

		if (queue.IsEmpty() == false)
		{
			while ((time - queue.Retrieve().orderTime) >= 600 && queue.IsEmpty() == false)
			{
				// Customer Leaves
				walkOut++;
				// Single star Review
				yelpStars++; 
				// Calculate Wait time
				wait = wait + (time - queue.Retrieve().orderTime);
				// Remove Customer From Queue
				queue.DeQueue();
			}
		}

		if ((time > 36000) && MeatStack.IsEmpty() && VegStack.IsEmpty() && DresStack.IsEmpty())
		{
			// Calculates average wait time 
			int avgWait = wait / (served + walkOut);
			// Calculates Average Review Score
			int avgReview = yelpStars / (served + walkOut);

			// Converts current time into readable format
			int hours = (28800 + time) / 3600;
			int minutes = ((28800 + time) % 3600) / 60;

			// Ensures standard time
			if (hours > 12)
			{
				hours = hours - 12;
			}

			// Checks for day to print
			switch (weekDay)
			{

			case 1: 
				dout << "Monday:" << "\n";
				break;
			case 2: 
				dout << "\n" << "\n" << "Tuesday:" << "\n";
				break;
			case 3: 
				dout << "\n" << "\n" << "Wednesday:" << "\n";
				break;
			case 4: 
				dout << "\n" << "\n" << "Thursday:" << "\n";
				break;
			case 5: 
				dout << "\n" << "\n" << "Friday:" << "\n";
				break;

			} // End of switch


			// Sends Report to output file for the day
			dout << served << " subs were served, the average wait time was "
				<< avgWait << " seconds, the average review was "
				<< avgReview << " stars, and "
				<< walkOut << " customers walked out. The store closed at "
				<< hours << ":"
				<< minutes << endl;

			// Sends report to the console
				cout << served << " subs were served, and the average wait time was "
					<< avgWait << " seconds, the average review was "
					<< avgReview << " star, and "
					<< walkOut << " walked out. The store closed at "
					<< hours << ":"
					<< minutes << endl;

				// Increment day of the week and reset vars for following day
				weekDay++;
				served = 0;
				time = 0;
				ordNum = 1;
				yelpStars = 0;
				printed = false;
		}
	}
	dout.close();
}; // End of main

void PrintResults(int time, int weekDay, bool& printed, int served, ItemType currOrd, ofstream& dout)
{
	dout.flush();

	// Converts from seconds
	int hours = (time / 3600) + 8;
	int minutes = (time % 3600) / 60;

	// Ensures standard time
	if (hours > 12)
	{
		hours = hours - 12;
	}

	if (!printed)
	{
		switch (weekDay)
		{

		case 1: 
			dout << "Monday:" << "\n";
			break;
		case 2:
			dout << "\n" << "\n" << "Tuesday:" << "\n";
			break;
		case 3: 
			dout << "\n" << "\n" << "Wednesday:" << "\n";
			break;
		case 4: 
			dout << "\n" << "\n" << "Thursday:" << "\n";
			break;
		case 5: 
			dout << "\n" << "\n" << "Friday:" << "\n";
			break;

		} // End of switch
		printed = true;
	}

	// Prints served order to the screen as well as contents
	cout << "Order " << served << ":"
		<< currOrd.meats << " meats,"
		<< currOrd.veggies << " veggies,"
		<< currOrd.dressings << " dressings, and was";
	if (!currOrd.toasted)
	{
		cout << "not toasted.";
	}
	else
	{
		cout << "toasted";
	}
	cout << "The order took a total of "
		<< currOrd.serveTime
		<< " seconds to make, it was served at "
		<< hours << ":";
	if (minutes < 10)
	{
		cout << "0";
	}
	cout << minutes << endl;
	
	// Prints served order to the output file as well as contents
	dout << "Order " << served << ":"
		<< currOrd.meats << " meats,"
		<< currOrd.veggies << " veggies,"
		<< currOrd.dressings << " dressings, and was";
		if (!currOrd.toasted)
		{
			dout << "not toasted.";
		}
		else
		{
			dout << "toasted";
		}
		dout << "This order took a total of "
		<< currOrd.serveTime
		<< " seconds to make, it was served at "
		<< hours << ":"
		<< minutes << endl;
}



void PlaceOrd(int tempNum, int& tempInt, ItemType& newOrd, int& ordNum, int& time, CircularQueueClass& newQueue)
{

	tempNum = (rand() % 5) + tempInt;

	for (int i = 0; i < tempNum; i++)
	{
		newOrd.key = ordNum;
		newOrd.meats = rand() % 5;
		if (newOrd.meats == 0)
		{
			newOrd.meats = 1;
		}
		newOrd.veggies = rand() % 5;
		if (newOrd.veggies == 0)
		{
			newOrd.veggies = 1;
		}
		newOrd.dressings = rand() % 3;
		if (newOrd.dressings == 0)
		{
			newOrd.dressings = 1;
		}
		newOrd.toasted = rand() % 2;
		newOrd.orderTime = time;
		newQueue.EnQueue(newOrd);
	}
}// End of PlaceOrd