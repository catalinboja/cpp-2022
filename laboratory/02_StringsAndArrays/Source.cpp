#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

char* readDynamicCharArray() {
	char* value;
	char buffer[1000];
	std::cout << std::endl << "Give me the string value: ";
	std::cin >> buffer;
	value = new char[strlen(buffer) + 1];
	strcpy(value, buffer);
	return value;
}

char* concatenateCharArrays(char* string1, const char* string2) {
	char* result = new char[strlen(string1) + strlen(string2) + 1];
	strcpy(result, string1);
	strcat(result, string2);
	return result;
}

int main() {

	char filename[50];
	char temp[50];
	char* folder;	//is default 0xCCCC....

	//reading static arrays of chars

	//read the filename
	//if you exceed more than 50 chars will crash or ....
	//space is a delimiter for >>
	std::cout << std::endl << "Give me the filename: ";
	//std::cin >> filename;

	//reading space inside the input
	std::cin.getline(filename, sizeof(filename) - 1);

	std::cout << std::endl << "Give me temp: ";
	std::cin >> temp;

	std::cout << std::endl << "The file name is " << filename;
	std::cout << std::endl << "The temp name is " << temp;
	//std::cout << std::endl << "The folder name is " << folder;


	//reading dynamic arrays of chars
	std::cout << std::endl << "Give me the folder name: ";

	//allocate the dynamic char array
	//define a static buffer big enough for any string
	char buffer[1000];
	std::cin >> buffer;

	folder = new char[strlen(buffer) + 1];	//extra byte for \0
	strcpy(folder, buffer);

	std::cout << std::endl << "The folder name is " << folder;

	//avoid the memory leak
	delete[] folder;
	folder = readDynamicCharArray();

	std::cout << std::endl << "The folder name is " << folder;

	//char* newFolderName =  concatenateCharArrays(folder, " OOP");

	//delete[] folder;
	//folder = concatenateCharArrays(folder, " OOP");

	char* newFolderName = concatenateCharArrays(folder, " OOP");

	delete[] folder;
	folder = newFolderName;

	std::cout << std::endl << "The folder name is " << folder;

	return 0;
}