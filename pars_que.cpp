//
// Created by ruby on 27.02.18.
//

#include <iostream>
#include <queue>
#include <SFML/Audio.hpp>


void audio_play(std::string val){

    std::string facker_ID = "Heavy_domination08_ru.wav";
    int facker_counter = 0;
    std::string norm_prep_ID = "skip.wav";
    std::string end_ID = "112.wav";
    std::string start_ID = "start.wav";
    std::string win_ID = "win.wav";
    sf::SoundBuffer buffer_e;
    buffer_e.loadFromFile(end_ID);
    sf::SoundBuffer buffer_w;
    buffer_w.loadFromFile(win_ID);



    sf::SoundBuffer buffer_s;
    buffer_s.loadFromFile(start_ID);

    sf::SoundBuffer buffer_g;
    sf::SoundBuffer buffer_b;
    buffer_g.loadFromFile(norm_prep_ID);
    buffer_b.loadFromFile(facker_ID);



    if(val[0] == '1' and val[1] == '1'){



        sf::Sound sound;
        sound.setBuffer(buffer_g);
        sound.play();

		while(sound.getStatus() == sf::Sound::Playing)
        {
            sf::sleep(sf::seconds(1.f));
        }


        facker_counter++;
        norm_prep_ID[0] = facker_counter;


    }else if(val[0] == '0' and val[1] == '0'){



        sf::Sound sound;
        sound.setBuffer(buffer_g);
        sound.play();

        while(sound.getStatus() == sf::Sound::Playing)
        {
            sf::sleep(sf::seconds(1.f));
        }


    }else if(val[0] == '0' and val[1] == '1'){



        sf::Sound sound;
        sound.setBuffer(buffer_w);
        sound.play();

	    while(sound.getStatus() == sf::Sound::Playing)
        {
            sf::sleep(sf::seconds(1.f));
        }


    }else if (val[0] == '1' and val[1] == '0')
    {



        sf::Sound sound;
        sound.setBuffer(buffer_b);
        sound.play();




		    while(sound.getStatus() == sf::Sound::Playing)
        {
            sf::sleep(sf::seconds(1.f));
        }

    }else if(val[0] == '2'){



        sf::Sound sound;
        sound.setBuffer(buffer_s);
        sound.play();

        while(sound.getStatus() == sf::Sound::Playing)
        {
            sf::sleep(sf::seconds(1.f));
        }


    }



    if (val[0] == '3') {


        buffer_e.loadFromFile(end_ID);

        sf::Sound sound;
        sound.setBuffer(buffer_e);
        sound.play();

        while(sound.getStatus() == sf::Sound::Playing)
        {
            sf::sleep(sf::seconds(1.f));
        }

    }



}

void get_val_from_que(std::queue<std::string>& main_que){

    while (true)
    {

        if (not main_que.empty()) {
            std::string val = main_que.front();
            main_que.pop();

            audio_play(val);
            if (val[0] == '3') break;
        }
    }

}
