#pragma once
#include "Sniper.hpp"

class SniperCommander : public Sniper
{

public:
    SniperCommander(int g) : Soldier(g, 120, 100) {}
    void act(vector<vector<Soldier *>> &board, pair<int, int> location); //attack by himself first
    void act_as_commander(vector<vector<Soldier *>> &board, pair<int, int> location);                                             //send all his soldiers to attack
};