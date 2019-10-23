////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Includes.h"

//Flags
#define FL_ON_GROUND                     257
#define FL_ON_GROUND_CROUCHED             263
#define FL_IN_AIR_STAND                    256
#define FL_IN_AIR_MOVING_TO_STAND         258
#define FL_ON_GROUND_MOVING_TO_STAND     259
#define FL_IN_AIR_MOVING_TO_CROUCH         260
#define FL_ON_GROUND_MOVING_TO_CROUCH     261
#define FL_IN_AIR_CROUCHED                 262
#define FL_IN_WATER                     1280
#define FL_IN_PUDDLE                     1281
#define FL_IN_WATER_CROUCHED             1286
#define FL_IN_PUDDLE_CROUCHED             1287
#define FL_PARTIALGROUND (1 << 18)

//Team IDs
#define TEAM_ID_GOTV 1
#define TEAM_ID_T 2
#define TEAM_ID_CT 3

void glowie(int idx)
{
	auto datatype = Entity::getEntBase(idx);

	if (Entity::getEntTeam(datatype) != LocalPlayer::getLocalTeam())
	{
		auto gObject = Entity::getGlowObj();
		auto gIndex = Entity::getGlowIndex(datatype);

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
