//
// Created by Michal Přikryl on 21.09.2025.
// Copyright (c) 2025 slynxcz. All rights reserved.
//
#include "ctakedamageinfo.h"
#include <platform.h>
#include "ehandle.h"
#include "globaltypes.h"
#include "CCSPlayerController.h"
#include "serversideclient.h"
#include "ctakedamageinfo.h"
#include "CCSPlayerController.h"
#include "serversideclient.h"

CAttackerInfo::CAttackerInfo(CEntityInstance* attacker)
{
    NeedInit = false;
    IsPawn = false;
    IsWorld = true;
    pad0x3 = 0;
    Attacker = 0;
    AttackerUserId = 0xFFFF;
    TeamChecked = -1;
    TeamNum = -1;

    if (!attacker)
        return;

    if (auto* baseEnt = reinterpret_cast<CBaseEntity*>(attacker))
        Attacker = baseEnt->GetHandle().ToInt();

    if (auto* baseEnt = reinterpret_cast<CBaseEntity*>(attacker);
        baseEnt && baseEnt->m_pEntity && baseEnt->m_pEntity->m_designerName.String() == std::string("cs_player_controller"))
    {
        auto* controller = reinterpret_cast<CCSPlayerController*>(attacker);
        if (controller)
        {
            AttackerUserId = 0xFFFF;
            IsWorld = false;
            IsPawn = true;
            TeamNum  = controller->m_iTeamNum();
            TeamChecked = TeamNum;
        }
    }
}
