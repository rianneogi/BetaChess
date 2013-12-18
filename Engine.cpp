#include "Engine.h"

#include <ctime>

//jmp_buf env;
//
//unsigned int HistoryScores[64][64];
//unsigned int ButterflyScores[64][64];
//
//int MAXTIME = 10000;
//int MAXDEPTH = 32;
//
//int MaterialValues[13] = {0,100,325,335,500,975,-CONS_MATED,-100,-325,-335,-500,-975,CONS_MATED};
//
//int ColorFactor[2] = {1,-1};
//
//int CONS_DOUBLEDPAWN[8] = {13,17,20,23,23,20,17,13};
//int CONS_ISOLATEDPAWN[8] = {7,10,25,40,40,25,10,7};
//int CONS_PASSEDPAWN[64] = {  0,  0,  0,  0,  0,  0,  0,  0,
//						     5, 10, 10, 10, 10, 10, 10,  5,
//						    10, 20, 20, 20, 20, 20, 20, 10,
//                            20, 40, 40, 40, 40, 40, 40, 20,
//                            30, 60, 60, 60, 60, 60, 60, 30,
//							40, 80, 80, 80, 80, 80, 80, 40,
//						   120,120,120,120,120,120,120,120,
//						   200,200,200,200,200,200,200,200};
//int CONS_ROOKHALFOPEN[8] = {15,15,20,30,30,20,15,15};
//int CONS_ROOKOPEN[8] = {20,20,30,40,40,30,20,20};
//
//int PieceSq[13][64];
//int PieceSqEG[13][64];
//int PieceSqValues[7][64] = 
//{
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //empty
//	{  0,  0,  0,  0,  0,  0,  0,  0, //pawn
//	   0,  0,  0,  0,  0,  0,  0,  0,
//	   0,  0,  2, 10, 10,  5,  0,  0,
//	   0,  0,  4, 22, 22, 11,  0,  0,
//	   0,  0,  5, 24, 24, 12,  0,  0,
//	  40, 50, 50, 50, 50, 50, 50, 40,
//	  70,100,100,100,100,100,100, 70,
//	 100,100,100,100,100,100,100,100},
//
//	{-10, -7, -5, -5, -5, -5, -7,-10, //knight
//	  -5,  0,  0,  0,  0,  0,  0, -7,
//	  -5,  0, 10,  3,  3, 10,  0, -5,
//	  -5,  0,  3, 15, 15,  3,  0, -5,
//	  -5,  0,  3, 15, 15,  3,  0, -5,
//	  35, 40, 50, 60, 60, 50, 40, 35,
//	  10, 15, 20, 25, 25, 20, 15, 10,
//	   0,  0,  0,  0,  0,  0,  0,  0},
//
//	{  5, -5, -7, -5, -5, -7, -5,  5, //bishop
//	   0, 10,  0,  0,  0,  0, 10,  0,
//	   0,  0, 10,  5,  5, 10,  0,  0,
//	   0,  0,  8, 12, 12,  8,  0,  0,
//	   0,  2,  5, 12, 12,  5,  2,  0,
//	   0,  0, 10,  5,  5, 10,  0,  0,
//	   0, 10,  0,  0,  0,  0, 10,  0,
//	   5,  0,  0,  0,  0,  0,  0,  5},
//
//	{  0,  0, 10, 10, 10, 10,  0,  0, //rook
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	  10, 10, 10, 20, 20, 20, 10, 10,
//	  10, 10, 10, 20, 20, 20, 10, 10},
//
//	{  0,  0,  0,  0,  0,  0,  0,  0, //queen
//	   0,  0,  0,  0,  2,  3,  0,  0,
//	   0,  0,  3,  1,  1,  3,  3,  0,
//	   0,  0,  1,  5,  5,  1,  0,  0,
//	   0,  0,  1,  5,  5,  1,  0,  0,
//	   0,  0,  3,  1,  1,  3,  0,  0,
//	   0,  0,  0,  0,  0,  0,  0,  0,
//	   0,  0,  0,  0,  0,  0,  0,  0},
//
//	{ 20, 30,  0,  0,  0, 20, 30, 20, //king
//	   0, 20,  0,-10,-10,  0, 15,  0,
//	   0,-10,-20,-20,-20,-20,-10,  0,
//	 -10,-20,-40,-40,-40,-40,-20,-10,
//	 -60,-60,-60,-60,-60,-60,-60,-60,
//	 -80,-80,-80,-80,-80,-80,-80,-80,
//	 -80,-80,-80,-80,-80,-80,-80,-80,
//	 -80,-80,-80,-80,-80,-80,-80,-80}
//};
//
//int PieceSqValuesEG[7][64] = 
//{
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //empty
//	{  0,  0,  0,  0,  0,  0,  0,  0, //pawn
//	   0,  5,  5, 10, 10,  5,  5,  0,
//	   5, 15, 15, 20, 20, 15, 15,  5,
//	  20, 30, 30, 40, 40, 30, 30, 20,
//	  30, 45, 45, 60, 60, 45, 45, 30,
//	  40, 60, 60, 80, 80, 60, 60, 40,
//	  70,100,100,100,100,100,100, 70,
//	 100,100,100,100,100,100,100,100},
//
//	{-10, -7, -5, -5, -5, -5, -7,-10, //knight
//	  -5,  0,  0,  0,  0,  0,  0, -7,
//	  -5,  0, 10,  3,  3, 10,  0, -5,
//	  -5,  0,  3, 15, 15,  3,  0, -5,
//	  -5,  0,  3, 15, 15,  3,  0, -5,
//	  35, 40, 50, 60, 60, 50, 40, 35,
//	  10, 15, 20, 25, 25, 20, 15, 10,
//	   0,  0,  0,  0,  0,  0,  0,  0},
//
//	{  5, -5, -7, -5, -5, -7, -5,  5, //bishop
//	   0, 10,  0,  0,  0,  0, 10,  0,
//	   0,  0, 10,  5,  5, 10,  0,  0,
//	   0,  0,  8, 12, 12,  8,  0,  0,
//	   0,  2,  5, 12, 12,  5,  2,  0,
//	   0,  0, 10,  5,  5, 10,  0,  0,
//	   0, 10,  0,  0,  0,  0, 10,  0,
//	   5,  0,  0,  0,  0,  0,  0,  5},
//
//	{  0,  0, 10, 10, 10, 10,  0,  0, //rook
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	   0,  0,  0, 10, 10, 10,  0,  0,
//	  10, 10, 10, 20, 20, 20, 10, 10,
//	  10, 10, 10, 20, 20, 20, 10, 10},
//
//	{  0,  0,  0,  0,  0,  0,  0,  0, //queen
//	   0,  0,  0,  0,  2,  3,  0,  0,
//	   0,  0,  3,  1,  1,  3,  3,  0,
//	   0,  0,  1,  5,  5,  1,  0,  0,
//	   0,  0,  1,  5,  5,  1,  0,  0,
//	   0,  0,  3,  1,  1,  3,  0,  0,
//	   0,  0,  0,  0,  0,  0,  0,  0,
//	   0,  0,  0,  0,  0,  0,  0,  0},
//
//	{-40,-30,-20,-10,-10,-20,-30,-40, //king
//	 -30,  0,  0,  0,  0,  0,  0,-30,
//	 -20,  0, 10, 20, 10, 10,  0,-20,
//	 -10,  0, 20, 40, 40, 20,  0,-10,
//	 -10,  0, 20, 40, 40, 20,  0,-10,
//	 -20,  0, 10, 20, 20, 10,  0,-20,
//	 -30,  0,  0,  0,  0,  0,  0,-30,
//	 -40,-30,-20,-10,-10,-20,-30,-40}
//};

