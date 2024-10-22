#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.1it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
	TEST_CLASS(UnitTest71it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3;
            const int colCount = 3;
            int S = 0;
            int k = 0;
            int** P = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                P[i] = new int[colCount];

            P[0][0] = 1;
            P[0][1] = 2;
            P[0][2] = 3;
            P[1][0] = 4;
            P[1][1] = 5;
            P[1][2] = 6;
            P[2][0] = 7;
            P[2][1] = 8;
            P[2][2] = 9;

            Calc(P, rowCount, colCount, S, k);

            Assert::AreEqual(18, S);
            Assert::AreEqual(3, k);


            for (int i = 0; i < rowCount; i++)
                delete[] P[i];
            delete[] P;

		}
	};
}
