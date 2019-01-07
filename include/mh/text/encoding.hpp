#ifndef	_MH_TEXT_ENCODING_HPP_
#define	_MH_TEXT_ENCODING_HPP_

/*
 *	C# 의 System.Text.Encoding 클래스를 모방한 것(GameDevForever)
 */
namespace Mh
{
	namespace Text
	{
		class Encoding
		{
		public:
			Encoding();
			Encoding( int codepage );
			virtual ~Encoding();

			static Encoding& GetEncoding( int codepage );


		};

		class UTF8Encoding : public Encoding
		{
		public:
			UTF8Encoding();
			UTF8Encoding( bool );
			UTF8Encoding( bool, bool );

			//static Byte[] Convert( Encoding srcEncoding, Encoding dstEncoding, Byte[] bytes );
			//static Byte[] Convert( Encoding srcEncoding, Encoding dstEncoding, Byte[] bytes, int index, int count );
		};

	}	// namespace Mh::Text
}	// namespace

#endif	/* _MH_TEXT_ENCODING_HPP_ */