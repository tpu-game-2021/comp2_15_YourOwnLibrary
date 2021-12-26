#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	// 素敵なオレオレライブラリーを作ってみよう！

	int my_func_int(int* pass, int a,int* correct,int b);

	void pass_set(int* pass, int num);

	bool my_func_bool();


	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
