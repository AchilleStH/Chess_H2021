#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>


int main()
{
	// Exemple d'utilisation de la logique du jeu d'�chec :


	// Exemple 1 : Choix de l'emplacement des pi�ces 
	// On instancie un �chiquier
	Plateau echiquier;

	// On cr�e un cavalier blanc en (6, 1), une tour blanche en (1, 1) et un roi blanc en (7, 2)
	std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(Couleur::Noir, Position(1, 8)));
	std::unique_ptr<Piece> tour2 = std::make_unique<Tour>(Tour(Couleur::Blanc, Position(2, 1)));
	std::unique_ptr<Piece> caval = std::make_unique<Cavalier>(Cavalier(Couleur::Noir, Position(1, 4)));
	std::unique_ptr<Piece> caval2 = std::make_unique<Cavalier>(Cavalier(Couleur::Blanc, Position(6, 8)));
	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(Couleur::Noir, Position(3, 1)));
	std::unique_ptr<Piece> roi2 = std::make_unique<Roi>(Roi(Couleur::Blanc, Position(1, 1)));

	// On place les pi�ces cr�es sur l'�chiquier :
	echiquier.setPiece(roi, roi->position);
	echiquier.setPiece(tour2, tour2->position);
	//echiquier.setPiece(caval, caval->position);
	//echiquier.setPiece(caval2, caval2->position);
	//echiquier.setPiece(roi, roi->position);
	echiquier.setPiece(roi2, roi2->position);
	//echiquier.plateauRandom(Couleur::Blanc);
	//echiquier.plateauRandom(Couleur::Noir);
	echiquier.afficher();

	echiquier.deplacerPiece(Position(1, 1), Position(2, 1));

	echiquier.afficher();
	std::cout << echiquier.roiEnEchec(Couleur::Blanc) << std::endl;
	std::cout << echiquier.roiEnEchec(Couleur::Noir) << std::endl;
}

//#include "Piece.h"
//#include "Plateau.h"
//#include "../gtest/gtest.h"
//
//#include <iostream>
//#include <string>
//
//
//int main()
//{
//	// Exemple d'utilisation de la logique du jeu d'�chec :
//
//
//	// Exemple 1 : Choix de l'emplacement des pi�ces 
//	// On instancie un �chiquier
//	Plateau echiquier;
//
//	// On cr�e un cavalier blanc en (6, 1), une tour blanche en (1, 1) et un roi blanc en (7, 2)
//	std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(Couleur::Blanc, Position(1, 1)));
//	std::unique_ptr<Piece> cavalier = std::make_unique<Cavalier>(Cavalier(Couleur::Blanc, Position(6, 1)));
//	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(Couleur::Blanc, Position(7, 2)));
//
//	// On place les pi�ces cr�es sur l'�chiquier :
//	echiquier.setPiece(tour, tour->position);
//	echiquier.setPiece(cavalier, cavalier->position);
//	echiquier.setPiece(roi, roi->position);
//	// On affiche l'�chiquier :
//	std::cout << "ECHIQUIER EXEMPLE 1 : \n";
//	echiquier.afficher();
//
//	// D�placement des pi�ces : 
//
//	// On d�place la tour en (1, 4)
//	echiquier.deplacerPiece(Position(1, 1), Position(1, 4));
//
//	// On d�place le cavalier en (5, 3)
//	echiquier.deplacerPiece(Position(6, 1), Position(5, 3));
//
//	// On d�place le roi en (8, 3)
//	echiquier.deplacerPiece(Position(7, 2), Position(8, 3));
//	echiquier.afficher();
//
//
//
//	// Exemple 2 : G�n�ration d'une position al�atoire (Pions noirs et pions blancs)
//	std::cout << "ECHIQUIER RANDOM EXEMPLE 2 : \n";
//	// On g�n�re al�atoirement un Cavalier, un Roi et une Tour blanche.
//	echiquier.plateauRandom(Couleur::Blanc);
//	// On g�n�re al�atoirement un Cavalier, un Roi et une Tour noire.
//	echiquier.plateauRandom(Couleur::Noir);
//	echiquier.afficher();
//
//	std::cout << "ECHIQUIER VIDE : \n";
//	// On vide l'�chiquier.
//	echiquier.clearPlateau(Couleur::Blanc);
//	echiquier.clearPlateau(Couleur::Noir);
//	echiquier.afficher();
//}