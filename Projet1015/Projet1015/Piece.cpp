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
	position = pos;
	mnemonique = 'T';
}

bool Tour::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
{
	return true;
}




Roi::Roi(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'R';
}

bool Roi::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
{
	// Pour l'instant, je met toujours le déplacement a true
	return true;
}





Reine::Reine(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
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
	position = pos;
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
	if (echiquier.getPiece(nouvellePosition) != nullptr && echiquier.getPiece(nouvellePosition)->couleurPiece == couleurPiece)
		caseDisponible = false;

	return (deplacementValide && caseDisponible);
}





Fou::Fou(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'F';
}

bool Fou::verificationDeplacement(Position nouvellePosition, Plateau echiquier)
{
	// Pour l'instant, je met toujours le déplacement a true
	return true;
}
