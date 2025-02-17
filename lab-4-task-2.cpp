#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    double price;
    int stock;

public:
    Book(const std::string& title, double price, int stock) : title(title), price(price), stock(stock) {}

    void applyDiscount(int quantity) {
        if (quantity > 10) {
            price *= 0.90; 
        } else if (quantity > 5) {
            price *= 0.95;
        }
    }

    void purchase(int quantity) {
        if (stock >= quantity) {
            applyDiscount(quantity); 
            stock -= quantity;
            std::cout << quantity << " books purchased. Total price after discount: $" << price * quantity << std::endl;

            if (stock < 5) {
                std::cout << "Low stock warning: Only " << stock << " units remaining." << std::endl;
            }
        } else {
            std::cout << "Insufficient stock. Only " << stock << " units available. You can purchase a maximum of " << stock << " units." << std::endl;
        }
    }

    void displayBook() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << " units" << std::endl;
    }
};

int main() {
    Book myBook("The C++ Programming Language", 49.99, 50);

    std::cout << "Initial Book Details:" << std::endl;
    myBook.displayBook();

    myBook.purchase(10);
    myBook.purchase(15); 
    myBook.purchase(40); 

    std::cout << "\nUpdated Book Details:" << std::endl;
    myBook.displayBook();

    return 0;
}