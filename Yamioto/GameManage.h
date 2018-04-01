#pragma once

/*
参照しているヘッダー
#include "Const.h"
*/
#include "Question.h"
#include "Player.h"
#include "Enemy.h"
#include <time.h>
#include <math.h>

enum GameStatus gamestatus = GAME_START;

bool initialized = false;			//初期化を一回だけ行うため

int bright;					//点滅の透明度
bool bright_max;			//透明度が最大になったかどうか

int flame_count;			//フレーム数
int distance;				//残り距離 
int escape_count;			//逃げているフレーム数を数える変数
bool sounded;				//音を一回だけならすため
int gameover_wait_count;	//ゲームオーバーの間

int p_pos_index;			//playerが入れるpre_posの添字番号
int e_pos_index;			//enemyが入れるpre_posの添字番号

int whited;					//スタート画面の文字の白さ
bool pushed;				//キーを押したかどうか

struct fps {
	short int start;
	short int flame;
	float save;
};
struct fps fps_counter;

bool debug = false;			//デバックモード


int leftUp_light_x, leftUp_light_y,		//クリア直前の光
	rightUp_light_x, rightUp_light_y, 
	rightDown_light_x, rightDown_light_y, 
	leftDown_light_x, leftDown_light_y;

void Initialization( );
void debugdraw( );
void Action( );

void GameStart( );
void GameMain( );
void GameResult( );

VECTOR operator-( VECTOR& vecA, VECTOR& vecB );
bool operator==( VECTOR& vec, float num );

struct Player player;
struct Enemy enemy;

VECTOR operator-( VECTOR& vecA, VECTOR& vecB ) {
	VECTOR vec;
	vec.x = vecA.x - vecB.x;
	vec.y = vecA.y - vecB.y;
	vec.z = vecA.z - vecB.z;
	return vec;
}

bool operator==( VECTOR& vec, float num ) {
	return ( vec.x == num && vec.y == num && vec.z == num );
}

void Initialization( ) {

	PlayerInitialize( &player );
	EnemyInitialize( &enemy );
	QuesitionInitialize( );
	SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
	SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );
	SetRadius( 60, sound[ ENEMY_VOICE ] );

	flame_count = 0;
	distance = FIRST_DISTANCE;
	escape_count = 0;
	gameover_wait_count = 0;

	bright = 0;
	bright_max = true;

	p_pos_index = 1;	//player.pre_pos[ 0 ]は最初の値を格納済み(player.pre_pos[ 0 ]を上書きしないため)
	e_pos_index = 0;

	leftUp_light_x = SCREEN_WIDTH_CENTER;
	leftUp_light_y = SCREEN_HEIGHT_CENTER;
	rightUp_light_x = SCREEN_WIDTH_CENTER;
	rightUp_light_y = SCREEN_HEIGHT_CENTER;
	rightDown_light_x = SCREEN_WIDTH_CENTER;
	rightDown_light_y = SCREEN_HEIGHT_CENTER;
	leftDown_light_x = SCREEN_WIDTH_CENTER;
	leftDown_light_y = SCREEN_HEIGHT_CENTER;

	sounded = false;

	whited = 255;
	pushed = false;
}


