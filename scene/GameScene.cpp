#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"AxisIndicator.h"
#include"PrimitiveDrawer.h"
#include"Object.h"
#include<random>
float PI = 3.14159265f;

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();
	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("sentouki01.png");
	//3Dモデルの生成
	model_ = Model::Create();
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engin(seed_gen());

	//for (WorldTransform& worldTransform_ : worldTransforms_) {
	//	//乱数範囲の指定
	//	std::uniform_real_distribution<float> dist(100.0f, 100.0f);
	//	float value = dist(engin);

	//	std::uniform_real_distribution<float> Rotdist(0.0f, PI*2);
	//	float Rotvalue = Rotdist(engin);

	//	std::uniform_real_distribution<float> TransXdist(-10.0f, 10.0f);
	//	float TransXvalue = TransXdist(engin);

	//	std::uniform_real_distribution<float> TransYdist(-10.0f, 10.0f);
	//	float TransYvalue = TransYdist(engin);

	//	std::uniform_real_distribution<float> TransZdist(-10.0f, 10.0f);
	//	float TransZvalue = TransZdist(engin);

	//	worldTransform_.Initialize();

	//	worldTransform_.scale_ = { 1.0f, 1.0f, 1.0f };
	//	worldTransform_.rotation_ = { Rotvalue,Rotvalue,Rotvalue };
	//	worldTransform_.translation_ = { TransXvalue,TransYvalue,TransZvalue };
	//	affinTransformation::Com(worldTransform_);

	//	
	//	
	//}
	
	//カメラ視点座標を設定
	//viewProjection_.eye = { 0,0,-10 };
	//カメラ注視点座標を設定
	//viewProjection_.target = { 10,0,0 };
	//カメラ上方向ベクトルを設定(右上45度指定)
	//viewProjection_.up = { cosf(PI / 4.0f),sinf(PI / 4.0f),0.0f };
	//カメラ垂直方向視野角を設定       ラジアン変換    
	//viewProjection_.fovAngleY = 10 * PI / 180;
	//アスペクト比を設定
	//viewProjection_.aspectRatio = 1.0f;
	//ニアクリップ距離を設定
	//viewProjection_.nearZ = 52.0f;
	//ファークリップ距離を設定
	//viewProjection_.farZ = 53.0f;
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
	
	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
	//軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	//軸方向表示が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);
	//ライン描画が参照するビュープロジェクションを指定する(アドレス渡し)
	PrimitiveDrawer::GetInstance()->SetViewProjection(&debugCamera_->GetViewProjection());
	//自キャラの生成
	player_ = new Player();
	//自キャラの初期化
	player_->Initialize(model_,textureHandle_);
	

	


}

void GameScene::Update() { 
	
	//自キャラの更新
	player_->Update();
#ifdef DEBUG
	if (input_->TriggerKey(DIK_0)) {
		isDebugCameraActive_ = true;
	}
#endif // DEBUG
	//カメラの処理
	/*if (isDebugCameraActive_) {
		debugCamera_->Update();
		viewProjection_.matView = ;
		viewProjection_.matProjection = ;
	}
	else {

		viewProjection_.UpdateMatrix();
	}*/
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//ライン描画が参照するビュープロジェクションを指定する(アドレス渡し)
	//PrimitiveDrawer::GetInstance()->DrawLine3d(Vector3,Vector3,Vector4)
	player_->Draw(viewProjection_);
	
	//3Dモデル描画
	//model_->Draw(worldTransform_, viewProjection_, textureHandle_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
