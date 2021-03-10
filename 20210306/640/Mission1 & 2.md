# Mission1 & 2
//OCE......640
#include <iostream> // cin, cout, endl
#include <iomanip> // setw
#include <new> // new, delete
#include <string> // c_str, length
#include <cstdlib> // strtoul, system
#include <ctime> // clock_t, clock, CLOCKS_PER_SEC
using namespace std;

//int anArray[3] = {1, 2, 3};

void printArr(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<setw(2)<<a[i];
    }
    cout<<endl;
}

int n=0;//陣列大小
int k=0;//[序號]
int L=0;//遞迴呼叫次數

void Permutation(int anArray[], int l, int r)//l:左邊的index,r:右邊的index
{
    L++;
    if(l == r)//base case
    {
        k++;
        cout<<"["<<k<<"]";//[序號]
        printArr(anArray, n);
        return;
    }
    else
    {
        for(int i=l; i<=r; i++)
        {
            swap(anArray[l], anArray[i]);//陣列中(r-l+1)個元素輪流固定當頭
                Permutation(anArray, l+1, r);//後面的(r-l)個元素進行下一層的遞迴呼叫
            swap(anArray[l], anArray[i]);//恢復原狀進行下一個迴圈
        }
    }
}

int main()
{
    int command = 0; // user command
    do
    { int N, M;
    cout << endl << "** Permutation Generator **";
    cout << endl << "* 0. Quit                 *";
    cout << endl << "* 1. N numbers from 1..N  *";
    cout << endl << "* 2. M numbers from input *";
    cout << endl << "***************************";
    cout << endl << "Input a choice(0, 1, 2): ";
    cin >> command; // get a command
    switch (command)
        {
            case 0: break;
            case 1:
            {
                cout<<"Input a number: ";
                cin>>n;
                //int cT = clock(); // start timer
                int anArray[n];
                for(int i=0; i<n; i++)
                {
                    anArray[i] = i+1;
                }
                Permutation(anArray, 0,n-1);
                cout<<"Mission 1: "<<k<<" permutations"<<endl;
                cout<<"L = "<<L<<endl;
                k = 0;//序號歸零
                //cT = clock() - cT; // stop timer
                //cout << "T = " << (float)cT * 1000 / CLOCKS_PER_SEC << " ms" << endl;
                break;
            }
            case 2:
            {
                cout<<"Input a number: ";
                cin>>n;
                int anArray[n];
                for(int i=0; i<n; i++)
                {
                    cin>>anArray[i];
                }
                //printArr(anArray, n);
                int cT = clock(); // start timer
                Permutation(anArray, 0,n-1);
                cout<<"Mission 2: "<<k<<" permutations"<<endl;
                cout<<"L = "<<L<<endl;
                k = 0;//序號歸零
                cT = clock() - cT; // stop timer
                cout << "T = " << (float)cT * 1000 / CLOCKS_PER_SEC << " ms" << endl;
                break;
            }

            default: cout << endl << "Command does not exist!" << endl;
        } // end switch
     }
     while (command != 0); // '0': stop the program
     system("pause"); // pause the display
     return 0;
}
