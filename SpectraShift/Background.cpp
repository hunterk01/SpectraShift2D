#include "sfwdraw.h"
#include "AssetLibrary.h"
#include "GameObjects.h"
#include "Background.h"
#include "Player.h"

extern vec2 lightSkyPos = { 450,450 };
extern vec2 darkSkyPos = { 450,450 };
extern vec2 starfieldPos = { 450,450 };

bool currentState, lastState;

void DrawBackground()
{
	currentState = sfw::getKey(32);
	
	if (!playerLight)
	{
		sfw::drawTexture(GetTexture("BG_stars"), starfieldPos.x, starfieldPos.y, 1800, 1800, 90, true, 0, 0xffffffff);
		sfw::drawTexture(GetTexture("BG_dark"), darkSkyPos.x, darkSkyPos.y, 1800, 1800, 90, true, 0, 0xffffff60);

		if (currentState && !lastState)
		{
			playerLight = true;
		}
	}
	else
	{
		sfw::drawTexture(GetTexture("BG_stars"), starfieldPos.x, starfieldPos.y, 1800, 1800, 90, true, 0, 0xffffffff);
		sfw::drawTexture(GetTexture("BG_light"), lightSkyPos.x, lightSkyPos.y, 1800, 1800, 90, true, 0, 0xffff0080);

		if (currentState && !lastState)
		{
			playerLight = false;
		}
	}

	lastState = currentState;
}