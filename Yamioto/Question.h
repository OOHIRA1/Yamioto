#pragma once

#include "DxLib.h"
#include "Key.h"

int question_num = 0;	//問題番号
bool answer = true;
bool not_answer = false;
bool input = true;

void Question( int num ) {

	switch( num ) {
	case 1 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 1は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：1 / B：2 / C：3 / D：4" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 2は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：1 / B：2 / C：3 / D：4" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 3は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：1 / B：2 / C：3 / D：4" );

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