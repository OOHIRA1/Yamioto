#pragma once

#include "DxLib.h"

int key[ KEY_MAX ];
char key_c[ KEY_MAX ];

int updatekey( ) {
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