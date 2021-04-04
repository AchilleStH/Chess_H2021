#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>


using namespace std;


int main()
{
	// initialisation d'une seed random
	srand((unsigned)time(NULL));
	// Si on indique une position invalide, le programme throw une erreur : Position(0, 6), Position(2, -4), Position(12, 1) donnent des erreurs.

	unique_ptr<Piece> tour = make_unique<Tour>(Tour(Couleur::Noir, Position(2, 3)));
	unique_ptr<Piece> roi = make_unique<Roi>(Roi(Couleur::Blanc, Position(7, 4)));
	unique_ptr<Piece> cavalier = make_unique<Cavalier>(Cavalier(Couleur::Noir, Position(4, 6)));

	cout << "DEBUT\n";
	Plateau echiquier;

	echiquier.setPiece(roi, roi->position);
	echiquier.setPiece(tour, tour->position);
	echiquier.afficher();



	/*if (dynamic_cast<Roi*>(echiquier.getPiece(Position(2, 3)).get())->verificationEchec(echiquier))
		cout << "GEGEGEGEG";*/

	cout << "\033[31mTEST\033[0m";

}