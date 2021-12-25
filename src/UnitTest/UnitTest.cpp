#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(２と３の数の最小公倍数を求める)
		{
			int Numbers[2] = { 2, 3 };
			Assert::AreEqual(6, my_func_int(Numbers, Numbers + sizeof(Numbers) / sizeof(int)));
		}

		TEST_METHOD(２と－３の数の最小公倍数を求める)
		{
			int Numbers[2] = { 2, -3 };
			Assert::AreEqual(6, my_func_int(Numbers, Numbers + sizeof(Numbers) / sizeof(int)));
		}

		TEST_METHOD(３つ数の最小公倍数を求める)
		{
			int Numbers[3] = { 100, 99, 98 };
			Assert::AreEqual(485100, my_func_int(Numbers, Numbers + sizeof(Numbers) / sizeof(int)));
		}


	public:

		TEST_METHOD(NULLは帰り値が－１)
		{
			int Numbers[1];
			Assert::AreEqual(-1, my_func_int(NULL, Numbers));
			Assert::AreEqual(-1, my_func_int(Numbers, NULL));
		}

		TEST_METHOD(０は帰り値が－１)
		{
			int Numbers[1];
			Assert::AreEqual(-1, my_func_int(0, Numbers));
			Assert::AreEqual(-1, my_func_int(Numbers, 0));
		}

		TEST_METHOD(endのアドレスが小さいのはダメ)
		{
			int Numbers[1];
			Assert::AreEqual(-1, my_func_int(Numbers + sizeof(Numbers) / sizeof(int), Numbers));
		}
	};
}
