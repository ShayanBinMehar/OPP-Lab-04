#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    double basePrice;
    double discountPercentage;
    int stock;
    int bookId;
    static int bookCount; 

public:
    
    Book(const std::string& title, double basePrice, double discountPercentage, int stock)
      : title(title), basePrice(basePrice), discountPercentage(discountPercentage), stock(stock), bookId(++bookCount) {
        std::cout << "Book object created: " << title << " (ID: " << bookId << ")" << std::endl;
    }

    Book(const Book& other)
      : title(other.title), basePrice(other.basePrice), discountPercentage(other.discountPercentage), stock(other.stock), bookId(++bookCount) {
        std::cout << "Book object copied: " << title << " (ID: " << bookId << ")" << std::endl;
    }

    ~Book() {
        std::cout << "Book object destroyed: " << title << " (ID: " << bookId << ")" << std::endl;
    }

    double calculatePrice(int quantity) const {
        double discountedPrice = basePrice * (1.0 - discountPercentage / 100.0);
        return discountedPrice * quantity;
    }

    void purchase(int quantity) {
        if (stock >= quantity) {
            double totalPrice = calculatePrice(quantity);
            stock -= quantity;
            std::cout << quantity << " books purchased. Total price: $" << totalPrice << std::endl;

            if (stock < 5) {
                std::cout << "Low stock warning: Only " << stock << " units remaining." << std::endl;
            }
        } else {
            std::cout << "Insufficient stock. Only " << stock << " units available. You can purchase a maximum of " << stock << " units." << std::endl;
        }
    }

    void updateBook(double basePrice, double discountPercentage, int stock) {
        this->basePrice = basePrice;
        this->discountPercentage = discountPercentage;
        this->stock = stock;
    }

    void displayBook() const {
        std::cout << "Book ID: " << bookId << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Base Price: $" << basePrice << std::endl;
        std::cout << "Discount: " << discountPercentage << "%" << std::endl;
        std::cout << "Stock: " << stock << " units" << std::endl;
    }
};

int Book::bookCount = 0;

int main() {
    
    Book book1("The C++ Programming Language", 50.0, 10.0, 100);
    Book book2("Effective Modern C++", 60.0, 15.0, 50);

    std::cout << "\nBook 1 Details:" << std::endl;
    book1.displayBook();
    std::cout << "\nBook 2 Details:" << std::endl;
    book2.displayBook();

    Book book3 = book1;

    std::cout << "\nCopied Book Details:" << std::endl;
    book3.displayBook();

    return 0;
}