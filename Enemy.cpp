#include "Enemy.h"
#include <cassert>
#include"Object.h"
void Enemy::Initialize(Model* model, uint32_t textureHandle)
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
void Enemy::Update()
{

}
void Enemy::Draw(ViewProjection viewprojection_)
{
	model_->Draw(worldTransform_, viewprojection_, textureHandle_);
}
