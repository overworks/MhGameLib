#ifndef	_MH_RESOURCE_BASE_HPP_
#define	_MH_RESOURCE_BASE_HPP_

#include <mh/prerequisite.h>
#include <list>

#define	RESOURCE_OBJECT_INTERFACE(terminal)\
	virtual void release() ## terminal\

#define	RESOURCE_OBJECT_BASE_INTERFACE()		RESOURCE_OBJECT_INTERFACE(=0;)
#define	RESOURCE_OBJECT_DERIVED_INTERFACE()		RESOURCE_OBJECT_INTERFACE(;)

#define	RESOURCE_LISTENER_INTERFACE(terminal)\
	virtual void on_loading_completed( Object* object ) ## terminal\
	virtual void on_preparing_completed( Object* object ) ## terminal\
	virtual void on_unloading_completed( Object* object ) ## terminal\

#define	RESOURCE_LISTENER_BASE_INTERFACE()		RESOURCE_LISTENER_INTERFACE(=0;)
#define	RESOURCE_LISTENER_DERIVED_INTERFACE()	RESOURCE_LISTENER_INTERFACE(;)

#define	RESOURCE_MANAGER_INTERFACE(terminal)\
	virtual bool initialize() ## terminal\
	virtual void finalize() ## terminal\

#define	RESOURCE_MANAGER_BASE_INTERFACE()		RESOURCE_MANAGER_INTERFACE(=0;)
#define	RESOURCE_MANAGER_DERIVED_INTERFACE()	RESOURCE_MANAGER_INTERFACE(;)

namespace Mh
{
	namespace Resource
	{
		class Object;
		class Listener;
		class Manager;

	//	MH_TEMPLATE template class MH_CLASS std::list<Listener*>;

		class MH_CLASS Object
		{
		public:
			typedef std::list<Listener*>	ListnerList;

			enum State
			{
				STATE_UNLOADED,
				STATE_LOADING,
				STATE_LOADED,
				STATE_UNLOADING,
				STATE_PREPARED,
				STATE_PREPARING,
			};

		public:
			Object( Manager* creator );
			virtual ~Object();
			RESOURCE_OBJECT_BASE_INTERFACE();

			void	add_listener( Listener* listener )		{ m_listener_list.push_back( listener ); }
			void	remove_listener( Listener* listener )	{ m_listener_list.remove( listener ); }

			State	get_state() const			{ return m_state; }

		protected:
			Manager*		get_creator()		{ return m_creator; }
			const Manager*	get_creator() const	{ return m_creator; }

		private:
			State			m_state;		// 원자적으로 처리해야함...
			Manager*		m_creator;
			ListnerList		m_listener_list;
		};

		class MH_CLASS Listener
		{
		public:
			Listener();
			virtual ~Listener();
			RESOURCE_LISTENER_BASE_INTERFACE();
		};

		/*!
		 *	리소스 관리 클래스
		 */
		class MH_CLASS Manager
		{
		public:
			Manager();
			virtual ~Manager();
			RESOURCE_MANAGER_BASE_INTERFACE();
		};

	}	// namespace Mh::Resource
}		// namespace Mh

#endif	/* _MH_RESOURCE_BASE_HPP_ */