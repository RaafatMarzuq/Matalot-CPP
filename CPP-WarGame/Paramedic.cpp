#include "Paramedic.hpp"

    void Paramedic::act(vector<vector<Soldier *>> &board, pair<int, int> location)
    {

        int row = location.first;
        int col = location.second;

        for (int k = row - 1; k <= row + 1; k++)
        {
            for (int l = col - 1; l <= col + 1; l++)
            {
                if (k >= 0 && k < board.size() && l >= 0 && l < board[0].size())
                {
                    Soldier *s = board[k][l];

                    if (s != nullptr && s->_player() == _player())
                    {
                        if (!(k == row && l == col))
                            s->set_hp(s->_max_hp());
                    }
                }
            }
        }
    }
