////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Includes.h"

void glowie(int idx)
{
	auto playr = Entity::getEntBase(idx);

	if (Entity::getEntTeam(playr) != LocalPlayer::getLocalTeam())
	{
		auto gObject = Entity::getGlowObj();
		auto gIndex = Entity::getGlowIndex(playr);

		Entity::glowEsp(gObject, gIndex, 255, 0, 0, 150);
	}

}

int main()
{

	if (attatchProc(XOR("csgo.exe")))
	{
		if (baseAddress = getModule(XOR("client_panorama.dll")))
		{
			LocalPlayer::setLocalPlayer();

			while (!GetAsyncKeyState(VK_F10))
			{
				for (int i = 0; i <= 32; i++)
				{
					glowie(i);
				}

				Sleep(1);
			}
		}
	}

	//Close handle to csgo.exe to prevent memory leaks
	CloseHandle(hProc);
}
