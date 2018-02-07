#pragma once

#include "DxLib.h"

void Psound( int handle, int type ) {
	switch ( type ) {
	case 0:
		PlaySoundMem( handle, DX_PLAYTYPE_NORMAL, TRUE );
		break;

	case 1:
		PlaySoundMem( handle, DX_PLAYTYPE_BACK, TRUE );
		break;

	case 2:
		PlaySoundMem( handle, DX_PLAYTYPE_LOOP, TRUE );
		break;

	default:
		break;
	}
}


void Ssound( int handle ) {
	StopSoundMem( handle );
}

int Csound( int handle ) {
	return CheckSoundMem( handle );
}

void Vsound( int handle, int volume ) {
	ChangeVolumeSoundMem( volume, handle );
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

