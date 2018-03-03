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

int bright = 0;
bool bright_max = true;

int flame_count = 0;
int distance = FIRST_DISTANCE; //残り時間 
int escape_count = 0;	//逃げているフレーム数を数える変数
bool sounded = false; 
int exercise_books_num = 0;
int gameover_wait_count = 0;
bool gameover_wait = true;

int p_pos_index = 0;
int e_pos_index = 0;

struct fps {
	short int start;
	short int flame;
	float save;
};
struct fps fps_counter;

bool debug = false;


int light_x1 = SCREEN_WIDTH_CENTER, light_y1 = SCREEN_HEIGHT_CENTER, 
	light_x2 = SCREEN_WIDTH_CENTER, light_y2 = SCREEN_HEIGHT_CENTER, 
	light_x3 = SCREEN_WIDTH_CENTER, light_y3 = SCREEN_HEIGHT_CENTER, 
	light_x4 = SCREEN_WIDTH_CENTER, light_y4 = SCREEN_HEIGHT_CENTER;

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
	/*if ( vec.x == num && vec.y == num && vec.z == num ) {
		return true;
	} else {
		return false;
	}*/


	return ( vec.x == num && vec.y == num && vec.z == num );

}

void Initialization( ) {

	PlayerInitialize( &player );
	EnemyInitialize( &enemy );
	QuesitionInitialize( );
	SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
	SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );
	SetRadius( 30, sound[ ENEMY_VOICE ] );

	flame_count = 0;
	distance = FIRST_DISTANCE;
	escape_count = 0;
	gameover_wait_count = 0;
	bright = 0;
	p_pos_index = 0;
	e_pos_index = 0;

	light_x1 = SCREEN_WIDTH_CENTER;
	light_y1 = SCREEN_HEIGHT_CENTER;
	light_x2 = SCREEN_WIDTH_CENTER;
	light_y2 = SCREEN_HEIGHT_CENTER;
	light_x3 = SCREEN_WIDTH_CENTER;
	light_y3 = SCREEN_HEIGHT_CENTER;
	light_x4 = SCREEN_WIDTH_CENTER;
	light_y4 = SCREEN_HEIGHT_CENTER;

	sounded = false;
	gameover_wait = true;


}


void debugdraw( ) {

	float Ex = SCREEN_WIDTH * ( float )0.5 + enemy.position.x - 8;
	float Px = SCREEN_WIDTH * ( float )0.5 + player.position.x - 8;
	DrawBoxAA( Ex, ( SCREEN_HEIGHT - ( enemy.position.z + 8 ) ), Ex + 16, ( SCREEN_HEIGHT - ( enemy.position.z - 8 ) ), 0xffffff, TRUE );
	DrawBoxAA( Px, ( SCREEN_HEIGHT - ( player.position.z + 8 ) ), Px + 16, ( SCREEN_HEIGHT - ( player.position.z - 8 ) ), 0x0000ff, TRUE );

	//残り距離を描画
	DrawFormatString( 0, 0, 0xffffff, "エネミーとの距離：%d", distance );

	//正解数 / 最大正解数を描画
	DrawFormatString( 0, 20, 0xffffff, "正解数 / 最大正解数：%d / %d", player.answer_count, CLEAR );

	//q_finishedを描画
	for ( int i = 0; i < QUESTION_MAX; i++ ) {
		DrawFormatString( 0, ( i * 20 ) + 40, 0xffffff, "%d", q_finished[ 0 ][ i ] );
	}

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
	DrawFormatString( 1000, 0, 0xffffff, "%f", fps_counter.save );
	fps_counter.flame++;
	//------------------------------------------------------------

	//p_pos配列を描画-------------------------------------------------------------------------------------------------------------------------------------
	for ( int i = 0; i < 30; i++ ) {
		DrawFormatString( 50, 40 + ( i * 20 ), 0xffffff, "( %5.1f, %5.1f, %5.1f )", player.pre_pos[ i ].x, player.pre_pos[ i ].y, player.pre_pos[ i ].z );
	}
	//----------------------------------------------------------------------------------------------------------------------------------------------------

	//e_pos_indexを描画-------------------------------------
	DrawFormatString( 200, 0, 0xffffff, "%d", e_pos_index );
	//------------------------------------------------------
}

