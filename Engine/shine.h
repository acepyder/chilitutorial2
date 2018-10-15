#pragma once
#include "Graphics.h"
#include "player.h"

class Shine
{
public:
	void Update(int new_x, int new_y);
	void Shine::Chase(int playerx, int playery);
	void IsColliding(const Player& player);
	bool Get() const;
	void Sparkle();
	void Draw(Graphics& gfx) const;
private:
	int x = 100;
	int y = 100;
	int r = 255;
	int g = 255;
	int b = 0;
	static constexpr int w = 25;
	static constexpr int h = 25;
	bool got = false;
	bool swap = false;
};