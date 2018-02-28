//
// Created by ruby on 27.02.18.
//

#include <iostream>
#include <queue>
#include <SFML/Audio.hpp>

void audio_play(std::string val){

    std::string facker_ID = "0facker.wav";
    int facker_counter = 0;
    std::string norm_prep_ID = "norm_prep.wav";

    if(val[0] == 1 & val[1] == 1){
        sf::SoundBuffer buffer;
        buffer.loadFromFile(norm_prep_ID);

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();

		while(sound.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::seconds(1.f));
    }

        facker_counter++;
        norm_prep_ID[0] = facker_counter;


    }else if(val[0] == 0 & val[1] == 0){
        sf::SoundBuffer buffer;
        buffer.loadFromFile(norm_prep_ID);

        sf::Sound sound;
        sound.setBuffer(buffer);
	while(sound.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::seconds(1.f));
    }
        sound.play();
    }else if(val[0] == 0 & val[1] == 1){
        sf::SoundBuffer buffer;
        buffer.loadFromFile(facker_ID);

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();

	while(sound.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::seconds(1.f));
    }

    }else{
        sf::SoundBuffer buffer;
        buffer.loadFromFile(facker_ID);

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();
		while(sound.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::seconds(1.f));
    }
    }


}

void get_val_from_que(std::queue<std::string> &main_que){

    std::string val = main_que.front();
	main_que.pop;

    audio_play(val);


}


