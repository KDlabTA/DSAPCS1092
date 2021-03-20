#Practice 1-4
//OCE......640
//Practice 1-4
//getValue(first, last, n);
//getValue(1, 30, 30)=5
//1~30之間,5^2=25最接近30

#include <iostream> // cin, cout, endl
#include <iomanip> // setw
#include <new> // new, delete
#include <string> // c_str, lengtha
#include <cstdlib> // strtoul, system
#include <ctime> // clock_t, clock, CLOCKS_PER_SEC
using namespace std;

int getValue(int a, int b, int n)
{
    int returnValue;
    int c = (a+b)/2;
    if((c*c <= n) && (n < (c+1)*(c+1)))
        returnValue = c;
    else if(c*c > n)
        returnValue = getValue(a, c-1, n);
    else
        returnValue = getValue(c+1, b, n);
    return returnValue;
}


int main()
{
    int first, last, n;
    cout<<"input first = ";
    cin>>first;
    cout<<"input last = ";
    cin>>last;
    cout<<"input n = ";
    cin>>n;
    cout<<"The answewr is "<<getValue(first,last,n)<<endl;
    return 0;
}
