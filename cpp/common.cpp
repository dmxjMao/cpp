#pragma once

#include "common.h"

int func_extern()
{
	return 7 * 2;
}

/*
��cpp������const������һ��ӷ�׵�.h��
extern-���������ط�extern����һ�¾�������;
*/
extern const int bufsize = func_extern();

void func_declear()
{
	int i = 1024, *p = &i, &r = i;
	int **ppi = &p; //ָ���ָ��
	int *&pr = p; //ָ�������

	/*
	��̬�洢������̬���ݡ�ȫ�����ݺͳ�����ֻ������
	ջ���ֲ�����ʱ������
	�ѣ���̬������ڴ棻
	*/
	char* pstr = "hello";
	//pstr[2] = 'A'; //pstr��ջ�У���pstr[2]�ھ�̬�洢���У�ֻ����

}