//--プレイヤーの行動を表す関数
void Action( ) {
	if ( !chooseWayFlag && !input && !answer && !not_answer  ) {						//道を選んで問題表示してないときの処理			

		//走り出す
		if ( escape_count == 0 ) {
			Vsound( sound[ PLAYER_ASIOTO ], 100 );
			Psound( sound[ PLAYER_ASIOTO ], LOOP );
		}

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


		escape_count++;

		distance += escape_count % 21 / 20;

		//player.position.z += escape_count % 21 / 20;
		//SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );

		if ( escape_count == 100 ) {
			Ssound( sound[ PLAYER_ASIOTO ] );
			Vsound( sound[ DOOR_GATYA ], 100 );
			Psound( sound[ DOOR_GATYA ], NORMAL );
			escape_count = 0;
			player.direction = VGet( 0, 0, 1 );
			SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
			input = true;


			//プレイヤーの座標をいれる----------------------
			player.pre_pos[ p_pos_index ] = player.position;
			p_pos_index = ( p_pos_index + 1 ) % 30; //数値を0～29で繰り返す
			//----------------------------------------------

		}
	}
	




	if ( not_answer ) {	//不正解処理

		if ( escape_count == 0 ) {
			Vsound( sound[ MATIGAI ], 100 );
			Psound( sound[ MATIGAI ], NORMAL );
			player.not_answer_count++;
		}

		escape_count++;

		if ( escape_count == 200 ) {

			escape_count = 0;
			
			q_finished[ 0 ][ question_num - 1 ] = true;

			//全ての問題が出たらリセットする
			for ( int i = 0; i < QUESTION_MAX; i++ ) {

				if ( !q_finished[ 0 ][ i ] ) break;

				if ( i == QUESTION_MAX - 1 ) {
					for ( int j = 0; j < QUESTION_MAX; j++ ) {
						q_finished[ 0 ][ j ] = false;
					}
				}
			}

			//問題をランダムにする//問題の重複防止	
			srand( ( unsigned int )time( NULL ) );
			do {
				question_num = rand( ) % QUESTION_MAX + 1; 
			} while ( q_finished[ 0 ][ question_num - 1 ] );

			selectedSentence = 0;
			input = true;
			not_answer = false;
		}

	}

	if ( answer ) {						//正解処理			
		if ( escape_count == 0 && player.answer_count > -1 ) {			//正解したら最初に正解音を鳴らす。そのあとにドアの開閉音を鳴らす
			Vsound( sound[ SEIKAI ], 100 );
			Psound( sound[ SEIKAI ], NORMAL );
			Vsound( sound[ DOOR ], 100 );
			Psound( sound[ DOOR ], NORMAL );
		}


		//正解音とドアの開閉音が鳴り終わったら走り出す
		if ( escape_count == 0 ) {
			Vsound( sound[ PLAYER_ASIOTO ], 100 );
			Psound( sound[ PLAYER_ASIOTO ], LOOP );
		}

			
		escape_count++;
		
		distance += escape_count % 21 / 20;
		
		player.position.z += escape_count % 21 / 20;
		SetPlayerPosAndDir( player.position, VAdd( player.position, player.direction ) );
		
		//脱出直前の画像表示
		if ( player.answer_count == CLEAR - 1 ) {
			DrawModiGraph( light_x1--, light_y1--, light_x2++, light_y2--, light_x3++, light_y3++, light_x4--, light_y4++, resource[ 1 ], TRUE );
		}

		

		if ( escape_count == 200 ) {
			Ssound( sound[ PLAYER_ASIOTO ] );
			escape_count = 0;
			player.answer_count++;

			if ( player.answer_count < CLEAR ) {	//player.answer_countが必要正解数以下のとき
				
				q_finished[ 0 ][ question_num - 1 ] = true;

				//全ての問題が出たらリセットする
				for ( int i = 0; i < QUESTION_MAX; i++ ) {

					if ( !q_finished[ 0 ][ i ] ) break;

					if ( i == QUESTION_MAX - 1 ) {
						for ( int j = 0; j < QUESTION_MAX; j++ ) {
							q_finished[ 0 ][ j ] = false;
						}
					}
				}

				//問題をランダムにする//問題の重複防止----------	
				srand( ( unsigned int )time( NULL ) );
				do {
					question_num = rand( ) % QUESTION_MAX + 1; 
				} while ( q_finished[ 0 ][ question_num - 1 ] );
				//----------------------------------------------


				//プレイヤーの座標をいれる----------------------
				player.pre_pos[ p_pos_index ] = player.position;
				p_pos_index = ( p_pos_index + 1 ) % 30; //数値を0～29で繰り返す
				//----------------------------------------------


				selectedSentence = 0;
				input = false;
				answer = false;
				chooseWayFlag = true;	//道を選べるようにする
			} else {
				gamestatus = GAME_RESULT;
			}

		}

	}
}


