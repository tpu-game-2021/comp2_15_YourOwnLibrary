#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	// 素敵なオレオレライブラリーを作ってみよう！
	typedef struct item_
	{
		unsigned int key;
		char value[256];
	}item;

	bool counting_sort(item* begin, const item* end);

	#define POINTS 10
	
	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
