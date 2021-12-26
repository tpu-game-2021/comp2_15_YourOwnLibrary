#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(ItCanBeFiniishedIn1Second)//1秒以内に少なくとも1回は処理Aが終わる
		{
			Assert::AreNotEqual(0, my_func_int(), L"0以外が返ってくることを想定したテスト");
		}

		TEST_METHOD(ItCanBeFinishedIn10FPS)//10FPS環境で処理Bが1フレーム内で終わる
		{
			Assert::IsTrue(my_func_bool(10), L"true が返ってくることを想定したテスト");
		}

		TEST_METHOD(InvailedValueCheck)//引数が0のときFalseになる
		{
			Assert::IsFalse(my_func_bool(0), L"false が返ってくることを想定したテスト");
		}

	};
}
