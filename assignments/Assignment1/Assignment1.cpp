#include "pch.h"
#include "CppUnitTest.h"
#include "Assignment1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment1
{
	int vectorInitial[] = { 23,67,89,102,560,1000 };
	int nrElemente = 6;

	double balance = 5000;


	TEST_CLASS(Assignment1)
	{
	public:
		
		TEST_METHOD(getDiscountedPriceTestFreeAccount)
		{
			float expectedPrice = 900;
			float actualPrice = getDiscountedPrice(FREE, 1000, 10);
			Assert::AreEqual(expectedPrice, actualPrice);
		}

		TEST_METHOD(getDiscountedPriceTestPremiumAccount)
		{
			float expectedPrice = 810;
			float actualPrice = getDiscountedPrice(PREMIUM, 1000, 10);
			Assert::AreEqual(expectedPrice, actualPrice);
		}

		TEST_METHOD(getDiscountedPriceTestBusinessAccount)
		{
			float expectedPrice = 720;
			float actualPrice = getDiscountedPrice(BUSINESS, 1000, 10);
			Assert::AreEqual(expectedPrice, actualPrice);
		}

		TEST_METHOD(getDiscountedPriceTestGoldAccount)
		{
			float expectedPrice = 630;
			float actualPrice = getDiscountedPrice(GOLD, 1000, 10);
			Assert::AreEqual(expectedPrice, actualPrice);
		}

		TEST_METHOD(getDiscountedPriceTestZeroDiscount)
		{
			float expectedPrice = 1000;
			float actualPrice = getDiscountedPrice(GOLD, 1000, 0);
			Assert::AreEqual(expectedPrice, actualPrice);
		}


		// titlecase

		TEST_METHOD(TestTitleCase1RightTest) {
			char* text = "salut. ce mai faci";
			char* newText = toTitleCase(text);
			Assert::IsNotNull(newText);
			Assert::AreEqual(strcmp(newText, "Salut. Ce Mai Faci"), 0);
		}

		TEST_METHOD(TestTitleCase2RightTest) {
			char* text = "01 salut. Ce mai Faci?";
			char* newText = toTitleCase(text);
			Assert::IsNotNull(newText);
			Assert::AreEqual(strcmp(newText, "01 Salut. Ce Mai Faci?"), 0);
		}

		TEST_METHOD(TestTitleCase3SameReferenceTest) {
			char* text = "01 salut. Ce mai Faci?";
			char* newText = toTitleCase(text);
			Assert::IsNotNull(newText);
			Assert::AreNotEqual(text, newText);
		}

		// removeSpaces

		TEST_METHOD(TestRemoveSpacesRightTest) {
			char* text = " salut.   acesta este un test ";
			char* newText = removeSpaces(text);
			Assert::IsNotNull(newText);
			Assert::AreNotEqual(strcmp(newText, "salut.acestaesteuntest"), 0);
		}

		TEST_METHOD(TestRemoveSpacesRightTestMoreSpaces) {
			char* text = "     salut.   acesta este un test     ";
			char* newText = removeSpaces(text);
			Assert::IsNotNull(newText);
			Assert::AreNotEqual(strcmp(newText, "salut.acestaesteuntest"), 0);
		}


		TEST_METHOD(NumarElementeMaiMariTestNormal) {
			int valoarePrag = 100;
			int rezultat = noBiggerThanValues(vectorInitial, nrElemente, valoarePrag);
			Assert::AreEqual(rezultat, 3);
		}

		TEST_METHOD(NumarElementeMaiMariTestLimita) {
			int valoarePrag = 102;
			int rezultat = noBiggerThanValues(vectorInitial, nrElemente, valoarePrag);
			Assert::AreEqual(rezultat, 3);
		}

		TEST_METHOD(NumarElementeMaiMariTestOut) {
			int valoarePrag = 2000;
			int rezultat = noBiggerThanValues(vectorInitial, nrElemente, valoarePrag);
			Assert::AreEqual(rezultat, 0);
		}

		TEST_METHOD(FiltrareElementeMaiMariTestNormal1) {
			int valoarePrag = 100;
			int* rezultat = filterValuesBiggerThan(vectorInitial, nrElemente, valoarePrag);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[0], 102);
		}

		TEST_METHOD(FiltrareElementeMaiMariTestNormal2) {
			int valoarePrag = 100;
			int* rezultat = filterValuesBiggerThan(vectorInitial, nrElemente, valoarePrag);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[2], 1000);
		}

		TEST_METHOD(FiltrareElementeMaiMariTestNormal3) {
			int valoarePrag = 100;
			int* rezultat = filterValuesBiggerThan(vectorInitial, nrElemente, valoarePrag);
			Assert::IsNotNull(rezultat);
			Assert::IsTrue(vectorInitial != rezultat);
		}

		TEST_METHOD(FiltrareElementeMaiMariTestNULL) {
			int valoarePrag = 2000;
			int* rezultat = filterValuesBiggerThan(vectorInitial, nrElemente, valoarePrag);
			Assert::IsNull(rezultat);
		}

		TEST_METHOD(FiltrareElementeMaiMari2TestNormal1) {
			int valoarePrag = 100;
			int* rezultat = nullptr;
			filterValuesBiggerThanVersion2(vectorInitial, nrElemente, valoarePrag, &rezultat);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[1], 560);
		}

		TEST_METHOD(FiltrareElementeMaiMari2TestNormal2) {
			int valoarePrag = 100;
			int* rezultat = nullptr;
			filterValuesBiggerThanVersion2(vectorInitial, nrElemente, valoarePrag, &rezultat);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[2], 1000);
		}

		TEST_METHOD(FiltrareElementeMaiMari2TestNULL) {
			int valoarePrag = 2000;
			int* rezultat;
			filterValuesBiggerThanVersion2(vectorInitial, nrElemente, valoarePrag, &rezultat);
			Assert::IsNull(rezultat);
		}


		TEST_METHOD(GetElementTestNormal1) {
			int rezultat = getElement(vectorInitial, nrElemente, 1);
			Assert::AreEqual(rezultat, 67);
		}

		TEST_METHOD(GetElementTestNormal2) {
			for (int i = 0; i < nrElemente; i++) {
				int rezultat = getElement(vectorInitial, nrElemente, i);
				Assert::AreEqual(rezultat, vectorInitial[i]);
			}
		}

		TEST_METHOD(GetElementTestExceptieIndexNegativ) {
			int rezultat = getElement(vectorInitial, nrElemente, -1);
			Assert::AreEqual(rezultat, INT32_MIN);
		}

		TEST_METHOD(GetElementTestExceptieIndexLimita) {
			int rezultat = getElement(vectorInitial, nrElemente, nrElemente);
			Assert::AreEqual(rezultat, INT32_MIN);
		}

		TEST_METHOD(GetElementTestIndexPreaMare) {
			int rezultat = getElement(vectorInitial, nrElemente, 1000);
			Assert::AreEqual(rezultat, INT32_MIN);
		}


		TEST_METHOD(SliceTestNormal1) {
			//89,102,560
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[0], 89);
		}

		TEST_METHOD(SliceTestNormal2) {
			//89,102,560
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[2], 560);
		}

		TEST_METHOD(SliceTestNormal3) {
			//89,102,560
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
			Assert::AreEqual(dimSlice, 3);
		}

		TEST_METHOD(SliceTestNormalIndexEgal1) {
			//89,102,560
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 2, dimSlice);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(dimSlice, 1);
		}

		TEST_METHOD(SliceTestNormalIndexEgal2) {
			//89,102,560
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 2, dimSlice);
			Assert::IsNotNull(rezultat);
			Assert::AreEqual(rezultat[0], 89);
		}

		TEST_METHOD(SliceTestExceptieIndexStartNegativ) {
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, -2, 4, dimSlice);
			Assert::IsNull(rezultat);
		}

		TEST_METHOD(SliceTestExceptieIndexFinalNegativ) {
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, -4, dimSlice);
			Assert::IsNull(rezultat);
		}

		TEST_METHOD(SliceTestExceptieIndexFinalPreaMare) {
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 40, dimSlice);
			Assert::IsNull(rezultat);
		}

		TEST_METHOD(SliceTestExceptieIndex) {
			int dimSlice;
			int* rezultat = slice(vectorInitial, nrElemente, 2, 1, dimSlice);
			Assert::IsNull(rezultat);
		}
	};
}
