/*
Name: Curt Patrick
Date: 4/3/18
Class: Programming 2 with C++
Instructor: Dr. Williams
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

using namespace std;
/* Function prototypes */
void programmingChallenge1();
void programmingChallenge2();

int main()
{
	
	int again;
	int choice;
	/*
	Menu driven goodness.
	*/
	do {
		
			cout << "Welcome to Lab 9! Please select the exercise you wish to view." << endl;
			cout << "1. Recursive Array Sum" << endl;
			cout << "2. String Reversal." << endl;
			cout << "3. Exit." << endl;
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
		
			while (choice < 1 || choice > 3) // Input validation
			{
				cout << "Invalid choice! Please try again." << endl;
				cin >> choice;
			}
		
			if (choice != 3) // If you're not shutting it down, choose an exercise.
			{
				switch (choice)
				{
					case 1:
						programmingChallenge1();
						break;
					case 2:
						programmingChallenge2();
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

int sumArray(int[], int);

void programmingChallenge1()
{
	// I used a pointer. I want the user to be able to input however many they wanna add.
	// Plus... I wanted practice with pointers. 
	int *numbersToAdd;
	int size;
	cout << "Welcome to Recursive Array Sum! Here, you can sum up all the elements of an array." << endl;
	cout << "How many numbers do you wish to enter?" << endl;
	cin >> size;
	numbersToAdd = new int[size]; // Dynamically allocated array.
	
	for (int index = 0; index < size; index++) // Fill in the array using a loop.
	{
		cout << "Enter a value." << endl;
		cin >> numbersToAdd[index];	
	}
	
	cout << "The sum is: " << sumArray(numbersToAdd, size) << endl;	
	delete [] numbersToAdd;
	numbersToAdd = 0;
	
	char again;
	
	cout << "Would you like to repeat this exercise? (Y/N)" << endl;
	cin.ignore(10, '\n');
	again = cin.get();
	if (toupper(again) == 'Y')
	{
		system("cls");
		programmingChallenge1();
	}
	else if (toupper(again) == 'N')
	{
		main();
	}
	else
	{
		cout << "Error! Please try again." << endl;
		again = cin.get();
	}
}
/******************************************************
*						sumArray	                  *                
*   Recursively adds all the elements of the array.   *
******************************************************/
int sumArray(int *numbersToAdd, int size)
{
	// Base case: If you only have one element, you already have your sum.
	if (size == 1)
	{
		// Returns the value of the first element in the array..which is the value itself.
		return *numbersToAdd;
	}
	else
	{
		// Recursively call the function.
		// The left operand is moving down by one in the array, starting from the end.
		// The right operand is the function being called, having the value from the left added to it.
		// This approaches the base case.
		return *(numbersToAdd + (size - 1)) + sumArray(numbersToAdd, size - 1);
	}
}

char reversal(char *);

void programmingChallenge2()
{
	const int SIZE = 64; // Establish an array. 64 should be okay.
	char *myString; // Pointer to char
	myString = new char[SIZE]; // Dynamically allocate the array.
	
	cout << "Welcome to Programming Challenge 2: String Reversal!" << endl;
	cout << "Enter a word: ";
	cin >> myString;
	
	cout << "The word reversed is: " << endl; 
	cout << reversal(myString);
	delete [] myString;
	myString = 0;
	
	char again;
	cout << "Would you like to repeat this exercise? (Y/N)" << endl;
	again = cin.get();
	if (toupper(again) == 'Y')
	{
		system("cls");
		programmingChallenge2();
	}
	else if (toupper(again) == 'N')
	{
		main();
	}
	else
	{
		cout << "Error! Please try again." << endl;
		again = cin.get();
	}
}
/***********************************************
/				   reversal                    *
/ This function takes a character array        *
/ input from the user and reverses it by       *
/ taking the last character from the string    *
/ and placing it at the beginning.             *
/***********************************************/
char reversal(char *myString)
{	
	if (*myString != '\0') // As long as it's not the end of the string.
	{
		reversal(myString + 1); // Recursively call the function. Add one each time it's called.
	}
	cout << *myString; // Print the string. Because you recursively incremented the pointer, the contents will print in reverse until it hits the base case.
}
