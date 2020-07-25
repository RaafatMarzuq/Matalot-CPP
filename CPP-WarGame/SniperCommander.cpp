#include "SniperCommander.hpp"
void SniperCommander::act(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Sniper::act(board, location);
    act_as_commander(board, location);
}
void SniperCommander::act_as_commander(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *maybeSniper = board[i][j];
            if (maybeSniper != nullptr && maybeSniper->_player() == _player())
            {
                if (dynamic_cast<Sniper *>(maybeSniper) && !(dynamic_cast<SniperCommander *>(maybeSniper)))
                    maybeSniper->act(board, {i, j});
            }
        }
    }
}