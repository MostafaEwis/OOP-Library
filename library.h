#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "book.h"
#include <utility>

class Library{
public: 
	Librar(){}
	void stockTake(){

	}
	void addBook(Book* book){
	}
	void removeBook(Book* book){

	}
	void buyBook(std::string isbn, int quantity, std::string email, std::string address){

	}

private:
	std::vector<std::pair<Book*, int>> inventory;
};
#endif
