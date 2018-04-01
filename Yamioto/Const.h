#pragma once

const int KEY_MAX = 256;

const int FIRST_DISTANCE = 80;								//playerとenemeyの初期距離
const int CLEAR = 10;										//必要正解数
const int QUESTION_MAX = 20;								//最大問題数(一つの問題集の中の)
const int SCREEN_WIDTH = 1280;								//ウィンドウの横幅
const int SCREEN_HEIGHT = 720;								//ウィンドウの縦幅
const int SCREEN_WIDTH_CENTER = 1280 / 2;					//ウィンドウ中心x座標
const int SCREEN_HEIGHT_CENTER = 720 / 2;					//ウィンドウ中心y座標
const int QUESTION_POS_X = SCREEN_WIDTH_CENTER - 400;		//問題文の一行目のx座標
const int QUESTION_POS_Y = SCREEN_HEIGHT_CENTER - 200;		//問題文の一行目のy座標
const int CHOICES_POS_X = SCREEN_WIDTH_CENTER - 150;		//選択肢の一個目のx座標
const int CHOICES_POS_Y = SCREEN_HEIGHT_CENTER - 100;		//選択肢の一個目のy座標
const int CURSOR_SELECT_POS_Y = 50;							//選択肢の間隔
const int QUESTION_STATEMENT_SEPARATE = 22;					//問題文の間隔
const int QUESTION_ELEMENT = 256;							//問題文の一行の最大文字数
const int CHOICES_ELEMENT = 100;							//選択肢の一行の最大文字数
const int PRE_POS_MAX_INDEX = 30;							//配列pre_posの要素数
const int RATE_X = SCREEN_WIDTH_CENTER / 150;				//脱出時の光画像の拡大増加数x
const int RATE_Y = SCREEN_HEIGHT_CENTER / 150;				//脱出時の光画像の拡大増加数y

enum GameStatus {	//シーン
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};

enum SoundStatus {	//再生モード
	NORMAL,
	BACK,
	LOOP
};

enum Sound {	//音データ
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

enum Way {		//道
	NOT_CHOOSE_WAY = -1,
	STRAIGHT_WAY,
	RIGHT_WAY,
	LEFT_WAY,
	WAY_MAX
};

enum Joypad {	//ジョイパット
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

enum Difficulty {	//問題の難易度
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};
