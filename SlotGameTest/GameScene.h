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
    const Texture Txt_Reel1{U"example/Reel/Reel.png"};
	const Texture Txt_Reel2{ U"example/Reel/Reel.png" };
	const Texture Txt_Reel3{ U"example/Reel/Reel.png" };
	int count = 0;

	//リールの初期位置
	const int reel1initialPos = -440;
	const int reel2initialPos = -360;
	const int reel3initialPos =-40 ;

	//リールの今の位置
    int reel1NowPos = reel1initialPos;
	int reel2NowPos = reel2initialPos;
	int reel3NowPos = reel3initialPos;

	//リールの回転速度
	 float speed=5;
	


	 //リールの最大値
	 const int ReelMaxPos = 40;
	

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
