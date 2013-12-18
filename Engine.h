#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "Position.h"
#include "Node.h"
#include "TranspositionTable.h"
#include "Clock.h"

enum EvalConstants{CONS_INF = 20000,CONS_NEGINF = -20000, CONS_DRAW = 0, CONS_MATED = -10000};

extern int EndgameMaterial;

class EvalStruct
{
public:
	EvalStruct();
	EvalStruct(string personality); //loads evaluation data from personality file
	~EvalStruct();

	int MaterialValues[13]; //material values

	int PieceSq[13][64];    //piece square values for mid and endgame
	int PieceSqEG[13][64];

	int BishopPairBonus;
	int KnightPairBonus;
	int RookPairBonus;
	int NoPawnsPenalty;

	int DoubledPawnPenalty[8];  //pawn structure
	int IsolatedPawnPenalty[8];
	int PassedPawnBonus[64];
	int BlockedPawnPenaly[64];

	int RookHalfOpenBonus[8];
	int RookOpenBonus[8];
};

class Engine
{
    public:
    Position pos;
    Move historymove;
	int nodes;
	Clock timer;

	int myColor;
	deque<Move> PrincipalVariation;
	Move KillerMoves[2][100];
	int ply;

	//Engine.cpp
    Engine();
	Engine(int col);
    Engine(int col,Position const& p);
	Engine(int col,Position const& p,Move const& prevmove);
    ~Engine();
	void makeMove(int n);
	void makeMove(Move const& m);
	void unmakeMove(Move const& m);
	
	//Search.cpp
	Move IterativeDeepening();
	int think(int depth,int alpha,int beta,deque<Move>* variation);
	int AlphaBeta(int depth,int alpha,int beta,Move lastmove,deque<Move>* variation,bool cannull,bool dopv);
	void movesort(vector<Move>& moves,int depth);
	Move getHighestScoringMove(vector<Move>& moves,int currentmove);
	int getMoveScore(const Move& m);
	void ageHistoryTable();
	void checkup();
	void setKiller(Move m,int depth);

	//Quiescence.cpp
	int QuiescenceSearch(int alpha,int beta,Move lastmove);
	int QuiescenceSearchStandPat(int alpha,int beta,Move lastmove);
	int StaticExchangeEvaluation2(Move m);
	int StaticExchangeEvaluation(Move m);
	int StaticExchangeEvaluation(int square,int side);

	//Evaluation.cpp
	int LeafEval(int alpha,int beta);
	int FastEval();
	int getBoardMaterial();
	int Trace(int alpha,int beta);
};

void evalinit();
void searchinit();
int getNPS(int nodes,int milliseconds);
#endif // ENGINE_H_INCLUDED
