#pragma once

#include <iostream>
#include <string>


// Permet d'utiliser Plateau avant sa définition
class Plateau;

// struct Position
// Structure qui permet de définir une position à l'aide de
// deux coordonées x et y => x représente l'index de la ligne
// et y l'index de la colonne.
struct Position
{
	// Vérifie si une position est valide. (x et y compris entre 1 et 8)
	Position(int x_, int y_)
	{
		if (x_ <= 8 && x_ >= 1 && y_ <= 8 && y_ >= 1)
		{
			x = x_;
			y = y_;
		}
		else
			throw std::runtime_error("Position Invalide");
	}
	Position(){ x = 1; y = 1;}
	int x = 1;
	int y = 1;
};

// enum class Couleur
// Enumération permettant de définir la couleur d'une
// pièce. Une pièce peut être Blanche ou Noire.
enum class Couleur {Blanc, Noir};

inline Couleur operator!(Couleur C) 
{
	switch (C) 
	{
	case Couleur::Blanc: return Couleur::Noir;
	case Couleur::Noir: return Couleur::Blanc;
	default: return Couleur::Blanc;
	}
}

// class Piece
// Chaque pièce possède une position, une couleur,
// ainsi qu'un mnemonique (R pour roi, Q pour reine...)
// verificationDeplacement permet de vérifier la validité
// d'un déplacement. deplacement modifie la position
// de la pièce.
class Piece
{
public: 
	Piece() { couleurPiece = Couleur::Blanc; mnemonique = ' '; };
	virtual bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier) = 0;
	char getInfos() const;
	Position position;
	Couleur couleurPiece;
	char mnemonique;
};

// Class Tour
// Une tour est une pièce
class Tour : public Piece
{
public:
	Tour(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
};

// Class Roi
// Un roi est une pièce
class Roi : public Piece
{
public:
	Roi(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
	bool verificationEchec(Plateau &echiquier);

private:
	std::pair<int, int> deplacementsPossibles[8] = { {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}, {+1, -1}, {0, -1}, {-1, -1} };
	bool estEnEchec = false;
};

// Class Cavalier
// Un cavalier est une pièce
class Cavalier : public Piece
{
public:
	Cavalier(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
private:
	std::pair<int, int> deplacementsPossibles[8] = { {-2, -1}, {-1, -2}, {+1, -2}, {-2, +1}, {-1, +2}, {+1, +2}, {+2, +1}, {+2, -1} };
};

// Pièce non implémentée
//class Reine : public Piece
//{
//public: 
//	Reine(Couleur couleur, Position pos);
//	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
//};


// Pièce non implémentée
//class Fou : public Piece
//{
//public:
//	Fou(Couleur couleur, Position pos);
//	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
//};