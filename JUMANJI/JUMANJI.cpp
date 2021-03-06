// JUMANJI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
	"stdafx.h" is apparenly a reference to pre-compiled version of the standard library
	which is used to save time recompiling the save library over and over again.
*/
#include <iostream> //iostream give us access to cout and cin input and output streams
#include <string> //importing string gives us access to the string object (used for leader var)
//although many compilers include string and iostream by default, it's good practice to include them just in case 

using std::cout;
using std::cin; //This program requires input from the user, hence why cin (c-input) is used
using std::endl;
using std::string;

/*
	Ordinarilly, these variables would be initialized in the same function where they're used,
	giving them a function-wide local scope. However, since I've moved all the cout lines to
	another function, the variables have to have a project-wide scope so they're visible to both.
	Declaring the variables outside of the functions gives them a project-wide scope.
*/
const int GOLD_PIECES = 900; 
/*
	Just like Java, C++ requires all variables to be initialized with a type, but not nesecarily a value.
	const, short for constant, is the C++ equivalent of 'final' in Java. It decalres that the value of this
	variable does not change and all classes refrerence the same memory pointer for the variable.
	Attempting to change a const variable will throw an error. 
*/

int adventurers, killed, survivors;
//Like Java, once a type is declared, any number of variable of the same type can be initialized.
string leader;

/*
	I chose to represent the cout story-telling part of the program as a separate void function
	because it makes no changes to any variables, only prints them out. 
	This function could even be re-written as a static function, which recieves the variables
	from main() and prints out the same output. The advantage of which is that the above 
	declared variables can be converted back to a local scope within main().
	
	One way that C++ differs from Java is that code is initialized and run at the same time, 
	meaning that tellTheStory() has to be declared before main() otherwise the compiler won't
	know that it is a valid function when main tries to call it. In contrast, Java initializes 
	all the variables and function names first before the code is executed so order of functions
	doesn't really matter. 
*/
void tellTheStory() { //Nothing interesting in this code that wasn't explained in the last project
	cout << "\nA brave group of " << adventurers << " set out on a quest ";
	cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
	cout << "The group was led by that ledendary rogue, " << leader << ".\n";
	cout << "\nAlong the ay, a band of marauding ogres ambushed the party. ";
	cout << "All fought bravely under the command of " << leader;
	cout << ", and the ogres were defeated, but at a cost. ";
	string desu = killed == 1 ? " was" : " were"; //makes the verb 'is' singular if only one person died
	cout << "Of the adventurers, " << killed << desu << " vanquished, ";
	cout << "leaving just " << survivors << " in the group.\n";

	cout << "\nThe party was about to give up all hope. ";
	cout << "But while laying the deceased to rest, ";
	cout << "they stumbled upon the buried fortunes. ";
	cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
	cout << leader << " held on the the extra " << (GOLD_PIECES % survivors);
	//The modulo operator, represented by the percent symbol (%), returns the 
	//remainder after division.
	cout << " pieces to keep things fair of course.\n";
}


int main()
{
	//get the information
	cout << "Welcome to Lost Fortune\n\n";
	cout << "Please enter the following for your personalized adventure\n";

	cout << "Enter a number: ";
	cin >> adventurers;
	//This simple use of cin to get a string from the user only works with strings that have no whitespace (such as tabs or spaces) in them.

	cout << "Enter a number, smaller than the first:\t";
	cin >> killed;

	survivors = adventurers - killed;
	//Should be self-explanatory, but out of the initial number of advertures, those who weren't killed are survivors.

	cout << "Enter your last name: ";
	cin >> leader;

	tellTheStory(); //Calls the void function tellTheStory(), whose job is to print out the JUMANJI story using the above set variables

	system("pause");
	return 0;
}