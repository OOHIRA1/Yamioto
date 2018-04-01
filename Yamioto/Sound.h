#pragma once
/*
参照しているヘッダー
#include "DxLib.h"
*/


//関数原型宣言========================================================================
void Psound( int handle, int type );						//音を鳴らす関数
void Ssound( int handle );									//音を止める関数
int Csound( int handle );									//音が鳴っているか確認する関数
void Vsound( int handle, int volume );						//音量を変える関数
void SetEnemySoundPos( VECTOR v, int handle );				//音データの３Ｄサウンド用の再生位置を設定する関数
void SetPlayerPosAndDir( VECTOR listenerpos, VECTOR listenerdir );	//音データの３Ｄサウンド用の音が聞こえる距離を設定する関数
void SetRadius( float radius, int handle );							//音データの３Ｄサウンド用の音が聞こえる距離を設定する関数
void SetOneMeter( float distance );									//３Ｄ空間の１メートルに相当する距離を設定する
//====================================================================================


//--音を鳴らす関数
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


//--音を止める関数
void Ssound( int handle ) {
	StopSoundMem( handle );
}


//--音が鳴っているか確認する関数
int Csound( int handle ) {
	return CheckSoundMem( handle );
}


//--音量を変える関数
void Vsound( int handle, int volume ) {
	ChangeVolumeSoundMem( volume, handle );
}


//--音データの３Ｄサウンド用の再生位置を設定する関数
void SetEnemySoundPos( VECTOR v, int handle ) {
	Set3DPositionSoundMem( v, handle );
}


//--３Ｄサウンドのリスナーの位置とリスナーの前方位置を設定する
void SetPlayerPosAndDir( VECTOR listenerpos, VECTOR listenerdir ) {
	Set3DSoundListenerPosAndFrontPos_UpVecY( listenerpos, VAdd( listenerpos, listenerdir ) );
}


//--音データの３Ｄサウンド用の音が聞こえる距離を設定する関数
void SetRadius( float radius, int handle ) { 
	Set3DRadiusSoundMem( radius, handle );
}


//--３Ｄ空間の１メートルに相当する距離を設定する
void SetOneMeter( float distance ) {
	Set3DSoundOneMetre( distance );
}

