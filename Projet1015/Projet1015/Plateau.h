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
	Plateau();
	void afficher();
	void setPiece(std::unique_ptr<Piece>& piece, Position pos);
	void retirerPiece(Position pos);
	void deplacerPiece(Position posActuelle, Position nouvellePos);
	std::unique_ptr<Piece>& getPiece(Position pos) { return plateau[pos.x-1][pos.y-1]; }
	void clearPlateau(Couleur couleur);
	void plateauRandom(Couleur couleur);
	bool roiEnEchec(Couleur couleur);
	//bool checkMate(Couleur couleur);
private:
	std::unique_ptr<Piece> plateau[8][8] = { nullptr };
};