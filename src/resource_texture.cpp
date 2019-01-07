#include <mh/resource/texture.hpp>
#include <mh/atomic.hpp>

namespace Mh
{
	namespace Resource
	{
		Texture::Texture( TextureManager* creator )
			: Object( creator )
		{}

		Texture::~Texture()
		{}

		// TextureManager
		TextureManager::TextureManager()
		{}

		TextureManager::~TextureManager()
		{}

	}	// namespace Mh::Resource
}		// namespace Mh