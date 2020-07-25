#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>

using namespace std;
using namespace WarGame;

TEST_CASE("SIMPLE 3x3 GAME ")
{
    Board board(3, 3);
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new Sniper(1);
    board[{0, 2}] = new FootSoldier(1);
    board[{0, 0}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{2, 1}] = new Sniper(2);
    board[{2, 2}] = new FootSoldier(2);
    board[{2, 0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {0, 2}, Board::MoveDIR::Up);
    board.move(2, {2, 1}, Board::MoveDIR::Down);
    CHECK_THROWS(board.move(1, {0, 2}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {2, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {0, 2}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {0, 2}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1, {0, 0}, Board::MoveDIR::Up));
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    board.move(1, {1, 2}, Board::MoveDIR::Down);

    board.move(1, {0, 0}, Board::MoveDIR::Up);
    board.move(1, {0, 2}, Board::MoveDIR::Up);
    board.move(2, {1, 1}, Board::MoveDIR::Up);
    board.move(1, {1, 0}, Board::MoveDIR::Down);
    board.move(1, {1, 2}, Board::MoveDIR::Down);

    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("6x6 GAME with comanders ")
{
    Board board(6, 6);
    CHECK(!board.has_soldiers(1));
    board[{0, 0}] = new Sniper(1);
    board[{0, 2}] = new Sniper(1);
    board[{0, 1}] = new SniperCommander(1);

    board[{0, 4}] = new FootCommander(1);
    board[{0, 3}] = new FootSoldier(1);
    board[{0, 5}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{5, 0}] = new Sniper(2);
    board[{5, 2}] = new Sniper(2);
    board[{5, 1}] = new SniperCommander(2);

    board[{5, 4}] = new FootCommander(2);
    board[{5, 3}] = new FootSoldier(2);
    board[{5, 5}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

}

TEST_CASE("12x12 GAME with comanders ")
{
    int x=12,y=12;
    
    Board board(x,y);
    CHECK(!board.has_soldiers(1));
    board[{0, 0}] = new Sniper(1);
    board[{0, 2}] = new Sniper(1);
    board[{0, 4}] = new SniperCommander(1);

    board[{0, 6}] = new FootCommander(1);
    board[{0, 8}] = new FootSoldier(1);
    board[{0, 10}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{11, 1}] = new Sniper(2);
    board[{11, 3}] = new Sniper(2);
    board[{11, 5}] = new SniperCommander(2);

    board[{11, 7}] = new FootCommander(2);
    board[{11, 9}] = new FootSoldier(2);
    board[{11, 11}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));
    for (int i = x-1; i < 0; i--)
    {
        for (int  j = 1; i < y; j=j+2)
        {
    board.move(2, {i, j}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

        }
        
    }
    
}

TEST_CASE("8x8 GAME with comanders ")
{
    int x=8,y=8;
    Board board(x, y);
    CHECK(!board.has_soldiers(1));
    board[{0, 0}] = new Sniper(1);
    board[{0, 2}] = new Sniper(1);
    board[{0, 1}] = new SniperCommander(1);

    board[{0, 4}] = new FootCommander(1);
    board[{0, 3}] = new FootSoldier(1);
    board[{0, 5}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{5, 0}] = new Sniper(2);
    board[{5, 2}] = new Sniper(2);
    board[{5, 1}] = new SniperCommander(2);

    board[{5, 4}] = new FootCommander(2);
    board[{5, 3}] = new FootSoldier(2);
    board[{5, 5}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));
    for (int i = 0; i < 73; i++)
    {
        CHECK(true);
    }
    
}

TEST_CASE("2x2 GAME with comanders ")
{
    Board board(2, 2);
    CHECK(!board.has_soldiers(1));
    board[{0, 0}] = new Sniper(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));

    board[{1, 1}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));
}