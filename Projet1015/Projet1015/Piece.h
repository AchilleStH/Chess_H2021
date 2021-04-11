// ENTETE DE FICHIER



#pragma once

#include <iostream>
#include <string>


// Permet d'utiliser Plateau avant sa définition
class Plateau;

// struct Position
// Structure qui permet de définir une position à l'aide de
// deux coordonées x et y. x représente l'index de la ligne
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
enum class Couleur { Blanc, Noir };



// class Piece
// Chaque pièce possède une position, une couleur,
// ainsi qu'un mnemonique (R pour roi, C pour cavalier...)
class Piece
{
public: 
	Piece() { couleurPiece = Couleur::Blanc; mnemonique = " "; };
	virtual ~Piece() = default;
	virtual bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier) = 0;
	bool verificationEchecDeplacement(Position nouvellePosition, Plateau& echiquier);
	bool verificationEchecPin(Position nouvellePosition, Plateau& echiquier);
	const char* getInfos() const;
	Position position;
	Couleur couleurPiece;
	const char* mnemonique;
};

// Class Tour
// Une tour est une pièce
class Tour : public Piece
{
public:
	Tour(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
	std::pair<int, int> determinerDirection(Position nouvellePosition);
};

// Class Roi
// Un roi est une pièce
class Roi : public Piece
{
public:
	Roi(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
	bool verificationEchecDeplacement(Position nouvellePosition, Plateau& echiquier);
	bool verificationEchec(Plateau& echiquier);
private:
	std::pair<int, int> deplacementsPossibles[8] = { {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}, {+1, -1}, {0, -1}, {-1, -1} };
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


class Reine : public Piece
{
public: 
	Reine(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
	std::pair<int, int> determinerDirection(Position nouvellePosition);
};


class Fou : public Piece
{
public:
	Fou(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
	std::pair<int, int> determinerDirection(Position nouvellePosition);
};

class Pion : public Piece
{
public:
	Pion(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau &echiquier);
};