#include <vector>
#include "FootCommander.hpp"
#include <iostream>
void FootCommander::act(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    FootSoldier::act(board, location);
    act_as_commander(board, location);
}
void FootCommander::act_as_commander(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *maybeFoot = board[i][j];
            if (maybeFoot != nullptr && maybeFoot->_player() == _player())
            {
                if (dynamic_cast<FootSoldier *>(maybeFoot) && !(dynamic_cast<FootCommander *>(maybeFoot)))
                    maybeFoot->act(board, {i, j});
            }
        }
    }
}

