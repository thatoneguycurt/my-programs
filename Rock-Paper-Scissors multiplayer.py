import random

def main():
    answer="y"
    while answer == "y":
        game()
        answer = input("Do you want to play again? (y/n) ")
        print("")
    if answer == "n":
        print("Thanks for playing! Goodbye!")
    else:
        print("Error! Please make a valid selection!")
        main()
        

def game():

    print("Welcome to Rock, Paper, Scissors!")
    print("You can choose between one of the following:")
    print("1. Rock")
    print("2. Paper")
    print("3. Scissors")
    
    player1 = str(input("Player 1, please enter your name: "))
    player2 = str(input("Player 2, please enter your name: "))
    choice1 = random.randrange(1, 4)
    choice2 = random.randrange(1, 4)


    if choice1 == 1:
        print(player1,"played rock.")

    elif choice1 == 2:
        print(player1,"played paper.")

    else:
        print(player1,"played scissors.")

    if choice2 == 1:
        print(player2,"played rock.")

    elif choice2 == 2:
        print(player2,"played paper.")

    elif choice2 == 3:
        print(player2,"played scissors.")

    if choice1 == 1 and choice2 == 1:
        print("Tie.")

    elif choice1 == 1 and choice2 == 2:
        print(player2,"wins!")

    elif choice1 == 1 and choice2 == 3:
        print(player1,"wins!")

    elif choice1 == 2 and choice2 == 1:
        print(player1,"wins!")

    elif choice1 == 2 and choice2 == 3:
        print(player2,"wins!")

    elif choice1 == 2 and choice2 == 2:
        print("Tie.")

    elif choice1 == 3 and choice2 == 2:
        print(player1,"wins!")

    elif choice1 == 3 and choice2 == 1:
        print(player2,"wins!")

    elif choice1 == 3 and choice2 == 3:
        print("Tie.")

main()
                   
                   
