#Practice 1-5 Acker(m,n)
//OCE......640
//Practice 1-5 Acker(m,n)
//Acker(1,2)=4
//Try Acker(4,3)=?
//無法算出Acker(4,3)的值
//ref https://en.wikipedia.org/wiki/Ackermann_function
#include <iostream> // cin, cout, endl
#include <iomanip> // setw
#include <new> // new, delete
#include <string> // c_str, length
#include <cstdlib> // strtoul, system
#include <ctime> // clock_t, clock, CLOCKS_PER_SEC
using namespace std;

unsigned long long Acker(int, int);

int main()
{
    int m, n;
    while(1)
    {
        cout<<"Get Acker(m, n) = ?"<<endl;
        cout<<"m = ";
        cin>>m;
        cout<<"n = ";
        cin>>n;
        cout<<"Acker("<<m<<", "<<n<<") = "<<Acker(m,n)<<endl<<endl;
    }
    return 0;
}

unsigned long long Acker(int a, int b)
{
    if(a == 0)
    {
        return b+1;
    }
    else if(b == 0)
    {
        return Acker(a-1,1);
    }
    else
    {
        return Acker(a-1,Acker(a,b-1));
    }
}
