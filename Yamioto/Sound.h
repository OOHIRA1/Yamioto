#pragma once
/*
�Q�Ƃ��Ă���w�b�_�[
#include "DxLib.h"
*/


//�֐����^�錾========================================================================
void Psound( int handle, int type );						//����炷�֐�
void Ssound( int handle );									//�����~�߂�֐�
int Csound( int handle );									//�������Ă��邩�m�F����֐�
void Vsound( int handle, int volume );						//���ʂ�ς���֐�
void SetEnemySoundPos( VECTOR v, int handle );				//���f�[�^�̂R�c�T�E���h�p�̍Đ��ʒu��ݒ肷��֐�
void SetPlayerPosAndDir( VECTOR listenerpos, VECTOR listenerdir );	//���f�[�^�̂R�c�T�E���h�p�̉����������鋗����ݒ肷��֐�
void SetRadius( float radius, int handle );							//���f�[�^�̂R�c�T�E���h�p�̉����������鋗����ݒ肷��֐�
void SetOneMeter( float distance );									//�R�c��Ԃ̂P���[�g���ɑ������鋗����ݒ肷��
//====================================================================================


//--����炷�֐�
void Psound( int handle, int type ) {
	switch ( type ) {
	case 0:
		PlaySoundMem( handle, DX_PLAYTYPE_NORMAL, TRUE );
		break;

	case 1:
		PlaySoundMem( handle, DX_PLAYTYPE_BACK, TRUE );
		break;

	case 2:
		PlaySoundMem( handle, DX_PLAYTYPE_LOOP, TRUE );
		break;

	default:
		break;
	}
}


//--�����~�߂�֐�
void Ssound( int handle ) {
	StopSoundMem( handle );
}


//--�������Ă��邩�m�F����֐�
int Csound( int handle ) {
	return CheckSoundMem( handle );
}


//--���ʂ�ς���֐�
void Vsound( int handle, int volume ) {
	ChangeVolumeSoundMem( volume, handle );
}


//--���f�[�^�̂R�c�T�E���h�p�̍Đ��ʒu��ݒ肷��֐�
void SetEnemySoundPos( VECTOR v, int handle ) {
	Set3DPositionSoundMem( v, handle );
}


//--�R�c�T�E���h�̃��X�i�[�̈ʒu�ƃ��X�i�[�̑O���ʒu��ݒ肷��
void SetPlayerPosAndDir( VECTOR listenerpos, VECTOR listenerdir ) {
	Set3DSoundListenerPosAndFrontPos_UpVecY( listenerpos, VAdd( listenerpos, listenerdir ) );
}


//--���f�[�^�̂R�c�T�E���h�p�̉����������鋗����ݒ肷��֐�
void SetRadius( float radius, int handle ) { 
	Set3DRadiusSoundMem( radius, handle );
}


//--�R�c��Ԃ̂P���[�g���ɑ������鋗����ݒ肷��
void SetOneMeter( float distance ) {
	Set3DSoundOneMetre( distance );
}

