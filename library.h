#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "book.h"
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
				if(inventory[entryNum].first -> getPubYear() + yearLimit <= currentYear){
					std::cout << "Removing book: " << inventory[entryNum].first -> getIsbn() << "." << std::endl;
					removeBook(inventory[entryNum].first);
				}
		}
		printTitle("Finsihed Stock Taking");
	}
	void addBook(Book* book, int quantity){
		bool bookExists = false;
		size_t entryNum = 0;
		//checking if the book already exists;
		while(entryNum < inventory.size() && !bookExists){
			if(book == inventory[entryNum].first){
				bookExists = true;
			}
			entryNum++;
		}
		printTitle("Addition Summary");
		if(bookExists){
			if(book -> getType() == "paper"){
				inventory[entryNum].second += quantity;
				std::cout << "increased \"" << book -> getTitle() << "\" by " << quantity << "." << std::endl;
			}else{
				std::cout << "This book already exists." << std::endl;
			}
		}else{
			inventory.push_back({book, quantity});
			std::cout << "Added \"" << book -> getTitle() << "\" to the inventory." << std::endl;
		}
	}
	int buyBook(std::string isbn, size_t quantity, std::string email, std::string address){
		int bookIndex = getBookIndex(isbn);	
		int totalPrice = 0;
		try{
			if(bookIndex < 0){
				throw std::invalid_argument("Book doens't exist");
			}
			if(inventory[bookIndex].second < quantity){
				throw std::invalid_argument("No enough books.");
			}
			totalPrice = inventory[bookIndex].first -> getPrice() * quantity;
			int shippingFees = 0;
			std::string bookType = inventory[bookIndex].first -> getType();
				if(bookType == "paper"){
					inventory[bookIndex].second -= quantity;
					shippingFees = ShippingService::ship(quantity, address);
				}else if(bookType == "EBook"){
					EmailService::email(email);
				}else if(bookType == "demo"){
					throw std::invalid_argument("Can't buy demo books");
				}else{ 
					throw std::invalid_argument("sorry, book can't be processed");
				}
			
			printTitle("** checkout reciept **");
			std::cout << std::left
				<<inventory[bookIndex].second << "x " <<
				std::setw(20) <<
				inventory[bookIndex].first -> getTitle() <<
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
	void removeBook(Book* book, int entry = -1){
		bool bookExists = false;
		if(entry < 0){
			size_t entryNum = inventory.size() - 1;
			while(entryNum >= 0 && !bookExists){
				if(inventory[entryNum].first == book){
					inventory.erase(inventory.begin() + entryNum);	
					bookExists = true;
				}
				entryNum--;
			}
		}else{
			inventory.erase(inventory.begin() + entry);	
			bookExists = true;
		}
		printTitle("REmoval summary");
		if(bookExists){
			std::cout << "Removed the book." << std::endl;
		}else{
			std::cout << "The book doesn't exist." << std::endl;
		}

	}
	int getBookIndex(std::string isbn){
		int entryNum = 0;
		while(entryNum < inventory.size()){
			if(inventory[entryNum].first -> getIsbn() == isbn){
				return entryNum;
			}
			entryNum++;
		}
		return -1;
	}
	std::vector<std::pair<Book*, int>> inventory;
};
#endif
