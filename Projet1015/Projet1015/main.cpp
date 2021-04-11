#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>

Plateau init()
{
	// On instancie un echiquier
	Plateau echiquier;

	// Pieces blanches
	for (int i = 1; i < 9; i++)
	{
		std::unique_ptr<Piece> pion = std::make_unique<Pion>(Pion(Couleur::Blanc, Position(i, 7)));
		echiquier.setPiece(pion, pion->position);
	}
	std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(Couleur::Blanc, Position(1, 8)));
	std::unique_ptr<Piece> tour1 = std::make_unique<Tour>(Tour(Couleur::Blanc, Position(8, 8)));
	std::unique_ptr<Piece> cavalier = std::make_unique<Cavalier>(Cavalier(Couleur::Blanc, Position(2, 8)));
	std::unique_ptr<Piece> cavalier1 = std::make_unique<Cavalier>(Cavalier(Couleur::Blanc, Position(7, 8)));
	std::unique_ptr<Piece> fou = std::make_unique<Fou>(Fou(Couleur::Blanc, Position(3, 8)));
	std::unique_ptr<Piece> fou1 = std::make_unique<Fou>(Fou(Couleur::Blanc, Position(6, 8)));
	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(Couleur::Blanc, Position(4, 8)));
	std::unique_ptr<Piece> reine = std::make_unique<Reine>(Reine(Couleur::Blanc, Position(5, 8)));

	echiquier.setPiece(tour, tour->position);
	echiquier.setPiece(tour1, tour1->position);
	echiquier.setPiece(cavalier, cavalier->position);
	echiquier.setPiece(cavalier1, cavalier1->position);
	echiquier.setPiece(fou, fou->position);
	echiquier.setPiece(fou1, fou1->position);
	echiquier.setPiece(roi, roi->position);
	echiquier.setPiece(reine, reine->position);

	// Pieces noires
	for (int i = 1; i < 9; i++)
	{
		std::unique_ptr<Piece> pion2 = std::make_unique<Pion>(Pion(Couleur::Noir, Position(i, 2)));
		echiquier.setPiece(pion2, pion2->position);
	}
	std::unique_ptr<Piece> tour2 = std::make_unique<Tour>(Tour(Couleur::Noir, Position(1, 1)));
	std::unique_ptr<Piece> tour3 = std::make_unique<Tour>(Tour(Couleur::Noir, Position(8, 1)));
	std::unique_ptr<Piece> cavalier2 = std::make_unique<Cavalier>(Cavalier(Couleur::Noir, Position(2, 1)));
	std::unique_ptr<Piece> cavalier3 = std::make_unique<Cavalier>(Cavalier(Couleur::Noir, Position(7, 1)));
	std::unique_ptr<Piece> fou2 = std::make_unique<Fou>(Fou(Couleur::Noir, Position(3, 1)));
	std::unique_ptr<Piece> fou3 = std::make_unique<Fou>(Fou(Couleur::Noir, Position(6, 1)));
	std::unique_ptr<Piece> roi2 = std::make_unique<Roi>(Roi(Couleur::Noir, Position(4, 1)));
	std::unique_ptr<Piece> reine2 = std::make_unique<Reine>(Reine(Couleur::Noir, Position(5, 1)));

	echiquier.setPiece(tour2, tour2->position);
	echiquier.setPiece(tour3, tour3->position);
	echiquier.setPiece(cavalier2, cavalier2->position);
	echiquier.setPiece(cavalier3, cavalier3->position);
	echiquier.setPiece(fou2, fou2->position);
	echiquier.setPiece(fou3, fou3->position);
	echiquier.setPiece(roi2, roi2->position);
	echiquier.setPiece(reine2, reine2->position);

	return echiquier;
}


int main()
{
	// Exemple d'utilisation de la logique du jeu d'échec :


	// Exemple 1 : Choix de l'emplacement des pièces 
	// On instancie un échiquier
	Plateau echiquier = init();

	echiquier.afficher();

	return 0;
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
//	// Exemple d'utilisation de la logique du jeu d'échec :
//
//
//	// Exemple 1 : Choix de l'emplacement des pièces 
//	// On instancie un échiquier
//	Plateau echiquier;
//
//	// On crée un cavalier blanc en (6, 1), une tour blanche en (1, 1) et un roi blanc en (7, 2)
//	std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(Couleur::Blanc, Position(1, 1)));
//	std::unique_ptr<Piece> cavalier = std::make_unique<Cavalier>(Cavalier(Couleur::Blanc, Position(6, 1)));
//	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(Couleur::Blanc, Position(7, 2)));
//
//	// On place les pièces crées sur l'échiquier :
//	echiquier.setPiece(tour, tour->position);
//	echiquier.setPiece(cavalier, cavalier->position);
//	echiquier.setPiece(roi, roi->position);
//	// On affiche l'échiquier :
//	std::cout << "ECHIQUIER EXEMPLE 1 : \n";
//	echiquier.afficher();
//
//	// Déplacement des pièces : 
//
//	// On déplace la tour en (1, 4)
//	echiquier.deplacerPiece(Position(1, 1), Position(1, 4));
//
//	// On déplace le cavalier en (5, 3)
//	echiquier.deplacerPiece(Position(6, 1), Position(5, 3));
//
//	// On déplace le roi en (8, 3)
//	echiquier.deplacerPiece(Position(7, 2), Position(8, 3));
//	echiquier.afficher();
//
//
//
//	// Exemple 2 : Génération d'une position aléatoire (Pions noirs et pions blancs)
//	std::cout << "ECHIQUIER RANDOM EXEMPLE 2 : \n";
//	// On génére aléatoirement un Cavalier, un Roi et une Tour blanche.
//	echiquier.plateauRandom(Couleur::Blanc);
//	// On génére aléatoirement un Cavalier, un Roi et une Tour noire.
//	echiquier.plateauRandom(Couleur::Noir);
//	echiquier.afficher();
//
//	std::cout << "ECHIQUIER VIDE : \n";
//	// On vide l'échiquier.
//	echiquier.clearPlateau(Couleur::Blanc);
//	echiquier.clearPlateau(Couleur::Noir);
//	echiquier.afficher();
//}