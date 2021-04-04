#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>


using namespace std;


int main()
{
	// Si on indique une position invalide, le programme throw une erreur : Position(0, 6), Position(2, -4), Position(12, 1) donnent des erreurs.



	// FAUT JUSTE FAIRE LES PINS ET FINITO LA PARTI ECHEC AHAHA JSUIS TRO CONTEN

	std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(Couleur::Noir, Position(1, 5)));
	std::unique_ptr<Piece> tour2 = std::make_unique<Tour>(Tour(Couleur::Noir, Position(2, 2)));
	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(Couleur::Blanc, Position(8, 1)));
	std::unique_ptr<Piece> tour3 = std::make_unique<Tour>(Tour(Couleur::Blanc, Position(7, 1)));
	cout << "DEBUT\n";
	Plateau echiquier;

	echiquier.setPiece(tour, tour->position);
	echiquier.setPiece(tour2, tour2->position);
	echiquier.setPiece(tour3, tour3->position);
    echiquier.setPiece(roi, roi->position);
	echiquier.afficher();

	cout << "Blanc : " << echiquier.roiEnEchec(Couleur::Blanc);
	cout << "\n\nNoir : " << echiquier.roiEnEchec(Couleur::Noir) << "\n\n";

	echiquier.deplacerPiece(Position(2, 2), Position(2, 1));
	echiquier.afficher();

	cout << "Blanc : " << echiquier.roiEnEchec(Couleur::Blanc);
	cout << "\n\nNoir : " << echiquier.roiEnEchec(Couleur::Noir) << "\n\n";

	echiquier.deplacerPiece(Position(7, 1), Position(7, 2));
	echiquier.afficher();

	cout << "Blanc : " << echiquier.roiEnEchec(Couleur::Blanc);
	cout << "\n\nNoir : " << echiquier.roiEnEchec(Couleur::Noir) << "\n\n";
}