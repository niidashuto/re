
#include"AxisIndicator.h"
#include"Matrix4.h"
#define PI =3.141592;
namespace a {

	void Scale(WorldTransform &worldTransform_) {

		//X,Y,Z�����̃X�P�[�����O��ݒ�

		//�X�P�[�����O�{�����s��ɐݒ肷��
		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransform_.scale_.x;
		matScale.m[1][1] = worldTransform_.scale_.y;
		matScale.m[2][2] = worldTransform_.scale_.z;
		//�P�ʍs���������
		worldTransform_.matWorld_ = {
			1.0f,0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f,0.0f,
			0.0f,0.0f,1.0f,0.0f,
			0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_��matScale���|���Z���đ������
		worldTransform_.matWorld_ *= matScale;

		//�s��̓]��
		worldTransform_.TransferMatrix();

	}

	void RotX(WorldTransform worldTransform_, float angle) {
		//X,Y,Z�����̉�]�p��ݒ�
		worldTransform_.rotation_ = { angle,0.0f,0.0f };

		//X����]�s���錾
		Matrix4 matRotX =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
		matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
		matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
		matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

		//�P�ʍs���������
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_��matRotX���|���Z���đ������
		worldTransform_.matWorld_ *= matRotX;

		//�s��̓]��
		worldTransform_.TransferMatrix();

	}
	void RotY(WorldTransform worldTransform_, float angle) {
		//X,Y,Z�����̉�]�p��ݒ�
		worldTransform_.rotation_ = { 0.0f,angle,0.0f };

		//Y����]�s���錾
		Matrix4 matRotY =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
		matRotY.m[0][2] = sin(worldTransform_.rotation_.y);
		matRotY.m[2][0] = -sin(worldTransform_.rotation_.y);
		matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

		//�P�ʍs���������
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_��matRotY���|���Z���đ������
		worldTransform_.matWorld_ *= matRotY;

		//�s��̓]��
		worldTransform_.TransferMatrix();

	}
	void RotZ(WorldTransform worldTransform_, float angle) {
		//X,Y,Z�����̉�]�p��ݒ�
		worldTransform_.rotation_ = { 0.0f,0.0f,angle };

		//Z����]�s���錾
		Matrix4 matRotZ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
		matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
		matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

		//�P�ʍs���������
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_��matRotZ���|���Z���đ������
		worldTransform_.matWorld_ *= matRotZ;

		//�s��̓]��
		worldTransform_.TransferMatrix();

	}

	void Trans(WorldTransform worldTransform_, float Tx, float Ty, float Tz) {
		//X,Y,Z������̕��s�ړ���ݒ�
		worldTransform_.translation_ = { 10.0f,10.0f,10.0f };

		//�ړ��ʂ��s��ɐݒ肷��
		Matrix4 matTrans =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		matTrans.m[3][0] = worldTransform_.translation_.x;
		matTrans.m[3][1] = worldTransform_.translation_.y;
		matTrans.m[3][2] = worldTransform_.translation_.z;

		worldTransform_.matWorld_ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		worldTransform_.matWorld_ *= matTrans;

		//�s��̓]��
		worldTransform_.TransferMatrix();

	}
	void com(WorldTransform worldTransform_, float Sx, float Sy, float Sz, float angle, float Tx, float Ty, float Tz) {
		//�X�P�[�����O�s��̐ݒ�
		worldTransform_.scale_ = { 5.0f, 5.0f, 5.0f };

		//�X�P�[�����O�{�����s��ɐݒ肷��
		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransform_.scale_.x;
		matScale.m[1][1] = worldTransform_.scale_.y;
		matScale.m[2][2] = worldTransform_.scale_.z;

		//��]�s��̐ݒ�
		worldTransform_.rotation_ = { angle,angle,0.0f };

		//�����p��]�s���錾
		Matrix4 matRot =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };
		//�e���p��]�s���錾
		Matrix4 matRotZ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		Matrix4 matRotX =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		Matrix4 matRotY =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		//Z����]�s��̊e�v�f��ݒ肷��(��]�p��Z)
		matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
		matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
		matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

		//X����]�s��̊e�v�f��ݒ肷��(��]�p��X)
		matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
		matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
		matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
		matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

		//Y����]�s��̊e�v�f��ݒ肷��(��]�p��Y)
		matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
		matRotY.m[0][2] = -sin(worldTransform_.rotation_.y);
		matRotY.m[2][0] = sin(worldTransform_.rotation_.y);
		matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

		//�e���̉�]�s�������
		matRot *= matRotZ *= matRotX *= matRotY;

		//���s�ړ��s��̐ݒ�
		worldTransform_.translation_ = { Tx, Ty, Tz };

		Matrix4 matTrans =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		matTrans.m[3][0] = worldTransform_.translation_.x;
		matTrans.m[3][1] = worldTransform_.translation_.y;
		matTrans.m[3][2] = worldTransform_.translation_.z;

		//�s��̍���
		worldTransform_.matWorld_ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		worldTransform_.matWorld_ *= matScale *= matRot *= matTrans;

		//�s��̓]��
		worldTransform_.TransferMatrix();

	}

}
