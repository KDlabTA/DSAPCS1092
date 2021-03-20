#Practice 1-3 computing powers by 3 ways
//OCE......640
//Practice 1-3 computing powers
//iterative function power1
//recursive function power2
//recursive function power3
#include <iostream> // cin, cout, endl
#include <iomanip> // setw
#include <new> // new, delete
#include <string> // c_str, length
#include <cstdlib> // strtoul, system
#include <ctime> // clock_t, clock, CLOCKS_PER_SEC
using namespace std;

int power1(int a, int b)
{
    int result = 1;
    while(b>0)
    {
        result = result * a;
        b--;
    }
    return result;
}

int power2(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else
    {
        return a*power2(a,b-1);
    }
}

int power3(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b%2 == 0)
    {
        return power3(a,b/2)*power3(a,b/2);
    }
    else
    {
        return a*power3(a,b/2)*power3(a,b/2);
    }
}

int main()
{
    int command = 0; // user command
    do
    { int x, n;
    cout << endl << "** Computing Powers **";
    cout << endl << "* 0. Quit            *";
    cout << endl << "* 1. iterative power1*";
    cout << endl << "* 2. recursive power2*";
    cout << endl << "* 3. recursive power3*";
    cout << endl << "**********************";
    cout << endl << "Input a choice(0, 1, 2, 3): ";
    cin >> command; // get a command
    switch (command)
        {
        case 0:break;
        case 1:
            {
                cout<<"compute x^n = ?"<<endl;
                cout<<"input x = ";
                cin>>x;
                cout<<"input n = ";
                cin>>n;
                cout<<x<<"^"<<n<<" = "<<power1(x, n)<<endl;
                break;
            }
        case 2:
            {
                cout<<"compute x^n = ?"<<endl;
                cout<<"input x = ";
                cin>>x;
                cout<<"input n = ";
                cin>>n;
                cout<<x<<"^"<<n<<" = "<<power2(x, n)<<endl;
                break;
            }
        case 3:
            {
                cout<<"compute x^n = ?"<<endl;
                cout<<"input x = ";
                cin>>x;
                cout<<"input n = ";
                cin>>n;
                cout<<x<<"^"<<n<<" = "<<power3(x, n)<<endl;
                break;
            }
        default: cout << endl << "Command does not exist!" << endl;
        }
    }
    while (command != 0); // '0': stop the program
    system("pause"); // pause the display
    return 0;
}
