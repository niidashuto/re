#include "Player.h"
#include <cassert>
#include"Object.h"
void Player::Initialize(Model* model, uint32_t textureHandle)
{
	//NULLポインタチェック
	assert(model);
	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	textureHandle_ = textureHandle;
	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();
	//ワールド変換の初期化
	worldTransform_.Initialize();
}

void Player::Update()
{
	//キャラクターの移動処理
	
	//キャラクターの移動ベクトル
	Vector3 move = { 0, 0, 0 };

	//キャラクターの移動速度
	const float kCharactorSpeed = 0.2f;
	//キーボード入力による移動処理
	
	//押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_A)) {
		move = { -kCharactorSpeed, 0, 0 };
	}
	else if (input_->PushKey(DIK_D)) {
		move = { kCharactorSpeed, 0, 0 };
	}
	else if (input_->PushKey(DIK_W)) {
		move = { 0,kCharactorSpeed,0 };
	}
	else if (input_->PushKey(DIK_S)) {
		move = { 0,-kCharactorSpeed,0 };
	}
	//プレイヤーをY軸方向に回転させる処理
	
	//回転速度[ラジアン/frame]
	const float kChestRotSpeed = 0.05f;

	//押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_U))
	{
		worldTransform_.rotation_.y += kChestRotSpeed;
	}
	else if (input_->PushKey(DIK_I)) {
		worldTransform_.rotation_.y -= kChestRotSpeed;
	}
	//キャラクターの攻撃処理
	Attack();

	//弾の更新
	for (std::unique_ptr<PlayerBullet>& bullet_:bullets_)
	{
		bullet_->Update();
	}

	//移動限界座標
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 18.0f;
	//範囲を超えない処理
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);
	//注視点移動(ベクトルの加算)
	worldTransform_.translation_.x += move.x;
	worldTransform_.translation_.y += move.y;
	worldTransform_.translation_.z += move.z;

	//関数を使ってプレイヤーを平行移動させる
	affinTransformation::Com(worldTransform_);
	
	//デバッグ用
	debugText_->SetPos(50, 150);
	debugText_->Printf("%f,%f,%f", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);
	
	
	
}

void Player::Draw(ViewProjection viewprojection_)
{
	model_->Draw(worldTransform_, viewprojection_, textureHandle_);
	//弾の描画
	for (std::unique_ptr<PlayerBullet>&bullet_:bullets_)
	{
		bullet_->Draw(viewprojection_);
	}
}

void Player::Attack()
{
	if (input_->TriggerKey(DIK_SPACE))
	{
		//弾を生成し、初期化
		std::unique_ptr<PlayerBullet> newBullet = std::make_unique<PlayerBullet>();
		newBullet->Initialize(model_, worldTransform_.translation_);
		//弾を登録する
		bullets_.push_back(std::move(newBullet));
	}
}
