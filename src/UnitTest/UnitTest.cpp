#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"
#include<stdio.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		int pass[4];
		int comp[4];


		TEST_METHOD(TestMethod1)
		{
			pass_set(pass, 4);
			my_func_int(comp, 4, pass, 4);
			Assert::AreEqual(comp[0], pass[0], L"パスワードの１桁目が正しいか確認");
			Assert::AreEqual(comp[1], pass[1], L"パスワードの２桁目が正しいか確認");
			Assert::AreEqual(comp[2], pass[2], L"パスワードの３桁目が正しいか確認");
			Assert::AreEqual(comp[3], pass[3], L"パスワードの４桁目が正しいか確認");
		}

		//TEST_METHOD(TestMethod2)
		//{
		//	Assert::IsTrue(my_func_bool(), L"true が返ってくることを想定したテスト");
		//}
	};
}
