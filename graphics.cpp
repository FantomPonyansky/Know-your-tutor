#include <SFML/Graphics.hpp>

void Draw_Fucker(sf::RenderWindow window, std::string Fucker_Name)
{
    sf::Image FuckerImage;
    FuckerImage.loadFromFile(Fucker_Name);
    sf::Texture FuckerTexture;
    FuckerTexture.loadFromImage(FuckerImage);
    sf::Sprite FuckerSprite;
    FuckerSprite.setTexture(FuckerTexture);
    FuckerSprite.setPosition(0, 0);
    window.draw(FuckerSprite);
}

void Create_Window()
{
    unsigned int screen_width = 600;       //FIXME
    unsigned int screen_height = 600;      //FIXME
    sf::RenderWindow MainWindow(sf::VideoMode(screen_width, screen_height), "My window", sf::Style::Close);
    while (MainWindow.isOpen())
    {
        //Here must be a lot of drawing different fuckers and some events
        MainWindow.clear();
        Draw_Fucker(MainWindow, "Bek.jpg");
        MainWindow.display();
    }
}
