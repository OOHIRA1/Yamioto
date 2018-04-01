#include "DxLib.h"
#include "Const.h"
#include "Input.h"
#include "Load.h"
#include "Sound.h"
#include "GameManage.h"





int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	SetWindowText( "闇音" );
	SetOneMeter( 0.2f );
	ChangeWindowMode( TRUE );
	SetAlwaysRunFlag( TRUE );	//別のウィンドウに切り替えても処理が継続される関数
	SetWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	SetGraphMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );	//画像の解像度を設定する関数
	SetEnableXAudioFlag( TRUE );	//サウンドの再生にXAudio2を使用するかどうかを設定する
	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	//データの読み込み------
	load_sound( );
	load_resource( );
	load_question( );
	//----------------------

	while ( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}

		updateDevice( );	//キー入力受付
		
		switch( gamestatus ) {	//シーン切り替え処理
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

		if (  key[ KEY_INPUT_ESCAPE ] > 1 ) {	//escapeキーを押したら強制終了
			break;
		}
	}
	InitSoundMem( );
	DxLib_End( );
	return 0;
}






