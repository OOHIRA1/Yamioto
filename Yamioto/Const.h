#pragma once

const int KEY_MAX = 256;

const int FIRST_DISTANCE = 30;	//player��enemey�̏�������	30
const int CLEAR = 3;		//�K�v����
const int QUESTION_MAX = 20;	//�ő��萔

enum GameStatus {
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};

enum SoundStatus {
	NORMAL,
	BACK,
	LOOP
};