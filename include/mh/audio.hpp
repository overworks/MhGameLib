#ifndef	_MH_AUDIO_HPP_
#define	_MH_AUDIO_HPP_

/*!
 *	오디오 관련 인터페이스
 */

#include <mh/prerequisite.h>
#include <mh/util.hpp>
#include <mh/math.hpp>

#define	AUDIO_BUFFER_INTERFACE(terminal)\
	virtual void	close() ## terminal\

#define	AUDIO_BUFFER_BASE_INTERFACE()		AUDIO_BUFFER_INTERFACE(= 0;)
#define	AUDIO_BUFFER_DERIVED_INTERFACE()	AUDIO_BUFFER_INTERFACE(;)

#define AUDIO_SOURCE_INTERFACE(terminal)\
	virtual	void	play() ## terminal\
	virtual	void	stop() ## terminal\
	virtual void	rewind() ## terminal\
	virtual	void	pause() ## terminal\
	virtual	void	set_loop( bool loop ) ## terminal\
	virtual	void	set_position( const Float3& position ) ## terminal\
	virtual	void	set_direction( const Vector3& direction ) ## terminal\
	virtual	void	set_velocity( const Vector3& velocity ) ## terminal\
	virtual	bool	is_loop() const ## terminal\
	virtual	Float3	get_position() const ## terminal\
	virtual	Vector3	get_direction() const ## terminal\
	virtual	Vector3	get_velocity() const ## terminal\
	virtual	void	get_position( Float3* position ) const ## terminal\
	virtual	void	get_direction( Vector3* direction ) const ## terminal\
	virtual	void	get_velocity( Vector3* velocity ) const ## terminal\

#define	AUDIO_SOURCE_BASE_INTERFACE()		AUDIO_SOURCE_INTERFACE(= 0;)
#define	AUDIO_SOURCE_DERIVED_INTERFACE()	AUDIO_SOURCE_INTERFACE(;)

#define	AUDIO_LISTENER_INTERFACE(terminal)\
	virtual	void	set_position( const Float3& position ) ## terminal\
	virtual	void	set_direction( const Vector3& direction ) ## terminal\
	virtual	void	set_velocity( const Vector3& velocity ) ## terminal\
	virtual	Float3	get_position() const ## terminal\
	virtual	Vector3	get_direction() const ## terminal\
	virtual	Vector3	get_velocity() const ## terminal\
	virtual	void	get_position( Float3* position ) const ## terminal\
	virtual	void	get_direction( Vector3* direction ) const ## terminal\
	virtual	void	get_velocity( Vector3* velocity ) const ## terminal\

#define	AUDIO_LISTENER_BASE_INTERFACE()		AUDIO_LISTENER_INTERFACE(= 0;)
#define	AUDIO_LISTENER_DERIVED_INTERFACE()	AUDIO_LISTENER_INTERFACE(;)

#define	AUDIO_SYSTEM_INTERFACE(terminal)\
	virtual bool	initialize() ## terminal\
	virtual void	finalize() ## terminal\
	virtual	void	suspend() ## terminal\
	virtual void	process() ## terminal\

#define	AUDIO_SYSTEM_BASE_INTERFACE()		AUDIO_SYSTEM_INTERFACE(= 0;)
#define	AUDIO_SYSTEM_DERIVED_INTERFACE()	AUDIO_SYSTEM_INTERFACE(;)

namespace Mh
{
	namespace Audio
	{
		/*
		 *	사운드 데이터 수납용 버퍼. Resource 이름공간으로 옮길 가능성도?
		 */
		class MH_CLASS Buffer
		{
		public:
			Buffer();
			virtual ~Buffer();
			AUDIO_BUFFER_BASE_INTERFACE();
		};

		/*
		 *	음원 클래스
		 */
		class MH_CLASS Source
		{
		public:
			enum Format
			{
				FORMAT_WAVE,
			};

		public:
			Source();
			virtual ~Source();
			AUDIO_SOURCE_BASE_INTERFACE();
		};

		/*
		 *	청자 클래스
		 */
		class MH_CLASS Listener
		{
		public:
			Listener();
			virtual ~Listener();
			AUDIO_LISTENER_BASE_INTERFACE();
		};

		class MH_CLASS System
		{
		public:
			System();
			virtual ~System();
			AUDIO_SYSTEM_BASE_INTERFACE();
		};

	}	// namespace Mh::Audio
}		// namespace Mh

#endif	/* _MH_AUDIO_HPP_ */