#include "EndScene.h"
EndScene::EndScene(const InitData& init)
	: IScene(init)
{

}

void EndScene::update()
{
	m_startTransition.update(m_startButton.mouseOver());
	m_exitTransition.update(m_exitButton.mouseOver());

	if (m_startButton.mouseOver() || m_exitButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_startButton.leftClicked())
	{
		changeScene(State::GameScene);
	}

	if (m_exitButton.leftClicked())
	{
		System::Exit();
	}
	FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(620, 550));
}


void EndScene::draw() const
{
	const String titleText = U"ゲームオーバー";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Resultmenu")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Resultmenu")(titleText).drawAt(center);

	m_startButton.draw(ColorF(1.0, m_startTransition.value())).drawFrame(2);
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).drawFrame(2);

	FontAsset(U"Menu")(U"もう一度賭ける").drawAt(m_startButton.center(), ColorF(0.25));
	FontAsset(U"Menu")(U"おわる").drawAt(m_exitButton.center(), ColorF(0.25));


}
