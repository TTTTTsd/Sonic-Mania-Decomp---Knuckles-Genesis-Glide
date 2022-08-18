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

void Player_State_KnuxGlideSlide_Hook(void)
{
    RSDK_THIS(Player);
    if (self->onGround) {
        if (self->jumpPress & self->down & self->groundVel == 0)
            {
            self->nextAirState = Player_State_Air;
            self->skidding     = 0;
            self->groundVel   = 0;
            Player_Action_Spindash(self);
        }
        if (self->jumpPress & !self->down & self->groundVel == 0) {
            self->nextAirState = Player_State_Air;
            self->skidding     = 0;
            self->velocity.x   = 0;
            Player_Action_Jump(self);
        }
    }
}

void Player_State_KnuxGlideLeft_Hook(void)
{
    RSDK_THIS(Player);
    if (abs(self->velocity.x) < 0x10000 && !self->jumpHold) {
        self->direction = FLIP_NONE;
    }
}

void Player_JumpAbility_Knux_Hook(void)
{
    RSDK_THIS(Player);

    if (self->animator.animationID == ANI_GLIDE && self->velocity.y > 0) {
            self->velocity.y += 0x20000;
    }
}