# SandwichShop
This sandwich shop program emulates a week of a sandwich shop running, based on an array based stack.

It performs the following tasks:

Tracks the amount of seconds that have passed since opening

Varies the amount of customers that come in based on the time of day

Tracks opening and closing hours across the week to control the flow of customers

Tracks how long each sandwich takes to make depending on the toppings that a customer in the queue may choose

Collects the information on how many of certain ingredients or sandwiches are made. 

Collects the sales information for the shop throughout the week and on each day to be able to return it for ananlysis.

Each sandwich is contained in its own object to be modified as it is passed along the "robots" that add ingredients to the sandwich while the customer waits for it to finish.

Average wait time is recorded, and if a customer waits too long for a given sandwich, they walk away and the sale is lost. 

If a customer waits too long in line, they will also walk away and a sale will be lost.

# SPECIFICATIONS FROM ASSIGNMENT
You have been hired by Smiling Stev's Specialty Sandwich Shoppe to create a computer system for tracking the status of their orders as they implement their new robotic Sandwich Creation System.  The SCS will be built around two types of data structures – a circular node-based queue to track customers entering and leaving the store, and 3 separate instances of static array-based stacks to track the progress on each of the individual creation lines.  The simulation will work as follows:

•	When a new customer enters the store, they will get in the back of the queue.  You will simulate this using random numbers – Between 10 AM and 4 PM 5-9 customers will be added every 5 minutes.   Between 8 AM and 10 AM, and between 4 PM and 5:55 PM 1-5 customers will be added every 5 minutes. The store closes at 6 PM and opens at 8 AM.
•	When a customer enters the queue, the type of sandwich will be randomly determined as well.  Each sandwich will contain 0-4 different meats, 0-4 different vegetables, 0-2 dressings and may or may not be toasted.
•	After a sandwich is determined, it will first pass to the meat addition robot. This robot will be represented by a stack capable of holding 3 under-construction sandwiches and will take 20 seconds to add each type of meat.  
•	After a sandwich is finished by the meat robot it will be sent over to the vegetable robot (which will again have a 3-sandwich stack) which will again take 20 seconds to add each type of vegetable which is selected.
•	After a sandwich has its vegetables added it will move over to the dressing and cooking robot (which again has a 3-item stack).  It takes 10 seconds to add each type of dressing, and then 40 seconds to toast the sandwich (if needed).
•	Sandwiches with 0 of an item CANNOT skip that step.  They will get sent to the meat robot first, then the vegetable robot when the meat robot processes them, then the dressing robot when the vegetable robot is done.
•	Each robot can only work on one item at a time.  
•	When an item is finished by one robot, it passes to the next robot assuming the next robot has a free space in its stack.  If the next robot does not have any free space, the previous robot will just wait until it does.
•	When a sandwich is finished, the contents of the sandwich will be printed to a file named results.txt, as well as the time it was completed.  Upon getting the sandwich, there is a 10% chance each that the customer will give a 5-star or 2-star Yelp review, a 40% chance each 3-star or 4-star review.  If the customer gives a 5-star review, they will be so impressed they will immediately queue up for another sandwich.  
•	If a customer waits in the queue for 10 minutes or more without placing their order, upon reaching the front of the line they will yell at Steve, walk out of the store and leave a 1-star Yelp review.  
•	Upon reaching 6 PM, no new customers will be allowed in, but the robots will need to continue work until all the customers have left.

Additionally, you should collect the following statistics to display at the end of each day once all the customers have left:
1)	How many sandwiches were served
2)	The average wait time for a customer
3)	The day's average Yelp review score
4)	How many customers got angry and walked out
5)	The time the store finally closed

At the end of the week, after printing Friday's statistics, you should also print out the total number of sandwiches sold and the overall Yelp score for the week.  

If your system works well, Stev will want to use it long-term, so it should be easy to edit various parameters such as the time to perform each action, the hours per day, maximum number of ingredients and so on.

	Your objective is to implement (and test) the static stack and dynamic queue ADTs, and then construct a client simulation based on the rules above that tracks the store's progress from 8 AM Monday morning until 6 PM Friday evening.
	

(continued) 
Requirements

	To begin, you will need to create a circular node-based queue class OR a static array-based stack class.  Each of these classes needs to have (at a minimum) the following methods: appropriate constructors and destructors, IsFull and IsEmpty, Clear, and appropriate insert and delete methods, and print and retrieve methods.  You can add other methods as you see fit, but they should be methods relevant to the stack and queue.  Feel free to create any functions you want to help the simulation, but they should be part of the simulation client, not the classes.

	In the event that something is added to the stack class when the stack is full, it should throw a StackFull exception.  In the event that Retrieve, Delete or Print is called on the Queue when it is empty, it should throw a QueueEmpty exception.  Both exceptions should be caught and handled by the client, not handled within the class.
