# Writing a String Backward
//OCE......640
#include <iostream>
#include <string>

using namespace std;
void writeBackward(string s);

int main()
{
    string s;
    cout <<"Please enter a string : ";
    cin >>s;
    int length = s.size();
    writeBackward(s);
    return 0;
}

void writeBackward(string s)
{
    int length = s.size();
    if(length > 0)
    {
        cout << s.substr(length - 1, 1);
        writeBackward(s.substr(0, length -1));
    }
}
