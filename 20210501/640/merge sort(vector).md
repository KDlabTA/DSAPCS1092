#merge sort(vector)
//OCE122921640
//merge sort(vector)
#include <iostream>
#include <iomanip> //IO manipulation：控制輸出格式
                   //https://www.cplusplus.com/reference/iomanip/?kw=iomanip
                   //setw       Set field width (function )
#include <vector>  //https://www.cplusplus.com/reference/vector/vector/
                   //begin      Return iterator to beginning (public member function )
                   //end        Return iterator to end (public member function )
                   //insert     Insert elements (public member function )

using namespace std;
const int Max = 100000;                                             //先定義一個很大的常數 Max 設為 100000

void mSort(vector<int>, int, int);
void Merge(vector<int>, int, int, int);

vector<int> vec;

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

    cout<<"  原始資料:";
    for(int i=0; i<vec.size(); i++)                                 //印出原始資料
    {
            cout<<setw(3)<<vec[i];
    }
    cout<<endl;

    mSort(vec, 0, vec.size()-1);                                    //merge sort

    return 0;
}

void mSort(vector<int>, int first, int last)                        //將一個未排序的陣列進行切割
{
    if(first < last)
    {
        int mid = (first + last)/2;                                 //取出中點mid的idx
        mSort(vec, first, mid);                                     //將前左半段子集合呼叫mSort函數
        mSort(vec, mid+1, last);                                    //將後右半段子集合呼叫mSort函數
        Merge(vec, first, mid, last);                               //將前半段與後半段排序好的兩個子集合進行合併
    }
}

int n = 1;

void Merge(vector<int>, int first, int mid, int last)               //將兩個排序好的子集合進行合併的函數
{
    vector<int> LeftSub(vec.begin()+first, vec.begin()+mid+1);      //左邊子集合
    vector<int> RightSub(vec.begin()+mid+1, vec.begin()+last+1);    //右邊子集合
    LeftSub.insert(LeftSub.end(), Max);                             //在左邊子集合的最後插入Max
    RightSub.insert(RightSub.end(), Max);                           //在右邊子集合的最後插入Max

    int idxLeft = 0;                                                //初始化左邊idx為0
    int idxRight = 0;                                               //初始化右邊idx為0

    for(int i=first; i<=last; i++)                                  //開始比較左右兩邊已經排序好的子集合
    {
        if(LeftSub[idxLeft] <= RightSub[idxRight])                  //若左邊元素<=右邊元素
        {
            vec[i] = LeftSub[idxLeft];                              //把左邊那個比較小的塞回vec
            idxLeft++;                                              //並且更新左邊的idx(右移1位)
        }
        else                                                        //否則(左邊元素>右邊元素)
        {
            vec[i] = RightSub[idxRight];                            //把右邊那個比較小的塞回vec
            idxRight++;                                             //並且更新右邊的idx(右移1位)
        }

    cout<<"第"<<setw(2)<<n<<"回呼叫:";
    for(int i=0; i<vec.size(); i++)
    {
        cout<<setw(3)<<vec[i];
    }
    cout<<endl;
    n++;
    }

}
