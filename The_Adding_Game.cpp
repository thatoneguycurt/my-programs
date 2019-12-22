#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

/* Function prototypes */
void easyMode();
void mediumMode();
void hardMode();

class MathGame
{
	public:
		static int attempts;
		static int timesCorrect;
		MathGame()
		{
			attempts++; // Each time a game object is created, add 1 to attempts
		}
		char playAgain, quitGame;
		int num1, num2, userAnswer, correctAnswer;
};

int MathGame::timesCorrect = 0;
int MathGame::attempts = 0;

int main() 
{

	int choice;
	
	cout << "-------------------------------" << endl;
	cout << "*                             *" << endl;
	cout << "* Welcome to the Adding Game! *" << endl;
	cout << "*                             *" << endl;
	cout << "-------------------------------" << endl;
	cout << "Press any key to continue." << endl;
	getchar();
	
	
	cout << "Please select your difficulty: " << endl;
	cout << "1. Easy " << endl;
	cout << "2. Medium " << endl;
	cout << "3. Hard " << endl;
	cout << "4. Quit Game " << endl;
	
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
		cout << "Invalid choice! Please try again.\a" << endl;
		cin >> choice;
	}
			
	if (choice != 4) // If you're not quitting the game, choose an exercise.
	{
		switch (choice)
		{
			case 1:
				easyMode();
				break;
			case 2:
				mediumMode();
				break;
			case 3:
				hardMode();
				break;
		}
	}
			
	else
	{
		cout << "Thanks for playing! Good bye!" << endl;
		exit(0);
	}
	 
		return 0;
	
}

void easyMode()
{
	MathGame easyGame;

	easyGame.playAgain = 'Y';

	while (easyGame.playAgain == 'Y' || easyGame.playAgain == 'y') 
	{
		unsigned seed;
		seed = time(0); // Seed based on the time. Time always changes!
		srand(seed); // random function.
		//Pre-emptive calculations
		easyGame.num1 = rand() % 9 + 1; // Randomly generate numbers 1-9 by using the modulo for any seed and then add 1 so as to keep it in the range 1-9, not 0-8
		easyGame.num2 = rand() % 9 + 1;
		easyGame.correctAnswer = easyGame.num1 + easyGame.num2;
		
		//Set up the math statement
		cout << "Add the following: " << endl;
		cout << "  " << easyGame.num1 << endl;
		cout << "+ " << easyGame.num2 << endl; 
		cout << "---" << endl << endl;
		
		cout << "What is the answer?: " << endl;
		cin >> easyGame.userAnswer;
		
		//Compare answers
		cout << "You answered: " << easyGame.userAnswer << endl;
		if (easyGame.userAnswer == easyGame.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl;
			easyGame.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << easyGame.correctAnswer << endl;
		}
		cout << "You got " << easyGame.timesCorrect << " out of " << easyGame.attempts << " correct." << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> easyGame.playAgain;
		
		if (easyGame.playAgain == 'Y' || easyGame.playAgain == 'y') 
		{
			easyMode();
		}
		else if (easyGame.playAgain == 'N' || easyGame.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> easyGame.quitGame;
				if (easyGame.quitGame == 'y' || easyGame.quitGame == 'Y')
				{
					system("cls"); // Clear the screen for organization. 
					cout << "Thanks for playing! Goodbye!" << endl;
					exit(0);
				}
				else if (easyGame.quitGame == 'n' || easyGame.quitGame == 'N')
				{
					system("cls");
					main();
				}
				else
				{
					cout << "Error: invalid input. Please try again." << endl;
					cin >> easyGame.quitGame;
				}
	
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> easyGame.playAgain;
		}
}

}

