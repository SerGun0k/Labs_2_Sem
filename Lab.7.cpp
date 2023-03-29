#include <iostream>
#include <vector>

enum class Color
{
	BLACK,
	WHITE,
	PINK
};

class Shape 
{
protected:
    double m_x, m_y;
    Color m_color; 
public:
    Shape(double x, double y, Color color) : m_x(x), m_y(y), m_color(color) {}
    virtual double Square() = 0;
};

class Triangle : public Shape 
{
private:
    int m_a, m_b, m_c;
public:
    Triangle(double x, double y, Color color, int a, int b, int c) : Shape(x, y, color), m_a(a), m_b(b), m_c(c) {}
    double Square() 
    {
        double p = (m_a + m_b + m_c) / 2; 
        return std::sqrt(p * (p - m_a) * (p - m_b) * (p - m_c)); 
    }
};

class Rectangle : public Shape 
{
private:
    double m_a, m_b;
public:
    Rectangle(double x, double y, Color color, double a, double b) : Shape(x, y, color), m_a(a), m_b(b) {}
    double Square() 
    {
        return m_a * m_b;
    }
};

class Circle : public Shape
{
private:
    double m_radius; 
    double PI = 3.14159265358979323;
public:
    Circle(int x, int y, Color color, double radius) : Shape(x, y, color), m_radius(radius) {}
    double Square() {
        return PI * m_radius * m_radius;
    }
};

int main() {
    std::vector<Shape*> shapes; // создание вектора указателей на базовый класс
    shapes.push_back(new Triangle(0, 0, Color::BLACK, 3, 4, 5)); 
    shapes.push_back(new Rectangle(0, 0, Color::PINK, 2, 4)); 
    shapes.push_back(new Circle(0, 0, Color::WHITE, 3)); 

    for (Shape* shape : shapes) 
    {
        std::cout << "Shape Square: " << shape->Square() << std::endl;
        std::cout << std::endl;
    }

    // очистка памяти
    for (Shape* shape : shapes) 
    {
        delete shape;
    }

    return 0;
}
