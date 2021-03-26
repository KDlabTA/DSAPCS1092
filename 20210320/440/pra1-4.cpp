#include <iostream>															        
#include <iomanip>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;															

int getValue(int first, int last, int n);

int main()
{
  cout << getValue(1, 30, 30) << endl;
  return 0;	
}

int getValue(int a, int b, int n)
{
	int returnValue;
	cout << "Enter:a =" << a << "b = " << b << endl;
	int c = (a + b) / 2;
	if( (c * c <= n) && (n < (c + 1)*(c + 1)) )
	  returnValue = c;
	else if(c * c > n)
	  returnValue = getValue(a, c - 1, n);
	else
	  returnValue = getValue(c + 1, b, n);
	cout << "Leave:a =" << a << "b = " << b << endl;
	return returnValue;
}
