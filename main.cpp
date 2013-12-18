///TODO 
// show principal variation and evaluation on gui
// add highlighted squares
// add sound on move played
///TODO LIST

///STATUS
// Currently working on improving the engine
// Transposition Table added
// Move ordering added
// Quiescense search added
// Engine has been made
// Check, checkmate and stalemate done
// Castling done
// ep done and checked
// Moving for all pieces done and checked
// Bishop moves done and checked
// Rook Rank and File moves done and checked
// Pawn, King and Knight moves done and checked
// initial position setup done
///STATUS

///BUGS
// FIXED - Bug where white king is being replaced by black king during engine search
// FIXED - Bug regarding sliding piece move generation
///BUGS

///HISTORY
// 22-05-2013 - Gamma Chess created with Graphics
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
//#include "Interface.h"
#include "GUI.h"

using namespace std;

int main(int argc, char* args[])
{
	srand(time(0));
    datainit();
	evalinit();
	TTinit();
    cout << "Initialization done" << endl;
	GUI g = GUI();
	g.start();
    return 0;
}
