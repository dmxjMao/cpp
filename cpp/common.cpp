#pragma once

#include "common.h"

int func_extern()
{
	return 7 * 2;
}

/*
在cpp中声明const避免了一份臃肿的.h，
extern-》在其他地方extern声明一下就能用了;
*/
extern const int bufsize = func_extern();

void func_declear()
{
	int i = 1024, *p = &i, &r = i;
	int **ppi = &p; //指针的指针
	int *&pr = p; //指针的引用

	/*
	静态存储区：静态数据、全局数据和常量（只读）；
	栈：局部、临时变量；
	堆：动态分配的内存；
	*/
	char* pstr = "hello";
	//pstr[2] = 'A'; //pstr在栈中，但pstr[2]在静态存储区中（只读）

}

