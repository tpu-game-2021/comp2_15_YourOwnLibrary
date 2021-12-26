#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(基本確認)
	{
	public:
		
		TEST_METHOD(一文字母音一つ)
		{
			char sentence[] = "a";
			Assert::AreEqual(1, my_func_int(sentence), L"1が返ってくることを想定したテスト");
		}

		TEST_METHOD(一文字子音一つ)
		{
			char sentence[] = "ka";
			Assert::AreEqual(0, my_func_int(sentence), L"0が返ってくることを想定したテスト");
		}

		TEST_METHOD(二文字母音二つ)
		{
			char sentence[] = "ai";
			Assert::AreEqual(2, my_func_int(sentence), L"2が返ってくることを想定したテスト");
		}

		TEST_METHOD(二文字母音一つ)
		{
			char sentence[] = "aka";
			Assert::AreEqual(1, my_func_int(sentence), L"1が返ってくることを想定したテスト");
		}

		TEST_METHOD(二文字子音二つ)
		{
			char sentence[] = "kaki";
			Assert::AreEqual(0, my_func_int(sentence), L"0が返ってくることを想定したテスト");
		}
	};
}
