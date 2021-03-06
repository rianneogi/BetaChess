///TODO
// Use arrays instead of vectors to improve speed
// check ep
// find a way to make PV generation faster my making lineptr a pointer instead of an object
// add enpassant values to Hash Entries
///TODO

///BUGS
// Search doesn't consider enpassant moves even though they are generated my movegen
// FIXED - Engine crashes when near mate
// FIXED - Bug where after calculating upto depth 6 then calculating upto depth 5 after e2e4 e7e5 leads to messed up engine position
// FIXED - Bug where calculation in depth 6 or above leads to messed up engine position
// FIXED - Bug where white king is being replaced by black king during engine search
// FIXED - Bug regarding sliding piece move generation
///BUGS

///BUILDS
// Build 37 - 08-11-2014 - Optimized a little bit more
// Build 36 - 08-11-2014 - Optimized a little bit
// Build 35 - 08-11-2014 - Fixed 3-fold repetition bug by making evaluation return 0 once 2 similar positions occur(instead of 3)
// Build 34 - 06-04-2014 - Added bishop pawn same color adjustment
// Build 33 - 19-01-2014 - Fixed SEE
// Build 32 - 04-01-2014 - Added epsquare to TTKey
// Build 31 - 29-12-2013 - Fixed 3-fold repetition check
// Build 30 - 28-12-2013 - Added Castling to TTKey
// Build 29 - 28-12-2013 - Reduced queen out early penalty, improved Qsearch by increase margin for big delta pruning, added 3-fold repetition check
// Build 28 - Improved eval, added huge penalty for bringing the queen out early, now beats Faile consistently
// Build 27 - Slighty improved eval, now gives bonus to connected rooks
// Build 26 - Now checks for mate/stalemate after searching all moves rather than before(this allows us to generate only capture moves if necessary)
//                approx. 50% improvement in nps
// Build 25 - GenerateMoves() now generates pseudo-legal moves and move legality checking happens while making the move
//                fixed a bug where ply wasnt incrementing in quiescence (a massive approx. 100% improvement in nps)
// Build 24 - Made SEE faster by making it iterative (approx. 10% improvement in nps)
// Build 23 - Added mobility factor in evaluation and improved king safety evaluation
// Build 22 - Disabled lazy eval and basic move ordering
// Build 21 - Fixed a few bugs with move ordering that caused some moves to not be considered at all
// Build 20 - Fixed en passant, fixed some problems with TT(ep and castle moves were not properly updating the key)
// Build 19 - Improved move ordering with changes to SEE
// Build 18 - Improved king safety evaluation
// Build 17 - Fixed some bugs with leaf evaluation
// Build 16 - Minor performance improvement
// Build 15 - Increased TT size to 128 MB
// Build 14 - Improved king evaluation, added outpost evaluation, added piece attack evaluation
// Build 13 - Added King Safety Evaluation, engine plays much more safer now.
// Build 12 - Increased Endgame Material, engine should now take its king out in endgames.
// Build 11 - Added Static Exchange Evaluation for move sorting
// Build 10 - Added Hash Table Heuristic for move sorting
// Build 9 - Added basic lazy eval, improved evaluation
// Build 8 - Made sorting more retroactive, now sorts every time a child node is searched instead of sorting only once at the start of the search.
//             This is a big improvement over the previous builds, it goes a full extra depth at start position in 10 seconds.
// Build 7 - Readded basic move sort, added killer move heuristic and reimplemented PV search first
// Build 6 - Added killer move heuristic and PV is now searched first
// Build 5 - Removed basic move sort, moves are sorted only by history heuristic
// Build 4 - Engine no longer searches PV first. This fixed a number of bugs. I'll add a proper implementation of PV later.
// Build 3 - Uses mirror instead of turn180 in eval
// Build 2 - Does null move searching in pv searches and fails
// Build 1 - Original Build
///BUILDS

///HISTORY
// 26-11-2013 - Build 9 : Added Lazy Eval and Killer Move Heuristic
// 24-11-2013 - Divided Engine.cpp into three parts:- Search.cpp, Quiescence.cpp and Evaluation.cpp
// 21-11-2013 - Added UCI support
// 15-09-2013 - Added razoring
// 19-07-2013 - Added Stand Pat Quiescence Search
// 14-07-2013 - Massive increase in speed, depth 6 gives d7d5 after e2e4 in ~2.79 seconds
// 11-07-2013 - Added turn to the TTKey
// 09-07-2013 - Program now searches Principal Variation first
// 08-07-2013 - Program now prints Principal Variation
// 30-06-2013 - Added Principal Variation Search
// 28-06-2013 - Added Relative History Heuristic and Late Move Reductions
// 28-06-2013 - Added extended bounds Aspiration Search
// 27-06-2013 - Added Aspiration Search and Null Move Pruning
// 07-05-2013 - Improved move ordering
// 07-05-2013 - Improved move generation speed
// 07-05-2013 - Added Endgame Evaluation
// 07-05-2013 - Added Transposition Table
// 23-04-2013 - Improved leaf evaluation, now it takes into account pawn structure and rook mobility
// 22-04-2013 - Improved move ordering
// 21-04-2013 - Added move ordering
// 21-04-2013 - Added quiescence search
// 21-04-2013 - Improved memory management
// 21-04-2013 - Improved speed of generateMoves() and forceMove()
// 19-04-2013 - Engine now does not take alot of time to evaluate beyond depth 2
// 19-04-2013 - Engine now works! *Celebration* Although it takes a lot of time to evaluate beyond depth 2
// 18-04-2013 - Added conditions for check, checkmate and stalemate
// 17-04-2013 - Added unmakeMove()
// 17-04-2013 - Basic Move generation and enpassant done
// 16-04-2013 - Made a couple of bitops functions inline
// 27-11-2012 - Made a move list to trace back with unmakeMove()
//   -Doesn't work because when I regenerate moves after coming back to root position, already analysed memory is lost
// Original BetaChess with only prevmove to trace back for unmakeMove()
//   -Doesn't work because after using unmakeMove() to go back, you don't know the previous move
///HISTORY

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "..\..\Common\Interface.h"

using namespace std;

int main(int argc, char* args[])
{
	srand(time(0));
	//loadFromLua("Personalities\\Wierd.lua");
    datainit();
	searchinit();
	evalinit();
	TTinit();
    cout << "Initialization done" << endl;
    Interface i = Interface();
	try{
    i.start();
	}catch(exception e) {cout << e.what() << endl;}
    return 0;
}
