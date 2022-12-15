#include <iostream>
#include <string>
using namespace std;


class Address {
private:
	string street;
	int no;
	string city;
public:
	string getStreet() {
		return this->street;
	}
	int getNo() {
		return this->no;
	}
};

class Driver {
private:
	string name;
	int age;
public:
	Driver() {

	}
	Driver(string name, int age) : name(name), age(age) {

	}

};

class Delivery {
	string content;
	Address address;
	Driver driver;
public:
	Delivery(string content, Address address, Driver driver) {
		this->content = content;
		this->address = address; //operator= from Address
		this->driver = driver; //operator = from Driver
	}


	//this version uses the copy constructors
	Delivery(string content, Driver driver, Address address)
		:content(content), driver(driver), address(address)
	{
	}

	Delivery(string content, string driverName, int driverAge,
		Address address): content(content), driver(driverName, driverAge),
		address(address)
	{

	}

	Delivery(string content, Address address, string driverName, int driverAge) 
		:content(content), address(address)
	{
		this->driver = Driver(driverName, driverAge); //= operator from Driver + ctor
	}

	string getContent() {
		return this->content;
	}

	Address& getAddress() {
		return this->address;
	}

};

void operator<<(ostream& out, Address& address) {
	cout << endl << "Address: " << address.getStreet() << ", " << address.getNo();
}

void operator<<(ostream& out, Delivery& delivery) {
	cout << endl << "Delivery data: ";
	cout << endl << "Content: " << delivery.getContent();
	cout << endl << delivery.getAddress();
	cout << endl << "Address: "<< delivery.getAddress().getStreet() << " , " << 
		delivery.getAddress().getNo();
}



int main() {
	Driver driver;
	Address address;
	
	Delivery delivery("Gift",address, driver);
	Delivery delivery2("Gift 2", driver, address);
	Delivery delivery3("Gift 3", "John", 23, address);
	Delivery delivery4("Gift 4", address, "John", 23);

	//Delivery deliveries[100]();
	//int noDeliveries;

	//Delivery* newDeliveries;
	//int noNewDeliveries;

	//newDeliveries = new Delivery[5];

	Delivery* deliveries[10];

	Delivery** pointersToDeliveries;
	int noDeliveries;

	pointersToDeliveries = new Delivery * [3];
	pointersToDeliveries[0] = new Delivery("Gift", address, driver);
	pointersToDeliveries[1] = new Delivery("Gift", address, driver);
	pointersToDeliveries[2] = new Delivery("Gift", address, driver);
	noDeliveries = 3;


	cout << delivery4;
}