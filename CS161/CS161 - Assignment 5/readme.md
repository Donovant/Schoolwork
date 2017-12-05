# Assignment 5:

- In this assignment you are to create a class called KString.  The KString will have two pieces of data ( a dynamic array of characters and an integer that holds the length of the dynamic array).  All the procedure and functions that are added to the KString will do something to this data.  Below is a list of procedure and function that you should add to the class. 
```
KString( const char name[ ]); // Constructor that is passed in an array of characters.  This constructor should make it possible to do                                                
                              // the following.   Name = "Scott";   In this example Scott is an array of characters.  The computer would 
                              // call the constructor which would convert it into a KString and then it would assign it.  This constructor 
                              // Should ask for dynamic memory and then store Scott in it.  It should also set length.
  
KString( const KString & temp)				// Copy constructor
  
KString();									// default constructor should just set length to zero. 
  
~KString();									// Destructor, should give dynamic memory back. 
  
void operator =(KString temp);				// This procedure makes it possible to assign one KString equal to another KString. 
											// This is needed because of dynamic memory.
  
char &operator[ ] (int i);					// This overloads the [ ].  This return one character as a lvalue.
  
const char &operator[ ](int i) const;		// This overloads the [ ].  This return one character as a rvalue. 
  
KString operator +(KString temp);           // This makes it possible to add to KStrings together (concatenation). 
```
  
Example main program:  
```
void main() 
{ 
    KString k1("Scott ");			// Creates a KString initialized to "Scott " 
    KString k2;						// Creates a KString 
    KString k3;						// Creates a KString 
    k2 = "Cast";					// Assigns "Cast" to k2 
    k3 = k1 + k2;					// Concatenates K1 and K2 and assigns to k3 
    cout << k3[6] << endl;			// Prints out the 6 character in k3 (C) 
    k3[6]='K';						// Changes the 6 character from (C) to (K) 
    cout << "Enter your name"; 
    cin >> k2;						// you need to overload >> for the KString 
    if ( k1 == k2)					// you need to overload == to compare two KStrings. 
            cout << "Same Name"  << endl; 
     if ( k1 < k2)					// you need to overload < to compare two KStrings. 
            cout << "First name less than"  << endl; 
     if ( k1 > k2)					// you need to overload > to compare two KStrings. 
            cout << "First name greater than"  << endl; 
    cout << k2 << " have a nice day!" << endl;		// you need to overload << for the KString

    if (k1 =="Scott")								// Should be able to compare a KString with an array of characters 
            cout << "Nice Name" << endl;

    cout << k1.length() << endl;					// Create the function which returns the length of the KString.  Length would be 5 in this example. 
}
```