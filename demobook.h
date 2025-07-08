#ifndef	DEMO_H
#define	DEMO_H
#include "book.h"
#include <string>

class DemoBook: virtual public Book{
public:
	DemoBook(std::string isbn_, std::string title_, int pubYear_, int price_, std::string fileType_):Book(isbn_, title_, pubYear_, price_){}

	std::string getType(){
		return "demo";
	}
};

#endif
