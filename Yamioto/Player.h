#pragma once
/*
参照しているヘッダー
#include "DxLib.h"
*/

struct Player {
	VECTOR position;
	VECTOR direction;
	VECTOR pre_pos[ 30 ];	//プレイヤーがいた座標（道選択時の座標）を記憶する配列
	int answer_count;	//正解数	//最初にanswerをtureで処理するため-1で初期化
	int not_answer_count; //不正解数
};

void PlayerInitialize( struct Player *player ) {
	player->position = VGet( 0, 0, ( float )FIRST_DISTANCE );
	player->direction = VGet( 0, 0, 1 );

	for ( int i = 0; i < 30; i++ ) {
		player->pre_pos[ i ] = VGet( 0, 0, 0 );
	}

	player->answer_count = 0;
	player->not_answer_count = 0;

}