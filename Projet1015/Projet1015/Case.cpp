#include "Case.h"


Case::Case()
{
	piece_ = make_unique<Piece>(Piece());
}

Piece Case::getPieceCase() const
{
	return *piece_.get();
}

void Case::setPieceCase(unique_ptr<Piece> &nouvellePiece)
{
	piece_ = move(nouvellePiece);
}
