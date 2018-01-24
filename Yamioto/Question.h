#pragma once

#include "DxLib.h"
#include "Key.h"

int question_num = 0;	//���ԍ�
bool answer = true;
bool not_answer = false;
bool input = true;

void Question( int num ) {

	switch( num ) {
	case 1 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�킳�т�H�ׂĕ@���c�[���Ƃ������Ɉ��ނƎ��܂���̂́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�R�[�� / B�F�� / C�F���h�X�[�v / D�F�I�����W�W���[�X" );

			if ( key[ KEY_INPUT_A ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}
		}
		break;

	case 2 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�h��������̐g���́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F120cm / B�F127.3cm / C�F129.3cm / D�F180cm" );

			if ( key[ KEY_INPUT_C ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

	case 3 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�J�o�̊��̐F�́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�n�`�̐F / B�F���瓤�̐F / C�F�킽���߂̐F / D�F���̐F" );

			if ( key[ KEY_INPUT_D ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 4 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�A���p���}���̊�̒��g�́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�`���R���[�g / B�F�Ԃ��� / C�F�������� / D�F�����܃y�[�X�g" );

			if ( key[ KEY_INPUT_B ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 5 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�u�Ђ炯�|���L�b�L�v�ɏo�Ă��郀�b�N�̐��̂́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�݂̒��̒j�̎q / B�F�����u�����̗d�� / C�F���b�v�̂��΂� / D�F��j�i�C�G�e�B�[�j�̒j�̎q" );

			if ( key[ KEY_INPUT_D ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 6 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�h���S���{�[���́uSSGSS�v ���̗��H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�X�[�p�[�T�C���l�S�b�g�X�[�p�[�T�C���l / B�F�X�[�p�[�T�C���l�O�����h�X�[�p�[�T�C���l / C�F�X�[�p�[�T�C���l�S�b�e�X�X�[�p�[�T�C���l / D�F�X�y�V�����T�C���l�S�b�g�X�y�V�����T�C���l" );

			if ( key[ KEY_INPUT_A ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 7 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�h���S���N�G�X�g�W�ɏo�Ă���{�X�̖��O�́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F���� / B�F�G���M�I�X / C�F���v�\�[�� / D�F�I���S�f�~�[��" );

			if ( key[ KEY_INPUT_C ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 8 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "2016�N��f�̉f��u��qVS�����v�@���̒�q�ƑΌ������̂́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�W�F�C�\�� / B�F�����q / C�F�A�z�t / D�F�g�C���̉Ԏq����" );

			if ( key[ KEY_INPUT_B ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_C ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 9 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�~�}�ԂȂǂ̉����߂Â��ꍇ�Ɖ�������ꍇ�ŕ����������Ⴄ���Ƃ��Ȃ�Ƃ����H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�g���b�v���� / B�F�h���b�v���� / C�F�h�b�u���[���� / D�F�h�b�v���[����" );

			if ( key[ KEY_INPUT_D ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_C ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

		case 10 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�u�΂̏�ɂ����N�v�@���́��ɓ���̂́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F1 / B�F2 / C�F3 / D�F4" );

			if ( key[ KEY_INPUT_C ] ) {
				answer = true;
				input = false;
			}

			if ( key[ KEY_INPUT_A ] || key[ KEY_INPUT_B ] || key[ KEY_INPUT_D ] ) {
				not_answer = true;
				input = false;
			}

		}
		break;

	default :
		break;
	}
}