#pragma once
namespace affinTransformation{
	void Scale(WorldTransform worldTransform_);
    void RotX(WorldTransform worldTransform_, float angle);
	void RotY(WorldTransform worldTransform_, float angle);
	void RotX(WorldTransform worldTransform_, float angle);
	void Trans(WorldTransform worldTransform_, float Tx, float Ty, float Tz);
	void com(WorldTransform worldTransform_, float Sx, float Sy, float Sz, float angle, float Tx, float Ty, float Tz);
}


