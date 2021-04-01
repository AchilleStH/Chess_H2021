#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "Piece.h"
#include "Plateau.h"


using namespace std;


int main()
{
	shared_ptr<Piece> tour = make_shared<Tour>(Tour(Couleur::Blanc, Position(2, 3)));
	shared_ptr<Piece> roi = make_shared<Roi>(Roi(Couleur::Blanc, Position(7, 3)));
	shared_ptr<Piece> cavalier = make_shared<Cavalier>(Cavalier(Couleur::Blanc, Position(5, 3)));
	cout << "DEBUT\n";
	Plateau echiquier;
	echiquier.setPiece(tour, tour->position);

	echiquier.setPiece(roi, roi->position);

	echiquier.setPiece(cavalier, cavalier->position);

	echiquier.deplacerPiece(tour->position, Position(1, 1));

	echiquier.afficher();
}