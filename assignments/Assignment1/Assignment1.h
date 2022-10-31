#pragma once

#include <iostream>
#include <exception>
#include <string.h>

#pragma once

using namespace std;



/*

Sa se implementeze functia getDiscountedPrice() ce calculeaza pretul cu discount.
@Input
- accountType: tipul contului clientului; tipul are asociata a valoare specifica
- initialPrice: pretul initial al produsului
- discountAsPercentage: discount-ul acordat ca si procent (20 -> 20%, 30 -> 30%, 12.5 -> 12.5%)

Pretul final se calculeaza aplicand discount-ul primit din pretul initial.In functie de tipul clientului
se va acorda un discount suplimentar.

Important! Daca discountAsPercentage este 0 atunci se returneaza pretul initial, indiferent de tipul clientului

Exemplu
- getDiscountedPrice(FREE,1000,10) trebuie sa returneze 900
- getDiscountedPrice(PREMIUM,1000,10) trebuie sa returneze 810
- getDiscountedPrice(BUSINESS,1000,10) trebuie sa returneze 720
- getDiscountedPrice(GOLD,1000,10) trebuie sa returneze 630
- getDiscountedPrice(GOLD,1000,0) trebuie sa returneze 1000


*/

/*

Implement the getDiscountedPrice() function that calculates the discounted price.
@Input
- accountType: customer account type with a predefined value
- initialPrice: initial price of the product
- discountAsPercentage: the discount granted as a percentage (20 -> 20%, 30 -> 30%, 12.5 -> 12.5%)

The final price is calculated by applying the discount received from the initial price, depending on the type of customer
an additional discount will be granted.

Important! If discountAsPercentage is 0, then the initial price is returned, regardless of the type of customer

Example
- getDiscountedPrice(FREE,1000,10) must return 900
- getDiscountedPrice(PREMIUM,1000,10) must return 810
- getDiscountedPrice(BUSINESS,1000,10) must return 720
- getDiscountedPrice(GOLD,1000,10) must return 630
- getDiscountedPrice(GOLD,1000,0) must return 1000


*/

enum AccountType { FREE = 0, PREMIUM = 10, BUSINESS = 20, GOLD = 30 };

float getDiscountedPrice(AccountType accountType, float initialPrice, float discountAsPercentage) {
	return 0;
}


/*
	Sa se implementeze metoda toTitleCase(char* text) care transforma un text primit in formatul Title Case
	- toate cuvintele incep cu majuscula
	- ex: "salut. acesta este un test" devine "Salut. Acesta Este Un Test"

	Implement the toTitleCase (char * text) method that converts received text to Title Case format
	- all words start with a capital letter
	- ex: "hello. this is a test" becomes "Hello. This Is A Test"
*/

char* toTitleCase(const char* text) {
	return nullptr;
}


/*
	Sa se implementeze metoda removeSpaces(char* text) care elimina toate spatiile dintr-un text primit
	- se iau in considerare toate spatiile (la inceput, la final si in interior)
	- ex: " salut.   acesta este un test " devine "salut.acestaesteuntest"


	Implement the removeSpaces (char * text) method which removes all spaces from a received text
	- all spaces are taken into account (at the beginning, at the end and inside)
	- ex: "hello. this is a test" becomes "hello.thisisatest"
	- ex: "    hello. this is a test   " becomes "hello.thisisatest"
*/

char* removeSpaces(const char* text) {
	return nullptr;
}


/*
Sa se implementeze metoda noBiggerThanValues ce determina numarul de elemente din vector ce sunt mai mari sau egale cu valoarea data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- numarul de elemente din vector ce sunt mai mari sau egale cu valoarea data
*/

/*

Implement the noBiggerThanValues method that determines the number of elements in the vector that are greater than or equal to the given value

input
- a vector of integers
- vector size
- a given value
return
- the number of elements in the vector that are greater than or equal to the given value


*/

int noBiggerThanValues(int* values, int noValues, int checkedValue) {
	return -1;
}

/*
Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- un vector nou (creat in HEAP) ce contine toate elementele mai mari sau egale cu valoarea prag
- NULL daca in vectorul initial nu exista elemente mai mari sau egale
*/

/*

The function extracts from a given vector all the elements that are greater than or equal to a given threshold value

input
- a vector of integers
- vector size
- a given value
return
- a new vector (created in HEAP) containing all elements greater than or equal to the threshold value
- NULL if there are no greater or equal elements in the initial vector

*/

int* filterValuesBiggerThan(int* values, int noValues, int checkedValue) {
	return nullptr;
}


/*
Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- un vector nou ce contine toate elementele mai mari sau egale cu valoarea prag; pointerul catre noul vector este primit in lista de argumente
- NULL daca in vectorul initial nu exista elemente mai mari sau egale
*/

void filterValuesBiggerThanVersion2(const int* valori, int nrValori, int valoarePrag, int** valoriMaiMari) {

}

/*
Functia extrage elementul de pe pozitia index

input
- un vector de numere intregi
- dimensiunea vectorului
- indexul elementului (valoare pentru index trebuie sa fie validata) - daca valoarea 
pentru index nu este ok atunci se returneaza INT32_MIN
return
- elementul de pe pozitia index
- INT32_MIN daca indexul nu este valid
*/


/*
The function extracts the item from the index position

input
- an integer vector
- vector size
- element index (value for index must be validated) - if the value for index is not ok then return INT32_MIN
return
- the item on the index position
- INT32_MIN if the index is invalid
*/

int getElement(const int* valori, int nrValori, int index) {
	return -1;
}


/*
Functia extrage un subvector din vectorul primit - [index_start, index_final]

input
- un vector de numere intregi
- dimensiunea vectorului
- index start si index final
	- daca valoarea pentru oricare index nu este ok atunci se returneaza null pointer
	- daca index start este egal cu index final atunci se returneaza un sub-vector ce contine elementul de pe pozitia index start
	- daca index start este mai mare decat index final atunci se returneaza nullptr
return
- un vector nou
- dimensiunea vectorului nou este returnata prin referinta dimensiuneSubvector din lista de argumente
- nullptr daca indexul nu este valid
*/

/*

The function extracts a subvector from the received vector - [index_start, index_final]

input
- an integer vector
- vector size
- start index and final index
- if the value for any index is not ok then return nullptr
- if the start index is equal to the final index then a sub-vector is returned that contains the element from the start index position
- if the start index is higher than the final index then return nullptr
return
- a new vector
- the size of the new vector is returned by the sizeSubvector reference in the argument list
- nullptr if the index is invalid

*/

int* slice(const int* valori, int nrValori, int indexStart, int indexFinal, int& dimensiuneSubvector) {
	return nullptr;
}

