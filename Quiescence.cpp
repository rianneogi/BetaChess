#include "Engine.h"

int Engine::QuiescenceSearch(int alpha,int beta,Move lastmove)
{
	nodes++;
	if(nodes%1024==0)
	{
		checkup();
		//nodes = 0;
	}
	if(lastmove.getCapturedPiece()!=0)
	{
		vector<Move> vec = pos.generateMoves();
		//movesort(vec,0);
		int to = lastmove.getTo();
		//int max = CONS_NEGINF;
		bool change = false;
		Move m;
		int score = 0;
		for(int i = 0;i<vec.size();i++)
		{
			m = getHighestScoringMove(vec,i);
			if(m.getTo() == to) //capturing a piece that just captured a piece in the last move
			{
				pos.forceMove(m);
				score = -QuiescenceSearch(-beta,-alpha,m);
				pos.unmakeMove(m);
				if(score>=beta)
					return score;
				if(score>alpha)
				{
					alpha = score;
					change = true;
				}
			}
		}
		if(change)
			return alpha;
		return LeafEval(alpha,beta);
	}
	return LeafEval(alpha,beta);
}

int Engine::QuiescenceSearchStandPat(int alpha,int beta,Move lastmove)
{
	nodes++;
	if(nodes%1024==0)
	{
		checkup();
		//nodes = 0;
	}
	if(pos.getGameStatus()!=STATUS_NOTOVER)
	{
		int val = LeafEval(alpha,beta);
		if(val >= beta)
			return beta;
		else if(val < alpha)
			return alpha;
		return val;
	}
	int stand_pat = LeafEval(alpha,beta);
	if(stand_pat >= beta) //standpat
	{
		return beta;
	}
	if(stand_pat < alpha-200) //delta pruning
	{
		return alpha;
	}
	if(alpha < stand_pat)
	{
		alpha = stand_pat;
	}
	Move m;
	int score = 0;
    vector<Move> vec = pos.generateCaptures();
	for(int i = 0;i<vec.size();i++)
	{
		m = getHighestScoringMove(vec,i);
		pos.forceMove(m);
		score = -QuiescenceSearchStandPat(-beta,-alpha,m);
		pos.unmakeMove(m);
		if(score >= beta)
			return beta;
		if(alpha < score)
			alpha = score;
	}
	return alpha;
}