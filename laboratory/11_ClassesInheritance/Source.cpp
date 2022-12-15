#include <iostream>
#include <string>
using namespace std;

class Product
{
	const int id;
	float price;
	string name;
	static int PRODUCTS_WITH_PRICE_ABOVE_100;
public:
	static const float MIN_PRICE;

	Product(int id, float Price, string Name)
		:id(id), price(Price), name(Name)
	{
		if (Price < MIN_PRICE)
			throw "Price too small";
		if (Price > 100) {
			PRODUCTS_WITH_PRICE_ABOVE_100 += 1;
		}
	}

	virtual void print() {
		cout << endl << "Product data: ";
		cout << endl << "Price: " << this->price;
		cout << endl << "Name: " << this->name;
		cout << endl << "Id: " << this->id;
	}
};

int Product::PRODUCTS_WITH_PRICE_ABOVE_100 = 0;
const float Product::MIN_PRICE = 0.1;

class DiscountProduct : public Product {
	float discountPercentage; //10 is 10%

public:
	DiscountProduct():Product(0,MIN_PRICE,"") {

	}

	DiscountProduct(
		int Id, float Price, string Name, float Discount)
		:Product(Id,Price,Name), discountPercentage(Discount)
	{
		//this->discountPercentage = Discount;
	}

	//void printProductWithDiscount() {
	//	this->print();
	//	cout << endl << "Discount "
	//		<< this->discountPercentage << "%";
	//}

	//override the Product print method
	void print()
	{
		//calling the parent/Product version
		this->Product::print();
		cout << endl << "Discount "
			<< this->discountPercentage << "%";
	}

};

int main() {
	Product laptop(1, 1300, "Asus laptop");
	laptop.print();

	//Product laptops[2];
	Product* laptops[3];


	//DON't MIX THEM - USE ONLY objects in HEAP
	//laptops[0] = &laptop;
	//laptops[1] = &Product(2, 2500, "Lenovo laptop");
	//laptops[2] = new Product(3, 2220, " HP laptop");

	laptops[0] = new Product(laptop);
	laptops[1] = new Product(2, 2500, "Lenovo laptop");
	laptops[2] = new Product(3, 2220, " HP laptop");

	cout << endl << "**********Laptops stock:************";
	for (int i = 0; i < 3; i++) {
		laptops[i]->print();
	}

	//inheritance part
	DiscountProduct laptopOnSale(4,3200,"Lenovo laptop",15);

	//calling the Product version
	laptopOnSale.Product::print();

	//calling the defaul Discount Product version
	laptopOnSale.print();

	
	cout << endl << "******* IT Shop Stock************";

	//managing the entire stock
	Product* stock[3];
	stock[0] = new Product(1, 2200, "Samsung smartphone");
	//up-casting
	stock[1] = new DiscountProduct(2, 3500, "Gaming laptop", 20);
	//up casting
	stock[2] = new DiscountProduct(3, 1000, "Mouse", 50);

	for (int i = 0; i < 3; i++) {
		stock[i]->print();
	}



	//laptopOnSale.printProductWithDiscount();


}