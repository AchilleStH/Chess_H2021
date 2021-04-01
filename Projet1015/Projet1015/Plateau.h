#include <iostream>
#include <string>
#include <vector>
#pragma once
#include <map>
#include <algorithm>
#include <string>
#include "Piece.h"


using namespace std;


// class Plateau
// Une instance de Plateau repr�sente un �chiquier.
// Un �chiquier poss�de 64 cases, repr�sent� par 
// un array bi-dimentionnel de Case.
// setPiece permet d'affecter une pi�ce a une case
// du plateau, et afficher affiche le tableau
// dans la console.
class Plateau
{
public:
	// SUPPRIMER CETTE M�THODE
	Plateau();
	void afficher();
	void setPiece(shared_ptr<Piece> piece, Position pos);
	void deplacerPiece(Position posActuelle, Position nouvellePos);
private:
	shared_ptr<Piece> plateau[8][8] = { nullptr };
};