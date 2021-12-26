// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>
#include "../include/lib_func.h"

int main()
{
	int knum = 4;

	Change_Factorial(knum);
    Judge_Even_Odd(knum);

	printf("%dの階乗は%d\n", knum, Change_Factorial(knum));
	printf("%dは%s",knum, Judge_Even_Odd(knum) ?"偶数":"奇数");
	return 0;
}

