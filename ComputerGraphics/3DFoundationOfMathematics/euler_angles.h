#ifndef euler_angles_h__
#define euler_angles_h__

namespace tdfom
{
	class CQuaternion;
	class CMatrix4x3;
	class CRotationMatrix;
	class CEulerAngles
	{
	public:
		float m_fHeading;
		float m_fPitch;
		float m_fBank;
	public:
		CEulerAngles(){}

		CEulerAngles(float h, float p, float b):
			m_fHeading(h),
			m_fPitch(p),
			m_fBank(b){}

		//************************************
		// Description:reset to zero
		// Method:    Identity
		// FullName:  tdfom::CEulerAngles::Identity
		// Access:    public 
		// Returns:   void
		// Qualifier:
		//************************************
		void Identity(){
			m_fHeading = m_fPitch = m_fBank = 0.0f;
		}

		//************************************
		// Description:变换为“限制集”的欧拉角
		// Method:    Canonize
		// FullName:  tdfom::CEulerAngles::Canonize
		// Access:    public 
		// Returns:   void
		// Qualifier:
		//************************************
		void Canonize();

		//************************************
		// Description:
		// Method:    FromObjectToInertialQuaternion
		// FullName:  tdfom::CEulerAngles::FromObjectToInertialQuaternion
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const CQuaternion & q
		//************************************
		void FromObjectToInertialQuaternion(const CQuaternion& q);
		void FromInertialToObjectQuaternion(const CQuaternion& q);

		void FromObjectToWorldMatrix(const CMatrix4x3& m);
		void FromWorldToObjectMatrix(const CMatrix4x3& m);

		void FromRotationMatrix(const CRotationMatrix& rm);
	};
	extern const CEulerAngles g_kEulerAnglesIdentity;
}
#endif // euler_angles_h__
