#pragma once

const int KEY_MAX = 256;

const int TIME_LIMIT = 30;	//‰Šú§ŒÀŠÔ	30
const int CLEAR = 3;		//•K—v³‰ğ”
const int QUESTION_MAX = 10;	//Å‘å–â‘è”

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