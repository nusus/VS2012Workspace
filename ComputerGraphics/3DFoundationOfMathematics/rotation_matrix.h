#ifndef rotation_matrix_h__
#define rotation_matrix_h__

namespace tdfom {
	class CVector3;
	class CEulerAngles;
	class CQuaternion;
	class CRotationMatrix
	{
	public:
		float m_fM11, m_fM12, m_fM13;
		float m_fM21, m_fM22, m_fM23;
		float m_fM31, m_fM32, m_fM33;
	public:
		CRotationMatrix();
		~CRotationMatrix();

		void Identity();
		
		void Setup(const CEulerAngles& orientation); 

		void FromInertialToObjectQuaternion(const CQuaternion& q);

		void FromObjectToInertialQuaternion(const CQuaternion& q);

		CVector3 InertialToObejct(const CVector3& vec) const;

		CVector3 ObejctToInertial(const CVector3& vec) const;
	private:

	};
}
#endif // rotation_matrix_h__
