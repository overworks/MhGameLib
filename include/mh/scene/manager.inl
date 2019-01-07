namespace Mh
{
	namespace Scene
	{
		inline void Manager::set_camera( Camera* camera )
		{
			assert( camera );
			m_current_camera = camera;
		}

		inline void Manager::render(Renderer* renderer)
		{
			std::for_each(m_node_list.begin(), m_node_list.end(), std::bind2nd(std::mem_fun(&Node::render), renderer));
		}
	}
}	// namespace Mh