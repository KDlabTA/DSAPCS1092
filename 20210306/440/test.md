// OCE124828440 賴建億 

#include <iostream>
#include <iomanip> // setw
#include <new> // new, delete
#include <string> // c_str, length
#include <cstdlib> // strtoul, system
#include <ctime> // clock_t, clock, CLOCKS_PER_SEC

using namespace std;

//int getNO( ); // get a number from user
//bool openData( ); // allocate space to keep data
//void closeData( ); // release unused space
//void getNum( ); // get M distinct numbers

int main(void)
{ int command = 0; // user command
 do
 { int N, M;
 cout << endl << "** Permutation Generator **";
 cout << endl << "* 0. Quit *";
 cout << endl << "* 1. N numbers from 1..N *";
 cout << endl << "* 2. M numbers from input *";
 cout << endl << "***************************";
 cout << endl << "Input a choice(0, 1, 2): ";
 cin >> command; // get a command
 switch (command)
 { case 0: break;
 
 case 1: N = getNO( ); // get the permutation length
 if (openData( )) // allocate space to keep data
// Mission One: permutations of N numbers from 1..N
 } // end if
 closeData( ); // release unused space
 break;
 
 case 2: M = getNO( ); // get the permutation length
 if (openData( )) // allocate space to keep data
 { getNum(M); // get M numbers from input
 cT = clock(); // start timer
// Mission Two: permutations of M numbers from input
 cT = clock() - cT; // stop timer
 cout << "T = " << (float)cT * 1000 / CLOCKS_PER_SEC << " ms" << endl;
 } // end if
 closeData(used, ans); // release unused space
 break;
 default: cout << endl << "Command does not exist!" << endl;
 } // end switch
 } while (command != 0); // '0': stop the program
 system("pause"); // pause the display
 return 0;
} // end main

	// your code goes here
	return 0;
}
