#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <string>

int NB_PODS = 3;
int POD_RADIUS = 10;
int FRICTION = 0.005;
int WIDTH = 800;
int HEIGHT = 800;
int TIME = 1;
int MAX_TRUST = 100;
int MAX_TURN = 15;

void next_input_must_be(string value) {
    string val;
    std::cin >> val;
    if (val.compare(value)) {
        std::cout << "expected input was " << value << "instead of " << val <<std::endl;
        exit(0);
    }
}
    


def sub(a,b):
    return [x-y for x,y in zip(a,b)]

def prod(a,b):
    return [x*y for x,y in zip(a,b)]


def dot(a,b):
    return sum(x*y for x,y in zip(a,b))

