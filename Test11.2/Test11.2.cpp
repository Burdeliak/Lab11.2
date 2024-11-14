#include "pch.h"
#include "CppUnitTest.h"
#include "../lab11.2/lab11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test112
{
	TEST_CLASS(Test112)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тест на простий випадок без вкладених дужок
			std::string input = "Це приклад <тексту, який потрібно видалити> для перевірки.";
			std::string expected = "Це приклад  для перевірки.";

			std::string result = RemoveBracketsContent(input);

			Assert::AreEqual(expected, result, L"Текст між дужками не був видалений правильно");

		}
	};
}
