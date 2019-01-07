#include <DirectXMath.h>

#include <mh/math.hpp>

namespace Mh
{
	// 상수 정의

	const Vector2 Vector2::ZERO(0.0f, 0.0f);
	const Vector2 Vector2::ONE(1.0f, 1.0f);
	const Vector2 Vector2::X_AXIS(1.0f, 0.0f);
	const Vector2 Vector2::Y_AXIS(0.0f, 1.0f);

	const Vector3 Vector3::ZERO(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::ONE(1.0f, 1.0f, 1.0f);
	const Vector3 Vector3::X_AXIS(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::Y_AXIS(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::Z_AXIS(0.0f, 0.0f, 1.0f);

	// Quaternion
	const Quaternion Quaternion::IDENTITY(
		0.0f, 0.0f, 0.0f, 1.0f
		);

	// Matrix3x3
	const Matrix3x3 Matrix3x3::ZERO(
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f
		);
	const Matrix3x3	Matrix3x3::IDENTITY(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
		);

	// Matrix4x4
	const Matrix4x4 Matrix4x4::ZERO(
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
		);
	const Matrix4x4 Matrix4x4::IDENTITY(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	// ColorI
	const ColorI ColorI::WHITE	(	255,	255,	255 );
	const ColorI ColorI::GRAY	(	128,	128,	128	);
	const ColorI ColorI::BLACK	(	  0,	  0,	  0	);
	const ColorI ColorI::RED	(	255,	  0,	  0	);
	const ColorI ColorI::GREEN	(	  0,	255,	  0	);
	const ColorI ColorI::BLUE	(	  0,	  0,	255	);

	// COlorF
	const ColorF ColorF::WHITE	(	1.0f,	1.0f,	1.0f	);
	const ColorF ColorF::GRAY	(	0.5f,	0.5f,	1.0f	);
	const ColorF ColorF::BLACK	(	0.0f,	0.0f,	0.0f	);
	const ColorF ColorF::RED	(	1.0f,	0.0f,	1.0f	);
	const ColorF ColorF::GREEN	(	0.0f,	1.0f,	0.0f	);
	const ColorF ColorF::BLUE	(	0.0f,	0.0f,	1.0f	);
	
}