#include<iostream>

class Pod {
private:
    float x;
    float y;
    float dir;
    float health;
    float vx;
    float vy;

public:
    Pod(){}

    float getX() {
        return this->x;
    }
    void setX(int x) {
        this->x = x;
    }
    float getY() {
        return this->y;
    }
    void setY(int y) {
        this->y = y;
    }
    float getDir() {
        return this->dir;
    }
    void setDir(int dir) {
        this->dir = dir;
    }
    float getHealth() {
        return this->health;
    }
    void setHealth(int health) {
        this->health = health;
    }
    float getVX() {
        return this->vx;
    }
    void setVX(float vx) {
        this->vx = vx;
    }
    float getVY() {
        return this->vy;
    }
    void setVY(float vy) {
        this->vy = vy;
    }

};