//
// Assignment 4
// Donovan Torgerson
// Donovan@Bitzpc.com
// 9/14/11
//

#include "Cslot.h"
#include "Cspinner.h"


void main() 
{ 
	Cslot newGame;
	int payarray[3][7] = {	{4, 10, 50, 250, 1, 2, 20},
	{8, 20, 75, 500, 2, 4, 40},
	{16, 30, 500, 750, 3, 6, 60} };
	Cspinner w1;
	Cspinner w2;
	Cspinner w3;
	int credits = 0;
	int lastpay = 0;
	char option = 0;
	int payoff = 0;
	int wager = 0;
	cout << "QUARTER SLOT MACHINE" << endl << endl;
	do{
		cout << "Please select one of the following options" << endl; 
		cout << "Q:      Quarter" << endl;
		cout << "O:      One dollar" << endl;
		cout << "F:      Five dollars" << endl;
		cout << "T:      Ten Dollars" << endl;
		cout << "1:      Play one quarter              Credits:     " << credits << endl;
		cout << "2:      Play two quarters             Last payoff: " << lastpay << endl;
		cout << "3:      Play three quarters" << endl;
		cout << "4:      Cash out" << endl;
		cout << "5:      Exit Program" << endl;
		cout << "Enter Selection: ";
		cin >> option;
		cout << endl;
		switch(option)
		{
		case 'q':		// Add quarter
		case 'Q':
			credits = newGame.addCredit(Currency::Quarter);
			newGame.addBank(Currency::Quarter);
			break;
		case 'o':		// Add one dollar
		case 'O':
			credits = newGame.addCredit(Currency::Dollar);
			newGame.addBills(Currency::Dollar);
			break;
		case 'f':		// Add five dollars
		case 'F':
			credits = newGame.addCredit(Currency::Five);
			newGame.addBills(Currency::Five);
			break;
		case 't':		// Add ten dollars
		case 'T':
			credits = newGame.addCredit(Currency::Ten);
			newGame.addBills(Currency::Ten);
			break;
		case '1':		// Play one quarter
			if (credits >= 1)
			{
				wager = 1;
				credits = newGame.subCredit(wager);
				w1.spin();
				w2.spin();
				w3.spin();
				newGame.chkPayArry(payarray, wager, w1, w2, w3, payoff);
				lastpay = newGame.chkPayoff();
				credits = newGame.addCredit(payoff);
				cout << w1 << w2 << w3 << endl << endl;
			}
			else cout << "\nNot enough credits!!!\n" << endl;
			break;
		case '2':		// Play two quarters
			if (credits >= 2)
			{
				wager = 2;
				credits = newGame.subCredit(wager);
				w1.spin();
				w2.spin();
				w3.spin();
				newGame.chkPayArry(payarray, wager, w1, w2, w3, payoff);
				lastpay = newGame.chkPayoff();
				credits = newGame.addCredit(payoff);
				cout << w1 << w2 << w3 << endl << endl;
			}
			else cout << "\nNot enough credits!!!\n" << endl;
			break;
		case '3':		// Play 3 quarters
			if (credits >= 3)
			{
				wager = 3;
				credits = newGame.subCredit(wager);
				w1.spin();
				w2.spin();
				w3.spin();
				newGame.chkPayArry(payarray, wager, w1, w2, w3, payoff);
				lastpay = newGame.chkPayoff();
				credits = newGame.addCredit(payoff);
				cout << w1 << w2 << w3 << endl << endl;
			}
			else cout << "\nNot enough credits!!!\n" << endl;
			break;
		case '4':		// Cash out
			credits = newGame.cashOut();
			break;
		}
	}while(option != '5');
	newGame.profitReport();
	system("pause");
}