void debugdraw( ) {

	float Ex = SCREEN_WIDTH * ( float )0.5 + enemy.position.x - 8;
	float Px = SCREEN_WIDTH * ( float )0.5 + player.position.x - 8;
	DrawBoxAA( Ex, ( SCREEN_HEIGHT - ( enemy.position.z + 8 ) ), Ex + 16, ( SCREEN_HEIGHT - ( enemy.position.z - 8 ) ), 0xffffff, TRUE );
	DrawBoxAA( Px, ( SCREEN_HEIGHT - ( player.position.z + 8 ) ), Px + 16, ( SCREEN_HEIGHT - ( player.position.z - 8 ) ), 0x0000ff, TRUE );

	//残り距離を描画------------------------------------------------------
	DrawFormatString( 0, 0, 0xffffff, "エネミーとの距離：%d", distance );
	//--------------------------------------------------------------------

	//正解数 / 最大正解数を描画---------------------------------------------------------------------
	DrawFormatString( 0, 20, 0xffffff, "正解数 / 最大正解数：%d / %d", player.answer_count, CLEAR );
	//----------------------------------------------------------------------------------------------

	//q_finishedを描画---------------------------------------------------------------------------------
	for ( int i = 0; i < DIFFICULTYMAX; i++ ) {

		for ( int j = 0; j < QUESTION_MAX; j++ ) {
			int color = 0xffffff;
			if ( q_finished[ i ][ j ] ) color = 0xffff00;
			
			DrawFormatString( 0 + ( i * 20 ), ( j * 20 ) + 40, color, "%d", q_finished[ i ][ j ] );
		}

	}
	//-------------------------------------------------------------------------------------------------

	//fpsを描画--------------------------------------------------
	time_t timer;
	struct tm local_time;
	time( &timer );
	localtime_s( &local_time,  &timer );
	if ( fps_counter.start != local_time.tm_sec ) {
		short int dif = local_time.tm_sec - fps_counter.start;
		if ( dif < 0 ) {
			dif += 60;
		}
		fps_counter.start = local_time.tm_sec;
		fps_counter.save = fps_counter.flame / ( float )dif;
		fps_counter.flame = 0;
	}
	DrawFormatString( 1000, 0, 0xffffff, "fps : %f", fps_counter.save );
	fps_counter.flame++;
	//------------------------------------------------------------

	//p_pos配列を描画-------------------------------------------------------------------------------------------------------------------------------------
	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		int color = 0xffffff;
		if ( i == p_pos_index - 1 ) {
			color = 0x0000ff;
		}
		if ( i == e_pos_index ) {
			color = 0xff0000;
		}
		DrawFormatString( 50, 40 + ( i * 20 ), color, "( %5.1f, %5.1f, %5.1f )", player.pre_pos[ i ].x, player.pre_pos[ i ].y, player.pre_pos[ i ].z );
	}
	//----------------------------------------------------------------------------------------------------------------------------------------------------

	//enemy.positionを描画-----------------------------------------------------------------------------------------------------------------
	DrawFormatString( 500, 0, 0xffffff, "enemy.position : ( %5.1f, %5.1f, %5.1f )", enemy.position.x, enemy.position.y, enemy.position.z );
	//-------------------------------------------------------------------------------------------------------------------------------------

	//player.positionを描画-----------------------------------------------------------------------------------------------------------------
	DrawFormatString( 500, 20, 0xffffff, "player.position : ( %5.1f, %5.1f, %5.1f )", player.position.x, player.position.y, player.position.z );
	//-------------------------------------------------------------------------------------------------------------------------------------
}

