#include "pch.h"
#include "CppUnitTest.h"
#include "Assignment3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment3
{
	TEST_CLASS(TesteUnitare)
	{
	public:

		TEST_METHOD(_01TestClassDefaultValues)
		{

			Taxi t;

			Assert::AreEqual(t.noRides, 0, L"Taxi::noRides attribute has not a proper default value");
			Assert::IsNull(t.kmPerRide, L"Taxi::kmPerRide attribute has not a proper default value");
			if (t.lastDestination._Equal("*") || t.lastDestination == "Unknown")
				Assert::IsTrue(true);
			else
				Assert::Fail(L"Taxi::lastDestination attribute has not a proper default value");

			if (t.pricePerKm == 0 || abs(t.pricePerKm - 2.5) < 0.01)
				Assert::IsTrue(true);
			else
				Assert::Fail(L"Taxi::pricePerKm attribute has not the required default value");

			if (t.type == TaxiType::CLASSIC || t.type == TaxiType::OTHER)
				Assert::IsTrue(true);
			else
				Assert::Fail(L"Taxi::type attribute has not the required default value");
		}

		TEST_METHOD(_02TestDefaultCtor)
		{
			Taxi t;
			Assert::AreEqual(t.taxiId, -1, L"Default ctor does not init properly Taxi::taxiId");
			Assert::IsTrue(t.lastDestination == "Unknown",
				L"Default ctor does not init properly Taxi::lastDestination");
			Assert::IsNull(t.kmPerRide, L"Default ctor does not init properly Taxi::kmPerRide");
			Assert::AreEqual(t.noRides, 0, L"Default ctor does not init properly Taxi::noRides");
			Assert::IsTrue(abs(t.pricePerKm - 2.5) < 0.01,
				L"Default ctor does not init properly Taxi::pricePerKm");
			Assert::AreEqual(t.type, TaxiType::CLASSIC);

			//test if in Heap
			delete[] t.kmPerRide;
		}

		TEST_METHOD(_03TestParamsCtor)
		{
			Taxi t(100, TaxiType::UBER, 3.7);

			Assert::AreEqual(t.taxiId, 100, L"Default ctor does not init properly Taxi::taxiId");
			Assert::IsTrue(t.lastDestination == "None",
				L"Default ctor does not init properly Taxi::lastDestination");
			Assert::IsNull(t.kmPerRide, L"Default ctor does not init properly Taxi::kmPerRide");
			Assert::AreEqual(t.noRides, 0, L"Default ctor does not init properly Taxi::noRides");
			Assert::IsTrue(abs(t.pricePerKm - 3.7) < 0.01,
				L"Default ctor does not init properly Taxi::pricePerKm");
			Assert::AreEqual(t.type, TaxiType::UBER);

			//test if in Heap
			delete[] t.kmPerRide;
		}

		TEST_METHOD(_04TestGetStandardType)
		{
			TaxiType rezultat = Taxi::getStandardType("petrol");
			Assert::IsTrue(rezultat == 5, L"getStandardType does not return ok for 'petrol'");
			rezultat = Taxi::getStandardType("hybrid");
			Assert::IsTrue(rezultat == 10, L"getStandardType does not return ok for 'hybrid'");
			rezultat = Taxi::getStandardType("electric");
			Assert::IsTrue(rezultat == 15, L"getStandardType does not return ok for 'electric'");
		}

		TEST_METHOD(_05TestGetType)
		{
			Taxi Taxi;
			Taxi.hasBattery = true;

			TaxiType rezultat = Taxi.getType();
			Assert::IsTrue(rezultat == 15, L"Taxi::getType does not return ok if the Taxi has battery");

			Taxi.hasBattery = false;
			rezultat = Taxi.getType();
			Assert::IsTrue(rezultat == 5, L"Taxi::getType does not return ok if the Taxi does NOT have battery");
		}

		TEST_METHOD(_06TestApplyDiscount)
		{
			auto func1 = [] { Taxi a; a.price = 9876; a.applyDiscount(0); };
			Assert::ExpectException<TaxiException>(func1, L"Taxi::applyDiscount does not throw TaxiException for values less than 1");

			auto func2 = [] { Taxi a; a.price = 9876; a.applyDiscount(55); };
			Assert::ExpectException<TaxiException>(func2, L"Taxi::applyDiscount does not throw TaxiException for values greater than 50");

			Taxi a;
			a.price = 9876;
			a.applyDiscount(25);
			Assert::IsTrue(abs(a.price - 7407) < 0.01,
				L"Taxi::applyDiscount does not apply correctly the discount");
		}


		TEST_METHOD(_07TestSetLicensePlatesNumber)
		{
			Taxi a;
			char plates[] = "B101POO";
			a.setLicensePlatesNumber(plates);
			char* rezultat = a.getLicensePlatesNumber();

			Assert::IsTrue(strcmp(rezultat, plates) == 0, L"LicensePlates functions are not ok");
			Assert::IsFalse(rezultat == plates, L"LicensePlates functions are not ok. Shallow copy");
		}

		TEST_METHOD(_08TestSetModel)
		{
			Taxi a;
			char model[] = "Model Y";
			a.setModel(model);

			Assert::IsTrue(strcmp(a.model, model) == 0, L"SetModel does not init ok model attribute");
			Assert::IsFalse(a.model == model, L"SetModel not ok. Shallow copy");

			auto func1 = [] { Taxi a; a.setModel("Y"); };
			Assert::ExpectException<TaxiException>(func1, L"Taxi::setModel does not throw TaxiException short model names");

			auto func2 = [] { Taxi a; a.setModel("model Y"); };
			Assert::ExpectException<TaxiException>(func2,
				L"Taxi::setModel does not throw TaxiException for names that don't start with capital letter");

			auto func3 = [] { Taxi a; a.setModel("5 model Y"); };
			Assert::ExpectException<TaxiException>(func3,
				L"Taxi::setModel does not throw TaxiException for names that don't start with capital letter");

		}

		TEST_METHOD(_09TestGetModel)
		{
			Taxi a;
			char model[] = "Model Y";
			a.model = (char*)model;

			char* result = a.getModel();

			Assert::IsNotNull(result, L"GetModel NOT ok. Returns null");
			Assert::IsTrue(strcmp(a.model, result) == 0, L"GetModel does NOT return ok the model attribute value");
			Assert::IsFalse(a.model == result, L"GetModel NOT ok. Returns address");
		}


		TEST_METHOD(_10TestDestructor)
		{

			Taxi* pa = new Taxi();
			Taxi::NO_TaxiS = 0;
			delete pa;
			Assert::IsTrue(Taxi::NO_TaxiS == -1,
				L"The destructor does NOT change NO_TaxiS correctly");
		}

		TEST_METHOD(_11TestComputeFleetValue)
		{
			Taxi Taxis[3];
			Taxi a1, a2, a3;
			a1.price = 1111.5;
			a2.price = 2222.5;
			a3.price = 3333.4;
			Taxis[0] = a1; Taxis[1] = a2; Taxis[2] = a3;
			double rezultat = computeFleetValue(Taxis, 3);
			Assert::IsTrue(abs(rezultat - 6667.4) < 0.01, L"computeFleetValue does not compute correctly the value");
		}

		TEST_METHOD(_12TestGetTheMostExpensiveTaxi)
		{
			Taxi a1, a2, a3;
			a1.price = 200.5;
			a2.price = 200.7;
			a3.price = 154.5;
			Taxi** vector = new Taxi * [3];
			vector[0] = &a1; vector[1] = &a2; vector[2] = &a3;
			double rezultat = getTheMostExpensiveTaxi(vector, 3);
			Assert::IsTrue(abs(200.7 - rezultat) < 0.01,
				L"The returned value is not the price of the most expensive Taxi");
		}
}
