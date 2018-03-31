#pragma once
/*
参照しているヘッダー
#include "DxLib.h"
*/

struct Player {
	VECTOR position;
	VECTOR direction;
	VECTOR pre_pos[ PRE_POS_MAX_INDEX ];	//プレイヤーがいた座標（道選択時の座標）を記憶する配列
	int answer_count;	//正解数	//最初にanswerをtureで処理するため-1で初期化※道選択実装前
	int not_answer_count; //不正解数
};

void PlayerInitialize( struct Player *player ) {
	player->position = VGet( 0, 0, ( float )FIRST_DISTANCE );
	player->direction = VGet( 0, 0, 1 );

	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		player->pre_pos[ i ] = VGet( 0, 0, 0 );
	}
	player->pre_pos[ 0 ] = player->position;	//最初の座標をpre_pos[ 0 ]に代入

	player->answer_count = 0;
	player->not_answer_count = 0;

}