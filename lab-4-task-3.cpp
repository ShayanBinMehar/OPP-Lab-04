#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    double price;
    int stock;

public:
    Book(const std::string& title, double price, int stock): title(title), price(price), stock(stock) {
        std::cout << "Book object created: " << title << std::endl;
    }

    Book(const Book& other): title(other.title), price(other.price), stock(other.stock) {
        std::cout << "Book object copied: " << title << std::endl;
    }

    ~Book() {
        std::cout << "Book object destroyed: " << title << std::endl;
    }

    void updateBook(const std::string& newTitle, double newPrice, int newStock) {
        title = newTitle;
        price = newPrice;
        stock = newStock;
    }

    void displayBook() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << " units" << std::endl;
    }
};

int main() {

    Book originalBook("The C++ Programming Language", 49.99, 50);

    std::cout << "\nOriginal Book Details:" << std::endl;
    originalBook.displayBook();

    originalBook.updateBook("Effective Modern C++", 59.99, 40);

    std::cout << "\nUpdated Original Book Details:" << std::endl;
    originalBook.displayBook();

    Book copiedBook = originalBook;

    std::cout << "\nCopied Book Details:" << std::endl;
    copiedBook.displayBook();
}
