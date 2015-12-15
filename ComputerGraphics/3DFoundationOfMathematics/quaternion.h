#ifndef quaternion_h__
#define quaternion_h__

namespace tdfom {
	class CVector3;
	class CEulerAngles;

	class CQuaternion
	{
	public:
		float m_fW;
		float m_fX;
		float m_fY;
		float m_fZ;

	public:
		CQuaternion();
		
		~CQuaternion();

		CQuaternion(float w, float x , float y, float z):
			m_fW(w),
			m_fX(x),
			m_fY(y),
			m_fZ(z) {}

		void Identity() {
			m_fW = 1.0f;
			m_fX = m_fY = m_fZ = 0.0f;
		}

		void SetToRotateAboutX(float theta);
		void SetToRotateAboutY(float theta);
		void SetToRotateAboutZ(float theta);
		void SetToRotateAboutAxis(const CVector3& axis, float theta);

		void SetToRotateObjectToInertial(const CEulerAngles& orientation);
		void SetToRotateInertialToObject(const CEulerAngles& orientation);

		CQuaternion operator *(const CQuaternion& rhs) const;

		CQuaternion& operator *=(const CQuaternion& rhs);

		void Normalize();

		float GetRotationAngle() const;

		CVector3 GetRotationAxis() const;
	private:

	};

	extern const CQuaternion g_kQuaternoinIdentity;

	extern float DotProduct(const CQuaternion& lhs, const CQuaternion& rhs);

	extern CQuaternion Slerp(const CQuaternion& begin, const CQuaternion& end, float t);

	extern CQuaternion Conjugate(const CQuaternion& val);

	extern CQuaternion Pow(const CQuaternion& lhs, float exponent);
}
#endif // quaternion_h__
