#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(int型品質確認)
	{
	public:
		
		TEST_METHOD(５の階乗を求める)
		{	
			Assert::AreEqual(120, Change_Factorial(5));
		}

		TEST_METHOD(１２の階乗を求める)
		{	
			Assert::AreEqual(479001600, Change_Factorial(12));
		}
		TEST_METHOD(入力された値が13以上なら－1を返す)
		{
			Assert::AreEqual(-1, Change_Factorial(13));
		}
		TEST_METHOD(入力された値が0未満なら－1を返す)
		{
			Assert::AreEqual(-1, Change_Factorial(-2));
		}
	};

	TEST_CLASS(bool型品質確認)
	{
	public:

		TEST_METHOD(入力された値が偶数であるか)
		{
			Assert::AreEqual(true, Judge_Even_Odd(2));
		}

		TEST_METHOD(入力された値が奇数であるか)
		{
			Assert::AreEqual(false, Judge_Even_Odd(1));
		}




	};

}