Engine::Engine()
{
	myColor = COLOR_WHITE;
    pos = Position();
	historymove = Move();
}

Engine::Engine(int col)
{
	myColor = col;
	pos = Position();
	historymove = Move();
}

Engine::Engine(int col,Position const& p)
{
	myColor = col;
    pos = p;
	historymove = Move();
}

Engine::Engine(int col,Position const& p,Move const& prevmove)
{
	myColor = col;
    pos = p;
	historymove = Move();
}

Engine::~Engine()
{
}

void Engine::makeMove(int i)
{
	vector<Move> v = pos.generateMoves();
	Move m = v.at(i);
	pos.forceMove(m);
}

void Engine::makeMove(Move const& m)
{
	pos.forceMove(m);
}

void Engine::unmakeMove(Move const& m) //needs testing
{
	pos.unmakeMove(m);
}

//
//Move Engine::IterativeDeepening()
//{
//	int status = pos.getGameStatus();
//	if(status!=STATUS_NOTOVER)
//	{
//		if(status==STATUS_BLACKMATED || status==STATUS_WHITEMATED)
//		{
//			/*if(alpha>CONS_MATED)
//				return alpha;*/
//			return CONS_NULLMOVE;
//		}
//		if(status==STATUS_STALEMATE)
//		{
//			/*if(alpha>=CONS_DRAW)
//				return alpha;
//			if(beta<=CONS_DRAW)
//				return beta;*/
//			return CONS_NULLMOVE;
//		}
//	}
//
//	//init
//	nodes = 0;
//	for(unsigned int i = 0;i<64;i++)
//	{
//		for(unsigned int j = 0;j<64;j++)
//		{
//			HistoryScores[i][j] = 0;
//			ButterflyScores[i][j] = 0;
//		}
//	}
//	//int firstguess = 0;
//	deque<Move> line;
//	PrincipalVariation = deque<Move>();
//	//int score = think(2,CONS_NEGINF,CONS_INF,&line);
//	int score = AlphaBeta(1,CONS_NEGINF,CONS_INF,CONS_NULLMOVE,&line);
//	PrincipalVariation = line;
//	int val = 0;
//	timer.Start();
//	int takeback = 0;
//	int initialmovenumber = pos.movelist.size();
//	//cout << "takeback set " << takeback << " " << PrincipalVariation.size() << endl;
//	takeback = setjmp(env);
//	if(takeback!=0)
//	{
//		//cout << pos.movelist.size() << endl;
//		//cout << "Nodes: " << nodes << endl;
//		while(pos.movelist.size()>initialmovenumber)
//		{
//			pos.takebackMove();
//			takeback--;
//		}
//		return PrincipalVariation.at(0);
//	}
//	for(int i = 2;i<=MAXDEPTH;i++)
//	{
//		//mr = think(i,CONS_NEGINF,CONS_INF);
//		//mr = think(i,score - 100,score + 100); //aspiration search
//		//if(mr.eval <= score-150 || mr.eval >= score+150)
//		//{
//		//	cout << "Aspiration fail " << mr.eval << endl;
//		//	mr = think(i,CONS_NEGINF,CONS_INF);
//		//}
//		int low = 8;
//		int high = 8;
//		//if(i==4) DEBUG=true;
//		while(true)
//		{
//			//line = deque<Move>();
//			val = think(i,score - low,score + high,&line); //aspiration search
//			//cout << mr.move.toString() << " " << mr.eval << endl;
//			if(val <= score - low)
//			{
//				low = low << 1;
//				//cout << "Value is " << val <<" Aspiration fail low set to " << low << endl;
//				//high = 1;
//			}
//			else if(val >= score + high)
//			{
//				high = high << 1;
//				//cout << "Value is " << val << " Aspiration fail high set to " << high << endl;
//				//low = 1;
//			}
//			else break;
//		}
//        score = val;
//		//firstguess = val;
//		if(OUTPUT != OUTPUT_XBOARD)
//			cout << "info score cp " << score << " depth " << i << " nodes " << nodes << " pv ";
//		//info score cp 13  depth 1 nodes 13 time 15 pv f1b5 
//
//		for(int i = 0;i<line.size();i++)
//		{
//			cout << line.at(i).toString() << " ";
//		}
//		cout << endl;
//		PrincipalVariation = line;
//	}
//	Move bestmove = PrincipalVariation.at(0);
//	cout << "Nodes: " << nodes << endl;
//	//cout << bestmove.toString() << " " << firstguess << endl;
//	return bestmove;
//}
//
//Move Engine::IterativeDeepeningDepth(int depth)
//{
//	int status = pos.getGameStatus();
//	if(status!=STATUS_NOTOVER)
//	{
//		if(status==STATUS_BLACKMATED || status==STATUS_WHITEMATED)
//		{
//			/*if(alpha>CONS_MATED)
//				return alpha;*/
//			return CONS_NULLMOVE;
//		}
//		if(status==STATUS_STALEMATE)
//		{
//			/*if(alpha>=CONS_DRAW)
//				return alpha;
//			if(beta<=CONS_DRAW)
//				return beta;*/
//			return CONS_NULLMOVE;
//		}
//	}
//	for(unsigned int i = 0;i<64;i++)
//	{
//		for(unsigned int j = 0;j<64;j++)
//		{
//			HistoryScores[i][j] = 0;
//			ButterflyScores[i][j] = 0;
//		}
//	}
//	//int firstguess = 0;
//	deque<Move> line;
//	PrincipalVariation = deque<Move>();
//	int score = think(2,CONS_NEGINF,CONS_INF,&line);
//	PrincipalVariation = line;
//	int val = 0;
//	for(int i = 3;i<=depth;i++)
//	{
//		//mr = think(i,CONS_NEGINF,CONS_INF);
//		//mr = think(i,score - 100,score + 100); //aspiration search
//		//if(mr.eval <= score-150 || mr.eval >= score+150)
//		//{
//		//	cout << "Aspiration fail " << mr.eval << endl;
//		//	mr = think(i,CONS_NEGINF,CONS_INF);
//		//}
//		int low = 8;
//		int high = 8;
//		//if(i==4) DEBUG=true;
//		while(true)
//		{
//			//line = deque<Move>();
//			val = think(i,score - low,score + high,&line); //aspiration search
//			//cout << mr.move.toString() << " " << mr.eval << endl;
//			if(val <= score - low)
//			{
//				low = low << 1;
//				//cout << "Value is " << val <<" Aspiration fail low set to " << low << endl;
//				//high = 1;
//			}
//			else if(val >= score + high)
//			{
//				high = high << 1;
//				//cout << "Value is " << val << " Aspiration fail high set to " << high << endl;
//				//low = 1;
//			}
//			else break;
//		}
//        score = val;
//		//firstguess = val;
//		cout << "Depth " << i << endl;
//		cout << val << " ";
//		for(int i = 0;i<line.size();i++)
//		{
//			cout << line.at(i).toString() << " ";
//		}
//		cout << endl;
//		PrincipalVariation = line;
//	}
//	Move bestmove = PrincipalVariation.at(0);
//	cout << bestmove.toString() << " " << val << endl;
//	return bestmove;
//}
//
//MoveReturn Engine::MTDF(int f,int depth,deque<Move>* variation)
//{
//	int g = f;
//	int upperbound = CONS_INF;
//	int lowerbound = CONS_NEGINF;
//	MoveReturn mr;
//	while(lowerbound < upperbound)
//	{
//		int beta = g;
//		if(g==lowerbound)
//		{
//			beta = g+1;
//		}
//		g = think(depth,beta-1,beta,variation);
//		if(g<beta)
//		{
//			upperbound = g;
//		}
//		else
//		{
//			lowerbound = g;
//		}
//	}
//	return mr;
//}
//
//int Engine::AlphaBeta(int depth,int alpha,int beta,Move lastmove,deque<Move>* variation)
//{
//	int status = pos.getGameStatus();
//	if(status!=STATUS_NOTOVER)
//	{
//		if(status==STATUS_BLACKMATED || status==STATUS_WHITEMATED)
//		{
//			if(alpha>CONS_MATED)
//				return alpha;
//			return CONS_MATED; //mate
//		}
//		if(status==STATUS_STALEMATE)
//		{
//			if(alpha>=CONS_DRAW)
//				return alpha;
//			if(beta<=CONS_DRAW)
//				return beta;
//			return CONS_DRAW; //stalemate
//		}
//	}
//	int probe = Table.Probe(pos.TTKey,depth,alpha,beta);
//	if(probe != CONS_TTUNKNOWN)
//	{
//		//cout << probe << " found " << pos.TTKey << endl;
//		Move ttbestmove = Table.getBestMove(pos.TTKey);
//		if(!(ttbestmove==CONS_NULLMOVE))
//		{
//			variation->push_front(ttbestmove);
//		}
//		return probe;
//	}
//	int bound = TT_ALPHA;
//	if(depth==0)
//	{
//		int value = QuiescenceSearchStandPat(alpha,beta,lastmove); //go to quiescence
//		//Table.Save(pos.TTKey,depth,value,TT_EXACT);
//		return value;
//	}
//	nodes++;
//	if(nodes%1024==0)
//	{
//		checkup();
//		//nodes = 0;
//	}
//
//	deque<Move> dummyline;
//	deque<Move> lineptr;
//	Move m;
//	int score = 0;
//
//	//razoring
//	int fscore = LeafEval() + 150;
//	if((depth == 3) && (fscore <= alpha) && (pos.getColorPieces(getOpponent(pos.turn)) > 3)) 
//	{
//		depth = 2;
//	}
//
//	//more razoring
//	/*if(depth<=3 && depth>=2)
//	{
//		int fscore = LeafEval() + 300;
//		if (fscore < beta) 
//		{
//			deque<Move> line;
//			int newfscore = AlphaBeta(1,alpha,beta,CONS_NULLMOVE,&line);
//			if (newfscore < beta)
//			{
//				*variation = line;
//				return max(newfscore,fscore);
//			}
//		}
//	}*/
//
//	//adaptive null move pruning
//	Bitset Pieces = pos.OccupiedSq ^ pos.Pieces[COLOR_WHITE][PIECE_PAWN] ^ pos.Pieces[COLOR_BLACK][PIECE_PAWN];
//	int pieceCount = popcnt(Pieces);
//    if(depth>=3 && pos.underCheck(pos.turn)==false && pieceCount>6) //not endgame
//    {
//		int R = depth > 5 ? 3 : 2; //dynamic depth-based reduction
//		m = CONS_NULLMOVE;
//		pos.forceMove(m);
//        score = -AlphaBeta(depth-R-1,-beta,-beta+1,m,&dummyline); //make a null-window search (we don't care by how much it fails high, if it does)
//        pos.unmakeMove(m);
//		if(score >= beta)
//		{
//			//cout << "Null move cutoff " << beta << endl;
//			return beta;
//		}
//    }
//	vector<Move> vec = pos.generateMoves();
//	movesort(vec);
//	bool latemove = true;
//	bool foundpv = false;
//	Move alphamove = CONS_NULLMOVE;
//	for(unsigned int i = 0;i<vec.size();i++) //search
//	{
//		deque<Move> line;
//		m = vec.at(i);
//		//Position x = pos; //debug
//		pos.forceMove(m);
//		score = 0;
//		/*if(popcnt(pos.Pieces[COLOR_WHITE][PIECE_QUEEN])+popcnt(pos.Pieces[COLOR_WHITE][PIECE_PAWN])>9 || popcnt(pos.Pieces[COLOR_BLACK][PIECE_QUEEN])+popcnt(pos.Pieces[COLOR_BLACK][PIECE_PAWN])>9)
//		{
//			x.display(0);
//			pos.display(0);
//			printBitset(x.Pieces[COLOR_BLACK][PIECE_PAWN]);
//			cout << "\n";
//			printBitset(pos.Pieces[COLOR_BLACK][PIECE_PAWN]);
//			cout << m.toString() << endl;
//			cout << lastmove.toString() << endl;
//			for(int i = 0;i<pos.movelist.size();i++)
//			{
//				cout << pos.movelist.at(i).toString() << " " << endl;
//			}
//			pos.unmakeMove(m);
//			return beta;
//		}*/
//		if(foundpv) //principal variation search
//		{
//			score = -AlphaBeta(depth-1,-alpha-1,-alpha,m,&dummyline);
//			if(score>alpha && score<beta) //check for failure
//			{
//				score = -AlphaBeta(depth-1,-beta,-alpha,m,&line); //research
//				//cout << "pv research" << endl;
//			}
//		}
//		else if(i>=4 && depth>=3 && m.getCapturedPiece()==0 && m.getSpecial()==PIECE_NONE && latemove) //latemove reduction
//		{
//			score = -AlphaBeta(depth-3,-beta,-alpha,m,&dummyline);
//			//cout << "latemove" << endl;
//			if(score>alpha)
//			{
//				score = -AlphaBeta(depth-1,-beta,-alpha,m,&line);
//				//cout << "latemove research" << endl;
//			}
//		}
//		else
//		{
//			score = -AlphaBeta(depth-1,-beta,-alpha,m,&line);
//		}
//		pos.unmakeMove(m);
//		/*if(popcnt(pos.Pieces[COLOR_WHITE][PIECE_QUEEN])+popcnt(pos.Pieces[COLOR_WHITE][PIECE_PAWN])>9 || popcnt(pos.Pieces[COLOR_BLACK][PIECE_QUEEN])+popcnt(pos.Pieces[COLOR_BLACK][PIECE_PAWN])>9)
//		{
//			x.display(0);
//			pos.display(0);
//			printBitset(x.Pieces[COLOR_BLACK][PIECE_PAWN]);
//			cout << "\n";
//			printBitset(pos.Pieces[COLOR_BLACK][PIECE_PAWN]);
//			cout << m.toString() << endl;
//			cout << lastmove.toString() << endl;
//			for(int i = 0;i<pos.movelist.size();i++)
//			{
//				cout << pos.movelist.at(i).toString() << " " << endl;
//			}
//			return beta;
//		}*/
//		if(score>=beta)
//		{
//			Table.Save(pos.TTKey,depth,score,TT_BETA,m);
//			if(m.getCapturedPiece()==0)
//				HistoryScores[m.getFrom()][m.getTo()]+= 1<<depth;
//			return beta; //fail hard beta cutoff
//		}
//		else if(score>alpha)
//		{
//			if(m.getCapturedPiece()==0)
//				ButterflyScores[m.getFrom()][m.getTo()]+= 1<<depth;
//			bound = TT_EXACT;
//			alpha = score;
//			latemove = false;
//			foundpv = true;
//			alphamove = m;
//			lineptr = line;
//		}
//		else
//		{
//			if(m.getCapturedPiece()==0)
//				ButterflyScores[m.getFrom()][m.getTo()]+= 1<<depth;
//		}
//	}
//	if(!(alphamove==CONS_NULLMOVE))
//	{
//		*variation = lineptr;
//		variation->push_front(alphamove);
//	}
//	Table.Save(pos.TTKey,depth,alpha,bound,alphamove);
//	return alpha;
//}
//
//int Engine::QuiescenceSearch(int alpha,int beta,Move lastmove)
//{
//	nodes++;
//	if(nodes%1024==0)
//	{
//		checkup();
//		//nodes = 0;
//	}
//	if(lastmove.getCapturedPiece()!=0)
//	{
//		vector<Move> vec = pos.generateMoves();
//		movesort(vec);
//		int to = lastmove.getTo();
//		//int max = CONS_NEGINF;
//		bool change = false;
//		Move m;
//		int score = 0;
//		for(int i = 0;i<vec.size();i++)
//		{
//			m = vec.at(i);
//			if(m.getTo() == to) //capturing a piece that just captured a piece in the last move
//			{
//				pos.forceMove(m);
//				score = -QuiescenceSearch(-beta,-alpha,m);
//				pos.unmakeMove(m);
//				if(score>=beta)
//					return score;
//				if(score>alpha)
//				{
//					alpha = score;
//					change = true;
//				}
//			}
//		}
//		if(change)
//			return alpha;
//		return LeafEval();
//	}
//	return LeafEval();
//}
//
//int Engine::QuiescenceSearchStandPat(int alpha,int beta,Move lastmove)
//{
//	nodes++;
//	if(nodes%1024==0)
//	{
//		checkup();
//		//nodes = 0;
//	}
//	if(pos.getGameStatus()!=STATUS_NOTOVER)
//	{
//		int val = LeafEval();
//		if(val >= beta)
//			return beta;
//		else if(val < alpha)
//			return alpha;
//		return val;
//	}
//	int stand_pat = LeafEval();
//	if(stand_pat >= beta) //standpat
//	{
//		return beta;
//	}
//	if(stand_pat < alpha-200) //delta pruning
//	{
//		return alpha;
//	}
//	if(alpha < stand_pat)
//	{
//		alpha = stand_pat;
//	}
//	Move m;
//	int score = 0;
//    vector<Move> vec = pos.generateCaptures();
//	for(int i = 0;i<vec.size();i++)
//	{
//		m = vec.at(i);
//		pos.forceMove(m);
//		score = -QuiescenceSearchStandPat(-beta,-alpha,m);
//		pos.unmakeMove(m);
//		if(score >= beta)
//			return beta;
//		if(alpha < score)
//			alpha = score;
//	}
//	return alpha;
//}
//
//int Engine::StaticExchangeEvaluation(int square,int side)
//{
//	int value = 0;
//	int piece = pos.getSmallestAttacker(side,square);
//	if(piece!=PIECE_NONE)
//	{
//		
//	}
//	return value;
//}
//
//int Engine::LeafEval()
//{
//	nodes++;
//	if(nodes%1024==0)
//	{
//		checkup();
//		//nodes = 0;
//	}
//	int eval = 0;
//	Bitset Pieces = pos.OccupiedSq ^ pos.Pieces[COLOR_WHITE][PIECE_PAWN] ^ pos.Pieces[COLOR_BLACK][PIECE_PAWN];
//	int pieceCount = popcnt(Pieces);
//	bool isEG = false;
//	if(pieceCount <= 8)
//	{
//		isEG = true;
//	}
//
//	//Material eval
//	for(int i = 0;i<64;i++)
//	{
//		eval += MaterialValues[pos.Squares[i]];
//		if(isEG)
//			eval += PieceSqEG[pos.Squares[i]][i];
//		else
//			eval += PieceSq[pos.Squares[i]][i];
//	}
//
//	//Pawn structure
//	Bitset b = 0x0;
//	for(int i = 0;i<2;i++)
//	{
//		b = pos.Pieces[i][PIECE_PAWN];
//		while(b)
//		{
//			int k = firstOf(b);
//			b ^= getPos2Bit(k);
//			if(getAboveBits(i,k)&pos.Pieces[i][PIECE_PAWN]) //checks if there are friendly pawns in the same file
//			{
//				eval -= ColorFactor[i]*CONS_DOUBLEDPAWN[getFile(k)];
//			}
//			if((getAboveAndAboveSideBits(i,k)&pos.Pieces[getOpponent(i)][PIECE_PAWN])==0) //checks if the pawn is a passer
//			{
//				eval += ColorFactor[i]*CONS_PASSEDPAWN[k];
//			}
//			if((getSideBits(i)&pos.Pieces[i][PIECE_PAWN])==0) //checks if there are no friendly pawns on the adjacent files
//			{
//				eval -= ColorFactor[i]*CONS_ISOLATEDPAWN[getFile(k)];
//			}
//		}
//	}
//
//	//Rooks
//	for(int i = 0;i<2;i++)
//	{
//		b = pos.Pieces[i][PIECE_ROOK];
//		while(b)
//		{
//			int k = firstOf(b);
//			b ^= getPos2Bit(k);
//			if((getAboveBits(i,k)&pos.Pieces[i][PIECE_PAWN])==0) //checks if there arent friendly pawns in the same file
//			{
//				if(getAboveBits(i,k)&pos.Pieces[getOpponent(i)][PIECE_PAWN]) //checks if there are opponent pawns in the same file
//				{
//					eval += ColorFactor[i]*CONS_ROOKHALFOPEN[getFile(k)];
//				}
//				else
//				{
//					eval += ColorFactor[i]*CONS_ROOKOPEN[getFile(k)];
//				}
//			}
//		}
//	}
//
//	if(pos.turn==COLOR_BLACK)
//		return -eval;
//	return eval;
//}
//
//int Engine::Trace()
//{
//	int eval = 0;
//	Bitset Pieces = pos.OccupiedSq ^ pos.Pieces[COLOR_WHITE][PIECE_PAWN] ^ pos.Pieces[COLOR_BLACK][PIECE_PAWN];
//	int pieceCount = popcnt(Pieces);
//	bool isEG = false;
//	if(pieceCount > 8)
//	{
//		isEG = true;
//	}
//
//	//Material eval
//	for(int i = 0;i<64;i++)
//	{
//		eval += MaterialValues[pos.Squares[i]];
//		if(isEG)
//		{
//			eval += PieceSqEG[pos.Squares[i]][i];
//			cout << "Added " << MaterialValues[pos.Squares[i]] << " and " << PieceSqEG[pos.Squares[i]][i] << " for material on square " 
//			<< Int2Sq(i) << endl;
//		}
//		else
//		{
//			eval += PieceSq[pos.Squares[i]][i];
//			cout << "Added " << MaterialValues[pos.Squares[i]] << " and " << PieceSq[pos.Squares[i]][i] << " for material on square " 
//			<< Int2Sq(i) << endl;
//		}
//	}
//
//	//Pawn structure
//	Bitset b = 0x0;
//	for(int i = 0;i<2;i++)
//	{
//		b = pos.Pieces[i][PIECE_PAWN];
//		while(b)
//		{
//			int k = firstOf(b);
//			b ^= getPos2Bit(k);
//			if(getAboveBits(i,k)&pos.Pieces[i][PIECE_PAWN]) //checks if there are friendly pawns in the same file
//			{
//				eval -= ColorFactor[i]*CONS_DOUBLEDPAWN[getFile(k)];
//				cout << "Substracted " << (ColorFactor[i]*CONS_DOUBLEDPAWN[getFile(k)]) << " for doubled pawn on square " << Int2Sq(k) << endl;
//			}
//			if((getAboveAndAboveSideBits(i,k)&pos.Pieces[getOpponent(i)][PIECE_PAWN])==0) //checks if the pawn is a passer
//			{
//				eval += ColorFactor[i]*CONS_PASSEDPAWN[k];
//				cout << "Added " << (ColorFactor[i]*CONS_PASSEDPAWN[k]) << " for passed pawn on square " << Int2Sq(k) << endl;
//			}
//			if((getSideBits(i)&pos.Pieces[i][PIECE_PAWN])==0) //checks if there are no friendly pawns on the adjacent files
//			{
//				eval -= ColorFactor[i]*CONS_ISOLATEDPAWN[getFile(k)];
//				cout << "Substracted " << (ColorFactor[i]*CONS_ISOLATEDPAWN[getFile(k)]) << " for isolated pawn on square " << Int2Sq(k) << endl;
//			}
//		}
//	}
//
//	//Rooks
//	for(int i = 0;i<2;i++)
//	{
//		b = pos.Pieces[i][PIECE_ROOK];
//		while(b)
//		{
//			int k = firstOf(b);
//			b ^= getPos2Bit(k);
//			if((getAboveBits(i,k)&pos.Pieces[i][PIECE_PAWN])==0) //checks if there arent friendly pawns in the same file
//			{
//				if(getAboveBits(i,k)&pos.Pieces[getOpponent(i)][PIECE_PAWN]) //checks if there are opponent pawns in the same file
//				{
//					eval += ColorFactor[i]*CONS_ROOKHALFOPEN[getFile(k)];
//					cout << "Added " << (ColorFactor[i]*CONS_ROOKHALFOPEN[getFile(k)]) << " for rook on half open file on square " 
//						<< Int2Sq(k) << endl;
//				}
//				else
//				{
//					eval += ColorFactor[i]*CONS_ROOKOPEN[getFile(k)];
//					cout << "Added " << (ColorFactor[i]*CONS_ROOKOPEN[getFile(k)]) << " for rook on open file on square " 
//						<< Int2Sq(k) << endl;
//				}
//			}
//		}
//	}
//
//	if(pos.turn==COLOR_BLACK)
//		return -eval;
//	return eval;
//}
//
//void evalinit()
//{
//	for(int i = 0;i<13;i++)
//	{
//		for(int j = 0;j<64;j++)
//		{
//			if(i<7)
//			{
//				PieceSq[i][j] = PieceSqValues[i][j];
//				PieceSqEG[i][j] = PieceSqValuesEG[i][j];
//			}
//			else
//			{
//				PieceSq[i][j] = -PieceSqValues[i-6][getturn180(j)];
//				PieceSqEG[i][j] = -PieceSqValuesEG[i][j];
//			}
//		}
//	}
//}
//
//void Engine::movesort(vector<Move>& moves)
//{
//	vector<double> score;
//	for(unsigned int i = 0;i<moves.size();i++)
//	{
//		Move m = moves.at(i);
//		score.push_back((HistoryScores[m.getFrom()][m.getTo()]*1.0)/ButterflyScores[m.getFrom()][m.getTo()]);
//	}
//	for(unsigned int i = 0;i<moves.size();i++)
//	{
//		for(unsigned int j = 0;j<moves.size()-1-i;j++)
//		{
//			if(score.at(j)<score.at(j+1))
//			{
//				int tmp = score.at(j);
//				score.at(j) = score.at(j+1);
//				score.at(j+1) = tmp;
//				Move mov = moves.at(j);
//				moves.at(j) = moves.at(j+1);
//				moves.at(j+1) = mov;
//			}
//		}
//	}
//}
//
//void Engine::checkup()
//{
//	//time_t t;
//	//time(&t);
//	timer.Stop();
//	int seconds = timer.ElapsedMilliseconds();
//	if(seconds >= MAXTIME)
//	{
//		cout << "milliseconds: " << seconds << endl;
//		longjmp(env,seconds);
//	}
//	//cout << (seconds-MAXTIME) << endl;
//}

