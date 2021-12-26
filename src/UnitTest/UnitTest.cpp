#include "pch.h"
#include <chrono>
#include <random>
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(基本確認)
	{
	public:
		_CrtMemState sStartMemState;
	public:
		TEST_METHOD_INITIALIZE(Initialize)
		{
#ifdef _DEBUG
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
			_CrtMemCheckpoint(&sStartMemState);
#endif
		}
		TEST_METHOD_CLEANUP(Cleanup)
		{
#ifdef _DEBUG
			_CrtMemState endMemState, diffMemState;
			_CrtMemCheckpoint(&endMemState);
			if (_CrtMemDifference(&diffMemState, &sStartMemState, &endMemState))
			{
				_CrtMemDumpStatistics(&diffMemState);
				Assert::Fail(L"Memory Leaks!");
			}
#endif
		}

	public:

		TEST_METHOD(一要素はそのまま)
		{
			item items[1] = { {1, "ハナコ"} };
			Assert::IsTrue(counting_sort(items, items + sizeof(items) / sizeof(item)));
			Assert::AreEqual("ハナコ", items[0].value);

		}

		TEST_METHOD(２要素でそのまま)
		{
			item items[2] = {
				{2, "ハナコ"},
				{3, "タロウ"},
			};
			Assert::IsTrue(counting_sort(items, items + sizeof(items) / sizeof(item)));
			Assert::AreEqual("ハナコ", items[0].value);
			Assert::AreEqual("タロウ", items[1].value);
		}

		TEST_METHOD(２要素で入れ替え)
		{
			item items[2] = {
				{3, "タロウ"},
				{2, "ハナコ"},
			};
			Assert::IsTrue(counting_sort(items, items + sizeof(items) / sizeof(item)));
			Assert::AreEqual("ハナコ", items[0].value);
			Assert::AreEqual("タロウ", items[1].value);
		}
	};

	TEST_CLASS(品質確認)
	{
	public:
		_CrtMemState sStartMemState;
	public:
		TEST_METHOD_INITIALIZE(Initialize)
		{
#ifdef _DEBUG
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
			_CrtMemCheckpoint(&sStartMemState);
#endif
		}
		TEST_METHOD_CLEANUP(Cleanup)
		{
#ifdef _DEBUG
			_CrtMemState endMemState, diffMemState;
			_CrtMemCheckpoint(&endMemState);
			if (_CrtMemDifference(&diffMemState, &sStartMemState, &endMemState))
			{
				_CrtMemDumpStatistics(&diffMemState);
				Assert::Fail(L"Memory Leaks!");
			}
#endif
		}

		TEST_METHOD(NULLは帰り値がfalse)
		{
			item items[1];
			Assert::IsFalse(counting_sort(NULL, items));
			Assert::IsFalse(counting_sort(items, NULL));
		}

		TEST_METHOD(endのアドレスが小さいのはダメ)
		{
			item items[1];
			Assert::IsFalse(counting_sort(items + sizeof(items) / sizeof(item), items));
		}

		TEST_METHOD(ランダムな値のたくさんの要素を入れ替え)
		{
			const int NUM = 10000;
			item* items = (item*)malloc(sizeof(item) * NUM);
			if (NULL == items) { Assert::Fail(); return; }

			for (int i = 0; i < NUM; i++) {
				items[i].key = rand() % POINTS;

				sprintf_s(items[i].value, 256, "%d", i);
			}

			Assert::IsTrue(counting_sort(items, items + NUM));

			for (int i = 0; i < NUM; i++) {
				char buf[256];
				sprintf_s(buf, 256, "%d", NUM - i - 1);
				Assert::AreEqual(buf, items[i].value);
			}

			free(items);
		}
	};
}