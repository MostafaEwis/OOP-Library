#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H
#include <iostream>
#include <string>
#include <iomanip>

class EmailService{
public:
	static void email(std::string email){
		std::cout << "Book has been sent to your email: " << email << std::endl;
	}
};
#endif
