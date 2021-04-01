#include "Piece.h"
#include "Plateau.h"


// Implementation de la classe Piece et de ses d�riv�es



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

bool Tour::verificationDeplacement(Position nouvellePosition)
{
	if (nouvellePosition.verificationPosition())
		return true;
	else
		return false;
}

void Tour::deplacement(Position nouvellePosition)
{
	if (verificationDeplacement(nouvellePosition) == true)
		position = Position(nouvellePosition.x, nouvellePosition.y);
	else
		cout << "D�PLACEMENT INVALIDE\n";
}




Roi::Roi(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'R';
}

bool Roi::verificationDeplacement(Position nouvellePosition)
{
	// Pour l'instant, je met toujours le d�placement a true
	return true;
}

void Roi::deplacement(Position nouvellePosition)
{
	if (verificationDeplacement(nouvellePosition) == true)
		position = Position(nouvellePosition.x, nouvellePosition.y);
	else
		cout << "D�PLACEMENT INVALIDE\n";
}




Reine::Reine(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'Q';
}

bool Reine::verificationDeplacement(Position nouvellePosition)
{
	// Pour l'instant, je met toujours le d�placement a true
	return true;
}

void Reine::deplacement(Position nouvellePosition)
{
	if (verificationDeplacement(nouvellePosition) == true)
		position = Position(nouvellePosition.x, nouvellePosition.y);
	else
		cout << "D�PLACEMENT INVALIDE\n";
}




Cavalier::Cavalier(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'C';
}

bool Cavalier::verificationDeplacement(Position nouvellePosition)
{
	// Pour l'instant, je met toujours le d�placement a true
	return true;
}

void Cavalier::deplacement(Position nouvellePosition)
{
	if (verificationDeplacement(nouvellePosition) == true)
		position = Position(nouvellePosition.x, nouvellePosition.y);
	else
		cout << "D�PLACEMENT INVALIDE\n";
}




Fou::Fou(Couleur couleur, Position pos)
{
	couleurPiece = couleur;
	position = pos;
	mnemonique = 'F';
}

bool Fou::verificationDeplacement(Position nouvellePosition)
{
	// Pour l'instant, je met toujours le d�placement a true
	return true;
}

void Fou::deplacement(Position nouvellePosition)
{
	if (verificationDeplacement(nouvellePosition) == true)
		position = Position(nouvellePosition.x, nouvellePosition.y);
	else
		cout << "D�PLACEMENT INVALIDE\n";
}