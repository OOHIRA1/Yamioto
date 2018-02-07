#pragma once

#include "DxLib.h"

struct Player {
	VECTOR position;
	VECTOR direction;
	int answer_count = 0;	//����	//�ŏ���answer��ture�ŏ������邽��-1�ŏ�����
	int not_answer_count = 0; //�s����
};

void PlayerInitialize( struct Player *player ) {
	player->position = VGet( 0, 0, FIRST_DISTANCE - 10 );
	player->direction = VGet( 0, 0, 1 );
	player->answer_count = 0;
	player->not_answer_count = 0;

}