//--プレイヤーの行動を表す関数
void Action( ) {
	if ( !chooseWayFlag && !input && !answer && !not_answer  ) {			//道を選んで問題表示してないときの処理			

		//走り出す----------------------------------
		if ( escape_count == 0 ) {
			Vsound( sound[ PLAYER_ASIOTO ], 100 );
			Psound( sound[ PLAYER_ASIOTO ], LOOP );
		}
		//------------------------------------------

		//道選択時の動き----------------------------------------------------------------------
		switch ( way ) {
		case STRAIGHT_WAY:
			player.position.z += escape_count % 21 / 20;
			break;

		case RIGHT_WAY:
			player.position.x += escape_count % 21 / 20;
			player.direction = VGet( 1, 0, 0 );
			SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
			break;

		case LEFT_WAY:
			player.position.x -= escape_count % 21 / 20;
			player.direction = VGet( -1, 0, 0 );
			SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
			break;
		}
		//-------------------------------------------------------------------------------------

		
		escape_count++;							//道を選んで走っている間

		//走り終えたら-----------------------------------------------------------------------------
		if ( escape_count == 200 ) {
			Ssound( sound[ PLAYER_ASIOTO ] );													//足跡を止める
			Vsound( sound[ DOOR_GATYA ], 100 );
			Psound( sound[ DOOR_GATYA ], NORMAL );												//ドアの音を鳴らす

			escape_count = 0;																	//カウントをリセット

			player.direction = VGet( 0, 0, 1 );													//プレイヤーの向きを前にする
			SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );

			input = true;																		//入力を受け付ける

			//プレイヤーの座標をいれる-----------------------------
			player.pre_pos[ p_pos_index ] = player.position;
			p_pos_index = ( p_pos_index + 1 ) % PRE_POS_MAX_INDEX;								//数値を0～29で繰り返す
			//-----------------------------------------------------

		}
		//-----------------------------------------------------------------------------------------
	}
	




	if ( not_answer ) {	//不正解処理

		//不正解した最初の処理-----------------
		if ( escape_count == 0 ) {
			Vsound( sound[ MATIGAI ], 100 );
			Psound( sound[ MATIGAI ], NORMAL );
			player.not_answer_count++;
		}
		//-------------------------------------

		escape_count++;

		//ペナルティが終了したら------------------------------------------------------------------------------
		if ( escape_count == 200 ) {

			escape_count = 0;
			
			q_finished[ exercise_books_num ][ question_num - 1 ] = true;	//出た問題にフラグを立てる

			//全ての問題が出たらリセットする-----------------------------------
			for ( int i = 0; i < QUESTION_MAX; i++ ) {

				if ( !q_finished[ exercise_books_num ][ i ] ) break;

				if ( i == QUESTION_MAX - 1 ) {
					for ( int j = 0; j < QUESTION_MAX; j++ ) {
						q_finished[ exercise_books_num ][ j ] = false;
					}
				}
			}
			//-----------------------------------------------------------------

			RandamQuestion( );	//問題のランダム処理

			selectedSentence = 0;
			input = true;
			not_answer = false;

		}
		//------------------------------------------------------------------------------------------------------
	}




	if ( answer ) {						//正解処理			
		//正解したら最初に正解音を鳴らす。そのあとにドアの開閉音を鳴らす-----------
		if ( escape_count == 0 && player.answer_count > -1 ) {			
			Vsound( sound[ SEIKAI ], 100 );
			Psound( sound[ SEIKAI ], NORMAL );
			Vsound( sound[ DOOR ], 100 );
			Psound( sound[ DOOR ], NORMAL );
		}
		//-------------------------------------------------------------------------

		//正解音とドアの開閉音が鳴り終わったら走り出す---------
		if ( escape_count == 0 ) {
			Vsound( sound[ PLAYER_ASIOTO ], 100 );
			Psound( sound[ PLAYER_ASIOTO ], LOOP );
		}
		//-----------------------------------------------------
			
		escape_count++;
		
		player.position.z += escape_count % 21 / 20;
		SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
		

		//脱出直前の画像表示---------------------------------------------------------------------------------------------------------------------
		if ( player.answer_count == CLEAR - 1 ) {
			DrawModiGraph(	leftUp_light_x    -= RATE_X, leftUp_light_y    -= RATE_Y, 
							rightUp_light_x   += RATE_X, rightUp_light_y   -= RATE_Y, 
							rightDown_light_x += RATE_X, rightDown_light_y += RATE_Y,	
							leftDown_light_x  -= RATE_X, leftDown_light_y  += RATE_Y,
							resource[ 1 ], TRUE );
		}
		//---------------------------------------------------------------------------------------------------------------------------------------


		
		
		//走り終わったら-------------------------------------------------------------------------
		if ( escape_count == 200 ) {
			Ssound( sound[ PLAYER_ASIOTO ] );
			escape_count = 0;
			player.answer_count++;

			if ( player.answer_count < CLEAR ) {	//player.answer_countが必要正解数以下のとき

				q_finished[ exercise_books_num ][ question_num - 1 ] = true;				//出た問題にフラグを立てる

				//全ての問題が出たらリセットする---------------------------------------
				for ( int i = 0; i < QUESTION_MAX; i++ ) {

					if ( !q_finished[ exercise_books_num ][ i ] ) break;

					if ( i == QUESTION_MAX - 1 ) {
						for ( int j = 0; j < QUESTION_MAX; j++ ) {
							q_finished[ exercise_books_num ][ j ] = false;
						}
					}
				}
				//-----------------------------------------------------------------------


				

				//プレイヤーの座標をいれる----------------------------
				player.pre_pos[ p_pos_index ] = player.position;
				p_pos_index = ( p_pos_index + 1 ) % PRE_POS_MAX_INDEX; //数値を0～29で繰り返す
				//----------------------------------------------------


				selectedSentence = 0;
				input = false;
				level_randamed = false;	//道に難易度を振り分けられるようにする
				answer = false;
				chooseWayFlag = true;	//道を選べるようにする
			} else {
				gamestatus = GAME_RESULT;
			}
			
		}
		//-------------------------------------------------------------------------------------------------------------------------------------
	}
}


