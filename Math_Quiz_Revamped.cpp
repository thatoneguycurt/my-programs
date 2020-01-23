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

void AdditionQuiz();
void SubtractionQuiz();
void MultiplicationQuiz();
void DivisionQuiz(); 

class MathGame
{
	public:
		static int attempts;
		static int timesCorrect;
		unsigned seed;
		MathGame()
		{
			attempts++; // Each time a game object is created, add 1 to attempts
		}
		char playAgain, quitGame;
		int num1, num2, userAnswer, correctAnswer, choice;
};

int MathGame::timesCorrect = 0;
int MathGame::attempts = 0;

int main() 
{

	int choice;

	cout << "----------------------------------------------" << endl;
	cout << "Welcome to the interactive Math Quiz!" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Press any key to continue." << endl;
	getchar();
	
	
	cout << "What do you want to quiz on? " << endl;
	cout << "1. Addition " << endl;
	cout << "2. Subtraction " << endl;
	cout << "3. Multiplication " << endl;
	cout << "4. Division " << endl;
	cout << "5. Quit game " << endl;
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
			
	while (choice < 1 || choice > 5) // Input validation
	{
		cout << "Invalid choice! Please try again." << endl;
		cin >> choice;
	}
			
	if (choice != 5) // If you're not quitting the game, select an option.
	{
		switch (choice)
		{
			case 1:
				AdditionQuiz();
				break;
			case 2:
				SubtractionQuiz();
				break;
			case 3:
				MultiplicationQuiz();
				break;
			case 4:
				DivisionQuiz();
				break;			
		}
	}
	else
	{
		system("cls"); // Clear the screen for organization.
		cout << "Thank you for playing. Bye bye!" << endl;
		exit(0); // Vital to shutdown.
	}
	
	return 0;
		
}

