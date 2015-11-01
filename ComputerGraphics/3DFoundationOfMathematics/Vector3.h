/********************************************************************
	created:	2015/11/01
	created:	1:11:2015   22:27
	filename: 	F:\VSWorkspace\VS2012Workspace\ComputerGraphics\3DFoundationOfMathematics\Vector3.h
	file path:	F:\VSWorkspace\VS2012Workspace\ComputerGraphics\3DFoundationOfMathematics
	file base:	Vector3
	file ext:	h
	author:		zengli
	
	purpose:	
*********************************************************************/
#ifndef Vector3_h__
#define Vector3_h__

#include <cfloat>

namespace tdfom {

	//************************************
	// Description:卡马克开方法
	// Method:    CarmackSqrt
	// FullName:  tdfom::CarmackSqrt
	// Access:    public 
	// Returns:   float
	// Qualifier:
	// Parameter: float number
	//************************************
	float CarmackSqrt(float number);

	class Vector3
	{
	public:
		float x_, y_, z_;
	public:
		Vector3() {}
		Vector3(const Vector3& rhs) :
			x_(rhs.x_),
			y_(rhs.y_),
			z_(rhs.z_) {}
		Vector3(float x, float y, float z) :
			x_(x),
			y_(y),
			z_(z) {}

		~Vector3();


		Vector3& operator=(const Vector3& rhs) {
			x_ = rhs.x_;
			y_ = rhs.y_;
			z_ = rhs.z_;
			return *this;
		}

		bool operator == (const Vector3& rhs) const {
			return (x_ == rhs.x_) && (y_ == rhs.y_) && (z_ == rhs.z_);
		}
		bool operator!=(const Vector3& rhs) const {
			return x_ != rhs.x_ || y_ != rhs.y_ || z_ != rhs.z_;
		}

		void Zero() {
			x_ = y_ = z_ = 0.0f;
		}

		Vector3 operator - () const {
			return Vector3(-x_, -y_, -z_);
		}

		Vector3 operator+(const Vector3& rhs) const {
			return Vector3(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_);
		}


		Vector3 operator-(const Vector3& rhs) const {
			return Vector3(x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_);
		}

		Vector3 operator*(float a) const {
			return Vector3(x_ * a, y_ * a, z_ * a);
		}

		Vector3 operator/(float a) const {
			float one_over_a = 1.0f / a;
			return Vector3(x_ * one_over_a, y_ * one_over_a, z_ * one_over_a);
		}

		Vector3& operator+=(const Vector3& rhs) {
			x_ += rhs.x_;
			y_ += rhs.y_;
			z_ += rhs.z_;
			return *this;
		}

		Vector3& operator-=(const Vector3& rhs) {
			x_ -= rhs.x_;
			y_ -= rhs.y_;
			z_ -= rhs.z_;
			return *this;
		}

		Vector3& operator *=(float a) {
			x_ *= a;
			y_ *= a;
			z_ *= a;
			return *this;
		}

		Vector3& operator/=(float a) {
			float one_over_a = 1.0f / a;
			x_ *= one_over_a;
			y_ *= one_over_a;
			z_ *= one_over_a;
			return *this;
		}

		void Normalize() {
			float sq = x_ * x_ + y_ * y_ + z_ *z_;
			if (sq > 0.00f) {
				float one_over_sq = 1.0f / tdfom::CarmackSqrt(sq);
				x_ *= one_over_sq;
				y_ *= one_over_sq;
				z_ *= one_over_sq;
			}
		}

		float operator*(const Vector3& rhs) const {
			return x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_;
		}
	private:

	};

	inline float VectorMag(const Vector3& rhs) {
		return rhs.x_ * rhs.x_ + rhs.y_ * rhs.y_ + rhs.z_ * rhs.z_;
	}

	inline Vector3 CrossProduct(const Vector3& lhs, const Vector3& rhs) {
		return Vector3(
			lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_,
			lhs.z_ * rhs.x_ - lhs.x_ * rhs.z_,
			lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_
			);
	}

	inline Vector3 operator*(float k, const Vector3& rhs) {
		return Vector3(
			rhs.x_ * k,
			rhs.y_ * k,
			rhs.z_ * k
			);
	}

	inline float Distance(const Vector3& lhs, const Vector3& rhs) {
		float x = lhs.x_ - rhs.x_;
		float y = lhs.y_ - rhs.y_;
		float z = lhs.z_ - rhs.z_;
		return CarmackSqrt(x*x + y*y + z*z);
	}

	float CarmackSqrt(float number) {
		long i;
		float x, y;
		const float f = 1.5F;
		x = number * 0.5F;
		y = number;
		i = *(long *)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float *)&i;
		y = y* (f - (x * y * y));
		y = y * (f - (x * y * y));
		return number * y;
	}

	extern const Vector3 kZeroVector;
}
#endif // Vector3_h__