#pragma once

#include "DxLib.h"
#include <time.h>
/*
�Q�Ƃ��Ă���w�b�_�[
#include "Input.h"
#include "Load.h"
*/

int question_num;	//���ԍ�
int exercise_books_num;	//���W�̔ԍ�

bool answer;			//�����������ǂ����̃t���O
bool not_answer;		//�s�������ǂ����̃t���O
bool input;				//���͂��󂯕t���邩�ǂ����̃t���O
bool chooseWayFlag;		//����I��ł��邩�ǂ����t���O
bool q_finished[ 3 ][ QUESTION_MAX ]; //���W�i��Փx�j�̐��Ɩ�萔 //��肪�o�����ǂ����𔻒肷��ϐ�

int font_handle;		//��蕶�t�H���g�n���h��
int font_handle2;		//�I�����t�H���g�n���h��
int cr;					//��蕶�̐F
int cr2;				//�I�����̐F

int selectedSentence;	//�J�[�\���̈ʒu

enum Way way;	//�I�񂾓�
int level[ WAY_MAX ];	//���I�����̓�Փx
bool level_randamed;	//���I�����Ɋe���Ƀ����_���œ�Փx������U�������ǂ����̃t���O

void QuesitionInitialize( );
void Question( int, int );
void Question1( int );
void Question2( int );
void Question3( int );
void ChooseWay( );

void changeColor( int selectedchoice, char* string, int color ) {
	DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CURSOR_SELECT_POS_Y * selectedchoice ), color, font_handle2, string );
}



//--Question.h�̕ϐ�������������֐�
void QuesitionInitialize( ) {
	question_num = 1;
	exercise_books_num = 0;

	answer = false;
	not_answer = false;
	input = false;
	chooseWayFlag = true;
	way = NOT_CHOOSE_WAY;
	font_handle = CreateFontToHandle( "�l�r ����", 20, 5 );
	font_handle2 = CreateFontToHandle( "�l�r ����", 20, 3 );
	cr = GetColor( 255, 255, 255 );	
	cr2 = GetColor( 255, 255, 255 );

	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < QUESTION_MAX; j++ ) {
			q_finished[ i ][ j ] = false;
		}
	}

	selectedSentence = 0;

	for ( int i = 0; i < WAY_MAX; i++ ) {
		level[ i ] = -1;
	}
	level_randamed = false;
}

////--�J�[�\����\������֐�(�L�[�{�[�h�Ή�)
//void KeybordCursor( ) {
//	DrawCircle( CHOICES_POS_X - 20, CHOICES_POS_Y + 10 + ( CURSOR_SELECT_POS_Y * selectedSentence ), 5, cr, true );
//	//DrawGraph( CHOICES_POS_X - 10, CHOICES_POS_Y + 5 + ( CURSOR_SELECT_POS_Y * selectedSentence ), resource[ 4 ], TRUE );
//	if ( key[ KEY_INPUT_DOWN ] == 1 && selectedSentence < 3 ) {	//��ԉ��ɗ����炻��ȏ�i�܂Ȃ� //�I�������S����̂�4 - 1
//		selectedSentence++;
//	}
//
//	if ( key[ KEY_INPUT_UP ] == 1 && selectedSentence > 0 ) {	//��ԉ��ɗ����炻��ȏ�i�܂Ȃ� //�I�������S����̂�4 - 1
//		selectedSentence--;
//	}
//}

//--�J�[�\����\������֐�(�W���C�p�b�g�Ή�)
void JoypadCursor( ) { 
	DrawCircle( CHOICES_POS_X - 20, CHOICES_POS_Y + 11 + ( CURSOR_SELECT_POS_Y * selectedSentence ), 5, cr, true );
	//DrawGraph( CHOICES_POS_X - 10, CHOICES_POS_Y + 5 + ( CURSOR_SELECT_POS_Y * selectedSentence ), resource[ 4 ], TRUE );

	if ( joypad[ DOWN ] == 1 && selectedSentence < 3 ) {	//��ԉ��ɗ����炻��ȏ�i�܂Ȃ� //�I�������S����̂�4 - 1
		selectedSentence++;
	}

	if ( joypad[ UP ] == 1 && selectedSentence > 0 ) {	//��ԉ��ɗ����炻��ȏ�i�܂Ȃ� //�I�������S����̂�4 - 1
		selectedSentence--;
	}
}

