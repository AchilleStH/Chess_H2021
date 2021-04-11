#include "Piece.h"
#include "Plateau.h"
#include <math.h>

// Implémentation de la classe Piece et de ses dérivées


// getInfos()
// Retourne la mnemonique de la pièce. Cette méthode est utilisé
// dans l'unique but d'afficher le contenu de l'échiquier, et 
// n'influe pas sur la logique du jeu d'échec.
const char * Piece::getInfos() const
{
	if (this != nullptr)
		return mnemonique;
	else
		return "#";
}

bool Piece::verificationEchecDeplacement(Position nouvellePosition, Plateau& echiquier)
{
	Position posTmp = position;

	if (echiquier.roiEnEchec(couleurPiece))
	{
		// On crée une pièce temporaire (ici une tour, mais le type de pièce n'influe pas sur la vérification)
		std::unique_ptr<Piece> tmpPiece = std::make_unique<Tour>(Tour(couleurPiece, nouvellePosition));
		if (echiquier.getPiece(nouvellePosition) != nullptr)
		{
			std::unique_ptr<Piece> sauvegardeCase = move(echiquier.getPiece(nouvellePosition));
			echiquier.retirerPiece(nouvellePosition);
			echiquier.setPiece(tmpPiece, tmpPiece->position);
			if (echiquier.roiEnEchec(couleurPiece))
			{
				echiquier.retirerPiece(nouvellePosition);
				echiquier.setPiece(sauvegardeCase, nouvellePosition);
				return false;
			}
			echiquier.retirerPiece(nouvellePosition);
			echiquier.setPiece(sauvegardeCase, nouvellePosition);
			return true;
		}
		else
		{
			echiquier.setPiece(tmpPiece, tmpPiece->position);
			if (echiquier.roiEnEchec(couleurPiece))
			{
				echiquier.retirerPiece(nouvellePosition);
				return false;
			}
			else
			{
				echiquier.retirerPiece(nouvellePosition);
				return true;
			}
		}
	}
	else
		return true;
}

bool Piece::verificationEchecPin(Position nouvellePosition, Plateau& echiquier)
{
	std::unique_ptr<Piece> sauvegardePieceActuelle = move(echiquier.getPiece(position));
	bool verificationPin = verificationEchecDeplacement(nouvellePosition, echiquier);
	echiquier.setPiece(sauvegardePieceActuelle, position);
	return verificationPin;
}

// Tour(Couleur couleur, Position pos)
// Constructeur de la classe Tour
Tour::Tour(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	switch (couleur)
	{
	case Couleur::Blanc:
		mnemonique = "\033[1m\033[31mT\033[0m";
		break;
	case Couleur::Noir:
		mnemonique = "\033[1m\033[32mT\033[0m";
		break;
	default:
		mnemonique = "#";
		break;
	}
}

// determinerDirection(Position nouvellePosition)
// Méthode de Tour permettant de déterminer la direction d'un 
// mouvement vers une position donnée.
std::pair<int, int> Tour::determinerDirection(Position nouvellePosition)
{
	int diffX = nouvellePosition.x - position.x;
	int diffY = nouvellePosition.y - position.y;

	if (diffX != 0)
		diffX /= abs(diffX);

	if (diffY != 0)
		diffY /= abs(diffY);

	return { diffX, diffY };
}

// verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
// Méthode de Tour permettant de déterminer si un déplacement vers
// une position donnée est possible (Sans prendre en compte les échecs)
bool Tour::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool caseDisponible = true;
	bool deplacementValide = true;
	Position posTmp = position;

	std::pair<int, int> direction = determinerDirection(nouvellePosition);

	if (!(direction.first && direction.second) && (direction.first != 0 || direction.second != 0))
	{
		while (true)
		{
			if (posTmp.x == nouvellePosition.x && posTmp.y == nouvellePosition.y)
				break;
			else
			{
				posTmp.x += direction.first;
				posTmp.y += direction.second;
			}
			// verification : une pièce est en chemin (et si il y a une pièce de la couleur
			// opposée sur la case finale, on mange la pièce)
			if ((echiquier.getPiece(posTmp) != nullptr))
				if (posTmp.x != nouvellePosition.x || posTmp.y != nouvellePosition.y)
					return false;
				else if (echiquier.getPiece(nouvellePosition) != nullptr && \
					echiquier.getPiece(nouvellePosition)->couleurPiece != couleurPiece)
					caseDisponible = true;
				else
					caseDisponible = false;
		}
	}
	else
		deplacementValide = false;
	return (deplacementValide && caseDisponible);
}


