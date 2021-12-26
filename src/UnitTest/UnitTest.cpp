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

		TEST_METHOD(素数なら0が返る)
		{
			Assert::AreEqual(0, my_func_int(2));
		}

		TEST_METHOD(素数でなければ1が返る)
		{
			Assert::AreEqual(1, my_func_int(4));
		}
	};
}
