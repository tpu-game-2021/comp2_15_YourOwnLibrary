#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/lib_func.h"

int my_func_int(void) //処理Aを実行するのにかかる秒数を計測し、それを1分間に行える回数を返す
{
	double process_sec; //処理にかかった時間
	clock_t now, end; //CPU時間の計測に用いる

	//処理A　開始
	now = clock();
	int i;
	printf("処理Aを行います\n");
	for (i = 0; i < 1000; i++) //.を1000回表示するだけ
	{
		printf(".");
	}
	printf("\n\n");
	//処理A　終了
	end = clock();

	process_sec = ((double)end - (double)now) / CLOCKS_PER_SEC; //CPU時間を実際の秒数に直す

	printf("処理Aにかかった時間 %.4f秒\n", process_sec);

	return (int)(1.0 / process_sec);
}

bool my_func_bool(int fps) //希望するフレームレートの値を引数とし、処理Bを1フレームの時間内に行えるか確かめる
{
	if (fps < 1) //fpsが0以下ならfalse
	{
		return false;
	}

	double flame_sec = 1.0 / (double)fps;; //1フレームの時間
	double process_sec;
	clock_t now, end;

	//処理B　開始
	int i;
	now = clock();
	printf("処理Bを行います\n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ",i * i);
		if (i == 99)
			printf("\n\n");
	}
	//処理B　終了
	end = clock();

	process_sec = ((double)end - (double)now) / CLOCKS_PER_SEC;

	printf("希望するフレームレート %dfps\n", fps);
	printf("1フレームあたり %.4f秒\n", flame_sec);
	printf("処理Bにかかった時間 %.4f秒\n", process_sec);

	if (flame_sec > process_sec)
	{
		return true;
	}
	else
	{
		return false;
	}
}

