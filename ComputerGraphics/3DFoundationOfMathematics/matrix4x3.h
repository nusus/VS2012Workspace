#ifndef matrix4x3_h__
#define matrix4x3_h__

namespace tdfom {
	class CVector3;
	class CEulerAngles;
	class CQuaternion;
	class CRotationMatrix;

	class CMatrix4x3
	{
	public:
		float m_fM11, m_fM12, m_fM13;
		float m_fM21, m_fM22, m_fM23;
		float m_fM31, m_fM32, m_fM33;
		float m_fTx, m_fTy, m_fTz;
	public:
		CMatrix4x3();
		~CMatrix4x3();


		void ZeroTranslation();

		void SetTranslation(const CVector3& d);

		void SetupTranslation(const CVector3& d);

		void SetupLocalToParent(const CVector3& pos, const CEulerAngles& orient);
		void SetupLocalToParent(const CVector3& pos, const CRotationMatrix& orient);

		void SetupParentToLocal(const CVector3& pos, const CEulerAngles& orient);
		void SetupParentToLocal(const CVector3& pos, const CRotationMatrix& orient);
	private:

	};
}
#endif // matrix4x3_h__
