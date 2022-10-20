#include <stdio.h>


void changeVariableValue(int variable) {
	int vb;
	variable = 100;
}

void changeVariableValue2(int* pointerVariable) {
	int vb;
	*pointerVariable = 100;
}




int main() {


	int noStudents = 10;
	int* pointer;


	noStudents = 20;
	pointer = (int*)20;

	void* genericPointer;

	//will crash eveytime
	//printf("\n In RAM at address 20 the integer has a value of %d", *pointer);

	pointer = &noStudents;

	printf("\n Address of noStudents variable is %d", &noStudents);
	printf("\n The value of the pointer is %d", pointer);
	printf("\n The number of students is %d", *pointer);
	printf("\n The address of pointer is %d", &pointer);
	printf("\n The address of generic pointer is %d", &genericPointer);

	char name[20];

	pointer = new int[noStudents];
	//avoiding a memory leak
	delete[] pointer;

	pointer = new int;
	delete pointer;

	pointer = new int[40];
	//pointer = new int[noStudents];

	printf("\n The number of students is %d", noStudents);
	//changeVariableValue(noStudents);
	changeVariableValue2(&noStudents);
	printf("\n The number of students is %d", noStudents);

}