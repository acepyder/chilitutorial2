#pragma once
#include "Graphics.h"
#include "player.h"

class Poo
{
public:
	void Init(int in_x, int in_y, int in_vx, int in_vy); //constructor which initializes
	void Update();
	void IsColliding(const Player& player); //doesnt change reference variables. read only. but mutating.
	bool Eaten() const;	//getter function
	void Draw(Graphics& gfx) const;	//does change reference variable, but not anything else. non-mutating.
private:
	static constexpr int w = 24;
	static constexpr int h = 24;
	int x;
	int y;
	int vx;
	int vy;
	bool eaten = false;
	bool initialized = false;
};