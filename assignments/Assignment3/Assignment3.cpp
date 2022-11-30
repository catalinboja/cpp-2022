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
			Assert::AreEqual((int)t.type, 3, L"Default ctor does not init properly Taxi::type");

			//test if in Heap
			delete[] t.kmPerRide;
		}

		TEST_METHOD(_03TestParamsCtor)
		{
			Taxi t(100, TaxiType::UBER, 3.7);

			Assert::AreEqual(t.taxiId, 100, L"Ctor with params does not init properly Taxi::taxiId");
			Assert::IsTrue(t.lastDestination == "None",
				L"Ctor with params does not init properly Taxi::lastDestination");
			Assert::IsNull(t.kmPerRide, L"Ctor with params does not init properly Taxi::kmPerRide");
			Assert::AreEqual(t.noRides, 0, L"Ctor with params does not init properly Taxi::noRides");
			Assert::IsTrue(abs(t.pricePerKm - 3.7) < 0.01,
				L"Ctor with params does not init properly Taxi::pricePerKm");
			Assert::AreEqual((int)t.type, (int)TaxiType::UBER, L"Ctor with params does not init properly Taxi::type");

			//test if in Heap
			delete[] t.kmPerRide;
		}

		TEST_METHOD(_04TestParamsCtor)
		{
			int records[] = { 10,20,30 };
			Taxi t(100, TaxiType::UBER, 2.5, records, 3);

			Assert::AreEqual(t.taxiId, 100, L"Ctor with params does not init properly Taxi::taxiId");
			Assert::IsTrue(t.lastDestination == "None",
				L"Ctor with params does not init properly Taxi::lastDestination");
			Assert::IsNotNull(t.kmPerRide, L"Ctor with params does not init properly Taxi::kmPerRide");
			Assert::AreEqual(t.noRides, 3, L"Ctor with params does not init properly Taxi::noRides");
			Assert::IsTrue(abs(t.pricePerKm - 2.5) < 0.01,
				L"Ctor with params does not init properly Taxi::pricePerKm");
			Assert::AreEqual((int)t.type, (int)TaxiType::UBER, L"Ctor with params does not init properly Taxi::type");
			Assert::AreEqual(t.kmPerRide[0], (float)10, L"Ctor with params does not init properly Taxi::kmPerRide");
			Assert::AreEqual(t.kmPerRide[2], (float)30, L"Ctor with params does not init properly Taxi::kmPerRide");

			//test if in Heap
			delete[] t.kmPerRide;
		}

		TEST_METHOD(_05TestParamsCtorAndStatic)
		{
			Taxi::NO_UBER_TAXIES = 0;
			Taxi t1(100, TaxiType::UBER, 3.7);
			Taxi t2(100, TaxiType::BOLT, 3.7);
			int records[] = { 10,20,30 };
			Taxi t3(100, TaxiType::UBER, 2.5, records, 3);
			Taxi t4(100, TaxiType::BOLT, 2.5, records, 3);

			Assert::AreEqual(Taxi::NO_UBER_TAXIES, 2, L"Ctor(s) with params does not init properly Taxi::NO_UBER_TAXIES");


		}

		TEST_METHOD(_06CopyConstructor)
		{
			Taxi::NO_UBER_TAXIES = 0;
			int records[] = { 10,20,30 };
			Taxi t(100, TaxiType::UBER, 2.5, records, 3);
			t.lastDestination = "Bucharest";
			Taxi copy = t;

			Assert::AreEqual(copy.taxiId, t.taxiId, L"Copy Ctor does not init properly Taxi::taxiId");
			Assert::AreEqual(copy.lastDestination, t.lastDestination, L"Copy Ctor does not init properly Taxi::lastDestination");
			Assert::AreEqual(copy.noRides, t.noRides, L"Copy Ctor does not init properly Taxi::noRides");
			Assert::AreEqual(copy.pricePerKm, t.pricePerKm, L"Copy Ctor does not init properly Taxi::pricePerKm");
			Assert::AreEqual((int)copy.type, (int)t.type, L"Copy Ctor does not init properly Taxi::type");
			Assert::AreNotEqual(copy.kmPerRide, t.kmPerRide, L"Copy Ctor does not init properly Taxi::kmPerRide");
			Assert::AreEqual(Taxi::NO_UBER_TAXIES, 2, L"Copy Ctor does not change properly Taxi::NO_UBER_TAXIES");
		}

		TEST_METHOD(_07Destructor)
		{
			Taxi::NO_UBER_TAXIES = 0;
			Taxi* taxi1 = new Taxi(100, TaxiType::UBER, 3.7);
			Taxi* taxi2 = new Taxi(100, TaxiType::UBER, 3.7);
			delete taxi1;
			Assert::AreEqual(Taxi::NO_UBER_TAXIES, 1, L"Destructor does not change properly Taxi::NO_UBER_TAXIES");
		}


		TEST_METHOD(_08OperatorEquals)
		{
			int records[] = { 10,20,30 };
			Taxi::NO_UBER_TAXIES = 0;
			Taxi t(100, TaxiType::UBER, 2.9, records, 3);
			Taxi t2(100, TaxiType::OTHER, 2.9, records, 3);
			t.lastDestination = "Ploiesti";

			Taxi copy(200, TaxiType::BOLT, 3.7);

			Taxi::NO_UBER_TAXIES = 0;

			copy = t;

			//Assert::AreEqual(copy.taxiId, 200, L"Operator = does not init properly Taxi::taxiId");
			Assert::AreEqual(copy.lastDestination, t.lastDestination, L"Operator = does not init properly Taxi::lastDestination");
			Assert::AreEqual(copy.noRides, t.noRides, L"Operator = does not init properly Taxi::noRides");
			Assert::AreEqual(copy.pricePerKm, t.pricePerKm, L"Operator = does not init properly Taxi::pricePerKm");
			Assert::AreEqual((int)copy.type, (int)t.type, L"Operator = does not init properly Taxi::type");
			Assert::AreNotEqual(copy.kmPerRide, t.kmPerRide, L"Operator = does not init properly Taxi::kmPerRide");
			Assert::AreEqual(Taxi::NO_UBER_TAXIES, 1, L"Operator = does not change properly Taxi::NO_UBER_TAXIES");

			copy = t2;

			Assert::AreEqual(Taxi::NO_UBER_TAXIES, 0, L"Operator = does not change properly Taxi::NO_UBER_TAXIES");
		}


		TEST_METHOD(_09TestTotalRevenue)
		{
			int records[] = { 10,10,10 };
			Taxi t(1, TaxiType::UBER, 1, records, 3);

			float totalRevenue = t.getTotalRevenue();

			Assert::AreEqual(totalRevenue, (float)30, L"getTotalRevenue() does not compute the correct value");
		}

		TEST_METHOD(_10TestComputeFleetValue)
		{
			Taxi taxis[3];
			int records[] = { 10,10,10 };
			Taxi t(1, TaxiType::UBER, 1, records, 3);

			taxis[0] = t;
			taxis[1] = t;
			taxis[2] = t;
			double rezultat = Taxi::computeFleetValue(taxis, 3);
			Assert::IsTrue(abs(rezultat - 90) < 0.01, L"computeFleetValue does not compute correctly the value");
		}
	};
}
