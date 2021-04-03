#pragma once
#include "Piece.h"
#include <iostream>
#include <string>


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
	void setPiece(std::shared_ptr<Piece> piece, Position pos);
	void retirerPiece(Position pos);
	void deplacerPiece(Position posActuelle, Position nouvellePos);
	std::shared_ptr<Piece> getPiece(Position pos) const { return plateau[pos.x-1][pos.y-1]; }
	void clearPlateau();
	void plateauRandom();
private:
	std::shared_ptr<Piece> plateau[8][8] = { nullptr };
};