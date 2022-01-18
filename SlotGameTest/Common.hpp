# pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.2

// シーンの名前
enum class State
{
	StartScene,

	GameScene
};

// ゲームデータ
struct GameData
{
	Optional<int32>lastGameScore;

	Array<int32>highScore = { 100,50,10 };

};

// シーン管理クラス
using MyApp = SceneManager<State, GameData>;
