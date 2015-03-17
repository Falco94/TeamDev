#include "Game.h"

int main()
{
	Game ArcadeShooter;
	
		while (ArcadeShooter.isRunning())
		{
			ArcadeShooter.Run();
		}

	return 0;
}