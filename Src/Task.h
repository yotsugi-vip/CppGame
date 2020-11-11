#pragma once

class Task {
public:
	Task() = default;
	virtual ~Task() = default;
	virtual void update() = 0;
	virtual void draw() = 0;
};