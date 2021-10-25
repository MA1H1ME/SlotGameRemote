# pragma once
# include "Common.hpp"
class GameScene : public MyApp::Scene {
private:

	//本体Texture
	const Texture txt_Dai{ U"example/texture/Sotowaku.png" };
	const Texture txt_StopButton1{ U"example/texture/StopButton.png" };
	const Texture txt_StopButton2{ U"example/texture/StopButton.png" };
	const Texture txt_StopButton3{ U"example/texture/StopButton.png" };

	//リールTexture
    const Texture Txt_Reel1A{U"example/Reel/Reel.png"};
	const Texture Txt_Reel2A{ U"example/Reel/Reel.png" };
	const Texture Txt_Reel3A{ U"example/Reel/Reel.png" };
	const Texture Txt_Reel1B{ U"example/Reel/Reel.png" };
	const Texture Txt_Reel2B{ U"example/Reel/Reel.png" };
	const Texture Txt_Reel3B{ U"example/Reel/Reel.png" };
	int count = 0;

	//リールの初期位置
	const int reel1A_initialPos = -440;
	const int reel2A_initialPos = -360;
	const int reel3A_initialPos =-40 ;

	const int reel1B_initialPos = -440+(-720);
	const int reel2B_initialPos = -360 + (-720);
	const int reel3B_initialPos = -40 + (-720);

	
	//リールの回転速度
	Vec2 speed = Vec2(0.0, 20.0);

	 Vec2 Reel1A_NowPos =  Vec2(370, reel1A_initialPos);
	 Vec2 Reel2A_NowPos = Vec2(550, reel2A_initialPos);
	 Vec2 Reel3A_NowPos = Vec2(730,reel3A_initialPos) ;


	 Vec2 Reel1B_NowPos = Vec2(370, reel1B_initialPos);
	 Vec2 Reel2B_NowPos = Vec2(550, reel2B_initialPos);
	 Vec2 Reel3B_NowPos = Vec2(730, reel3B_initialPos);


	 //リールの最大値
	 const int Reel_MaxPos = 280;
	 
	

	bool stopflag1 = false;//ボタンが押されたかどうか
    bool stopflag2 = false;
	bool stopflag3 = false;
	bool allflag = true;

	float delayTime = 0;
	const float FrameTime = 1.0f / 60.0f;
public:

	GameScene(const InitData& init);//シーン管理
	void update() override;
	void draw() const override;


	
};
/*
約絵柄サイズ=80
リールPos＝-440,-360,-280,-200,-120,-40,40,
*/
