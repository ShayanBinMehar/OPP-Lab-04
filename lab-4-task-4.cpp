#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    double basePrice;
    double discountPercentage;
    int stock;

public:
    
    Book(const std::string& title, double basePrice, double discountPercentage, int stock)
      : title(title), basePrice(basePrice), discountPercentage(discountPercentage), stock(stock) {
        std::cout << "Book object created: " << title << std::endl;
    }

    Book(const Book& other)
      : title(other.title), basePrice(other.basePrice), discountPercentage(other.discountPercentage), stock(other.stock) {
        std::cout << "Book object copied: " << title << std::endl;
    }

    ~Book() {
        std::cout << "Book object destroyed: " << title << std::endl;
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
        std::cout << "Title: " << title << std::endl;
        std::cout << "Base Price: $" << basePrice << std::endl;
        std::cout << "Discount: " << discountPercentage << "%" << std::endl;
        std::cout << "Stock: " << stock << " units" << std::endl;
    }
};

int main() {
    Book myBook("The C++ Programming Language", 50.0, 10.0, 100);

    std::cout << "Initial Book Details:" << std::endl;
    myBook.displayBook();

    myBook.purchase(10);
    myBook.purchase(50);

    myBook.updateBook(60.0, 15.0, 50);

    std::cout << "\nUpdated Book Details:" << std::endl;
    myBook.displayBook();
}