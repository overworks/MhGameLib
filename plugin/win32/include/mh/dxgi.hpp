#ifndef _MH_DXGI_HPP_
#define _MH_DXGI_HPP_

#pragma comment(lib, "dxgi")

#include <dxgi.h>
#include <mh/util.hpp>

namespace Mh
{
	struct DXGITraitCommon
	{
		typedef	IDXGISwapChain	SwapChain;
	};

	struct DXGITrait1 : public DXGITraitCommon
	{
		typedef	IDXGIFactory	Factory;
		typedef IDXGIAdapter	Adapter;
	};

	struct DXGITrait1_1 : public DXGITraitCommon
	{
		typedef	IDXGIFactory1	Factory;
		typedef IDXGIAdapter1	Adapter;
	};

    // DXGI 래퍼 클래스
	template<typename DXGITrait>
    class DXGIWrapper
    {
	public:
		typedef	typename DXGITrait::SwapChain	SwapChain;
		typedef	typename DXGITrait::Adapter		Adapter;
		typedef	typename DXGITrait::Factory		Factory;

		DXGIWrapper()
			: m_factory(nullptr)
		{

		}

		~DXGIWrapper()
		{
			SafeRelease(&m_factory);
		}

		bool initialize()
		{
			return create_factory();
		}

		bool create_factory()
		{
			return create_factory(m_factory);
		}
		
	private:
		bool create_factory(IDXGIFactory*& factory)
		{
			HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory));
			return SUCCEEDED(hr);
		}

		bool create_factory(IDXGIFactory1*& factory)
		{
			HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&factory));
			return SUCCEEDED(hr);
		}

	private:
		Factory* m_factory;
    };

	typedef DXGIWrapper<DXGITrait1>	DXGIWrapper1;
}

#endif  // _MH_DXGI_HPP_