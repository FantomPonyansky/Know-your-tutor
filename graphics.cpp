#include <SFML/Graphics.hpp>

void Draw_Fucker(sf::RenderWindow& window, std::string Fucker_Name)
//This function gets window and draw in it picture of fucker, whose name is also given
{
    sf::Image FuckerImage;
    FuckerImage.loadFromFile(Fucker_Name);
    sf::Texture FuckerTexture;
    FuckerTexture.loadFromImage(FuckerImage);
    sf::Sprite FuckerSprite;
    FuckerSprite.setTexture(FuckerTexture);
    FuckerSprite.setPosition(200, 100);
    window.draw(FuckerSprite);
}

void Game(sf::RenderWindow& window)
//This is the main part of the game
{
    //FIXME
}

void Create_Window()
//This function only display rules and call game-function when start-key pressed and close if close-key pressed
{
    unsigned int screen_width = 600;       //FIXME
    unsigned int screen_height = 600;      //FIXME
    sf::RenderWindow MainWindow(sf::VideoMode(screen_width, screen_height), "My window", sf::Style::Close);
    while (MainWindow.isOpen())
    {
        MainWindow.clear(sf::Color(0, 0, 0, 255));
        Draw_Fucker(MainWindow, "Bek.jpg");
        MainWindow.display();
    }
}
