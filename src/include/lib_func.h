#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	// 素敵なオレオレライブラリーを作ってみよう！

	int my_func_int();

	bool my_func_bool();
	//Val2はval1の倍数ですか？
	bool is_same(int val1, int val2);
	// val1 から val3 の任意の組み合わせで値の和sumの倍数になる組み合わせは何個ありますか？
	int calc_BAY_3(int sum, int val1, int val2, int val3);

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
