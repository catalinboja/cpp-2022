#pragma once

#include <iostream>
#include <string>
using namespace std;


//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//WARNING!!!
//Only the original and individual solution will be graded
//Any attempt of copying the solution will lead to loosing the entire lab grade
//The header of the functions cannot be modified, just their body


//DON't change it. Needed for tests
class TaxiException {

};

//TO BE changed based on requirements
enum TaxiType { UBER, BOLT, BLACK_CAB, CLASSIC, OTHER};

class Taxi
{


	/*
		Requirement 1. Set the default values for the class attributes. For lastDestination use "*" and for type use OTHER
		CHange existing values if necessary
	*/

	//leave the class public - needed for tests
public:
	const int taxiId;
	string lastDestination;
	int noRides = -1;
	float* kmPerRide;		//used to store the on of kms of each ride
	double pricePerKm;
	TaxiType type;

	static int NO_UBER_TAXIES;
	const static int MIN_KM_PER_RIDE = 5;

	/*
			Requirement 2. Modify the default constructor of the Taxi class defined below
	this will initialize lastDestination with "Unknown", pricePerKm with 2.5, type with CLASSIC and the taxiId with -1

	*/
	Taxi():taxiId(-1)
	{

	}


	/*
			Requirement 3. Modify the constructor with 3 parameters: id, type, price
	this will initialize the 3 attributes with the received values. Last destination is initialized with "None"

	*/
	Taxi(int id, TaxiType type, double price):taxiId(id)
	{
	}

	/*
		Requirement 4. Modify the constructor with 5 parameters: id, type, price, old records, no previous rides
this will initialize the 3 attributes with the received values. Last destination is initialized with "None"

*/
	Taxi(int id, TaxiType type, double price, int* records, int noPreviousRides) :taxiId(id)
	{
	}


	/*
			Requirement 4. The function below return a variable of type enum (TaxiType, the enum defined above)
	modify the enum so it can have only three posible values
	Those are: 5 - petrol, 10 - hybrid, 15 - electric
	the function receives one parameter which is a string from the ones above
	("petrol", "hybrid", "electric") and returns the enum value

	*/
	static TaxiType getStandardType(string type)
	{
		return (TaxiType)0;
	}


	/*
			Requirement 5. The function below return a variable of type enum (TaxiType, the enum defined above)
	Modify the enum so it can have only three posible values: 5 - PETROL, 10 - HYBRID, 15 - ELECTRIC
	The function must return ELECTRIC if the vehicle has battery. Otherwise must return PETROL

	*/
	TaxiType getType()
	{
		return (TaxiType)0;
	}


	/*
			Requirement 6. Modify the applyDiscount method in order to give a discount from the price
	the discount is a percentage between 1% and 50%
	the function should modify the price with the value obtained after the discount is applied
	the function shoud throw an exception for values outside [1,50]	with throw TaxiException();
	*/

	void applyDiscount(int percent)
	{
	}


	/*
			Requirement 7. Add to the class a new attribute called 'licensePlatesNumber'
		this is a statically allocated char array with the maximum length 9
		Modify the methods setLicensePlatesNumber and getLicensePlatesNumber
		in such a manner that they will modify (first one) and return (second one) the value of this field

	*/
	void setLicensePlatesNumber(const char* licensePlates)
	{
	}

	char* getLicensePlatesNumber()
	{
		return nullptr;
	}

	/*
			Requirement 8. Implement setModel in order to change the vehicle model
		The method should not do shallow copy
		The method should not generate memory leaks
		The method should validate that the model length is greater or equal than LICENSE_MIN_LENGTH. Otherwise throws exception with throw TaxiException();
		The method should validate that the model name starts with a capital letter (A - Z). Otherwise throws exception with throw TaxiException();
	*/
	void setModel(const char* model) {

	}


	/*
			Requirement 9. Implement getModel in order to get the vehicle model
		The method should return a copy of the model and not its address/pointer
	*/
	char* getModel() {
		return nullptr;
	}

	/*
		Requirement 10. Add a desctructor to the class that will decrement NO_VEHICLES each time a vehicle is detroyed
	*/

};

int Taxi::NO_VEHICLES = 0;



//11. The function below receive as arguments an array of cars and its number of elements
//compute and return the todal value of the vehicles by adding the prices (pret) of all the cars from the array
double computeFleetValue(Taxi vehicles[], int noVehicles)
{
	return 0;
}

//12. The function below receives as parameters a dinamically allocated array of pointers to Taxi together with its number of elements
//Return the value of the most expensive car from this array
double getTheMostExpensiveVehicle(Taxi** vector, int nr_masini)
{
	return 0.0f;
}

