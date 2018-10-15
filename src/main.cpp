#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <map>

#include "star.h"
//run g++ -c main.cpp
//after first compile, run g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#define L 36
#define S 84

unsigned int microseconds;

void gen1(blackh_one* result){                                     //Generate Hole One
    result -> x = 1 + rand() %((340 + 1) - 1);                     // Generates X position
    result -> y = 1 + rand() %((481 + 1) - 1);                     // Generates Y position
    result -> size = 10 + rand() % ((35 + 1) - 10);                // Generate Size
}

void gen2(blackh_two* result){
    result -> x = 340 + rand() %((681 + 1) - 340);
    result -> y = 1 + rand() %((481 + 1) - 1);
    result -> size = 10 + rand() % ((35 + 1) - 10);
}

int main(){
    int bx = 0;
    int by = 0;
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    window.clear();                                                 // Clear the window
    //-----------------------------------------------------------------------------------
    blackh_one one = {1, 1, 5};                                     // Define struct
    blackh_two two = {1, 1, 5};
    gen1(&one);                                                      // One black hole
    sf::CircleShape bho(one.size); 
    bho.setPosition(one.x, one.y);                                   // Set shape
    bho.setFillColor(sf::Color::White);
    std::cout << one.x, " ", one.y;
    std::cout << "\n";
    window.draw(bho);                                                // Draw shapes
    gen2(&two);
    sf::CircleShape bht(two.size);
    bht.setFillColor(sf::Color::Blue);
    bht.setPosition(two.x, two.y);
    bho.setOrigin(bho.getRadius(), bho.getRadius());
    bht.setOrigin(bht.getRadius(), bht.getRadius());
    window.draw(bht);
    window.display();                         
    //------------------------------------------------------------------------------------
    while (window.isOpen()){	    // Window event
	window.clear();
	if (bho.getRadius() > bht.getRadius()){
		bho.move(-1 * (one.x - two.x) / S ,-1 * (one.y - two.y) / S );
		bht.move((one.x - two.x) / L,(one.y - two.y) / L );
		window.draw(bho);
		window.draw(bht);
		window.display();
		usleep(100000);
	}else{
        	bht.move((one.x - two.x) / S ,(one.y - two.y) / S );
                bho.move(-1 * (one.x - two.x) / L,-1 * (one.y - two.y) / L );
                window.draw(bho);
                window.draw(bht);
                window.display();
		usleep(100000);
	}
	if (bho.getRadius() + bht.getRadius() < bho.getPosition().x - bht.getPosition().x && bho.getPosition().y - bht.getPosition().y){
	//	window.close();
	}

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    }
    return 0;
}
