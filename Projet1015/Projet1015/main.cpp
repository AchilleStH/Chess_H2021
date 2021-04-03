#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>


using namespace std;


int main()
{
	// initialisation d'une seed random
	srand(time(NULL));
	// Si on indique une position invalide, le programme throw une erreur : Position(0, 6), Position(2, -4), Position(12, 1) donnent des erreurs.

	shared_ptr<Piece> tour = make_shared<Tour>(Tour(Couleur::Noir, Position(6, 6)));
	shared_ptr<Piece> roi = make_shared<Roi>(Roi(Couleur::Blanc, Position(7, 3)));
	shared_ptr<Piece> cavalier = make_shared<Cavalier>(Cavalier(Couleur::Blanc, Position(4, 6)));

	cout << "DEBUT\n";
	Plateau echiquier;

	echiquier.plateauRandom();

	echiquier.afficher();



	echiquier.plateauRandom();
	echiquier.afficher();

	echiquier.plateauRandom();
	echiquier.afficher();

	echiquier.plateauRandom();
	echiquier.afficher();

	echiquier.plateauRandom();
	echiquier.afficher();

	echiquier.plateauRandom();
	echiquier.afficher();

	echiquier.clearPlateau();
	echiquier.afficher();



}