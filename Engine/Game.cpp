/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	vDist(0, 1),
	thedude(400, 300)
{
	int speed[] = { 1, -1 };
	for (int i = 0; i < nPoo; i++)
	{
		poos[i].Init(xDist(rng), yDist(rng), speed[vDist(rng)], speed[vDist(rng)]);
	}
}
 
void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!isStarted)
	{
		menu.GiveNumPoos(nPoo); //unused
		//starts game
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}
	}
	if (isStarted && !menu.Over()) 
	{
		//move player
		thedude.Update(wnd.kbd);
		//move poo around and test if colliding, then assigning poo dmg
		pooDmgTotal = 0;
		for (int i = 0; i < nPoo; i++)
		{
			poos[i].Update();;
			poos[i].IsColliding(thedude);
			if (poos[i].Eaten())
			{
				pooDmgTotal += 1;
			}
		}
		menu.Hurt(pooDmgTotal);
		//check all poos eaten, then make poo Dmg Total
		// test if colliding
		shine.Chase(thedude.GetX(), thedude.GetY());
		shine.IsColliding(thedude);
		//if collecting, random spawn, and progress
		if (shine.Get())
		{
			shine.Update(xDist(rng), yDist(rng));
			menu.Progress();
		}
	}
	//exits game
	if (menu.Over() && wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		exit(0);
	}
}

void Game::ComposeFrame()
{
	if (!isStarted)
	{
		menu.DrawTitle(gfx, 325, 211);
	} 
	else if (menu.Over())
	{
		menu.DrawEnd(gfx, 358, 268);
	}
	else 
	{
		thedude.Draw(gfx);
		menu.DrawHP(gfx);
		menu.DrawProgress(gfx);
		shine.Sparkle();
		shine.Draw(gfx);
		for (int i = 0; i < nPoo; i++)
		{
			if (!poos[i].Eaten())
				poos[i].Draw(gfx);
		}
	}
}
