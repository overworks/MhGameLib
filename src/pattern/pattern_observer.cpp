#include <functional>
#include <mh/pattern/observer.hpp>

namespace Mh
{
	void ISubject::notify()
	{
		std::for_each( m_observers.begin(), m_observers.end(), std::mem_fun( &IObservable::on_notified ) );
	}
}