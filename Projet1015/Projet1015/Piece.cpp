#include "Piece.h"
#include "Plateau.h"
#include <math.h>

// Implementation de la classe Piece et de ses dérivées



char Piece::getInfos() const
{
	if (this != nullptr)
		return mnemonique;
	else
		return 'x';
}



Tour::Tour(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'T';
}

bool Tour::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool caseDisponible = true;
	bool deplacementValide = true;
	Position posTmp = position;

	std::pair<int, int> direction = { 0, 0 };

	// trouver dans quel sens on va 
	if ((position.x == nouvellePosition.x) && (position.y > nouvellePosition.y))
		direction = { 0, -1 };
	else if ((position.x == nouvellePosition.x) && (position.y < nouvellePosition.y))
		direction = { 0, +1 };
	else if ((position.y == nouvellePosition.y) && (position.x > nouvellePosition.x))
		direction = { -1, 0 };
	else if ((position.y == nouvellePosition.y) && (position.x < nouvellePosition.x))
		direction = { +1, 0 };
	else
		deplacementValide = false;

	while (deplacementValide)
	{
		if (posTmp.x == nouvellePosition.x && posTmp.y == nouvellePosition.y)
			break;
		else
		{
			posTmp.x += direction.first;
			posTmp.y += direction.second;
		}
		// On vérifie si une pièce est en chemin (en si il y a une pièce de la couleur
		// opposée sur la case finale, on mange la pièce)
		if (posTmp.x <= 8 && posTmp.x >= 1 && posTmp.y <= 8 && posTmp.y >= 1)
		{
			if ((echiquier.getPiece(posTmp) != nullptr))
			{
				if (posTmp.x != nouvellePosition.x && posTmp.y != nouvellePosition.y)
				{
					caseDisponible = false;
					return (deplacementValide && caseDisponible);
				}
				else if (echiquier.getPiece(nouvellePosition) != nullptr && \
					echiquier.getPiece(nouvellePosition)->couleurPiece != couleurPiece)
					caseDisponible = true;
				else
				{
					caseDisponible = false;
					return (deplacementValide && caseDisponible);
				}

			}
		}
		else
			break;
	}
	return (deplacementValide && caseDisponible);
}




Roi::Roi(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'R';
}

bool Roi::verificationDeplacement(Position nouvellePosition, Plateau &echiquier)
{
	bool deplacementValide = false;
	bool caseDisponible = true;
	// verification : nouvelle position est valide (mouvement du roi)
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


bool Roi::verificationEchec(Plateau &echiquier)
{
	estEnEchec = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Position posActuelle = Position(i + 1, j + 1);
			if (echiquier.getPiece(posActuelle) != nullptr && echiquier.getPiece(posActuelle)->couleurPiece != couleurPiece)
			{
				if (echiquier.getPiece(posActuelle)->verificationDeplacement(position, echiquier))
					estEnEchec = true;
			}
		}
	}
	return estEnEchec;
}

// Pièce non implémentée
//Reine::Reine(Couleur couleur, Position pos)
//{
//	couleurPiece = couleur;
//	position = pos;
//	mnemonique = 'Q';
//}
//
//bool Reine::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
//{
//	// Pour l'instant, je met toujours le déplacement a true
//	return true;
//}





Cavalier::Cavalier(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'C';
}

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




// Pièce non implémentée
//Fou::Fou(Couleur couleur, Position pos)
//{
//	couleurPiece = couleur;
//	position = pos;
//	mnemonique = 'F';
//}
//
//bool Fou::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
//{
//	bool deplacementLegal = false;
//	bool caseDisponible = true;
//	bool deplacementValide = true;
//	Position posTmp = position;
//
//	std::pair<int, int> direction = { 0, 0 };
//
//	// Verification si la case est légale ( | x2 - x1 | = | y2 -y1 | > 0)
//	int offsetX = abs(nouvellePosition.x - position.x);
//	int offsetY = abs(nouvellePosition.y - position.y);
//	if (offsetX == offsetY && offsetX > 0)
//		deplacementLegal = true;
//
//
//	if (deplacementLegal)
//	{
//		// trouver dans quel sens on va 
//		if (nouvellePosition.x > position.x && nouvellePosition.y < position.y)
//			direction = { +1, -1 };
//		else if (nouvellePosition.x < position.x && nouvellePosition.y < position.y)
//			direction = { +1, +1 };
//		else if (nouvellePosition.x > position.x && nouvellePosition.y > position.y)
//			direction = { -1, -1 };
//		else if (nouvellePosition.x < position.x && nouvellePosition.y > position.y)
//			direction = { -1, +1 };
//		else
//			deplacementValide = false;
//	}
//
//	while (deplacementValide)
//	{
//		//On vérifie si une pièce est en chemin (en si il y a une pièce de la couleur
//		//opposée sur la case finale, on mange la pièce)
//		if (posTmp.x == nouvellePosition.x && posTmp.y == nouvellePosition.y)
//			break;
//		else
//		{
//			posTmp.x += direction.first;
//			posTmp.y += direction.second;
//		}
//
//		if (posTmp.x <= 8 && posTmp.x >= 1 && posTmp.y <= 8 && posTmp.y >= 1)
//		{
//			if ((echiquier.getPiece(posTmp) != nullptr))
//			{
//				if (posTmp.x != nouvellePosition.x && posTmp.y != nouvellePosition.y)
//				{
//					caseDisponible = false;
//					return (deplacementValide && caseDisponible);
//				}
//				else if (echiquier.getPiece(nouvellePosition)->couleurPiece != couleurPiece)
//					caseDisponible = true;
//				else
//				{
//					caseDisponible = false;
//					return (deplacementValide && caseDisponible);
//				}
//					
//			}
//		}
//		else
//			break;
//	}
//	return (deplacementValide && caseDisponible && deplacementLegal);
//}
