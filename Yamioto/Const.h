#pragma once

const int KEY_MAX = 256;

const int FIRST_DISTANCE = 100;	//playerÇ∆enemeyÇÃèâä˙ãóó£
const int CLEAR = 100;		//ïKóvê≥âêî
const int QUESTION_MAX = 20;	//ç≈ëÂñ‚ëËêî
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH_CENTER = 1280 / 2;
const int SCREEN_HEIGHT_CENTER = 720 / 2;
const int QUESTION_POS_X = SCREEN_WIDTH_CENTER - 400;
const int QUESTION_POS_Y = SCREEN_HEIGHT_CENTER - 200;
const int CHOICES_POS_X = SCREEN_WIDTH_CENTER - 150;
const int CHOICES_POS_Y = SCREEN_HEIGHT_CENTER - 100;
const int CURSOR_SELECT_POS_Y = 50;
const int QUESTION_STATEMENT_SEPARATE = 22;
const int QUESTION_ELEMENT = 256;
const int CHOICES_ELEMENT = 100;
const int PRE_POS_MAX_INDEX = 30;

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

enum Sound {
	ENEMY_VOICE,
	PLAYER_ASIOTO,
	DOOR,
	DOOR_GATYA,
	SEIKAI,
	MATIGAI,
	GAME_CLEAR,
	GAME_OVER,
	GAME_START_BGM,
	GAME_MAIN_BGM
};

enum Way {
	NOT_CHOOSE_WAY = -1,
	STRAIGHT_WAY,
	RIGHT_WAY,
	LEFT_WAY,
	WAY_MAX
};

enum Joypad {
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

enum Difficulty {
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};
