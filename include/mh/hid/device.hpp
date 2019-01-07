#ifndef	_MH_HID_DEVICE_HPP_
#define	_MH_HID_DEVICE_HPP_

namespace Mh
{
	namespace HID
	{
		enum DeviceType
		{
			DEVICE_UNKNOWN,
			DEVICE_MOUSE,
			DEVICE_KEYBOARD,
			DEVICE_GAMEPAD,
		};
		
		// 매니저에서 초기화할때 쓰기 위해...
		enum DeviceFlag
		{
			FLAG_MOUSE		= (1 << 0),
			FLAG_KEYBOARD	= (1 << 1),
			FLAG_GAMEPAD1	= (1 << 2),
			FLAG_GAMEPAD2	= (1 << 3),
			FLAG_GAMEPAD3	= (1 << 4),
			FLAG_GAMEPAD4	= (1 << 5),
		};
		
		// 장치 기본 인터페이스 클래스. 공통 메서드들을 모아놓기 위해 만들긴 했는데...
		class Device
		{
		public:
			class Handler
			{
			public:
				Handler();
				virtual ~Handler();
			};
			
		protected:
			Device( DeviceType type );
			virtual ~Device();
			
		public:
			// 여기서 베이스 클래스를 등록하면 추가된 메서드를 호출하지 못하는 문제가 생기는데...
			// 각 클래스별로 멤버 변수를 추가할 것인지, 멤버 함수에서 타입 캐스팅해서 쓸 것인지는 알아서...
			// ...아무래도 그냥 따로 추가해서 쓰는게 나을것 같음. 공통점이 너무 없다...
			//bool set_handler( Handler* handler ) = 0;
			DeviceType get_type() const		{ return m_type; }
			
		private:
			DeviceType	m_type;
			Handler*	m_handler;
		};

	}	// namespace Mh::HID
}		// namespace Mh

#endif	/* _MH_HID_DEVICE_HPP_ */