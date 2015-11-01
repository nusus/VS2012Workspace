#ifndef euler_angles_h__
#define euler_angles_h__

namespace tdfom
{
	class Quaternion;
	class Matrix4x3;
	class RotationMatrix;
	class EulerAngles
	{
	public:
		float heading_;
		float pitch_;
		float bank_;
	public:
		EulerAngles(){}

		EulerAngles(float h, float p, float b):
			heading_(h),
			pitch_(p),
			bank_(b){}

		void Identity(){
			heading_ = pitch_ = bank_ = 0.0f;
		}

		void Canonize();

		void FromObjectToInertialQuaternion(const Quaternion& q);
		void FromInertialToObjectQuaternion(const Quaternion& q);

		void FromObjectToWorldMatrix(const Matrix4x3& m);
		void FromWorldToObjectMatrix(const Matrix4x3& m);

		void FromRotationMatrix(const RotationMatrix& rm);
	};
	extern const EulerAngles g_kEulerAnglesIdentity;
}
#endif // euler_angles_h__
