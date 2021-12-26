// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>
#include "../include/lib_func.h"

int main()
{
	// ここでオレオレライブラリを使った素敵なサンプルを作る
	tree t;
	int input;
	char* result[256];
	initialize(&t);
	item items[5] = {
	{ 4, "siro"},
	{ 5, "goro"},
	{ 1, "taro"},
	{ 2, "jiro"},
	{ 3, "saburo"},
	};
	
	t = tree_sort(items, items + sizeof(items) / sizeof(item));
	for (int i = 0; i < 5; i++)
	{
		printf("%2d : 「%s」\n", items[i].id, items[i].name);
	}
	printf("idを入力してください。");
	scanf_s("%d", &input);
	*result = find(&t, input);
	if (*result != NULL)
		printf("id「%d」は%sです。", input, *result);
	else
		printf("失敗しました。そのidの人はいません。");
	finalize(&t);
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//   1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
