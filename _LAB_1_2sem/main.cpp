#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <sstream>


class AnimatedText
{
private:
    double m_duration = 0;
    std::string m_text = "";

public:
    std::string textik = "";
    AnimatedText(double duration, std::string text)
    {
        textik = "";
        m_duration = duration;
        m_text = text;
    }
    double s4et()
    {
        return (m_duration / size(m_text));
    }

    void update(float time, int cur)
    {   
        Interaction(cur);
    }

    void Interaction(int cur)
    {
        if (size(m_text) < cur)
        {
            exit(0);
        }
        std::string sl = "";
        for (int i = 0; i < cur; i++)
        {
            sl += m_text[i];
        }
        textik = sl;

    }


    ~AnimatedText() {}
     
};

int main()
{
    int cur = 0;

    sf::Font font;//шрифт 
    font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
    sf::Text text("", font, 30);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    text.setStyle(sf::Text::Bold);//жирный текст.

    double duration;
    std::cout << "Duration: ";
    std::cin >> duration;
    std::string txt, a;
    std::cout << "Text: ";
    std::cin >> txt;
    a = txt;
    std::getline(std::cin, txt);
    txt = a + txt;
    AnimatedText Test(duration, txt);

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");


    float CurrentFrame = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 800 / 1000;


        std::ostringstream AnimationOfText;
        AnimationOfText << Test.textik;


        if (time > Test.s4et()) {
            cur += 1;
            Test.update(time, cur);
            clock.restart();
        }

        text.setString("Ваше слово: " + AnimationOfText.str());
        text.setPosition(50, 150);//задаем позицию текста
        text.setFillColor(sf::Color::Red);
        window.draw(text);//рисую этот текст
    





        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}