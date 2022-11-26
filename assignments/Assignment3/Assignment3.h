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
	float* kmPerRide;		//used to store the no of kms of each ride
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
	this will initialize the 3 attributes with the received values. 
	Last destination is initialized with "None"
	The Taxi id must be the one received as parameter
	*/

	Taxi(int id, TaxiType type, double price):taxiId(0)
	{
	}

	/*
		Requirement 4. Modify the constructor with 5 parameters: id, type, price, old records, no previous rides
	this will initialize the 5 attributes with the received values. 
	Last destination is initialized with "None"
	The Taxi id must be the one received as parameter
	*/

	Taxi(int id, TaxiType type, double price, int* records, int noPreviousRides) :taxiId(0)
	{
	}

	/*
	Requirement 5. Modify the constructors (both) with parameters so if the Taxi type is UBER
	then NO_UBER_TAXIES is incremented by 1
	*/


	/*
		Requirement 6. Implement the class copy constructor without doing shallow copy
		The copy id must be identical with the given object
		If the copy is a UBER taxi the NO_UBER_TAXIES values must be updated accordingly
	*/
	Taxi(const Taxi& taxi):taxiId(0)
	{
	}


	/*
			Requirement 7. Implement the class destructor to remove the chance to generate memory leaks
			If the destroyed Taxi is an UBER then NO_UBER_TAXIES must be updated

	*/
	~Taxi()
	{

	}


	/*
			Requirement 8. Overload the = operator so you don't genereate shallow copy and you avoid self equality (obj = obj)
			NO_UBER_TAXIES must be updated based on different cases
	*/

	void operator=(const Taxi& taxi)
	{
	}

	/*
			Requirement 9. Implement the next method that computes the total revenue of the Taxi
			based on the kms records and the price per km
	*/
	float getTotalRevenue()
	{
		return 0;
	}


	/*
		Requirement 10. Implement the next method that computes the total revenue of a Taxi fleet
	*/

	static double computeFleetValue(Taxi vehicles[], int noVehicles)
	{
		return 0;
	}

};

int Taxi::NO_UBER_TAXIES = 0;


/*
	11. Overload the next operators so the next functions instructions will be valid
	There are no unit tests for this requirement
*/


void operatorsTest() {

	Taxi taxi(1, TaxiType::UBER, 2.5);

	//cout << taxi;		//display all the taxi data to the console

	//cin >> taxi;		//read the taxi values from the console (including the array)

	//taxi = taxi + 20;	//adds a new ride that was 20 km long
	//taxi = 15 + taxi;	//adds a new ride that was 15 km long

	//taxi *= 2;			//multiply the price per km

	//Taxi copy = taxi++;				//increments the price per km

	//cout << copy;
	//cout << taxi;

	//Taxi otherCopy = ++taxi;		//increments the price per km

	//cout << otherCopy;
	//cout << taxi;

	//if (otherCopy == copy) {
	//	cout << endl << "They have the same total revenue";
	//}

	//if (!taxi) {
	//	cout << endl << "Total revenue is 0";
	//}

	//float partialRevenue = taxi(1, 3);	//computes the revenue for the rides with index between 1 and 3; 
											//index between 0 and n-1
											//	if the index values are wrong (outside array boundaries) you return 0

	//int secondRide = taxi[1];				//gets the 2nd ride distance

	//taxi[1] = 5;							//changes the 2nd ride distance

	//cout << taxi;

}



