#pragma once

#include "Dxlib.h"

int sound[ 10 ]; //音楽のハンドル
int resource[ 10 ];	//画像のハンドル

void load_sound( ) {
	sound[ 0 ] = LoadSoundMem( "Sound/asioto.wav" );
	sound[ 1 ] = LoadSoundMem( "Sound/door.wav" );
	sound[ 2 ] = LoadSoundMem( "Sound/playerAsioto.wav" );
	sound[ 3 ] = LoadSoundMem( "Sound/gatyagatya.wav" );
	sound[ 4 ] = LoadSoundMem( "Sound/seikai.wav" );
	sound[ 5 ] = LoadSoundMem( "Sound/matigai.wav" );
	sound[ 6 ] = LoadSoundMem( "Sound/clear.wav" );
	sound[ 7 ] = LoadSoundMem( "Sound/gameover.wav" );
} 

void load_resource( ) {
	resource[ 0 ] = LoadGraph( "Resource/gameover.png" );
}