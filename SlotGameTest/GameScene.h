# pragma once
# include "Common.hpp"
class GameScene : public MyApp::Scene {
private:
	const Texture txt_Dai{ U"example/texture/Sotowaku.png" };
    const Texture Reel{U"example/Reel/Sotowaku.png"};
	const Texture txt_Dai{ U"example/texture/Sotowaku.png" };

	int count = 0;
public:

	GameScene(const InitData& init);//シーン管理
	void update() override;
	void draw() const override;


	
};
