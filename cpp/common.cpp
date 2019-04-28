#pragma once

#include "common.h"
#include <stdexcept>


int help_extern()
{
	return 7 * 2;
}

/*
��cpp������const������һ��ӷ�׵�.h��
extern-���������ط�extern����һ�¾�������;
*/
extern const int bufsize = help_extern();

void func_declear()
{
	int i = 1024, *p = &i, &r = i;
	int **ppi = &p; //ָ���ָ��
	int *&pr = p; //ָ�������
	//������������->�⣬��->��
	//int* n[10]; //10��int*
	//int(*pn)[10]; //һ��*
	//int(*pf(int i))[10]; //����ָ�뷵��һ��*��ָ��int[10]


	/*
	��̬�洢������̬���ݡ�ȫ�����ݺͳ�����ֻ������
	ջ���ֲ�����ʱ������
	�ѣ���̬������ڴ棻
	*/
	char* pstr = "hello";
	//pstr[2] = 'A'; //pstr��ջ�У���pstr[2]�ھ�̬�洢���У�ֻ����

	/*
	��ֵ���������ݣ� =, [], ������, ǰ++ / --�ȱ��ʽ��������
	��ֵ�������ֵ����������ϵ��λ���㣬��++ / --��ȡ��ַ&p��
	*/


	int* const pcur = &i; //pcurһֱָ��i
	const int* const pip = &i;
	/*
	����const��ָ�뱾���ǳ������ײ�const����ָ������const��
	const int i = 32;���㣻const int& r = ci;�ײ㣻
	auto�ñ������ж����ͣ����Զ���const���ֶ���const�����ã�
	decltyp(����) �����Զ���const��decltype((���ʽ)) ���������ͣ�
	decltype(���ʽ) ��ֵ�������ֵ���������ͣ���ֵ���ǽ�����ͣ�
	decltype(fun)* ����ָ�룻
	*/

	using pf = bool(*)(int*, int);
	typedef bool(*pf)(int*, int);
	//typedef decltype(func)* pf; 
}

void help_coding_style()
{
	/*
	��̷��
	.h�����˱仯��������Ҫ�رࡣ
	|-	ǰ����������#include��
	  -	.h�ٰ���using��
	  -	�ļ�����˳��
		  -	ͬ��.h		
		  -	cϵͳ�ļ�
		  -	c++ϵͳ�ļ�
		  -	�������ļ�
		  -	����Ŀ���ļ�
	|-	������
		�βμ�const��&
		inline��.h����static
		���е�public/protected/private�Ǿ���������/����ܲ��ܷ��ʣ��̳з�ʽ�Ǿ��������з����������������еķÿ�


	*/
}


void func_cast()
{
	//static_cast��ʹ���벻����
	//const_cast
	//reinterpret_cast��λģʽ�����͵��ؽ��ͣ�
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

inline //������ʽ��������ʽ
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


