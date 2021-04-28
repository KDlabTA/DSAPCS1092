#bubble sort(vector)
//OCE122921640
//bubble sort(vector)
#include <iostream>
#include <iomanip> //IO manipulation：控制輸出格式
                   //setw()
#include <vector>
using namespace std;

void bSort(vector<int>);

vector <int> vec;

int main(void)
{
    int i, j;
    cout << "Original vector size = " << vec.size() << endl;        //原始vector的大小為0
    int input;
    cout<<"Please input numbers, and input -1 for the end."<<endl;

    while(cin >> input)                                             //while迴圈輸入vector容器
    {
        if(input == -1)                                             //當輸入-1時候跳出迴圈
            break;
        vec.push_back(input);
    }
    cout << "Now vector size = " << vec.size() << endl;             //顯示後來vector裝了幾筆資料

    cout<<"          ";
    for(i=0; i<vec.size(); i++)
    {
        cout<<'['<<i<<']';
    }
    cout<<endl;

    cout<<" 原始資料:";
    for(int i=0; i<vec.size(); i++)                                 //印出原始資料
    {
            cout<<setw(3)<<vec[i];
    }
    cout<<endl;

    bSort(vec);                                                     //bubble sort

    return 0;
}

void bSort(vector<int>)
{
    int n = 1;
    bool isSwap = true;
    for(int i=0; i<vec.size()-1; i++)                   //i=0; i<n-1; i++
    {
        isSwap = false;                                 //一開始設為false
        for(int j=0; j<vec.size()-i-1; j++)             //j=0; j<n-i-1; j++
        {
            if(vec[j] > vec[j+1])                       //若左邊>右邊
            {
                swap(vec[j],vec[j+1]);                  //swap
                isSwap = true;                          //若有交換則改為true
            }
        }
        if(!isSwap)                                     //若沒有交換則跳出迴圈
            break;
        cout<<"第"<<n<<"回排序:";
        for(int i=0; i<vec.size(); i++)                 //有swap才印出來
        {
            cout<<setw(3)<<vec[i];
        }
        cout<<endl;
        n++;
    }
}