// Roi(Couleur couleur, Position pos)
// Constructeur de la classe Roi
Roi::Roi(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	switch (couleur)
	{
	case Couleur::Blanc:
		mnemonique = "\033[1m\033[31mR\033[0m";
		break;
	case Couleur::Noir:
		mnemonique = "\033[1m\033[32mR\033[0m";
		break;
	default:
		mnemonique = "#";
		break;
	}
}


// verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
// Méthode de Roi permettant de déterminer si un déplacement vers
// une position donnée est possible (Sans prendre en compte les échecs)
bool Roi::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool deplacementValide = false;
	bool caseDisponible = true;
	// verification : nouvelle position est valide (mouvement du roi)
	for (std::pair<int, int> pairPos : deplacementsPossibles)
	{
		if ((pairPos.first + position.x) == nouvellePosition.x && ((pairPos.second + position.y) == nouvellePosition.y))
		{
			deplacementValide = true;
			break;
		}
	}
	// verification : cases possibles ne sont pas occupées par une pièce de la même couleur
	if ((echiquier.getPiece(nouvellePosition) != nullptr) && (echiquier.getPiece(nouvellePosition)->couleurPiece == couleurPiece))
		caseDisponible = false;

	return (deplacementValide && caseDisponible); 
}


bool Roi::verificationEchec(Plateau& echiquier)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Position posActuelle = Position(i + 1, j + 1);
			if (echiquier.getPiece(posActuelle) != nullptr && echiquier.getPiece(posActuelle)->couleurPiece != couleurPiece)
			{
				if (echiquier.getPiece(posActuelle)->verificationDeplacement(position, echiquier))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Roi::verificationEchecDeplacement(Position nouvellePosition, Plateau& echiquier)
{
	Position posTmp = position;
	std::unique_ptr<Piece> tmpRoi = std::make_unique<Roi>(Roi(couleurPiece, nouvellePosition));
		std::unique_ptr<Piece> sauvegardeRoi = std::move(echiquier.getPiece(position));
		if (echiquier.getPiece(nouvellePosition) != nullptr)
		{
			std::unique_ptr<Piece> sauvegardeCase = move(echiquier.getPiece(nouvellePosition));
			echiquier.retirerPiece(nouvellePosition);
			echiquier.setPiece(tmpRoi, tmpRoi->position);
			if (echiquier.roiEnEchec(couleurPiece))
			{
				echiquier.retirerPiece(nouvellePosition);
				echiquier.setPiece(sauvegardeCase, nouvellePosition);
				echiquier.setPiece(sauvegardeRoi, position);
				return false;
			}
			echiquier.retirerPiece(nouvellePosition);
			echiquier.setPiece(sauvegardeCase, nouvellePosition);
			echiquier.setPiece(sauvegardeRoi, position);
			return true;
		}
		else
		{
			echiquier.setPiece(tmpRoi, tmpRoi->position);
			if (echiquier.roiEnEchec(couleurPiece))
			{
				echiquier.retirerPiece(nouvellePosition);
				echiquier.setPiece(sauvegardeRoi, position);
				return false;
			}
			else
			{
				echiquier.retirerPiece(nouvellePosition);
				echiquier.setPiece(sauvegardeRoi, position);
				return true;
			}
		}
}


// Cavalier(Couleur couleur, Position pos)
// Constructeur de la classe Cavalier
Cavalier::Cavalier(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	switch (couleur)
	{
	case Couleur::Blanc:
		mnemonique = "\033[1m\033[31mC\033[0m";
		break;
	case Couleur::Noir:
		mnemonique = "\033[1m\033[32mC\033[0m";
		break;
	default:
		mnemonique = "#";
		break;
	}
}

// verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
// Méthode de Cavalier permettant de déterminer si un déplacement vers
// une position donnée est possible (Sans prendre en compte les échecs)
bool Cavalier::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool deplacementValide = false;
	bool caseDisponible = true;
	// verification : nouvelle position est valide (mouvement du cavalier)
	for (std::pair<int, int> pairPos : deplacementsPossibles)
	{
		if ((pairPos.first + position.x) == nouvellePosition.x && ((pairPos.second + position.y) == nouvellePosition.y))
			deplacementValide = true;
	}

	// verification : cases possibles ne sont pas occupées par une pièce de la même couleur
	if ((echiquier.getPiece(nouvellePosition) != nullptr) && (echiquier.getPiece(nouvellePosition)->couleurPiece == couleurPiece))
		caseDisponible = false;

	return (deplacementValide && caseDisponible);
}

