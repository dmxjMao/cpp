#pragma once

#include "common.h"
#include <stdexcept>


int help_extern()
{
	return 7 * 2;
}

/*
在cpp中声明const避免了一份臃肿的.h，
extern-》在其他地方extern声明一下就能用了;
*/
extern const int bufsize = help_extern();

void func_declear()
{
	int i = 1024, *p = &i, &r = i;
	int **ppi = &p; //指针的指针
	int *&pr = p; //指针的引用
	//复杂声明：内->外，右->左
	//int* n[10]; //10个int*
	//int(*pn)[10]; //一个*
	//int(*pf(int i))[10]; //函数指针返回一个*，指向int[10]


	/*
	静态存储区：静态数据、全局数据和常量（只读）；
	栈：局部、临时变量；
	堆：动态分配的内存；
	*/
	char* pstr = "hello";
	//pstr[2] = 'A'; //pstr在栈中，但pstr[2]在静态存储区中（只读）

	/*
	左值：对象的身份， =, [], 解引用, 前++ / --等表达式，变量；
	右值：对象的值，算术，关系，位运算，后++ / --，取地址&p；
	*/


	int* const pcur = &i; //pcur一直指向i
	const int* const pip = &i;
	/*
	顶层const：指针本身是常量；底层const：所指对象是const；
	const int i = 32;顶层；const int& r = ci;底层；
	auto让编译器判断类型；忽略顶层const，手动加const、引用；
	decltyp(变量) 不忽略顶层const；decltype((表达式)) 得引用类型；
	decltype(表达式) 求值结果是左值得引用类型，右值就是结果类型；
	decltype(fun)* 函数指针；
	*/

	using pf = bool(*)(int*, int);
	typedef bool(*pf)(int*, int);
	//typedef decltype(func)* pf; 
}

void help_coding_style()
{
	/*
	编程风格
	.h发生了变化，依赖就要重编。
	|-	前置声明代替#include；
	  -	.h少包含using；
	  -	文件包含顺序：
		  -	同名.h		
		  -	c系统文件
		  -	c++系统文件
		  -	其它库文件
		  -	本项目内文件
	|-	类的设计
		形参加const；&
		inline（.h）、static
		类中的public/protected/private是决定派生类/外界能不能访问；继承方式是决定父类中方法或属性在子类中的访控


	*/
}


void func_cast()
{
	//static_cast：使编译不报错；
	//const_cast
	//reinterpret_cast：位模式上类型的重解释；
	//dynamic_cast
}


void func_try()
{
	cbook b1, b2;
	if (b1.isbn() != b2.isbn()) {
		throw std::runtime_error( "bad isbn!");
	}

	/*
	<exception>, <stdexcept>
	*/
	try{

	}catch (const std::exception&)
	{

	}
}

cbook::cbook(std::istream& is)
{
	read(is, *this);
}

inline //类内隐式，类外显式
cbook& cbook::combine(const cbook& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}


double cbook::rate(int r)
{
	return r*3.14;
}

double cbook::exterRate = rate(3);

cbook add(const cbook& lhs, const cbook& rhs)
{
	cbook sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::ostream& print(std::ostream& os, cbook& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

std::istream& read(std::istream& is, cbook& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}


