#pragma once // インクルードガード

#include <stdbool.h>

//関数の定義みたいな場所

//補完のタイプ
typedef enum
{
	Linear, //線型補完
	Sine, //三角関数のサインで補完 未実装
}TweenType;

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	// 素敵なオレオレライブラリーを作ってみよう！

	//初期値,目標値,補完の方法
	bool ValueTween(float start, float goal, float *tweenSpd, float *temp, float setType);


	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
