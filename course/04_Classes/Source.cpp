#include <iostream>
#include<string>

enum Group { g1065, g1066, g1067, g1068 };

class Student {

	char* name;
	std::string address;
	char faculty[100];
	int age;
	bool hasScholaship;
	Group group;
	int noGrades;
	int* grades;
	char** courses;		//array of strings
	//char* courses[100];
	//std::string* courses;


};