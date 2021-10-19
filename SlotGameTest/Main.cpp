# include <Siv3D.hpp> // OpenSiv3D v0.6.2
#include"Common.hpp"
#include"StartScene.h"
#include"GameScene.h"
void Main()
{
	Window::Resize(1280,600);
	GameScene* GS;
	// （Esc キーで終了しないようにする場合はコメントを外す）
		//System::SetTerminationTriggers(UserAction::CloseButtonClicked);
#pragma region 見ないとこ


		// タイトルを設定
	Window::SetTitle(U"スロットゲーム");

	// 背景色を設定
	Scene::SetBackground(ColorF(1, 1, 1));

	// 使用するフォントアセットを登録
	FontAsset::Register(U"Title", 120, U"example/font/AnnyantRoman/AnnyantRoman.ttf");
	FontAsset::Register(U"Menu", 30, Typeface::Regular);
	FontAsset::Register(U"Score", 36, Typeface::Bold);

	// シーンと遷移時の色を設定
	MyApp manager;
	manager
		.add<StartScene>(State::StartScene)
		.add<GameScene>(State::GameScene);
		/*.setFadeColor(ColorF(1.0));*/

	// （ゲームシーンから開始する場合はコメントを外す）
	manager.init(State::GameScene);
#pragma endregion

	while (System::Update())
	{
		if (!manager.update())
		{
			break;
		}
	}
}


//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク | Quick Links =
//
// Siv3D リファレンス
// https://zenn.dev/reputeless/books/siv3d-documentation
//
// Siv3D Reference
// https://zenn.dev/reputeless/books/siv3d-documentation-en
//
// Siv3D コミュニティへの参加
// Slack や Twitter, BBS で気軽に質問や情報交換ができます。
// https://zenn.dev/reputeless/books/siv3d-documentation/viewer/community
//
// Siv3D User Community
// https://zenn.dev/reputeless/books/siv3d-documentation-en/viewer/community
//
// 新機能の提案やバグの報告 | Feedback
// https://github.com/Siv3D/OpenSiv3D/issues
//
