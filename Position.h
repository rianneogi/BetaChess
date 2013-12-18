#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

#include <vector>
#include "Move.h"
#include "TranspositionTable.h"

enum CASTLE {CASTLE_KINGSIDE,CASTLE_QUEENSIDE};
enum GAMESTATUS{STATUS_NOTOVER,STATUS_WHITEMATED,STATUS_BLACKMATED,STATUS_STALEMATE,STATUS_INSUFFICIENTMAT};

extern string pieceStrings[13];

class Position
{
public:
	Bitset TTKey;
    int Squares[64];
    Bitset Pieces[2][6];
    Bitset OccupiedSq;
    Bitset OccupiedSq90;
    Bitset OccupiedSq45;
    Bitset OccupiedSq135;
    int turn;
    Bitset castling[2][2];
    Bitset epsquare;
	vector<Move> movelist; //debug

    Position();
    Position(Position const& pos,Move const& m);
    ~Position();
    std::vector<Move> generateMoves();
	std::vector<Move> generateCaptures();
	std::vector<Move> generateMoves2();
	bool isLegal(Move const& m);
    void addMove(std::vector<Move>& vec,Move const& m);
    void forceMove(Move const& m);
    void makeMove(int n); //deprecated
    void unmakeMove(Move const& m);
    Move* getBestMove();
    bool checkLegal(Move* m);
    bool isAttacked(int turn,int n);
	Move getSmallestAttacker(int turn,int n);
	int getSmallestAttacker2(int turn,int n);
	Move makeCapture(int piece,int n); //makes the first legal move by piece to square n, returns the move made
    bool underCheck(int turn);
    int getGameStatus();
	int getColorPieces(int turn);
	void display(int flip);
	void takebackMove();
};

//int getSquare2Piece(int sq);
//int getSquare2Color(int sq);
//int getPiece2Square(int p,int color);
#endif // POSITION_H_INCLUDED
