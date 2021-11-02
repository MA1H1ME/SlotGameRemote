# pragma once
# include "Common.hpp"
class GameScene : public MyApp::Scene {
private:
#pragma region 画像読み込み
	//本体Texture
	const Texture txt_Dai{ U"example/texture/Sotowaku.png" };
	const Texture txt_StopButton1{ U"example/texture/StopButton.png" };
	const Texture txt_StopButton2{ U"example/texture/StopButton.png" };
	const Texture txt_StopButton3{ U"example/texture/StopButton.png" };

	
	//リールTexture
	Array<Texture>Reel_Tex = {
		Texture {U"example/Reel/Reel.png"},
		Texture {U"example/Reel/Reel2.png"},
		Texture {U"example/Reel/Reel3.png"},
		Texture {U"example/Reel/Reel.png"},
		Texture {U"example/Reel/Reel2.png"},
		Texture {U"example/Reel/Reel3.png"},
	};
#pragma endregion


	
	//リールの初期位置
	Array<int> reel_initialPos = {
		-440,
		-440 + (-720)
	};
	//リールの回転速度
	Vec2 speed = Vec2(0.0, 2.0);

	//リールの今の場所
	 Array<Vec2>Reel_NowPos = {
		Vec2{370, reel_initialPos[0] },
		Vec2{550, reel_initialPos[0] },
		Vec2{730, reel_initialPos[0] },
		Vec2{370, reel_initialPos[1] },
		Vec2{550, reel_initialPos[1] },
		Vec2{730, reel_initialPos[1] },
	};
	Vec2	 NowMousePos = Vec2{0,0};
	
	const int ButtonSize = 40;
	const 	Array<Vec2>buttonPos = {
		 Vec2 {440,380},
		 Vec2{620,380 },
		 Vec2{800,380}
	};
	//リールの最大値
	const int Reel_MaxPos = 280;
	//描画系
	double delayTime = 0.0;
	

	//------------------------------------------------
	Array <bool>Stopflag{
		false,
		false,
		false,
		false,
		false
	};
	bool allflag = true;


//---------------------------------------------------------------
public:

	GameScene(const InitData& init);//シーン管理
	void update() override;
	void draw() const override;
	void ReelGenetrate();//リール回転
	void StopButton();
	
};


/*Memo
約絵柄サイズ=80
リールPos＝-440,-360,-280,-200,-120,-40,40,
*/
