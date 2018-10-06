#include <stdio.h>
#include <stdlib.h>

struct blackh_one{
    int x = 0;
    int y = 0;
    int size = 0;
};
struct blackh_two{
    int x = 0;
    int y = 0;
    int size = 0;
};

void gen1(blackh_one* result){                                      //Generate Hole One
    result -> x = rand() % 681;                                     // Generates X position
    result -> y = rand() % 481;                                     // Generates Y position
    result -> size = rand() % 25;                                   // Generate Size
    std::cout << "This is a test";
}

void gen2(blackh_two* result){
    result -> x = rand() % 681;
    result -> y = rand() % 481;
    result -> size = rand() % 25;
}
