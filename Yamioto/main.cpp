#include "DxLib.h"
#include "Const.h"
#include "Key.h"
#include "Load.h"
#include "Sound.h"
#include "GameManage.h"




int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	ChangeWindowMode( 1 );
	SetWindowText( "�ŉ�" );
	SetOneMeter( 1 );
	//ChangeWindowMode( FALSE );
	SetAlwaysRunFlag( TRUE );	//�ʂ̃E�B���h�E�ɐ؂�ւ��Ă��������p�������֐�
	SetWindowSize( 1280, 720 );
	SetGraphMode( 1280, 720, 32 );	//�摜�̉𑜓x��ݒ肷��֐�
	SetEnableXAudioFlag( TRUE );	//�T�E���h�̍Đ���XAudio2���g�p���邩�ǂ�����ݒ肷��
	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	//������
	load_sound( );
	load_resource( );

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
			Ssound( sound[ GAME_START_BGM ] );
			break;
		}
	}
	InitSoundMem( );
	DxLib_End( );
	return 0;
}






