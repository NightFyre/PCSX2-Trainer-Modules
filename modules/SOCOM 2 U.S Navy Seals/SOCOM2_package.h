#pragma once
#include <string>

/**
 * Name: SOCOM 2
 * Platform: PlayStation 2
 * PCSX2 Version: 1.7 beta
 * Author: NightFyre
*/

#pragma pack(push, 0x01)
namespace PlayStation2
{
	namespace SOCOM2
	{
		// --------------------------------------------------
		// # Forwards
		// --------------------------------------------------
		typedef unsigned __int32  i32_t;

		/* WEAPONS */
#define WEAPON_MODEL_18 0xC66FE0
#define WEAPON_MARK_23 0xC67270
#define WEAPON_F57 0xC67500
#define WEAPON_DE50 0xC67790
#define WEAPON_M9 0xC67A20
#define WEAPON_226 0xC67CD0
#define WEAPON_MARK_23_SD  0xC67F60
#define WEAPON_9MM_PISTOL  0xC681F0
#define WEAPON_M11 0xC68480
#define WEAPON_SP10 0xC68710
#define WEAPON_LASER_DESIGNATOR 0xC689A0
#define WEAPON_TA_SHOTGUN 0xC68C50
#define WEAPON_MK3_A2_SHOTGUN 0xC68EE0
#define WEAPON_REMINGTON_870 0xC69170
#define WEAPON_M16A2 0xC69400
#define WEAPON_M16A2_M203 0xC69690
#define WEAPON_M4A1 0xC69920
#define WEAPON_M4A1_SD 0xC69BB0
#define WEAPON_M4A1_M203 0xC69E40
#define WEAPON_552 0xC6A0D0
#define WEAPON_552_SD 0xC6A360
#define WEAPON_AK47 0xC6A5F0
#define WEAPON_AKS74 0xC6A880
#define WEAPON_M14 0xC6AB10
#define WEAPON_OICW 0xC6ADA0
#define WEAPON_IW_80_A2 0xC6B030
#define WEAPON_AK105 0xC6B2C0
#define WEAPON_RA14 0xC6B550
#define WEAPON_M60E3 0xC6B7E0
#define WEAPON_M63A 0xC6BA70
#define WEAPON_PKM 0xC6BD00
#define WEAPON_HK5 0xC6BF90
#define WEAPON_HK5_SD 0xC6C220
#define WEAPON_F90 0xC6C4B0
#define WEAPON_9MM_SUB 0xC6C740
#define WEAPON_STG_77 0xC6C9D0
#define WEAPON_HK5K 0xC6CC60
#define WEAPON_M82A1A 0xC6CEF0
#define WEAPON_M40A1 0xC6D180
#define WEAPON_M87ELR 0xC6D410
#define WEAPON_SR25_SD 0xC6D6A0
#define WEAPON_SR25 0xC6D930
#define WEAPON_SASR 0xC6DBC0
#define WEAPON_DETONATOR 0xC6DE50
#define WEAPON_EMPTY 0xC6E0E0
#define WEAPON_NONE 0xC6E370
#define WEAPON_THERMAL SCOPE 0xC6E600
#define WEAPON_BINOCULARS 0xC6E890
#define WEAPON_M67 0xC6EB20
#define WEAPON_HE 0xC6EDB0
#define WEAPON_SMOKE 0xC6F040
#define WEAPON_CHEM_LIGHT 0xC6F2D0
#define WEAPON_RED_SMOKE  0xC6F560
#define WEAPON_FLASHBANG 0xC6F7F0
#define WEAPON_SATCHEL 0xC6FAA0
#define WEAPON_CLAYMORE 0xC6FD30
#define WEAPON_PMN_MINE 0xC6FFC0
#define WEAPON_C4 0xC70250
#define WEAPON_MPBOMB 0xC704E0
#define WEAPON_M203 0xC70770
#define WEAPON_M203_HE 0xC70A00
#define WEAPON_M203_FRAG 0xC70C90
#define WEAPON_M203_SMOKE 0xC70F20
#define WEAPON_OICW_HE 0xC711B0
#define WEAPON_OICW_FRAG 0xC71440
#define WEAPON_OICW_SMOKE 0xC716D0
#define WEAPON_MGL 0xC71960
#define WEAPON_M79 0xC71BF0
#define WEAPON_M79_HE 0xC71E80
#define WEAPON_M79_FRAG 0xC72110
#define WEAPON_M79_SMOKE 0xC723A0
#define WEAPON_ARTILLERY SHELL 0xC72630
#define WEAPON_AT4 0xC728C0
#define WEAPON_AT4_HEAT 0xC72B50
#define WEAPON_RPG7 0xC72DE0
#define WEAPON_RPG_ROUND 0xC73070
#define WEAPON_BACKBLAST 0xC73300
#define WEAPON_KEVLAR_ARMOR 0xC73590
#define WEAPON_KEVLAR_ARMOR_INSERT 0xC73820
#define WEAPON_2X_AMMO 0xC73AF0
#define WEAPON_ATG_MISSILE 0xC73D80
#define WEAPON_EXPLOSION 0xC74010
#define WEAPON_SATCHEL_EXPLOSION 0xC742A0
#define WEAPON_TURRET_RMG 0xC74530
#define WEAPON_TURRET_30MM_MGL 0xC747C0
#define WEAPON_TURRET_LMG 0xC74A50

