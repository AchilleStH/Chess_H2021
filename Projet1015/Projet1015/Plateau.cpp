#include "Plateau.h"

// Implementation de la classe Plateau
Plateau::Plateau() 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			plateau[i][j] = nullptr;
		}
	}
}
void Plateau::afficher()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << plateau[i][j]->getInfos() << " ";
			if (j == 7)
				cout << endl;
		}
	}
}


void Plateau::setPiece(shared_ptr<Piece> piece, Position pos)
{
	plateau[pos.x-1][pos.y-1] = move(piece);
}

void Plateau::deplacerPiece(Position posActuelle, Position nouvellePos)
{
	plateau[nouvellePos.x - 1][nouvellePos.y - 1] = plateau[posActuelle.x-1][posActuelle.y-1];
	plateau[posActuelle.x - 1][posActuelle.y - 1] = nullptr;
}