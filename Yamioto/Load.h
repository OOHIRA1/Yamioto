#pragma once

#include "Dxlib.h"
#include <stdio.h>

int sound[ 20 ]; //���y�̃n���h��
int resource[ 10 ];	//�摜�̃n���h��
FILE* fp;
char num[ 10 ];		//�e�L�X�g�t�@�C�������₷�����邽�߂ɏ��������ԍ�
char questionStatement[ 3 * QUESTION_MAX ][ QUESTION_ELEMENT ];
char choices[ 4 * QUESTION_MAX ][ CHOICES_ELEMENT ];
int answerNum[ QUESTION_MAX ];		//����ԍ�

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
		int x = 0;
		int y = 1;
		int z = 2;
		int a = 0;
		int b = 1;
		int c = 2;
		int d = 3;
		int e = 0;
		
		while( fscanf_s( fp, "%s %s %s %s %s %s %s %s %d", num, 10, questionStatement[ x ], QUESTION_ELEMENT, questionStatement[ y ], QUESTION_ELEMENT, questionStatement[ z ], QUESTION_ELEMENT, choices[ a ], CHOICES_ELEMENT, choices[ b ], CHOICES_ELEMENT, choices[ c ], CHOICES_ELEMENT, choices[ d ], CHOICES_ELEMENT, &answerNum[ e ] ) == 9 ) { 
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
	fclose( fp );

	for ( int i = 0; i < 3 * 18; i++ ) {
		if ( questionStatement[ i ][ 0 ] == '/' ) {
			questionStatement[ i ][ 0 ] = ' ';
			if ( questionStatement[ i ][ 1 ] != '\0' ) {
				for ( int j = 0; j < CHOICES_ELEMENT - 1; j++ ) {
					questionStatement[ i ][ j ] = questionStatement[ i ][ j + 1 ];
				}
				questionStatement[ i ][ CHOICES_ELEMENT - 1 ] = '\0';
			}
		}
	}
}
