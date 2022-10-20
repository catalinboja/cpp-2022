#include <stdio.h>
#include <malloc.h>
//#include "myLibrary.h"


//global variable
//never to be used again at this course
int globalVariable = 10;

void doSomething() {
	printf("\n global = %d", globalVariable);
}

void doSomethingElse() {
	int vb = 20;

	int values[10000000];
	doSomethingElse();
}

int main() {


	//data types

	char character;		//1 byte
	short int shortInteger;   //2 bytes
	int integer; //4 bytes
	long longInteger; //4 bytes
	long long longLongInteger; //8 bytes
	unsigned int positiveInteger;	//4 bytes

	float floatVariable; //4 bytes
	double dooubleVariable; //8 bytes

	bool logicVariable;	//1 byte

	logicVariable = true;
	logicVariable = false;

	logicVariable = 23;	//is true
	logicVariable = 0; //is false

	//character = "a";
	character = 'a';
	printf("\n Value of character is %c", character);
	printf("\n Value of character is %d", character);

	character -= 32;

	//character = 'Z';
	character = 90;			//ASCII code for 'Z'


	printf("\n Value of character is %c", character);
	printf("\n Value of character is %d", character);


	printf("\n Size of longLongInteger is %d ",
		sizeof(longLongInteger));

	int variable;
	int vb2 = 10;
	printf("\n Hello C++!");
	variable = 10;
	variable = vb2 + 10;

	//return 0;

	//arrays
	//are stored on this function (main) stack
	//have a fix size -> you can't resize them
	const int n = 10;
	int numbers[n];	//static array of 10 integers
	float averages[10];			//static array of 10 floats
	char name[20];		//static array of 20 chars


	numbers[9] = 10;
	//numbers[10] = 11;
	//numbers[11] = 12;

	int vbNew = 23;

	for (int i = 0; i < 10; i++) {
		printf("\n Value at index %d is %d", i, numbers[i]);
	}

	//doSomethingElse();

	//dynamic arrays
	//THEY ARE NOT on the STACK
	//THEY are all in HEAP
	malloc(100);
	//allocate an array of 100 integers
	malloc(100 * sizeof(int));

	new int[100];

	int integerVariable;
	int* pointer;

	integerVariable = 100;

	pointer = (int*)100;

	pointer = new int[100];

	//we have created a memory leak
	
	pointer = new int[100];


}