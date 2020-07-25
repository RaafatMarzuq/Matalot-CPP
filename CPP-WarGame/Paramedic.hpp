#pragma once
#include "Soldier.hpp"

class Paramedic : public virtual Soldier
{
public:
    Paramedic(int g) : Soldier(g, 100, 0) {}
    Paramedic() : Soldier(0, 0, 0) {}
    void act(vector<vector<Soldier *>> &board, pair<int, int> location);
};