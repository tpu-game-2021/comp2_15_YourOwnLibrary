#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(0, my_func_int(), L"0が返ってくることを想定したテスト");
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::IsTrue(my_func_bool(), L"true が返ってくることを想定したテスト");
		}

		TEST_METHOD(TestIsSame0_0)
		{
			int val1 = 5;
			int val2 = 25;
			Assert::AreEqual(true, is_same(val1, val2));
		}

		TEST_METHOD(TestIsNotSame0_1)
		{
			int val1 = 4;
			int val2 = 99;
			Assert::AreEqual(false, is_same(val1, val2));
		}

		TEST_METHOD(TestIsSame1_1)
		{
			int val1 = 7;
			int val2 = 49;
			Assert::AreEqual(true, is_same(val1, val2));
		}

	};

	TEST_CLASS(UnitTestCalcCombinations3)
	{
	public:

		TEST_METHOD(TestCalcCombinations3_1111)
		{
			Assert::AreEqual(3, calc_BAY_3(2, 1, 1, 1));
		}

		TEST_METHOD(TestCalcCombinations3_2111)
		{
			Assert::AreEqual(1, calc_BAY_3(3, 1, 1, 1));
		}

		TEST_METHOD(TestCalcCombinations3_3111)
		{
			Assert::AreEqual(3, calc_BAY_3(4, 2, 2, 2));
		}

		TEST_METHOD(TestCalcCombinations3_3123)
		{
			Assert::AreEqual(2, calc_BAY_3(5, 3, 2, 3));
		}

	};
}
