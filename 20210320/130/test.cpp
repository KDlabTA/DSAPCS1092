#include <iostream>	      //必要標頭檔, 勿移除！
#include <stdio.h>
#include <iomanip>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int square(int) ;
int main()
{
	int length;
	int ans;
	
	cout << endl << "Input a length : ";
	cin >> length;
	
	ans = square(length);
	cout << endl << "正方形面積: " <<ans;
	
	return 0;
}
int square (int len)
{
	int x = 0;
	x = len * len;
	
	return x;
 } 
