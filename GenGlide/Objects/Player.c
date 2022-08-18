#include "Player.h"
#include "GameAPI/Game.h"

ObjectPlayer *Player;

void Player_State_KnuxGlideDrop_Hook(void)
{
    RSDK_THIS(Player);

    if (self->onGround) {
            if (self->jumpPress & self->down) {
                self->nextAirState = Player_State_Air;
                Player_Action_Spindash(self);
                self->skidding = 0;
            }
            if (self->jumpPress & !self->down) {
                self->nextAirState = Player_State_Air;
                Player_Action_Jump(self);
                self->skidding = 0;
            }
    }
}
void Player_JumpAbility_Knux_Hook(void)
{
    RSDK_THIS(Player);

    if (self->animator.animationID == ANI_GLIDE && self->velocity.y > 0) {
            self->velocity.y += 0x20000;
    }
}