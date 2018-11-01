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

	// Max size of generations
	int maxGenerationSize = 100;

	// Create two arrays, the size of those arrays is defined by "currentGenerationSize", 100 should be wide enough
	int currentGenerationSize = 31;

	// This is used to tell the while loop to stop
	int programEnd = 0;

	// Parent gen is the old generation of cells that defines the new cells
	int parentGen[currentGenerationSize];

	// Child gen is the generation of cells that is currently being processed
	int childGen[currentGenerationSize];

	// Given value for number of generations to be done
	int givenValue = 10;

	// Make a new line in terminal
	printf("\n");

	while(programEnd == 0){

		// Display the user menu

		printf("\n-------------------------------------------------------\n\n");
		printf("Main Menu - Please chose one of the following options\n");
		printf("\n-------------------------------------------------------\n");
		printf("1. Generate Pattern (Default - Rule 30)\n");
		printf("2. Change The Generation Settings\n");
		printf("3. Change rules\n");
		printf("0. Exit\n");

		// Int choice is the user input
		int choice;

		// Get the user input
		scanf("%d", &choice);

		// Switch For Choosing What To Run
		switch(choice){

			// Run the generation
			case 1:

				// This fills the arrays with zeros
				memset(parentGen, 0, sizeof(parentGen));
				memset(childGen, 0, sizeof(childGen));

				// Test divide by 2
				int test =0; 
				test = currentGenerationSize/2; 
				printf("Test is %d\n",test );

				// Place a one (Known as the seed) in the middle of the array (This changes so we need to replace)
				parentGen[(currentGenerationSize/2)] = 1;

				printf("\n\n-------------------------------------------------------\n");
				printf("\nGenerating With A Width Of %d, %d times!\n", currentGenerationSize, givenValue);
				printf("\n-------------------------------------------------------\n");

				// Print First Generation has when the first loop starts this will be overwritten
				for (int i = 0; i < currentGenerationSize; ++i){
							printf("%d", parentGen[i]);
				}

				// Loop until t (time) equals a given value
				for(int t = 0; t != givenValue; t++){

					// For each posistion in the child array
					for(int index = 0; index != currentGenerationSize+1; index++){

						// Create varibles to store three cells above
						int a;
						int b;
						int c;

						// Get value of cell to the left, might be end so check
						if(index == 0){

							// If end then wrap around
							a = parentGen[currentGenerationSize];
						}
						else{
							// Must not be end so treat like normal
							a = parentGen[(index-1)];
						}

						// Get the value of the cell above, this is simple
						b = parentGen[index];

						// Get the value of the cell to the right, might be end so check
						if (index == currentGenerationSize){

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
					for (int i = 0; i < currentGenerationSize; ++i){
							parentGen[i] = childGen[i];
					}

					// Take a new line in terminal
					printf("\n");

					// Print the parentGen array
					for (int i = 0; i < currentGenerationSize; ++i){
							printf("%d", parentGen[i]);
					}
				}

			break;

			// Case 2- Change generation settings
			case 2:

				printf("\n-------------------------------------------------------\n");
				printf("\nWhat Generation Settings Would You Like To Change?\n");
				printf("\n-------------------------------------------------------\n");
				
				// Ask user how wide they want the generation to be.
				printf("How wide do you want the generation to be?\n");

				// Get the user input
				scanf("%d", &currentGenerationSize);

				// Ask the user how many lines they wanted generated
				printf("How many lines do you want generated?\n");
				scanf("%d", &givenValue);

			break;

			// Case 3 - Currently Empty
			case 3:

			break;

			// Exit Case
			case 0:

				printf("Exit\n");
				programEnd = 1;	

			break;
		}
	}
}
