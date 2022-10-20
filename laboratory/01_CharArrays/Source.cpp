//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


int main() {

	char lastName[50];
	char* firstName;

	std::cout << endl << "Hello world";


	lastName[10] = '\0';

	cout << endl << "The last name is " << lastName;

	lastName[0] = 'J';
	lastName[1] = 'o';
	//...

	//strcpy(lastName, "John");
	strcpy_s(lastName,sizeof(lastName)-1, "John");
	cout << endl << "The last name is " << lastName;

	char filename[50] = "students.txt";

	//filename = "university.txt";
	strcpy_s(filename, sizeof(filename) - 1, "university.txt");



	int maxNameSize = 50;

	//firstName = "Bob";

	firstName = new char[maxNameSize];

	//strcpy_s(firstName, strlen("Alexandru")+1, "Alexandru");
	strcpy_s(firstName, maxNameSize, "Alexandru");
	cout << endl << "first name " << firstName;

	delete[] firstName;


	//return 0;
}
