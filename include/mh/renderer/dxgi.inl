#ifndef	_MH_RENDERER_DXGI_INL_
#define	_MH_RENDERER_DXGI_INL_

namespace Mh 
{

	// DXGI 멤버 함수 정의
	template<typename T>
	DXGI<T>::DXGI()
		:	m_module( NULL )
		,	m_factory( NULL )
		,	m_device( NULL )
	{}

	template<typename T>
	DXGI<T>::~DXGI()
	{}

	template<typename T>
	bool DXGI<T>::initialize()
	{
		if( !this->load_module() )
			return false;

		if( !this->create_factory() )
			return false;

		this->enum_adapters( m_factory );

		return true;
	}

	template<typename T>
	void DXGI<T>::finalize()
	{
		SafeRelease( &m_device );
		SafeRelease( &m_factory );

		if( m_module )
		{
			::FreeLibrary( m_module );
			m_module = NULL;
		}
	}

	template<typename T>
	bool DXGI<T>::load_module()
	{
		m_module = LoadLibrary( TEXT("dxgi.dll") );
		return ( m_module != NULL );
	}

	template<typename T>
	bool DXGI<T>::create_factory()
	{
		typedef HRESULT (WINAPI *CreateFactoryFunc)(REFIID riid, void **ppFactory);
		
		CreateFactoryFunc pf = NULL;
		HRESULT hr;

		// get function address
		{
			switch( version() )
			{
			case DXGI_VERSION_1:
				pf = (CreateFactoryFunc)::GetProcAddress( m_module, "CreateDXGIFactory" );
				break;
			case DXGI_VERSION_1_1:
				pf = (CreateFactoryFunc)::GetProcAddress( m_module, "CreateDXGIFactory1" );;
				break;
			default:
				return false;
			}
		
			if( NULL == pf )
				return false;
		}

		// call funcion
		{
			hr = (*pf)( __uuidof(Factory), reinterpret_cast<void**>( &m_factory ) );
			if( FAILED(hr) )
				return false;
		}
		
		return true;
	}

	template<typename T>
	bool DXGI<T>::enum_adapters( ::IDXGIFactory* factory )
	{
		UINT i = 0;
		Adapter* adapter;
		while( DXGI_ERROR_NOT_FOUND != factory->EnumAdapters( i, &adapter ) )
		{
			m_adapters.push_back( adapter );
			++i;
		}

		return ( !m_adapters.empty() );
	}

	template<typename T>
	bool DXGI<T>::enum_adapters( ::IDXGIFactory1* factory )
	{
		UINT i = 0;
		Adapter* adapter;
		while( DXGI_ERROR_NOT_FOUND != factory->EnumAdapters1( i, &adapter ) )
		{
			m_adapters.push_back( adapter );
			++i;
		}

		return ( !m_adapters.empty() );
	}

	template<typename T>
	bool DXGI<T>::create_swap_chain( ::IUnknown* device, ::UINT width, ::UINT height )
	{
		::DXGI_SWAP_CHAIN_DESC desc;
		ZeroMemory( &desc, sizeof(::DXGI_SWAP_CHAIN_DESC) );
		desc.BufferDesc.Width = width;
		desc.BufferDesc.Height = height;
		desc.BufferDesc.Format = ::DXGI_FORMAT_B8G8R8A8_UNORM;
		desc.BufferDesc.RefreshRate.Numerator = 60;
		desc.BufferDesc.RefreshRate.Denominator = 1;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.BufferUsage = (DXGI_USAGE_RENDER_TARGET_OUTPUT);
		desc.BufferCount = 1;
		desc.OutputWindow = g_hwnd;
		desc.Windowed = TRUE;
		desc.Flags = ::DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		
		if( FAILED( m_factory->CreateSwapChain( device, &desc, &m_swap_chain ) ) )
			return false;

		return true;
	}

	template<typename T>
	bool DXGI<T>::resize( uint width, uint height )
	{
		HRESULT hr = m_swap_chain->ResizeBuffers( 1, width, height, DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH);
		
		return SUCCEEDED( hr );
	}
}

#endif	/* _MH_RENDERER_DXGI_INL */