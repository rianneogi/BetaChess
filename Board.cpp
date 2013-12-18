#include "Board.h"


Board::Board(void)
{
}


Board::~Board(void)
{
}

void Board::makeMove(Move const& m)
{
	pos.forceMove(m);
	prevmoves.push_back(m);
}

void Board::makeMove(int n)
{
	pos.forceMove(moves.at(n));
	prevmoves.push_back(moves.at(n));
}

void Board::unmakeMove()
{
	if(prevmoves.size()!=0)
	{
		Move m = prevmoves.at(prevmoves.size()-1);
		prevmoves.pop_back();
		pos.unmakeMove(m);
	}
}

void Board::generateMoves()
{
	moves = pos.generateMoves();
}

int Board::getGameStatus()
{
	if(moves.size()==0)
	{
		if(pos.underCheck(pos.turn) && pos.turn==COLOR_WHITE)
		{
			return STATUS_WHITEMATED;
		}
		else if(pos.underCheck(pos.turn) && pos.turn==COLOR_BLACK)
		{
			return STATUS_BLACKMATED;
		}
		else
		{
			return STATUS_STALEMATE;
		}
	}
	return STATUS_NOTOVER;
}