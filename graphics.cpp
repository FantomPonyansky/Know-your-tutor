#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <queue>
#include <random>
#include <cstdlib>
#include <time.h>

sf::Event event;
sf::Clock Timer;
float Time_Left;
unsigned int counter = 10;

std::queue<std::string> Create_Fucker_Queue()
//This function creates queue which is containing names of pictures with fuckers
{
    std::queue<std::string> Fucker_Queue;
    long rndm_1;
    long rndm_2;
    srand(time(nullptr));
    std::string Current_Fucker;
    for (int k = 0; k < 10; k++) {
        rndm_1 = random() % 8;
        rndm_2 = random() % 2;

        if (rndm_2 == 0)
            Current_Fucker = std::to_string(rndm_1) + "n" + ".jpeg";

        if (rndm_2 == 1)
            Current_Fucker = std::to_string(rndm_1) + "f" + ".jpeg";

        Fucker_Queue.push(Current_Fucker);
    }
    return Fucker_Queue;
}

unsigned int Get_Screen_Width()
{
    //FIXME
    return 400;
}

unsigned int Get_Screen_Height()
{
    //FIXME
    return 700;
}

void Draw_Fucker(sf::RenderWindow& window, std::string Fucker_Name)
//This function gets window and draw in it picture of fucker, whose name is also given
{
    sf::Image FuckerImage;
    FuckerImage.loadFromFile(Fucker_Name);
    sf::Texture FuckerTexture;
    FuckerTexture.loadFromImage(FuckerImage);
    sf::Sprite FuckerSprite;
    FuckerSprite.setTexture(FuckerTexture);
    FuckerSprite.setPosition(0, 100);
    window.draw(FuckerSprite);
}

void Draw_Inscription(sf::RenderWindow& window, std::string inscription, std::queue<std::string>& EventQueue, bool proyob)
{
    sf::Text Inscription;
    sf::Font font;
    font.loadFromFile("ARIAL.TTF");
    Inscription.setFont(font);
    Inscription.setColor(sf::Color(34, 139, 34));
    Inscription.setCharacterSize(18);
    unsigned int xpos;
    if (proyob)
        xpos = 110;
    else
        xpos = 50;
    Inscription.setPosition(xpos, 350);
    Inscription.setString(inscription);
    while (window.isOpen())
    {
        if (proyob)
            window.clear(sf::Color(139, 0, 0));
        else
            window.clear(sf::Color(164, 211, 238));
        window.draw(Inscription);
        window.display();
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                {
                    EventQueue.push("30");
                    window.close();
                    break;
                }
            }
        }
    }
}

bool Is_A_Fucker(std::string Fucker_Name)
{
    bool Is_He = true;
    if (Fucker_Name[1] == 'f')
        Is_He = true;
    if (Fucker_Name[1] == 'n')
        Is_He = false;
    return Is_He;
}

void Battle(sf::RenderWindow& window, std::queue<std::string>& Fucker_Queue, std::queue<std::string>& EventQueue) {
    counter -= 1;
    Timer.restart();
    Time_Left -= 0.1;
    std::string Fucker_Name = Fucker_Queue.front();
    Fucker_Queue.pop();
    sf::Text How_Many_Tutors_Left;
    sf::Font font;
    font.loadFromFile("ARIAL.TTF");
    How_Many_Tutors_Left.setFont(font);
    How_Many_Tutors_Left.setColor(sf::Color::Magenta);
    How_Many_Tutors_Left.setCharacterSize(18);
    How_Many_Tutors_Left.setPosition(5, 5);
    std::string Warning_Sign = "Tutors left: " + std::to_string(counter);
    How_Many_Tutors_Left.setString(Warning_Sign);
    while (window.isOpen()) {
        window.clear();
        window.draw(How_Many_Tutors_Left);
        Draw_Fucker(window, "Fuckers/" + Fucker_Name);
        window.display();
        if (Timer.getElapsedTime().asSeconds() >= Time_Left)
        {
            if (Is_A_Fucker(Fucker_Name))
            {
                EventQueue.push("10");
                Draw_Inscription(window, "You have been FUCKED", EventQueue, true);
            }
            else
            {
                EventQueue.push("01");
                Draw_Inscription(window, "You are going down for ABRAMOVKA", EventQueue, false);
            }
        }
        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::KeyPressed: {

                    if (event.key.code == sf::Keyboard::Y) {
                        if (Is_A_Fucker(Fucker_Name)) {
                            EventQueue.push("10");
                            Draw_Inscription(window, "You have been FUCKED", EventQueue, true);
                        }
                        else {
                            EventQueue.push("01");
                            Draw_Inscription(window, "You are going down for ABRAMOVKA", EventQueue, false);
                        }
                    }

                    if (event.key.code == sf::Keyboard::N) {
                        if (Is_A_Fucker(Fucker_Name)) {
                            EventQueue.push("11");
                            if (Fucker_Queue.empty())
                                Draw_Inscription(window, "You have been FUCKED", EventQueue, true);
                            Battle(window, Fucker_Queue, EventQueue);
                        }
                        else {
                            EventQueue.push("00");
                            if (Fucker_Queue.empty())
                                Draw_Inscription(window, "You have been FUCKED", EventQueue, true);
                            Battle(window, Fucker_Queue, EventQueue);
                        }
                    }
                }

                case sf::Event::Closed:
                {
                    EventQueue.push("30");
                    window.close();
                    break;
                }
            }
        }
    }
}

void Start_Game(sf::RenderWindow& window, std::queue<std::string>& EventQueue)
//This function asks main who is the first fucker and tell audio thread to start
{
    EventQueue.push("20");
    Time_Left = 3.1;
    while (window.isOpen())
    {
        std::queue<std::string> Fucker_Queue = Create_Fucker_Queue();
        Battle(window, Fucker_Queue, EventQueue);
    }
}

std::string Get_Rules_From_File(){

    std::string sf;
    std::ifstream inf;

    inf.open ( "Rules.txt" );

    getline ( inf, sf, '\0' );

    inf.close();

    return sf;

}

void Create_Window(std::queue<std::string>& EventQueue)
//This function only display rules and call game-function when start-key pressed and close if close-key pressed
{
    unsigned int screen_width = Get_Screen_Width();
    unsigned int screen_height = Get_Screen_Height();
    sf::RenderWindow MainWindow(sf::VideoMode(screen_width, screen_height), "My window", sf::Style::Close);
    sf::Text rules;
    sf::Font font;
    font.loadFromFile("ARIAL.TTF");
    rules.setFont(font);
    rules.setColor(sf::Color::Magenta);
    rules.setCharacterSize(18);
    rules.setPosition(5, 5);
    std::string RulesInString = Get_Rules_From_File();
    rules.setString(RulesInString);
    while (MainWindow.isOpen()) {

        MainWindow.clear(sf::Color(0, 0, 0, 255));
        MainWindow.draw(rules);
        MainWindow.display();

        while (MainWindow.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::KeyPressed: {

                    if (event.key.code == sf::Keyboard::Escape) {
                        EventQueue.push("30");
                        MainWindow.close();
                    }

                    if (event.key.code == sf::Keyboard::S) {
                        Start_Game(MainWindow, EventQueue);
                    }
                }

                case sf::Event::Closed:
                    EventQueue.push("30");
                    MainWindow.close();
                    break;

            }
        }
    }
}
