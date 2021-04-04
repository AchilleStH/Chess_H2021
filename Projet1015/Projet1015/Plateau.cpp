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
			if((i + j) % 2)
				std::cout << "\033[1m\033[30m" << plateau[j][i]->getInfos() << "\033[0m" << " ";
			else
				std::cout << plateau[j][i]->getInfos() << " ";
			if (j == 7)
				std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}


void Plateau::setPiece(std::unique_ptr<Piece>& piece, Position pos)
{
	if(plateau[pos.x - 1][pos.y - 1] == nullptr)
		plateau[pos.x-1][pos.y-1] = std::move(piece);
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
		plateau[nouvellePos.x - 1][nouvellePos.y - 1] = std::move(getPiece(posActuelle));
		getPiece(nouvellePos)->position = nouvellePos;
	}
}

void Plateau::clearPlateau(Couleur couleur)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(plateau[i][j] != nullptr && plateau[i][j]->couleurPiece == couleur)
				plateau[i][j] = nullptr;
		}
	}
}

void Plateau::plateauRandom(Couleur couleur)
{
	clearPlateau(couleur);
	Position randomPosRoi = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(couleur, randomPosRoi));
	setPiece(roi, randomPosRoi);

	// On s'assure que la case sur laquelle on ajoute un pièce n'est pas déja occupée 
	while (true)
	{
		Position randomPosCaval = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
		if (plateau[randomPosCaval.x - 1][randomPosCaval.y - 1] == nullptr)
		{
			std::unique_ptr<Piece> cavalier = std::make_unique<Cavalier>(Cavalier(couleur, randomPosCaval));
			setPiece(cavalier, randomPosCaval);
			break;
		}
	}

	// On s'assure que la case sur laquelle on ajoute un pièce n'est pas déja occupée 
	while (true)
	{
		Position randomPosTour = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
		if (plateau[randomPosTour.x - 1][randomPosTour.y - 1] == nullptr)
		{
			std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(couleur, randomPosTour));
			setPiece(tour, randomPosTour);
			break;
		}
	}
}


bool Plateau::roiEnEchec(Couleur couleur)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (couleur)
			{
			case Couleur::Blanc:
				if (dynamic_cast<Roi*>(plateau[i][j].get()) != nullptr &&
					plateau[i][j]->couleurPiece == Couleur::Blanc)
					return dynamic_cast<Roi*>(plateau[i][j].get())->verificationEchec(*this);
				break;

			case Couleur::Noir:
				if (dynamic_cast<Roi*>(plateau[i][j].get()) != nullptr &&
					plateau[i][j]->couleurPiece == Couleur::Noir)
					return dynamic_cast<Roi*>(plateau[i][j].get())->verificationEchec(*this);
				break;

			default:
				break;
			}
		}
	}
	return false;
}

// Beta testing
//bool Plateau::checkMate(Couleur couleur)
//{
//	bool checkmate = true;
//	if (!roiEnEchec(couleur))
//		checkmate = false;
//	else
//	{
//		for (int i = 0; i < 8; i++)
//			for (int j = 0; j < 8; j++)
//				for (int k = 0; k < 8; k++)
//					for (int u = 0; u < 8; u++)
//						if (plateau[i][j] != nullptr && plateau[i][j]->couleurPiece == couleur)
//							if (plateau[i][j]->verificationDeplacement(Position(k + 1, u + 1), *this))
//								checkmate = false;
//	}
//	return checkmate;
//}