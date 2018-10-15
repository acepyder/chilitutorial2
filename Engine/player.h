#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Player
{
public:
	Player(int in_x, int in_y);
	void Update(const Keyboard& kbd);
	void Draw(Graphics& gfx) const;
	int GetX() const;	//getter function
	int GetY() const;	//getter function
	int GetW() const;	//getter function
	int GetH() const;	//getter function
private:
	static constexpr int w = 64;	//width
	static constexpr int h = 74;	//height
	int x;
	int y;
	static constexpr int s = 2;		//speed
};