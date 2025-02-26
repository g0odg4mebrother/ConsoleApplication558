#include <iostream>
#include <string>
using namespace std;

// Класс для хранения даты
class Date {
public:
    int day;
    int month;
    int year;

    // Конструктор с параметрами
    Date(int d = 1, int m = 1, int y = 1900)
        : day(d), month(m), year(y) {
    }
};

// Класс Человек
class Human {
private:
    string firstName;
    string lastName;
    string middleName;
    Date birthDate;
    long idNumber;
    static int countInstances;  // Счетчик экземпляров

public:
    // Конструктор с параметрами
    Human(long id, const string& lName, const string& fName,
        const string& mName, const Date& bDate)
        : idNumber(id),
        lastName(lName),
        firstName(fName),
        middleName(mName),
        birthDate(bDate) {
        ++countInstances;
    }

    // Конструктор по умолчанию
    Human() : Human(0, "", "", "", Date()) {}

    // Конструктор копирования
    Human(const Human& other)
        : idNumber(other.idNumber),
        lastName(other.lastName),
        firstName(other.firstName),
        middleName(other.middleName),
        birthDate(other.birthDate) {
        ++countInstances;
    }

    // Деструктор 
    ~Human() {
        --countInstances;
    }

    static int getInstanceCount() {
        return countInstances;
    }

    // Геттеры
    long getIdNumber() const { return idNumber; }
    const string& getLastName() const { return lastName; }
    const string& getFirstName() const { return firstName; }
    const string& getMiddleName() const { return middleName; }
    const Date& getBirthDate() const { return birthDate; }

    // Сеттеры
    void setIdNumber(long id) { idNumber = id; }
    void setLastName(const string& name) { lastName = name; }
    void setFirstName(const string& name) { firstName = name; }
    void setMiddleName(const string& name) { middleName = name; }
    void setBirthDate(const Date& date) { birthDate = date; }

    // Вывод информации о человеке
    void printInfo() const {
        cout << "ID: " << idNumber << endl;
        cout << "Фамилия: " << lastName << endl;
        cout << "Имя: " << firstName << endl;
        cout << "Отчество: " << middleName << endl;
        cout << "Дата рождения: ";
        cout << birthDate.day << "." << birthDate.month << "." << birthDate.year << endl;
    }
};

int Human::countInstances = 0 ;

int main() {
    setlocale(LC_ALL, "");
    // Пример использования
    Date birthDate(10, 5, 1990);
    Date birthDate2(11, 4, 1996);

    Human person(1, "Иванов", "Иван", "Иванович", birthDate);
    Human person2(2, "Иванов", "Иван", "Иванович", birthDate2);

    person.printInfo();
    person2.printInfo();
    cout << "Количество созданных объектов: " << Human::getInstanceCount() << endl;

    return 0;
}