// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdlib.h>
#include <stdio.h>
#include "../include/lib_func.h" 

int main()
{
	// ここでオレオレライブラリを使った素敵なサンプルを作る
	//100人のテストの結果をソートする
	const int NUM = 1000;
	item* items=(item*)malloc(sizeof(item) * NUM);

	for (int i= 0; i < NUM; i++)
	{
		items[i].key = rand() % (POINTS + 1);
	}

	printf("ソート前\n");
	
	for (int i = 0; i < NUM; i++){
		printf("%3d\n", items[i].key);
	}

	counting_sort(items, items + NUM);

	printf("\nソート後\n");
	for (int i = 0; i < NUM; i++){
		printf("%3d\n", items[i].key);
	}

	free(items);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
