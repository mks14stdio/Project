// OOPLibrary.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <iostream>

struct Book {
    std::string Name;
    std::string Author;
    unsigned int Year;

    Book() {}
    Book(std::string n, std::string a, unsigned int y) {
        Name = n;
        Author = a;
        Year = y;
    }

    bool operator==(const Book& a) {
        if (Name == a.Name && Author == a.Author && Year == a.Year) {
            return true;
        }
        return false;
    }
};

class Library
{
public:
    Library() {}
    ~Library() {}

    bool addBooks(Book book) {
        for (auto it = Books.begin(); it != Books.end(); it++) {
            if (*it == book) {
                return false;
            }
        }
        Books.push_back(book);
        return true;
    }

    std::vector<Book> FindBookName(std::string name) {
        std::vector<Book> FindBooks;
        for (auto& i : Books) {
            if (i.Name == name) {
                FindBooks.push_back(i);
            }
            
        }
        return FindBooks;
    }
    std::vector<Book> FindBookAuthor(std::string author) {
        std::vector<Book> FindBooks;
        for (auto& i : Books) {
            if (i.Author == author) {
                FindBooks.push_back(i);
            }
            
        }
        return FindBooks;
    }
    std::vector<Book> FindBookYear(unsigned int year) {
        std::vector<Book> FindBooks;
        for (auto& i : Books) {
            if (i.Year == year) {
                FindBooks.push_back(i);
            }
            
        }
        return FindBooks;
    }

    bool removeBook(Book bookNeedRemove) {
        for (auto it = Books.begin(); it != Books.end(); it++) {
            if (*it == bookNeedRemove) {
                Books.erase(it);
                return true;
            }
        }
        return false;
    }

    bool loadFromFile(std::string path) {
        std::ifstream fil(path.c_str());
        if (!fil.is_open()) {
            return false;
        }
        Book nBook;
        std::string fileYear;
        fil >> nBook.Name;
        fil >> nBook.Author;
        fil >> nBook.Year;

        Books.push_back(nBook);
        fil.close();
        return true;
    }
    bool writeFile() {
        for (auto& i : Books) {
            std::string nameFile = i.Name + " " + i.Author + ".txt";
            std::ofstream fil(nameFile.c_str());
            if (!fil.is_open()) {
                return false;
            }
            fil << i.Name << "\n";
            fil << i.Author << "\n";
            fil << i.Year << "\n";
            fil.close();
        }
        return true;
    }


private:
    std::vector<Book> Books;
};


int main()
{
    Book b1("wef", "afwger", 2000);
    Book b2("zxc", "jk,", 2000);
    Book b3("qwe", "afwger", 2000);
    Book b4("tyh", "yuk", 2000);
    Book b5("fgb", "afwger", 2000);

    Library lib;
    lib.addBooks(b1);
    lib.addBooks(b2);
    lib.addBooks(b3);
    lib.addBooks(b4);
    lib.addBooks(b5);
    std::vector<Book> s = lib.FindBookAuthor("afwger");
    for (auto& i : s) {
        std::cout << i.Name << std::endl;
    }
    std::cout << std::endl;
    std::vector<Book> ss = lib.FindBookYear(2000);
    for (auto& i : ss) {
        std::cout << i.Author << std::endl;
    }
    std::cout << std::endl;
    std::vector<Book> sss = lib.FindBookName("qwe");
    for (auto& i : sss) {
        std::cout << i.Year << " ";
        std::cout << i.Author << std::endl;
    }
}
