#pragma once
class SceneBase {
public:
	virtual void Draw() = 0;
	virtual void Input() = 0;
	virtual void Initialize() = 0;
	virtual void End() = 0;
};