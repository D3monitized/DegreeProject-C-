#pragma once

namespace Engine {
	class GameObject {

	static std::set<GameObject*> _instances;

	public:
		GameObject() 
		{
			_instances.insert(this);
		}
		GameObject(GameObject& other)
		{
			_instances.insert(this);
		}
		~GameObject()
		{
			_instances.erase(this);
		}

		virtual void Start()
		{

		}

		virtual void Tick()
		{
			std::cout << _Name << std::endl; 
		}

		static const std::set<GameObject*>& GetInstances()
		{
			return _instances;
		}

	public:
		std::string _Name;
	};
}
