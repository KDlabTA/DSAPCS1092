#quick sort(random pivot)
//choose a random index as value of pivot

//OCE122921640

#include <iostream>
#include <iomanip> //IO manipulation：控制輸出格式
                   //https://www.cplusplus.com/reference/iomanip/?kw=iomanip
                   //setw       Set field width (function )
#include <vector>  //https://www.cplusplus.com/reference/vector/vector/
                   //begin      Return iterator to beginning (public member function )
                   //end        Return iterator to end (public member function )
                   //insert     Insert elements (public member function )
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

using namespace std;

int partQS(vector<int>, int, int);
void qSort(vector<int>, int, int);
void printVec(vector<int>, int, int);

vector<int> vec;
int n = 1;

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

    cout<<"            ";
    for(i=0; i<vec.size(); i++)
    {
        cout<<'['<<i<<']';
    }
    cout<<endl;

    cout<<"未排序資料:";
    for(i=0; i<vec.size(); i++)                       //印出原始資料
    {
            cout<<setw(3)<<vec[i];
    }
    cout<<endl;

    qSort(vec, 0, vec.size()-1);                      //quick sort

    cout<<"------------------------------"<<endl;
    cout<<"排序後資料:";
    for(i=0; i<vec.size(); i++)                       //印出排序資料
    {
            cout<<setw(3)<<vec[i];
    }
    cout<<endl;

    return 0;
}

int partQS(vector<int>, int first, int last)         //將原陣列分割成小於pivot和大於pivot兩個子集合
{                                                    //first最前端idx, last最後端idx
    //隨機指定第k個位置為pivot
    srand( time(NULL) );
    int k = (rand() % (last-first+1))+ first;
    //將第k個位置與第last對調
    swap(vec[k], vec[last]);

    //接下來就是原本的quick sort
    int pivot = vec[last];                           //將最後一個位置設為pivot
    cout<<endl;
    cout<<"********隨機將 "<<vec[last]<<" 設定為pivot********"<<endl;
    int i = first-1;                                 //i為所有小於pivot子集合的最後一個idx
                                                     //開始設為first-1(0-1 = -1)表示有可能所有數都比pivot大
    for(int j=first; j<last; j++)                    //j是欲與pivot比較大小的元素idx
    {
        if(vec[j] < pivot)                           //若比較的vec[j]小於pivot
        {
            i++;                                     //i向右移1位
            cout<<"--------------------------------"<<endl;
            cout<<"左邊最大的 "<<vec[i]<<" 與右邊最小的 "<<vec[j]<<" 交換"<<endl;
            cout<<"--------------------------------"<<endl;
            swap(vec[i], vec[j]);
            printVec(vec, first, last);
        }
    }

    i++;                                             //當原陣列已分割成小於pivot和大於pivot兩個子集合後
                                                     //小於pivot子集合的最後一個idx i向右移移一位
    cout<<"--------------------------------"<<endl;
    cout<<"右邊最小的 "<<vec[i]<<" 與pivot = "<<vec[last]<<" 交換"<<endl;
    cout<<"--------------------------------"<<endl;
    swap(vec[i], vec[last]);                         //將所有大於pivot子集合的第一個idx i 與最後一個pivot的idx=last對調
                                                     //則此時pivot會介在小於pivot和大於pivot兩個子集合中間
    printVec(vec, first, last);

    return i;                                        //回傳此時pivot之idx i
}

void qSort(vector<int>, int first, int last)         //quick sort
{
    int k = 0;
    if(first < last)
    {
        int pivot = partQS(vec, first, last);

        for(int i=first; i<last; i++)                //檢查(元素個數-1)次
        {                                            //由左至右一一比較
            if(vec[i] <= vec[i+1])                   //若左邊元素 <= 右邊元素
            {
                k++;                                 //k++
            }
        }
        if(k == vec.size()-1)                        //當k的值 = (元素個素-1)時
        {                                            //代表該陣列內部元素均已經排序好
            return;                                  //則不須qSort, 跳出函數
        }
        else
        {
            qSort(vec, first, pivot-1);              //對小於pivot的子集合進行quick sort
            qSort(vec, pivot+1, last);               //對大於pivot的子集合進行quick sort
        }
    }
}

void printVec(vector<int>, int first, int last)
{
    cout<<"第"<<setw(2)<<n<<"回swap:";
    for(int i=0; i<vec.size(); i++)
    {
        cout<<setw(3)<<vec[i];
    }
    cout<<endl;
    n++;
}
