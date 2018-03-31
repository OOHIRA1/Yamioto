#pragma once
/*
�Q�Ƃ��Ă���w�b�_�[
#include "DxLib.h"
*/

struct Player {
	VECTOR position;
	VECTOR direction;
	VECTOR pre_pos[ PRE_POS_MAX_INDEX ];	//�v���C���[���������W�i���I�����̍��W�j���L������z��
	int answer_count;	//����	//�ŏ���answer��ture�ŏ������邽��-1�ŏ����������I�������O
	int not_answer_count; //�s����
};

void PlayerInitialize( struct Player *player ) {
	player->position = VGet( 0, 0, ( float )FIRST_DISTANCE );
	player->direction = VGet( 0, 0, 1 );

	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		player->pre_pos[ i ] = VGet( 0, 0, 0 );
	}
	player->pre_pos[ 0 ] = player->position;	//�ŏ��̍��W��pre_pos[ 0 ]�ɑ��

	player->answer_count = 0;
	player->not_answer_count = 0;

}