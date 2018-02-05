#pragma once

#include "Dxlib.h"

int sound[ 20 ]; //音楽のハンドル
int resource[ 10 ];	//画像のハンドル

void load_sound( ) {
	SetCreate3DSoundFlag( TRUE );
	sound[ ENEMY_VOICE ] = LoadSoundMem( "Sound/EnemyVoice.wav" );
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
}
