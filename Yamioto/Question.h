#pragma once

#include "DxLib.h"
#include <time.h>
/*
参照しているヘッダー
#include "Input.h"
#include "Load.h"
*/

int question_num;	//問題番号
int exercise_books_num;	//問題集の番号

bool answer;			//正解したかどうかのフラグ
bool not_answer;		//不正解かどうかのフラグ
bool input;				//入力を受け付けるかどうかのフラグ
bool chooseWayFlag;		//道を選んでいるかどうかフラグ
bool q_finished[ 3 ][ QUESTION_MAX ]; //問題集（難易度）の数と問題数 //問題が出たかどうかを判定する変数

int font_handle;		//問題文フォントハンドル
int font_handle2;		//選択肢フォントハンドル
int cr;					//問題文の色
int cr2;				//選択肢の色

int selectedSentence;	//カーソルの位置

enum Way way;	//選んだ道
int level[ WAY_MAX ];	//道選択時の難易度
bool level_randamed;	//道選択時に各道にランダムで難易度を割り振ったかどうかのフラグ

void QuesitionInitialize( );
void Question( int, int );
void Question1( int );
void Question2( int );
void Question3( int );
void ChooseWay( );

void changeColor( int selectedchoice, char* string, int color ) {
	DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CURSOR_SELECT_POS_Y * selectedchoice ), color, font_handle2, string );
}



