#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.1A/Lab10.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student students[N] = {
				{ "Ivanenko", 2, 0, 5, 5, 3 },
				{ "Petrenko", 3, 1, 4, 4, 4 },
				{ "Sydorenko", 1, 2, 3, 3, 5 }
			};
			int count5, count4, count3;

			// Act
			CountMathGrades(students, N, count5, count4, count3);

			// Assert
			Assert::AreEqual(1, count5);
			Assert::AreEqual(1, count4);
			Assert::AreEqual(1, count3);
		}
	};
}
