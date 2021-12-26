#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(基本チェック)
	{
		TEST_METHOD(一要素)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 1, "Taro"));
			Assert::AreEqual("Taro", find(&t, 1), "Taro");

			finalize(&t);
		}
		TEST_METHOD(二要素)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 4, "siro"));
			Assert::IsTrue(add(&t, 3, "saburo"));
			Assert::AreEqual("saburo", find(&t, 3), "3のキーの値はsaburo");
			Assert::AreEqual("siro", find(&t, 4), "4のキーの値はsiro");

			finalize(&t);
		}

		TEST_METHOD(同じ値は上書き)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 1, "itiro"));
			Assert::IsTrue(add(&t, 1, "taro"));
			Assert::AreEqual("taro", find(&t, 1), "1のキーの値はtaro");

			finalize(&t);
		}

		TEST_METHOD(３要素)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 8, "hatiro"));
			Assert::IsTrue(add(&t, 5, "goro"));
			Assert::IsTrue(add(&t, 4, "siro"));
			Assert::AreEqual("siro", find(&t, 4), "6のキーの値はHello");
			Assert::AreEqual("hatiro", find(&t, 8), "7のキーの値はworld");
			Assert::AreEqual("goro", find(&t, 5), "8のキーの値は!");

			finalize(&t);
		}

		TEST_METHOD(追加順を入れ替えても同じ結果)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 4, "siro"));
			Assert::IsTrue(add(&t, 8, "hatiro"));
			Assert::IsTrue(add(&t, 5, "goro"));
			Assert::AreEqual("siro", find(&t, 4), "6のキーの値はHello");
			Assert::AreEqual("hatiro", find(&t, 8), "7のキーの値はworld");
			Assert::AreEqual("goro", find(&t, 5), "8のキーの値は!");

			finalize(&t);
		}
	};
	TEST_CLASS(品質チェック)
	{
		TEST_METHOD(NULLチェック)
		{
			initialize(NULL);
			finalize(NULL);

			tree t;
			initialize(&t);
			Assert::IsNull(find(&t, -1000), (const wchar_t*)("何も登録していなければ検索しても何も得られない"));
			finalize(&t);
		}

		TEST_METHOD(異なる要素)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 1, "hanako"));
			Assert::IsNull(find(&t, 0), (const wchar_t*)("存在しないキーを検索しても何も得られない"));

			finalize(&t);
		}

		TEST_METHOD(大量の要素)
		{
			tree t;

			initialize(&t);
			const int NUM = 10000;
			for (int i = 0; i < NUM; i++) {
				char c[2] = { 'a' + (i % 26) };
				add(&t, i, c);
			}

			for (int i = 0; i < NUM; i++) {
				Assert::AreEqual((char)('a' + (i % 26)), *find(&t, i), (const wchar_t*)("周期的にアルファベットが入出てくるはず"));
			}

			finalize(&t);
		}

		TEST_METHOD(２度の解放)
		{
			tree t;

			initialize(&t);
			Assert::IsTrue(add(&t, 2, "Release twice"));
			finalize(&t);
			finalize(&t);
		}
	};
	TEST_CLASS(ソートチェック)
	{
		TEST_METHOD(３要素で入れ替え)
		{
			tree t;
			item items[3] = {
				{4, "siro"},
				{8, "hatiro"},
				{5,"goro"},
			};
			t = tree_sort(items, items + sizeof(items) / sizeof(item));
			Assert::AreEqual("siro", items[0].name);
			Assert::AreEqual("goro", items[1].name);
			Assert::AreEqual("hatiro", items[2].name);
			Assert::AreEqual("siro", find(&t, 4), "4のキーの値はsiro");
			Assert::AreEqual("hatiro", find(&t, 8), "8のキーの値はhatiro");
			Assert::AreEqual("goro", find(&t, 5), "5のキーの値はgoro");
			finalize(&t);
		}
	};
};


