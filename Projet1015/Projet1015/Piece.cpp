#include "Piece.h"
#include "Plateau.h"


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
	if (pos.verifierPosition())
		position = pos;
	else
		position = Position(1, 1);
	mnemonique = 'T';
}

bool Tour::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
{
	bool caseDisponible = true;
	bool deplacementValide = true;
	Position posTmp = position;

	std::pair<int, int> direction = { 0, 0 };
	if (nouvellePosition.verifierPosition())
	{
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


		while (true)
		{
			// add direction
			posTmp.x += direction.first;
			posTmp.y += direction.second;
			if (posTmp.x <= 8 && posTmp.x >= 1 && posTmp.y <= 8 && posTmp.y >= 1)
			{
				if ((echiquier.getPiece(posTmp) != nullptr))
				{
					caseDisponible = false;
					return (deplacementValide && caseDisponible);
				}
			}
			else
				break;
		}
		return (deplacementValide && caseDisponible);
	}
	return true;
}




Roi::Roi(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	if (pos.verifierPosition())
		position = pos;
	else
		position = Position(1, 1);
	mnemonique = 'R';
}

bool Roi::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
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





Reine::Reine(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	if (pos.verifierPosition())
		position = pos;
	else
		position = Position(1, 1);
	mnemonique = 'Q';
}

bool Reine::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
{
	// Pour l'instant, je met toujours le déplacement a true
	return true;
}





Cavalier::Cavalier(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	if (pos.verifierPosition())
		position = pos;
	else
		position = Position(1, 1);
	mnemonique = 'C';
}

bool Cavalier::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
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





Fou::Fou(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	if (pos.verifierPosition())
		position = pos;
	else
		position = Position(1, 1);
	mnemonique = 'F';
}

bool Fou::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
{
	// Pour l'instant, je met toujours le déplacement a true
	return true;
}
