#pragma once
#include "Soldier.hpp"

class Sniper : public virtual Soldier {
    
public:
    Sniper(int g): Soldier(g,100,50) {}
    Sniper() : Soldier(0,0,0) {}
    void act(vector<vector<Soldier *>> &board, pair<int, int> location);
}; 