#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "Piece.h"

using namespace std;

class Case
{
public: 
	Case();
	void setPieceCase(Piece nouvellePiece);
	Piece getPieceCase() const;
private:
	Piece piece_;
};
