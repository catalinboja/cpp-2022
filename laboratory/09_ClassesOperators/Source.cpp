#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class SantaList {
	const string kidName;
	char* address = nullptr;
	float budget = 0;
	bool isNice = true;

public:
	SantaList() : kidName("John Doe") {
		//this->kidName = string("John Doe");
	}

	SantaList(string kid, float budget)
		: kidName(kid), budget(budget) {
	}
	//this->budget = budget;

	SantaList(string kidName,
		const char* kidAddress,
		float kidBudget)
		:kidName(kidName),
		budget(kidBudget)
	{
		this->address = new char[strlen(kidAddress) + 1];
		//strcpy(this->address, kidAddress);
		memcpy(this->address,
			kidAddress,
			strlen(kidAddress) + 1);
	}

	void print() {
		cout << endl << "Santa's list for " << this->kidName;
		if (this->address != nullptr) {
			cout << endl << "Delivery address: " << this->address;
		}
		cout << endl << " Budget: " << this->budget;
		cout << endl << "Is nice: " <<
			(this->isNice ? "Is a good kid" : "Doesn't get presents");
	}

	void doesSomethingBad() {
		this->isNice = false;
	}

	~SantaList() {
		delete[] this->address;
	}

	SantaList(const SantaList& list)
		: kidName(list.kidName),
		budget(list.budget),
		isNice(list.isNice) {

		if (list.address != nullptr) {
			this->address = new char[strlen(list.address) + 1];
			memcpy(this->address,
				list.address,
				strlen(list.address) + 1);
		}
		else
			this->address = nullptr;
	}

	void operator=(const SantaList& list) {

		//test for self equal
		if (this == &list) {
			//the same object
			return;
		}

		this->budget = list.budget;
		this->isNice = list.isNice;

		if (this->address) {
			delete[] this->address;
			this->address = nullptr;
		}

		if (list.address != nullptr) {

			this->address = new char[strlen(list.address) + 1];
			memcpy(this->address,
				list.address,
				strlen(list.address) + 1);
		}
		else {
			this->address = nullptr;
		}

	}

	float getBudget() {
		return this->budget;
	}
	void setBudget(float value) {
		this->budget = value;
	}

	//SantaList operator+(float value) {
	//	//don't change this
	//	SantaList result = *this;
	//	result.budget += value;
	//	return result;
	//}

	void operator*=(float value) {
		this->budget *= value;
	}

	bool operator<=(float value) {
		return this->budget <= value;
	}

	bool operator>(SantaList& list) {
		return this->budget > list.budget;
	}

	bool operator!() {
		return this->budget == 0;
	}

	float operator()(float estimatedValue) {
		return this->budget + estimatedValue;
	}

	char& operator[](int index) {
		if (index < 0 || index >= strlen(this->address)) {
			throw "Wrong index";
		}
		return this->address[index];
	}

	friend void operator<<(ostream& out, SantaList list);
	friend void operator>>(istream& in, SantaList& list);

};

//overload of + (SantaList, int)
SantaList operator+(SantaList list, float value) {
	//don't
	//+, -, *, / don't change the input object
	//list.setBudget(list.getBudget() + value);

	SantaList result = list;
	result.setBudget(list.getBudget() + value);
	return result;
}

SantaList operator+(float value, SantaList list) {
	//return list + value; //if you already have it
	SantaList result = list;
	result.setBudget(list.getBudget() + value);
	return result;
}

bool operator==(SantaList& list1, SantaList& list2) {
	return list1.getBudget() == list2.getBudget();
}

void operator<<(ostream& out, SantaList list) {
	out << endl << "List name: " << list.kidName;
	out << endl << "Budget: " << list.budget;
	//if (list.address != nullptr) {
	//	out << endl << "Address: " << list.address;
	//}

	out << endl << (list.address != nullptr ? "Address: " + string(list.address) : "No address");
}

void operator>>(istream& in, SantaList& list) {
	cout << endl << "Budget: ";
	in >> list.budget;
	cout << endl << "Address: ";
	char buffer[100];
	in >> buffer;
	if (list.address != nullptr) {
		delete[] list.address;
		list.address = nullptr;
	}
	list.address = new char[strlen(buffer) + 1];
	strcpy(list.address, buffer);
	cout << endl << "Is a good kid (y/n):";
	string confirmation;
	in >> confirmation;
	if (confirmation == "y") {
		list.isNice = true;
	}
	else {
		list.isNice = false;
	}

}


void doSomething(SantaList s) {

}

SantaList doSomethingElse() {
	SantaList s;
	return s;
}

int main() {

	SantaList list;
	SantaList johnList("John", 100);
	SantaList aliceList("Alice", "Bucharest", 100);

	johnList.doesSomethingBad();

	list.print();
	johnList.print();
	aliceList.print();

	SantaList copy = aliceList;
	//johnList = aliceList;

	//math operators: +, - , /, *, +=, /=, +=, -=, *=
	// 

	johnList.print();
	
	cout << endl << "---------------------Operators ";

	//increase the budget
	johnList = johnList + 200;
	johnList.print();
	johnList = 200 + johnList;

	johnList.print();
	johnList *= 4.5;
	johnList.print();

	//conditional operators: <, >, >=, <=, ==, !=
	if (johnList <= 5000) {
		cout << endl << "John budget is less or equal to 5000";
	}
	else {
		cout << endl << "John budget is bigger than 5000";
	}

	if (johnList > aliceList) {
		cout << endl << "John has a bigger budget";
	}
	else {
		cout << endl << "Alice has a bigger/ equal budget";
	}

	if (johnList == aliceList) {
		cout << endl << "They have the same budget";
	}

	//stream operators <<, >>
	cout << johnList;
	cin >> johnList;
	cout << johnList;

	//negation operator
	if (!johnList) {
		cout << endl << "John budget is 0";
	}

	float estimateBudget = johnList(500);

	//++, --

	char secondAddressChar = johnList[1];
	johnList[1] = 'X';

	cout << johnList;
}
