#include <iostream>
using namespace std;

void printArray(int* values, int noValues) {
	cout << endl << "The array values are: ";
	for (int i = 0; i < noValues; i++) {
		cout << " " << values[i];
	}
}

void initArray(int* array, int noValues, int defaultValue) {
	for (int i = 0; i < noValues; i++) {
		array[i] = defaultValue;
	}
}

int* copyAndInitArray(const int* array, int noValues, int newDefaultValue) {
	
	int* copy = new int[noValues];
	// //don't return pointer to static arrays defined in the function
	//int copy[1000];

	for (int i = 0; i < noValues; i++) {
		copy[i] = array[i];
	}
	
	for (int i = 0; i < noValues; i++) {
		copy[i] = newDefaultValue;
	}

	return copy;
}

void deleteValueFromArrayByIndex(int* array, int noValues, int index) {

	if (index < 0 || index >= noValues) {
		throw "Wrong index";
	}

	int* copy = new int[noValues - 1];
	for (int i = 0; i < index; i++) {
		copy[i] = array[i];
	}
	for (int i = index + 1; i < noValues; i++) {
		copy[i - 1] = array[i];
	}

	delete[] array;
	array = copy;
}



void doSomething() {
	int values[10000];
}

int main() {

	int noValues = 4;
	int values[] = { 10, 20, 30, 40 };

	int noMoreValues = 100;
	int* moreValues = new int[noMoreValues];

	printArray(values, noValues);
	printArray(moreValues, noMoreValues);

	initArray(moreValues,
		noMoreValues,
		0);
	printArray(moreValues, noMoreValues);


	int* copy = copyAndInitArray(moreValues,
		noMoreValues,
		10);

	cout << endl << "**************** The copy:";
	printArray(copy, noMoreValues);
	printArray(moreValues, noMoreValues);

	doSomething();
	printArray(copy, noMoreValues);

	cout << endl << "**************** After delete:";
	deleteValueFromArrayByIndex(copy, noMoreValues, 4);
	printArray(copy, noMoreValues - 1);
}