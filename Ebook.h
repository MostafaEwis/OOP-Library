#ifndef	E_BOOK_H
#define	E_BOOK_H
#include <string>
#include "book.h"

class EBook: virtual public Book{
public:
	EBook(std::string isbn_, std::string title_, int pubYear_, int price_, std::string fileType_):Book(isbn_, title_, pubYear_, price_),
	fileType(fileType_){}

	std::string getType(){
		return "EBook";
	}
	std::string getFileType(){
		return fileType;
	}
private:
	std::string fileType;
};

#endif
