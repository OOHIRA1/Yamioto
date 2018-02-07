#pragma once

#include "Const.h"
#include "Question.h"
#include "Player.h"
#include "Enemy.h"
#include <time.h>

enum GameStatus gamestatus = GAME_START;

int bright = 0;
bool bright_max = true;

int flame_count = 0;
int distance = FIRST_DISTANCE - 10; //�c�莞�� 
int escape_count = 0;	//�����Ă���t���[�����𐔂���ϐ�
bool sounded = false; 
int ExerciseBooks_num;
int gameoverWait_count = 0;
bool gameover_wait = true;


int x1 = SCREEN_WIDTH_CENTER, y1 = SCREEN_HEIGHT_CENTER, 
	x2 = SCREEN_WIDTH_CENTER, y2 = SCREEN_HEIGHT_CENTER, 
	x3 = SCREEN_WIDTH_CENTER, y3 = SCREEN_HEIGHT_CENTER, 
	x4 = SCREEN_WIDTH_CENTER, y4 = SCREEN_HEIGHT_CENTER;

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
	QuesitionInitialize( );
	SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
	SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );
	SetRadius( 30, sound[ ENEMY_VOICE ] );

	flame_count = 0;
	distance = FIRST_DISTANCE - 10;
	escape_count = 0;
	gameoverWait_count = 0;
	bright = 0;

	x1 = SCREEN_WIDTH_CENTER;
	y1 = SCREEN_HEIGHT_CENTER;
	x2 = SCREEN_WIDTH_CENTER;
	y2 = SCREEN_HEIGHT_CENTER;
	x3 = SCREEN_WIDTH_CENTER;
	y3 = SCREEN_HEIGHT_CENTER;
	x4 = SCREEN_WIDTH_CENTER;
	y4 = SCREEN_HEIGHT_CENTER;

	sounded = false;
	gameover_wait = true;


}




void Judge( ) {
	if ( !chooseWayFlag && !input && !answer && !not_answer  ) {						//����I��Ŗ��\�����ĂȂ��Ƃ��̏���			

		//����o��
		if ( escape_count == 0 ) {
			Vsound( sound[ PLAYER_ASIOTO ], 100 );
			Psound( sound[ PLAYER_ASIOTO ], LOOP );
		}

			
		escape_count++;

		distance += escape_count % 21 / 20;

		player.position.z += escape_count % 21 / 20;
		SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );

		if ( escape_count == 100 ) {
			Ssound( sound[ PLAYER_ASIOTO ] );
			Vsound( sound[ DOOR_GATYA ], 100 );
			Psound( sound[ DOOR_GATYA ], NORMAL );
			escape_count = 0;
			input = true;
		}
	}

	if ( not_answer ) {	//�s��������

		if ( escape_count == 0 ) {
			Vsound( sound[ MATIGAI ], 100 );
			Psound( sound[ MATIGAI ], BACK );
			player.not_answer_count++;
		}

		escape_count++;

		if ( escape_count == 200 ) {

			escape_count = 0;
			question_num++;

			srand( time( NULL ) );
			ExerciseBooks_num = rand( ) % 3;

			input = true;
			not_answer = false;
		}

	}

	if ( answer ) {						//��������			
		if ( escape_count == 0 && player.answer_count > -1 ) {			//����������ŏ��ɐ�������炷�B���̂��ƂɃh�A�̊J����炷
			Vsound( sound[ SEIKAI ], 100 );
			Psound( sound[ SEIKAI ], NORMAL );
			Vsound( sound[ DOOR ], 100 );
			Psound( sound[ DOOR ], NORMAL );
		}


		//�������ƃh�A�̊J������I������瑖��o��
		if ( escape_count == 0 ) {
			Vsound( sound[ PLAYER_ASIOTO ], 100 );
			Psound( sound[ PLAYER_ASIOTO ], LOOP );
		}

			
		escape_count++;

		distance += escape_count % 21 / 20;

		player.position.z += escape_count % 21 / 20;
		SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
		
		//�E�o���O�̉摜�\��
		if ( player.answer_count == CLEAR - 1 ) {
			DrawModiGraph( x1--, y1--, x2++, y2--, x3++, y3++, x4--, y4++, resource[ 1 ], TRUE );
		}

		

		if ( escape_count == 200 ) {
			Ssound( sound[ PLAYER_ASIOTO ] );
			escape_count = 0;
			player.answer_count++;

			if ( player.answer_count < CLEAR ) {	//player.answer_count���K�v���𐔈ȉ��̂Ƃ�
				
				question_num++;

				srand( time( NULL ) );
				ExerciseBooks_num = rand( ) % 3;

				answer = false;
				chooseWayFlag = true;	//����I�ׂ�悤�ɂ���
			} else {
				gamestatus = GAME_RESULT;
			}

		}

	}
}



