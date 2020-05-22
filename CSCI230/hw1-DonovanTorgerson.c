/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	******************************************************
	HW-1	CS230	10 points	Due: Friday, August 31
	******************************************************

	Create a C program that will calculate the interest paid on
	a loan. The equations we will use are:

		 I[o] = (r/12)*B
		 I[n] = (r/12)*(B-P+I[n-1])

	Where:
		 r is the anual interest rate (assume 25% or 0.25).
		 B is the amount borrowed (assume $2000).
		 P is the payment amount (pick some value).
		 I[o] is the interest due after the first month.
		 I[n] is the interest due after the nth month.

	Your program must prompt the user for the monthly payment that
	they wish to make. Your program must then display the interest
	rate (r), the initial balance (B), the monthly payment (P).
	Your program must then produce a month-by-month table showing the
	month, the interest due/paid each month and the remaining balance.

	The table must take the user to the payoff-point (where balance
	becomes zero or negative). Finally the program must display the
	total interest paid over the life of the loan.

	Example:
	--------
	Enter your monthly payment: 200

	r = 0.25
	B = 2000.0
	P = 200.0

	1 41.67	2000.00
	2 38.37	1841.67
	3 35.00	1680.03
	4 31.56	1515.04
	5 28.05	1346.60
	6 24.47	1174.65
	7 20.82	999.12
	8 17.08	819.94
	9 13.27	637.02
	10 9.38	450.29
	11 5.41	259.67
	12 1.36	65.08
	13 -2.78 -133.56

	total interst paid: 266.44


	CONCERNS:
	---------
	1. Watch the data types!

	REQUIREMENTS:
	-------------
	1. Your program must run in Streibel 115/109 or on Gandalf.aero.und.edu.

	2. Your full name must appear as a comment at the beginning of your
	   program.

	3. Your source code must be named hw1-yourname.c

	3. Email your source (subject hw1-yourname) to <<Redacted>>
	
*/
#include <stdio.h>
main()
{
	int x = 1;
	int y;
	float r, P, B, interest, I[100];
	r = 0.25;
	B = 2000;

	printf("Enter monthly payment amount: ");
	scanf("%f", &P);
	printf("r = \t%.2f\n", r);
	printf("B = \t%.2f\n", B);
	printf("P = \t%.2f\n", P);

	I[0] = (r / 12)*B;

	printf("\n%d\t%.2f\t%.2f \n", x, I[0], B);
	
	for (x = 1; B > 0; x++)
	{
		I[x] = (r / 12)*(B - P + I[x - 1]);
		B = B - P + I[x - 1];
		printf("%d\t%.2f\t%.2f \n", x, I[x], B);
	}

	for (y = 0; y != x - 1; y++)
	{
		interest = interest + I[y];
	}

	printf("\nTotal interest paid: \t%.2f \n", interest);
}
