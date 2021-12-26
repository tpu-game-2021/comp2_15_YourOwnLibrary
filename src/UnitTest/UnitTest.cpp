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
			float start = 0,goal = 100,tweenSpd = 0.1f,temp = 0;

			Assert::IsFalse(ValueTween(start, goal, &tweenSpd, &temp, 1), L"false が返ってくることを想定したテスト");

			Assert::IsTrue(ValueTween(start, goal, &tweenSpd, &temp, 0), L"true が返ってくることを想定したテスト");
		}
	};
}
