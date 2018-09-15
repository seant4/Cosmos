#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <thread>

#include "star.h"
//run g++ -c main.cpp
//after first compile, run g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
//test
int main(){
    Star star;
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation");
    sf::CircleShape shape(3);
    shape.setFillColor(sf::Color::White);
    window.clear();
    int i = 0;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    window.draw(shape);
    star.x = rand() % 681;
    star.y = rand() % 481;
    shape.setPosition(star.x, star.y);
    i++;
    window.display();
    if (i > 1000){
        break;
    }
    }
    for (int i; i < 100; i++){
        shape.setPosition(star.x, i);
        sleep(2000);
    }
    std::cin.ignore();
    return 0;
}
