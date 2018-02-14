#pragma once
/*
参照しているヘッダー
#include "DxLib.h"
*/

struct Enemy { 
	VECTOR position;
};

void EnemyInitialize( struct Enemy *enemy ) { 
	enemy->position = VGet( 0, 0, 0 );
}
