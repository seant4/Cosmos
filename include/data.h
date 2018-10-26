struct blackh{
    int x = 0;
    int y = 0;
    int size = 0;
};

void gen(blackh* result);
sf::CircleShape intHole(blackh * result, sf::CircleShape *bho);
sf::CircleShape intThree(sf::CircleShape *bh3, sf::CircleShape *bht, sf::CircleShape *bho);
sf::CircleShape intWaves(sf::CircleShape *waves, sf::CircleShape *bh3);
sf::CircleShape growWaves(sf::CircleShape *waves, sf::CircleShape *bh3);
