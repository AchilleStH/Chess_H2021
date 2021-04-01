#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>


using namespace std;


int main()
{
	shared_ptr<Piece> tour = make_shared<Tour>(Tour(Couleur::Blanc, Position(2, 3)));
	shared_ptr<Piece> roi = make_shared<Roi>(Roi(Couleur::Blanc, Position(7, 3)));
	shared_ptr<Piece> cavalier = make_shared<Cavalier>(Cavalier(Couleur::Blanc, Position(5, 3)));
	cout << "DEBUT\n";
	Plateau echiquier;
	echiquier.setPiece(cavalier, cavalier->position);

	echiquier.afficher();

	echiquier.deplacerPiece(cavalier->position, Position(7, 5));

	echiquier.afficher();
}