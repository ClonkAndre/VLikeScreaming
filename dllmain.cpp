// V Like Screaming by ItsClonkAndre
// Version 1.0

#include "ZHookBase.cpp"

#pragma region Variables
int tickTemp;
Ped playerPed;
#pragma endregion

#pragma region Unused
void scriptLoad() {

}
void scriptUnload() {

}
#pragma endregion

void scriptTick()
{
	Player player = Scripting::CONVERT_INT_TO_PLAYERINDEX(Scripting::GET_PLAYER_ID());
	GET_PLAYER_CHAR(player, &playerPed);

    float heightAboveGround;
    GET_CHAR_HEIGHT_ABOVE_GROUND(playerPed, &heightAboveGround);

    if (heightAboveGround > 6) {
        if (IS_PED_RAGDOLL(playerPed)) {
            tickTemp++;
            if (tickTemp % 210 == 0) {
                HIGH_FALL_SCREAM(playerPed);
                tickTemp = 0;
            }
        }
    }
    else {
        tickTemp = 0;
    }
}