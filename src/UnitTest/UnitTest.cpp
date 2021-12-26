#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
	
		TEST_METHOD(品質確認)
		{
			int num = -1;

			Assert::IsFalse(judge_prime(num));
			Assert::IsFalse(judge_prime_many(num));
		}

		TEST_METHOD(素数なら０が返る)
		{
			Assert::AreEqual(0, judge_prime(2));
		}

		TEST_METHOD(素数でなければ１が返る)
		{
			Assert::AreEqual(1, judge_prime(4));
		}

		TEST_METHOD(大きな数字が出ても問題なく素数判定ができる)
		{
			Assert::AreEqual(1, judge_prime(123456789));
		}

		TEST_METHOD(１までの素数は０個)
		{
			Assert::AreEqual(0, judge_prime_many(1));
		}

		TEST_METHOD(ある値までの数字の中に素数が何個あるか)
		{
			Assert::AreEqual(4, judge_prime_many(10));        // 10までなら4個
			Assert::AreEqual(25, judge_prime_many(100));      // 100までなら25個
			Assert::AreEqual(135, judge_prime_many(765));     // 765までなら135個
			Assert::AreEqual(9592, judge_prime_many(100000)); // 100000までなら9592個
		}
	};
}
