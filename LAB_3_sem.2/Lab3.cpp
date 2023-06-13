#include<iostream>

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) 
    {
        real = r;
        imag = i;
    }

    // Конструктор копирования
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    Complex operator=(const Complex& other) // Оператор присваивания копированием
    {
        real = other.real;
        imag = other.imag;
        return *this;
        /* без* this было бы
        Complex operator=(const Complex & other){
            Complex a;
            a.real = other.real;
            a.imaginary = other.imaginary;
            return a; 
        }*/
    }

    ~Complex() {} // Деструктор

    // оператор +=
    Complex operator+=(const Complex& other)
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // оператор +
    friend Complex operator+(Complex c1, const Complex& c2) 
    {
        return c1 += c2;
    }

    // оператор *=
    Complex operator*=(const Complex& other) 
    {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    // оператор *
    friend Complex operator*(Complex c1, const Complex& c2) 
    {
        return c1 *= c2;
    }

    // префиксный оператор ++
    Complex& operator++() 
    {
        ++real;
        return *this;
    }

    // постфиксный оператор ++
    Complex operator++(int) 
    {
        Complex temp(*this);
        ++(*this);
        return temp;
    }

    // оператор ввода
    friend std::istream& operator>>(std::istream& in, Complex& other) 
    {
        std::cout << "Введите действительную часть: ";
        in >> other.real;
        std::cout << "Введите мнимую часть: ";
        in >> other.imag;
        return in;
    }

    // оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const Complex& other)
    {
        if (other.imag >= 0)
        {
            out << other.real << " + " << other.imag << "i";
            return out;
        }
        else
        {
            out << other.real << " - " << abs(other.imag) << "i";
            return out;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "russian");
    Complex a(2, 3);
    Complex b(4, 5);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    Complex c = a + b;
    std::cout << "a + b = " << c << std::endl;

    a += b;
    std::cout << "a += b: a = " << a << std::endl;

    Complex d = a * b;
    std::cout << "a * b = " << d << std::endl;

    a *= b;
    std::cout << "a *= b: a = " << a << std::endl;

    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;

    Complex e;
    std::cin >> e;
    std::cout << "Вы ввели: " << e << std::endl;

    return 0;
}