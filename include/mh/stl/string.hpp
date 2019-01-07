#ifndef	_MH_STL_STRING_HPP_
#define	_MH_STL_STRING_HPP_

#include "iterator.hpp"

/*
 *	커스텀 string 클래스(연습)
 */

namespace Mh
{
	template<typename charT>
	struct char_traits
	{
		typedef	charT	char_type;
		typedef	int		int_type;
		typedef	streampos	pos_type;
		typedef	streamoff	off_type;
		typedef	mbstate_t	state_type;
		static void assign(char_type& c1, char_type& c2) { c1 = c2; }
		static void eq(const char_type& c1, const char_type& c2);
		static void lt(const char_type& c1, const char_type& c2);
		static int compare(const char_type* c1, const char_type* c2, size_t n);
		static size_t length(const char_type* s);
		static const char_type* find(const char_type* s, size_t n, const char_type& a);
		static char_type* move(char_type* s1, const char_type* s2, size_t n);
		static char_type* copy(char_type* s1, const char_type* s2, size_t n);
		static char_type* assign(char_type* s, size_t n, char_type a);
	};

	template<>
	struct char_traits<char>
	{
		typedef char		char_type;
		typedef	int			int_type;
		typedef	streampos	pos_type;
		typedef	streamoff	off_type;
		typedef	mbstate_t	state_type;

		static void assign(char_type& c1, const char_type& c2) { c1 = c2; }
		static void eq(const char_type& c1, const char_type& c2) { return c1 == c2; }
		static void lt(const char_type& c1, const char_type& c2) { return c1 < c2; }
		static size_t length(const char_type& s) { return strlen(s); }
	};

	template<>
	struct char_traits<wchar_t>;

	template<typename charT, typename traits = char_traits<charT>, typename Allocator = allocator<charT> >
	class basic_string
	{
	public:
		typedef	Allocator	allocator_type;
		typedef	typename Allocator::size_type		size_type;
		typedef	typename Allocator::reference		reference;
		typedef	typename Allocator::const_reference	const_reference;

		class iterator
		{
		public:
			iterator();
			~iterator();
			
			void operator + ();

		private:
			charT*	m_ptr;
		};

		class const_iterator
		{
		public:
			const_iterator();
			~const_iterator();

		private:
			const charT*	m_ptr;
		};

		typedef	Mh::reverse_iterator<iterator>			reverse_iterator;
		typedef	Mh::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:

		/*
		 *	내부 문자열. 애초에 private 클래스이므로 굳이 데이터 멤버를 private으로 할 필요는 없음. 그게 더 귀찮...
		 */
		class Internal
		{
		public:
			Internal( const charT* str, const Allocator& allocator );
			~Internal();

			Allocator	allocator;
			charT*		buffer;
			size_type	length;
			size_type	capacity;
			size_type	reference;
		};

	public:
		/*!
		 *	BasicString()
		 *
		 *	\brief	빈 문자열을 생성
		 */
		explicit basic_string( const Allocator& a = Allocator() );
		/*!
		 *	BasicString()
		 *
		 *	\brief	다른 문자열의 복사본을 생성
		 */
		basic_string( const basic_string& str );
		/*!
		 *	BasicString()
		 *
		 *	\brief	다른 문자열의 특정 부위를 생성
		 */
		basic_string( const basic_string& str, size_type pos, size_type n = npos, const Allocator& a = allocator() );
		basic_string( const charT* s, size_t n, const Allocator& a = allocator() );
		basic_string( const charT* s, const Allocator& a = allocator() );
		basic_string( size_type n, charT c, const Allocator& a = allocator() );
		template<typename InputIterator> basic_string( InputIterator begin, InputIterator end );

		/*!
		 *	append()
		 *
		 *	\brief	문자열 추가
		 */
		basic_string&	append( const basic_string& str );
		basic_string&	append( const basic_string& str, size_type pos, size_type n );
		basic_string&	append( const charT* s, size_type n );
		basic_string&	append( const charT* s );
		basic_string&	append( size_type n, charT c );
		template <class InputIterator> basic_string& append( InputIterator first, InputIterator last );

		/*!
		 *	assign()
		 *
		 *	\brief	새로운 문자열 대입
		 */
		basic_string&	assign( const basic_string& str );
		basic_string&	assign( const basic_string& str, size_type pos, size_type n );
		basic_string&	assign( const charT* s, size_type n );
		basic_string&	assign( const charT* s );
		basic_string&	assign( size_type n, charT c );
		template <class InputIterator> basic_string& assign( InputIterator first, InputIterator last );

		/*!
		 *	at()
		 *
		 *	\brief	특정 위치의 문자를 취득
		 */
		const_reference	at( size_type pos ) const;
		reference		at( size_type pos );

		/*!
		 *	capacity()
		 *
		 *	\brief	문자열 개체에 할당된 크기를 반환
		 */
		size_type	capacity() const;

		/*!
		 *	clear()
		 *
		 *	\brief	문자열을 비움
		 */
		void	clear();

		/*!
		 *	compare()
		 *
		 *	\brief	다른 문자열과 비교
		 *	\return	같은 문자열이면 0
		 */
		int		compare( const basic_string& str ) const;
		int		compare( const charT* s ) const;
		int		compare( size_type pos1, size_type n1, const basic_string& str ) const;
		int		compare( size_type pos1, size_type n1, const charT* s ) const;
		int		compare( size_type pos1, size_type n1, const basic_string& str, size_t pos2, size_type n2 ) const;
		int		compare( size_type pos1, size_type n1, const charT* s, size_type n2 ) const;

		/*!
		 *	copy()
		 *
		 *	\brief	문자 배열로 복사
		 */
		size_type	copy( charT* s, size_type n, size_type pos = 0 ) const;

		/*!
		 *	c_str()
		 *
		 *	\brief	C 스타일 Null-terminated 문자열로 출력
		 */
		const charT*	c_str() const;

		/*!
		 *	data()
		 *
		 *	\brief	문자열과 같은 문자 배열의 포인터를 반환 (null문자를 포함하지 않음)
		 */
		const charT*	data() const;

		/*!
		 *	empty()
		 *
		 *	\brief	문자열이 비어있는지 확인
		 */
		bool	empty() const;

		/*!
		 *	begin()
		 *
		 *	\brief	시작 부분의 반복자를 얻
		 */
		iterator		begin();
		const_iterator	begin() const;

		/*!
		 *	end()
		 *
		 *	\brief	마지막 문자 다음의 반복자를 반환
		 */
		iterator		end();
		const_iterator	end() const;

		/*!
		 *	erase()
		 *
		 *	\brief	문자열에서 특정 부위를 삭제
		 */
		basic_string&	erase( size_type pos = 0, size_type n = npos );
		iterator		erase( iterator position );
		iterator		erase( iterator first, iterator last );

		allocator_type	get_allocator() const;

		basic_string&	operator =	( const basic_string& str );
		basic_string&	operator =	( const charT* s );
		basic_string&	operator =	( charT c );

		reference		operator []	( size_type n );
		const_reference	operator []	( size_type n ) const;

	public:
		static const size_t npos = -1;

	private:
		Internal*		m_internal;
		Allocator		m_allocator;
	};

	typedef basic_string<char>		string;
	typedef	basic_string<wchar_t>	wstring;

	template<typename T, typename Traits, typename Allocator> void swap( basic_string<T, Traits, Allocator>& l, basic_string<T, Traits, Allocator>& r );

#include "string.inl"

}		// namespace Mh

#endif	/* _MH_STL_STRING_HPP_ */