#insert sort(vector)
//OCE122921640
//insert sort(vector)
#include <iostream>
#include <iomanip> //IO manipulation：控制輸出格式
                   //setw()
#include <vector>
using namespace std;

void iSort(vector<int>);

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

    iSort(vec);                                                     //selection sort

    return 0;
}
//0-1-2-3-4-5
//3 6 4 7 1 2
//-----------
//3 6 4 7 1 2
//3 4 6 7 1 2
//3 4 6 7 1 2
//1 3 4 6 7 2
//1 2 3 4 6 7

void iSort(vector<int>)
{
    int n = 1;
    int i;                                      //i是目前要處理的資料idx

    for(i=1; i<vec.size(); i++)                 //i=1; i<n; i++
    {

        int temp = vec[i];                      //先把要處理的資料vec[i]抄寫在temp
        int j = i-1;                            //j是用來指出前1~(i-1)筆資料的idx

        while(temp<vec[j] && j>=0)              //while迴圈將抄寫出來的temp和前1~(i-1)筆資料做比較
        {                                       //若temp小於要比較的值 && j在陣列範圍內(>=0)
            vec[j+1] = vec[j];                  //將vec[j]往後移一位至vec[j+1]
            j--;                                //j不斷的遞減往前檢查
        }                                       //當已經檢查到前1~(i-1)筆資料的盡頭 || 已經沒有比temp還小的資料
        vec[j+1] = temp;                        //就把temp塞回陣列內

        cout<<"第"<<n<<"回排序:";
        for(int i=0; i<vec.size(); i++)
        {
            cout<<setw(3)<<vec[i];
        }
        cout<<endl;
        n++;
    }
}
