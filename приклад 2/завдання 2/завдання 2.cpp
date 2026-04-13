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

// ================= ПОХІДНИЙ КЛАС: BOOK =================
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

// ================= ПОХІДНИЙ КЛАС: MAGAZINE =================
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const string& t, int num)
        : LibraryItem(t), issueNumber(num) {
    }

    void PrintInfo() const override {
        cout << "Журнал: " << title
            << ", Номер випуску: " << issueNumber << endl;
    }
};

// ============================================================================
// 2) ТРИ КЛАСИ: передача у функцію покажчика (*) на базовий клас
// ============================================================================

void PrintItemByPointer(LibraryItem* p) {
    cout << "[Функція PrintItemByPointer] ";
    p->PrintInfo(); // поліморфний виклик
}

void Example2_ThreeClasses_FunctionPointer() {

    cout << "============================\n";
    cout << "2) ТРИ КЛАСИ: LibraryItem -> Book, Magazine\n";
    cout << "   Передача у функцію покажчика (LibraryItem*)\n";
    cout << "============================\n";

    LibraryItem item("Картотека");
    Book book("Clean Code", "Robert C. Martin");
    Magazine mag("Наука і життя", 12);

    PrintItemByPointer(&item);
    PrintItemByPointer(&book);
    PrintItemByPointer(&mag);

    cout << "\nАНАЛІЗ:\n";
    cout << "- Функція приймає LibraryItem*.\n";
    cout << "- Можна передати адресу будь-якого похідного класу.\n";
    cout << "- Завдяки virtual викликається правильна версія PrintInfo().\n\n";
}

// ================= MAIN =================
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Example2_ThreeClasses_FunctionPointer();

    system("pause");
    return 0;
}