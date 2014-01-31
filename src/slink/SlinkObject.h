#pragma once

#include <stdint.h>
#include <string>

namespace Slink
{
	class Object
	{
	public:
		Object();
		~Object();

	private:
		uint32_t id;
		std::string name;
	};
}