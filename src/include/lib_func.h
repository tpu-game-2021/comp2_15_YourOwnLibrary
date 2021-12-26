#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	// 素敵なオレオレライブラリーを作ってみよう！
	int Change_Factorial(int wnum);
	bool Judge_Even_Odd(int wnum);
	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
