#include <iostream>
#include <string>
using namespace std;

class Dummy {
private:
	string color;
	static int NO_BLUE_DUMMIES;

public:
	const static int MAX_BLUE_DUMMIES = 1000;

	Dummy(string color): color(color) {
	}

	void doSomething() {
		Dummy:NO_BLUE_DUMMIES = 10;
	}
	void saySomething() {
		cout << endl << "Hello from " << this->color << " dummy";
	}

	Dummy(const Dummy& dummy): color(dummy.color) {
		//this->color = dummy.color;
	}

public:
	static int getNoBlueDummies() {
		return Dummy::NO_BLUE_DUMMIES;
	}
	static void incrementNoBlueDummies() {
		Dummy::NO_BLUE_DUMMIES += 1;
	}

};

int Dummy::NO_BLUE_DUMMIES = 1;
//const int Dummy::MAX_BLUE_DUMMIES = 100;



class Employee {
public:
	string name;
	int age;
	string city;
	string street;
	int streetNo;
	string companyName;
	string corporateEmail;
	string personalEmail;
	string companyCity;
	string companyStreet;
	float salary;
};

class Address {
public:
	string city;
	string street;
	int streetNo;
};

class PersonalData {
public:
	string name;
	int age;
	string personalEmail;
};

class Job {
public:
	string corporateEmail;
	string companyName;
	Address companyAddress;
	float salary;
};

class SmartEmployee {
public:
	PersonalData personalData;
	Address personalAddress;
	Job job;
};





int main() {
	//Dummy::NO_BLUE_DUMMIES = 1;
	int noBlues = Dummy::getNoBlueDummies();
	cout << endl << "No Blue Dummies" << noBlues;
	Dummy::incrementNoBlueDummies();
	noBlues = Dummy::getNoBlueDummies();
	cout << endl << "No Blue Dummies" << noBlues;
	cout << endl << "Max " << Dummy::MAX_BLUE_DUMMIES;

	Dummy red("red");
	Dummy blue("blue");

	red.saySomething();
	blue.saySomething();

	Employee john;
	//john.city;
	string street = john.companyStreet;

	SmartEmployee alice;
	street = alice.job.companyAddress.street;
}