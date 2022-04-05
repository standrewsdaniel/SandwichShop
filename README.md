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
