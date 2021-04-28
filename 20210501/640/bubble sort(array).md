#bubble sort(array)
//OCE122921640
//bubble sort(array)
#include <iostream>
#include <iomanip> //IO manipulation：控制輸出格式
                   //setw()

using namespace std;

void bSort(int *);

int main(void)
{
    int i, j;
    int data[5] = {3,7,5,9,1};
    // [0] [1] [2] [3] [4]
    //  3   5   7   1   9
    //  3   5   1   7   9
    //  3   1   5   7   9
    //  1   3   5   7   9
    for(i=0; i<5; i++)
    {
        cout<<'['<<i<<']';
    }
    cout<<endl;
    bSort(data);

    return 0;
}

void bSort(int data[])
{
    for(int i=0; i<5-1; i++)        //i=0; i<n-1; i++
    {
        for(int j=0; j<5-i-1; j++)  //j=0; j<n-i-1; j++
        {
            if(data[j] > data[j+1])
            {
                swap(data[j],data[j+1]);
            }
        }
        for(int i=0; i<5; i++)
        {
            cout<<setw(3)<<data[i];
        }
        cout<<endl;
    }
}
