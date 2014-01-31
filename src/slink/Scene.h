#pragma once

#include <vector>

namespace Slink
{
	class Object;

	class Scene
	{
	public:
		Scene();
		~Scene();

		void add(Object*);
		void remove();

	private:
		std::vector<Object*> objects;
	};
}