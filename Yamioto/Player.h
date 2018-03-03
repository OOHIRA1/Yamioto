#pragma once
/*
�Q�Ƃ��Ă���w�b�_�[
#include "DxLib.h"
*/

struct Player {
	VECTOR position;
	VECTOR direction;
	VECTOR pre_pos[ 30 ];	//�v���C���[���������W�i���I�����̍��W�j���L������z��
	int answer_count;	//����	//�ŏ���answer��ture�ŏ������邽��-1�ŏ�����
	int not_answer_count; //�s����
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