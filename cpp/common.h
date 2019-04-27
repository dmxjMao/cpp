#pragma once

//const int bufsize = 512;

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


