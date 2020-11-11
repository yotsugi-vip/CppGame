#pragma once
#include "Task.h"
typedef struct {
	float x;
	float y;
}T_Coordinate;

class Player : public Task
{
public:
	Player();
	~Player();

	T_Coordinate Now;
	T_Coordinate Pre;
	T_Coordinate HitBox;
	int Frame;

public:
	void update();
	void draw();

public:
	void CheckPlayerCoordinate(T_Coordinate *info);
};