void Question( int a, int num ) {
	switch( a ) {
	case 0:
		Question1( num );
		break;
	case 1:
		Question2( num );
		break;
	case 2:
		Question3( num );
		break;
	}
}

void Question1( int num ) {	
	 cr2 = GetColor( 255, 255, 255 );
	if ( input == true ) {
		for ( int i = 0; i < 3; i++ ) {		//��蕶�\��
			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), cr, font_handle, q_load[ EASY ].questionStatement[ i + ( num - 1 ) * 3 ] );
		}
		
		for ( int i = 0; i < 4; i++ ) {		//�I�����\��
			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CURSOR_SELECT_POS_Y * i ), cr2, font_handle2, q_load[ EASY ].choices[ i + ( num - 1 ) * 4 ] );
		}


		if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_2 ] == 1 ) {

			if ( selectedSentence == q_load[ EASY ].answerNum[ num - 1 ] ) {

				cr2 = GetColor( 0, 255, 0 );
				changeColor( selectedSentence, q_load[ EASY ].choices[ selectedSentence + ( num - 1 ) * 4 ], cr2 );
				answer = true;
				input = false;

			} else {

				cr2 = GetColor( 255, 0, 0 );
				changeColor( selectedSentence, q_load[ EASY ].choices[ selectedSentence + ( num - 1 ) * 4  ], cr2 );
				not_answer = true;
				input = false;

			}
		
		}
		
	}
}

void Question2( int num ) {
	cr2 = GetColor( 255, 255, 255 );
	if ( input == true ) {
		for ( int i = 0; i < 3; i++ ) {		//��蕶�\��
			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), cr, font_handle, q_load[ BASIC ].questionStatement[ i + ( num - 1 ) * 3 ] );
		}
		
		for ( int i = 0; i < 4; i++ ) {		//�I�����\��
			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CURSOR_SELECT_POS_Y * i ), cr2, font_handle2, q_load[ BASIC ].choices[ i + ( num - 1 ) * 4 ] );
		}


		if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_2 ] == 1 ) {

			if ( selectedSentence == q_load[ BASIC ].answerNum[ num - 1 ] ) {

				cr2 = GetColor( 0, 255, 0 );
				changeColor( selectedSentence, q_load[ BASIC ].choices[ selectedSentence + ( num - 1 ) * 4 ], cr2 );
				answer = true;
				input = false;

			} else {

				cr2 = GetColor( 255, 0, 0 );
				changeColor( selectedSentence, q_load[ BASIC ].choices[ selectedSentence + ( num - 1 ) * 4  ], cr2 );
				not_answer = true;
				input = false;

			}
		
		}
		
	}
}


void Question3( int num ) {
	cr2 = GetColor( 255, 255, 255 );
	if ( input == true ) {
		for ( int i = 0; i < 3; i++ ) {		//��蕶�\��
			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), cr, font_handle, q_load[ HARD ].questionStatement[ i + ( num - 1 ) * 3 ] );
		}
		
		for ( int i = 0; i < 4; i++ ) {		//�I�����\��
			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CURSOR_SELECT_POS_Y * i ), cr2, font_handle2, q_load[ HARD ].choices[ i + ( num - 1 ) * 4 ] );
		}


		if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_2 ] == 1 ) {

			if ( selectedSentence == q_load[ HARD ].answerNum[ num - 1 ] ) {

				cr2 = GetColor( 0, 255, 0 );
				changeColor( selectedSentence, q_load[ HARD ].choices[ selectedSentence + ( num - 1 ) * 4 ], cr2 );
				answer = true;
				input = false;

			} else {

				cr2 = GetColor( 255, 0, 0 );
				changeColor( selectedSentence, q_load[ HARD ].choices[ selectedSentence + ( num - 1 ) * 4  ], cr2 );
				not_answer = true;
				input = false;

			}
		
		}
		
	}
}

