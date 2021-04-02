#include "Plateau.h"
#include "Piece.h"

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
			std::cout << plateau[i][j]->getInfos() << " ";
			if (j == 7)
				std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}


void Plateau::setPiece(std::shared_ptr<Piece> piece, Position pos)
{
	if(plateau[pos.x - 1][pos.y - 1] == nullptr)
		plateau[pos.x-1][pos.y-1] = move(piece);
}

void Plateau::retirerPiece(Position pos)
{
	plateau[pos.x - 1][pos.y - 1] = nullptr;
}


void Plateau::deplacerPiece(Position posActuelle, Position nouvellePos)
{
	if (plateau[posActuelle.x - 1][posActuelle.y - 1]->verificationDeplacement(nouvellePos, *this))
	{
		plateau[posActuelle.x - 1][posActuelle.y - 1]->position = nouvellePos;
		plateau[nouvellePos.x - 1][nouvellePos.y - 1] = plateau[posActuelle.x - 1][posActuelle.y - 1];
		plateau[posActuelle.x - 1][posActuelle.y - 1] = nullptr;
	}
}