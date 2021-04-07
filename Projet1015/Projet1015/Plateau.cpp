#include "Plateau.h"
#include "Piece.h"
#include<cstdlib>

// Implémentation de la classe Plateau

// Plateau() 
// Constructeur de la classe Plateau
Plateau::Plateau() 
{
	// Initialisation d'une seed aléatoire (pour rand())
	srand((unsigned)time(0));

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			plateau[i][j] = nullptr;
}

// afficher()
// Permet d'afficher l'état actuel de l'échiquier.
// Cette méthode n'influe pas sur la logique du
// jeu et est principallement utilisée a des fins
// de débugage.
void Plateau::afficher()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if((i + j) % 2)
				std::cout << "\033[1m\033[30m" << plateau[j][i]->getInfos() << "\033[0m" << " ";
			else
				std::cout << plateau[j][i]->getInfos() << " ";
			if (j == 7)
				std::cout << std::endl;
		}
	std::cout << std::endl;
}


// setPiece(std::unique_ptr<Piece>& piece, Position pos)
// Méthode permettant d'ajouter une pièce sur 
// une case vide du plateau.
void Plateau::setPiece(std::unique_ptr<Piece>& piece, Position pos)
{
	if(plateau[pos.x - 1][pos.y - 1] == nullptr)
		plateau[pos.x-1][pos.y-1] = std::move(piece);
}


// retirerPiece(Position pos)
// Permet de retirer une pièce du plateau
void Plateau::retirerPiece(Position pos)
{
	plateau[pos.x - 1][pos.y - 1] = nullptr;
}

// deplacerPiece(Position posActuelle, Position nouvellePos)
// Si le mouvement indiqué en paramètre est valide,
// cette méthode déplace la pièce sur la case voulue.
void Plateau::deplacerPiece(Position posActuelle, Position nouvellePos)
{
	if (dynamic_cast<Roi*>(getPiece(posActuelle).get()) == nullptr)
	{
		if (plateau[posActuelle.x - 1][posActuelle.y - 1] != nullptr && \
			plateau[posActuelle.x - 1][posActuelle.y - 1]->verificationDeplacement(nouvellePos, *this) && \
			plateau[posActuelle.x - 1][posActuelle.y - 1]->verificationEchecDeplacement(nouvellePos, *this) && \
			plateau[posActuelle.x - 1][posActuelle.y - 1]->verificationEchecPin(nouvellePos, *this))
		{
			plateau[nouvellePos.x - 1][nouvellePos.y - 1] = std::move(getPiece(posActuelle));
			getPiece(nouvellePos)->position = nouvellePos;
		}
	}
	else
		if (dynamic_cast<Roi*>(getPiece(posActuelle).get())->verificationEchecDeplacement(nouvellePos, *this) && \
			getPiece(posActuelle)->verificationDeplacement(nouvellePos, *this) && \
			getPiece(posActuelle)->verificationEchecPin(nouvellePos, *this))
		{
			plateau[nouvellePos.x - 1][nouvellePos.y - 1] = std::move(getPiece(posActuelle));
			getPiece(nouvellePos)->position = nouvellePos;
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

// clearPlateau(Couleur couleur)
// Permet de retirer du plateau toutes les pièces
// d'une certaine couleur
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

// setRandomPiece(std::unique_ptr<Piece>& piece)
// Permet de placer aléatoirement sur le Plateau
// la pièce indiquée en paramètre.
void Plateau::setRandomPiece(std::unique_ptr<Piece>& piece)
{
	while (true)
	{
		Position randomPos = Position(((rand() % 8) + 1), ((rand() % 8) + 1));
		if (plateau[randomPos.x - 1][randomPos.y - 1] == nullptr)
		{
			piece->position = randomPos;
			setPiece(piece, randomPos);
			break;
		}
	}
}

// plateauRandom(Couleur couleur)
// Méthode permettant de placer aléatoirement un roi,
// un cavalier et une tour de couleur choisie, en 
// enlevant les pièces de cette dernière déjà présentes.
void Plateau::plateauRandom(Couleur couleur)
{
	clearPlateau(couleur);
	std::unique_ptr<Piece> tour = std::make_unique<Tour>(Tour(couleur, Position()));
	std::unique_ptr<Piece> cavalier = std::make_unique<Cavalier>(Cavalier(couleur, Position()));
	std::unique_ptr<Piece> roi = std::make_unique<Roi>(Roi(couleur, Position()));
	setRandomPiece(tour);
	setRandomPiece(cavalier);
	setRandomPiece(roi);
}
