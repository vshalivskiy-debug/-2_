#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ================= БАЗОВИЙ КЛАС =================
class LibraryItem {
protected:
    string title;

public:
    LibraryItem(const string& t) : title(t) {}

    virtual void PrintInfo() const {
        cout << "Елемент бібліотеки: " << title << endl;
    }

    virtual ~LibraryItem() {}
};

// ================= ПОХІДНИЙ КЛАС =================
class Book : public LibraryItem {
private:
    string author;

public:
    Book(const string& t, const string& a)
        : LibraryItem(t), author(a) {
    }

    void PrintInfo() const override {
        cout << "Книга: " << title
            << ", Автор: " << author << endl;
    }
};

// ================= ПРИКЛАД =================
void Example1_TwoClasses() {
    cout << "=== Приклад: 2 класи, виклик віртуальної функції через покажчик (->) ===\n";

    LibraryItem baseItem("Загальний каталог");
    Book book("Кобзар", "Тарас Шевченко");

    LibraryItem* p1 = &baseItem; // покажчик на базовий
    LibraryItem* p2 = &book;     // базовий покажчик на похідний

    cout << "p1->PrintInfo(): ";
    p1->PrintInfo(); // LibraryItem::PrintInfo()

    cout << "p2->PrintInfo(): ";
    p2->PrintInfo(); // Book::PrintInfo() (поліморфізм)
}

int main() {
    // Встановлюємо кодування Windows-1251 для вводу/виводу консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Example1_TwoClasses();

    system("pause");
    return 0;
}