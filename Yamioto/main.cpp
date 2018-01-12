#include "DxLib.h"


const int KEY_MAX = 256;
int key[ KEY_MAX ];
char key_c[ KEY_MAX ];

const int TIME_LIMIT = 30;	//初期制限時間
const int CLEAR = 3;		//必要正解数
const int QUESTION_MAX = 3;	//最大問題数

int sound[ 10 ]; //音楽のハンドル

int flame_count = 0;
int escape_count = 0;	//逃げているフレーム数を数える変数
int time = TIME_LIMIT - 10; //残り時間
int question_num = 0;	//問題番号
int answer_count = -1;	//正解数

bool answer = true;
bool not_answer = false;
bool input = true;


enum GameStatus {
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};
enum GameStatus gamestatus = GAME_START;


int updatekey( ) {
	GetHitKeyStateAll( key_c );

	for ( int i = 0; i < KEY_MAX; i++ ) {
		if ( key_c[ i ] == 1 ) {
			++key[ i ];
		} else {
			key[ i ] = 0;
		}
	}

	return 0;
}



void load_sound( ) {
	sound[ 0 ] = LoadSoundMem( "Sound/asioto.wav" );
	sound[ 1 ] = LoadSoundMem( "Sound/door.wav" );
	sound[ 2 ] = LoadSoundMem( "Sound/playerAsioto.wav" );
	sound[ 3 ] = LoadSoundMem( "Sound/gatyagatya.wav" );
} 


void Initialization( ) {
	flame_count = 0;
	time = TIME_LIMIT - 10;
	answer_count = -1;
	question_num = 0;
	escape_count = 0;
	answer = true;
	not_answer = false;
	input = true;
}


void Question( int num ) {

	switch( num ) {
	case 1 :
		DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 1は？" );
		DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：1 / B：2 / C：3 / D：4" );
		if ( input == true ) {
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
		DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 2は？" );
		DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：1 / B：2 / C：3 / D：4" );
		if ( input == true ) {
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
		DrawFormatString( 100, 100, GetColor( 255, 255, 255 ), "1 + 3は？" );
		DrawFormatString( 100, 120, GetColor( 255, 255, 255 ), "A：1 / B：2 / C：3 / D：4" );
		if ( input == true ) {
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


void GameStart( ) {

	//表示
	DrawString(100, 100, "闇音", GetColor( 255, 255, 255 ) );
	DrawString(100, 150, "PUSH ENTER", GetColor( 255, 255, 255 ) );
	if ( key[ KEY_INPUT_RETURN ] ) {
		gamestatus = GAME_MAIN;
		Initialization( );
	}
		
}


void GameMain( ) {
	//計算
	//初期足音
	if ( CheckSoundMem( sound[ 0 ] ) == 0 ) {
		ChangeVolumeSoundMem( 30, sound[ 0 ] );
		PlaySoundMem( sound[ 0 ], DX_PLAYTYPE_LOOP, TRUE );
	}


	//時間経過で足音の音量を変える
	flame_count++;
	if ( !answer ) {
		time -= flame_count % 61 / 60;
	}
	
	DrawFormatString( 0, 0, GetColor( 255, 0, 0 ), "%d", time );

	if ( time > 20 ) {
		ChangeVolumeSoundMem( 30, sound[ 0 ] );
	}

	if ( time < 20 && time > 10 ) {
		ChangeVolumeSoundMem( 50, sound[ 0 ] );
	}

	if ( time < 10 && time > 0 ) {
		ChangeVolumeSoundMem( 100, sound[ 0 ] );
	}


	//問題に答えたら
	if ( not_answer ) {					//不正解処理

		escape_count++;
		//answer = false;

		if ( escape_count == 200 ) {

			escape_count = 0;
			question_num++;
			input = true;
			not_answer = false;

		}

	}
	
	if ( answer ) {						//正解処理
		//正解したら最初にドアを開ける
		if ( escape_count == 0 && answer_count > -1 ) {
			PlaySoundMem( sound[ 1 ], DX_PLAYTYPE_NORMAL, TRUE );
		}

		//ドアを開け終わったら走り出す
		if ( !CheckSoundMem( sound[ 1 ] ) ) {
			if ( escape_count == 0 ) {
				PlaySoundMem( sound[ 2 ], DX_PLAYTYPE_LOOP, TRUE );
			}
			escape_count++;											
			//not_answer = false;
			time += escape_count % 21 / 20;
		}

		if ( escape_count == 200 ) {
			StopSoundMem( sound[ 2 ] );
			escape_count = 0;
			answer_count++;
			
			if ( answer_count < CLEAR ) {
				PlaySoundMem( sound[ 3 ], DX_PLAYTYPE_NORMAL, TRUE );
				question_num++;
				input = true;
				answer = false;
			} else {
				gamestatus = GAME_RESULT;
			}

		}

	}


	//制限時間が０になったら
	if ( time == 0 ) {
		gamestatus = GAME_RESULT;
	}
	

	//問題のループ
	if ( question_num > QUESTION_MAX ) {
		question_num = 1;
	}

	Question( question_num );
}


void GameResult( ) {
	StopSoundMem( sound[ 0 ] );

	//描画
	if ( answer_count == CLEAR ) {
		DrawString(100, 100, "ゲームクリア！！！", GetColor( 255, 255, 255 ) );
	} else {
		DrawString(100, 100, "ゲームオーバー！！！", GetColor( 255, 0, 0 ) );
	}

	DrawString(100, 150, "PUSH SPACE", GetColor( 255, 255, 255 ) );
	if ( key[ KEY_INPUT_SPACE ] ) {
		gamestatus = GAME_START;
	}

}






int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	ChangeWindowMode( 1 );

	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	//初期化
	load_sound( );

	while ( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 || updatekey( ) != 0) {
			break;
		}

		switch( gamestatus ) {
		case GAME_START :
			GameStart( );
			break;
		case GAME_MAIN :
			GameMain( );
			break;
		case GAME_RESULT :
			GameResult( );
			break;
		}


		if (  key[ KEY_INPUT_ESCAPE ] > 1 ) {
			break;
		}
	}

	DxLib_End( );
	return 0;
}






