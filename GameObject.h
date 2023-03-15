#pragma once
#include <iostream>
#include <set>

#include "SpriteRenderer.h"

namespace Engine {

	class GameObject { //Abstract class not to be used as is 
	static std::set<GameObject*> _instances;
	public:
<<<<<<< HEAD
		GameObject() 
		{
=======
		GameObject() {
>>>>>>> 1a2d0f6c613db269b6aeadc8a4441660c4cd4b50
			_instances.insert(this);
		}
		GameObject(GameObject& other) {
			_instances.insert(this);
		}
		~GameObject() {
			_instances.erase(this);
		}

		virtual void Start() = 0;
		virtual void Tick() = 0; 

<<<<<<< HEAD
		}

		virtual void Tick()
		{
			std::cout << _Name << std::endl; 
		}

		static const std::set<GameObject*>& GetInstances()
		{
=======
		static const std::set<GameObject*>& GetInstances() {
>>>>>>> 1a2d0f6c613db269b6aeadc8a4441660c4cd4b50
			return _instances;
		}

	public:
		std::string _Name;
		SpriteRenderer* _spriteRenderer;
	};
}
