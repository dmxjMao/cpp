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

	//����ÿ����Ա��ͨ����ַ
};

struct st_built_in_type_short
{
	// �ṹ���ֽڶ���
};


class cbook
{
	/*�����ܷ���private��Ա�ˣ����ڶ�����ʽ����
	*/
	friend cbook add(const cbook&, const cbook&);
	friend std::ostream& print(std::ostream&, cbook&);
	friend std::istream& read(std::istream&, cbook&);

public:
	/* ��Ĭ���ṩ��
	���졢�������졢������ֵ���ƶ����졢����
	���ι��죬string str="9-1-2"; cbook.combine(str);ֻ����һ��

	*/
	cbook() = default; //���ڳ�ʼ��������дʵ�֣�
	cbook(const std::string& s) : bookNo(s) {}
	cbook(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	explicit cbook(std::istream& is); //��ֹ���ι���

	~cbook() = default;

public:
	/* ���ͳ�Ա��public��private */
	using pos = std::string::size_type;
	//typedef std::string::size_type pos;

private:
//public:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	/*constexprֻ�ܳ���
	*/
	static constexpr double interRate = 1.32;
	static double exterRate; //�����ʼ��

public:
	//���ڶ�����ʽinline
	std::string isbn() { return bookNo; }
	//constexpr int new_sz() { return 42; } vs2015��֧��
	cbook& combine(const cbook&);
	static double rate(int);

private:
	double avg_price() const { //����ı��Ա��ֵ
		return units_sold ? revenue / units_sold : 0; 
	}
};
cbook add(const cbook&, const cbook&);
std::ostream& print(std::ostream&, cbook&);
std::istream& read(std::istream&, cbook&);
