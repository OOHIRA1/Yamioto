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

		case 11 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�u���l�̋C�����������͂���v�Ƃ����Ӗ��̌��t�u�u�x�v�B���ƓǂށH" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F����� / B�F����� / C�F���񂽂� / D�F���񂽂�" );

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

		case 12 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "��C�푈�A����푈�ŗL���ȍ��N�̑�̓h���}�Ŏ��グ��ꂽ�l���Ƃ����΁H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F��v�ۗ��� / B�F�������� / C�F�ɓ����� / D�F�_�ޏ�" );

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

		case 13 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "���p�O�p�`�̎ΕӒ�����2��͑��̓�ӂ�2��̘a�ɓ������B���̒藝�����Ƃ������H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�O�����̒藝 / B�F���@�藝 / C�F���l���E�X�̒藝 / D�F�t�F���}�[�̍ŏI�藝" );

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

		case 14 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "���N�̃m�[�x�����w�܂���܂������茧�o�g�̏����ƂƂ����΁H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F��[�N�� / B�F�J�Y�I�E�C�V�O�� / C�F���g���� / D�F�V�C��" );

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

		case 15 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "29�A���̗��ő��L�^��j��ŔN�����m�L�^�Ƃ��ėL���ɂȂ��������̃v�����m�ƌ����Γ���s���ł����A����܂�62�N�Ԃ��j���Ȃ������j��ŔN�����m�ƌ����΁H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�������O / B�F�n�Ӗ� / C�F�H���P�� / D�F�J��_�i" );

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

		case 16 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "���E�O�嗿���ƌ����Β��ؗ����A�t�����X�����Ɖ��H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F���{���� / B�F�C�^���A���� / C�F�C���h���� / D�F�g���R����" );

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

		case 17 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�u���]�������݂ŗL���ɂȂ������E�̒j���̐��́u35��5000���l�v�ł����A2017�N6��21���ɍ��A�����\�������E�̐l���͉����l�H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F35�� / B�F52�� / C�F76�� / D�F87��" );

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

		case 18 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�����s�[�X�̎�l�����t�B�̕��e�̖��O�́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F�����L�[�ED�E�h���S�� / B�F�|�[�g�K�X�ED�E�G�[�X / C�F�}�[�V�����ED�E�e�B�[�` / D�F�S�[���ED�E���W���[" );

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

		case 19 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "���N�A�j�q100�����œ��{�l����9�b����}�[�N�����l�ƌ����΁H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F����s / B�F�ː��ˏG / C�F�P���u���b�W�� / D�F�ђ��đ�" );

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

		case 20 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "�ȉ��̒��œ����ɂ�����̂͂ǂ�H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F���c��` / B�F�����f�B�Y�j�[�����h / C�F�H�c��` / D�F�����h�C�c��" );

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