# Cosmos
### Cosmos is a simulation of black holes colliding in space
test
## What happens when black holes collide?
>### When two black are in space and are within each others gravitational pull, they will move twards eachother, and when they collide, they combine to form a larger black hole. But when this happpens, tons of energy is released from the black hole, these ripples are called [gravitional waves](http://hubblesite.org/explore_astronomy/black_holes/encyc_mod3_q6.html)

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
void gen1(blackh_one* result){                                      //Generate Hole One
    result -> x = rand() % 681;                                     // Generates X position
    result -> y = rand() % 481;                                     // Generates Y position
    result -> size = rand() % 25;                                   // Generate Size
}

void gen2(blackh_two* result){
    result -> x = rand() % 681;
    result -> y = rand() % 481;
    result -> size = rand() % 25;
}
```
### These randomly generate the position and size of each black hole

```cpp
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
```
### And here they are drawn and displayed

## This is a work in progress, 
### Todo
>1) ~~Move Towards eachother~~
>1) ~~Collision event~~
>1) ~~Combination event~~
>1) Ripple effect
>1) ~~Growth effect~~