void GameStart( ) {
	if ( !initialized ) {
		Initialization( );
		initialized = true;
	}


	//スタート画面ＢＧＭ-----------------------------
	if ( !Csound( sound[ GAME_START_BGM ] ) && !sounded ) {
		Vsound( sound[ GAME_START_BGM ], 100 );
		Psound( sound[ GAME_START_BGM ], LOOP );
		sounded = true;
	}
	//-----------------------------------------------

	//タイトル表示-------------------------------------------------------------------------------------------
	DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER - 50, "闇音", GetColor( whited, whited, whited ) );
	DrawString( SCREEN_WIDTH_CENTER - 90, SCREEN_HEIGHT_CENTER, "PRESS BUTTON", GetColor( whited, whited, whited ) );
	//-------------------------------------------------------------------------------------------------------

	//キー受付-------------------------------------------------------------------------------------------------------------------------------------------
	if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_1 ] == 1 || joypad[ INPUT_2 ] == 1 || joypad[ INPUT_3 ] == 1 || joypad[ INPUT_4 ] == 1 ) {
		Ssound( sound[ GAME_START_BGM ] );
		Vsound( sound[ GAME_START_SE ], 80 );
		Psound( sound[ GAME_START_SE ], BACK );
		pushed = true;
		
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------

	//キー入力後の処理------------------
	if ( pushed ) {
		if ( whited > 0 ) whited -= 2;
		if ( whited < 0 ) whited = 0;
		

		if ( whited <= 0 ) {
			Ssound( sound[ GAME_START_SE ] );
			gamestatus = GAME_MAIN;
			initialized = false;
			sounded = false;		//GameResultにも使用するためfalseに戻す
		}

	}
	//----------------------------------

}

void GameMain( ) {
	//ゲームメインＢＧＭ-----------------------
	if ( !Csound( sound[ GAME_MAIN_BGM ] ) ) {
		Vsound( sound[ GAME_MAIN_BGM ], 100 );
		Psound( sound[ GAME_MAIN_BGM ], LOOP );
	}
	//-----------------------------------------

	//初期歌声-----------------------------------
	if ( !Csound( sound[ ENEMY_VOICE ] ) ) {
		Psound( sound[ ENEMY_VOICE ], LOOP );
		Vsound( sound[ ENEMY_VOICE ], 255 );
	}
	//-------------------------------------------

	//距離が縮まる-------------------------------------------------------------------
	flame_count++;
	distance = ( int )( ( player.position.z - enemy.position.z ) + fabs( player.position.x - enemy.position.x ) );	//プレイヤーとエネミーの距離の計算
	if ( !answer || chooseWayFlag ) {	//問題を答えていないとき または　道を選んでいないとき
		float x_diff = player.pre_pos[ e_pos_index ].x - enemy.position.x;
		

		if ( ( player.pre_pos[ e_pos_index ] - enemy.position ) == 0 ){
			e_pos_index = ( e_pos_index + 1 ) % PRE_POS_MAX_INDEX;
		}

		switch( player.not_answer_count ) {
		case 0:
			if ( x_diff < 0 ) {
				enemy.position.x -= flame_count % 61 / 60;
			} else if ( x_diff > 0 ){
				enemy.position.x += flame_count % 61 / 60;
			} else {
				enemy.position.z += flame_count % 61 / 60;
			}
			break;

		case 1:
			if ( x_diff < 0 ) {
				enemy.position.x -= flame_count % 46 / 45;
			} else if ( x_diff > 0 ){
				enemy.position.x += flame_count % 46 / 45;
			} else {							  
				enemy.position.z += flame_count % 46 / 45;
			}
			break;

		default:
			if ( x_diff < 0 ) {
				enemy.position.x -= flame_count % 31 / 30;
			} else if ( x_diff > 0 ){
				enemy.position.x += flame_count % 31 / 30;
			} else {							  
				enemy.position.z += flame_count % 31 / 30;
			}
			break;
		}

		SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );
	}
	//----------------------------------------------------------------------------------

	//道選択---------------
	if ( chooseWayFlag ) {
		ChooseWay( );
	}
	//----------------------

	//問題の難易度表示--------------------------------
	if ( !chooseWayFlag && !answer && !not_answer ) {
		DisplayLevel( );
	}
	//------------------------------------------------

	//時間に合わせて画面を赤くしていく------------------------------
	int r = bright;
	int g = bright;
	int b = bright;

	if ( distance > 30 ) {

		if ( bright > 0 ) bright--;
		
	} else if ( distance > 20 && distance <= 30 ) {

		if ( bright > 100 ) {
			bright--;
		} else {
			bright++;
		}
	
	} else if ( distance > 10 && distance <= 20 ) {

		if ( bright < 255 ) bright++;

	} else {
		
		if ( bright > 255  ) {
			bright_max = true;
		} else if ( bright < 0 ) {
			bright_max = false;
		} 

		if ( !bright_max ) {
			bright += 5;
		} else {
			bright -= 5;
		}

	}
	//----------------------------------------------------------------


	//画面を赤くするやつ描画------------------
	SetDrawBright( r, g, b );
	DrawGraph( 0, 0, resource[ 3 ], TRUE );
	SetDrawBright( 255, 255, 255 );							
	//----------------------------------------

	//問題に答えたら------------
	if ( !chooseWayFlag ) {
		Action( );
	}
	//--------------------------

	//制限時間が０になったら----------
	if ( distance == 0 ) {
		gamestatus = GAME_RESULT;
	}
	//--------------------------------

	//問題の出題---------------------------------
	Question( exercise_books_num, question_num );
	//-------------------------------------------

	//入力受付//--------------------------------
	if ( input ) {
		JoypadCursor( );
		/*if ( GetJoypadNum( ) ) {
			JoypadCursor( );
		} else {
			KeybordCursor( );
		}*/
	}
	//------------------------------------------


	//デバックモード------------------------------
	if ( key[ KEY_INPUT_SPACE ] == 1 ) {
		if ( !debug ) {
			debug = true;
		} else {
			debug = false;
		}
	}

	if ( debug ) {
		debugdraw( );
	}
	//-----------------------------------------------
}

