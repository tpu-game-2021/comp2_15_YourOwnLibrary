#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" 
{

#endif

	// 素敵なオレオレライブラリーを作ってみよう！
	int a, b;

	int my_func_int(a);

	
	typedef struct item_
	{
		unsigned int key;
		char letter[5];
	}item;

	
	bool my_func_bool(item* begin, const item* end);

	



	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
