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
    float getVx() {
        return this->vx;
    }
    void setVx(float vx) {
        this->vx = vx;
    }
    float getVy() {
        return this->vy;
    }
    void setVy(float vy) {
        this->vy = vy;
    }

};