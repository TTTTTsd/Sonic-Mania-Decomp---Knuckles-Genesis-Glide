#include "../GameAPI/C/GameAPI/Game.h"
#include "Objects/Player.h"

#if RETRO_USE_MOD_LOADER
DLLExport bool32 LinkModLogic(EngineInfo *info, const char *id);
#endif

void InitModAPI(void) {
Player_State_Spindash     = Mod.GetPublicFunction(NULL, "Player_State_Spindash");
Player_Action_Spindash = Mod.GetPublicFunction(NULL, "Player_Action_Spindash");
Player_Action_Jump = Mod.GetPublicFunction(NULL, "Player_Action_Jump");
Player_State_Ground = Mod.GetPublicFunction(NULL, "Player_State_Ground");
Player_State_Air        = Mod.GetPublicFunction(NULL, "Player_State_Air");
Player_State_KnuxGlideDrop = Mod.GetPublicFunction(NULL, "Player_State_KnuxGlideDrop");
Mod.RegisterStateHook(Player_State_KnuxGlideDrop,Player_State_KnuxGlideDrop_Hook, false);
Player_State_KnuxGlideSlide = Mod.GetPublicFunction(NULL, "Player_State_KnuxGlideSlide");
Mod.RegisterStateHook(Player_State_KnuxGlideSlide, Player_State_KnuxGlideSlide_Hook, false);
Player_JumpAbility_Knux = Mod.GetPublicFunction(NULL, "Player_JumpAbility_Knux");
Mod.RegisterStateHook(Player_JumpAbility_Knux, Player_JumpAbility_Knux_Hook, false);
Player_State_KnuxGlideLeft = Mod.GetPublicFunction(NULL, "Player_State_KnuxGlideLeft");
Mod.RegisterStateHook(Player_State_KnuxGlideLeft, Player_State_KnuxGlideLeft_Hook, false);
}

#if RETRO_USE_MOD_LOADER
#define ADD_PUBLIC_FUNC(func) Mod.AddPublicFunction(#func, (void *)(func))

void InitModAPI(void);

bool32 LinkModLogic(EngineInfo *info, const char *id)
{
#if MANIA_USE_PLUS
    LinkGameLogicDLL(info);
#else
    LinkGameLogicDLL(*info);
#endif

    globals = Mod.GetGlobals();

    modID = id;

    InitModAPI();

    return true;
}
#endif