//void Question3( int num ) {
//	switch( num ) {
//	case 1 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�J�o�̊��̐F�́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�n�`�̐F\n B�F���瓤�̐F\n C�F�킽���߂̐F\n D�F���̐F" );
//
//			if ( key[ KEY_INPUT_D ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
//				not_answer = true;
//				input = false;
//			}
//		}
//		break;
//
//	case 2 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�h��������̐g���́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F120cm\n B�F127.3cm\n C�F129.3cm\n D�F180cm" );
//
//			if ( key[ KEY_INPUT_C ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//	case 3 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�J�o�̊��̐F�́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�n�`�̐F\n B�F���瓤�̐F\n C�F�킽���߂̐F\n D�F���̐F" );
//
//			if ( key[ KEY_INPUT_D ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 4 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�A���p���}���̊�̒��g�́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�`���R���[�g\n B�F�Ԃ���\n C�F��������\n D�F�����܃y�[�X�g" );
//
//			if ( key[ KEY_INPUT_B ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 5 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�u�Ђ炯�|���L�b�L�v�ɏo�Ă��郀�b�N�̐��̂́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�݂̒��̒j�̎q\n B�F�����u�����̗d��\n C�F���b�v�̂��΂�\n D�F��j�i�C�G�e�B�[�j�̒j�̎q" );
//
//			if ( key[ KEY_INPUT_D ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 6 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�h���S���{�[���́uSSGSS�v ���̗��H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�X�[�p�[�T�C���l�S�b�g�X�[�p�[�T�C���l\n B�F�X�[�p�[�T�C���l�O�����h�X�[�p�[�T�C���l\n C�F�X�[�p�[�T�C���l�S�b�e�X�X�[�p�[�T�C���l\n D�F�X�y�V�����T�C���l�S�b�g�X�y�V�����T�C���l" );
//			if ( key[ KEY_INPUT_A ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 7 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�h���S���N�G�X�g�W�ɏo�Ă���{�X�̖��O�́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F����\n B�F�G���M�I�X\n C�F���v�\�[��\n D�F�I���S�f�~�[��" );
//
//			if ( key[ KEY_INPUT_C ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 8 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"2016�N��f�̉f��u��qVS�����v�@���̒�q�ƑΌ������̂́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�W�F�C�\��\n B�F�����q\n C�F�A�z�t\n D�F�g�C���̉Ԏq����" );
//
//			if ( key[ KEY_INPUT_B ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 9 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�~�}�ԂȂǂ̉����߂Â��ꍇ�Ɖ�������ꍇ�ŕ����������Ⴄ���Ƃ��Ȃ�Ƃ����H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�g���b�v����\n B�F�h���b�v����\n C�F�h�b�u���[����\n D�F�h�b�v���[����" );
//
//			if ( key[ KEY_INPUT_D ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 10 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�u�΂̏�ɂ����N�v�@���́��ɓ���̂́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F1\n B�F2\n C�F3\n D�F4" );
//
//			if ( key[ KEY_INPUT_C ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 11 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"�u���l�̋C�����������͂���v�Ƃ����Ӗ��̌��t�u�u�x�v�B���ƓǂށH" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�����\n B�F�����\n C�F���񂽂�\n D�F���񂽂�" );
//
//			if ( key[ KEY_INPUT_C ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 12 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"��C�푈�A����푈�ŗL���ȍ��N�̑�̓h���}�Ŏ��グ��ꂽ�l���Ƃ����΁H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F��v�ۗ���\n B�F��������\n C�F�ɓ�����\n D�F�_�ޏ�" );
//
//			if ( key[ KEY_INPUT_B ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 13 :
//		if ( input == true ) {
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle,"���p�O�p�`�̎ΕӒ�����2��͑��̓�ӂ�2��̘a�ɓ������B���̒藝�����Ƃ������H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�O�����̒藝\n B�F���@�藝\n C�F���l���E�X�̒藝\n D�F�t�F���}�[�̍ŏI�藝" );
//
//			if ( key[ KEY_INPUT_A ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 14 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "���N�̃m�[�x�����w�܂���܂������茧�o�g�̏����ƂƂ����΁H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F��[�N��\n B�F�J�Y�I�E�C�V�O��\n C�F���g����\n D�F�V�C��" );
//
//			if ( key[ KEY_INPUT_B ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 15 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "29�A���̗��ő��L�^��j��ŔN�����m�L�^�Ƃ��ėL���ɂȂ��������̃v�����m�ƌ����Γ���s���ł����A����܂�62�N�Ԃ��j���Ȃ������j��ŔN�����m�ƌ����΁H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�������O\n B�F�n�Ӗ�\n C�F�H���P��\n D�F�J��_�i" );
//
//			if ( key[ KEY_INPUT_A ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 16 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "���E�O�嗿���ƌ����Β��ؗ����A�t�����X�����Ɖ��H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F���{����\n B�F�C�^���A����\n C�F�C���h����\n D�F�g���R����" );
//
//			if ( key[ KEY_INPUT_D ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 17 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "�u���]�������݂ŗL���ɂȂ������E�̒j���̐��́u35��5000���l�v�ł����A2017�N6��21���ɍ��A�����\�������E�̐l���͉����l�H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F35��\n B�F52��\n C�F76��\n D�F87��" );
//
//			if ( key[ KEY_INPUT_C ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 18 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "�����s�[�X�̎�l�����t�B�̕��e�̖��O�́H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F�����L�[�ED�E�h���S��\n B�F�|�[�g�K�X�ED�E�G�[�X\n C�F�}�[�V�����ED�E�e�B�[�`\n D�F�S�[���ED�E���W���[" );
//
//			if ( key[ KEY_INPUT_A ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 19 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "���N�A�j�q100�����œ��{�l����9�b����}�[�N�����l�ƌ����΁H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F����s\n B�F�ː��ˏG\n C�F�P���u���b�W��\n D�F�ђ��đ�" );
//
//			if ( key[ KEY_INPUT_B ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//		case 20 :
//		if ( input == true ) {
//
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "�ȉ��̒��œ����ɂ�����̂͂ǂ�H" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A�F���c��`\n B�F�����f�B�Y�j�[�����h\n C�F�H�c��`\n D�F�����h�C�c��" );
//
//			if ( key[ KEY_INPUT_C ] ) {
//				answer = true;
//				input = false;
//			}
//
//			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
//				not_answer = true;
//				input = false;
//			}
//
//		}
//		break;
//
//	default :
//		break;
//	}
//}

