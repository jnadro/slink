#pragma once

#include <string>

namespace Slink
{
	class Object
	{
	public:
		Object();
		~Object();

	private:
		unsigned int id;
		std::string name;
	};
}