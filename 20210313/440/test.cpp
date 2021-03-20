//*********************** ************************************************************************/
// Ref. 1: Non-recursive Permutation Function Wu, Yi-Hung@ICE.CYCU    2021
// Please fill the required code on your own to make it work.
//************************************************************************************************/
#include <iostream>															        //必要標頭檔, 勿移除！
#include <iomanip>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;																// 標準函式庫的命名空間, 勿移除！
#define OUTPUT_NO   1000															// 輸出筆數的批次單位 

// (1) 填入下方函數所需的參數列可使編譯成功 

void solveF(unsigned long);																		// 任務一

unsigned long getN(int, unsigned long);																// 輸入指定範圍內的一個整數 
bool openData(int);																	// 動態配置二個陣列的空間 
void PermutationN( int);																// 任務二
void outputSeries(void);															// 輸出一筆結果 
void closeData(void);																// 釋放動態陣列的空間 
// 以上是N個相異數列的非遞迴函式宣告。

bool            *used = NULL;														// 表示是否使用的布林值 
int             *ans = NULL;														// 紀錄目前的一筆結果 
unsigned long   N, num, last;
// 以上是全域變數

int main(void)
{   int     command = 0;													   		// 操作指令
// ---------------------- 操作介面 ----------------------
    do {    num = 0;
            last = 1;
            cout << endl << "***** 指令介面 *****";
            cout << endl << "* 0. 終止程式      *";
            cout << endl << "* 1. 計算指定數列  *";
            cout << endl << "* 2. 各種相異排列  *";
            cout << endl << "********************";
			cout << endl << "Input a command(0, 1, 2): ";
	    	cin >> command;															//嘗試讀取操作指令
            switch (command)
			{	case 0: break;
			    case 1: N = getN(0, 999999999);                                 	// 取得輸入整數N值
                        solveF(N);													// 任務一
                        break;
			    case 2:	// 列舉從1,2,3..n個不同數字形成的所有「相異」數列
                        N = getN(2, 12);                                        	// 取得輸入整數N值
                        for (int i = 2; i <= N; i++)
                            last *= i;												// 排列總數
                        if (openData(N))                                      		// 建立暫存資訊的陣列
                            PermutationN(N);										// 任務二
                        closeData();                                             	// 釋放暫存資訊的空間
                        break;
                default: cout << endl << "Command does not exist!" << endl;
			}	// end switch
    } while (command != 0); 													 	// 指令'0': 結束主程式
	system("pause");																// 暫停畫面
    return 0;
}	//主程序結尾
//**************************************************************************************************************************/

void solveF(unsigned long value)
{   unsigned long sum;

    cout << endl << "Output: ";
    while (value / 10)																// 不只是單一的個位數字 
    {
        cout << value << ", ";
        sum = 0;
        while (value > 0)
        { 
		  // (2) 填寫下方二行敘述可完成任務一 
             sum = sum + (value % 10);																		// 加入最右側的一個數字 
             value = (value / 10);																		// 去掉最右側的一個數字 
        }   // end inner-while
        value = sum;																// 本回合的加總數字 
    }   // end outer-while
    cout << value << endl;
}   // end solveF
//**************************************************************************************************************************/

unsigned long getN(int minM, unsigned long maxM)
{   unsigned long   M;
    string          inputS;
    bool            isNum;

    do {
        cout << endl << "Input a number: ";
        cin >> inputS;
        isNum = true;
        for (int i = 0; i < inputS.length(); i++)
// (3) 填寫下方二行if敘述的條件可完成此函數 
            if ( inputS[i] < '0' || inputS[i] > '9' )													// 在'0'~'9'範圍之外就是非數字 
                isNum = false;
        if (!isNum)
            continue;
        M = strtoul(inputS.c_str(), NULL, 10);										// 將字串轉存成長整數 
        if ( M >= minM && M <= maxM )											// 確認數字 
            break;																	// 在限制範圍內才算完成 
        else
            cout << endl << "### The number must be in [" << minM << "," << maxM << "] ###" << endl;
    } while (true);   // end do-while
    return M;										                           	
}   // end getM

bool openData(int arraySize)
{   try {
	// (4) 填寫下方二行敘述可完成ans變數的動態配置和給定初始值 

        used = new bool [arraySize];												// 動態配置陣列存布林值
        ans = new int [arraySize];													// 動態配置陣列存數字
        for (int i = 0; i < arraySize; i++)
        {   used[i] = false;														// 預設值表示尚未使用 
            ans[i] = 0;																// 預設值0代表目前都放入數字1
        }   // end for
    }	// end try
    catch (std::bad_alloc& ba)														// 配置空間失敗
    {   std::cerr << endl << "bad_alloc caught: " << ba.what() << endl;
        return false;
    }   // end catch
    return true; 
}   // end openData

void PermutationN(int N)
{   int level = 0, start = 0;

        ans[level] = start;															// 第一個位置從0開始放，代表數字1
        used[start] = true;															// 紀錄位置0代表數字1已放入ans
        level++;																	// 右移到下一個位置
        do
        {   if (level < N)															// 尚未達到指定長度
            {
                for (int i = 0; i < N; i++)											// 依序選擇下一個數字
                    if (!used[i])													// 只限尚未放入ans的數字
                    {   ans[level] = i;												// 把數字放入目前位置
                        used[i] = true;												// 紀錄數字已放入ans 
                        level++;													// 右移到下一個位置
                        break;														// 找到一個數字就跳脫for迴圈 
                    }   // end for-if
            }   // end if
            else																	// 遞增level終究會等於N
            {   bool	backtrack;

                num++;																// 增加一筆結果 

                if ((N <= 6) || (num <= N) || (!(num % OUTPUT_NO)) || (num == last))	// 前幾筆、批次、最後一筆 
                    outputSeries();													// 印出結果
                level--;
                used[ ans[level] ] = false;                                      	// 最右側的一個數字恢復成可用 
                backtrack = true;													// 開始由右向左退回 
                while ((level > 0) && (backtrack))
                {   level--;
                    used[ans[level]] = false;                             			// 目前的數字恢復成可用 
                    for (int i = ans[level] + 1; i < N; i++)              			// 選擇目前數字之後的可用數字
                        if (!used[i])												// 類似前述步驟 
                        {   ans[level] = i;												// 把數字放入目前位置
                            used[i] = true;												// 紀錄數字已放入ans 
                            level++;   
	                                                                                 // (5) 填寫此處敘述可完成任務二 
                            backtrack = false;										// 找到一個就跳出迴圈 
                            break;
                        }   // end for-if            }   // end else
                }   // end inner-while
            }   // end else
        } while (level); // end do-while
}   // end PermutationN

void outputSeries(void)
{
    cout << "[" << num << "]";														// 目前筆數 
    for (int i = 0; i < N; i++)
        cout << " " << ans[i] + 1;													// 從0開始的索引需要加一 
    cout << endl;
}   // end outputSeries

void closeData()
{   delete [] used;																	// 釋放動態配置的空間 
	delete [] ans;
}   // end closeData

//**************************************************************************************************************************/
// 以上是N個相異數列的非遞迴函式
//**************************************************************************************************************************/
