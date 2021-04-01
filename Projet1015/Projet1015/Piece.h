#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;



struct Position
{
	Position(int x_, int y_) : x(x_), y(y_) {};
	int x = 0;
	int y = 0;
};

enum class Couleur {Blanc, Noir, Default};



class Piece
{
public: 
	Piece() : position(Position(0, 0)), couleurPiece(Couleur::Default), mnemonique('x'){};
	bool verificationDeplacement(Position nouvellePosition) {};
	void deplacement(Position nouvellePosition) {};
	// A DES FINS DE DEBUGGAGE, A RETIRER
	char getInfos() const;

	Position position;
	Couleur couleurPiece;
	char mnemonique;
};

class Tour : public Piece
{
public:
	Tour(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

class Roi : public Piece
{
public:
	Roi(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

class Reine : public Piece
{
public: 
	Reine(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

class Cavalier : public Piece
{
public:
	Cavalier(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};

class Fou : public Piece
{
public:
	Fou(Couleur couleur, Position pos);
	bool verificationDeplacement(Position nouvellePosition);
	void deplacement(Position nouvellePosition);
};