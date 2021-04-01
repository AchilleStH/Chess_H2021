#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


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
	};
	int x = 1;
	int y = 1;
};

// enum class Couleur
// Enumération permettant de définir la couleur d'une
// pièce. Une pièce peut être Blanche ou Noire.
enum class Couleur {Blanc, Noir, Default};

// class Piece
// Chaque pièce possède une position, une couleur,
// ainsi qu'un mnemonique (R pour roi, Q pour reine...)
// verificationDeplacement permet de vérifier la validité
// d'un déplacement. deplacement modifie la position
// de la pièce.
class Piece
{
public: 
	Piece() : position(Position(0, 0)), couleurPiece(Couleur::Default), mnemonique('x'){};
	virtual bool verificationDeplacement(Position nouvellePosition) = 0;
	virtual void deplacement(Position nouvellePosition) = 0;
	// A DES FINS DE DEBUGGAGE, A RETIRER
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
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

// Class Roi
// Un roi est une pièce
class Roi : public Piece
{
public:
	Roi(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

// Class Reine
// Une reine est une pièce
class Reine : public Piece
{
public: 
	Reine(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

// Class Cavalier
// Un cavalier est une pièce
class Cavalier : public Piece
{
public:
	Cavalier(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};


// Class Fou
// Un fou est une pièce
class Fou : public Piece
{
public:
	Fou(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};