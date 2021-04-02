#pragma once

#include <iostream>
#include <string>


// Permet d'utiliser Plateau avant sa d�finition
class Plateau;

// struct Position
// Structure qui permet de d�finir une position � l'aide de
// deux coordon�es x et y => x repr�sente l'index de la ligne
// et y l'index de la colonne.
struct Position
{

	// V�rifie si une position est valide. (x et y compris entre 1 et 8)
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
	int x = 1;
	int y = 1;
};

// enum class Couleur
// Enum�ration permettant de d�finir la couleur d'une
// pi�ce. Une pi�ce peut �tre Blanche ou Noire.
enum class Couleur {Blanc, Noir, Default};

// class Piece
// Chaque pi�ce poss�de une position, une couleur,
// ainsi qu'un mnemonique (R pour roi, Q pour reine...)
// verificationDeplacement permet de v�rifier la validit�
// d'un d�placement. deplacement modifie la position
// de la pi�ce.
class Piece
{
public: 
	Piece() : position(Position(1, 1)), couleurPiece(Couleur::Default), mnemonique('x'){};
	virtual bool verificationDeplacement(Position nouvellePosition, Plateau echiquier) = 0;
	// A DES FINS DE DEBUGGAGE, A RETIRER
	char getInfos() const;
	Position position;
	Couleur couleurPiece;
	char mnemonique;
};

// Class Tour
// Une tour est une pi�ce
class Tour : public Piece
{
public:
	Tour(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
};

// Class Roi
// Un roi est une pi�ce
class Roi : public Piece
{
public:
	Roi(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
private:
	std::pair<int, int> deplacementsPossibles[8] = { {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}, {+1, -1}, {0, -1}, {-1, -1} };
};

// Class Reine
// Une reine est une pi�ce
class Reine : public Piece
{
public: 
	Reine(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
};

// Class Cavalier
// Un cavalier est une pi�ce
class Cavalier : public Piece
{
public:
	Cavalier(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
private:
	std::pair<int, int> deplacementsPossibles[8] = { {-2, -1}, {-1, -2}, {+1, -2}, {-2, +1}, {-1, +2}, {+1, +2}, {+2, +1}, {+2, -1} };
};


// Class Fou
// Un fou est une pi�ce
class Fou : public Piece
{
public:
	Fou(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition, Plateau echiquier);
};