///OLD FUNCTIONS
//Move Engine::think2(int depth,int alpha,int beta)
//{
//	Move alphamove = Move();
//	if(depth==0)
//		return Move();
//	int status = pos.getGameStatus();
//	if(status!=STATUS_NOTOVER)
//	{
//		return Move();
//	}
//	n = root;
//	shared_ptr<Node> ptr = n.lock();
//	if(ptr->children->size()==0)
//		ptr->setChildren(pos.generateMoves()); //generate moves
//	for(unsigned int i = 0;i<ptr->children->size();i++) //search
//	{
//		Move m = ptr->children->at(i)->move;
//		cout << "Analyzing " << m.toString() << endl;
//		pos.forceMove(m);
//		n = ptr->children->at(i);
//		int val = -AlphaBeta(depth-1,-beta,-alpha);
//		pos.unmakeMove(m);
//		n = ptr->parent;
//		if(val>=beta)
//			return m;
//		if(val>alpha)
//		{
//			alpha = val;
//			alphamove = m;
//		}
//	}
//	cout << alphamove.toString() << " " << alpha << endl;
//	return alphamove;
//}
//
//int Engine::AlphaBeta2(int depth,int alpha,int beta)
//{
//	if(depth==0)
//	{
//		return QuiscenceSearch(); //leaf evaluation
//	}
//	int status = pos.getGameStatus();
//	if(status!=STATUS_NOTOVER)
//	{
//		if((status==STATUS_BLACKMATED && myColor==COLOR_WHITE)||(status==STATUS_WHITEMATED && myColor==COLOR_BLACK))
//		{
//			return CONS_INF; //engine has mated opponent
//		}
//		if((status==STATUS_WHITEMATED && myColor==COLOR_WHITE)||(status==STATUS_BLACKMATED && myColor==COLOR_BLACK))
//		{
//			return CONS_NEGINF; //engine is mated
//		}
//		if(status==STATUS_STALEMATE)
//		{
//			return CONS_DRAW; //stalemate
//		}
//	}
//	shared_ptr<Node> ptr = n.lock();
//	if(ptr->children->size()==0)
//		ptr->setChildren(pos.generateMoves()); //generate moves
//	for(unsigned int i = 0;i<ptr->children->size();i++) //search
//	{
//		Move m = ptr->children->at(i)->move;
//		//cout << m.toString() << endl;
//		pos.forceMove(m);
//		n = ptr->children->at(i);
//		int val = -AlphaBeta(depth-1,-beta,-alpha);
//		pos.unmakeMove(m);
//		n = ptr->parent;
//		if(val>=beta)
//			return val;
//		if(val>=alpha)
//			alpha = val;
//	}
//	return alpha;
//}
//
//int Engine::QuiscenceSearch2()
//{
//	shared_ptr<Node> ptr = n.lock();
//	if(ptr->move.getCapturedPiece()!=0)
//	{
//		ptr->setChildren(pos.generateMoves());
//		int to = ptr->move.getTo();
//		int max = CONS_NEGINF;
//		bool change = false;
//		for(int i = 0;i<ptr->children->size();i++)
//		{
//			if(ptr->children->at(i)->move.getTo() == to) //capturing a piece that just captured a piece in the last move
//			{
//				Move m = ptr->children->at(i)->move;
//				pos.forceMove(m);
//				n = ptr->children->at(i);
//				//cout << "quiscence" << endl;
//				int val = -QuiscenceSearch();
//				pos.unmakeMove(m);
//				n = ptr->parent;
//				if(val>max)
//				{
//					max = val;
//					change = true;
//				}
//			}
//		}
//		if(change)
//			return max;
//		return LeafEval();
//	}
//	return LeafEval();
//}
//
//void Engine::makeMove(int i)
//{
//	root->parent.reset();
//	if(root->children->size()==0)
//	{
//		root->setChildren(pos.generateMoves());
//	}
//	Move m = root->children->at(i)->move;
//	pos.forceMove(m);
//	root = root->children->at(i);
//	n = root;
//}
//
//void Engine::unmakeMove() //doesnt work
//{
//	Move m = root->parent.lock()->move;
//	pos.unmakeMove(m);
//	root = root->parent.lock();
//	n = root;
//}