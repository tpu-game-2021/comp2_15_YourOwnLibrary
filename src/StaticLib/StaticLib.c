#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include<stdlib.h>
#include<time.h>
#ifdef _OPENMP
#endif
#include <omp.h>

#include "../include/lib_func.h"


void pass_set(int* pass, int num) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < num; i++) {
		pass[i] = rand() % 256;
	}
}

int my_func_int(int *pass, int a,int *correct,int b)
{
	int temp[4]={0};
	int i, j, k, l;

#pragma omp parallel for
	for (i=0; i < 256; i++)
		for (j = 0; j < 256; j++)
			for (k = 0; k < 256; k++)
				for (l = 0; l < 256; l++){
					if (i == correct[0])
						pass[0] = i;
					if (j == correct[1])
						pass[1] = j;
					if (k == correct[2])
						pass[2] = k;
					if (l == correct[3])
						pass[3] = l;
	}
	return 1;
}

bool my_func_bool()
{
	return false;
}

