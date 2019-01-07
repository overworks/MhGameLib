/*
 *	ColorI
 */
inline
ColorI::ColorI( u8 _r, u8 _g, u8 _b, u8 _a )
:	r(_r), g(_g), b(_b), a(_a)
{
}

inline
ColorI::ColorI( u32 rgba )
{
	set( rgba );
}

inline
ColorI::ColorI( const ColorF& colorf )
{
	set( colorf );
}

inline ColorI&
ColorI::set( u8 _r, u8 _g, u8 _b, u8 _a )
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
	return (*this);
}

inline ColorI&
ColorI::set( u32 rgba )
{
	r = static_cast<u8>(((rgba) & 0xff000000) >> 24);
	g = static_cast<u8>(((rgba) & 0x00ff0000) >> 16);
	b = static_cast<u8>(((rgba) & 0x0000ff00) >> 8);
	a = static_cast<u8>(((rgba) & 0x000000ff) >> 0);
	return (*this);
}

inline ColorI&
ColorI::set( const ColorF& colorf )
{
	r = static_cast<u8>( colorf.r * 255.0f );
	g = static_cast<u8>( colorf.g * 255.0f );
	b = static_cast<u8>( colorf.b * 255.0f );
	a = static_cast<u8>( colorf.a * 255.0f );
	return (*this);
}


inline ColorI&
ColorI::invert()
{
	return set( 255 - r, 255 - g, 255 - b, a );
}

/*
inline u32
ColorI::to_argb() const
{
	return argb;
}

inline u32
ColorI::to_argb() const
{
	const u32 _r = ( static_cast<u32>(r) << 16 );
	const u32 _g = ( static_cast<u32>(g) << 8 );
	const u32 _b = ( static_cast<u32>(b) << 0 );
	const u32 _a = ( static_cast<u32>(a) << 24 );
	const u32 ret = _r + _g + _b + _a;
	return ret;
}

inline u32
ColorI::to_rgbx() const
{
	const u32 _r = ( static_cast<u32>(r) << 24 );
	const u32 _g = ( static_cast<u32>(g) << 16 );
	const u32 _b = ( static_cast<u32>(b) << 8 );
	const u32 _a = ( 0x000000ff );
	const u32 ret = _r + _g + _b + _a;
	return ret;
}

inline u32
ColorI::to_xrgb() const
{
	const u32 _r = ( static_cast<u32>(r) << 16 );
	const u32 _g = ( static_cast<u32>(g) << 8 );
	const u32 _b = ( static_cast<u32>(b) << 0 );
	const u32 _a = ( 0xff000000 );
	const u32 ret = _r + _g + _b + _a;
	return ret;
}
*/

inline ColorI
ColorI::from_argb( u32 argb )
{
	return ColorI( argb );
}

inline ColorI
ColorI::from_rgba( u32 rgba )
{
#if 0
	const u8 r = static_cast<u8>( (rgba & 0xff000000) >> 24 );
	const u8 g = static_cast<u8>( (rgba & 0x00ff0000) >> 16 );
	const u8 b = static_cast<u8>( (rgba & 0x0000ff00) >> 8 );
	const u8 a = static_cast<u8>( (rgba & 0x000000ff) >> 0 );
	return ColorI( r, g, b, a );
#else
	const u32 a = (rgba & 0xff000000) >> 24;
	return ColorI( (rgba << 8) + a );
#endif
}

inline ColorI
ColorI::from_xrgb( u32 xrgb )
{
#if 0
	const u8 r = static_cast<u8>( (xrgb & 0x00ff0000) >> 16 );
	const u8 g = static_cast<u8>( (xrgb & 0x0000ff00) >> 8 );
	const u8 b = static_cast<u8>( (xrgb & 0x000000ff) >> 0 );
	return ColorI( r, g, b );
#else
	return ColorI( xrgb & 0x00ffffff );
#endif
}
inline ColorI
ColorI::from_rgbx( u32 rgbx )
{
#if 0
	const u8 r = static_cast<u8>( (rgbx & 0xff000000) >> 24 );
	const u8 g = static_cast<u8>( (rgbx & 0x00ff0000) >> 16 );
	const u8 b = static_cast<u8>( (rgbx & 0x0000ff00) >> 8 );
	return ColorI( r, g, b );
#else
	return ColorI(rgbx << 8);
#endif
}

inline u32
ColorI::to_argb( const ColorI& colori )
{
	return (((u32)colori.r << 16) | ((u32)colori.g << 8) | ((u32)colori.b) | ((u32)colori.a << 24));
}

inline u32
ColorI::to_rgba( const ColorI& colori )
{
	return (((u32)colori.r << 24) | ((u32)colori.g << 16) | ((u32)colori.b << 8) | ((u32)colori.a));
}

inline u32
ColorI::to_xrgb( const ColorI& colori )
{
	return (((u32)colori.r << 16) | ((u32)colori.g << 8) | ((u32)colori.b));
}

inline u32
ColorI::to_rgbx( const ColorI& colori )
{
	return (((u32)colori.r << 24) | ((u32)colori.g << 16) | ((u32)colori.b << 8));
}

inline ColorI
ColorI::invert( const ColorI& colori )
{
	ColorI temp = colori;
	temp.invert();
	return temp;
}

inline bool
operator == ( const ColorI& lhs, const ColorI& rhs )
{
	return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b) && (lhs.a == rhs.a);
}

inline bool
operator != ( const ColorI& lhs, const ColorI& rhs )
{
	return !( lhs == rhs );
}

inline u8&
ColorI::operator [] ( size_t index )
{
	return *( &r + index );
}

