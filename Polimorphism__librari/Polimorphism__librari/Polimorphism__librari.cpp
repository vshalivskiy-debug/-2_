#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ===================== БАЗОВИЙ КЛАС =====================
class LibraryItem {
protected:
    string title;

public:
    LibraryItem(const string& t) : title(t) {}

    virtual void PrintInfo() const {
        cout << "Елемент бібліотеки: " << title << "\n";
    }

    virtual ~LibraryItem() {}
};

// ===================== КЛАС КНИГА =====================
class Book : public LibraryItem {
    string author;

public:
    Book(const string& t, const string& a)
        : LibraryItem(t), author(a) {
    }

    void PrintInfo() const override {
        cout << "Книга: " << title
            << " | Автор: " << author << "\n";
    }
};

// ===================== КЛАС ЖУРНАЛ =====================
class Magazine : public LibraryItem {
    int issueNumber;

public:
    Magazine(const string& t, int issue)
        : LibraryItem(t), issueNumber(issue) {
    }

    void PrintInfo() const override {
        cout << "Журнал: " << title
            << " | Номер випуску: " << issueNumber << "\n";
    }
};

// ===================== MAIN =====================
int main() {

    // Встановлення Windows-1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створення об'єктів
    Book book("Кобзар", "Тарас Шевченко");
    Magazine magazine("Наука і життя", 12);

    // Поліморфізм через покажчик
    LibraryItem* ptr1 = &book;
    LibraryItem* ptr2 = &magazine;

    cout << "Виклик через покажчик (->):\n";
    ptr1->PrintInfo();
    ptr2->PrintInfo();

    cout << "\n";

    // Поліморфізм через масив покажчиків
    LibraryItem* items[2];
    items[0] = &book;
    items[1] = &magazine;

    cout << "Вивід через масив покажчиків:\n";
    for (int i = 0; i < 2; i++) {
        items[i]->PrintInfo();
    }

    return 0;
}