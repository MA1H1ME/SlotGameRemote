#include"GameScene.h"

GameScene::GameScene(const InitData& init)
	:IScene(init)
{


}
void GameScene::update()  {
	
}
void GameScene::draw() const  
{
	txt_Dai.resized(900).draw(180, 0);
}


