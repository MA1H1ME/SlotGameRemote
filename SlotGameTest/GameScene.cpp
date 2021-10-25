#include"GameScene.h"

GameScene::GameScene(const InitData& init)
	:IScene(init)
{


}
void GameScene::update()  {

	
	Txt_Reel1A.draw(Reel1A_NowPos);
	Txt_Reel2A.draw(Reel2A_NowPos);
	Txt_Reel3A.draw(Reel3A_NowPos);
	Txt_Reel1B.draw(Reel1B_NowPos);
	Txt_Reel2B.draw(Reel2B_NowPos);
	Txt_Reel3B.draw(Reel3B_NowPos);


	Reel1A_NowPos += speed;
	Reel1B_NowPos += speed;

	if (Reel1A_NowPos.y>Reel_MaxPos)
	{
		Reel1A_NowPos.y = Reel1B_NowPos.y - 720;
	}
	if (Reel1B_NowPos.y > Reel_MaxPos)
	{
		Reel1B_NowPos.y = Reel1A_NowPos.y - 720;
	}
	
	/*Print << Reel1A_NowPos;
	Print << Reel1B_NowPos;*/
		
		
}
void GameScene::draw() const  
{	
	txt_Dai.resized(890).draw(180, 0);
	txt_StopButton1.resized(80).draw(405, 300);
	txt_StopButton2.resized(80).draw(585, 300);
	txt_StopButton3.resized(80).draw(765, 300);


	
}



