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

			DrawFormatString( 10, 100, GetColor( 255, 255, 255 ), "�킳�т�H�ׂĕ@���c�[���Ƃ������Ɉ��ނƎ��܂���̂́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�R�[��\n B�F��\n C�F���h�X�[�v\n D�F�I�����W�W���[�X" );

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

			DrawFormatString( 10, 100, GetColor( 255, 255, 255 ), "�h��������̐g���́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F120cm\n B�F127.3cm\n C�F129.3cm\n D�F180cm" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�n�`�̐F\n B�F���瓤�̐F\n C�F�킽���߂̐F\n D�F���̐F" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�`���R���[�g\n B�F�Ԃ���\n C�F��������\n D�F�����܃y�[�X�g" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�݂̒��̒j�̎q\n B�F�����u�����̗d��\n C�F���b�v�̂��΂�\n D�F��j�i�C�G�e�B�[�j�̒j�̎q" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�X�[�p�[�T�C���l�S�b�g�X�[�p�[�T�C���l\n B�F�X�[�p�[�T�C���l�O�����h�X�[�p�[�T�C���l\n C�F�X�[�p�[�T�C���l�S�b�e�X�X�[�p�[�T�C���l\n D�F�X�y�V�����T�C���l�S�b�g�X�y�V�����T�C���l" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F����\n B�F�G���M�I�X\n C�F���v�\�[��\n D�F�I���S�f�~�[��" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�W�F�C�\��\n B�F�����q\n C�F�A�z�t\n D�F�g�C���̉Ԏq����" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�g���b�v����\n B�F�h���b�v����\n C�F�h�b�u���[����\n D�F�h�b�v���[����" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F1\n B�F2\n C�F3\n D�F4" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�����\n B�F�����\n C�F���񂽂�\n D�F���񂽂�" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F��v�ۗ���\n B�F��������\n C�F�ɓ�����\n D�F�_�ޏ�" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�O�����̒藝\n B�F���@�藝\n C�F���l���E�X�̒藝\n D�F�t�F���}�[�̍ŏI�藝" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F��[�N��\n B�F�J�Y�I�E�C�V�O��\n C�F���g����\n D�F�V�C��" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�������O\n B�F�n�Ӗ�\n C�F�H���P��\n D�F�J��_�i" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F���{����\n B�F�C�^���A����\n C�F�C���h����\n D�F�g���R����" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F35��\n B�F52��\n C�F76��\n D�F87��" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F�����L�[�ED�E�h���S��\n B�F�|�[�g�K�X�ED�E�G�[�X\n C�F�}�[�V�����ED�E�e�B�[�`\n D�F�S�[���ED�E���W���[" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F����s\n B�F�ː��ˏG\n C�F�P���u���b�W��\n D�F�ђ��đ�" );

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
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), " A�F���c��`\n B�F�����f�B�Y�j�[�����h\n C�F�H�c��`\n D�F�����h�C�c��" );

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