#include "Plateau.h"
#include "Piece.h"
#include<cstdlib>
// Implementation de la classe Plateau
Plateau::Plateau() 
{
	// Initialisation d'une seed aléatoire (pour rand())
	srand((unsigned)time(0));
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
			std::cout << plateau[j][i]->getInfos() << " ";
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
	// ICI VÉRIFIER QUE LA PIECE EST PAS NULLPTR
	if (plateau[posActuelle.x - 1][posActuelle.y - 1] != nullptr && \
		plateau[posActuelle.x - 1][posActuelle.y - 1]->verificationDeplacement(nouvellePos, *this))
	{
		plateau[posActuelle.x - 1][posActuelle.y - 1]->position = nouvellePos;
		plateau[nouvellePos.x - 1][nouvellePos.y - 1] = plateau[posActuelle.x - 1][posActuelle.y - 1];
		plateau[posActuelle.x - 1][posActuelle.y - 1] = nullptr;
	}
}

void Plateau::clearPlateau()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			plateau[i][j] = nullptr;
		}
	}
}

void Plateau::plateauRandom()
{
	clearPlateau();
	Position randomPos = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
	setPiece(std::make_shared<Cavalier>(Cavalier(Couleur::Blanc, randomPos)), randomPos);
	randomPos = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
	setPiece(std::make_shared<Tour>(Tour(Couleur::Blanc, randomPos)), randomPos);
	randomPos = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
	setPiece(std::make_shared<Roi>(Roi(Couleur::Blanc, randomPos)), randomPos);
}