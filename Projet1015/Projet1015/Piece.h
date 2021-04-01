#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


// struct Position
// Structure qui permet de d�finir une position � l'aide de
// deux coordon�es x et y => x repr�sente l'index de la ligne
// et y l'index de la colonne.
struct Position
{
	Position(int x_, int y_) : x(x_), y(y_) {};
	// V�rifie si une position est valide. (x et y compris entre 1 et 8)
	bool verificationPosition() { return (x <= 8 && x >= 1 && y <= 8 && y >= 1); }
	int x = 0;
	int y = 0;
};

// enum class Couleur
// Enum�ration permettant de d�finir la couleur d'une
// pi�ce. Une pi�ce peut �tre Blanche ou Noire, le type
// "Default" repr�sente la 'couleur' d'une case vide
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
	Piece() : position(Position(0, 0)), couleurPiece(Couleur::Default), mnemonique('x'){};
	virtual bool verificationDeplacement(Position nouvellePosition) { return false; };
	void deplacement(Position nouvellePosition) {};
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
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

// Class Roi
// Un roi est une pi�ce
class Roi : public Piece
{
public:
	Roi(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

// Class Reine
// Une reine est une pi�ce
class Reine : public Piece
{
public: 
	Reine(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

// Class Cavalier
// Un cavalier est une pi�ce
class Cavalier : public Piece
{
public:
	Cavalier(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};


// Class Fou
// Un fou est une pi�ce
class Fou : public Piece
{
public:
	Fou(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};