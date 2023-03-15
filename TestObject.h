#pragma once

#include "GameObject.h"

class TestObject : public Engine::GameObject {
public:
	TestObject();
	~TestObject();

	void Start() override;
	void Tick() override;

private:
	const std::string _imgPath = "$(SolutionDir)/Avatar.PNG";
};
