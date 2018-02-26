#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

sf::Event event;

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

void Game_Graphics(sf::RenderWindow& window)
//This is the main part of the game drawer. This function catches events, draw fuckers and so on.
{
    while (window.isOpen())
    {
        window.clear();
        Draw_Fucker(window, "Bek.jpeg"); //FIXME this function must start first battle
        window.display();
        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    //FIXME here must be sending event "Close" to main queue
                    window.close();
                    break;

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Y) {
                        //FIXME here must be code, explaining what to do if user says "YES"
                    }

                    if (event.key.code == sf::Keyboard::N){
                        //FIXME here must be code, explaining what to do if user says "NO"
                    }
            }
        }
    }
    //FIXME Where is all events and all stuff?
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
                        //FIXME here must be sending event "Start" to main queue
                        Game_Graphics(MainWindow);
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

void Send_Event_To_Queue()
{
    //FIXME
}