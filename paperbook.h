#ifndef	PAPER_BOOK_H
#define	PAPER_BOOK_H
#include "book.h"
#include <string>

class PaperBook : virtual public Book{
public:
	PaperBook(std::string isbn_, std::string title_, int pubYear_, int price_):Book(isbn_, title_, pubYear_, price_){}
	std::string getType(){
		return "paper";
	}
private:
};

#endif
