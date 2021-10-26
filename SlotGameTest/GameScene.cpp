#include"GameScene.h"

GameScene::GameScene(const InitData& init)//スコア引継ぎなどの数値
	:IScene(init)
{


}
//アップデート関数(Manager管理)---------------------------------------
void GameScene::update()  {
	
	ReelGenetrate();

	
	
	if (MouseL.down())
	{
		Cursor::Pos();
	}
}
//リール回転関数---------------------------------------
void GameScene::ReelGenetrate() {
	//描画
	for (int i = 0; i <= 5; i++)
	{
		Reel_Tex[i].draw(Reel_NowPos[i]);
		Reel_NowPos[i] += speed;
	}
	//リールを入れ替える
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 3; j <= 5; j++)
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

	Print << Reel_NowPos[0];

#pragma endregion
}
//描画関数(Manager管理)---------------------------------------
void GameScene::draw() const  
{	
	txt_Dai.resized(890).draw(180, 0);
	Circle{ 440,380,40 }.draw(Palette::Red);
	Circle{ 620,380,40 }.draw(Palette::Red);
	Circle{ 800,380,40 }.draw(Palette::Red);
	/*txt_StopButton1.resized(80).draw(405, 300);
	txt_StopButton2.resized(80).draw(585, 300);
	txt_StopButton3.resized(80).draw(765, 300);*/
}


