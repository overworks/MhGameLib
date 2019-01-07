#ifndef _MH_D2D1_HPP_
#define _MH_D2D1_HPP_

#include <d2d1.h>
#include <d2d1_1.h>
#include <d2d1_2.h>

#pragma comment(lib, "d2d1")

namespace Mh
{
	struct D2D1TraitCommon
	{
		typedef	::ID2D1Brush		Brush;
		typedef	::ID2D1RenderTarget	RenderTarget;
	};

	struct D2D1_0Trait : public D2D1TraitCommon
	{
		typedef	::ID2D1Factory		Factory;
		typedef	::ID2D1Device		Device;
		typedef	::ID2D1Bitmap		Bitmap;
		typedef	::ID2D1BitmapBrush	BitmapBrush;
	};

	struct D2D1_1Trait : public D2D1TraitCommon
	{
		typedef	::ID2D1Factory1		Factory;
		typedef	::ID2D1Device1		Device;
		typedef	::ID2D1Bitmap1		Bitmap;
		typedef	::ID2D1BitmapBrush1	BitmapBrush;
	};

    // Direct2D 래퍼 클래스
	template<typename Trait>
	class D2D1WrapperT
	{
	public:
		typedef	typename Trait::Factory		Factory;
		typedef	typename Trait::Device		Device;
		typedef	typename Trait::Bitmap		Bitmap;
		typedef	typename Trait::BitmapBrush	BitmapBrush;

	public:
		D2D1WrapperT()
			: m_factory(nullptr)
		{}

		~D2D1WrapperT()
		{
			SafeRelease(&m_factory);
		}

		bool initialize(HWND hwnd)
		{
			HRESULT hr = ::D2D1CreateFactory(::D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
			if (FAILED(hr))
				return false;

			RECT rect;
			::GetClientRect(hwnd, &rect);

			::ID2D1HwndRenderTarget* pRt = NULL;
			hr = m_factory->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(rect.right - rect.left, rect.bottom - rect.top)),
				&pRt
			);
			if (FAILED(hr))
				return false;

			return true;
		}

	private:
		Factory*	m_factory;
	};

	typedef	D2D1WrapperT<D2D1_0Trait>	D2D1Wrapper;
}

#endif  // _MH_D2D1_HPP_