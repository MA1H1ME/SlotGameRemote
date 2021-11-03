#include"GameScene.h"

GameScene::GameScene(const InitData& init)//スコア引継ぎなどの数値
	:IScene(init)
{


}
//アップデート関数(Manager管理)---------------------------------------
void GameScene::update() {

	if (allflag == false){
		if (KeySpace.down()){
			for (int i = 0; i < 3; i++)
				Stopflag[i] = false;		
		}
	}
	if (Stopflag[0] != false && Stopflag[1] != false && Stopflag[2] != false){
			allflag = true;
			Print << allflag;
	}
	if (allflag != true){
		if (Stopflag[0] != true) {
			ReelGenetrate1();
		}
		else {
			Reel_Tex[0].draw(Reel_NowPos[0]);
			Reel_Tex[1].draw(Reel_NowPos[1]);
		}
		if (Stopflag[1] != true) {
			ReelGenetrate2();
		}
		else {
			Reel_Tex[2].draw(Reel_NowPos[2]);
			Reel_Tex[3].draw(Reel_NowPos[3]);
		}
		if (Stopflag[2] != true) {
			ReelGenetrate3();
		}
		else {
			Reel_Tex[4].draw(Reel_NowPos[4]);
			Reel_Tex[5].draw(Reel_NowPos[5]);
		}
	}
	else{
		allflag = false;
		for (int i = 0; i < 6; i++)
			Reel_Tex[i].draw(Reel_NowPos[i]);				
	}
	
	
	StopButton();
	
}
//リール回転関数---------------------------------------
void GameScene::StopButton() {
	NowMousePos.x = Cursor::Pos().x;
	NowMousePos.y = Cursor::Pos().y;

	//ボタンをとめる処理
	if (MouseL.down())	{
		for (int i = 0; i < 3; i++) {
			auto x = NowMousePos.x - buttonPos[i].x;
			auto y = NowMousePos.y - buttonPos[i].y;
			auto dist = sqrt(x * x + y * y);
			if (dist < ButtonSize) {
				/*Print << NowMousePos;
				Print << i;	*/		
					Stopflag[i] = true;
					/*Print << Stopflag[i];*/
				break;
			}
		}
	}
	
}

//リール回転関数---------------------------------------
void GameScene::ReelGenetrate1() {
	//描画
		for (int i = 0; i < 2; i++){		
				Reel_Tex[i].draw(Reel_NowPos[i]);			
				Reel_NowPos[i] += speed;	
		}
	//リールを入れ替える
	for (int i = 0; i < 1; i++){
		for (int j = 1; j < 2; j++){
			if (Reel_NowPos[i].y >= Reel_MaxPos)
				Reel_NowPos[i].y = Reel_NowPos[j].y - 720;		
			if (Reel_NowPos[j].y >= Reel_MaxPos)	
				Reel_NowPos[j].y = Reel_NowPos[i].y - 720;	
		}
	}
#pragma region リール回転デバッグ用

	//Print << Reel_NowPos[0];

#pragma endregion
}
void GameScene::ReelGenetrate2() {
	//描画
	for (int i = 2; i < 4; i++) {
		Reel_Tex[i].draw(Reel_NowPos[i]);
		Reel_NowPos[i] += speed;
	}
	//リールを入れ替える
	for (int i = 2; i < 3; i++) {
		for (int j = 3; j < 4; j++) {
			if (Reel_NowPos[i].y >= Reel_MaxPos)
				Reel_NowPos[i].y = Reel_NowPos[j].y - 720;
			if (Reel_NowPos[j].y >= Reel_MaxPos)
				Reel_NowPos[j].y = Reel_NowPos[i].y - 720;
		}
	}
#pragma region リール回転デバッグ用

	//Print << Reel_NowPos[0];

#pragma endregion
}
void GameScene::ReelGenetrate3() {
	//描画
	for (int i = 4; i < 6; i++) {
		Reel_Tex[i].draw(Reel_NowPos[i]);
		Reel_NowPos[i] += speed;
	}
	//リールを入れ替える
	for (int i = 4; i < 5; i++) {
		for (int j = 5; j < 6; j++) {
			if (Reel_NowPos[i].y >= Reel_MaxPos)
				Reel_NowPos[i].y = Reel_NowPos[j].y - 720;
			if (Reel_NowPos[j].y >= Reel_MaxPos)
				Reel_NowPos[j].y = Reel_NowPos[i].y - 720;
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


