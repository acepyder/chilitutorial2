#pragma once
#include "Graphics.h"

class Menu
{
public:
	bool Over();
	void GiveNumPoos(int numpoo); //unused
	void Hurt(int dmg);
	void Progress();
	void DrawHP(Graphics& gfx) const;
	void DrawProgress(Graphics& gfx) const;
	void DrawTitle(Graphics & gfx, int x, int y) const;
	void DrawEnd(Graphics & gfx, int x, int y) const;
private:
	static constexpr int hp_x = 20;
	static constexpr int hp_y = 20;
	static constexpr int bar_x = 20;
	static constexpr int bar_y = 40;
	static constexpr int hp_ini = 201;
	static constexpr int dmgScale = 25;
	static constexpr int progressScale = 50;
	int numPoo;			//unused
	int numDmgScale;	//unused
	int hp_total = 201;
	int bar_total = 201;
	bool gameover = false;
};


//hp_total over nPoo
//don't forget const correctness here