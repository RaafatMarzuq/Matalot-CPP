#pragma once

#include <stdexcept>
#include <vector>
using namespace std;
class Soldier
{
private:
    int max_hp; //max amount of hp.
    int player; //player number.
    int hp;     // health points.
    int power;  //amount of power of his act; heal or damage.

public:
    virtual void act(vector<vector<Soldier *>> &board, pair<int, int> location){};

    //          full constructor
    Soldier(int p, int h, int pow)
        : player(p), hp(h), max_hp(h), power(pow) {}

   virtual ~Soldier(){
    
    }

    //          Get&Set
    virtual int _hp()
    {
        return hp;
    }
    virtual void set_hp(int new_hp)
    {
        hp = new_hp;
    }

    virtual int _player()
    {
        return player;
    }
    virtual void set_player(int new_player)
    {
        player = new_player;
    }

    virtual int _power()
    {
        return power;
    }
    virtual void set_power(int new_power)
    {
        power = new_power;
    }

    virtual int _max_hp()
    {
        return max_hp;
    }
    virtual void set_max_hp(int new_max_hp)
    {
        max_hp = new_max_hp;
    }
};
