#include "shine.h"
#include "Colors.h"

void Shine::Sparkle()
{
	if (b >= 255)
	{
		swap = true;
	}
	if (b <= 0)
	{
		swap = false;
	}
	if (swap)
	{
		b -= 1;
	}
	else
	{
		b += 1;
	}
}

void Shine::Update(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}

void Shine::Chase(int playerx, int playery)
{
	if (playerx > x)
	{
		x++;
	}
	if (playerx < x)
	{
		x--;
	}
	if (playery > y)
	{
		y++;
	}
	if (playery < y)
	{
		y--;
	}
}

void Shine::IsColliding(const Player& player)	//colliding with player
{
	if (
		player.GetX() <= x + w &&	//left0 <= right1
		player.GetX() + player.GetW() >= x &&	//right0 >= left1
		player.GetY() <= y + h &&	//top0 <= bottom1
		player.GetY() + player.GetH() >= y	//bottom0 >= top1
		)
	{
		got = true;
	}
	else
		got = false;
}

bool Shine::Get() const
{
	return got;
}

void Shine::Draw(Graphics & gfx) const
{
	gfx.DrawRect(x, y, x + w, y + h, r, g, b);
}
