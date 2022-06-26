#include "Enemy.h"
#include <cassert>
#include"Object.h"
void Enemy::Initialize(Model* model, uint32_t textureHandle)
{
	//NULL�|�C���^�`�F�b�N
	assert(model);
	//�����Ƃ��Ď󂯎�����f�[�^�������o�ϐ��ɋL�^����
	model_ = model;
	textureHandle_ = textureHandle;
	//�V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();
	//���[���h�ϊ��̏�����
	worldTransform_.Initialize();
}
void Enemy::Update()
{

}
void Enemy::Draw(ViewProjection viewprojection_)
{
	model_->Draw(worldTransform_, viewprojection_, textureHandle_);
}
