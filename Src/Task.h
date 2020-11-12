#pragma once

class Task {
public:
	Task() = default;
	virtual ~Task() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};