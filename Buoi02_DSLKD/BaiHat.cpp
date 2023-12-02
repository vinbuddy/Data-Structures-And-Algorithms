#include "BaiHat.h"

void nhapTTBaiHat(ItemType& x);
void xuatTTBaiHat(ItemType x) {
	printf("%-30s%s-30s%-30s%10d", x.tenBH, x.tenTG, x.tenCS, x.thoiGian);
}
