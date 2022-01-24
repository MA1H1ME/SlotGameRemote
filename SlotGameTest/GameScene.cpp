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
		
		getData().highScore = Max(getData().highScore, m_money);
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
					Yakuflag[i] = true;
					
				break;
			}
		}
	}	
}

void GameScene::ReelGen() {
	if (Stopflag[0] && Stopflag[1] && Stopflag[2] && KeySpace.down()) {
		allYakuflag = false;
		allflag = true;
		m_money -= 100;		
		//Money_s.playOneShot();
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

void GameScene::StopButtonSC(int Rpos1,int Rpos2,int Rpos3,int yakuNo) {
	Print << yakuNo;
	if (Stopflag[0] == true) {//ストップボタンが押されたら
		Reel_Tex[0].draw(Reel_NowPos[0].x, ReelPos[Rpos1]);
		Reel_Tex[1].draw(Reel_NowPos[1].x, ReelPos[Rpos1] + 720);		
	}
	if (Stopflag[1] == true) {//ストップボタンが押されたら
		Reel_Tex[2].draw(Reel_NowPos[2].x, ReelPos[Rpos2]);
		Reel_Tex[3].draw(Reel_NowPos[3].x, ReelPos[Rpos2] + 720);		
	}
	if (Stopflag[2] == true) {//ストップボタンが押されたら
		Reel_Tex[4].draw(Reel_NowPos[4].x, ReelPos[Rpos3]);
		Reel_Tex[5].draw(Reel_NowPos[5].x, ReelPos[Rpos3] + 720);	
	}
	if (Yakuflag[0] == true && Yakuflag[1] == true && Yakuflag[2] == true) {
		allYakuflag = true;
	}
	if (allYakuflag == true)
	{
		Result(yakuNo);	
		for (int i = 0; i < 3; i++)
			Yakuflag[i] = false;

		allYakuflag = false;
	}
}
void GameScene::Result(int YakuNo) {
	switch (YakuNo)
	{
	case 1://7
		Atari_s.play();
		m_money += 10000;
		if ()
		{

		}
		break;

	case 2://チェリー
		Atari_s.play();
		m_money += 1000;
		break;

	case 3://プルーン
		Atari_s.play();
		m_money += 1000;
		break;

	case 4://オレンジ
		Atari_s.play();
		m_money += 1000;
		break;

	case 5://ベル
		Atari_s.play();
		m_money += 1000;
		break;

	case 6://バー
		Atari_s.play();
		m_money += 100;
		break;

	case 7://無役

		break;

	default://いずれでもない時
		break;
	}
	
}

void GameScene:: ReelControll(int a) {
	if (allflag != true){
	
		if (Stopflag[0] == false) //リール１を回す
			ReelGenetrate(0, 2, 0, 1, 2);
		if (Stopflag[1] == false) //リール2を回す
			ReelGenetrate(2, 4, 2, 3, 4);
		if (Stopflag[2] == false) //リール3を回す
			ReelGenetrate(4, 6, 4, 5, 6);
		
		switch (a)
		{
		case 1://7
			StopButtonSC(3, 5, 3, a);
			
			break;

		case 2://チェリー
			StopButtonSC(2, 1, 3, a);
			
			break;

		case 3://プルーン
			StopButtonSC(4, 4, 5, a);
			
			break;

		case 4://オレンジ
			StopButtonSC(1, 2, 2, a);
			
			break;

		case 5://ベル
			StopButtonSC(6, 3, 1, a);
			
			break;

		case 6://バー
			StopButtonSC(6, 1, 5, a);
		
			break;

		case 7://無役
			StopButtonSC(0, 1, 3, a);
		
			break;

		default://いずれでもない時
			StopButtonSC(0, 1, 3, a);
		
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
void GameScene::ReelGenetrate(int a,int b,int x,int y,int z) {//引数１、２＝リールの一列目：：３４５＝入れ替えのポジション
	//描画1
		for (int i = a; i < b; i++){		
				Reel_Tex[i].draw(Reel_NowPos[i]);			
				Reel_NowPos[i] += speed;	
		}
		//リールを入れ替える

		for (int i = x; i < y; i++){
			for (int j = y; j < z; j++){
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
	FontAsset(U"MONEY")(m_money).draw(900,50, Palette::Black);
}

///memo

