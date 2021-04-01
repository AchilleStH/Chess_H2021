#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "Piece.h"
#include "Case.h"
#include "Plateau.h"


using namespace std;


int main()
{
	Piece* tour = new Tour(Couleur::Blanc, Position(2, 3));
	Piece* roi = new Roi(Couleur::Blanc, Position(7, 3));
	Piece* cavalier = new Cavalier(Couleur::Blanc, Position(45, 3));

	cout << "DEBUT\n";
	Plateau test;
	test.setPiece(tour, tour->position);

	test.setPiece(roi, roi->position);

	test.setPiece(cavalier, cavalier->position);


	test.afficher();
	test.finPartie();
}