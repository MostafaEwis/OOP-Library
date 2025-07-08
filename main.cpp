#include <iostream>
#include "book.h"
#include "library.h"
#include "paperbook.h"
#include "Ebook.h"
#include "demobook.h"

using namespace std;

int main(int argc, char** argv){
	Library lib;
	Book* paperBook = new PaperBook("123", "100 years of solitude", 2023, 100, 5);
	Book* paperBook2 = new PaperBook("145", "Season of Migration to the North", 2025, 100, 5);
	Book* ebook = new EBook("153", "The castle", 2024, 100, "pdf");
	Book* demoBook = new DemoBook("133", "The Trial", 2025, 100);
	lib.addBook(paperBook);
	lib.addBook(paperBook, 2);
	lib.addBook(paperBook2);
	lib.addBook(ebook);
	lib.addBook(demoBook);
	lib.stockTake(2);
	lib.buyBook("125", 3, "askdfa;", "akdljfha;");
	//this book has been removed
	lib.buyBook("123", 3, "kafr thanks", "mostafa@dev.com");
	//succeful buy
	lib.buyBook("145", 3, "kafr thanks", "mostafa@dev.com");
	//unsucceful no stock
	lib.buyBook("145", 3, "kafr thanks", "mostafa@dev.com");
	//ebook buy example
	lib.buyBook("153", 3, "kafr thanks", "mostafa@dev.com");
	return 0;
}
