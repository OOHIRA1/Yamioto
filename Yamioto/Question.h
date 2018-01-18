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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 1�́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F1 / B�F2 / C�F3 / D�F4" );

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

	case 2 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 2�́H" );
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

	case 3 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 3�́H" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A�F1 / B�F2 / C�F3 / D�F4" );

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

	default :
		break;
	}
}