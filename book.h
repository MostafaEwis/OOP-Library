#ifndef BOOK_H
#define BOOK_H

class Book{
public:
	Book(std::string isbn_, std::string title_, int pubYear_, int price_):isbn(isbn_), title(title_), pubYear(pubYear_), price(price_){}
	virtual std::string getType() = 0;

	std::string getIsbn(){
		return isbn;
	}

	std::string getTitle(){
		return title;
	}
	int getPrice(){
		return price;
	}
	int getPubYear(){
		return pubYear;
	}
	void setPrice(int price_){
		price = price_;
	}
private:
	std::string isbn, title;
	int pubYear, price;
};

#endif
