# Cosmos
### Cosmos is a simulation of black holes colliding in space
## What happens when black holes collide?
>### When two black are in space and are within each others gravitational pull, they will move twards eachother, and when they collide, they combine to form a larger black hole. But when this happpens, tons of energy is released from the black hole, these ripples are called [gravitational waves](http://hubblesite.org/explore_astronomy/black_holes/encyc_mod3_q6.html)

## How will this be achieved?
### This program will do a number of things, here are the steps
>1) Randomly generate two black holes position and size
>1) The program will determine they're distance from eachother, and decide with is larger
>1) The smaller black hole moves twards the larger one, and when they collide
>1) The larger black hole absorbs the smaller black hole, and grows in size relative to the smaller hole it absorbed
>1) Finally, it will release gravitational waves throghout

## The code
### This is a C/C++ program using the [SFML](https://www.sfml-dev.org/) graphics library
### Heres an example ---
```cpp
        bh3.setFillColor(sf::Color::White);
		bht->setFillColor(sf::Color::White);
		bho->setFillColor(sf::Color::White);
		bh3.setPosition(bho->getPosition().x, bho->getPosition().y);
		bh3.setOrigin(bh3.getRadius(), bh3.getRadius());
		window.clear();
		window.draw(bh3);
		window.display();
```
### This code creates an circle object, draws and displays it.

## The logic
```cpp
    bht->move((bho->getPosition().x - bht->getPosition().x) / BIGGPULL ,(bho->getPosition().y - bht->getPosition().y) / BIGGPULL );
    bho->move(-1 * (bho->getPosition().x - bht->getPosition().x) / spd,-1 * (bho->getPosition().y - bht->getPosition().y) / spd );
    window.draw(*bho);
    window.draw(*bht);
    window.display();

```
### This code is an a while loop, and moves the black holes based on gravitational pull

## Todo
>1) ~~Move Towards eachother~~
>1) ~~Collision event~~
>1) ~~Combination event~~
>1) Ripple effect
>1) ~~Growth effect~~
