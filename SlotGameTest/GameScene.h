# pragma once
# include "Common.hpp"
class GameScene : public MyApp::Scene {
private:
#pragma region 画像読み込み用の場所
	//本体Texture
	const Texture txt_Dai{ U"example/texture/Sotowaku.png" };
	const Texture txt_StopButton1{ U"example/texture/StopButton.png" };
	const Texture txt_StopButton2{ U"example/texture/StopButton.png" };
	const Texture txt_StopButton3{ U"example/texture/StopButton.png" };

	
	//リールTexture
	Array<Texture>Reel_Tex = {
		Texture {U"example/Reel/Reel.png"},
		Texture {U"example/Reel/Reel.png"},
		Texture {U"example/Reel/Reel2.png"},
		Texture {U"example/Reel/Reel2.png"},
		Texture {U"example/Reel/Reel3.png"},
		Texture {U"example/Reel/Reel3.png"},
	};
#pragma endregion


	double delayTime = 0.0;//ディレイ時間
	Vec2 NowMousePos = Vec2{ 0,0 };//マウスのいまのポジション

//------------------------------------------------
	//リールの初期位置
	Array<int> reel_initialPos = {//リールの初期位置

		-440,
		-440 + (-720)
	};	
	Vec2 speed = Vec2(0.0, 40.0);//リールの回転速度	
	const int Reel_MaxPos = 280;//リールの最大値
	Vec2 ReelSize = Vec2{ 0,80 };//リール一個分の大きさ
	const Array<int>ReelPos = {//リールのポジション
		-440,
		-360,
		-280,
		-200,
		-120,
		-40,
		40,
	};
	Array<Vec2>Reel_NowPos = {//リールの今の場所
		Vec2{370, reel_initialPos[0] },
		Vec2{370, reel_initialPos[1] },
		Vec2{550, reel_initialPos[0] },
		Vec2{550, reel_initialPos[1] },
		Vec2{730, reel_initialPos[0] },
		Vec2{730, reel_initialPos[1] },
	};
	Array<double>ReelPosY{
		 0,0,0
	};
//------------------------------------------------
	const int ButtonSize = 40;//停止ボタンのサイズ
	const Array<Vec2>buttonPos = {//停止ボタンのポジション
		 Vec2 {440,380},
		 Vec2{620,380 },
		 Vec2{800,380}
	};
	
//------------------------------------------------------------
	Array <bool>Stopflag{//各リールのストップフラグ
		false,
		false,
		false,
	};
	bool allflag = false;

//---------------------------------------------------------------
public:

	GameScene(const InitData& init);//シーン管理
	void update() override;
	void draw() const override;//描画
	void ReelGenetrate1();//リール回転
	void ReelGenetrate2();//リール回転
	void ReelGenetrate3();//リール回転
	void StopButton();//ボタン停止
	void ReelControll(int yaku);//リールを止める
};


/*Memo
約絵柄サイズ=80
リールPos＝-440,-360,-280,-200,-120,-40,40,
*/
