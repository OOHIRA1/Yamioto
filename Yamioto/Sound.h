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


void Ssound( int handol ) {
	StopSoundMem( handol );
}

int Csound( int handol ) {
	return CheckSoundMem( handol );
}

void SetEnemySoundPos( VECTOR v, int handle ) {
	Set3DPositionSoundMem( v, handle );
}

void SetPlayerPosAndDir( VECTOR listenerpos, VECTOR listenerdir ) {
	Set3DSoundListenerPosAndFrontPos_UpVecY( listenerpos, VAdd( listenerpos, listenerdir ) );
}

void SetRadius( float radius, int handle ) { 
	Set3DRadiusSoundMem( radius, handle );
}

void SetOneMeter( float distance ) {
	Set3DSoundOneMetre( distance );
}
