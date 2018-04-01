#include "DxLib.h"
#include "Const.h"
#include "Input.h"
#include "Load.h"
#include "Sound.h"
#include "GameManage.h"





int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	SetWindowText( "�ŉ�" );
	SetOneMeter( 0.2f );
	ChangeWindowMode( TRUE );
	SetAlwaysRunFlag( TRUE );	//�ʂ̃E�B���h�E�ɐ؂�ւ��Ă��������p�������֐�
	SetWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	SetGraphMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );	//�摜�̉𑜓x��ݒ肷��֐�
	SetEnableXAudioFlag( TRUE );	//�T�E���h�̍Đ���XAudio2���g�p���邩�ǂ�����ݒ肷��
	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	//�f�[�^�̓ǂݍ���------
	load_sound( );
	load_resource( );
	load_question( );
	//----------------------

	while ( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}

		updateDevice( );	//�L�[���͎�t
		
		switch( gamestatus ) {	//�V�[���؂�ւ�����
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

		if (  key[ KEY_INPUT_ESCAPE ] > 1 ) {	//escape�L�[���������狭���I��
			break;
		}
	}
	InitSoundMem( );
	DxLib_End( );
	return 0;
}






