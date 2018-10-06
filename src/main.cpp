#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <map>

#include "star.h"
//run g++ -c main.cpp
//after first compile, run g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

void gen1(blackh_one* result){                                      //Generate Hole One
    result -> x = rand() % 681;                                     // Generates X position
    result -> y = rand() % 481;                                     // Generates Y position
    result -> size = rand() % 25;                                   // Generate Size
    std::cout << "This is a test";
}

void gen2(blackh_two* result){
    result -> x = rand() % 681;
    result -> y = rand() % 481;
    result -> size = rand() % 25;
}

int main(){
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    sf::CircleShape bho(5);                                         // Create circle shape
    bho.setFillColor(sf::Color::White);                             // Make it white
    sf::CircleShape bht(4);
    bht.setFillColor(sf::Color::White);
    window.clear();                                                 // Clear the window
    blackh_one one = {1, 1, 5};                                     // Define struct
    blackh_two two = {1, 1, 5};
    gen1(&one);                                                      // One black hole 
    bho.setPosition(one.x, one.y);                                   // Set shape
    std::map<int, int> bh1;
    bh1[one.x]=one.y;                                                //Add to map
    std::cout << one.x, " ", one.y;
    std::cout << "\n";
    window.draw(bho);                                                // Draw shapes
    gen2(&two);
    bht.setPosition(two.x, two.y);
    std::map<int, int> bh2;
    bh2[two.x]=two.y;
    window.draw(bht);
    window.display();
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
