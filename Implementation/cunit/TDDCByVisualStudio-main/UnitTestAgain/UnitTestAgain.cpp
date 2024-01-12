#include "pch.h"
#include "CppUnitTest.h"

#include "../CTest/add.h"
#include "../CTest/add.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest
{

	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(3, add(1, 2));
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(5, add(1, 2));
		}
	};
}
