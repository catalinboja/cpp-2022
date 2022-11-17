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

		this->address = new char[strlen(list.address) + 1];
		memcpy(this->address,
			list.address,
			strlen(list.address) + 1);
	}

	void operator=(const SantaList& list) {
		//don't do it
		//this->kidName = list.kidName;

		this->budget = list.budget;
		this->isNice = list.isNice;

		if (this->address)
			delete[] this->address;

		this->address = new char[strlen(list.address) + 1];
		memcpy(this->address,
			list.address,
			strlen(list.address) + 1);

	}
};

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
	johnList = aliceList;
}
