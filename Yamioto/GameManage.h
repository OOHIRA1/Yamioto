#pragma once

#include "Const.h"
#include "Question.h"
#include "Player.h"
#include "Enemy.h"

enum GameStatus gamestatus = GAME_START;

int flame_count = 0;
int distance = FIRST_DISTANCE - 10; //�c�莞�� 
int escape_count = 0;	//�����Ă���t���[�����𐔂���ϐ�
bool sounded = false; 

void Initialization( );
void Judge( );


void GameStart( );
void GameMain( );
void GameResult( );

struct Player player;
struct Enemy enemy;

void Initialization( ) {

	PlayerInitialize( &player );
	EnemyInitialize( &enemy );
	SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
	SetEnemySoundPos( enemy.position, sound[ 0 ] );
	SetRadius( 30, sound[ 0 ] );

	flame_count = 0;
	distance = FIRST_DISTANCE - 10;
	question_num = 0;
	escape_count = 0;
	answer = true;
	not_answer = false;
	input = true;
	sounded = false;

}

void Judge( ) {

	if ( not_answer ) {	//�s��������

		if ( escape_count == 0 ) {
			Psound( sound[5], BACK );
			player.not_answer_count++;
		}

		escape_count++;

		if ( escape_count == 200 ) {
			escape_count = 0;
			question_num++;

			input = true;
			not_answer = false;
		}

	}

	if ( answer ) {						//��������
										//����������ŏ��ɐ�������炷�B���̂��ƂɃh�A�̊J����炷
		if ( escape_count == 0 && player.answer_count > -1 ) {
			Psound( sound[4], NORMAL );
			Psound( sound[1], NORMAL );
		}

		//�������ƃh�A�̊J������I������瑖��o��
		if ( escape_count == 0 ) {
			Psound( sound[2], LOOP );
		}

		escape_count++;
		distance += escape_count % 21 / 20;
		player.position.z += escape_count % 21 / 20;
		SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );

		if ( escape_count == 200 ) {
			Ssound( sound[2] );
			escape_count = 0;
			player.answer_count++;

			if ( player.answer_count < CLEAR ) {
				Psound( sound[3], NORMAL );
				question_num++;

				input = true;
				answer = false;
			} else {
				gamestatus = GAME_RESULT;
			}

		}

	}

}


void draw( ) {
	DrawBox( enemy.position.x - 8,  (480 - (enemy.position.z + 8 )), enemy.position.x + 8, (480 - ( enemy.position.z - 8 )), GetColor( 255, 0, 0 ), TRUE );
	DrawBox( player.position.x - 8,  (480 - (player.position.z + 8 )), player.position.x + 8, (480 - ( player.position.z - 8 )), GetColor( 0, 0, 255 ), TRUE );
}


void GameStart( ) {

	//�\��
	DrawString(100, 100, "�ŉ�", GetColor( 255, 255, 255 ) );
	DrawString(100, 150, "PUSH ENTER", GetColor( 255, 255, 255 ) );
	if ( key[ KEY_INPUT_RETURN ] ) {
		gamestatus = GAME_MAIN;
		Initialization( );
	}
		
}

void GameMain( ) {

	//��������
	if ( Csound( sound[ 0 ] ) == 0 ) {
		Psound( sound[0], LOOP );
	}

	//�������k�܂�
	flame_count++;
	if ( !answer ) {
		switch( player.not_answer_count ) {
		case 0:
			distance -= flame_count % 61 / 60;
			enemy.position.z += flame_count % 61 / 60;
			break;
		case 1:
			distance -= flame_count % 46 / 45;
			enemy.position.z += flame_count % 46 / 45;
			break;
		default:
			distance -= flame_count % 31 / 30;
			enemy.position.z += flame_count % 31 / 30;
			break;
		}
		SetEnemySoundPos( enemy.position, sound[ 0 ] );
	}
	


	DrawFormatString( 0, 0, GetColor( 255, 0, 0 ), "%d", distance );

	//���Ԍo�߂ő����̉��ʂ�ς���																	
	//EnemySound( );

	//���ɓ�������
	Judge( );

	//�������Ԃ��O�ɂȂ�����
	if ( distance == 0 ) {
		gamestatus = GAME_RESULT;
	}
	

	//���̃��[�v
	if ( question_num > QUESTION_MAX ) {
		question_num = 1;
	}

	Question( question_num );
	draw();
}

void GameResult( ) {
	Ssound( sound[0] );

	//�`��
	if ( player.answer_count == CLEAR ) {
		DrawString( 100, 100, "�Q�[���N���A�I�I�I", GetColor( 255, 255, 255 ) );

		if ( !sounded ) {
			Psound( sound[6], BACK );
			sounded = true;
		}

	} else {
		DrawString( 100, 100, "�Q�[���I�[�o�[�I�I�I", GetColor( 255, 0, 0 ) );
		DrawGraph( 100, 110, resource[ 0 ], TRUE );

		if ( !sounded ) {
			Psound( sound[7], BACK );
			sounded = true;
		}

	}

	DrawString( 100, 150, "PUSH SPACE", GetColor( 255, 255, 255 ) );
	if ( key[ KEY_INPUT_SPACE ] ) {
		gamestatus = GAME_START;
	}

}