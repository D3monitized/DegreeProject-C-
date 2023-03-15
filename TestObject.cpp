#include "TestObject.h"

TestObject::TestObject() {
}

TestObject::~TestObject() {
}

void TestObject::Start() {
	_spriteRenderer->SetTexture(_imgPath);
}

void TestObject::Tick() {
}

