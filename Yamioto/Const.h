#pragma once

const int KEY_MAX = 256;

const int FIRST_DISTANCE = 80;								//player��enemey�̏�������
const int CLEAR = 10;										//�K�v����
const int QUESTION_MAX = 20;								//�ő��萔(��̖��W�̒���)
const int SCREEN_WIDTH = 1280;								//�E�B���h�E�̉���
const int SCREEN_HEIGHT = 720;								//�E�B���h�E�̏c��
const int SCREEN_WIDTH_CENTER = 1280 / 2;					//�E�B���h�E���Sx���W
const int SCREEN_HEIGHT_CENTER = 720 / 2;					//�E�B���h�E���Sy���W
const int QUESTION_POS_X = SCREEN_WIDTH_CENTER - 400;		//��蕶�̈�s�ڂ�x���W
const int QUESTION_POS_Y = SCREEN_HEIGHT_CENTER - 200;		//��蕶�̈�s�ڂ�y���W
const int CHOICES_POS_X = SCREEN_WIDTH_CENTER - 150;		//�I�����̈�ڂ�x���W
const int CHOICES_POS_Y = SCREEN_HEIGHT_CENTER - 100;		//�I�����̈�ڂ�y���W
const int CURSOR_SELECT_POS_Y = 50;							//�I�����̊Ԋu
const int QUESTION_STATEMENT_SEPARATE = 22;					//��蕶�̊Ԋu
const int QUESTION_ELEMENT = 256;							//��蕶�̈�s�̍ő啶����
const int CHOICES_ELEMENT = 100;							//�I�����̈�s�̍ő啶����
const int PRE_POS_MAX_INDEX = 30;							//�z��pre_pos�̗v�f��
const int RATE_X = SCREEN_WIDTH_CENTER / 150;				//�E�o���̌��摜�̊g�呝����x
const int RATE_Y = SCREEN_HEIGHT_CENTER / 150;				//�E�o���̌��摜�̊g�呝����y

enum GameStatus {	//�V�[��
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};

enum SoundStatus {	//�Đ����[�h
	NORMAL,
	BACK,
	LOOP
};

enum Sound {	//���f�[�^
	ENEMY_VOICE,
	PLAYER_ASIOTO,
	DOOR,
	DOOR_GATYA,
	SEIKAI,
	MATIGAI,
	GAME_CLEAR,
	GAME_OVER,
	GAME_START_BGM,
	GAME_MAIN_BGM,
	GAME_START_SE
};

enum Way {		//��
	NOT_CHOOSE_WAY = -1,
	STRAIGHT_WAY,
	RIGHT_WAY,
	LEFT_WAY,
	WAY_MAX
};

enum Joypad {	//�W���C�p�b�g
	DOWN,
	LEFT,
	RIGHT,
	UP,
	INPUT_1,
	INPUT_2,
	INPUT_3,
	INPUT_4,
	JOYPADMAX
};

enum Difficulty {	//���̓�Փx
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};
