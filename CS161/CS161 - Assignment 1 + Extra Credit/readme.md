# Assignment 1:

- Write the class used to monitor the gas tank in a car.  The gas tank should have two constructors.  One constructor should create a tank that holds twenty gallons.  The other constructor should be passed the size of the tank.  The tank will be empty after creation.  The class will also have a function called fill which should fill up the tank and return the number of gallons filled.  There should be a procedure called used which should take gas out of the tank.  This procedure should be passed the number of gallons used.  The class will also have a function to tell the user if the fuel is getting low.  The fuel is low if there is only 25% of the fuel left.  The last function will tell the user how many gallons are left in the tank.  

Example main program:

`void main() 
{ 
    gastank tank1; 
    gastank tank2(5);

    cout << "Gallons filled tank 1 -> " << tank1.fill() << endl; 
    cout << "Gallons filled tank 2 -> " << tank2.fill() << endl;

    tank1.used(10);

    if (tank1.low()) 
    { 
        cout << "Low fuel light" << endl; 
        cout << "gallons left ->" << tank1.left() << endl; 
    } 
    else 
        cout << "fuel OK";

    tank1.used(6);

  if (tank1.low()) 
    { 
        cout << "Low fuel light" << endl; 
        cout << "gallons left ->" << tank1.left() << endl; 
    } 
    else 
        cout << "fuel OK";

    cout << "Gallons filled tank 1 -> " << tank1.fill() << endl; 
    cout << "Gallons filled tank 2 -> " << tank2.fill() << endl; 
}`
 

Example Output:  
  
Gallons filled tank 1 -> 20  
Gallons filled tank 2 -> 5  
fuel OK  
Low fuel light  
gallons left -> 4  
Gallons filled tank 1 -> 16  
Gallons filled tank 2 -> 0  
