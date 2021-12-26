#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include <string.h>

#include "../include/lib_func.h"


void initialize(tree* t)
{
	if (t == NULL) return;

	t->root = NULL;
}

static void release_recursive(node* n)
{
	if (n == NULL) return;

	if (n->right!=NULL) {
		release_recursive(n->right);
		n -> right = NULL;
	}

	if (n->left != NULL) {
		release_recursive(n->left);
		n -> left = NULL;
	}

	free(n);
}

void finalize(tree* t)
{
	if (t == NULL) return;

	release_recursive(t->root);
	t->root = NULL;
}

static node* generate(int id, const char* name)
{
	node* p = (node*)malloc(sizeof(node));

	if (p == NULL) return NULL;

	p->id = id;
	int n = (int)strlen(name);
	memcpy(p->name, name, strlen(name) + 1);

	p->left = NULL;
	p->right = NULL;

	return p;
}

bool add(tree* t, int id, const char* name)
{
	if (t == NULL) return false;

	node* p = generate(id, name);
	if (p == NULL) return false;

	if (t -> root == NULL) {
		t->root = p;
		return true;
	}
	node* attention = t -> root;
	while (1)
	{
		if (attention->id == p->id)
		{
			memcpy(attention->name, p->name, sizeof(char) * 256);
			free(p);
			return true;
		}
		else if (attention->id > p->id) {
			if (attention->left == NULL) {
				attention->left = p;
				return true;
			}
			attention = attention->left;
		}
		else{
			if (attention->right == NULL) {
				attention->right = p;
				return true;
			}
			attention = attention->right;
		}
	}
}

char* find(const tree* t, int id)
{
	if (t->root == NULL)
		return NULL;

	node* attention = t->root;
	while (1)
	{
		if (attention == NULL) {
			return NULL;
		}
		else if (attention->id == id) {
			return (attention->name);
		}
		else if (attention->id > id) {
			attention = attention->left;
		}
		else {
			attention = attention->right;
		}
	}
}
void array_add(item* array,node* attention)
{
	int i=0;
	if (attention->left)
		array_add(array, attention->left);
	while (1) {
		if (array[i].id == NULL) {
			array[i].id = attention->id;
			strcpy_s(array[i].name, 256, attention->name);
			break;
		}
			i++;
	}
	if (attention->right)
		array_add(array, attention->right);
}
tree tree_sort(item* begin, item* end)
{
	int i;
	tree t;
	initialize(&t);
	for (i = 0; i < end - begin; i++)
	{
		add(&t, begin[i].id, begin[i].name);
	}
	item* array;
	array = (item*)malloc((sizeof(item) * (end - begin)));
	for (i = 0; i < end - begin; i++)
	{
		array[i].id = NULL;
	}
	array_add(array,t.root);
	for (i = 0; i < end - begin; i++)
	{
		begin[i].id = array[i].id;
		strcpy_s(begin[i].name,256, array[i].name);
	}
	free(array);
	return t;
}