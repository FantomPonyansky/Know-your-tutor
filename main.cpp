#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics.h"
#include <thread>
#include "pars_que.h"

int main() {
    std::queue<std::string> EventQueue;
    std::thread graphics (Create_Window, std::ref(EventQueue));
    std::thread audio (get_val_from_que, std::ref(EventQueue));

    graphics.join();
    audio.join();

/*    while (not EventQueue.empty())
    {
        std::cout << EventQueue.front() << "\n";
        EventQueue.pop();
    }
    return 0;*/
}
