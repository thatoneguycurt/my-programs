/*
Name: Curt Patrick
Instructor: Dr. Williams
Date: 2/5/2018
Class: 11:00 Tuesday/Thursday Programming 2.
*/


/*
Wow, I ended up actually using most of these.. Can't wait to learn more!
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

using namespace std;
/* Function prototypes */
void programmingChallenge1();
int countPerfect(int [], int);
void programmingChallenge2();
void compareNumbers(int [], int, int);
void programmingChallenge3();

int main()
{
	
	int again;
	int choice;
	/*
	Menu driven goodness.
	*/
	do {
		
			cout << "Welcome to Lab 3! Please select the exercise you wish to view!" << endl;
			cout << "1. Perfect Scores" << endl;
			cout << "2. Larger Than N." << endl;
			cout << "3. Roman Numeral Converter." << endl;
			cout << "4. Exit." << endl;
			cin >> choice;
			
			while(1) // While error condition (e.g. entering a char in place of an integer)
			{
				if (cin.fail()) // If wrong data type..
				{
					cin.clear(); // get rid of it
					cin.ignore(10, '\n');
					cout << "Error! Invalid input. Try again.\a" << endl;
					cin >> choice;
				}
				else
				{
					break;
				}
			}
			
			while (choice < 1 || choice > 4) // Input validation
			{
				cout << "Invalid choice! Please try again." << endl;
				cin >> choice;
			}	
		
			if (choice != 4) // If you're not shutting it down, choose an exercise.
			{
				switch (choice)
				{
					case 1:
						programmingChallenge1();
						break;
					case 2:
						programmingChallenge2();
						break;
					case 3:
						programmingChallenge3();
						break;
				}
		}
		else 
		{	system("cls"); // Clear the screen for organization.
			cout << "Thank you for viewing. Bye bye!" << endl;
			exit(0); // Vital to shutdown.
		}
				
		
	} while (toupper(again) == 'Y');

}

void programmingChallenge1()
{
	char again;
	const int NUM_SCORES = 20; // Create a constant to be used to size the array.
	int examScores[NUM_SCORES];
	int score; 
	cout << "Welcome to Perfect Scores: The Perfect Score calculator" << endl;
	for (score = 0; score < NUM_SCORES; score++) // Fill the array with user generated values.
	{
		cout << "Please enter score #" << (score+1) << ": " << endl;
		cin >> examScores[score];
		if (examScores[score] < 0 || examScores[score] > 100) // Input validation.
		{
			cout << "ERROR: Must be in range from 0 to 100: " << endl;
			cin >> examScores[score];
		}
	}
	cout << "The number of perfect scores in this session is: " << countPerfect(examScores, NUM_SCORES) << endl; // Pass these to the function and return the value
	
	cout << "Would you like to repeat this exercise? (Y/N)" << endl; // Do it again?
	cin >> again;
	if (toupper(again) == 'Y')
	{
		programmingChallenge1(); // Repeat this exercise.
	}
	else if (toupper(again) == 'N')
	{
		main(); // Back to the main menu.
	}
	else
	{
		cout << "Invalid input: Please try again." << endl;
		cin >> again;
	}
}

/*********************************************************
*					countPerfect                         *
*	The objective of this function is to see how many    * 
*	times the value in the index equals 100. For each    *
*	that does, the perfectScore variable is incremented  *
*	by one.                                              *
**********************************************************/

int countPerfect(int examScores[], int NUM_SCORES) // The array is passed to this function.
{
	int perfectScore = 0; // Set this to zero.
	
	for (int i = 0; i < NUM_SCORES; i++)
		if (examScores[i] == 100) // If the value of the index equals 100..
		{
			perfectScore++; // Add one to this variable.
		}
	
	return perfectScore; // Return this value to the function that called it.
}

void programmingChallenge2()
{

	unsigned seed; // Decided to randomly generate the numbers for the array. This makes sure it doesn't capture a negative value.
	const int SIZE = 10; // Define the size of the array
	int numArray[SIZE];
	
	// This is used to generate random numbers based on something always changing: time.
	seed = time(0); 
	srand(seed); // srand is a function of seed, which is tied to the value contained in the time function.
	
	
	for (int subscript = 0; subscript < SIZE; subscript++) // This helps fill the loop with randomly generated numbers.
	{
		numArray[subscript] = (rand() % 100) + 1; // Offset by 1, so as to establish a range between 1 and 100.
	}
	
	int myNumber;
	cout << "Welcome to Challenge 2: Larger than N!" << endl;
	cout << "Please enter a number between 1 and 100." << endl;
	cin >> myNumber;
	compareNumbers(numArray, SIZE, myNumber);
}
/*********************************************************
*														 *
*				compareNumbers                           *
*                                                        *
*  The purpose of this function is to compare the        *
*  number of the user's choosing to the values randomly  *
*  generated by the computer to see which is larger.     *
*                                                        *
**********************************************************/
void compareNumbers(int numArray[], int SIZE, int myNumber)
{
	int i;
	char again;
	int largerThanCount = 0;
	for (i = 0; i < SIZE; i++)
	{
		if (numArray[i] > myNumber) // If the value of the index is greater than the number.
		{
			cout << numArray[i] << " is larger than " << myNumber << endl; // Display the number (chosen at random) that is larger than the user's number.
			largerThanCount++; // Add one to the larger-than count.
		}
	}
	
	cout << "There are " << largerThanCount << " numbers larger than your number in this array." << endl;
	cout << "Would you like to do this again? (Y/N)" << endl; // Repeat?
	cin >> again;
	if (toupper(again) == 'Y')
	{
		programmingChallenge2();
	}
	else if (toupper(again) == 'N')
	{
		main();
	}
	else
	{
		cout << "Invalid input. Please try again." << endl;
		cin >> again;
	}
}

void programmingChallenge3()
{
	int index; // Declared so that it can be the ACTUAL index as opposed to what the user enters.
	int number; // The number the user wants to convert into a Roman numeral.
	/*
	This is a string of 20 Roman numerals.
	*/
	string romanNumerals[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX"};
	cout << "Welcome to Challenge 3: Roman Numerals!" << endl;
	do // Do this, while the input > 0
	{
		cout << "Please enter a number for which you want to see the Roman equivalent." << endl;
		cin >> number;
		if (number < 0) // Input validation
		{
			cout << "Error. No negative values allowed." << endl;
			cin >> number;
		}
		else if (number > 20) // Out of range.
		{
			cout << "Too high. Try again." << endl;
			cin >> number;
		}
		index = number - 1; // Convert this into an index the array can use. Remember, arrays start at 0.
		if (number != 0) // More input handling.
		{
			cout << "The number you entered is " << number << " which has a Roman Numeral equivalent of " << romanNumerals[index] << endl;
		}
		else
		{
			cout << "Thanks for playing! Goodbye!" << endl;
			main();
		}
	} while (number > 0); // Admittedly, it's a redundant way of handling the inputs, but this keeps the loop going. The other validations solidify it.
	
}
