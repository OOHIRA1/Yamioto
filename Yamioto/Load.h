#pragma once

#include "Dxlib.h"
#include <stdio.h>

int sound[ 20 ]; //音楽のハンドル
int resource[ 10 ];	//画像のハンドル
FILE* fp;
char questionStatement[ 1 * 15 ][ QUESTION_ELEMENT ];
char choices[ 4 * 15 ][ CHOICES_ELEMENT ];
char num[ 10 ];		//テキストファイルを見やすくするために書いた問題番号

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
	fopen_s( &fp, "Question.txt", "r" );
	if ( fp == NULL ) {
		DxLib_End( );
	} else {
		int i = 0;
		int a = 0;
		int b = 1;
		int c = 2;
		int d = 3;

		
		while( fscanf_s( fp, "%s %s %s %s %s %s", num, 10, questionStatement[ i ], QUESTION_ELEMENT, choices[ a ], CHOICES_ELEMENT, choices[ b ], CHOICES_ELEMENT, choices[ c ], CHOICES_ELEMENT, choices[ d ], CHOICES_ELEMENT ) == 6 ) { 
			i++; 
			a += 4; 
			b += 4; 
			c += 4; 
			d += 4;
		}
	}
	fclose( fp );
}


