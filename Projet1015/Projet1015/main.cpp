#include "Piece.h"
#include "Plateau.h"

#include <iostream>
#include <string>


using namespace std;


int main()
{

	// BUG A CORRIGER : QUAND ON INITIALISE UNE PIECE AVEC UNE POSITION INVALIDE CA LE MET A 1:1 ET DONC IL PEUT SE DÉPLACER GENRE EN 1:2 SI C'EST UN ROI ALORS QUE FAUDRAIT PAS

	shared_ptr<Piece> tour = make_shared<Tour>(Tour(Couleur::Blanc, Position(2, 3)));
	shared_ptr<Piece> roi = make_shared<Roi>(Roi(Couleur::Blanc, Position(7, 3)));
	shared_ptr<Piece> cavalier = make_shared<Cavalier>(Cavalier(Couleur::Blanc, Position(7, 8)));
	cout << "DEBUT\n";
	Plateau echiquier;
	echiquier.setPiece(cavalier, cavalier->position);
	echiquier.setPiece(roi, roi->position);
	echiquier.setPiece(tour, tour->position);

	echiquier.afficher();

	echiquier.deplacerPiece(roi->position, Position(1, 2));

	echiquier.deplacerPiece(tour->position, Position(8, 3));

	echiquier.deplacerPiece(cavalier->position, Position(8, 8));

	echiquier.retirerPiece(cavalier->position);

	echiquier.afficher();
}