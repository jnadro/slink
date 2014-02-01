#include "SlinkObject.h"

namespace Slink
{
	uint32_t Object::nextId = 1;

	Object::Object()
		: id(nextId++)
	{
	}

	Object::~Object()
	{
	}
}
