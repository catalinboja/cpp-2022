#include "pch.h"
#include "CppUnitTest.h"
#include "Assignment2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment2
{
	TEST_CLASS(TesteUnitare)
	{
	public:

		TEST_METHOD(_01TestClassDefaultValues)
		{

			Vehicle v;

			if (v.model == nullptr || strcmp(v.model, "Unknown") == 0)
				Assert::IsTrue(true);
			else
				Assert::Fail(L"Vehicle::model attribute has not a proper default value");

			if (v.brand._Equal("-") || v.brand == "Unknown")
				Assert::IsTrue(true);
			else
				Assert::Fail(L"Vehicle::model attribute has not a proper default value");

			if (v.price == 0 || abs(v.price - 7000) < 0.01)
				Assert::IsTrue(true);
			else
				Assert::Fail(L"Vehicle::price attribute has not the required default value");
		}

		TEST_METHOD(_02TestDefaultCtor)
		{
			Vehicle a;
			Assert::IsTrue(a.brand == "Unknown",
				L"Default ctor does not init properly Vehicle::brand");
			Assert::IsTrue(strcmp(a.model,"Unknown") == 0,
				L"Default ctor does not init properly Vehicle::model");
			Assert::IsFalse(a.hasBattery,
				L"Default ctor does not init properly Vehicle::hasBattery");
			Assert::IsTrue(abs(a.price - 7000) < 0.01,
				L"Default ctor does not init properly Vehicle::price");

			//test if in Heap
			delete[] a.model;
		}

		TEST_METHOD(_03TestParamsCtor)
		{
			const char* model = "Logan";
			Vehicle a("Dacia", model, 14000);

			Assert::IsTrue(a.brand == "Dacia",
				L"Params ctor does not init properly Vehicle::brand");
			Assert::IsTrue(strcmp(a.model, "Logan") == 0,
				L"Params ctor does not init properly Vehicle::model");
			Assert::IsTrue(abs(a.price - 14000) < 0.01,
				L"Default ctor does not init properly Vehicle::price");
			Assert::IsFalse(a.model == model,
				L"Default ctor does shallow copy for Vehicle::model");

			//test if in Heap
			delete[] a.model;
		}

		TEST_METHOD(_04TestGetStandardType)
		{
			VehicleType rezultat = Vehicle::getStandardType("petrol");
			Assert::IsTrue(rezultat == 5, L"getStandardType does not return ok for 'petrol'");
			rezultat = Vehicle::getStandardType("hybrid");
			Assert::IsTrue(rezultat == 10, L"getStandardType does not return ok for 'hybrid'");
			rezultat = Vehicle::getStandardType("electric");
			Assert::IsTrue(rezultat == 15, L"getStandardType does not return ok for 'electric'");
		}

		TEST_METHOD(_05TestGetType)
		{
			Vehicle vehicle;
			vehicle.hasBattery = true;

			VehicleType rezultat = vehicle.getType();
			Assert::IsTrue(rezultat == 15, L"Vehicle::getType does not return ok if the vehicle has battery");

			vehicle.hasBattery = false;
			rezultat = vehicle.getType();
			Assert::IsTrue(rezultat == 5, L"Vehicle::getType does not return ok if the vehicle does NOT have battery");
		}

		TEST_METHOD(_06TestApplyDiscount)
		{
			auto func1 = [] { Vehicle a; a.price = 9876; a.applyDiscount(0); };
			Assert::ExpectException<VehicleException>(func1, L"Vehicle::applyDiscount does not throw VehicleException for values less than 1");

			auto func2 = [] { Vehicle a; a.price = 9876; a.applyDiscount(55); };
			Assert::ExpectException<VehicleException>(func2, L"Vehicle::applyDiscount does not throw VehicleException for values greater than 50");

			Vehicle a;
			a.price = 9876;
			a.applyDiscount(25);
			Assert::IsTrue(abs(a.price - 7407) < 0.01,
				L"Vehicle::applyDiscount does not apply correctly the discount");
		}


		TEST_METHOD(_07TestSetLicensePlatesNumber)
		{
			Vehicle a;
			char plates[] = "B101POO";
			a.setLicensePlatesNumber(plates);
			char* rezultat = a.getLicensePlatesNumber();
			
			Assert::IsTrue(strcmp(rezultat, plates) == 0,L"LicensePlates functions are not ok");
			Assert::IsFalse(rezultat == plates,L"LicensePlates functions are not ok. Shallow copy");
		}

		TEST_METHOD(_08TestSetModel)
		{
			Vehicle a;
			char model[] = "Model Y";
			a.setModel(model);

			Assert::IsTrue(strcmp(a.model, model) == 0, L"SetModel does not init ok model attribute");
			Assert::IsFalse(a.model == model, L"SetModel not ok. Shallow copy");

			auto func1 = [] { Vehicle a; a.setModel("Y"); };
			Assert::ExpectException<VehicleException>(func1, L"Vehicle::setModel does not throw VehicleException short model names");

			auto func2 = [] { Vehicle a; a.setModel("model Y"); };
			Assert::ExpectException<VehicleException>(func2,
				L"Vehicle::setModel does not throw VehicleException for names that don't start with capital letter");

			auto func3 = [] { Vehicle a; a.setModel("5 model Y"); };
			Assert::ExpectException<VehicleException>(func3,
				L"Vehicle::setModel does not throw VehicleException for names that don't start with capital letter");

		}

		TEST_METHOD(_09TestGetModel)
		{
			Vehicle a;
			char model[] = "Model Y";
			a.model = (char*)model;

			char* result = a.getModel();

			Assert::IsNotNull(result, L"GetModel NOT ok. Returns null");
			Assert::IsTrue(strcmp(a.model, result) == 0, L"GetModel does NOT return ok the model attribute value");
			Assert::IsFalse(a.model == result, L"GetModel NOT ok. Returns address");
		}


		TEST_METHOD(_10TestDestructor)
		{
			
			Vehicle* pa = new Vehicle();
			Vehicle::NO_VEHICLES = 0;
			delete pa;
			Assert::IsTrue(Vehicle::NO_VEHICLES == -1,
				L"The destructor does NOT change NO_VEHICLES correctly");
		}

		TEST_METHOD(_11TestComputeFleetValue)
		{
			Vehicle vehicles[3];
			Vehicle a1, a2, a3;
			a1.price = 1111.5;
			a2.price = 2222.5;
			a3.price = 3333.4;
			vehicles[0] = a1; vehicles[1] = a2; vehicles[2] = a3;
			double rezultat = computeFleetValue(vehicles, 3);
			Assert::IsTrue(abs(rezultat - 6667.4) < 0.01, L"computeFleetValue does not compute correctly the value");
		}

		TEST_METHOD(_12TestGetTheMostExpensiveVehicle)
		{
			Vehicle a1, a2, a3;
			a1.price = 200.5;
			a2.price = 200.7;
			a3.price = 154.5;
			Vehicle** vector = new Vehicle * [3];
			vector[0] = &a1; vector[1] = &a2; vector[2] = &a3;
			double rezultat = getTheMostExpensiveVehicle(vector, 3);
			Assert::IsTrue(abs(200.7 - rezultat) < 0.01,
				L"The returned value is not the price of the most expensive vehicle");
		}

	};
}
