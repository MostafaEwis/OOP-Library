#ifndef SHIPPING_SERVICE_H
#define SHIPPING_SERVICE_H
#include <iostream>
#include <string>
#include <iomanip>

class ShippingService{
public:
	static int ship(int quantity, std::string address){
		std::cout << quantity << "x books will be shipped to your address isa: "  << address << std::endl;
		//each book costs 5 pounds
		return quantity * 5;
	}
};
#endif