// Reine(Couleur couleur, Position pos)
// Constructeur de la classe Reine
Reine::Reine(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	switch (couleur)
	{
	case Couleur::Blanc:
		mnemonique = "\033[1m\033[31mQ\033[0m";
		break;
	case Couleur::Noir:
		mnemonique = "\033[1m\033[32mQ\033[0m";
		break;
	default:
		mnemonique = "#";
		break;
	}
}

// determinerDirection(Position nouvellePosition)
// Méthode de Reine permettant de déterminer la direction d'un 
// mouvement vers une position donnée.
std::pair<int, int> Reine::determinerDirection(Position nouvellePosition)
{
	int diffX = nouvellePosition.x - position.x;
	int diffY = nouvellePosition.y - position.y;

	if (diffX != 0)
		diffX /= abs(diffX);

	if (diffY != 0)
		diffY /= abs(diffY);

	return { diffX, diffY };
}

// verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
// Méthode de Reine permettant de déterminer si un déplacement vers
// une position donnée est possible (Sans prendre en compte les échecs)
bool Reine::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool caseDisponible = true;
	bool deplacementValide = true;
	Position posTmp = position;

	std::pair<int, int> direction = determinerDirection(nouvellePosition);

	if ((!(direction.first && direction.second) && (direction.first != 0 || direction.second != 0)) || (direction.first != 0 && direction.second != 0))
	{
		while (true)
		{
			if (posTmp.x == nouvellePosition.x && posTmp.y == nouvellePosition.y)
				break;
			else
			{
				posTmp.x += direction.first;
				posTmp.y += direction.second;
			}
			// verification : une pièce est en chemin (et si il y a une pièce de la couleur
			// opposée sur la case finale, on mange la pièce)
			if ((echiquier.getPiece(posTmp) != nullptr))
				if (posTmp.x != nouvellePosition.x || posTmp.y != nouvellePosition.y)
					return false;
				else if (echiquier.getPiece(nouvellePosition) != nullptr && \
					echiquier.getPiece(nouvellePosition)->couleurPiece != couleurPiece)
					caseDisponible = true;
				else
					caseDisponible = false;
		}
	}
	else
		deplacementValide = false;
	return (deplacementValide && caseDisponible);
}

// Fou(Couleur couleur, Position pos)
// Constructeur de la classe Fou
Fou::Fou(Couleur couleur, Position pos)
{
couleurPiece = couleur;
position = pos;
switch (couleur)
{
case Couleur::Blanc:
	mnemonique = "\033[1m\033[31mF\033[0m";
	break;
case Couleur::Noir:
	mnemonique = "\033[1m\033[32mF\033[0m";
	break;
default:
	mnemonique = "#";
	break;
}
}

// determinerDirection(Position nouvellePosition)
// Méthode de Fou permettant de déterminer la direction d'un 
// mouvement vers une position donnée.
std::pair<int, int> Fou::determinerDirection(Position nouvellePosition)
{
	int diffX = nouvellePosition.x - position.x;
	int diffY = nouvellePosition.y - position.y;

	if (diffX != 0)
		diffX /= abs(diffX);

	if (diffY != 0)
		diffY /= abs(diffY);

	return { diffX, diffY };
}

// verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
// Méthode de Fou permettant de déterminer si un déplacement vers
// une position donnée est possible (Sans prendre en compte les échecs)
bool Fou::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool caseDisponible = true;
	bool deplacementValide = true;
	Position posTmp = position;

	std::pair<int, int> direction = determinerDirection(nouvellePosition);

	if (direction.first != 0 && direction.second != 0)
	{
		while (true)
		{
			if (posTmp.x == nouvellePosition.x && posTmp.y == nouvellePosition.y)
				break;
			else
			{
				posTmp.x += direction.first;
				posTmp.y += direction.second;
			}
			// verification : une pièce est en chemin (et si il y a une pièce de la couleur
			// opposée sur la case finale, on mange la pièce)
			if ((echiquier.getPiece(posTmp) != nullptr))
				if (posTmp.x != nouvellePosition.x || posTmp.y != nouvellePosition.y)
					return false;
				else if (echiquier.getPiece(nouvellePosition) != nullptr && \
					echiquier.getPiece(nouvellePosition)->couleurPiece != couleurPiece)
					caseDisponible = true;
				else
					caseDisponible = false;
		}
	}
	else
		deplacementValide = false;
	return (deplacementValide && caseDisponible);
}

// Pion(Couleur couleur, Position pos)
// Constructeur de la classe Pion
Pion::Pion(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	switch (couleur)
	{
	case Couleur::Blanc:
		mnemonique = "\033[1m\033[31mP\033[0m";
		break;
	case Couleur::Noir:
		mnemonique = "\033[1m\033[32mP\033[0m";
		break;
	default:
		mnemonique = "#";
		break;
	}
}

bool Pion::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool caseDisponible = false;
	bool deplacementValide = false;
	bool diagonale = false;
	bool saut = false;
	int direction = 0;
	Position posTmp = position;

	switch (couleurPiece)
	{
	case Couleur::Noir:
		if (posTmp.y + 1 == nouvellePosition.y && posTmp.x == nouvellePosition.x)
			deplacementValide = true;
		else if (posTmp.y + 2 == nouvellePosition.y && posTmp.y == 2)
		{
			deplacementValide = true;
			saut = true;
			direction = 1;
		}
		else if (posTmp.y + 1 == nouvellePosition.y && posTmp.x + 1 == nouvellePosition.x)
		{
			deplacementValide = true;
			diagonale = true;
		}
		else if (posTmp.y + 1 == nouvellePosition.y && posTmp.x - 1 == nouvellePosition.x)
		{
			deplacementValide = true;
			diagonale = true;
		}
		break;
	case Couleur::Blanc:
		if (posTmp.y - 1 == nouvellePosition.y && posTmp.x == nouvellePosition.x)
			deplacementValide = true;
		else if (posTmp.y - 2 == nouvellePosition.y && posTmp.y == 7)
		{
			deplacementValide = true;
			saut = true;
			direction = -1;
		}
		else if (posTmp.y - 1 == nouvellePosition.y && posTmp.x + 1 == nouvellePosition.x)
		{
			deplacementValide = true;
			diagonale = true;
		}
		else if (posTmp.y - 1 == nouvellePosition.y && posTmp.x - 1 == nouvellePosition.x)
		{
			deplacementValide = true;
			diagonale = true;
		}
		break;
	}
		
	if (saut)
	{	
		if (echiquier.getPiece({ posTmp.x, posTmp.y + direction }) == nullptr && echiquier.getPiece(nouvellePosition) == nullptr)
			caseDisponible = true;
	}
	else if (diagonale)
	{
		if (echiquier.getPiece(nouvellePosition) != nullptr && \
			echiquier.getPiece(nouvellePosition)->couleurPiece != couleurPiece)
			caseDisponible = true;
	}
	else
	{
		if (echiquier.getPiece(nouvellePosition) == nullptr)
			caseDisponible = true;
	}

return (deplacementValide && caseDisponible);


}