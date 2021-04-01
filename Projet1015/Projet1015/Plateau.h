#include <iostream>
#include <string>
#include <vector>
#pragma once
#include <map>
#include <algorithm>
#include <string>
#include "Piece.h"
#include "Case.h"

using namespace std;



class Plateau
{
public:
	// SUPPRIMER CETTE MÉTHODE
	Plateau() = default;
	void afficher();
	void setPiece(unique_ptr<Piece> &piece, Position pos);
private:
	Case plateau[8][8];
};