#ifndef	_MH_RESOURCE_TEXTURE_HPP_
#define	_MH_RESOURCE_TEXTURE_HPP_

#include <memory>
#include <mh/types.hpp>
#include "base.hpp"

#define	RESOURCE_TEXTURE_INTERFACE(terminal)\
	RESOURCE_OBJECT_INTERFACE(terminal)

#define	RESOURCE_TEXTURE_BASE_INTERFACE()		RESOURCE_TEXTURE_INTERFACE(=0;)
#define	RESOURCE_TEXTURE_DERIVED_INTERFACE()	RESOURCE_TEXTURE_INTERFACE(;)


#define	RESOURCE_TEXTURE_MANAGER_INTERFACE(terminal)\
	RESOURCE_MANAGER_INTERFACE(terminal)\
	virtual	TexturePtr	create_texture( size_t width, size_t height, size_t level, Texture::PixelFormat pf ) ## terminal\

#define	RESOURCE_TEXTURE_MANAGER_BASE_INTERFACE()		RESOURCE_TEXTURE_MANAGER_INTERFACE(=0;)
#define	RESOURCE_TEXTURE_MANAGER_DERIVED_INTERFACE()	RESOURCE_TEXTURE_MANAGER_INTERFACE(;)


namespace Mh
{
	namespace Resource
	{
		class Texture;
		class TextureManager;

		typedef	std::tr1::shared_ptr<Texture>	TexturePtr;

		class MH_CLASS Texture : public Object
		{
			friend class TextureManager;

		public:
			enum PixelFormat
			{
				PF_UNKNOWN,
				PF_RGB8,
				PF_R5G6B5,
				PF_RGBA8,
				PF_ARGB8,

				PF_DXT1,
				PF_DXT2,
				PF_DXT3,
				PF_DXT4,
				PF_DXT5,

				PF_PVRTC_RGB2,
				PF_PVRTC_RGBA2,
				PF_PVRTC_RGB4,
				PF_PVRTC_RGBA4,

				PF_ATITC_ATC,
				PF_ATITC_ATCA,
				PF_ATITC_ATCI,

				PF_ETC1,

				MAX_PIXEL_FORMAT = 0xffffffff
			};

			enum PixelFormatFlags
			{
				PFF_HAS_ALPHA	= 0x00000001,
				PFF_COMPRESSED	= 0x00000002,
				PFF_FLOAT		= 0x00000004,
			};

		public:
			Texture( TextureManager* creator );
			virtual ~Texture();
			RESOURCE_TEXTURE_BASE_INTERFACE();

			size_t		width() const						{ return m_width; }
			size_t		height() const						{ return m_height; }

			PixelFormat	pixel_format() const				{ return m_pf; }

		protected:
			void		set_width( size_t width )			{ m_width = width; }
			void		set_height( size_t height )			{ m_height = height; }
			void		set_pixel_format( PixelFormat pf )	{ m_pf = pf; }

		private:
			size_t				m_width;
			size_t				m_height;

			PixelFormat			m_pf;
			PixelFormatFlags	m_pff;
		};

		class MH_CLASS TextureManager : public Manager
		{
		public:
			TextureManager();
			virtual ~TextureManager();
		};
	}
}		// namespace Mh

#endif	/* _MH_RESOURCE_TEXTURE_HPP_ */