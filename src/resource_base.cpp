#include <mh/resource/base.hpp>

namespace Mh
{
	namespace Resource
	{
		// Object
		Object::Object( Manager* creator )
			:	m_creator( creator )
		{}

		Object::~Object()
		{}

	
		// Listener
		Listener::Listener()
		{}

		Listener::~Listener()
		{}


		// Manager
		Manager::Manager()
		{}

		Manager::~Manager()
		{}

	}	// namespace Mh::Resource
}		// namespace Mh