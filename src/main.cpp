#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "../include/data.h"

#define BIGGPULL 84

unsigned int microseconds;

void gen(blackh_one* result);
sf::CircleShape intHole(blackh_one * result, sf::CircleShape *bho);
sf::CircleShape intThree(sf::CircleShape *bh3, sf::CircleShape *bht, sf::CircleShape *bho);
sf::CircleShape intWaves(sf::CircleShape *waves, sf::CircleShape *bh3);
sf::CircleShape growWaves(sf::CircleShape *waves, sf::CircleShape *bh3);

//-----------------------------------------------------------------------------------
int main(){
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    window.clear();                                                 // Clear the window
//-----------------------------------------------------------------------------------
    blackh_one one = {0, 0, 0};					    // Initialize one struct
    gen(&one); 						    // Populate 1 struct
    sf::CircleShape *bho = new sf::CircleShape(one.size);
    intHole(&one, bho);						    // Populate bho pointer o
    gen(&one);							    // Populate 2 struct
    sf::CircleShape *bht = new sf::CircleShape(one.size);  	    // Define bho pointer object
    intHole(&one, bht);						    // Populate bht pointer object
    int sx = bho->getRadius() + bht->getRadius();		    // Define sx variable
    sf::CircleShape *bh3 = new sf::CircleShape(sx);		    // Define black hole 3 object
    bh3->setPosition(7000, 0);					    // Set position of black hole 3 object off screen
    sf::CircleShape *waves = new sf::CircleShape(sx);
    window.draw(*bho);					            // Draw black hole one
    window.draw(*bht);						    // Draw black hole two
    window.display();
//------------------------------------------------------------------------------------
    int spd = 85;  						   // Define speed variable
    while (window.isOpen()){	    				   // Window event
		window.clear();					   // Clear the screen
		window.draw(*bh3);				   // Draw black hole 3
		window.display();				   // Display shapes on screen
//------------------------------------------------------------------------------------
		if (bho->getRadius() > bht->getRadius()){
			spd -= 2;				   // Decrement speed vaiable
			bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / BIGGPULL ,-1 * (bho->getPosition().y - bht->getPosition().y) / BIGGPULL );	// Move the larger black hole towards the smaller black hole
			bht->move((bho->getPosition().x - bht->getPosition().x) / spd,(bho->getPosition().y - bht->getPosition().y) / spd );				// Move the smaller black hole towards the larger black hole 
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
			intWaves(waves, bh3);
			
			for(int i = 0; i < 100; i++){
				growWaves(waves, bh3);
				window.clear();
				window.draw(*waves);
				window.draw(*bh3);
				window.display();
				usleep(10000);
			}
		}
//-------------------------------------------------------------------------------------
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				delete bho, bht, bh3, waves;
				window.close();
			}else if (event.mouseButton.button == sf::Mouse::Left){
				window.close();
				delete bho, bht, bh3, waves;
				main();
			}
		}
    }
//------------------------------------------------------------------------------------
    return 0;
}
