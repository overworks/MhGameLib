inline
Line3::Line3( const Vector3& _direction, const Vector3& _origin )
	:	direction(_direction), origin(_origin)
{}

inline Line3&
Line3::normalize()
{
	this->direction.normalize();
}