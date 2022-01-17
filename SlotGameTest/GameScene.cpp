#include"GameScene.h"
#include<Windows.h>

GameScene::GameScene(const InitData& init)//スコア引継ぎなどの数値
	:IScene(init)
{


}
//アップデート関数(Manager管理)---------------------------------------
void GameScene::update() {
	
		StopButton();
		ReelGen();
		
	
}
//リール回転関数---------------------------------------
void GameScene::StopButton() {

	//マウスのポジション代入
	NowMousePos.x = Cursor::Pos().x;
	NowMousePos.y = Cursor::Pos().y;

	//ボタンをとめる処理
	if (MouseL.down())	{
		for (int i = 0; i < 3; i++) {
			
			auto x = NowMousePos.x - buttonPos[i].x;
			auto y = NowMousePos.y - buttonPos[i].y;
			auto dist = sqrt(x * x + y * y);
			if (dist < ButtonSize) {
				
				Stop_s.playOneShot();
					Stopflag[i] = true;
					
				break;
			}
		}
	}
	
}

void GameScene::ReelGen() {
 	if (Stopflag[0] != false && Stopflag[1] != false && Stopflag[2] != false && KeySpace.down()) {
		allYakuflag = true;
		allflag = true;
		Money_s.playOneShot();
		Reba_s.play();
		Sleep(1 * 1000);
		if (allflag == true){
			for (int i = 0; i < 3; i++)
				Stopflag[i] = false;

			Rndins = Random(0, RndMax);

			if (Rndins >= HitLange_1 && Rndins <= HitLange_2)//0-			
				yaku = 1;			
			else if (Rndins > HitLange_2 && Rndins <= HitLange_3)//112			
				yaku = 2;			
			else if (Rndins > HitLange_3 && Rndins <= HitLange_4)//162-
			
				yaku = 3;			
			else if (Rndins > HitLange_4 && Rndins <= HitLange_5)//212-
			
				yaku = 4;			
			else if (Rndins > HitLange_5 && Rndins <= HitLange_6)//904-
			
				yaku = 5;			
			else if (Rndins > HitLange_6 && Rndins <= HitLange_7)//2754-
			
				yaku = 6;
			else if (Rndins > HitLange_7 && Rndins <= HitLange_8)//4999-			
				yaku = 7;			
			else			
				Print << U"error";			
		}
	}
	ReelControll(yaku);
}

void GameScene:: ReelControll(int a) {
	if (allflag != true){
	
		if (Stopflag[0] == false) //リール１を回す
			ReelGenetrate1();		
		if (Stopflag[1] == false) //リール2を回す
			ReelGenetrate2();
		if (Stopflag[2] == false) //リール3を回す
			ReelGenetrate3();
		
		switch (a)
		{
		case 1://7
			Print << U"1";
			
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[3]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[3] + 720);
				Yakuflag[0] = true;
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[5]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[5] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[3]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[3] + 720);
				Yakuflag[2] = true;
			}
			if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
				Atari_s.play();
				allYakuflag = false;
			}
			
			
			break;

		case 2://チェリー
			Print << U"2";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[2]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[2] + 720);
				Yakuflag[0] = true;
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[1]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[1] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[3]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[3] + 720);
				Yakuflag[2] = true;
			}
			if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
				allYakuflag = true;
			}
			if (allYakuflag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					Yakuflag[i] = false;
					
				}
				Atari_s.play();
				allYakuflag = false;
			}
			break;

		case 3://プルーン
			Print << U"3";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[4]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[4] + 720);
				Yakuflag[0] = true;
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[4]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[4] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[5]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[5] + 720);
				Yakuflag[2] = true;
			}
			if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
				allYakuflag = true;
			}
			if (allYakuflag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					Yakuflag[i] = false;
					
				}
				Atari_s.play();
				allYakuflag = false;
			}
			break;

		case 4://オレンジ
			Print << U"4";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[1]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[1] + 720);
				Yakuflag[0] = true;
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[2]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[2] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[2]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[2] + 720);
				Yakuflag[2] = true;
			}

			if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
				allYakuflag = true;
			}
			if (allYakuflag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					Yakuflag[i] = false;	
				}
				Atari_s.play();
				allYakuflag = false;
			}
			break;

		case 5://ベル
			Print << U"5";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[6]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[6] + 720);
				Yakuflag[0] = true;
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[3]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[3] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[1]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[1] + 720);
				Yakuflag[2] = true;
			}
					
			if (Yakuflag[0] == true&& Yakuflag[1] == true && Yakuflag[2] == true ){
				allYakuflag = true;
			}
				
			if (allYakuflag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					Yakuflag[i] = false;
					
				}
				Atari_s.play();
				allYakuflag = false;
			}
			
			break;

		case 6://バー
			Print << U"6";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[6]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[6] + 720);
				Yakuflag[0] = true;

			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[1]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[1] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[5]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[5] + 720);
				Yakuflag[2] = true;
			}
			
			if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
				allYakuflag = true;
			}
			if (allYakuflag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					Yakuflag[i] = false;					
				}
				Atari_s.play();
				allYakuflag = false;
			}
			
			break;

		case 7://無役
			Print << U"7";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[0]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[0] + 720);
				Yakuflag[0] = true;
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[1]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[1] + 720);
				Yakuflag[1] = true;
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[3]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[3] + 720);
				Yakuflag[2] = true;
			}
			if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
				allYakuflag = true;
			}
			if (allYakuflag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					Yakuflag[i] = false;					
				}		
				allYakuflag = false;
			}
			break;

		default://いずれでもない時
			Print << U"Elorr";
			if (Stopflag[0] == true) {//ストップボタンが押されたら
				Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[0]);
				Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[0] + 720);
			}
			if (Stopflag[1] == true) {//ストップボタンが押されたら
				Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[1]);
				Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[1] + 720);
			}
			if (Stopflag[2] == true) {//ストップボタンが押されたら
				Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[3]);
				Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[3] + 720);
			}
			break;
		}
		
	}
	else {
		allflag = false;
		Print << U"aaaa";
		for (int i = 0; i < 6; i++)
			Reel_Tex[i].draw(Reel_NowPos[i]);
	}
}


//リール回転関数---------------------------------------
void GameScene::ReelGenetrate1() {
	//描画1
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
}


//描画関数(Manager管理)---------------------------------------
void GameScene::draw() const  
{	
	txt_Dai.resized(890).draw(180, 0);
	Circle{ buttonPos[0],ButtonSize }.draw(Palette::Red);
	Circle{ buttonPos[1],ButtonSize }.draw(Palette::Red);
	Circle{ buttonPos[2],ButtonSize }.draw(Palette::Red);
	
}

///memo

