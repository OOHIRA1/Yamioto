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

		case 11 :
		if ( input == true ) {

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "「他人の気持ちをおしはかる」という意味の言葉「忖度」。何と読む？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：すんど / B：そんど / C：そんたく / D：すんたく" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "戊辰戦争、西南戦争で有名な今年の大河ドラマで取り上げられた人物といえば？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：大久保利通 / B：西郷隆盛 / C：伊藤博文 / D：板垣退助" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "直角三角形の斜辺長さの2乗は他の二辺の2乗の和に等しい。この定理を何というか？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：三平方の定理 / B：加法定理 / C：メネラウスの定理 / D：フェルマーの最終定理" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "去年のノーベル文学賞を受賞した長崎県出身の小説家といえば？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：川端康成 / B：カズオ・イシグロ / C：又吉直樹 / D：新海誠" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "29連勝の歴代最多記録や史上最年少棋士記録として有名になった将棋のプロ棋士と言えば藤井壮太ですが、それまで62年間も破られなかった史上最年少棋士と言えば？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：加藤一二三 / B：渡辺明 / C：羽生善治 / D：谷川浩司" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "世界三大料理と言えば中華料理、フランス料理と何？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：日本料理 / B：イタリア料理 / C：インド料理 / D：トルコ料理" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "ブルゾンちえみで有名になった世界の男性の数は「35億5000万人」ですが、2017年6月21日に国連が発表した世界の人口は何億人？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：35億 / B：52億 / C：76億 / D：87億" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "ワンピースの主人公ルフィの父親の名前は？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：モンキー・D・ドラゴン / B：ポートガス・D・エース / C：マーシャル・D・ティーチ / D：ゴール・D・ロジャー" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "去年、男子100ｍ走で日本人初の9秒台をマークした人と言えば？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：武井壮 / B：桐生祥秀 / C：ケンブリッジ飛鳥 / D：飯塚翔太" );

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

			DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "以下の中で東京にあるものはどれ？" );
			DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：成田空港 / B：東京ディズニーランド / C：羽田空港 / D：東京ドイツ村" );

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