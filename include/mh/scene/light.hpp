#ifndef	_MH_SCENE_LIGHT_HPP_
#define	_MH_SCENE_LIGHT_HPP_

#include "node.hpp"

namespace Mh
{
	namespace Scene
	{
		class Light : public Node
		{
		public:
			enum Type
			{
				LIGHT_DIRECTIONAL,	// 방향광
				LIGHT_POINT,		// 점광
				LIGHT_SPOT,			// 집중광(스포트라이트)
			};

			struct Desc
			{
				Type		type;
				ColorF		ambient;
				ColorF		diffuse;
				ColorF		emission;
			};

			struct Attenuation
			{
				f32		constant;
				f32		linear;
				f32		quadratic;
			};

		public:
			virtual ~Light();

			Type	type() const	{ return m_type; }

		protected:
			Light( Type type );

		private:
			Type	m_type;

			ColorF	m_ambient;
			ColorF	m_diffuse;
			ColorF	m_specular;
			ColorF	m_emission;
		};

		/*!
		 *	방향광
		 */
		class DirectionalLight : public Light
		{
		public:
			DirectionalLight();
			virtual ~DirectionalLight();

			const Vector3&	get_direction() const	{ return m_direction; }

		private:
			Vector3			m_direction;
		};

		/*!
		 *	점광
		 */
		class PointLight : public Light
		{
		public:
			PointLight();
			virtual ~PointLight();

			const Attenuation& get_attenuation() const	{ return m_attenuation; }

		private:
			Attenuation		m_attenuation;

		};

		/*!
		 *	집중
		 */
		class SpotLight : public Light
		{
		public:
			SpotLight();
			virtual SpotLight();

			const Vector3&	get_direction() const	{ return m_direction; }

		private:
			Vector3			m_direction;
			Attenuation		m_attenuation;
			f32				m_falloff;
		};

	}	// namespace Mh::Scene
}		// namespace Mh

#endif	/* _MH_SCENE_LIGHT_HPP_ */