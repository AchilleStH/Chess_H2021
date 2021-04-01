#include "Case.h"


Case::Case()
{
	piece_ = Piece();
}

Piece Case::getPieceCase() const
{
	return piece_;
}

void Case::setPieceCase(Piece nouvellePiece)
{
	piece_ = nouvellePiece;
}
