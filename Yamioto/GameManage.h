#pragma once

#include "Const.h"
#include "Question.h"

enum GameStatus gamestatus = GAME_START;

int flame_count = 0;
int time = TIME_LIMIT - 10; //残り時間
int escape_count = 0;	//逃げているフレーム数を数える変数
int answer_count = -1;	//正解数
bool sounded = false; 

void Initialization( );
void Judge( );
void EnemySound( );

void GameStart( );
void GameMain( );
void GameResult( );


void Initialization( ) {
	flame_count = 0;
	time = TIME_LIMIT - 10;
	answer_count = -1;
	question_num = 0;
	escape_count = 0;
	answer = true;
	not_answer = false;
	input = true;
	sounded = false;
}

void Judge( ) {

	if ( not_answer ) {	//不正解処理

		if ( escape_count == 0 ) {
			Psound( sound[5], BACK );
		}

		escape_count++;

		if ( escape_count == 200 ) {
			escape_count = 0;
			question_num++;

			input = true;
			not_answer = false;
		}

	}

	if ( answer ) {						//正解処理
										//正解したら最初に正解音を鳴らす。そのあとにドアの開閉音を鳴らす
		if ( escape_count == 0 && answer_count > -1 ) {
			Psound( sound[4], NORMAL );
			Psound( sound[1], NORMAL );
		}

		//正解音とドアの開閉音が鳴り終わったら走り出す
		if ( escape_count == 0 ) {
			Psound( sound[2], LOOP );
		}

		escape_count++;
		time += escape_count % 21 / 20;

		if ( escape_count == 200 ) {
			Ssound( sound[2] );
			escape_count = 0;
			answer_count++;

			if ( answer_count < CLEAR ) {
				Psound( sound[3], NORMAL );
				question_num++;

				input = true;
				answer = false;
			} else {
				gamestatus = GAME_RESULT;
			}

		}

	}

}

void EnemySound( ) {

	if ( time > 20 ) {
		Vsound( 30, sound[0] );
	}

	if ( time < 20 && time > 10 ) {
		Vsound( 50, sound[0] );
	}

	if ( time < 10 && time > 0 ) {
		Vsound( 100, sound[0] );
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

	//初期足音
	if ( Csound( sound[ 0 ] ) == 0 ) {
		Vsound( 30, sound[0] );
		Psound( sound[0], LOOP );
	}

	//時間を進める
	flame_count++;
	if ( !answer ) {
		time -= flame_count % 61 / 60;
	}
	
	DrawFormatString( 0, 0, GetColor( 255, 0, 0 ), "%d", time );

	//時間経過で足音の音量を変える																	
	EnemySound( );

	//問題に答えたら
	Judge( );

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
	Ssound( sound[0] );

	//描画
	if ( answer_count == CLEAR ) {
		DrawString( 100, 100, "ゲームクリア！！！", GetColor( 255, 255, 255 ) );

		if ( !sounded ) {
			Psound( sound[6], BACK );
			sounded = true;
		}

	} else {
		DrawString( 100, 100, "ゲームオーバー！！！", GetColor( 255, 0, 0 ) );
		DrawGraph( 100, 110, resource[ 0 ], TRUE );

		if ( !sounded ) {
			Psound( sound[7], BACK );
			sounded = true;
		}

	}

	DrawString( 100, 150, "PUSH SPACE", GetColor( 255, 255, 255 ) );
	if ( key[ KEY_INPUT_SPACE ] ) {
		gamestatus = GAME_START;
	}

}