inline u8
ColorI::operator [] ( size_t index ) const
{
	return *( &r + index );
}


/*
 *	ColorF
 */
inline
ColorF::ColorF( f32 _r, f32 _g, f32 _b, f32 _a )
:	r(_r), g(_g), b(_b), a(_a)
{}

inline
ColorF::ColorF( u32 rgba )
{
	set( rgba );
}

inline
ColorF::ColorF( const ColorI& colori )
{
	set( colori );
}

inline ColorF&
ColorF::set( f32 _r, f32 _g, f32 _b, f32 _a )
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
	return *this;
}

inline ColorF&
ColorF::set( u32 rgba )
{
	const f32 reciprocal = 1.0f / 255.0f;
	r = ( ( rgba & 0xff000000 ) >> 24 ) * reciprocal;
	g = ( ( rgba & 0x00ff0000 ) >> 16 ) * reciprocal;
	b = ( ( rgba & 0x0000ff00 ) >> 8 ) * reciprocal;
	a = ( ( rgba & 0x000000ff ) >> 0 ) * reciprocal;
	return *this;
}

inline ColorF&
ColorF::set( const ColorI& colori )
{
	return set( ColorI::to_rgba( colori ) );
}

inline ColorF&
ColorF::invert()
{
	r = 1.0f - r;
	g = 1.0f - g;
	b = 1.0f - b;
	return *this;
}

inline ColorF&
ColorF::saturate()
{
	if ( r > 1.0f ) r = 1.0f; else if ( r < 0.0f ) r = 0.0f;
	if ( g > 1.0f ) g = 1.0f; else if ( g < 0.0f ) g = 0.0f;
	if ( b > 1.0f ) b = 1.0f; else if ( b < 0.0f ) b = 0.0f;
	if ( a > 1.0f ) a = 1.0f; else if ( a < 0.0f ) a = 0.0f;
	return *this;
}

#if 0
inline u32
ColorF::to_argb() const
{
	const u32 _r = ( static_cast<u32>( r * 255.0f ) << 24 );
	const u32 _g = ( static_cast<u32>( g * 255.0f ) << 16 );
	const u32 _b = ( static_cast<u32>( b * 255.0f ) << 8 );
	const u32 _a = ( static_cast<u32>( a * 255.0f ) << 0 );
	const u32 argb = (_r | _g | _b | _a);
	return argb;
}

inline u32
ColorF::to_argb() const
{
	const u32 _r = ( static_cast<u32>( r * 255.0f ) << 16 );
	const u32 _g = ( static_cast<u32>( g * 255.0f ) << 8 );
	const u32 _b = ( static_cast<u32>( b * 255.0f ) << 0 );
	const u32 _a = ( static_cast<u32>( a * 255.0f ) << 24 );
	const u32 argb = _r + _g + _b + _a;
	return argb;
}

inline u32
ColorF::to_rgbx() const
{
	const u32 _r = ( static_cast<u32>( r * 255.0f ) << 24 );
	const u32 _g = ( static_cast<u32>( g * 255.0f ) << 16 );
	const u32 _b = ( static_cast<u32>( b * 255.0f ) << 8 );
	const u32 _a = 0x000000ff;
	const u32 argb = _r + _g + _b + _a;
	return argb;
}

inline ColorF
ColorF::saturate( const ColorF& colorf )
{
	ColorF ret = colorf;
	ret.saturate();
	return ret;
}

inline u32
ColorF::to_xrgb() const
{
	const u32 _r = ( static_cast<u32>( r * 255.0f ) << 16 );
	const u32 _g = ( static_cast<u32>( g * 255.0f ) << 8 );
	const u32 _b = ( static_cast<u32>( b * 255.0f ) << 0 );
	const u32 _a = 0xff000000;
	const u32 argb = _r + _g + _b + _a;
	return argb;
}
#endif

inline f32&
ColorF::operator [] ( size_t index )
{
	return *( &r + index );
}

inline f32
ColorF::operator [] ( size_t index ) const
{
	return *( &r + index );
}

inline ColorF
ColorF::from_argb( u32 argb )
{
	return ColorF((argb >> 24) | (argb << 8));
}

inline ColorF
ColorF::from_rgba( u32 rgba )
{
	return ColorF( rgba );
}

inline ColorF
ColorF::from_xrgb( u32 xrgb )
{
	return ColorF( xrgb << 8 );
}

inline ColorF
ColorF::from_rgbx( u32 rgbx )
{
	return ColorF(rgbx & 0xffffff00);
}

inline u32
ColorF::to_argb( const ColorF& colorf )
{
	const ColorI temp( colorf );
	return ColorI::to_argb( temp );
}

inline u32
ColorF::to_rgba( const ColorF& colorf )
{
	const ColorI temp( colorf );
	return ColorI::to_rgba( temp );
}

inline u32
ColorF::to_xrgb( const ColorF& colorf )
{
	const ColorI temp( colorf );
	return ColorI::to_xrgb( temp );
}

inline u32
ColorF::to_rgbx( const ColorF& colorf )
{
	const ColorI temp( colorf );
	return ColorI::to_rgbx( temp );
}

inline ColorF
ColorF::invert( const ColorF& colorf )
{
	ColorF temp = colorf;
	temp.invert();
	return temp;
}

#if 0
inline ColorF
ColorF::saturate( const ColorF& colorf )
{
	ColorF temp = colorf;
	temp.saturate();
	return temp;
}
#endif

inline bool
operator == ( const ColorF& lhs, const ColorF& rhs )
{
	return ( lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a );
}

inline bool
operator != ( const ColorF& lhs, const ColorF& rhs )
{
	return !( lhs == rhs );
}
