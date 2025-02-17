#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    double price;
    int stock;

public:

Book() : title("Unknown"), price(0.0), stock(30) {}

    void updateBook(const std::string& newTitle, double newPrice, int newStock) {
        title = newTitle;
        price = newPrice;
        stock = newStock;
    }

    void purchase(int quantity) {
        if (stock >= quantity) {
            stock -= quantity;
            std::cout << quantity << " books purchased. Remaining stock: " << stock << std::endl;

            if (stock < 5) {
                std::cout << "Low stock warning: Only " << stock << " units remaining." << std::endl;
            }
        } else {
            std::cout << "Insufficient stock. Only " << stock << " units available." << std::endl;
        }
    }

    void displayBook() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << " units" << std::endl;
    }
};

int main() {
    Book myBook;

    std::cout << "Initial Book Details:" << std::endl;
    myBook.displayBook();

    myBook.updateBook("The C++ Programming Language", 49.99, 50);

    std::cout << "\nUpdated Book Details:" << std::endl;
    myBook.displayBook();

    myBook.purchase(10);
    myBook.purchase(45);
    myBook.purchase(10);
    return 0;
}