void mediumMode()
{
	MathGame mediumGame;

	mediumGame.playAgain = 'Y';

	while (mediumGame.playAgain == 'Y' || mediumGame.playAgain == 'y') 
	{
		unsigned seed;
		seed = time(0); // Seed based on the time. Time always changes!
		srand(seed); // random function.
		//Pre-emptive calculations
		mediumGame.num1 = rand() % 99 + 1; // Randomly generate numbers 1-9 by using the modulo for any seed and then add 1 so as to keep it in the range 1-9, not 0-8
		mediumGame.num2 = rand() % 99 + 1;
		mediumGame.correctAnswer = mediumGame.num1 + mediumGame.num2;
		
		//Set up the math statement
		cout << "Add the following: " << endl;
		cout << "  " << mediumGame.num1 << endl;
		cout << "+ " << mediumGame.num2 << endl; 
		cout << "----" << endl << endl;
		
		cout << "What is the answer?: " << endl;
		cin >> mediumGame.userAnswer;
		
		//Compare answers
		cout << "You answered: " << mediumGame.userAnswer << endl;
		if (mediumGame.userAnswer == mediumGame.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl;
			mediumGame.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << mediumGame.correctAnswer << endl;
		}
		cout << "You got " << mediumGame.timesCorrect << " out of " << mediumGame.attempts << " correct." << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> mediumGame.playAgain;
		
		if (mediumGame.playAgain == 'Y' || mediumGame.playAgain == 'y') 
		{
			mediumMode();
		}
		else if (mediumGame.playAgain == 'N' || mediumGame.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> mediumGame.quitGame;
				if (mediumGame.quitGame == 'y' || mediumGame.quitGame == 'Y')
				{
					system("cls"); // Clear the screen for organization. 
					cout << "Thanks for playing! Goodbye!" << endl;
					exit(0);
				}
				else if (mediumGame.quitGame == 'n' || mediumGame.quitGame == 'N')
				{
					system("cls");
					main();
				}
				else
				{
					cout << "Error: invalid input. Please try again." << endl;
					cin >> mediumGame.quitGame;
				}
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> mediumGame.playAgain;
		}
}

}

void hardMode()
{
	MathGame hardGame;

	hardGame.playAgain = 'Y';

	while (hardGame.playAgain == 'Y' || hardGame.playAgain == 'y') 
	{
		unsigned seed;
		seed = time(0); // Seed based on the time. Time always changes!
		srand(seed); // random function.
		//Pre-emptive calculations
		hardGame.num1 = rand() % 999 + 1; // Randomly generate numbers 1-9 by using the modulo for any seed and then add 1 so as to keep it in the range 1-9, not 0-8
		hardGame.num2 = rand() % 999 + 1;
		hardGame.correctAnswer = hardGame.num1 + hardGame.num2;
		
		//Set up the math statement
		cout << "Add the following: " << endl;
		cout << "  " << hardGame.num1 << endl;
		cout << "+ " << hardGame.num2 << endl; 
		cout << "-----" << endl << endl;
		
		cout << "What is the answer?: " << endl;
		cin >> hardGame.userAnswer;
		
		//Compare answers
		cout << "You answered: " << hardGame.userAnswer << endl;
		if (hardGame.userAnswer == hardGame.correctAnswer) // Compare the two values.
		{
			cout << "Congratulations! That is the correct answer!" << endl;
			hardGame.timesCorrect++; 
		}
		else 
		{
			cout << "Sorry, that is the incorrect answer. The correct answer is " << hardGame.correctAnswer << endl;
		}
		cout << "You got " << hardGame.timesCorrect << " out of " << hardGame.attempts << " correct." << endl;
		cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
		cin >> hardGame.playAgain;
		
		if (hardGame.playAgain == 'Y' || hardGame.playAgain == 'y') 
		{
			hardMode();
		}
		else if (hardGame.playAgain == 'N' || hardGame.playAgain == 'n')
		{
			cout << "Do you want to exit the game? (Type y for yes, n for no.)" << endl;
			cin >> hardGame.quitGame;
				if (hardGame.quitGame == 'y' || hardGame.quitGame == 'Y')
				{
					system("cls"); // Clear the screen for organization. 
					cout << "Thanks for playing! Goodbye!" << endl;
					exit(0);
				}
				else if (hardGame.quitGame == 'n' || hardGame.quitGame == 'N')
				{
					system("cls");
					main();
				}
				else
				{
					cout << "Error: invalid input. Please try again." << endl;
					cin >> hardGame.quitGame;
				}
		}
		else 
		{
			cout << "Error! Invalid input!" << endl;
			cout << "Would you like to play again? (Type y for yes and n for no.)" << endl;
			cin >> hardGame.playAgain;
		}
	}
}
