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



//class CasePlateau
//{
//public:
//	Piece getPiece() const { return piece; };
//
//	ostream& operator<<(ostream& os)
//	{
//		os << piece;
//	}
//private:
//	Piece piece;
//};
//
//class Echiquier
//{
//public: 
//	// SUPPRIMER CETTE MÉTHODE
//	Echiquier() = default;
//	void afficher()
//	{
//		for (int i = 0; i <= 8; i++)
//		{
//			for (int j = 0; j <= 8; j++)
//			{
//				cout << plateau[i][j];
//			}
//		}
//			
//	}
//private:
//	CasePlateau plateau[8][8];
//};

int main()
{
	Tour tour(Couleur::Blanc, Position(2, 3));
	Roi roi(Couleur::Blanc, Position(2, 3));
	Fou fou(Couleur::Blanc, Position(2, 3));
	Cavalier cavalier(Couleur::Blanc, Position(2, 3));
	Reine reine(Couleur::Blanc, Position(2, 3));

	cout << "DEBUT\n";
	Plateau test;
	test.setPiece(tour, Position(1, 1));
	test.setPiece(tour, Position(1, 8));
	test.setPiece(tour, Position(8, 1));
	test.setPiece(tour, Position(8, 8));

	test.setPiece(cavalier, Position(1, 2));
	test.setPiece(cavalier, Position(1, 7));
	test.setPiece(cavalier, Position(8, 2));
	test.setPiece(cavalier, Position(8, 7));

	test.setPiece(fou, Position(1, 3));
	test.setPiece(fou, Position(1, 6));
	test.setPiece(fou, Position(8, 3));
	test.setPiece(fou, Position(8, 6));

	test.setPiece(reine, Position(1, 4));
	test.setPiece(roi, Position(1, 5));

	test.setPiece(reine, Position(8, 4));
	test.setPiece(roi, Position(8, 5));

	test.afficher();
}