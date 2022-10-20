#include <iostream>
using namespace std;

namespace mySpace{
	void printValue(int vb, const char* vbName) {
		std::cout << "\n " << vbName << " = " << vb;
	}
}

void interchangeValues(int , int );
void interchangeValues2(int* pointerA, int* pointerB);
void interchangeValues3(int& a, int& b);

int main() {

	int vb1 = 10;
	int vb2 = 20;

	//for printf we have <<
	//for scanf we have >>

	std::cout << "\n vb1 = " << vb1 << " and vb2 = " << vb2;
	cout << endl << " vb1 = " << vb1 << " and vb2 = " << vb2;
	mySpace::printValue(vb2,"vb2");

	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;

	mySpace::printValue(vb1, "vb1");
	mySpace::printValue(vb2, "vb2");

	interchangeValues(vb1, vb2);

	cout << endl << "----------------------------";

	mySpace::printValue(vb1, "vb1");
	mySpace::printValue(vb2, "vb2");

	interchangeValues2(&vb1, &vb2);

	cout << endl << "----------------------------";

	mySpace::printValue(vb1, "vb1");
	mySpace::printValue(vb2, "vb2");

	interchangeValues3(vb1, vb2);

	cout << endl << "----------------------------";

	mySpace::printValue(vb1, "vb1");
	mySpace::printValue(vb2, "vb2");

	return 0;
}

void interchangeValues(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interchangeValues2(int* pointerA, int* pointerB) {
	int temp = *pointerA;
	*pointerA = *pointerB;
	*pointerB = temp;


}

void interchangeValues3(int & a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}
