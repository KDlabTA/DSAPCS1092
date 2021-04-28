#selection sort(vector)
//OCE122921640
//selection sort(vector)
#include <iostream>
#include <iomanip> //IO manipulation：控制輸出格式
                   //setw()
#include <vector>
using namespace std;

void sSort(vector<int>);

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

    sSort(vec);                                                     //selection sort

    return 0;
}

void sSort(vector<int>)
{
    int n = 1;
    bool isSwap = true;
    for(int i=0; i<vec.size()-1; i++)                 //i=0; i<n-1; i++
    {
        isSwap = false;
        int min_idx = i;                              //先把第[i]個記為最小的位置第[min_idx]
        for(int j=i+1; j<vec.size(); j++)             //j=i+1; j<n; j++
        {
            if(vec[min_idx] > vec[j])                 //若後面第[j]個比原先最小的還小
            {
                min_idx = j;                          //第[j]個位置記為最小的位置第[min_idx]
                isSwap = true;                        //若有找到則改為true
            }
        }
        swap(vec[min_idx],vec[i]);                    //swap
        if(!isSwap)                                   //若沒有交換則繼續下一個迴圈
            continue;
        cout<<"第"<<n<<"回排序:";
        for(int i=0; i<vec.size(); i++)               //有swap才印出來
        {
            cout<<setw(3)<<vec[i];
        }
        cout<<endl;
        n++;
    }
}
