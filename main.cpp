#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics.h"
#include <thread>
#include "pars_que.h"

int main() {
    std::queue<std::string> EventQueue;
    std::thread graphics (Create_Window, EventQueue);
    std::thread audio (get_val_from_que, EventQueue);

    graphics.join();
    audio.join();

    return 0;
}
