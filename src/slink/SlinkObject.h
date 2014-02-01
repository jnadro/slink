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

	protected:
		static uint32_t nextId;

	private:
		const uint32_t id;
		std::string name;
	};
}