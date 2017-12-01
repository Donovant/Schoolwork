#if !defined(Cslot_h)
#define Cslot_h

#include "Cspinner.h"

class Cslot
{
private:
	int bank;		// number of quarters in the machine
	int credit;		// number of current credits
	int bills;		// number of dollars in the system
	int profit;		// profit/loss of machine
	int a3;			// all apple
	int o3;			// all orange
	int b3;			// all banana
	int p3;			// all peach
	int c1;			// one cherry
	int c2;			// two cherry
	int c3;			// all cherry
	int lastPay;

public:
	Cslot()
	{
		bank = 500;
		credit = 0;
		bills = 0;
		a3 = 0;
		o3 = 1;
		b3 = 2;
		p3 = 3;
		c1 = 4;
		c2 = 5; 
		c3 = 6;
		lastPay = 0;
		profit = 0;
	}

	void addBank(Currency newAmt)
	{
		bank += newAmt;	
	}

	int addCredit(int addAmt)
	{
		credit += addAmt;
		return credit;
	}

	int subCredit(int subAmt)
	{
		credit -= subAmt;
		return credit;
	}

	int subBank(int newAmt)
	{
		bank -= newAmt;
		credit -= newAmt;
		return credit;
	}

	void addBills(int addAmt)
	{
		bills += addAmt/4;
	}

	void profitReport()
	{
		profit = (bills * 4) + bank - 500;
		if (profit < 0) cout << "System reports loss of " << abs(profit) << " quarter(s)\n" << endl;
		else if (profit > 0) cout << "System reports gain of " << profit << " quarter(s)\n" << endl;
		else cout << "System reports it broke even\n" << endl;
	}

	int chkPayoff()
	{
		return lastPay;
	}

	int chkPayArry(int payarray[3][7], int w, Cspinner w1, Cspinner w2, Cspinner w3, int payoff)
	{
		if (w1 == w2 && w2 == w3)
		{ 

			if (w1 == "Apple ")
			{
				payoff = payarray[w-1][a3];
				lastPay = payoff;
				this->addCredit(payoff);
			}
			else if (w1== "Orange ")
			{
				payoff = payarray[w-1][o3];
				lastPay = payoff;
				this->addCredit(payoff);
			}
			else if (w1== "Banana ")
			{
				payoff = payarray[w-1][b3];
				lastPay = payoff;
				this->addCredit(payoff);
			}
			else if (w1== "Peach ")
			{
				payoff = payarray[w-1][p3];
				lastPay = payoff;
				this->addCredit(payoff);
			}
			else 
			{
				payoff = payarray[w-1][c3];
				lastPay = payoff;
				this->addCredit(payoff);
			}
		}
		else if (((w1 == "Cherry ") && !(w2 == "Cherry ") && !(w3 == "Cherry ")) || (!(w1 == "Cherry ") && !(w2 == "Cherry ") && (w3 == "Cherry ")) || (!(w1 == "Cherry ") && (w2 == "Cherry ") && !(w3 == "Cherry ")))  // If any one spinner is Cherry
		{
			payoff = payarray[w-1][c1];
			lastPay = payoff;
			this->addCredit(payoff);
		}
		else if (((w1 == "Cherry ") && (w2 == "Cherry ") && !(w3 == "Cherry ")) || (!(w1 == "Cherry ") && (w2 == "Cherry ") && (w3 == "Cherry ")) || ((w1 == "Cherry ") && !(w2 == "Cherry ") && (w3 == "Cherry ")))  // If any two spinners are Cherry
		{
			payoff = payarray[w-1][c2];
			lastPay = payoff;
			this->addCredit(payoff);
		}
		return payoff;
	}

	int cashOut()
	{
		if(credit <= bank && credit >= 0)
		{
			bank -= credit;
			cout << "\n" << credit << " quarters paid out!!!\n" << endl;
			credit = 0;
		}
		else
		{
			cout << "\nPlease get a cashier to complete transaction!\n" << endl;
		}
		return credit;
	}
};

#endif