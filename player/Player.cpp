#include "Player.h"
#include <cassert>
#include"Object.h"
void Player::Initialize(Model* model, uint32_t textureHandle)
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

	viewProjection_.Initialize();
	
}

void Player::Update()
{
	////�L�����N�^�[�̈ړ��x�N�g��
	//Vector3 move = { 0, 0, 0 };

	////�L�����N�^�[�̈ړ����x
	//const float kCharactorSpeed = 0.2f;

	//

	////�L�[�{�[�h���͂ɂ��ړ�����
	//
	////�����������ňړ��x�N�g����ύX
	//if (input_->PushKey(DIK_A)) {
	//	move = { -kCharactorSpeed, 0, 0 };
	//	
	//}
 //   if (input_->PushKey(DIK_D)) {
	//	move = { kCharactorSpeed, 0, 0 };
	//	
	//}
	//if (input_->PushKey(DIK_W)) {
	//	move = { 0,kCharactorSpeed,0 };
	//}
	//if (input_->PushKey(DIK_S)) {
	//	move = { 0,-kCharactorSpeed,0 };
	//}
	////�ړ����E���W
	//const float kMoveLimitX = 35.0f;
	//const float kMoveLimitY = 18.0f;
	////�͈͂𒴂��Ȃ�����
	//worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	//worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	//worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	//worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);
	////�����_�ړ�(�x�N�g���̉��Z)
	//worldTransform_.translation_.x += move.x;
	//worldTransform_.translation_.y += move.y;
	//worldTransform_.translation_.z += move.z;

	////�֐����g���ăv���C���[�𕽍s�ړ�������
	//affinTransformation::Trans(worldTransform_);
	//
	//

	////�f�o�b�O�p
	//debugText_->SetPos(50, 150);
	//debugText_->Printf("%f,%f,%f", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);
	
	
	
}

void Player::Draw(ViewProjection viewprojection_)
{
	model_->Draw(worldTransform_, viewprojection_, textureHandle_);
}
