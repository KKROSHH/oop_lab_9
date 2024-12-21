#include <iostream>
#include <string>
#include <limits>

// ������� ���� Car
class Car {
protected:
    std::string brand;
    std::string model;

public:
    // ����������� �������� �����
    Car(const std::string& brand = "", const std::string& model = "")
        : brand(brand), model(model) {}

    // ������ ��� ����� �����
    void input() {
        std::cout << "������ ����� ���������: ";
        std::cin >> brand;

        std::cout << "������ ������ ���������: ";
        std::cin >> model;
    }

    // ����� ��� ������ �����
    void display() const {
        std::cout << "�����: " << brand << ", ������: " << model;
    }
};

// ������� ���� CarDetails
class CarDetails : public Car {
private:
    int year;

public:
    // ����������� ���������� �����
    CarDetails(const std::string& brand = "", const std::string& model = "", int year = 0)
        : Car(brand, model), year(year) {}

    // ����� ��� ����� �����
    void input() {
        Car::input(); // ������ ������ ����� �������� �����

        while (true) {
            std::cout << "������ �� ������� ���������: ";
            std::cin >> year;

            // �������� ����
            if (std::cin.fail() || year < 1886 || year > 2024) {
                std::cout << "����������� ��. ��������� �� ���.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
    }

    // ����� ��� ������ �����
    void display() const {
        Car::display(); // ������ ������ ������ �������� �����
        std::cout << ", г� �������: " << year << '\n';
    }
};

int main() {
    // ��������� ��'���� ���������� �����
    CarDetails car;

    std::cout << "������ ��� ��� ���������:\n";
    car.input(); // �������� ����� ������������

    std::cout << "\n������ ��� ���������:\n";
    car.display(); // ���� ����� �� �����

    return 0;
}