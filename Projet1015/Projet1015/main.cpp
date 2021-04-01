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
	unique_ptr<Piece> tour = make_unique<Tour>(Tour(Couleur::Blanc, Position(2, 3)));
	unique_ptr<Piece> roi = make_unique<Roi>(Roi(Couleur::Blanc, Position(2, 3)));
	unique_ptr<Piece> cavalier = make_unique<Cavalier>(Cavalier(Couleur::Blanc, Position(2, 3)));


	cout << "DEBUT\n";
	Plateau test;
	test.setPiece(tour, tour.get()->position);

	test.setPiece(roi, roi.get()->position);

	test.setPiece(cavalier, cavalier.get()->position);





	test.afficher();
}