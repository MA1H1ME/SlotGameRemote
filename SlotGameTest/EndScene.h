# pragma once
# include "Common.hpp"
class EndScene : public MyApp::Scene {

private:
	//StartボタンUI
	Rect m_startButton = Rect(Arg::center = Scene::Center().movedBy(0, 0), 300, 60);
	Transition m_startTransition = Transition(0.4s, 0.2s);
	//ExitボタンUI
	Rect m_exitButton = Rect(Arg::center = Scene::Center().movedBy(0, 100), 300, 60);
	Transition m_exitTransition = Transition(0.4s, 0.2s);
	const int32 highScore = getData().highScore;
public:

	EndScene(const InitData& init);
	void update() override;

	void draw() const override;
};
