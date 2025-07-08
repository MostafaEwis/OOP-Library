#include <iostream>
#include "book.h"
#include "library.h"
#include "paperbook.h"
#include "Ebook.h"
#include "demobook.h"

using namespace std;

int main(int argc, char** argv){
	Library lib;
	Book* paperBook = new PaperBook("123", "100 years of solitude", 2023, 100);
	Book* ebook = new EBook("153", "The castle",2014, 100, "pdf");
	Book* demoBook = new DemoBook("133", "The Trial", 2025, 100);
	lib.addBook(paperBook, 5);
	lib.addBook(paperBook, 5);
	lib.addBook(ebook, 5);
	lib.addBook(demoBook, 5);
	lib.stockTake(2);
	return 0;
}
