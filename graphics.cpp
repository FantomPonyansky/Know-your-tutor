#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

sf::Event event;

void Send_Event_To_Queue()
//This function creates event ID and sends it to queue. I still haven't decide what I shall give it.
{
    //FIXME
}

unsigned int Get_Screen_Width()
{
    //FIXME
}

unsigned int Get_Screen_Height()
{
    //FIXME
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

void Battle(sf::RenderWindow& window, std::string Fucker_Name) {
    while (window.isOpen()) {
        window.clear();
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
                    //FIXME here must be sending event "Close" to main queue
                    window.close();
                    break;
            }
        }
    }
}

void Start_Game(sf::RenderWindow& window)
//This function asks main who is the first fucker and tell audio thread to start
{
    while (window.isOpen())
    {
        std::string First_Fucker_Name = "Bek.jpeg";
        Send_Event_To_Queue();
        //First_Fucker_Name = Who_is_Now();             //FIXME this function must give back first fuckers name
        Battle(window, First_Fucker_Name);
    }
}

void Create_Window()
//This function only display rules and call game-function when start-key pressed and close if close-key pressed
{
    unsigned int screen_width = 400;
    unsigned int screen_height = 700;
    sf::RenderWindow MainWindow(sf::VideoMode(screen_width, screen_height), "My window", sf::Style::Close);
    sf::Text rules;
    sf::Font font;
    font.loadFromFile("Admiration Pains.ttf");
    rules.setFont(font);
    rules.setColor(sf::Color::Magenta);
    rules.setCharacterSize(18);
    rules.setPosition(5, 5);
    std::string RulesInString = "Here must be rules"; //FIXME here must be reading rules from file
    rules.setString(RulesInString);
    while (MainWindow.isOpen()) {

        MainWindow.clear(sf::Color(0, 0, 0, 255));
        MainWindow.draw(rules);
        MainWindow.display();

        while (MainWindow.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::KeyPressed: {

                    if (event.key.code == sf::Keyboard::Escape) {
                        //FIXME here must be sending event "Close" to main queue
                        MainWindow.close();
                    }

                    if (event.key.code == sf::Keyboard::S) {
                        Start_Game(MainWindow);
                    }
                }

                case sf::Event::Closed:
                    //FIXME here must be sending event "Close" to main queue
                    MainWindow.close();
                    break;

            }
        }
    }
}
