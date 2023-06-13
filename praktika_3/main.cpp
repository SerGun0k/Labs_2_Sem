#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#define PI acos(-1)

class KinematicSolver 
{
private:
    double L1;
    double L2;
    double alpha;
    double beta;
public:
    KinematicSolver(double newL1, double newL2)
    {
        L1 = newL1;
        L2 = newL2;
    }

    void solve(double x, double y)
    {
        double B = sqrt(x * x + y * y);
        alpha = 180 * (acos(x / B) + acos((L1 * L1 - L2 * L2 + B * B) / (2 * B * L1))) / PI;
        beta = 180 * (PI - acos((L1 * L1 + L2 * L2 - B * B) / (2 * L1 * L2))) / PI;
        if (y < 0) {
            alpha *= -1;
            beta *= -1;
        }
    }

    void setJointsParams(double newL1, double newL2)
    {
        L1 = newL1;
        L2 = newL2;
    }

    double getAlpha() const
    {
        return alpha;
    }

    double getL1() const
    {
        return L1;
    }

    double getL2() const
    {
        return L2;
    }

    double getBeta() const
    {
        return beta;
    }
};

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 500), "praktika_3");


    KinematicSolver sample(100, 49);

    sf::Vector2f mousePosition;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseMoved) 
            {
                mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                double x = mousePosition.x - 500;
                double y = 250 - mousePosition.y;
                sample.solve(x, y);
            }
        }

        window.clear();

        sf::RectangleShape oX(sf::Vector2f(500.f, 1.f));
        oX.rotate(90.f);
        oX.setPosition(500, 0);
        window.draw(oX);
        sf::RectangleShape oY(sf::Vector2f(1000.f, 1.f));
        oY.setPosition(0, 250);
        window.draw(oY);

        sf::RectangleShape joint1(sf::Vector2f(sample.getL1(), 1.f));
        joint1.setPosition(500, 250);
        joint1.setFillColor(sf::Color::Green);
        sf::RectangleShape joint2(sf::Vector2f(sample.getL2(), 1.f));
        joint2.setFillColor(sf::Color::Red);

        joint1.rotate(-sample.getAlpha());
        
        joint2.setPosition(500.f + sample.getL1() * cos(sample.getAlpha() * PI / 180.f),
            250.f - sample.getL1() * sin(sample.getAlpha() * PI / 180.f));
        joint2.rotate(-sample.getAlpha() + sample.getBeta());
        window.draw(joint1);
        window.draw(joint2);
        joint1.rotate(sample.getAlpha());
        joint2.rotate(sample.getAlpha() - sample.getBeta());

        window.display();
    }

    return 0;
}



