# pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.2

// シーンの名前
enum class State
{
	StartScene,
	GameScene,
	EndScene
};

// ゲームデータ
struct GameData
{
	int32 highScore = 0;

};

// シーン管理クラス
using MyApp = SceneManager<State, GameData>;
