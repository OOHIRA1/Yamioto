#pragma once
#include "DxLib.h"

struct Enemy { 
	VECTOR position;
	VECTOR velocity;

};

void EnemyInitialize( struct Enemy *enemy ) { 
	enemy->position = VGet( 0, 0, 0 );
	enemy->velocity = VGet( 0, 0, 0 );
}
