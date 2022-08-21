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
}

void Player::Update()
{
	//�f�X�t���O�̗������e���폜
	bullets_.remove_if([](std::unique_ptr<PlayerBullet>& bullet) {
		return bullet->isDead();
		});

	//�L�����N�^�[�̈ړ�����
	
	//�L�����N�^�[�̈ړ��x�N�g��
	Vector3 move = { 0, 0, 0 };

	//�L�����N�^�[�̈ړ����x
	const float kCharactorSpeed = 0.2f;
	//�L�[�{�[�h���͂ɂ��ړ�����
	
	//�����������ňړ��x�N�g����ύX
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
	//�v���C���[��Y�������ɉ�]�����鏈��
	
	//��]���x[���W�A��/frame]
	const float kChestRotSpeed = 0.05f;

	//�����������ňړ��x�N�g����ύX
	if (input_->PushKey(DIK_U))
	{
		worldTransform_.rotation_.y += kChestRotSpeed;
	}
	else if (input_->PushKey(DIK_I)) {
		worldTransform_.rotation_.y -= kChestRotSpeed;
	}
	//�L�����N�^�[�̍U������
	Attack();

	//�e�̍X�V
	for (std::unique_ptr<PlayerBullet>& bullet_:bullets_)
	{
		bullet_->Update();
	}

	//�ړ����E���W
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 18.0f;
	//�͈͂𒴂��Ȃ�����
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);
	//�����_�ړ�(�x�N�g���̉��Z)
	worldTransform_.translation_.x += move.x;
	worldTransform_.translation_.y += move.y;
	worldTransform_.translation_.z += move.z;

	//�֐����g���ăv���C���[�𕽍s�ړ�������
	affinTransformation::Com(worldTransform_);
	
	//�f�o�b�O�p
	debugText_->SetPos(50, 150);
	debugText_->Printf("%f,%f,%f", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);
	
	
	
}

void Player::Draw(ViewProjection viewprojection_)
{
	model_->Draw(worldTransform_, viewprojection_, textureHandle_);
	//�e�̕`��
	for (std::unique_ptr<PlayerBullet>&bullet_:bullets_)
	{
		bullet_->Draw(viewprojection_);
	}
}

void Player::Attack()
{
	if (input_->TriggerKey(DIK_SPACE))
	{
		//�e�̑��x
		const float kBulletSpeed = 1.0f;

		Vector3 velocity(0, 0, kBulletSpeed);

		float w = 0.0f;
		
		//���x�x�N�g�������@�̌����ɍ��킹�ĉ�]������
		velocity.x = (velocity.x * worldTransform_.matWorld_.m[0][0]) +
			(velocity.y * worldTransform_.matWorld_.m[1][0]) +
			(velocity.z * worldTransform_.matWorld_.m[2][0]) +
			(w * worldTransform_.matWorld_.m[3][0]);

		velocity.y = (velocity.x * worldTransform_.matWorld_.m[0][1]) +
			(velocity.y * worldTransform_.matWorld_.m[1][1]) +
			(velocity.z * worldTransform_.matWorld_.m[2][1]) +
			(w * worldTransform_.matWorld_.m[3][1]);

		velocity.z = (velocity.x * worldTransform_.matWorld_.m[0][2]) +
			(velocity.y * worldTransform_.matWorld_.m[1][2]) +
			(velocity.z * worldTransform_.matWorld_.m[2][2]) +
			(w * worldTransform_.matWorld_.m[3][2]);

		w = (velocity.x * worldTransform_.matWorld_.m[0][3]) +
			(velocity.y * worldTransform_.matWorld_.m[1][3]) +
			(velocity.z * worldTransform_.matWorld_.m[2][3]) +
			(w * worldTransform_.matWorld_.m[3][3]);

		//�e�𐶐����A������
		std::unique_ptr<PlayerBullet> newBullet = std::make_unique<PlayerBullet>();
		newBullet->Initialize(model_, worldTransform_.translation_,velocity);
		//�e��o�^����
		bullets_.push_back(std::move(newBullet));
	}
}
