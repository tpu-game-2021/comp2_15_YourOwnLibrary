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
	};
}
