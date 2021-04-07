#pragma once
#include "Piece.h"
// ENTETE DE FICHIER

#include <iostream>
#include <string>


// class Plateau
// Une instance de Plateau représente un échiquier. Un échiquier 
// possède 64 cases, représenté par un array bi-dimentionnel 
// de unique_ptr<Piece>.
class Plateau
{
public:
	Plateau();
	void afficher();
	void setPiece(std::unique_ptr<Piece>& piece, Position pos);
	void retirerPiece(Position pos);
	void deplacerPiece(Position posActuelle, Position nouvellePos);
	void clearPlateau(Couleur couleur);
	void setRandomPiece(std::unique_ptr<Piece>& piece);
	void plateauRandom(Couleur couleur);
	bool roiEnEchec(Couleur couleur);
	std::unique_ptr<Piece>& getPiece(Position pos) { return plateau[pos.x - 1][pos.y - 1]; }
private:
	std::unique_ptr<Piece> plateau[8][8] = { nullptr };
};