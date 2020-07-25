#include "ParamedicCommander.hpp"

void ParamedicCommander::act(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Paramedic::act(board, location);
  for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *maybeParamedic = board[i][j];
            if (maybeParamedic != nullptr && maybeParamedic->_player() == _player())
            {
                if (dynamic_cast<Paramedic *>(maybeParamedic) && !(dynamic_cast<ParamedicCommander *>(maybeParamedic)))
                    maybeParamedic->act(board, {i, j});
            }
        }
    }}
void ParamedicCommander::act_as_commander(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *maybeParamedic = board[i][j];
            if (maybeParamedic != nullptr && maybeParamedic->_player() == _player())
            {
                if (dynamic_cast<Paramedic *>(maybeParamedic) && !(dynamic_cast<ParamedicCommander *>(maybeParamedic)))
                    maybeParamedic->act(board, {i, j});
            }
        }
    }
}
