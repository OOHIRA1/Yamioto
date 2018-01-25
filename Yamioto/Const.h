#pragma once

const int KEY_MAX = 256;

const int FIRST_DISTANCE = 30;	//player‚Æenemey‚Ì‰Šú‹——£	30
const int CLEAR = 3;		//•K—v³‰ğ”
const int QUESTION_MAX = 20;	//Å‘å–â‘è”

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