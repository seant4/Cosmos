#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <thread>

#include "star.h"
//run g++ -c main.cpp
//after first compile, run g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

void gen(Star* result){
    result -> x = rand() % 681;
    result -> y = rand() % 481; 
}

int main(){
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation");
    sf::CircleShape shape(3);
    shape.setFillColor(sf::Color::White);
    window.clear();
    Star star = {1, 1};
    int i = 0;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    gen(&star);
    shape.setPosition(star.x, star.y);
    window.draw(shape);
    i++;
    if (i > 1000){
        window.display();
        break;
    }
    }
    std::cin.ignore();
    return 0;
}
