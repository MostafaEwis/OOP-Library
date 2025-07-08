#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "book.h"
#include "paperbook.h"
#include <utility>
#include "emailservice.h"
#include "shippingservice.h"
#include <iomanip>

class Library{
public: 
	Librar(){}
	void printTitle(std::string title){
		std::cout << "---------------------" << std::endl;
		std::cout << title << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	void stockTake(int yearLimit){
		//let's assume the current year is 2025
		int currentYear = 2025;
		printTitle("Started Stock Taking");
		for(int entryNum = inventory.size() - 1; entryNum >= 0; entryNum--){
				if(inventory[entryNum] -> getPubYear() + yearLimit <= currentYear){
					std::cout << "Removing book: " << inventory[entryNum] -> getIsbn() << "." << std::endl;
					removeBook(inventory[entryNum]);
				}
		}
		printTitle("Finsihed Stock Taking");
	}
	void addBook(Book* book, int quantity = 0){
		int entryNum = getBookIndex(book -> getIsbn());
		printTitle("Addition Summary");
		if(entryNum >= 0){
			if(book -> getType() == "paper"){
				dynamic_cast<PaperBook*>(inventory[entryNum]) -> changeStock(quantity);
				std::cout << "increased \"" << book -> getTitle() << "\" by " << quantity << "." << std::endl;
			}else{
				std::cout << "This book already exists." << std::endl;
			}
		}else{
			inventory.push_back(book);
			std::cout << "Added \"" << book -> getTitle() << "\" to the inventory." << std::endl;
		}
	}
	int buyBook(std::string isbn, size_t quantity, std::string address, std::string email){
		int bookIndex = getBookIndex(isbn);
		int totalPrice = 0;
		try{
			if(bookIndex < 0){
				throw std::invalid_argument("Book doens't exist");
			}
			std::string bookType = inventory[bookIndex] -> getType();
			//this is so ugly and should be refactored;
			if(bookType == "paper" && dynamic_cast<PaperBook*>(inventory[bookIndex]) -> getStock() < quantity){
				throw std::invalid_argument("No enough books.");
			}
			totalPrice = inventory[bookIndex] -> getPrice() * quantity;
			int shippingFees = 0;
				if(bookType == "paper"){
					dynamic_cast<PaperBook*>(inventory[bookIndex]) -> changeStock(-quantity);
					printTitle("Shipping Notice");	
					shippingFees = ShippingService::ship(quantity, address);
				}else if(bookType == "EBook"){
					printTitle("Email Notice");	
					EmailService::email(email);
				}else if(bookType == "demo"){
					throw std::invalid_argument("Can't buy demo books");
				}else{ 
					throw std::invalid_argument("sorry, book can't be processed");
				}
			std::string bookAmount = bookType == "paper" ? 	quantity + "x " : "";
			printTitle("** checkout reciept **");
			std::cout << std::left
				<<bookAmount<<
				std::setw(20) <<
				inventory[bookIndex] -> getTitle() <<
				totalPrice <<
				std::endl;
			std::cout << "subtotal: " << totalPrice << std::endl;
			std::cout << "shippingg fees: " << shippingFees << std::endl;
			std::cout << "amount: " << totalPrice + shippingFees << std::endl;

		}catch(std::invalid_argument error){
			std::cout << error.what() << std::endl;
		}
		return totalPrice;
	}

private:
	void removeBook(Book* book, int providedEntry = -1){
		int entryNum = providedEntry == -1 ? getBookIndex(book -> getIsbn()) : providedEntry;
		printTitle("Removal summary");
		if(entryNum >= -1){
			inventory.erase(inventory.begin() + entryNum);	
			std::cout << "Removed the book." << std::endl;
		}else{
			std::cout << "The book doesn't exist." << std::endl;
		}

	}
	int getBookIndex(std::string isbn){
		int entryNum = 0;
		while(entryNum < inventory.size()){
			if(inventory[entryNum] -> getIsbn() == isbn){
				return entryNum;
			}
			entryNum++;
		}
		return -1;
	}
	std::vector<Book*> inventory;
};
#endif
