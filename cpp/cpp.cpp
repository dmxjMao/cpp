// cpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "common.h"
using namespace std;

int main()
{
	//char* p = "hello";
	//p[2] = 'A';

	//extern const int bufsize;
	//cout << bufsize << endl;

	cbook b1;
	string str = "123";
	b1.combine(str);
	//b1.combine(cin);

    return 0;
}

