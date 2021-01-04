//Garrett Pesi CS 0457 Dice
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int wins = 0, losses = 0, money = 0;

//Prototyping of functions
int roll();
void exit();
void newGame();

int main()
{
    //Declaration and initialization of variables used
	int d0 = 0, d1 = 0, total = 0, seed = 0, target = 0;
	char key = '\0';
	bool normalRoll = true, quit = false;

	//Get seed value from user, echo it, set seed value
	//If seed negative, uses system time
	cout << "Enter your lucky number:  ";
	cin >> seed;
	cout << seed << endl;
	if (seed < 0) {
		cout << "Using system time as the seed." << endl;
		srand(time(NULL));
	}
	else {
		srand(seed);
	}
    
	//Runs the game while 'q' isn't entered
	//Exits the loop if it is entered
	while (1) {
		//First set of dice rolls
		//Keeps track of whether first roll wins or loses the game
		normalRoll = true;

		//Make sure correct keys are pressed
		while (key != 'r' && key != 'q') {
			cout << "Press 'r' to roll the first set of dice, or 'q' to quit:  ";
			cin >> key;
			cout << key << endl;
		}

		//If 'q' is entered, leaves game
		if (key == 'q') {
			break;
		}

		//If 'r' is entered, rolls the first die, prints to screen
		d0 = roll();
		cout << "Die 1 is " << d0 << endl;
		d1 = roll();
		cout << "Die 2 is " << d1 << endl;
		total = d1 + d0;
		cout << "Your total roll was " << total << endl;

		//Resets key
		key = '\0';

		//Tests the total roll
		switch (total) {
			//Winning cases
			case 7:
				money += 1;
			case 11:
				cout << "Congrats, you won!" << endl;
				cout << "How about another game?" << endl;
				wins++;
				money += 9;
				normalRoll = false;
				break;
			//Losing cases
			case 2:
			case 3:
			case 10:
			case 12:
				cout << "Ouch, you lost this one!" << endl;
				cout << "How about another try?" << endl;
				losses++;
				money -= 10;
				normalRoll = false;
				break;
			//Sets target roll
			default:
				target = total;
				cout << target << " is the target number to hit..." << endl;
				break;
		}

		total = 0;

		//If first roll wins or loses, starts a new game
		if (normalRoll == false) {
			newGame();
			continue;
		}

		//Second set of rolls
		while (1){
			total = 0;
			//Checks keys again
			while (key != 'r' && key != 'q') {
				cout << "Press 'r' to roll the second set of dice, or 'q' to quit:  ";
				cin >> key;
				cout << key << endl;
			}

			//If 'q' is entered, leaves game
			if (key == 'q') {
				losses++;
				money -= 10;
				quit = true;
				break;
			}

			key = '\0';

			//If 'r' is entered, rolls next set, prints to screen
			d0 = roll();
			cout << "Die 1 is " << d0 << endl;
			d1 = roll();
			cout << "Die 2 is " << d1 << endl;
			total = d0 + d1;
			cout << "Your roll total was " << total << endl;

			//Tests the die roll
			//Loss
			if (total == 7) {
				cout << "Ouch, you lost" << endl;
				losses++;
				money -= 9;
				break;
			}
			//Win
			else if (total == target) {
				cout << "Congrats, you won!" << endl;
				wins++;
				money += 9;
				break;
			}
			//Reroll
			else {
				cout << "Looks like you didn't hit yet..." << endl;
				cout << target << " is the target number to hit..." << endl;
			}

		}

		//Checks to see if 'q' was pressed in the second roll loop
		if (quit == true) {
			break;
		}

		//Starts a new game
		cout << "How about another game?" << endl;
		total = 0;
		key = '\0';
		newGame();

	}

	//Runs once 'q' is pressed
	exit();

    return 1;
}

int roll() {
    //Simulates rolling of a die based on seed value set in main
    //Makes sure the value is between 1 and 6
	//Activated after 'r' is entered
    return rand() % 6 + 1;
}

void exit() {
	//Starts the exit process, which displays wins, losses, and money
	//Also displays textual histogram of 50,000 dice rolls with current seed
	//Activated after 'q' is entered
	int result = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	//Display final scores
	cout << "Here are your final results:  " << endl;
	newGame();
	//Roll 50,000 times
	cout << "\n\nTime to roll 50,000 times..." << endl;
	for (int i = 0; i < 50000; i++) {
		result = roll();
		switch (result) {
			case 1:
				one++;
				break;
			case 2:
				two++;
				break;
			case 3:
				three++;
				break;
			case 4:
				four++;
				break;
			case 5:
				five++;
				break;
			default:
				six++;
				break;
		}
	}

	//Display results of the rolls
	cout << "Here are the results:  " << endl;
	cout << "Ones:  " << one << endl << "Twos:  " << two << endl;
	cout << "Threes:  " << three << endl << "Fours:  " << four << endl;
	cout << "Fives:  " << five << endl << "Sixes:  " << six << endl;
}

void newGame() {
	//Prints lines ------- and score
	//Called everytime a new game is started
	cout << "----------------------------------------" << endl;
	cout << "Wins:  " << wins << "  Losses:  " << losses << "  Money:  " << money << endl;
}

