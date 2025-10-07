#pragma once
#include <string>

/**
 * Name: PlayStation2 - PCSX2 :: SOCOM U.S NAVY SEALs
 * Version: 0.0.1
 * Author: NightFyre
*/

#pragma pack(push, 0x01)
namespace PlayStation2
{
	namespace SOCOM
	{
		// --------------------------------------------------
		// # Forwards
		// --------------------------------------------------
		typedef unsigned __int32  i32_t;

		/* WEAPONS */
#define WEAPON_MODEL_18 0xCC1730
#define WEAPON_MARK_23 0xCC1A10
#define WEAPON_F57 0xCC1CF0
#define WEAPON_DE50 0xCC1FD0
#define WEAPON_M9 0xCC22D0
#define WEAPON_P226 0xCC25B0
#define WEAPON_MARK23_SD 0xCC2880
#define WEAPON_9MM_Pistol 0xCC2B60
#define WEAPON_LASER_DESIGNATOR 0xCC2E40		//	unknown, not used in SOCOM 1
#define WEAPON_MK3_A2_SHOTGUN 0xCC3110	//	unknown, not used in SOCOM 1
#define WEAPON_REMINGTON_870 0xCC33F0	//	unknown, not used in SOCOM 1
#define WEAPON_M16A2 0xCC36E0
#define WEAPON_M16A2_M203 0xCC39C0
#define WEAPON_M4A1 0xCC3CA0
#define WEAPON_M4A1_SD 0xCC3F80
#define WEAPON_M4A1_M203 0xCC4270
#define WEAPON_552 0xCC4550
#define WEAPON_AK47 0xCC4850
#define WEAPON_AKS74 0xCC4B20
#define WEAPON_M14 0xCC4E00
#define WEAPON_M60E3 0xCC50D0
#define WEAPON_M63A 0xCC53A0
#define WEAPON_STONER_63 0xCC5680		//	unknown, not used in SOCOM 1
#define WEAPON_HK5 0xCC5970
#define WEAPON_HK5_SD 0xCC5C40
#define WEAPON_F90 0xCC5F20
#define WEAPON_9M_SUB 0xCC61F0
#define WEAPON_M82A1A 0xCC64C0
#define WEAPON_M40A1 0xCC67A0
#define WEAPON_M87ELR 0xCC6AA0
#define WEAPON_SR25_SD 0xCC6D90
#define WEAPON_SR25 0xCC7080
#define WEAPON_KNIFE 0xCC7370 	//	unknown, not used in SOCOM 1
#define WEAPON_FLASHLIGHT 0xCC7650	//	unknown, not used in SOCOM 1
#define WEAPON_DETONATOR 0xCC7920	//	unknown, not used in SOCOM 1
#define WEAPON_BINOCULARS 0xCC7BF0	//	unknown, not used in SOCOM 1
#define WEAPON_RESTRAINTS 0xCC7EC0
#define WEAPON_M67 0xCC81A0
#define WEAPON_HE_GRENADE 0xCC8490
#define WEAPON_SMOKE 0xCC8760
#define WEAPON_FLASHBANG 0xCC8A60
#define WEAPON_SATCHEL 0xCC8D50
#define WEAPON_CLAYMORE 0xCC9030
#define WEAPON_C4 0xCC9300
#define WEAPON_MPBOMB 0xCC95C0
#define WEAPON_M203 0xCC9890
#define WEAPON_M203_HE 0xCC9B50
#define WEAPON_M203_FRAG 0xCC9E30
#define WEAPON_M203_SMOKE 0xCCA120
#define WEAPON_MGL 0xCCA410
#define WEAPON_M79 0xCCA6E0
#define WEAPON_M79_HE 0xCCA9B0
#define WEAPON_M79_FRAG 0xCCAC90
#define WEAPON_M79_SMOKE 0xCCAF70
#define WEAPON_KEVLAR_ARMOR 0xCCB260
#define WEAPON_KEVLAR_ARMOR_INSERT 0xCCB530
#define WEAPON_2X_AMMO 0xCCB800
#define WEAPON_ATG_MISSILE 0xCCBAE0
#define WEAPON_EXPLODING_FUEL 0xCCBDC0
#define WEAPON_SATCHEL_EXPLOSION 0xCCC090

		/* AMMO TYPES */
#define AMMO_9x19P 0xCC0C90				//	SMG_HK5, SMG_9MM, PISTOL_MODEL_18, PISTOL_9MM
#define AMMO_9x19P_SD 0xCC0CD0			//	SMG_HK5_SD, PISTOL_9MM_SD
#define AMMO_57x28 0xCC0D20				//	F57 , F90
#define AMMO_LONGRIFLE 0xCC0D70			//	unknown
#define AMMO_45ACP 0xCC0DC0				//	PISTOL_MK23
#define AMMO_50AE 0xCC0E10				//	DE50 , 
#define AMMO_545x39 0xCC0E60			//	AKS74
#define AMMO_556x45_SD 0xCC0ED0			//	M4A1_SD , 
#define AMMO_556x45 0xCC0F40			//	M4A1, M16A2, 552 , M63A
#define AMMO_762x51 0xCC0F90			//	M40A1 , M14 , M60E3 , SR25
#define AMMO_762x39_SD 0xCC0FE0			//	AK47 , 
#define AMMO_762x39 0xCC1050			//	AK47 , 
#define AMMO_50BMG 0xCC10C0				//	M82A1A , M87ELR
#define AMMO_12GUAGE 0xCC1110			//	unknown
#define AMMO_M67 0xCC1160
#define AMMO_HE 0xCC11B0
#define AMMO_SMOKE 0xCC1210
#define AMMO_M141 0xCC1260
#define AMMO_SATCHEL 0xCC12C0
#define AMMO_CLAYMORE 0xCC1320
#define AMMO_C4 0xCC1380
#define AMMO_MPBOMB 0xCC13D0
#define AMMO_M203_HE 0xCC1420
#define AMMO_M203_FRAG 0xCC1490
#define AMMO_M203_SMOKE 0xCC1500
#define AMMO_M79_HE 0xCC1570
#define AMMO_M79_FRAG 0xCC15C0
#define AMMO_M79_SMOKE 0xCC1620
#define AMMO_MISSILE 0xCC1680			//	unknown
#define AMMO_EXPLOSIVE_STUFF 0xCC16D0	//	unknown

		// --------------------------------------------------
		// # Global functions
		// --------------------------------------------------

		i32_t GetWeaponByIndex(int index);
		i32_t GetAmmoTypeByIndex(int index);
		i32_t GetTeamIDByIndex(int index);
		bool GetBoneNameByIndex(int index, std::string& outResult);

		namespace Dumper
		{
			void DumpMissionInfo();	/* dumps entity & pickups array for the current mission , should be run once at the start of a mission to generate information */
			void DumpWeaponStats();
			void DumpAmmoStats();
			void DumpBoneNames();
		}
	}
}
#pragma pack(pop)
#include <PCSX2/CDK.h>
#include "SOCOM1_structs.h"
#include "SOCOM1_classes.h"
#include "data/names.h"