//--Question.hの変数を初期化する関数
void QuesitionInitialize( ) {
	question_num = 1;
	exercise_books_num = 0;

	answer = false;
	not_answer = false;
	input = false;
	chooseWayFlag = true;
	way = NOT_CHOOSE_WAY;
	font_handle = CreateFontToHandle( "ＭＳ 明朝", 20, 5 );
	font_handle2 = CreateFontToHandle( "ＭＳ 明朝", 20, 3 );
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

////--カーソルを表示する関数(キーボード対応)
//void KeybordCursor( ) {
//	DrawCircle( CHOICES_POS_X - 20, CHOICES_POS_Y + 10 + ( CURSOR_SELECT_POS_Y * selectedSentence ), 5, cr, true );
//	//DrawGraph( CHOICES_POS_X - 10, CHOICES_POS_Y + 5 + ( CURSOR_SELECT_POS_Y * selectedSentence ), resource[ 4 ], TRUE );
//	if ( key[ KEY_INPUT_DOWN ] == 1 && selectedSentence < 3 ) {	//一番下に来たらそれ以上進まない //選択肢が４つあるので4 - 1
//		selectedSentence++;
//	}
//
//	if ( key[ KEY_INPUT_UP ] == 1 && selectedSentence > 0 ) {	//一番下に来たらそれ以上進まない //選択肢が４つあるので4 - 1
//		selectedSentence--;
//	}
//}

//--カーソルを表示する関数(ジョイパット対応)
void JoypadCursor( ) { 
	DrawCircle( CHOICES_POS_X - 20, CHOICES_POS_Y + 11 + ( CURSOR_SELECT_POS_Y * selectedSentence ), 5, cr, true );
	//DrawGraph( CHOICES_POS_X - 10, CHOICES_POS_Y + 5 + ( CURSOR_SELECT_POS_Y * selectedSentence ), resource[ 4 ], TRUE );

	if ( joypad[ DOWN ] == 1 && selectedSentence < 3 ) {	//一番下に来たらそれ以上進まない //選択肢が４つあるので4 - 1
		selectedSentence++;
	}

	if ( joypad[ UP ] == 1 && selectedSentence > 0 ) {	//一番下に来たらそれ以上進まない //選択肢が４つあるので4 - 1
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
		for ( int i = 0; i < 3; i++ ) {		//問題文表示
			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), cr, font_handle, q_load[ EASY ].questionStatement[ i + ( num - 1 ) * 3 ] );
		}
		
		for ( int i = 0; i < 4; i++ ) {		//選択肢表示
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
		for ( int i = 0; i < 3; i++ ) {		//問題文表示
			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), cr, font_handle, q_load[ BASIC ].questionStatement[ i + ( num - 1 ) * 3 ] );
		}
		
		for ( int i = 0; i < 4; i++ ) {		//選択肢表示
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
		for ( int i = 0; i < 3; i++ ) {		//問題文表示
			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), cr, font_handle, q_load[ HARD ].questionStatement[ i + ( num - 1 ) * 3 ] );
		}
		
		for ( int i = 0; i < 4; i++ ) {		//選択肢表示
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"カバの汗の色は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：墨汁の色\n B：そら豆の色\n C：わたあめの色\n D：血の色" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"ドラえもんの身長は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：120cm\n B：127.3cm\n C：129.3cm\n D：180cm" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"カバの汗の色は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：墨汁の色\n B：そら豆の色\n C：わたあめの色\n D：血の色" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"アンパンマンの顔の中身は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：チョコレート\n B：つぶあん\n C：こしあん\n D：黒ごまペースト" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"「ひらけポンキッキ」に出てくるムックの正体は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：みの虫の男の子\n B：モンブランの妖精\n C：モップのおばけ\n D：雪男（イエティー）の男の子" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"ドラゴンボールの「SSGSS」 何の略？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：スーパーサイヤ人ゴットスーパーサイヤ人\n B：スーパーサイヤ人グランドスーパーサイヤ人\n C：スーパーサイヤ人ゴッテススーパーサイヤ人\n D：スペシャルサイヤ人ゴットスペシャルサイヤ人" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"ドラゴンクエスト８に出てくるボスの名前は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：竜王\n B：エルギオス\n C：ラプソーン\n D：オルゴデミーラ" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"2016年上映の映画「貞子VS○○」　この貞子と対決したのは？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：ジェイソン\n B：伽椰子\n C：陰陽師\n D：トイレの花子さん" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"救急車などの音が近づく場合と遠ざかる場合で聞こえ方が違うことをなんという？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：トラップ効果\n B：ドラップ効果\n C：ドッブラー効果\n D：ドップラー効果" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"「石の上にも○年」　この○に入るのは？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：1\n B：2\n C：3\n D：4" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"「他人の気持ちをおしはかる」という意味の言葉「忖度」。何と読む？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：すんど\n B：そんど\n C：そんたく\n D：すんたく" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle ,"戊辰戦争、西南戦争で有名な今年の大河ドラマで取り上げられた人物といえば？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：大久保利通\n B：西郷隆盛\n C：伊藤博文\n D：板垣退助" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle,"直角三角形の斜辺長さの2乗は他の二辺の2乗の和に等しい。この定理を何というか？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：三平方の定理\n B：加法定理\n C：メネラウスの定理\n D：フェルマーの最終定理" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "去年のノーベル文学賞を受賞した長崎県出身の小説家といえば？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：川端康成\n B：カズオ・イシグロ\n C：又吉直樹\n D：新海誠" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "29連勝の歴代最多記録や史上最年少棋士記録として有名になった将棋のプロ棋士と言えば藤井壮太ですが、それまで62年間も破られなかった史上最年少棋士と言えば？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：加藤一二三\n B：渡辺明\n C：羽生善治\n D：谷川浩司" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "世界三大料理と言えば中華料理、フランス料理と何？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：日本料理\n B：イタリア料理\n C：インド料理\n D：トルコ料理" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "ブルゾンちえみで有名になった世界の男性の数は「35億5000万人」ですが、2017年6月21日に国連が発表した世界の人口は何億人？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：35億\n B：52億\n C：76億\n D：87億" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "ワンピースの主人公ルフィの父親の名前は？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：モンキー・D・ドラゴン\n B：ポートガス・D・エース\n C：マーシャル・D・ティーチ\n D：ゴール・D・ロジャー" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "去年、男子100ｍ走で日本人初の9秒台をマークした人と言えば？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：武井壮\n B：桐生祥秀\n C：ケンブリッジ飛鳥\n D：飯塚翔太" );
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
//			DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "以下の中で東京にあるものはどれ？" );
//			DrawFormatStringToHandle( CHOICES_POS_X, CHOICES_POS_Y, cr, font_handle2, " A：成田空港\n B：東京ディズニーランド\n C：羽田空港\n D：東京ドイツ村" );
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

//--道を選択する関数
void ChooseWay( ) {
	//それぞれの道に難易度を振り分ける------------------------
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

	DrawFormatStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, cr, font_handle, "道を選択してください。\n" );
	DrawFormatStringToHandle( SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, cr, font_handle2, "←：X　　↑：Z　　→：V" );
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