#include"GameScene.h"

GameScene::GameScene(const InitData& init)//スコア引継ぎなどの数値
	:IScene(init)
{


}
//アップデート関数(Manager管理)---------------------------------------
void GameScene::update()  {
	
	StopButton();
		if (Stopflag[0]== true)
		{
			
		}
	

	
}
//リール回転関数---------------------------------------
void GameScene::StopButton() {
	NowMousePos.x = Cursor::Pos().x;
	NowMousePos.y = Cursor::Pos().y;

	//ボタンをとめる処理
	if (MouseL.down())
	{
		for (int i = 0; i < 3; i++) {
			auto x = NowMousePos.x - buttonPos[i].x;
			auto y = NowMousePos.y - buttonPos[i].y;
			auto dist = sqrt(x * x + y * y);
			if (dist < ButtonSize) {
				
				Print << NowMousePos;
				Print << i;
				if (i==0)
				{
					Stopflag[0] = true;
					Stopflag[3] = true;
				}
				break;
			}
		}
	}
	else
	{
		ReelGenetrate();
	}
}


//リール回転関数---------------------------------------
void GameScene::ReelGenetrate() {
	//描画
	
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				Reel_Tex[i].draw(Reel_NowPos[i]);
				Reel_Tex[j].draw(Reel_NowPos[j]);
				Reel_NowPos[i] += speed;
				Reel_NowPos[j] += speed;
				if (Stopflag[0] == true)
				{
					
				}
			}
			
		}
		
	//リールを入れ替える
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			if (Reel_NowPos[i].y >= Reel_MaxPos)
			{
				Reel_NowPos[i].y = Reel_NowPos[j].y - 720;
			}
			if (Reel_NowPos[j].y >= Reel_MaxPos)
			{
				Reel_NowPos[j].y = Reel_NowPos[i].y - 720;
			}
		}
	}
#pragma region リール回転デバッグ用

	//Print << Reel_NowPos[0];

#pragma endregion
}
//描画関数(Manager管理)---------------------------------------
void GameScene::draw() const  
{	
	txt_Dai.resized(890).draw(180, 0);
	Circle{ buttonPos[0],ButtonSize }.draw(Palette::Red);
	Circle{ buttonPos[1],ButtonSize }.draw(Palette::Red);
	Circle{ buttonPos[2],ButtonSize }.draw(Palette::Red);
	/*txt_StopButton1.resized(80).draw(405, 300);
	txt_StopButton2.resized(80).draw(585, 300);
	txt_StopButton3.resized(80).draw(765, 300);*/
}