void GameStart( ) {
	//スタート画面ＢＧＭ
	if ( !Csound( sound[ GAME_START_BGM ] ) ) {
		Vsound( sound[ GAME_START_BGM ], 100 );
		Psound( sound[ GAME_START_BGM ], LOOP );
	}

	//表示
	DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER - 50, "闇音", GetColor( 255, 255, 255 ) );
	DrawString( SCREEN_WIDTH_CENTER - 90, SCREEN_HEIGHT_CENTER, "PRESS BUTTON", GetColor( 255, 255, 255 ) );

	if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_1 ] == 1 || joypad[ INPUT_2 ] == 1 || joypad[ INPUT_3 ] == 1 || joypad[ INPUT_4 ] == 1 ) {
		Ssound( sound[ GAME_START_BGM ] );
		gamestatus = GAME_MAIN;
		Initialization( );
	}
		
}

void GameMain( ) {
	//ゲームメインＢＧＭ
	if ( !Csound( sound[ GAME_MAIN_BGM ] ) ) {
		Vsound( sound[ GAME_MAIN_BGM ], 100 );
		Psound( sound[ GAME_MAIN_BGM ], LOOP );
	}

	//初期歌声
	if ( !Csound( sound[ ENEMY_VOICE ] ) ) {
		Psound( sound[ ENEMY_VOICE ], LOOP );
		Vsound( sound[ ENEMY_VOICE ], 255 );
	}

	//距離が縮まる-----------------------------------------------
	flame_count++;
	if ( !answer || chooseWayFlag ) {	//問題を答えていないとき または　道を選んでいないとき
		bool move_x_flag = false;
		if ( fabsf( player.pre_pos[e_pos_index].x - enemy.position.x ) <= 0 ) {
			move_x_flag = false;
		} else {
			move_x_flag = true;
		}

		if ( ( player.pre_pos[ e_pos_index ] - enemy.position ) == 0 ){
			e_pos_index = ( e_pos_index + 1 ) % 30;

		}

		switch( player.not_answer_count ) {
		case 0:
			distance -= flame_count % 61 / 60;
			if ( move_x_flag ) {
				enemy.position.x += flame_count % 61 / 60;
			} else {
				enemy.position.z += flame_count % 61 / 60;
			}
			break;
		case 1:
			distance -= flame_count % 46 / 45;
			if ( move_x_flag ) {
				enemy.position.x += flame_count % 46 / 45;
			} else {
				enemy.position.z += flame_count % 46 / 45;
			}
			break;
		default:
			distance -= flame_count % 31 / 30;
			if ( move_x_flag ) {
				enemy.position.x += flame_count % 31 / 30;
			} else {
				enemy.position.z += flame_count % 31 / 30;
			}
			break;
		}
		SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );
	}
	//-----------------------------------------------------------

	if ( chooseWayFlag ) {
		ChooseWay( );
	}


	//時間に合わせて画面を赤くしていく
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

	//画面を赤くするやつ描画
	SetDrawBright( r, g, b );
	DrawGraph( 0, 0, resource[ 3 ], TRUE );
	SetDrawBright( 255, 255, 255 );							

	//問題に答えたら
	if ( !chooseWayFlag ) {
		Action( );
	}

	//制限時間が０になったら
	if ( distance == 0 ) {
		gamestatus = GAME_RESULT;
	}
	

	//問題のループ
	if ( question_num > QUESTION_MAX ) {
		question_num = 1;
	}

	Question( /*exercise_books_num*/0, question_num );

	if ( input ) {
		JoypadCursor( );
		/*if ( GetJoypadNum( ) ) {
			JoypadCursor( );
		} else {
			KeybordCursor( );
		}*/
	}

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
}

void GameResult( ) {
	Ssound( sound[ GAME_MAIN_BGM ] );
	Ssound( sound[ ENEMY_VOICE ] );
	if ( Csound( sound[ PLAYER_ASIOTO ] ) ) {
		Ssound( sound[ PLAYER_ASIOTO ] );
	}

	//描画
	if ( player.answer_count == CLEAR ) {
		DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER - 50, "ゲームクリア！！！", GetColor( 255, 255, 255 ) );
		DrawString( SCREEN_WIDTH_CENTER - 50, SCREEN_HEIGHT_CENTER, "PRESS BUTTON", GetColor( 255, 255, 255 ) );
		DrawGraph( 100,110, resource[ 2 ], TRUE );
		if ( !sounded ) {
			Psound( sound[ GAME_CLEAR ], BACK );
			sounded = true;
		}

		if ( key[ KEY_INPUT_RETURN ] == 1 || joypad[ INPUT_1 ] == 1 || joypad[ INPUT_2 ] == 1 || joypad[ INPUT_3 ] == 1 || joypad[ INPUT_4 ] == 1 ) {
				Ssound( sound[ GAME_CLEAR ] );
				gamestatus = GAME_START;
			}

	} else {

		if ( gameover_wait ) gameover_wait_count++;

		if ( gameover_wait_count >= 120 ) {
			gameover_wait = false;
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



}



