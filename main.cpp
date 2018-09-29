#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <map>

#include "star.h"
//run g++ -c main.cpp
//after first compile, run g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

void gen(Star* result){                                             //Generate Galaxy
    result -> x = rand() % 681;                                     // Generates X position
    result -> y = rand() % 481;                                     // Generates Y position
}

int main(){
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    sf::CircleShape shape(1);                                       // Create circle shape
    shape.setFillColor(sf::Color::White);                           // Make it white
    window.clear();                                                 // Clear the window
    Star star = {1, 1};                                             // Define struct
    int i = 0;                                                      // Define i
    while (window.isOpen()){                                        // Window event
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    gen(&star);                                                     // Generate galaxy
    shape.setPosition(star.x, star.y);                              // Set shape
    std::map<int, int> points;
    points[star.x]=star.y;                                          //Add to map
    std::cout << star.x, " ", star.y;
    std::cout << "\n";
    window.draw(shape);                                             // Draw shapes
    i++;        
    if (i > 1000){                                                  // When there are 1000 galaxies display
        window.display();
        break;
    }
    }
    while (window.isOpen()){                                        // Window event
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    }
    return 0;
}
