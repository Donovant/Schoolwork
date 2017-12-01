# Assignment 4:

- Write the program that is going to simulate a slot machine. 
The slot machine should have the following menu. 
  
 

QUARTER SLOT MACHINE

 Please select one of the following options:  

 Q: Quarter 
 O: One dollar 
 F: Five dollars 
 T: Ten Dollars 
 1: Play one quarter&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Credits -       0 
 2: Play two quarters&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Last payoff -   0 
 3: Play three quarters 
 4: Cash out 
 5: Exit Program 
   
 Last spin -> Apple Apple Orange   
  
  
 

If the user selects option (Q, O, F, or T) these options only 
change the number of credits. (Q - 1, O - 4 , F - 20, T - 40) 
 

If the user selects option (1, 2, or 3) these options play the 
slot machine.  If there is enough money to play.  The pay outs 
are as follows. 
  
| Spin                 | Play 1 | Play 2 | Play 3 |
| -------------------- | ------ | ------ | ------ |
| Apple  Apple  Apple  |    4   |    8   |   16   |
| Orange Orange Orange |   10   |   20   |   30   |
| Banana Banana Banana |   50   |   75   |  100   |
| Peach  Peach  Peach  |  250   |  500   |  750   |

1 Cherry any where money back  
2 Cherries any where money back * 2   
3 Cherries   money back * 20  
  
If the user selects cash out the slot machine should pay out in quarters.  If there is not enough quarters in the machine it should print out "get a cashier".  The slot machine should start out with 500 quarters.  
  
When the program exits it should report the Loss or Gain for the slot machine.  
  
Last payoff should report how much they won on the last spin.  