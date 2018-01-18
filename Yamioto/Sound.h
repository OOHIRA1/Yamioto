#pragma once

#include "DxLib.h"

void Psound( int handol, int type ) {
	switch ( type ) {
	case 0:
		PlaySoundMem( handol, DX_PLAYTYPE_NORMAL, TRUE );
		break;

	case 1:
		PlaySoundMem( handol, DX_PLAYTYPE_BACK, TRUE );
		break;

	case 2:
		PlaySoundMem( handol, DX_PLAYTYPE_LOOP, TRUE );
		break;

	default:
		break;
	}
}

void Vsound( int size, int handol ) {
	ChangeVolumeSoundMem( size, handol );
}

void Ssound( int handol ) {
	StopSoundMem( handol );
}

int Csound( int handol ) {
	return CheckSoundMem( handol );
}
