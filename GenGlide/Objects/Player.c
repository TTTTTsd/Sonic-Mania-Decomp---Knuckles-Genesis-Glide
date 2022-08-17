#include "Player.h"
#include "GameAPI/Game.h"

ObjectPlayer *Player;

void Player_State_KnuxGlideDrop_Hook(void)
{
    RSDK_THIS(Player);

    if (self->onGround) {
            if (self->jumpPress & self->down) {
                Player_Action_Spindash();
                self->skidding = 0;
            }
            if (self->jumpPress & !self->down) {
                Player_Action_Jump(self);
                self->skidding = 0;
            }
    }
}
void Player_JumpAbility_Knux_Hook(void)
{
    RSDK_THIS(Player);

    if (self->jumpPress) {
            self->velocity.y += 0x20000;
    }
}