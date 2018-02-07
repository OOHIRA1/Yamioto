#pragma once

const int KEY_MAX = 256;

const int FIRST_DISTANCE = 60;	//playerÇ∆enemeyÇÃèâä˙ãóó£	30
const int CLEAR = 15;		//ïKóvê≥âêî
const int QUESTION_MAX = 20;	//ç≈ëÂñ‚ëËêî
const int SCREEN_WIDTH_CENTER = 1280 / 2;
const int SCREEN_HEIGHT_CENTER = 720 / 2;
const int QUESTION_POS_X = SCREEN_WIDTH_CENTER - 300;
const int QUESTION_POS_Y = SCREEN_HEIGHT_CENTER - 200;
const int SELECTED_POS_X = SCREEN_WIDTH_CENTER - 150;
const int SELECTED_POS_Y = SCREEN_HEIGHT_CENTER - 100;


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

enum Sound{
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
	NON_CHOOSE_WAY,
	STRAIGHT_WAY,
	RIGHT_WAY,
	LEFT_WAY
};
