#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "../include/data.h"

#define BIGGPULL 84

unsigned int microseconds;

void gen1(blackh_one* result);
void gen2(blackh_two* result);
sf::CircleShape intOne(blackh_one * result, sf::CircleShape *bho);
sf::CircleShape intTwo(blackh_two * result, sf::CircleShape *bht);
sf::CircleShape intThree(sf::CircleShape *bh3, sf::CircleShape *bht, sf::CircleShape *bho);
//-----------------------------------------------------------------------------------


int main(){
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    window.clear();                                                 // Clear the window
//-----------------------------------------------------------------------------------
	blackh_one one = {1, 1, 5};					    									// Initialize one struct
	blackh_two two = {1, 1, 5};					    									// Initialize two struct
    gen1(&one); 						    													 // Populate 1 struct
    gen2(&two);							                                                        // Populate 2 struct
    sf::CircleShape *bht = new sf::CircleShape(two.size);	 // Define bht pointer object
    sf::CircleShape *bho = new sf::CircleShape(one.size);  // Define bho pointer object
    intOne(&one, bho);						                                            // Populate bho pointer object
    intTwo(&two, bht);						                                            // Populate bht pointer object
    window.draw(*bho);						    									// Draw black hole one
    window.draw(*bht);						    									// Draw black hole two
    int sx = bho->getRadius() + bht->getRadius();		    // Define sx variable
    sf::CircleShape *bh3 = new sf::CircleShape(sx);					    // Define black hole 3 object
    bh3->setPosition(7000, 0);					    // Set position of black hole 3 object off screen
//------------------------------------------------------------------------------------
    int spd = 85;  						    // Define speed variable
    while (window.isOpen()){	    				    // Window event
		window.clear();						    // Clear the screen
		window.draw(*bh3);					    // Draw black hole 3
		window.display();					    // Display shapes on screen
//------------------------------------------------------------------------------------
		if (bho->getRadius() > bht->getRadius()){
			spd -= 2;					    // Decrement speed vaiable
			bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / BIGGPULL ,-1 * (bho->getPosition().y - bht->getPosition().y) / BIGGPULL );				    // Move the larger black hole towards the smaller black hole
			bht->move((bho->getPosition().x - bht->getPosition().x) / spd,(bho->getPosition().y - bht->getPosition().y) / spd );							    // Move the smaller black hole towards the larger black hole 
			window.draw(*bho);
			window.draw(*bht);
			window.display();
			usleep(100000);
//--------------------------------------------------------------------------------------
		}else{
			spd -= 2;
    	    bht->move((bho->getPosition().x - bht->getPosition().x) / BIGGPULL ,(bho->getPosition().y - bht->getPosition().y) / BIGGPULL );
    	    bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / spd,-1 * (bho->getPosition().y - bht->getPosition().y) / spd );
    	    window.draw(*bho);
    	    window.draw(*bht);
    	    window.display();
			usleep(100000);
		}
//-------------------------------------------------------------------------------------
		if (bho->getPosition() == bht->getPosition()){
			intThree(bh3, bht, bho);
			window.clear();
			window.draw(*bh3);
			window.display();
		}
//-------------------------------------------------------------------------------------
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				delete bho, bht, bh3;
				window.close();
			}
		}
    }
//------------------------------------------------------------------------------------
    return 0;
}
