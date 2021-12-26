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
			int val1 = 0;
			int val2 = 0;
			Assert::AreEqual(val1, my_func_int());
		}

		TEST_METHOD(TestMethod2)
		{
			int val1 = 0;
			int val2 = 1;
			Assert::AreEqual(val1, my_func_int());
		}

		TEST_METHOD(TestMethod3)
		{
			bool val1 = 0;
			bool val2 = 1;
			Assert::IsTrue(my_func_bool());
		}
	};
}
