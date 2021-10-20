#include"GameScene.h"

GameScene::GameScene(const InitData& init)
	:IScene(init)
{


}
void GameScene::update()  {
	
	Txt_Reel1.draw(370, reel1NowPos);
	Txt_Reel2.draw(550, reel2NowPos);
	Txt_Reel3.draw(730, reel3NowPos);

	reel1NowPos += speed;
	if (reel1NowPos <= ReelMaxPos)
	{
		reel1NowPos == reel1initialPos;
		return;
	}
	
	
	//reel2NowPos += speed;
//	reel3NowPos += speed;
	
		
	
	

}
void GameScene::draw() const  
{

	
	txt_Dai.resized(890).draw(180, 0);
	txt_StopButton1.resized(80).draw(405, 300);
	txt_StopButton2.resized(80).draw(585, 300);
	txt_StopButton3.resized(80).draw(765, 300);


	
}



