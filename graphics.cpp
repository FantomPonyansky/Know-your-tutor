#include <SFML/Graphics.hpp>

sf::Sprite Create_Fucker_sprite(std::string Fucker_Name)
{
    sf::Image FuckerImage;
    FuckerImage.loadFromFile(Fucker_Name);
    sf::Texture FuckerTexture;
    FuckerTexture.loadFromImage(FuckerImage);
    sf::Sprite FuckerSprite;
    FuckerSprite.setTexture(FuckerTexture);
    FuckerSprite.setPosition(10, 10);
    return FuckerSprite;
}

void Create_Window()
{
    unsigned int screen_width = 600;       //FIXME
    unsigned int screen_height = 600;      //FIXME
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "My window", sf::Style::Close);
    while (window.isOpen())
    {
        //Here must be a lot of drawing different fuckers and some events
        window.clear();
        sf::Sprite sprite = Create_Fucker_sprite("Bek.jpg");
        window.draw(sprite);
        window.display();
    }
}
