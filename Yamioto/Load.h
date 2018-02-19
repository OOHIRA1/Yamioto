#pragma once

/*
参照しているヘッダー
#include "DxLib.h"
*/
#include <stdio.h>

int sound[ 20 ]; //音楽のハンドル
int resource[ 10 ];	//画像のハンドル

struct q_load {
	FILE* fp;
	char num[ 10 ];		//テキストファイルを見やすくするために書いた問題番号
	char questionStatement[ 3 * QUESTION_MAX ][ QUESTION_ELEMENT ];
	char choices[ 4 * QUESTION_MAX ][ CHOICES_ELEMENT ];
	int answerNum[ QUESTION_MAX ];		//正解番号
};
struct q_load q_load[ DIFFICULTYMAX ];

void load_sound( ) {
	SetCreate3DSoundFlag( TRUE );
	sound[ ENEMY_VOICE ] = LoadSoundMem( "Sound/EnemyVoice.wav" );
	//sound[ ENEMY_VOICE ] = LoadSoundMem( "Sound/asioto.wav" );
	SetCreate3DSoundFlag( FALSE );

	sound[ PLAYER_ASIOTO  ] = LoadSoundMem( "Sound/PlayerAsioto.wav" );
	sound[ DOOR           ] = LoadSoundMem( "Sound/Door.wav" );
	sound[ DOOR_GATYA     ] = LoadSoundMem( "Sound/GatyaGatya.wav" );
	sound[ SEIKAI         ] = LoadSoundMem( "Sound/Seikai.wav" );
	sound[ MATIGAI        ] = LoadSoundMem( "Sound/Matigai.wav" );
	sound[ GAME_CLEAR     ] = LoadSoundMem( "Sound/GameClear.wav" );
	sound[ GAME_OVER      ] = LoadSoundMem( "Sound/GameOver.wav" );
	sound[ GAME_START_BGM ] = LoadSoundMem( "Sound/GameStart.wav" );
	sound[ GAME_MAIN_BGM  ] = LoadSoundMem( "Sound/GameMain.wav" );
} 

void load_resource( ) {
	resource[ 0 ] = LoadGraph( "Resource/gameover.png" );
	resource[ 1 ] = LoadGraph( "Resource/hikari.png" );
	resource[ 2 ] = LoadGraph( "Resource/gameclear.png" );
	resource[ 3 ] = LoadGraph( "Resource/aka.png" );
	resource[ 4 ] = LoadGraph( "Resource/cursor.png" );
}


void load_question( ) {
	fopen_s( &q_load[ 0 ].fp, "QuestionEasy.txt", "r" );
	fopen_s( &q_load[ 1 ].fp, "QuestionNormal.txt", "r" );
	fopen_s( &q_load[ 2 ].fp, "QuestionHard.txt", "r" );
	
	for ( int i = 0; i < DIFFICULTYMAX; i++ ) {
		if ( q_load[ i ].fp == NULL ) {
			DxLib_End( );
		} else {
			int x = 0;
			int y = 1;
			int z = 2;
			int a = 0;
			int b = 1;
			int c = 2;
			int d = 3;
			int e = 0;
			
			while( fscanf_s( q_load[ i ].fp, "%s %s %s %s %s %s %s %s %d", 
					q_load[ i ].num, 10,
					q_load[ i ].questionStatement[ x ], QUESTION_ELEMENT, 
					q_load[ i ].questionStatement[ y ], QUESTION_ELEMENT, 
					q_load[ i ].questionStatement[ z ], QUESTION_ELEMENT, 
					q_load[ i ].choices[ a ], CHOICES_ELEMENT, 
					q_load[ i ].choices[ b ], CHOICES_ELEMENT, 
					q_load[ i ].choices[ c ], CHOICES_ELEMENT, 
					q_load[ i ].choices[ d ], CHOICES_ELEMENT, 
					&q_load[ i ].answerNum[ e ] ) == 9 ) { 

				x += 3;
				y += 3;
				z += 3;
				a += 4; 
				b += 4; 
				c += 4; 
				d += 4;
				e++;

			}
		}
		fclose( q_load[ i ].fp );

		for ( int j = 0; j < 3 * QUESTION_MAX; j++ ) {
			if ( q_load[ i ].questionStatement[ j ][ 0 ] == '/' ) {
				q_load[ i ].questionStatement[ j ][ 0 ] = ' ';
				if ( q_load[ i ].questionStatement[ j ][ 1 ] != '\0' ) {
					for ( int k = 0; k < QUESTION_ELEMENT - 1; k++ ) {
						q_load[ i ].questionStatement[ j ][ k ] = q_load[ i ].questionStatement[ j ][ k + 1 ];
					}
					q_load[ i ].questionStatement[ j ][ QUESTION_ELEMENT - 1 ] = '\0';
				}
			}
		}
	}
}
