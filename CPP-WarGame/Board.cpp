#include "Board.hpp"
#include <map>

using namespace std;
namespace WarGame
{
        std::map<int, int> m;

        //Set a place on the board with soldier
        Soldier *&Board::operator[](std::pair<int, int> location)
        {
                return this->board[location.first][location.second];
        }

        //get a soldier from a place on the board.
        Soldier *Board::operator[](std::pair<int, int> location) const
        {
                return this->board[location.first][location.second];
        }

        void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
        {
                if ((*this)[source] == nullptr)
                {
                        throw runtime_error("No soldier at the source point");
                }
                Soldier *mover = (*this)[source];
                if (mover->_player() != player_number)
                {
                        throw runtime_error("Player can't move other player soldier");
                }
                std::pair<int, int> dest; // will be the destination point.
                switch (direction)
                {
                case Left:
                        dest.first = source.first;
                        dest.second = source.second - 1;
                        break;
                case Right:
                        dest.first = source.first;
                        dest.second = source.second + 1;
                        break;
                case Up:
                        dest.first = source.first + 1;
                        dest.second = source.second;
                        break;
                case Down:
                        dest.first = source.first - 1;
                        dest.second = source.second;
                        break;
                }
                //Out of the board
                if (dest.first >= board.size() || dest.first < 0 || dest.second >= board[0].size() || dest.second < 0)
                        throw invalid_argument("Out of the board");

                if ((*this)[dest] != nullptr)
                {
                        throw runtime_error("Dest has a soldier already");
                }

                (*this)[dest] = mover;
                (*this)[source] = nullptr;
                mover->act(this->board, dest);
        }

        bool Board::has_soldiers(uint player) const
        {
                for (int i = 0; i < board.size(); i++)
                {
                        for (int j = 0; j < board[i].size(); j++)
                        {
                                Soldier *check = this->board[i][j];
                                if (check != nullptr)
                                {
                                        if (check->_player() == player)
                                                return true;
                                }
                        }
                }
                return false;
        }
} // namespace WarGame