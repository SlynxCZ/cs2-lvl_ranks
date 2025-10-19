#pragma once
#include <platform.h>
#include "ehandle.h"
#include "globaltypes.h"

class CEntityInstance;
class CBaseEntity;
class CCSPlayerPawn;

struct CAttackerInfo
{
    bool NeedInit;
    bool IsPawn;
    bool IsWorld;
    char pad0x3;

    uint32_t Attacker;

    uint16_t AttackerUserId;
    char pad0xA[2];

    int TeamChecked;
    int TeamNum;

    CAttackerInfo(CEntityInstance* attacker);
};

static_assert(sizeof(CAttackerInfo) == 0x14, "CAttackerInfo has wrong size");

class CGameTrace;

class CTakeDamageInfo
{
public:
	DECLARE_SCHEMA_CLASS(CTakeDamageInfo)

	SCHEMA_FIELD(Vector, m_vecDamageForce);
	SCHEMA_FIELD(Vector, m_vecDamagePosition);
	SCHEMA_FIELD(Vector, m_vecReportedPosition);
	SCHEMA_FIELD(Vector, m_vecDamageDirection);
	SCHEMA_FIELD(CBaseHandle, m_hInflictor);
	SCHEMA_FIELD(CBaseHandle, m_hAttacker);
	SCHEMA_FIELD(CBaseHandle, m_hAbility);
	SCHEMA_FIELD(float, m_flDamage);
	SCHEMA_FIELD(float, m_flTotalledDamage);
	SCHEMA_FIELD(int32_t, m_bitsDamageType);
	SCHEMA_FIELD(int32_t, m_iDamageCustom);
	SCHEMA_FIELD(int8_t, m_iAmmoType);
	SCHEMA_FIELD(float, m_flOriginalDamage);
	SCHEMA_FIELD(bool, m_bShouldBleed);
	SCHEMA_FIELD(bool, m_bShouldSpark);
	SCHEMA_FIELD(float, m_flDamageAbsorbed);
	SCHEMA_FIELD(TakeDamageFlags_t, m_nDamageFlags);
	SCHEMA_FIELD(HitGroup_t, m_iHitGroupId);
	SCHEMA_FIELD(int32_t, m_nNumObjectsPenetrated);
	SCHEMA_FIELD(float, m_flFriendlyFireDamageReductionRatio);
	SCHEMA_FIELD(bool, m_bInTakeDamageFlow);

    CAttackerInfo& AttackerInfo()
    {
        return *reinterpret_cast<CAttackerInfo*>(
            reinterpret_cast<uint8_t*>(this) + 0x98);
    }
};

struct CTakeDamageInfoContainer
{
	DECLARE_SCHEMA_CLASS(CTakeDamageInfoContainer)

	SCHEMA_FIELD_POINTER(CTakeDamageInfo, m_DamageInfo);
};