#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "star.h"

#define BIGGPULL 84

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

sf::CircleShape intOne(blackh_one * result, sf::CircleShape *bho){                                 
    bho->setFillColor(sf::Color::White);
    bho->setPosition(result->x, result->y);
    bho->setOrigin(bho->getRadius(), bho->getRadius());                                             //Draw object
    return *bho;
}

sf::CircleShape intTwo(blackh_two * result, sf::CircleShape *bht){
    bht->setFillColor(sf::Color::Blue);
    bht->setOrigin(bht->getRadius(), bht->getRadius());
    bht->setPosition(result->x, result->y);
    return *bht;
}

int main(){
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    window.clear();                                                 // Clear the window
    //-----------------------------------------------------------------------------------
    blackh_one one = {1, 1, 5};
    blackh_two two = {1, 1, 5};
    gen1(&one); 
    gen2(&two);
    sf::CircleShape *bht = new sf::CircleShape(two.size);
    sf::CircleShape *bho = new sf::CircleShape(one.size);
    intOne(&one, bho);
    intTwo(&two, bht);
    window.draw(*bho);
    window.draw(*bht);
    window.display(); 
    int sx = bho->getRadius() + bht->getRadius(); 
    sf::CircleShape bh3(sx);
    bh3.setPosition(7000, 0);
    //------------------------------------------------------------------------------------
    int spd = 85;  
    while (window.isOpen()){	    // Window event
	window.clear();
	window.draw(bh3);
	window.display();
	if (bho->getRadius() > bht->getRadius()){
		spd -= 2;
		bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / BIGGPULL ,-1 * (bho->getPosition().y - bht->getPosition().y) / BIGGPULL );
		bht->move((bho->getPosition().x - bht->getPosition().x) / spd,(bho->getPosition().y - bht->getPosition().y) / spd );
		window.draw(*bho);
		window.draw(*bht);
		window.display();
		usleep(100000);
	}else{
		spd -= 2;
        	bht->move((bho->getPosition().x - bht->getPosition().x) / BIGGPULL ,(bho->getPosition().y - bht->getPosition().y) / BIGGPULL );
                bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / spd,-1 * (bho->getPosition().y - bht->getPosition().y) / spd );
                window.draw(*bho);
                window.draw(*bht);
                window.display();
		usleep(100000);
	}
	if (bho->getPosition() == bht->getPosition()){
		bh3.setFillColor(sf::Color::White);
		bh3.setPosition(bho->getPosition().x, bho->getPosition().y);
		bh3.setOrigin(bh3.getRadius(), bh3.getRadius());
		window.clear();
		window.draw(bh3);
		window.display();
	}
	sf::Event event;
	while (window.pollEvent(event)){
		window.clear();
		window.draw(bh3);
		window.display();
		if (event.type == sf::Event::Closed){
			std::cout << "Seeya!";
			delete bho, bht;
			window.close();
		}
	}
    }
    return 0;
}
