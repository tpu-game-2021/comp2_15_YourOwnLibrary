#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"

//定義した関数の処理の実装

bool ValueTween(float start, float goal, float *tweenSpd, float *temp, float setType)
{
	//Linear以外未実装なので
	if (setType != 0)
	{
		return false;
	}

	//tempは現在のスピード

	//Linear
	if (setType == 0)
	{
		//*temp = (1 - *tweenSpd) * start + *tweenSpd * goal;
		*temp = ((1 - *tweenSpd) * start) + (*tweenSpd * goal);
		*tweenSpd += 0.1f;
	}

	return true;
}