void debugdraw( ) {
	DrawBoxAA( enemy.position.x - 8,  (480 - (enemy.position.z + 8 )), enemy.position.x + 8, (480 - ( enemy.position.z - 8 )), GetColor( 255, 255, 255 ), TRUE );
	DrawBoxAA( player.position.x - 8,  (480 - (player.position.z + 8 )), player.position.x + 8, (480 - ( player.position.z - 8 )), GetColor( 0, 0, 255 ), TRUE );

	//�c�苗����`��
	DrawFormatString( 0, 0, GetColor( 255, 255, 255 ), "%d", distance );

}


void GameStart( ) {
	//�X�^�[�g��ʂa�f�l
	if ( !Csound( sound[ GAME_START_BGM ] ) ) {
		Vsound( sound[ GAME_START_BGM ], 100 );
		Psound( sound[ GAME_START_BGM ], LOOP );
	}

	//�\��
	DrawString(100, 100, "�ŉ�", GetColor( 255, 255, 255 ) );
	DrawString(100, 150, "PRESS ENTER KEY", GetColor( 255, 255, 255 ) );
	if ( key[ KEY_INPUT_RETURN ] ) {
		Ssound( sound[ GAME_START_BGM ] );
		gamestatus = GAME_MAIN;
		Initialization( );
	}
		
}

void GameMain( ) {
	//�Q�[�����C���a�f�l
	if ( !Csound( sound[ GAME_MAIN_BGM ] ) ) {
		Vsound( sound[ GAME_MAIN_BGM ], 100 );
		Psound( sound[ GAME_MAIN_BGM ], LOOP );
	}

	//�����̐�
	if ( !Csound( sound[ ENEMY_VOICE ] ) ) {
		Psound( sound[ ENEMY_VOICE ], LOOP );
		Vsound( sound[ ENEMY_VOICE ], 255 );
	}

	//�������k�܂�
	flame_count++;
	if ( !answer || chooseWayFlag ) {	//���𓚂��Ă��Ȃ��Ƃ� �܂��́@����I��ł��Ȃ��Ƃ�
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
		SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );
	}

	if ( chooseWayFlag ) {
		ChooseWay( );
	}


	//���Ԃɍ��킹�ĉ�ʂ�Ԃ����Ă���
	int r = bright;
	int g = bright;
	int b = bright;

	if ( distance > 30 ) {

		if ( bright > 0 ) bright--;
		
	} else if ( distance > 20 && distance <= 30 ) {

		if ( bright > 100 ) {
			bright--;
		} else {
			bright++;
		}
	
	} else if ( distance > 10 && distance <= 20 ) {

		if ( bright < 255 ) bright++;

	} else {
		
		if ( bright > 255  ) {
			bright_max = true;
		} else if ( bright < 0 ) {
			bright_max = false;
		} 

		if ( !bright_max ) {
			bright += 5;
		} else {
			bright -= 5;
		}

	}

	//��ʂ�Ԃ������`��
	SetDrawBright( r, g, b );
	DrawGraph( 0, 0, resource[ 3 ], TRUE );
	SetDrawBright( 255, 255, 255 );							

	//���ɓ�������
	if ( !chooseWayFlag ) {
		Judge( );
	}

	//�������Ԃ��O�ɂȂ�����
	if ( distance == 0 ) {
		gamestatus = GAME_RESULT;
	}
	

	//���̃��[�v
	if ( question_num > QUESTION_MAX ) {
		question_num = 1;
	}

	Question( /*ExerciseBooks_num*/1, question_num );
	debugdraw();
}


void GameResult( ) {
	Ssound( sound[ GAME_MAIN_BGM ] );
	Ssound( sound[ ENEMY_VOICE ] );
	if ( Csound( sound[ PLAYER_ASIOTO ] ) ) {
		Ssound( sound[ PLAYER_ASIOTO ] );
	}

	//�`��
	if ( player.answer_count == CLEAR ) {
		DrawString( 100, 100, "�Q�[���N���A�I�I�I", GetColor( 255, 255, 255 ) );
		DrawGraph( 100,110, resource[ 2 ], TRUE );
		if ( !sounded ) {
			Psound( sound[ GAME_CLEAR ], BACK );
			sounded = true;
		}

		DrawString( 100, 150, "PUSH SPACE", GetColor( 255, 255, 255 ) );
		if ( key[ KEY_INPUT_SPACE ] ) {
			Ssound( sound[ GAME_CLEAR ] );
			gamestatus = GAME_START;
			}

	} else {

		if ( gameover_wait ) gameoverWait_count++;

		if ( gameoverWait_count >= 120 ) {
			gameover_wait = false;
			DrawString( 100, 100, "�Q�[���I�[�o�[�I�I�I", GetColor( 255, 0, 0 ) );
			DrawGraph( 100, 110, resource[ 0 ], TRUE );

			if ( !sounded ) {
				Psound( sound[ GAME_OVER ], BACK );
				sounded = true;
			}

			DrawString( 100, 150, "PUSH SPACE", GetColor( 255, 255, 255 ) );
			if ( key[ KEY_INPUT_SPACE ] ) {
				Ssound( sound[ GAME_OVER ] );
				gamestatus = GAME_START;
			}
		
		}

	}
}