//--����I������֐�
void ChooseWay( ) {
	//���ꂼ��̓��ɓ�Փx��U�蕪����------------------------
	bool a[ DIFFICULTYMAX ] = { false, false, false };
	int count = 0;
	srand( ( unsigned int )time( NULL ) );

	while( !level_randamed ){
		
		int difficulty = rand( ) % WAY_MAX;
		level[ count ] = difficulty;

		if ( !a[ difficulty ] ) { 
			a[ difficulty ] = true;
			count++;
		}

		for ( int i = 0; i < WAY_MAX; i++ ) {
			if ( a[ i ] == false ) break;
			if ( i == WAY_MAX - 1 ) level_randamed = true;
		}
	};
	//-----------------------------------------------------------

	DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "����I�����Ă��������B\n" );
	DrawFormatStringToHandle( SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, cr, font_handle2, "���FX�@�@���FZ�@�@���FV" );
	if ( key[ KEY_INPUT_Z ] ) { 
		way = STRAIGHT_WAY; 
		chooseWayFlag = false;
	}
	else if ( key[ KEY_INPUT_X ] ) {
		way = LEFT_WAY;
		chooseWayFlag = false;
	}
	else if ( key[ KEY_INPUT_V ] ) { 
		way = RIGHT_WAY;
		chooseWayFlag = false;
	}
}