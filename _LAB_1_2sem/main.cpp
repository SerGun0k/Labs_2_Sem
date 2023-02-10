#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <windows.h>
#include <sstream>


class AnimatedText
{
private:
    double m_duration = 0;
    std::string m_text;

public:
    AnimatedText(const double& duration, std::string text)
    {
        m_duration = duration;
        m_text = text;
    }
    double s4et()
    {
        return (m_duration) / size(m_text);
    }

    double GetDuration()
    {
        return m_duration;
    }

    std::string update(float time_main)
    {
        std::string Out;
        for (int i = 0; i <= (time_main / s4et()); i++)
        {
            Out += m_text[i];
        }
        return (Out);
    }



    ~AnimatedText() {}

};

bool Checking(float timing, double duration)
{
    if (timing > duration) 
    {
        Sleep(500);
        exit(0);
    }

}

int main()
{


    sf::Font font_1;//шрифт 
    font_1.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
    sf::Text Font("", font_1, 30);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    Font.setStyle(sf::Text::Bold);//жирный текст.

    double duration;
    std::cout << "Duration: ";
    std::cin >> duration;
    std::string txt, a;
    std::cout << "Text: ";
    std::cin >> txt;
    a = txt;
    std::getline(std::cin, txt);
    txt = a + txt;
    AnimatedText Main_text(duration, txt);

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");



    float CurrentFrame = 0;
    sf::Clock clock_main;
    sf::Clock clock_restart;

    while (window.isOpen())
    {

        float time_main = clock_main.getElapsedTime().asMicroseconds();
        float time_restart = clock_restart.getElapsedTime().asMicroseconds();
        time_main = time_main / 800 / 1000 ;
        time_restart = time_restart / 800 / 1000;


        std::ostringstream AnimationOfText;

        AnimationOfText << Main_text.update(time_main);
        Font.setString("Text: " + AnimationOfText.str());

        if (time_restart > Main_text.s4et())
        {
            std::cout << time_restart << std::endl;
            clock_restart.restart();
        }

        Font.setPosition(50, 150);
        window.draw(Font);

        Checking(time_main, Main_text.GetDuration());

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(Font);
        window.display();
    }
    return 0;
}
