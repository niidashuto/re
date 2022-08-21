#include "PlayerBullet.h"
#include <cassert>
#include"Object.h"
void PlayerBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity)
{
	assert(model);

	model_ = model;
	//�e�N�X�`���ǂݍ���
	textureHandle_ = TextureManager::Load("white1x1.png");

	worldTransform_.Initialize();
	//�����Ŏ󂯎�����������W���Z�b�g
	worldTransform_.translation_ = {position.x,position.y,position.z };
	//�����Ŏ󂯎�������x�������o�ϐ��ɑ��
	velocity_ = velocity;
}

void PlayerBullet::Update()
{
	//���W���ړ�������(1�t���[�����̈ړ��ʂ𑫂�)
	worldTransform_.translation_ += {0,0,0.5f};

	//�s����X�V
	affinTransformation::Par(worldTransform_);

	//�o�ߎ��ԂŃf�X
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
}

void PlayerBullet::Draw(const ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}
