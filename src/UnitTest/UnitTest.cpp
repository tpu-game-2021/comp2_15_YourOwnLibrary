#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(NULLだったら0)
		{
			Assert::AreEqual(0, my_func_int(NULL, NULL), L"NULLだったら0");
		}

		TEST_METHOD(同じだったら1)
		{
			Assert::AreEqual(1, my_func_int(1, 1), L"同じだったら1");
		}

		TEST_METHOD(aが大きかったら2)
		{
			Assert::AreEqual(2, my_func_int(2, 1), L"aが大きかったら2");
		}

		TEST_METHOD(bが大きかったら3)
		{
			Assert::AreEqual(3, my_func_int(1, 2), L"bが大きかったら3");
		}

		TEST_METHOD(TestMethod5)
		{
			Assert::IsFalse(my_func_bool(), L"true が返ってくることを想定したテスト");
		}
	};
}
