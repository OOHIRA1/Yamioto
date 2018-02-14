#pragma once
/*
参照しているヘッダー
#include "DxLib.h"
*/

struct Player {
	VECTOR position;
	VECTOR direction;
	int answer_count = 0;	//正解数	//最初にanswerをtureで処理するため-1で初期化
	int not_answer_count = 0; //不正解数
};

void PlayerInitialize( struct Player *player ) {
	player->position = VGet( 0, 0, FIRST_DISTANCE - 10 );
	player->direction = VGet( 0, 0, 1 );
	player->answer_count = 0;
	player->not_answer_count = 0;

}