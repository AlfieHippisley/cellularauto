//
// FIle Name :          	cell.c
// Author : 	        	Alfie Hippisley
// Date Created :       	30/10/2018
// Date Last Modified : 	30/10/2018
//
// Purpose : Code to form the celluar automaton for assignment 2
//
// References : This code made use of the reference material on myDundee, no other sources were used

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){


	//menu
	printf("--Menu--\n");
	printf("Please chose one of the following options\n");
	printf("1. Run with preset settings\n");
	printf("2. Change set size and its values\n");
	printf("3. Change rules\n");
	printf("0. Exit\n");

	int choice;
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
		printf("1 option selected\n");
		// For this to work we will need to use predefined rules (This is not working yet)
	int ruleThirty[8] = {0,0,0,1,1,1,1,0};

	// Create two arrays, the size of those arrays is defined by "arraySize"
	int arraySize = 31;

	// Parent gen is the old generation of cells that defines the new cells
	int parentGen[arraySize];

	// Child gen is the generation of cells that is currently being processed
	int childGen[arraySize];

	// This fills the arrays with zeros
	memset(parentGen, 0, sizeof(parentGen));
	memset(childGen, 0, sizeof(childGen));

	// Place a one (Known as a seed) in the middle of the array
	parentGen[(arraySize/2)] = 1;

	// Make a new line in terminal
	printf("\n");

	// Print First Generation has when the first loop starts this will be overwritten
	for (int i = 0; i < arraySize; ++i){
				printf("%d", parentGen[i]);
	}

	// Given value for number of generations
	int givenValue = 10;

	// Loop until t (time) equals a given value
	for(int t = 0; t != givenValue; t++){

		// For each posistion in the child array
		for(int index = 0; index != arraySize+1; index++){

			// Create varibles to store three cells above
			int a;
			int b;
			int c;

			// Get value of cell to the left, might be end so check
			if(index == 0){

				// If end then wrap around
				a = parentGen[arraySize];
			}
			else{
				// Must not be end so treat like normal
				a = parentGen[(index-1)];
			}

			// Get the value of the cell above, this is simple
			b = parentGen[index];

			// Get the value of the cell to the right, might be end so check
			if (index == arraySize){

				// If end then wrap around
				c = parentGen[0];
			}
			else{

				// Must not be end so treat like normal
				c = parentGen[(index +1)];
			}

			// Place rule here (In this case its rule 30 hard coded)
			// The line below is for debugging
			//printf("(A is currently - %d, B is currently - %d, C is currently - %d)\n",a,b,c);

			if (a == 1 && b == 1 && c == 1)
			{
				childGen[index] = 0;
			}

			else if(a == 1 && b == 1 && c == 0)
			{
				childGen[index] = 0;
			}

			else if(a == 1 && b == 0 && c == 1)
			{
				childGen[index] = 0;
			}

			else if(a == 1 && b == 0 && c == 0)
			{
				childGen[index] = 1;
			}

			else if(a == 0 && b == 1 && c == 1)
			{
				childGen[index] = 1;
			}

			else if(a == 0 && b == 1 && c == 0)
			{
				childGen[index] = 1;
			}

			else if(a == 0 && b == 0 && c == 1)
			{
				childGen[index] = 1;
			}

			else if(a == 0 && b == 0 && c == 0)
			{
				childGen[index] = 0;
			}
		}

		// Fill the parent array with the new generation
		for (int i = 0; i < arraySize; ++i){
				parentGen[i] = childGen[i];
		}

		// Take a new line in terminal
		printf("\n");

		// Print the parentGen array
		for (int i = 0; i < arraySize; ++i){
				printf("%d", parentGen[i]);
		}
	}

	printf("\n\n");

		break;
		case 2:
		printf("2 option selected\n");
		break;
		case 3:
		printf("3 option selected\n");
		break;
		case 0:
		printf("Exist\n");
		void exit (int status);	
		break;
	}


	
}
