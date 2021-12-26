#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	// 素敵なオレオレライブラリーを作ってみよう！

	typedef struct node_
	{
		node_* left;
		node_* right;
		int id;
		char name[256];
	}node;
	typedef struct item_
	{
		int id;
		char name[256];
	}item;
	typedef struct
	{
		node* root;
	}tree;

	void initialize(tree* t);

	void finalize(tree* t);

	bool add(tree* t, int key, const char* value);

	char* find(const tree* t, int key);

	tree tree_sort(item* begin,item* end);

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
