// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/lib_func.h"

int main()
{
	int knum = 12;

	Change_Factorial(knum);

	printf("%dの階乗は%d", knum, Change_Factorial(knum));



	return 0;
}

