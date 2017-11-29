# Assignment 3:

- Add the following functions to the Cspinner class.

Overload the equal sign to compare two spinners.  The following instruction should be valid if w1, w2 and w3 are spinners.  

```  
    if ( w1 == w2 && w2 == w3)     cout << "You win!";
```  
Overload the equal sign to compare a spinner and a fruit (an array of characters).  The following instruction should be valid.
```  
    if (w1 == "Apple") cout << "Spinner is a Apple.";  
```  
Overload the output (<<).  This will replace the show procedure.  Below is an example.  
```  
    cout << w1 << endl;  
```
  
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
                cout << w1 << w2 << w3; 
                if (w1 == w2 && w2 == w3)
                { 
                    if (w1 == "Apple")    cout << "  (All Apples) "; 
                    else if (w1== "Orange") cout << "  (All Oranges) "; 
                    else if (w1== "Cherry") cout << "  (All Cherries) "; 
                    else if (w1== "Banana") cout << "  (All Bananas) "; 
                    else  cout << "  (All Peaches)"; 
                }

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
orange orange orange  (All Oranges) 
orange apple apple 
peach apple apple 
orange apple peach 
apple cherry apple