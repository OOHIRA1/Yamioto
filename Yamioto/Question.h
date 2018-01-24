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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "わさびを食べて鼻がツーンとした時に飲むと収まるものは？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：コーラ / B：水 / C：激辛スープ / D：オレンジジュース" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "ドラえもんの身長は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：120cm / B：127.3cm / C：129.3cm / D：180cm" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "カバの汗の色は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：墨汁の色 / B：そら豆の色 / C：わたあめの色 / D：血の色" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "アンパンマンの顔の中身は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：チョコレート / B：つぶあん / C：こしあん / D：黒ごまペースト" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "「ひらけポンキッキ」に出てくるムックの正体は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：みの虫の男の子 / B：モンブランの妖精 / C：モップのおばけ / D：雪男（イエティー）の男の子" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "ドラゴンボールの「SSGSS」 何の略？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：スーパーサイヤ人ゴットスーパーサイヤ人 / B：スーパーサイヤ人グランドスーパーサイヤ人 / C：スーパーサイヤ人ゴッテススーパーサイヤ人 / D：スペシャルサイヤ人ゴットスペシャルサイヤ人" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "ドラゴンクエスト８に出てくるボスの名前は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：竜王 / B：エルギオス / C：ラプソーン / D：オルゴデミーラ" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "2016年上映の映画「貞子VS○○」　この貞子と対決したのは？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：ジェイソン / B：伽椰子 / C：陰陽師 / D：トイレの花子さん" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "救急車などの音が近づく場合と遠ざかる場合で聞こえ方が違うことをなんという？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：トラップ効果 / B：ドラップ効果 / C：ドッブラー効果 / D：ドップラー効果" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "「石の上にも○年」　この○に入るのは？" );
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

	default :
		break;
	}
}