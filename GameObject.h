#pragma once
#include <iostream>
#include <set>

#include "SpriteRenderer.h"

namespace Engine {

	class GameObject { //Abstract class not to be used as is 
	static std::set<GameObject*> _instances;
	public:
		GameObject() {
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

		static const std::set<GameObject*>& GetInstances() {
			return _instances;
		}

	public:
		std::string _Name;
		SpriteRenderer* _spriteRenderer;
	};
}
