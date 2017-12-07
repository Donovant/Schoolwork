# Assignment 8:

- This assignment covers templating and exceptions.  
  
Build a templated Stack.  The Stack should have the following methods. (Last in First Out)  
  
```
Stack()          //  Default constructor.  Creates a stack that holds five items.

Stack(int size)  // Constructor.  Creates a stack that holds size items.

Push(t item)  // This procedure should put the new item on the top of the stack.
              //  This procedure should throw an exception if the stack is full.

t Pop()          // This procedure should return the top item of the stack.
                 //  This procedure should throw an exception if the stack is empty.

t RemoveItemFromBottom();  // This procedure removes the item from the bottom.
                           // The item is returned and the stack is shifted down.
                           //  This procedure should throw an exception if the stack is empty.

bool Empty();  // Returns (true) if the stack is empty.
```
   
Create a main program.  In the main program declare two stacks.  One stack should be able to store integers and one stack should be able to store characters.  Create a main program with the following menu.  
  
1)    Add an item to the integer stack  
2)    Add an item to the character stack  
3)    Remove and display top item of integer stack  
4)    Remove and display top item of character stack  
5)    Quit  
  
In option 1 and 2 if the stack throws a stack full error the following menu should appear.  
  
A)    Throw away new item.   //  The item they tried to add is thrown away.  
B)    Throw away top item.   //  The top item is thrown away and the new value is added to the top.  
C)    Throw away bottom item. // The bottom item is thrown away and the new value is added to the top.  
  
After the user selects (A, B, or C) the program should go back to the main menu.  
  
When the user quits remove and display the remaining items in the stack.  
