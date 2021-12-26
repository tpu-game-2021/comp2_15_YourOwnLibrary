#include "pch.h"
#include "CppUnitTest.h"
#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(初期化)
	{
	public:
		TEST_METHOD(リストの初期化)
		{
			LIST list;
			initialize_list(&list);

			Assert::IsNull(list.header);
		}
		TEST_METHOD(ノードの初期化)
		{
			NODE node;
			initialize_node(&node, 1);

			Assert::IsNull(node.Next);
			Assert::AreEqual(1, node.data);
		}
	};

	TEST_CLASS(要素の取得)
	{
	public:
		TEST_METHOD(NULLの次はNULL)
		{
			LIST list;
			initialize_list(&list);

			Assert::IsNull(get_next(NULL));
		}
	};

	TEST_CLASS(要素の追加)
	{
	public:
		TEST_METHOD(１番前に追加（1要素）)
		{
			LIST list;
			initialize_list(&list);
			
			NODE node[1];
			initialize_node(&node[0], 10);

			push_front(&list, &node[0]);

			NODE* point = list.header;
			Assert::AreEqual((void*)&node[0], (void*)point);
			Assert::AreEqual(10, point->data);

			Assert::IsNull(get_next(point));
		}
		TEST_METHOD(３つの要素のうち中央の要素を先頭に追加)
		{
			LIST list;
			initialize_list(&list);

			NODE node[3];
			initialize_node(&node[0], 100);
			initialize_node(&node[1], 300);
			initialize_node(&node[2], 500);

			push_front(&list, &node[0]);
			push_next(&list, &node[1]);
			push_front(&list, &node[2]);

			NODE* point = list.header;
			Assert::AreEqual((void*)&node[2], (void*)point);
			Assert::AreEqual(500, point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[1], (void*)point);
			Assert::AreEqual(300, point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[0], (void*)point);
			Assert::AreEqual(100, point->data);

			Assert::IsNull(get_next(point));
		}
		TEST_METHOD(１番前に追加（3要素）)
		{
			LIST list;
			initialize_list(&list);

			NODE node[3];
			initialize_node(&node[0],150);
			initialize_node(&node[1], 200);
			initialize_node(&node[2], 300);

			push_front(&list, &node[0]);
			push_front(&list, &node[1]);
			push_front(&list, &node[2]);

			NODE* point = list.header;
			Assert::AreEqual((void*)&node[2], (void*)point);
			Assert::AreEqual(300, point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[1], (void*)point);
			Assert::AreEqual(200,point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[0], (void*)point);
			Assert::AreEqual(150,point->data);

			Assert::IsNull(get_next(point));
		}
	};

	TEST_CLASS(要素を削除)
	{
	public:
		TEST_METHOD(３要素の先頭を削除)
		{
			LIST list;
			initialize_list(&list);

			NODE node[3];
			initialize_node(&node[0], 1);
			initialize_node(&node[1], 3);
			initialize_node(&node[2], 5);

			push_front(&list, &node[0]);
			push_front(&list, &node[1]);
			push_front(&list, &node[2]);

			remove_front(&list);

			NODE* point = list.header;
			Assert::AreEqual((void*)&node[1], (void*)point);
			Assert::AreEqual(3, point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[0], (void*)point);
			Assert::AreEqual(1, point->data);

			Assert::IsNull(get_next(point));
		}
		TEST_METHOD(３要素の中央を削除)
		{
			LIST list;
			initialize_list(&list);

			NODE node[3]; 
			initialize_node(&node[0], 120);
			initialize_node(&node[1], 140);
			initialize_node(&node[2], 160);

			push_front(&list, &node[0]);
			push_front(&list, &node[1]);
			push_front(&list, &node[2]);

			remove_next(&list, list.header);

			NODE* point = list.header;
			Assert::AreEqual((void*)&node[2], (void*)point);
			Assert::AreEqual(160,point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[0], (void*)point);
			Assert::AreEqual(120,point->data);

			Assert::IsNull(get_next(point));
		}
		TEST_METHOD(３要素の末尾を削除)
		{
			LIST  list;
			initialize_list(&list);

			NODE node[3];
			initialize_node(&node[0], 1500);
			initialize_node(&node[1], 1600);
			initialize_node(&node[2], 1700);

			push_front(&list, &node[2]);
			push_front(&list, &node[1]);
			push_front(&list, &node[0]);

			remove_next(&list, &node[1]);

			NODE* point = list.header;
			Assert::AreEqual((void*)&node[0], (void*)point);
			Assert::AreEqual(1500,point->data);
			point = get_next(point);
			Assert::AreEqual((void*)&node[1], (void*)point);
			Assert::AreEqual(1600,point->data);

			Assert::IsNull(get_next(point));
		}
	};
}
