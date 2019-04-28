#pragma once

#include <iostream>
#include <string>

struct st_built_in_type
{
	bool b;
	char ch;
	wchar_t wch;	//2
	char16_t ch16;	//2
	char32_t ch32;	//4
	short u16;		//2
	int	i;			//4
	long l;			//4
	long long ll;	//8
	float f;		//4
	double d;		//8
	long double ld;	//8
	//unsigned

	//遍历每个成员？通过地址
};

struct st_built_in_type_short
{
	// 结构体字节对齐
};


class cbook
{
	/*函数能访问private成员了，类内定义隐式内联
	*/
	friend cbook add(const cbook&, const cbook&);
	friend std::ostream& print(std::ostream&, cbook&);
	friend std::istream& read(std::istream&, cbook&);

public:
	/* 类默认提供：
	构造、拷贝构造、拷贝赋值、移动构造、析构
	单参构造，string str="9-1-2"; cbook.combine(str);只允许一步

	*/
	cbook() = default; //类内初始化（不用写实现）
	cbook(const std::string& s) : bookNo(s) {}
	cbook(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	explicit cbook(std::istream& is); //阻止单参构造

	~cbook() = default;

public:
	/* 类型成员，public、private */
	using pos = std::string::size_type;
	//typedef std::string::size_type pos;

private:
//public:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	/*constexpr只能常量
	*/
	static constexpr double interRate = 1.32;
	static double exterRate; //必须初始化

public:
	//类内定义隐式inline
	std::string isbn() { return bookNo; }
	//constexpr int new_sz() { return 42; } vs2015不支持
	cbook& combine(const cbook&);
	static double rate(int);

private:
	double avg_price() const { //不会改变成员的值
		return units_sold ? revenue / units_sold : 0; 
	}
};
cbook add(const cbook&, const cbook&);
std::ostream& print(std::ostream&, cbook&);
std::istream& read(std::istream&, cbook&);
