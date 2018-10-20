#include <SFML/Graphics.hpp>

#include "star.h"

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
    bho->setOrigin(bho->getRadius(), bho->getRadius());             // Draw object
    return *bho;
}
sf::CircleShape intTwo(blackh_two * result, sf::CircleShape *bht){
    bht->setFillColor(sf::Color::Blue);
    bht->setOrigin(bht->getRadius(), bht->getRadius());
    bht->setPosition(result->x, result->y);
    return *bht;
}
