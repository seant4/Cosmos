#include <SFML/Graphics.hpp>

#include "../include/data.h"

void gen(blackh* result){                                     //Generate Hole One
    result -> x = 1 + rand() %((340 + 1) - 1);                     // Generates X position
    result -> y = 1 + rand() %((481 + 1) - 1);                     // Generates Y position
    result -> size = 10 + rand() % ((35 + 1) - 10);                // Generate Size
}

sf::CircleShape intHole(blackh * result, sf::CircleShape *bho){                                 
    bho->setFillColor(sf::Color::White);
    bho->setPosition(result->x, result->y);
    bho->setOrigin(bho->getRadius(), bho->getRadius());             // Draw object
    return *bho;
}

sf::CircleShape intThree(sf::CircleShape *bh3, sf::CircleShape *bht, sf::CircleShape *bho){
    bh3->setFillColor(sf::Color::White);
	bht->setFillColor(sf::Color::White);
	bho->setFillColor(sf::Color::White);
	bh3->setPosition(bho->getPosition().x, bho->getPosition().y);
	bh3->setOrigin(bh3->getRadius(), bh3->getRadius());
    return *bh3;
}

sf::CircleShape intWaves(sf::CircleShape *waves, sf::CircleShape *bh3){
    waves->setFillColor(sf::Color::Black);
    waves->setOutlineColor(sf::Color::Blue);
    waves->setOutlineThickness(10);
    waves->setOrigin(waves->getRadius(), waves->getRadius());
    waves->setPosition(bh3->getPosition().x, bh3->getPosition().y);
    return *waves;
}

sf::CircleShape growWaves(sf::CircleShape *waves, sf::CircleShape *bh3){
    waves->setRadius(waves->getRadius() + 5);
	waves->setOrigin(waves->getRadius(), waves->getRadius());
	waves->setPosition(bh3->getPosition());
    return *waves;
}
