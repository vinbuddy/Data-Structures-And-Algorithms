/*
	Họ tên: Huỳnh Thế Vinh - 2001210660
	Lớp: 
	Tiết: 1-5 -> ST4
*/
#ifndef DSLKD_Baihat_h
#define DSLKD_Baihat_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct BaiHat
{
	char tenBH[51], tenTG[31], tenCS[31];
	unsigned int thoiGian;
};

typedef BaiHat ItemType;

void nhapTTBaiHat(ItemType& x);
void xuatTTBaiHat(ItemType x);


#endif