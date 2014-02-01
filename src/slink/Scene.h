#pragma once

#include <vector>
#include <memory>

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
		std::vector<std::shared_ptr<Object> > objects;
	};
}