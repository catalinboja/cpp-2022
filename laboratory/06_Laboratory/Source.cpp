#include <string>
#include <iostream>
using namespace std;

class Holiday {

	static int NO_HOLYDAYS_LOCATION;
public:

	const static string LOCATION;
private:
	string* locations = nullptr;
	int noLocations = 0;
	int noDays = 0;

public:
	Holiday(int noDays, string* locations, int noLocations) {
		this->noDays = noDays;
		this->noLocations = noLocations;
		//shalow copy
		//this->locations = locations;

		//deep copy
		bool hasTheLocation = false;

		this->locations = new string[this->noLocations];
		for (int i = 0; i < noLocations; i++) {
			this->locations[i] = locations[i];
			if (locations[i] == Holiday::LOCATION && !hasTheLocation) {
				Holiday::NO_HOLYDAYS_LOCATION += 1;
				hasTheLocation = true;
			}
		}
	}

	//the destructor
	~Holiday() {
		cout << endl << "Holiday destructor";
		if (this->locations != nullptr) {
			delete[] this->locations;
		}
	}

	static int getNoLocations() {
		return NO_HOLYDAYS_LOCATION;
	}

};

int Holiday::NO_HOLYDAYS_LOCATION = 0;
const string Holiday::LOCATION = "Bucharest";

int main() {

	string locations[] = {
		"Bucharest", "Sinaia", "Bucharest", "Tulcea", "Bucharest" };
	int noDays = 7;
	int noLocations = 5;

	Holiday romania(noDays, locations, noLocations);


	cout << endl << "No of Holidays in " << Holiday::LOCATION << " is "
		<< Holiday::getNoLocations();

	Holiday* newHoliday = new Holiday(noDays, locations, noLocations);
	delete newHoliday;


}