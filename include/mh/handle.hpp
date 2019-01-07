#ifndef _MH_HANDLE_HPP_
#define	_MH_HANDLE_HPP_

#include <mh/prerequisite.h>
#include <mh/types.hpp>

#include <vector>

namespace Mh
{
	/**
	 *	범용 핸들 템플릿 클래스
	 *
	 *	@details	내부적으로는 부호없는 정수(32비트)로 판단하는 핸들.
	 *				레퍼런스 카운트보다 좀 더 속도에 맞춘 것. 그만큼 안정성은 떨어짐.
	 *				GPG1의 내용을 사실상 그대로 가져옴.
	 *				멤버함수는 관리자 클래스에서 사용하므로 전부 private으로 만들고 friend 때리는게 나을지도?
	 *	@todo		멀티스레드 대응. 무효화되었는지는?
	 */
	template<typename T>
	class Handle
	{
	public:
		/**
		 *	@details	생성자. 내부 핸들을 0으로 초기화
		 */
		Handle() : m_handle(0)	{}
		/**
		 *	@details	초기화. 관리자에서 호출. 매직넘버 증가
		 */
		void init( u32 index )
		{
			m_index = index;
			// 여기서 매직넘버 증가... 매직넘버는 static?
		}

		u32 get_index() const	{ return m_index; }
		u32 get_magic() const	{ return m_magic; }
		u32 get_handle() const	{ return m_handle; }
		bool is_null() const	{ return !m_handle;}

		operator u32() const	{ return m_handle; }
		
	private:
		enum
		{
			MAX_BITS_INDEX = 16,
			MAX_BITS_MAGIC = 16,

			MAX_INDEX = (1 << MAX_BITS_INDEX) - 1,
			MAX_MAGIC = (1 << MAX_BITS_MAGIC) - 1,
		};

		union
		{
			struct
			{
				u32 m_index : MAX_BITS_INDEX;
				u32 m_magic : MAX_BITS_MAGIC;
			};
			u32 m_handle;
		};
	};

	/**
	 *	핸들 관리자
	 *
	 *	@details	핸들 관리자 클래스. 핸들의 멤버 함수는 여기서 다 처리함
	 *	@todo		컨테이너를 직접 지정할 수 있게 하면 좋을듯...
	 */
	template<typename T, typename Container = std::vector<T> >
	class HandleManager
	{
	public:
		HandleManager();

	private:
		Container	m_handles;
	};

	
}		// namespace Mh

#endif	/* _MH_HANDLE_HPP_ */