void AdditionQuiz()
{
	
	MathGame currentSession;
	
	currentSession.playAgain = 'Y';
			
	while (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y')
	{
		currentSession.seed = time(0); // Seed based on the time. Time always changes!
		srand(currentSession.seed); // random function.
		//Pre-emptive calculations
		currentSession.num1 = rand() % 99 + 1; // Randomly generate numbers 1-99 by using the modulo for any seed and then add 1 so as to keep it in the range 1-999
		currentSession.num2 = rand() % 99 + 1;
		currentSession.correctAnswer = currentSession.num1 + currentSession.num2;
	
		//Set up the math statement
		cout << "Add the following: " << endl;
		cout << "  " << currentSession.num1 << endl;
		cout << "+ " << currentSession.num2 << endl; 
		cout << "----" << endl << endl;
	
		cout << "What is the answer?: " << endl;
		cin >> currentSession.userAnswer;
	
		//Compare answers
		cout << "You answered: " << currentSession.userAnswer << endl << endl;
		if (currentSession.userAnswer == currentSession.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl << endl;
			currentSession.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << currentSession.correctAnswer << endl << endl;
		}
		cout << "You got " << currentSession.timesCorrect << " out of " << currentSession.attempts << " correct." << endl << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> currentSession.playAgain;
		
		if (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y') 
		{
			AdditionQuiz();
		}
		else if (currentSession.playAgain == 'N' || currentSession.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> currentSession.quitGame;
			if (currentSession.quitGame == 'y' || currentSession.quitGame == 'Y')
			{
				system("cls"); // Clear the screen for organization. 
				cout << "Thanks for playing! Goodbye!" << endl;
				exit(0);
			}
			else if (currentSession.quitGame == 'n' || currentSession.quitGame == 'N')
			{
				currentSession.timesCorrect = currentSession.attempts = 0;
				system("cls");
				main();
			}
			else
			{
				cout << "Error: invalid input. Please try again." << endl;
				cin >> currentSession.quitGame;
			}
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> currentSession.playAgain;
		}
	}
}

void SubtractionQuiz()
{
	MathGame currentSession;
	
	currentSession.playAgain = 'Y';

	while (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y') 
	{
		currentSession.seed = time(0); // Seed based on the time. Time always changes!
		srand(currentSession.seed); // random function.
		//Pre-emptive calculations
		currentSession.num1 = rand() % 99 + 1; // Randomly generate numbers 1-99 by using the modulo for any seed and then add 1 so as to keep it in the range 1-9, not 0-8
		currentSession.num2 = rand() % 99 + 1;
	
		if (currentSession.num2 > currentSession.num1)
		{
			currentSession.correctAnswer = currentSession.num2 - currentSession.num1;
			//Set up the math statement
			cout << "Subtract the following: " << endl;
			cout << "  " << currentSession.num2 << endl;
			cout << "- " << currentSession.num1 << endl; 
			cout << "----" << endl << endl;
		}
		else
		{
			currentSession.correctAnswer = currentSession.num1 - currentSession.num2;
			//Set up the math statement
			cout << "Subtract the following: " << endl;
			cout << "  " << currentSession.num1 << endl;
			cout << "- " << currentSession.num2 << endl; 
			cout << "----" << endl << endl;
		}
		
	
		cout << "What is the answer?: " << endl;
		cin >> currentSession.userAnswer;
	
		//Compare answers
		cout << "You answered: " << currentSession.userAnswer << endl << endl;
		if (currentSession.userAnswer == currentSession.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl << endl;
			currentSession.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << currentSession.correctAnswer << endl << endl;
		}
		cout << "You got " << currentSession.timesCorrect << " out of " << currentSession.attempts << " correct." << endl << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> currentSession.playAgain;
		
		if (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y') 
		{
			SubtractionQuiz();
		}
		else if (currentSession.playAgain == 'N' || currentSession.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> currentSession.quitGame;
			if (currentSession.quitGame == 'y' || currentSession.quitGame == 'Y')
			{
				system("cls"); // Clear the screen for organization. 
				cout << "Thanks for playing! Goodbye!" << endl;
				exit(0);
			}
			else if (currentSession.quitGame == 'n' || currentSession.quitGame == 'N')
			{
				currentSession.timesCorrect = currentSession.attempts = 0;
				system("cls");
				main();
			}
			else
			{
				cout << "Error: invalid input. Please try again." << endl;
				cin >> currentSession.quitGame;
			}
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> currentSession.playAgain;
		}
	}
}

void MultiplicationQuiz()
{
	MathGame currentSession;
	
	currentSession.playAgain = 'Y';
			
	while (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y')
	{
		currentSession.seed = time(0); // Seed based on the time. Time always changes!
		srand(currentSession.seed); // random function.
		//Pre-emptive calculations
		currentSession.num1 = rand() % 11 + 1; // Randomly generate numbers 1-12 by using the modulo for any seed and then add 1 so as to keep it in the range 1-999
		currentSession.num2 = rand() % 11 + 1;
		currentSession.correctAnswer = currentSession.num1 * currentSession.num2;
	
		//Set up the math statement
		cout << "Multiply the following: " << endl;
		cout << "  " << currentSession.num1 << endl;
		cout << "x " << currentSession.num2 << endl; 
		cout << "----" << endl << endl;
	
		cout << "What is the answer?: " << endl;
		cin >> currentSession.userAnswer;
	
		//Compare answers
		cout << "You answered: " << currentSession.userAnswer << endl << endl;
		if (currentSession.userAnswer == currentSession.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl << endl;
			currentSession.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << currentSession.correctAnswer << endl << endl;
		}
		cout << "You got " << currentSession.timesCorrect << " out of " << currentSession.attempts << " correct." << endl << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> currentSession.playAgain;
		
		if (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y') 
		{
			MultiplicationQuiz();
		}
		else if (currentSession.playAgain == 'N' || currentSession.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> currentSession.quitGame;
			if (currentSession.quitGame == 'y' || currentSession.quitGame == 'Y')
			{
				system("cls"); // Clear the screen for organization. 
				cout << "Thanks for playing! Goodbye!" << endl;
				exit(0);
			}
			else if (currentSession.quitGame == 'n' || currentSession.quitGame == 'N')
			{
				currentSession.timesCorrect = currentSession.attempts = 0;
				system("cls");
				main();
			}
			else
			{
				cout << "Error: invalid input. Please try again." << endl;
				cin >> currentSession.quitGame;
			}
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> currentSession.playAgain;
		}
	}
}

void DivisionQuiz()
{
	MathGame currentSession;
	int product;
	currentSession.playAgain = 'Y';

	while (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y') 
	{
		currentSession.seed = time(0); // Seed based on the time. Time always changes!
		srand(currentSession.seed); // random function.
		//Pre-emptive calculations
		currentSession.num1 = rand() % 11 + 1; // Randomly generate numbers 1-12 by using the modulo for any seed and then add 1 so as to keep it in the range 1-9, not 0-8
		currentSession.num2 = rand() % 11 + 1;
		product = currentSession.num1 * currentSession.num2;
		currentSession.correctAnswer = currentSession.num1;
		cout << "What is " << product << " divided by " << currentSession.num2 << endl;
		
		cin >> currentSession.userAnswer;
	
		//Compare answers
		cout << "You answered: " << currentSession.userAnswer << endl << endl;
		if (currentSession.userAnswer == currentSession.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl << endl;
			currentSession.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << currentSession.correctAnswer << endl << endl;
		}
		cout << "You got " << currentSession.timesCorrect << " out of " << currentSession.attempts << " correct." << endl << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> currentSession.playAgain;
		
		if (currentSession.playAgain == 'Y' || currentSession.playAgain == 'y') 
		{
			DivisionQuiz();
		}
		else if (currentSession.playAgain == 'N' || currentSession.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> currentSession.quitGame;
			if (currentSession.quitGame == 'y' || currentSession.quitGame == 'Y')
			{
				system("cls"); // Clear the screen for organization.
				cout << "Thanks for playing! Goodbye!" << endl;
				exit(0);
			}
			else if (currentSession.quitGame == 'n' || currentSession.quitGame == 'N')
			{
				currentSession.timesCorrect = currentSession.attempts = 0;
				system("cls");
				main();
			}
			else
			{
				cout << "Error: invalid input. Please try again." << endl;
				cin >> currentSession.quitGame;
			}
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> currentSession.playAgain;
		}
	}
}
