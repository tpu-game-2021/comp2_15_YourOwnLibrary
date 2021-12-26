#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestChange_Factorial)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int wnum = 5;
			Assert::AreEqual(120, Change_Factorial(wnum));
		}

		TEST_METHOD(TestMethod2)
		{
			int wnum = 12;
			Assert::AreEqual(479001600, Change_Factorial(wnum));
		}
		TEST_METHOD(TestMethod3)
		{
			int wnum = 13;
				Assert::AreEqual(-1, Change_Factorial(wnum));
		}
	};
}
