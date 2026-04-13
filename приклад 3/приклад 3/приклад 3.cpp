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
// 3) ТРИ КЛАСИ: виклик віртуальної функції у методі
//    Передача посилання (&) на базовий клас
// ============================================================================

class LibraryPrinter {
public:
    void PrintByReference(const LibraryItem& item) {
        cout << "[Метод LibraryPrinter] ";
        item.PrintInfo(); // поліморфний виклик
    }
};

void Example3_ThreeClasses_MethodReference() {

    cout << "============================\n";
    cout << "3) ТРИ КЛАСИ: LibraryItem -> Book, Magazine\n";
    cout << "   Передача посилання (LibraryItem&)\n";
    cout << "   Виклик віртуальної функції у методі\n";
    cout << "============================\n";

    LibraryPrinter printer;

    LibraryItem item("Архів");
    Book book("C++ Primer", "Lippman");
    Magazine mag("IT World", 5);

    printer.PrintByReference(item);
    printer.PrintByReference(book);
    printer.PrintByReference(mag);

    cout << "\nАНАЛІЗ:\n";
    cout << "- Метод приймає const LibraryItem&.\n";
    cout << "- Передається посилання, а не копія.\n";
    cout << "- Завдяки virtual працює динамічний поліморфізм.\n";
    cout << "- Викликається відповідна версія PrintInfo().\n\n";
}

// ================= MAIN =================
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Example3_ThreeClasses_MethodReference();

    system("pause");
    return 0;
}