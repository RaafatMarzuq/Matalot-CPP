#include "Sniper.hpp"
#include <iostream>
void Sniper::act(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Soldier *victim = nullptr;
    int Strongest = 0;
    int row, col;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *temp = board[i][j];
            if ((temp != nullptr) && (this->_player() != temp->_player()))
            {
                if (temp->_hp() > Strongest)
                {
                    Strongest = temp->_hp();
                    victim = temp;
                    row = i;
                    col = j;
                }
            }
        }
    }
    if (victim != nullptr)
    {
        victim->set_hp(victim->_hp() - _power());
        if (victim->_hp() <= 0)
        {
            delete board[row][col];
            board[row][col] = nullptr;
        }
    }
}