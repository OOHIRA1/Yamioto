#pragma once
/*
参照しているヘッダー
#include "DxLib.h"
*/
int key[ KEY_MAX ];
int joypad[ JOYPADMAX ];


//キーボードを操作したかどうかを確認する関数
int updatekey( ) {
	char key_c[ KEY_MAX ];
	GetHitKeyStateAll( key_c );

	 for ( int i = 0; i < KEY_MAX; i++ ) {
		if ( key_c[ i ] == 1 ) {
			++key[ i ];
		} else {
			key[ i ] = 0;
		}
	}

	return 0;
}


//ジョイパット操作をしたかどうかを確認する関数
int updateJoypad( ) {
	int pad[ JOYPADMAX ] = { 
		PAD_INPUT_DOWN, 
		PAD_INPUT_LEFT, 
		PAD_INPUT_RIGHT, 
		PAD_INPUT_UP, 
		PAD_INPUT_1,
		PAD_INPUT_2,
		PAD_INPUT_3,
		PAD_INPUT_4 
	};

	for ( int i = 0; i < JOYPADMAX; i++ ) {
		if ( GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & pad[ i ] ) {
			++joypad[ i ];
		} else {
			joypad[ i ] = 0;
		}
	}
	return 0;
}


//キーボードまたはジョイパットを操作したか確認する関数
void updateDevice( ) {
	updatekey( );
	updateJoypad( );
}