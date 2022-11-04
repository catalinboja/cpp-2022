#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int vbGlobal;

class Person {
public:
	char* name;
};

class MasterStudent : private Person {
	char* faculty;

	char* getName() {
		return this->name;
	}
};

class PhdStudent : public MasterStudent {

};

class Vehicle {
	int maxSpeed;
	float batteryLevel;
	int* kmPerDay;
	int noKm;
};

class Student {
	string name;
	const int age = 0;
public:
	static int maxNumberOfCourses;
	const static int maxGrades = 20;

};

void incrementValue(int & pValue) {
	pValue += 1;

}

void resizeArray(int** pointerPArray, int n) {
	*pointerPArray = new int[2*n];
}

void resizeArray(int* & pArray, int n) {
	pArray = new int[2 * n];
}

void resizeMatrix(int** & matrix, int n, int m) {
	//matrix = 
}

void resizeMatrix(int** * matrix, int n, int m) {
	//*matrix = 
}

int suma(int a, int b) {
	return a + b;
}

int diferenta(int a, int b) {
	auto vb = 10;
	return a - b;

}

int* allocateArray(int size) {
	return nullptr;
}


int Student::maxNumberOfCourses = 10;

int main() {
	static int something;

	const int constVariable = 10;

	Student john;
	Student alice;

	Student::maxNumberOfCourses = 10;


	cout << endl << "Hello";
	//constVariable = 20;

	//vbGlobal = 100;

	int value = 100;

	int* array = new int[100];
	int matrix[10][10];
	int** dynMatrix;

	int (*pf)(int, int) = suma;
	int rezultat = pf(2, 3);
	pf = diferenta;
	rezultat = pf(2, 3);

	int* (*pf2)(int) = allocateArray;

	vector<int> vectorInt;
	vectorInt.push_back(10);

	Person p1;
	p1.name;
	MasterStudent ms;
	//ms.name;
	_asm {
		MOV AX, 0
	}

	cout << endl << "Bye";
}