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
	int maxGenerationSize = 150;

	// Min size of generations
	int minGenerationSize = 5;

	// Create two arrays, the size of those arrays is defined by "currentGenerationSize", 100 should be wide enough
	int currentGenerationSize = 31;

	// This is used to tell the while loop to stop
	int programEnd = 0;

	// Parent gen is the old generation of cells that defines the new cells
	int parentGen[maxGenerationSize];

	// Child gen is the generation of cells that is currently being processed
	int childGen[maxGenerationSize];

	// Given value for number of generations to be done
	int noOfGen = 10;
	
	// Variables for binary conversion
	int n, binaryNum, decimalNum = 0, i = 1, remainder;

	// Seedpos is the position of the seed (Can be defined by user, defaults to middle of generation)
	int seedPos = maxGenerationSize/2;

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
		printf("4. Binary to decimal\n");
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

				// Place a one (Known as the seed) in the middle of the array (This changes so we need to replace)
				parentGen[seedPos] = 1;

				printf("\n\n-------------------------------------------------------\n");
				printf("\nGenerating With A Width Of %d, %d times!\n", currentGenerationSize, noOfGen);
				printf("\n-------------------------------------------------------\n");

				// Print First Generation has when the first loop starts this will be overwritten
				for (int i = 0; i < currentGenerationSize; ++i){
							printf("%d", parentGen[i]);
				}

				// Loop until t (time) equals a given value
				for(int t = 0; t != noOfGen; t++){

					// For each position in the child array
					for(int index = 0; index != currentGenerationSize+1; index++){

						// Create varibles to store three cells above
						int a;
						int b;
						int c;

						// Get value of cell to the left, might be end so check
						if(index == 0){

							// If end then 0
							c = 0;
						}
						else{
							// Must not be end so treat like normal
							a = parentGen[(index-1)];
						}

						// Get the value of the cell above, this is simple
						b = parentGen[index];

						// Get the value of the cell to the right, might be end so check
						if (index == currentGenerationSize){

							// If end then 0
							c = 0;
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
				printf("\nChange Generation Settings\n");
				printf("\n-------------------------------------------------------\n");

				int userInput;
				int valid;

				valid =0;

				while(valid == 0){

					// Ask user how wide they want the generation to be.
					printf("How wide do you want the generation to be  (For Example - 31):\n");

					// Get the user input
					scanf("%d", &userInput);

					// If user input is invalid then do this
					if (userInput > maxGenerationSize || userInput <minGenerationSize){

						printf("\n-------------------------------------------------------\n\n");
						printf("Invalid Input - Max Width Is 150 cells, Min is 5.\n");
						printf("Try Again!\n");
						printf("\n-------------------------------------------------------\n");

					} else if(userInput <=maxGenerationSize && userInput >= minGenerationSize){

						valid = 1;

						currentGenerationSize = userInput;

					} else{

						printf("\n-------------------------------------------------------\n\n");
						printf("Something went really wrong, Sorry\n");
						printf("\n-------------------------------------------------------\n");

						programEnd =1;
					}
				}

				valid =0;

				while(valid ==0){

					// Ask the user how many lines they wanted generated
					printf("How many lines do you want generated (For Example - 31):\n");

					// Get the user input
					scanf("%d", &userInput);

					// If user input is invalid then do this
					if (userInput > maxGenerationSize || userInput <minGenerationSize){

						printf("\n-------------------------------------------------------\n\n");
						printf("Invalid Input - Max generated Is 150 lines, Min is 5.\n");
						printf("Try Again!\n");
						printf("\n-------------------------------------------------------\n");

					} else if(userInput <=maxGenerationSize && userInput >= minGenerationSize){

						valid = 1;

						noOfGen = userInput;

					} else{

						printf("\n-------------------------------------------------------\n\n");
						printf("Something went really wrong, Sorry\n");
						printf("\n-------------------------------------------------------\n");

						programEnd =1;
					}
				}

				valid =0;

				while(valid ==0){

					// Ask the user if they want to change the position of the seed
					printf("\n-------------------------------------------------------\n");
					printf("\nDo you want to change the position of the seed?\n");
					printf("\n-------------------------------------------------------\n\n");
					printf("1. Yes I want to change the position\n");
					printf("2. No keep it in the middle of the generation\n");

					// Get the user input
					scanf("%d", &userInput);

					switch(userInput){

						// Change seed pos
						case 1:
							
							// Ask user
							printf("\nEnter the position you would like to place the seed at :\n");
							
							// Get the user input
							scanf("%d", &userInput);

							// If user input is invalid then do this
							if (userInput > maxGenerationSize || userInput < 0){

								printf("\n-------------------------------------------------------\n\n");
								printf("Invalid Input - Max seed position is %d as the generation is only %d wide, Min is 0.\n", maxGenerationSize, maxGenerationSize);
								printf("Try Again!\n");
								printf("\n-------------------------------------------------------\n");

							} else if(userInput <= maxGenerationSize && userInput >= 0){

								valid = 1;

								seedPos = userInput;

							} else{

								printf("\n-------------------------------------------------------\n\n");
								printf("Something went really wrong, Sorry\n");
								printf("\n-------------------------------------------------------\n");

								programEnd =1;
							}

						break;

						case 2:
							printf("\n Not Changed Seed Position\n");

							valid = 1;
						break;

						default:
							printf("Invalid Input - Please Enter Valid Number\n");

					}
				}

			break;

			// Case 3 - Currently Empty
			case 3:

			break;

			//Conversion from binary to decimal
			case 4:
				
				// Get user input
				printf("Please enter a binary number : ");
				scanf("%d", &n);

				// Set binary num to n which is user input,
				binaryNum = n;
				
				while (n != 0)
				{
					remainder = n%10;
					n = n/10;
					decimalNum = decimalNum + remainder * i;
					++i;
				}

				printf("The Binary number is = %d \n", binaryNum);
				printf("The decimal Number is =  %d \n",decimalNum);

			break;
			// Exit Case
			case 0:

				printf("Exit\n");
				programEnd = 1;	

			break;

			default:
				printf("Invalid Input - Please Enter Valid Number\n");
		}
	}
}