		/* AMMO TYPES */
#define AMMO_9x19P 0xC663B0
#define AMMO_9x21mm 0xC66400
#define AMMO_57x28mm 0xC66450
#define AMMO_LONG_RIFLE 0xC664A0
#define AMMO_45ACP 0xC664F0
#define AMMO_50AE 0xC66540
#define AMMO_545x39mm_SOVIET 0xC66590
#define AMMO_556x45mm 0xC665E0
#define AMMO_762x51mm 0xC66630
#define AMMO_762x39mm_M1943 0xC66680
#define AMMO_762x54R 0xC666D0
#define AMMO_50BMG 0xC66720
#define AMMO_12GUAGE 0xC66770
#define AMMO_M67 0xC667C0
#define AMMO_HE 0xC66810
#define AMMO_SMOKE 0xC66860
#define AMMO_RED_SMOKE 0xC668B0
#define AMMO_CHEM_LIGHT 0xC66900
#define AMMO_FLASHBANG 0xC66950
#define AMMO_SATCHEL 0xC669A0
#define AMMO_CLAYMORE 0xC669F0
#define AMMO_PMN_MINE 0xC66A40
#define AMMO_C4 0xC66A90
#define AMMO_MPBOMB 0xC66AE0
#define AMMO_M203_HE 0xC66B30
#define AMMO_M203_FRAG 0xC66B80
#define AMMO_M203_SMOKE 0xC66BD0
#define AMMO_OICW_HE 0xC66C20
#define AMMO_OICW_FRAG 0xC66C70
#define AMMO_OICW_SMOKE 0xC66CC0
#define AMMO_M79_HE 0xC66D10
#define AMMO_M79_FRAG 0xC66D60
#define AMMO_M79_SMOKE 0xC66DB0
#define AMMO_AT4_HEAT 0xC66E00
#define AMMO_BACKBLAST 0xC66E50
#define AMMO_ARTILLERY_SHELL 0xC66EA0
#define AMMO_RPG 0xC66EF0
#define AMMO_MISSILE 0xC66F40
#define AMMO_EXPLOSIVE_STUFF 0xC66F90

		// --------------------------------------------------
		// # Global functions
		// --------------------------------------------------

		i32_t GetWeaponByIndex(int index);
		i32_t GetAmmoTypeByIndex(int index);
		i32_t GetTeamIDByIndex(int index);

		std::string GetWeaponName(i32_t oWeapon);
		std::string GetAmmoTypeName(i32_t oAmmo);
		std::string GetFireTypeName(int ftIndex);
		std::string GetTeamNameByID(int teamid);

		//	bool GetBoneNameByIndex(i32_t pCZSealBody, int index, std::string& outResult);
		//	bool GetBoneTransformByIndex(i32_t pCZSealBody, int index, Mat4x4& outResult);

		// --------------------------------------------------
		namespace Dumper
		{
			void DumpWeaponStats();
			void DumpAmmoStats();
			void DumpBoneNames();
			void DumpBoneHierarchy();
		}
	}

}
#pragma pack(pop)

#include <PCSX2/CDK.h>
#include "SOCOM2_Structs.h"
#include "SOCOM2_Classes.h"
#include "data/names.h"