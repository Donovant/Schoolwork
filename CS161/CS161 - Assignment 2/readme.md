# Assignment 2:

- Create the class called Cspinner.  This class will have functions to spin and show.  When spinning, 
five fruits have the chance of coming up (apple, orange, cherry, banana and peach).  Each will have a different 
probability of coming up.  When using the default constructor the probabilities are as follows.

1.      apple -         30% 
2.      orange -        25% 
3.      cherry -        20% 
4.      banana -        15% 
5.      peach -         10%

When using the other constructor the user gets to select the percent for each fruit.  (Example Cspinner s2(50,20,10,10,10);)

spin is a procedure that spins the fruit on the spinner.

show is a procedure that displays the fruit of the spinner.

The following is an example of a main program that uses the spinner.  In this example three spinners are declared. 
 
```
void main() 
{ 
        Cspinner w1; 
        Cspinner w2; 
        Cspinner w3(80,5,5,5,5); 
        for (int x=0;x<=9;x++) 
        { 
                w1.spin(); 
                w2.spin(); 
                w3.spin(); 
                w1.show(); 
                w2.show(); 
                w3.show(); 
                cout << endl; 
        } 
}
```

Example output of the above program.

orange apple apple 
peach banana apple 
banana apple apple 
orange orange apple 
banana cherry apple 
orange orange orange 
orange apple apple 
peach apple apple 
orange apple peach 
apple cherry apple