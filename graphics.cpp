#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <queue>

sf::Event event;
unsigned int counter = 10;

std::queue<std::string> Create_Fucker_Queue()
//This function creates queue which is containing names of pictures with fuckers
{
    std::queue<std::string> Fucker_Queue;
    Fucker_Queue.push("Bek.jpeg");
    //FIXME
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

void Battle(sf::RenderWindow& window, std::queue<std::string> Fucker_Queue, std::queue<std::string>& EventQueue) {
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
        Draw_Fucker(window, Fucker_Name);
        window.display();
        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::KeyPressed: {

                    if (event.key.code == sf::Keyboard::Y) {
                        //FIXME
                    }

                    if (event.key.code == sf::Keyboard::N) {
                        //FIXME
                    }
                }

                case sf::Event::Closed:
                    EventQueue.push("30");
                    window.close();
                    break;
            }
        }
    }
}

void Start_Game(sf::RenderWindow& window, std::queue<std::string>& EventQueue)
//This function asks main who is the first fucker and tell audio thread to start
{
    while (window.isOpen())
    {
        std::string First_Fucker_Name = "Bek.jpeg";
        EventQueue.push("20");
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