void GameResult( ) {
	//メインBGMと足音と敵の歌声を止める(あとで統一)
	Ssound( sound[ GAME_MAIN_BGM ] );
	Ssound( sound[ ENEMY_VOICE ] );
	if ( Csound( sound[ PLAYER_ASIOTO ] ) ) {
		Ssound( sound[ PLAYER_ASIOTO ] );
	}
	//----------------------------------------

	//リザルト描画-------------------------------------------------------------------------------------------------------------------------------------------------
	if ( player.answer_count == CLEAR ) {	
		//クリア時
		DrawGraph( SCREEN_WIDTH_CENTER - 150, SCREEN_HEIGHT_CENTER - 40, resource[ 2 ], TRUE );
		DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER + 50, "PRESS BUTTON", GetColor( 255, 255, 255 ) );
		if ( !sounded ) {
			Psound( sound[ GAME_CLEAR ], BACK );
			sounded = true;
		}

		if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_1 ] == 1 || joypad[ INPUT_2 ] == 1 || joypad[ INPUT_3 ] == 1 || joypad[ INPUT_4 ] == 1 ) {
				Ssound( sound[ GAME_CLEAR ] );
				gamestatus = GAME_START;
			}

	} else {
		//ゲームオーバー時
		if ( gameover_wait_count < 120 ) gameover_wait_count++; //ゲームオーバーの間

		if ( gameover_wait_count >= 120 ) {
			DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER - 50, "ゲームオーバー！！！", GetColor( 255, 0, 0 ) );
			DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER, "PUSH SPACE", GetColor( 255, 255, 255 ) );
			DrawGraph( 100, 110, resource[ 0 ], TRUE );

			if ( !sounded ) {
				Vsound( sound[ GAME_OVER ], 100 );
				Psound( sound[ GAME_OVER ], BACK );
				sounded = true;
			}
		
			if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_1 ] == 1 || joypad[ INPUT_2 ] == 1 || joypad[ INPUT_3 ] == 1 || joypad[ INPUT_4 ] == 1 ) {
				Ssound( sound[ GAME_OVER ] );
				gamestatus = GAME_START;
			}
		}

	}
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------


}



