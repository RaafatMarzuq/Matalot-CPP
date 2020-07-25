#pragma once
#include "FootSoldier.hpp"


class FootCommander : public FootSoldier
{

public:
    FootCommander(int g) : Soldier(g, 150, 20) {}
    void act(vector<vector<Soldier *>> &board, pair<int, int> location);              //attack by himself first
    void act_as_commander(vector<vector<Soldier *>> &board, pair<int, int> location); //send all his soldiers to attack
};