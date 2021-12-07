#include"GameScene.h"

GameScene::GameScene(const InitData& init)//スコア引継ぎなどの数値
	:IScene(init)
{


}
//アップデート関数(Manager管理)---------------------------------------
void GameScene::update() {
	
	Print << Reel_NowPos[0];
	Print << Reel_NowPos[1];
	ReelControll(1);
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
//リールを回す処理とフラグ管理と止めたあとの処理
void GameScene:: ReelControll(int yaku) {
	
	if (Stopflag[0] != false && Stopflag[1] != false && Stopflag[2] != false && KeySpace.down()) {
		allflag = true;
		if (allflag == true)
		{
			for (int i = 0; i < 3; i++)
				Stopflag[i] = false;
		}
	}

	if (allflag != true) {
		
		if (Stopflag[0] != true) {//リール１を回す
			ReelGenetrate1();
		}
		if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x,ReelPos[0]);
				Reel_Tex[1].draw(Reel_NowPos[0].x, ReelPos[0]+720);
		}

		if (Stopflag[1] != true) {//リール2を回す
			ReelGenetrate2();
		}
		if (Stopflag[1] == true) {//ストップボタンが押されたら
			
		}

		if (Stopflag[2] != true) {//リール3を回す
			ReelGenetrate3();
		}
		if (Stopflag[2] == true) {//ストップボタンが押されたら
			
		}
	}
	else {//
		allflag = false;
		for (int i = 0; i < 6; i++)
			Reel_Tex[i].draw(Reel_NowPos[i]);
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

///memo
//if (Reel_NowPos[0].y == ReelPos[0] || Reel_NowPos[0].y == ReelPos[1] ||
			//   Reel_NowPos[0].y == ReelPos[2] || Reel_NowPos[0].y == ReelPos[3] ||
			//   Reel_NowPos[0].y == ReelPos[4] || Reel_NowPos[0].y == ReelPos[5] || Reel_NowPos[0].y == ReelPos[6] ||
			//   Reel_NowPos[1].y == ReelPos[0] || Reel_NowPos[1].y == ReelPos[1] ||
			//   Reel_NowPos[1].y == ReelPos[2] || Reel_NowPos[1].y == ReelPos[3] ||
			//   Reel_NowPos[1].y == ReelPos[4] || Reel_NowPos[1].y == ReelPos[5] || Reel_NowPos[1].y == ReelPos[6]) {

			//	Reel_Tex[0].draw(Reel_NowPos[0]);
			//	Reel_Tex[1].draw(Reel_NowPos[1]);
			//}
			//else//位置正しくなかったら
			//{
			//	Reel_NowPos[0].y += 40;
			//	Reel_NowPos[1].y += 40;
			//	Reel_Tex[0].draw(Reel_NowPos[0]);
			//	Reel_Tex[1].draw(Reel_NowPos[1]);
			//}

//if (Reel_NowPos[2].y == ReelPos[0] || Reel_NowPos[2].y == ReelPos[1] ||
//			   Reel_NowPos[2].y == ReelPos[2] || Reel_NowPos[2].y == ReelPos[3] ||
//			   Reel_NowPos[2].y == ReelPos[4] || Reel_NowPos[2].y == ReelPos[5] || Reel_NowPos[2].y == ReelPos[6] ||
//			   Reel_NowPos[3].y == ReelPos[0] || Reel_NowPos[3].y == ReelPos[1] ||
//			   Reel_NowPos[3].y == ReelPos[2] || Reel_NowPos[3].y == ReelPos[3] ||
//			   Reel_NowPos[3].y == ReelPos[4] || Reel_NowPos[3].y == ReelPos[5] || Reel_NowPos[3].y == ReelPos[6]) {
//
//	Reel_Tex[2].draw(Reel_NowPos[2]);
//	Reel_Tex[3].draw(Reel_NowPos[3]);
//}
//else//位置正しくなかったら
//{
//	Reel_NowPos[2].y += 40;
//	Reel_NowPos[3].y += 40;
//	Reel_Tex[2].draw(Reel_NowPos[2]);
//	Reel_Tex[3].draw(Reel_NowPos[3]);
//}
//if (Reel_NowPos[2].y == ReelPos[0] || Reel_NowPos[2].y == ReelPos[1] ||
//			   Reel_NowPos[2].y == ReelPos[2] || Reel_NowPos[2].y == ReelPos[3] ||
//			   Reel_NowPos[2].y == ReelPos[4] || Reel_NowPos[2].y == ReelPos[5] || Reel_NowPos[2].y == ReelPos[6] ||
//			   Reel_NowPos[3].y == ReelPos[0] || Reel_NowPos[3].y == ReelPos[1] ||
//			   Reel_NowPos[3].y == ReelPos[2] || Reel_NowPos[3].y == ReelPos[3] ||
//			   Reel_NowPos[3].y == ReelPos[4] || Reel_NowPos[3].y == ReelPos[5] || Reel_NowPos[3].y == ReelPos[6]) {
//
//	Reel_Tex[2].draw(Reel_NowPos[2]);
//	Reel_Tex[3].draw(Reel_NowPos[3]);
//}
//else//位置正しくなかったら
//{
//	Reel_NowPos[2].y += 40;
//	Reel_NowPos[3].y += 40;
//	Reel_Tex[2].draw(Reel_NowPos[2]);
//	Reel_Tex[3].draw(Reel_NowPos[3]);
////}
