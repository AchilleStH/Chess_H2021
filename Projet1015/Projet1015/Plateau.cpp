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


void Plateau::setPiece(Piece* piece, Position pos)
{
	plateau[pos.x-1][pos.y-1] = piece;
}

void Plateau::finPartie() 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete plateau[i][j];
		}
	}
}