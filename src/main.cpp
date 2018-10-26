#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "../include/data.h"

unsigned int microseconds;

//-----------------------------------------------------------------------------------
int main(){
    srand(time(NULL));                                              // Generate random seed based on time of day
    sf::RenderWindow window(sf::VideoMode(680, 480), "Simulation"); // Define window
    window.clear();                                                 // Clear the window
//-----------------------------------------------------------------------------------
    blackh data = {0, 0, 0};					    // Initialize one struct
    gen(&data); 						    // Populate 1 struct
    sf::CircleShape *bho = new sf::CircleShape(data.size);
    intHole(&data, bho);						    // Populate bho pointer o
    gen(&data);							    // Populate 2 struct
    sf::CircleShape *bht = new sf::CircleShape(data.size);  	    // Define bho pointer object
    intHole(&data, bht);						    // Populate bht pointer object
    int sx = bho->getRadius() + bht->getRadius();		    // Define sx variable
    sf::CircleShape *bh3 = new sf::CircleShape(sx);		    // Define black hole 3 object
    bh3->setPosition(7000, 0);					    // Set position of black hole 3 object off screen
    sf::CircleShape *waves = new sf::CircleShape(sx);
    window.draw(*bho);					            // Draw black hole one
    window.draw(*bht);						    // Draw black hole two
    window.display();
//------------------------------------------------------------------------------------
    int gpull = 85;  						   // Define speed variable
    while (window.isOpen()){	    				   // Window event
		window.clear();					   // Clear the screen
		window.draw(*bh3);				   // Draw black hole 3
		window.display();				   // Display shapes on screen
//------------------------------------------------------------------------------------
		if (bho->getRadius() > bht->getRadius()){
			gpull -= 4;				   // Decrement speed vaiable
			bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / gpull,-1 * (bho->getPosition().y - bht->getPosition().y) / gpull );	// Move the larger black hole towards the smaller black hole
			bht->move((bho->getPosition().x - bht->getPosition().x) / gpull,(bho->getPosition().y - bht->getPosition().y) / gpull );				// Move the smaller black hole towards the larger black hole 
			window.draw(*bho);
			window.draw(*bht);
			window.display();
			usleep(100000);
//--------------------------------------------------------------------------------------
		}else{
			gpull -= 4;
    		    	bht->move((bho->getPosition().x - bht->getPosition().x) / gpull ,(bho->getPosition().y - bht->getPosition().y) / gpull );
    		    	bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / gpull,-1 * (bho->getPosition().y - bht->getPosition().y) / gpull );
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
