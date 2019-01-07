#ifndef	_MH_PATTERN_OBSERVER_HPP_
#define	_MH_PATTERN_OBSERVER_HPP_

#include <set>
#include <algorithm>

namespace Mh
{
	class IObservable;

	// 과제 인터페이스
	class ISubject
	{
	protected:
		ISubject()		{}
		~ISubject()		{}

	public:
		void	register_obsever( IObservable* observer )		{ m_observers.insert( observer ); }
		void	unregister_observer( IObservable* observer )	{ m_observers.erase( observer ); }
		void	notify();
		//void	notify( Event event );

	private:
		std::set<IObservable*>	m_observers;
	};


	// 옵저버 인터페이스
	class IObservable
	{
	protected:
		IObservable()		{}
		~IObservable()		{}

	public:
		void	subscribe( ISubject* subject )		{ subject->register_obsever( this ); }
		void	unsubscribe( ISubject* subject )	{ subject->unregister_observer( this ); }
		virtual void	on_notified() = 0;
	};

}		// namespace Mh

#endif	/* _MH_PATTERN_OBSERVER_HPP */