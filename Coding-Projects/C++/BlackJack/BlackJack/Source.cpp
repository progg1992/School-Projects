/*
Pierce Rogg
CIS 247C
BlackJack Application
5/16/2021
*/

// Required Libraries
#include <iostream>
#include <conio.h>
#include <string>
#include "Card.h"
#include <vector>
using namespace std;

// Prototypes
string showCards( vector<Card> cards );
short sumCardValues(vector<Card> cards);
void playHand(short &cash);

/// Entry point to the application
int main()
{
	// set cash and display
	short cash = 100;
	cout << "Welcom to BlackJack Extreme!" << endl;
	cout << "\nYou are starting out with " << cash << " bucks" << endl;

	// Pause
	cout << "\nPress any key to continue...";
	_getch();

	// Main Loop variable
	short choice = 0;
	do
	{
		// Display App. Menu
		system("cls");
		cout << "\nMain Menu\n" << endl;
		cout << "1) Play a hand" << endl;
		cout << "2) Show current cash balance" << endl;
		cout << "3) Exit" << endl;

		// Get user's choice
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			playHand(cash);
			break;
		case 2:
			cout << "\nYour current cash balance: $"<< cash << endl;
			break;
		case 3:
			cout << "\nThank you for Playing BlackJack Extreme! Have a nice day." << endl;
			cout << "\nYour final cash balance: $" << cash << endl;
			break;
		default:
			cout << "\nERROR!! Please only use integers on the Menu!" << endl;
			break;
		}

		// Pause
		cout << "\nPress any key to continue...";
		_getch();

	} while (choice != 3);
}

/// Show Card Prototype
string showCards(vector<Card> cards)
{
	string output = "";

	for (short i = 0; i< cards.size(); i++)
	{
		output += cards[i].toString() + " ";
	}
	
	return output;
}

/// Adds total of cards
short sumCardValues(vector<Card> cards)
{
	short total = 0;

	for (short i = 0; i < cards.size(); i++)
	{
		total += cards[i].getValue();
	}
	return total;
}

/// Play a Hand
void playHand(short& cash)
{
	vector<Card> dealerCards;
	vector<Card> playerCards;
	short dealerCardsTotal = 0;
	short playerCardsTotal = 0;

	// Get bet amount
	short bet = 0;
	cout << "\nEnter bet amount: ";
	cin >> bet;

	//  Dealer Cards and Show 1
	Card card1;
	Card card2;
	dealerCards.push_back(card1);
	dealerCards.push_back(card2);
	dealerCardsTotal = sumCardValues(dealerCards);

	cout << "\nDealer is showing: " << dealerCards[0].toString() << endl;

	// Player Cards and show both
	playerCards.push_back(Card());
	playerCards.push_back(Card());

	playerCardsTotal = sumCardValues(playerCards);

	cout << "\nHere are your Cards: " << showCards(playerCards) << endl;

	// Give cards until Stand
	char answer = '?';
	do
	{
		cout << "\nDo you want to hit or stand (H/S)? ";
		cin.sync();
		cin >> answer;
		cin.sync();

		if (toupper(answer) == 'H')
		{
			Card c;
			cout << "\nYou were dealt a: " << c.toString() << endl;
			playerCards.push_back(c);

			playerCardsTotal = sumCardValues(playerCards);

			if (playerCardsTotal > 21)
			{
				for (short i = 0; i < playerCards.size(); i++)
				{
					if (playerCards[i].getValue() == 11)
					{
						cout << "\nYour total is " << playerCardsTotal << endl;
						playerCards[i].flipAceToOne();
						cout << "However you have an Ace that was converted to a value of '1'" << endl;
						playerCardsTotal = sumCardValues(playerCards);
						cout << "\nYour new total is " << playerCardsTotal << endl;

						// If good break out of loop
						if (playerCardsTotal <= 21)
							break;
					}
				}
			}

			// Show Cards
			cout << "\nHere are your Cards: " << showCards(playerCards) << endl;
			cout << "Your new total is " << playerCardsTotal << endl;

			// If still busted stop
			if (playerCardsTotal == 21)
				break;
		}

	} while (toupper(answer) != 'S');

	// Did player win or lose
	if (playerCardsTotal > 21)
	{
		cout << "\nYou Lost!" << endl;
		cash = cash - bet;
	}
	else
	{
		// Dealer Hits until 17 or greater
		do
		{
			if (dealerCardsTotal < 17)
			{
				Card c;
				cout << "\nDealer was dealt: " << c.toString() << endl;
				dealerCards.push_back(c);
				cout << "\nDealer cards: " << showCards(dealerCards) << endl;
				dealerCardsTotal = sumCardValues(dealerCards);
				cout << "\nDealer has: " << dealerCardsTotal << endl;
			}
		} while (dealerCardsTotal < 17);

		// Show Player and Dealer Cards
		cout << "\nYour cards: " << showCards(playerCards) << " (" << playerCardsTotal << endl;
		cout << "\nDealer cards: " << showCards(dealerCards) << " (" << dealerCardsTotal << endl;

		// Who wins
		if (dealerCardsTotal > 21)
		{
			cout << "\nDealer busted!" << endl;
			cash = cash + bet;
		}
		else if (dealerCardsTotal > playerCardsTotal)
		{
			cout << "\nDealer Wins!" << endl;
			cash = cash - bet;
		}
		else if (playerCardsTotal > dealerCardsTotal)
		{
			cout << "\nYou Win!" << endl;
		}
		else
		{
			cout << "\nYou pushed the dealer!" << endl;
		}
	}

	// Show Cash Amount
	cout << "\nYour current cash balance: $" << cash << endl;
}