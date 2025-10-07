#pragma once

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
		namespace Offsets
		{
			//	MatchData
			static const unsigned int	o_GameEndAddr{ 0x5D708C };
			static const unsigned int	o_GameForceMatch{ 0x1F66F4 };

			//	Seal
			static const unsigned int   o_World{ 0x48D288 };		//	CZWorld*
			static const unsigned int	o_LocalCamera{ 0x48D488 };	//	CAppCamera*
			static const unsigned int	o_LocalSeal{ 0x48D548 };	//	CZSealBody*
			static const unsigned int	o_SealArray{ 0x4D46A0 };	//	ZArray<CZSeal*>
			static const unsigned int	o_WeaponArray{ 0x52A490 };	//	ZArray<CZWeapon*>
			static const unsigned int	o_AmmoArray{ 0x52A500 };	//	ZArray<CZAmmo*>
			static const unsigned int	o_PickupArray{ 0x51E970 };	//	ZArray<CPickup*>
			static const unsigned int   o_ProjectileArray{ 0x48E568 };	//	CZProjectileList*

			//	Visuals
			static const unsigned int	o_fog{ 0x1E5AC0 };
			static const unsigned int	o_fps1{ 0x48CF60 };
			static const unsigned int	o_fps2{ 0x48CF64 };
		}

		namespace Enums
		{
			enum EENTITY_TYPE : char
			{
				ENT_TYPE_UNKNOWN,
				ENT_TYPE_RECYCLE,
				ENT_TYPE_SEAL,
				ENT_TYPE_TURRET
			};

			enum EPICKUP_TYPE : __int8
			{
				PICKUP_TYPE_ANIM = 1,
				PICKUP_TYPE_WEAPON = 8,
				PICKUP_TYPE_AMMO,
				PICKUP_TYPE_BOMB = 11
			};

			enum EEQUIPITEM_TYPE : unsigned __int8
			{
				EQUIP_NONE = 0xff,

				// Pistols
				EQUIP_PISTOL = 0,
				GLOCK18,
				MARK23,
				MARK23SD,
				FIVE_SEVEN,
				BERETTA,
				P226,
				DESERT_EAGLE,
				HKP9S,
				CHINESE_TYPE_59,
				CROATIAN_HS95,
				DESIGNATOR,

				// SMGs
				EQUIP_SMG = 30,
				MP5,
				STEYR_AUG9,
				MP5SD,
				FNP90,
				STEYR_MACHINE_PISTOL,
				SKORPION,
				USI,

				// Assault rifles
				EQUIP_ASSAULT_RIFLE = 50,
				M16A2,
				M16_M203,
				HKG11,
				M4A1_CARBINE,
				AR15,
				SIG551_SWAT,
				SIG552_COMMANDO,
				AK47,
				AKS74,
				M14,
				M4A1_CARBINE_M203,
				M4A1_CARBINE_SILENCED,

				// Shotguns
				EQUIP_SHOTGUN = 80,
				SPAS121,
				RM3_SUPER_COMBAT,
				JACKHAMMER,
				REMINGTON870,

				// Heavy machine guns
				EQUIP_MACHINEGUN,
				M60E,
				STONER_M63A,
				MARK46MOD0,

				// Sniper rifles
				EQUIP_SNIPER_RIFLE = 100,
				BARRETM82A1,
				REMMINGTON700,
				MCMILLAN,
				DRAGUNOV,
				STONER_SR25_SILENCED,
				STONER_SR25,

				// Grenades
				EQUIP_GRENADE = 120,
				GRENADE,
				SMOKE_GRENADE,
				FLASHBANG,
				PHOS_GRENADE,
				TEARGAS_GRENADE,
				HE_GRENADE,

				// Heavy weapons
				EQUIP_HEAVYWEAPON = 140,
				M203,
				MULTI_GRENADE_LAUNCHER,
				M79,

				// Explosives
				EQUIP_EXPLOSIVE = 150,
				C4,
				SATCHEL_CHARGE,
				CLAYMORE,
				MPBOMB,
				F18_MISSILE,
				EXPLODING_BARREL,

				// Melee weapons
				EQUIP_MELEE = 160,
				TASER,

				// Launched grenades
				EQUIP_LAUNCHED_GRENADE = 170,
				M203_HE,
				M203_IL,
				M203_SMOKE,
				M203_GAS,
				M203_FRAG,
				GL_HE,
				GL_IL,
				GL_SMOKE,
				GL_FRAG,

				// Equipment
				EQUIP_EQUIPMENT = 180,
				FLASHLIGHT,
				BINOCULARS,
				RESTRAINTS,
				OLD_NVG_ID,
				OLD_DESIGNATOR,
				KNIFE,
				DETONATOR,
				DOUBLE_AMMO_LOAD,

				// Armor
				EQUIP_ARMOR = 200,
				KEVLAR_ARMOR,
				KEVLAR_INSERT_ARMOR,

				EQUIP_END = 254
			};

			enum EEQUIPAMMO_TYPE : unsigned __int8
			{
				AMMO_NONE = 0xff,

				A_9X19 = 1,
				A_22_RIFLE,
				A_45_ACP,
				A_45_CASELESS,
				A_50_AE,
				A_50_AE_AP,
				A_545X39_SOVIET,
				A_556X45,
				A_762X51,
				A_50_BROWNING,
				A_FRAG_GRENADE,
				A_SMOKE_GRENADE,
				A_TEARGAS_GRENADE,
				A_FLASHBANG,
				A_WP_GRENADE,
				A_SATCHEL_CHARGE,
				A_CLAYMORE,
				A_C4,
				A_MPBOMB,
				A_M203_HE,
				A_M203_IL,
				A_M203_SMOKE,
				A_M203_GAS,
				A_F18_MISSILE,
				A_EXPLODING_BARREL,
				A_HE_GRENADE,
				A_12GAUGE,
				A_M203_FRAG,
				A_GL_FRAG,
				A_GL_IL,
				A_GL_SMOKE,
				A_GL_GAS,
				A_9X19S,
				A_9X19SD,
				A_556X45SD,
				A_762X51SD,
				A_762X39SD,
				A_57X28,

				AMMO_END = 254
			};

			enum EPROJECTILE_TYPE
			{
				PROJECTILE_TYPE_NORMAL,
				PROJECTILE_TYPE_ONE_FRAME,
				PROJECTILE_TYPE_ONE_FRAME_SHOTGUN
			};

			enum EPROJECTILE_STATE
			{
				PROJECTILE_STATE_EXPIRED,
				PROJECTILE_STATE_FLYOUT,
				PROJECTILE_STATE_AT_REST,
				PROJECTILE_STATE_TO_BE_DETONATED,
				PROJECTILE_STATE_DETONATION_TO_BE_HANDLED,
				PROJECTILE_STATE_WAS_DETONATED,
				PROJECTILE_STATE_TO_BE_REMOVED
			};

			enum EGRENADE_STATE
			{
				GRENADE_STATE_CREATE,
				GRENADE_STATE_NEWPOS,
				GRENADE_STATE_DETONATE,
				GRENADE_STATE_REMOVE
			};

			enum ESEALBONES_INDEX
			{
				ESEALBONES_MIN = 0,
				ESEALBONES_root = ESEALBONES_MIN,
				ESEALBONES_aimnodes,
				ESEALBONES_lfoot,			//	left heel
				ESEALBONES_rfoot,			//	right heel
				ESEALBONES_lhand,			//	left hand
				ESEALBONES_spinelo,			//	lower spine
				ESEALBONES_rhand,			//	right hand
				ESEALBONES_hips,
				ESEALBONES_head,			//	center head
				ESEALBONES_neck,			//	neck
				ESEALBONES_spinehi,			//	upper spine
				ESEALBONES_lthigh,			//	left hip
				ESEALBONES_rthigh,			//	right hip
				ESEALBONES_rcalf,			//	right knee
				ESEALBONES_rbicep,			//	right shoulder
				ESEALBONES_rforearm,		//	right elbow
				ESEALBONES_lbicep,			//	left shoulder
				ESEALBONES_lforearm,		//	left elbow
				ESEALBONES_lscap,
				ESEALBONES_rscap,
				ESEALBONES_lshoulder_wgt,	//	left shoulder
				ESEALBONES_rshoulder_wgt,	//	right shoulder
				ESEALBONES_lcalf,			//	knee
				ESEALBONES_ltoe,			//	foot	
				ESEALBONES_rtoe,			//	foot
				ESEALBONES_weapon,
				ESEALBONES_rifle,
				ESEALBONES_pistol,
				ESEALBONES_grenade,
				ESEALBONES_reyeball,
				ESEALBONES_leyeball,
				ESEALBONES_reyelid,
				ESEALBONES_leyelid,
				ESEALBONES_MAX = ESEALBONES_leyelid
			};

			enum EZOOM_STATE : char
			{
				EZoomState_default = 0,
				EZoomState_1stperson = 1,
				EZoomState_unknown = 2,
				EZoomState_binocs = 3,
				EZoomState_weapondef_1 = 4
			};

			enum class ESEAL_TEAMS : i32_t
			{
				// MULTIPLAYER
				ETeam_SEALS = 0x40000001,			//	Seal
				ETeam_TERRORIST = 0x80000100,		//	Terrorist
				ETeam_TURRET = 0x48000000,			//	Turret
				ETeam_SPECTATOR = 0x00010000,		//	Spectator
				ETeam_GHOST = 0x00020000,			//	test

				// CAMPAIGN
				ETeam_SP_ABLE = 0x84000006,			//	Alpha Team
				ETeam_SP_BRAVO = 0x8400000A,		//	Bravo Team
				ETeam_SP_ENEMY_A = 0x40000050,		//	Iron Brother / Iron Leader
				ETeam_SP_ENEMY_B = 0x40000100,		//	
				ETeam_SP_ENEMY_C = 0x40000210,		//	
				ETeam_SP_ENEMY_D = 0x40000410,		//	
				ETeam_SP_ENEMY_E = 0x40000810,		//	
				ETeam_SP_ENEMY_F = 0x40001010,		//	
				ETeam_SP_ENEMY_G = 0x40002010,		//	
				ETeam_SP_ENEMY_H = 0x40004010,		//	
				ETeam_SP_ENEMY_I = 0x40021010,		//	
				ETeam_NONE = 0
			};

			enum ESEAL_STANCE : char
			{
				ESealStance_Stand = 0,
				ESealStance_Crouch = 1,
				ESealStance_Prone = 2
			};

			enum ESEAL_LEAN : char
			{
				ESealLean_LEFT,
				ESealLean_UP,
				ESealLean_RIGHT,
				ESealLean_NONE
			};

			enum EWEAPONEQUIP_INDEX : __int32
			{
				EWeaponIndex_Primary = 0,
				EWeaponIndex_Secondary = 1,
				EWeaponIndex_EqSlot1 = 2,
				EWeaponIndex_EqSlot2 = 3,
				EWeaponIndex_EqSlot3 = 4
			};

			enum  EWEAPON_ENCUMBRANCE : char
			{
				LIGHTLY_ENCUMBERED,
				MEDIUM_ENCUMBERED,
				HEAVY_ENCUMBERED,
				VERY_HEAVILY_ENCUMBERED,
				NOT_ENCUMBERED,
				NUM_ECUMBTYPES
			};

			enum EWEAPON_FIREMODE : __int32
			{
				EFireMode_Default = 0,
				EFireMode_Single = 1,
				EFireMode_Burst = 2,
				EFireMode_Auto = 3,
				EFireMode_Special,
				NUM_FIREMODES
			};

			/*
				Weapons

				NOTE: points to static addresses in the game module defined in SOCOM1_package.h
			*/
			enum class EWEAPON : i32_t
			{
				EWeapon_EMPTY = 0,
				EWeapon_M4A1 = WEAPON_M4A1,
				EWeapon_M4A1_SD = WEAPON_M4A1_SD,
				EWeapon_M4A1_M203 = WEAPON_M4A1_M203,
				EWeapon_M16A2 = WEAPON_M16A2,
				EWeapon_M16A2_M203 = WEAPON_M16A2_M203,
				EWeapon_552 = WEAPON_552,
				EWeapon_AK47 = WEAPON_AK47,
				EWeapon_AKS74 = WEAPON_AKS74,
				EWeapon_M14 = WEAPON_M14,
				EWeapon_M63A = WEAPON_M63A,
				EWeapon_M60E3 = WEAPON_M60E3,
				EWeapon_STONER63 = WEAPON_STONER_63,	//	unknown, not used in SOCOM 1
				EWeapon_Remington870 = WEAPON_REMINGTON_870,	//	unknown, not used in SOCOM 1
				EWeapon_MK3_A2 = WEAPON_MK3_A2_SHOTGUN,	//	unknown, not used in SOCOM 1	
				EWeapon_UZI = WEAPON_9M_SUB,
				EWeapon_F90 = WEAPON_F90,
				EWeapon_HK5 = WEAPON_HK5,
				EWeapon_HK5_SD = WEAPON_HK5_SD,
				EWeapon_SR25 = WEAPON_SR25,
				EWeapon_SR25_SD = WEAPON_SR25_SD,
				EWeapon_M40A1 = WEAPON_M40A1,
				EWeapon_M87ELR = WEAPON_M87ELR,
				EWeapon_M82A1A = WEAPON_M82A1A,
				EWeapon_M79 = WEAPON_M79,
				EWeapon_MGL = WEAPON_MGL,
				EWeapon_M203 = WEAPON_M203,
				EWeapon_M9 = WEAPON_M9,
				EWeapon_9MM = WEAPON_9MM_Pistol,
				EWeapon_P226 = WEAPON_P226,
				EWeapon_F57 = WEAPON_F57,
				EWeapon_MODEL18 = WEAPON_MODEL_18,
				EWeapon_DE50 = WEAPON_DE50,
				EWeapon_MARK23 = WEAPON_MARK_23,
				EWeapon_MARK23_SD = WEAPON_MARK23_SD,
				EWeapon_M67 = WEAPON_M67,
				EWeapon_HE = WEAPON_HE_GRENADE,
				EWeapon_SMOKE = WEAPON_SMOKE,
				EWeapon_FLASHBANG = WEAPON_FLASHBANG,
				EWeapon_2XAMMO = WEAPON_2X_AMMO,
				EWeapon_M79_HE = WEAPON_M79_HE,
				EWeapon_M79_FRAG = WEAPON_M79_FRAG,
				EWeapon_M79_SMOKE = WEAPON_M79_SMOKE,
				EWeapon_M203_HE = WEAPON_M203_HE,
				EWeapon_M203_FRAG = WEAPON_M203_FRAG,
				EWeapon_M203_SMOKE = WEAPON_M203_SMOKE,
				EWeapon_C4 = WEAPON_C4,
				EWeapon_CLAYMORE = WEAPON_CLAYMORE,
				EWeapon_SATCHEL = WEAPON_SATCHEL,
				EWeapon_MPBOMB = WEAPON_MPBOMB,	//	unknown, not used in SOCOM 1
				EWeapon_KNIFE = WEAPON_KNIFE,		//	unknown, not used in SOCOM 1
				EWeapon_FLASHLIGHT = WEAPON_FLASHLIGHT,	//	unknown, not used in SOCOM 1
				EWeapon_DETONATOR = WEAPON_DETONATOR,	//	unknown, not used in SOCOM 1
				EWeapon_BINOCULARS = WEAPON_BINOCULARS,	//	unknown, not used in SOCOM 1
				EWeapon_RESTRAINTS = WEAPON_RESTRAINTS,	//	unknown, not used in SOCOM 1
				EWeapon_KEVLAR_ARMOR = WEAPON_KEVLAR_ARMOR,	//	unknown, not used in SOCOM 1
				EWeapon_KEVLAR_ARMOR_INSERT = WEAPON_KEVLAR_ARMOR_INSERT,	//	unknown, not used in SOCOM 1
				EWeapon_ExplodingFuel = WEAPON_EXPLODING_FUEL,	//	unknown, not used in SOCOM 1
				EWeapon_ATG_MISSILE = WEAPON_ATG_MISSILE,	//	unknown, not used in SOCOM 1
				EWeapon_SATCHEL_EXPLOSION = WEAPON_SATCHEL_EXPLOSION,	//	unknown, not used in SOCOM 1
				EWeapon_LASER_DESIGNATOR = WEAPON_LASER_DESIGNATOR,	//	unknown, not used in SOCOM 1
			};

			/*
				Weapon Ammo Types

				NOTE: points to static addresses in the game module defined in SOCOM1_package.h
			*/
			enum class EAMMO : i32_t
			{
				EWeaponAmmo_EMPTY = 0,

				EWeaponAmmo_M4A1 = AMMO_556x45,
				EWeaponAmmo_M4A1_M203 = AMMO_556x45,
				EWeaponAmmo_M4A1_SD = AMMO_556x45_SD,
				EWeaponAmmo_M16A2 = AMMO_556x45,
				EWeaponAmmo_M16A2_M203 = AMMO_556x45,
				EWeaponAmmo_552 = AMMO_556x45,
				EWeaponAmmo_AK74 = AMMO_762x39,
				EWeaponAmmo_AKS74 = AMMO_545x39,
				EWeaponAmmo_M14 = AMMO_762x51,

				EWeaponAmmo_UZI = AMMO_9x19P,
				EWeaponAmmo_HK5 = AMMO_9x19P,
				EWeaponAmmo_HK5_SD = AMMO_9x19P_SD,
				EWeaponAmmo_F90 = AMMO_57x28,

				EWeaponAmmo_M60E3 = AMMO_762x51,
				EWeaponAmmo_M63A = AMMO_556x45,

				EWeaponAmmo_SR25 = AMMO_762x51,
				EWeaponAmmo_SR25_SD = AMMO_762x51,
				EWeaponAmmo_M40A1 = AMMO_762x51,
				EWeaponAmmo_M82A1A = AMMO_50BMG,
				EWeaponAmmo_M87ELR = AMMO_50BMG,

				//	EWeaponAmmo_M79 = AMMO_2xAmmo,
				//	EWeaponAmmo_MGL = AMMO_2xAmmo,

				EWeaponAmmo_9MM = AMMO_9x19P,
				EWeaponAmmo_P226 = AMMO_9x19P,
				EWeaponAmmo_M18 = AMMO_9x19P,
				EWeaponAmmo_F57 = AMMO_57x28,
				EWeaponAmmo_DE50 = AMMO_50AE,
				EWeaponAmmo_MK23 = AMMO_45ACP,
				EWeaponAmmo_MK23_SD = AMMO_45ACP,

				EWeaponAmmo_M67 = AMMO_M67,
				EWeaponAmmo_HE = AMMO_HE,
				EWeaponAmmo_M141 = AMMO_M141,
				EWeaponAmmo_Smoke = AMMO_SMOKE,
				EWeaponAmmo_Claymore = AMMO_CLAYMORE,
				EWeaponAmmo_C4 = AMMO_C4,

				EWeaponAmmo_M79_HE = AMMO_M79_HE,
				EWeaponAmmo_M79_FRAG = AMMO_M79_FRAG,
				EWeaponAmmo_M79_SMOKE = AMMO_M79_SMOKE,
				EWeaponAmmo_M203_HE = AMMO_M203_HE,
				EWeaponAmmo_M203_FRAG = AMMO_M203_FRAG,
				EWeaponAmmo_M203_SMOKE = AMMO_M203_SMOKE,

				EWeaponAmmo_Satchel = AMMO_SATCHEL,
				EWeaponAmmo_LONGRIFLE = AMMO_LONGRIFLE,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_SHOTGUN = AMMO_12GUAGE,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_MP_BOMB = AMMO_MPBOMB,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_ATG_Missile = AMMO_MISSILE,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_ExplosiveStuff = AMMO_EXPLOSIVE_STUFF,	//	unknown, not used in SOCOM 1

				//	EWeaponAmmo_2xAmmo = AMMO_2xAmmo,
			};
		}

		namespace Structs
		{

			struct RFloat
			{
				float min;
				float range;
			};

			struct SSealStats
			{
				int mHeadshots; //0x0000
				int mHeadHits; //0x0004
				int mHits; //0x0008
				int mShotsFired; //0x000C
				int mKills; //0x0010
				int mWasHit; //0x0014
				int mDeaths; //0x0018
				int mHostages; //0x001C
				int mBasesBlown; //0x0020
				int mHostagesRescued; //0x0024
				float mAccuracy; //0x0028
				int mTimesSeen; //0x002C
				int mStealthKills; //0x0030
				int mRestrains; //0x0034
				int mGrenadesThrown; //0x0038
				int mCqcTakedowns; //0x003C
				int mPrimaryRoundsFired; //0x0040
				int mSecondaryRoundsFired; //0x0044
				__int16 mMVPScore; //0x0048
				int mRoundsWon; //0x004A
				int mRoundsLost; //0x004E
			}; //Size: 0x0052

			struct CZKit
			{
				// CZSeal
				//	__int32							mTotalShotsFired;			//0x04DC
				//	char							pad_04E0[48];				//0x04E0
				//	__int32							mPrimaryShotsFired;			//0x0510
				//	__int32							mSecondaryShotsFired;		//0x0514
				//	char							pad_0518[52];				//0x0518
				//	float							mRecoilPunch;				//0x054C
				//	char							pad_0550[188];				//0x0550
				//	i32_t							mPrimaryWeapon;				//0x060C	* CZWeapon
				//	i32_t							mSecondaryWeapon;			//0x0610	* CZWeapon
				//	i32_t							mEqSlot1;					//0x0614	* CZWeapon
				//	i32_t							mEqSlot2;					//0x0618	* CZWeapon
				//	i32_t							mEqSlot3;					//0x061C	* CZWeapon
				//	char							pad_0620[100];				//0x0620
				//	__int32							mPrimaryAmmoType;			//0x0684	* CZAmmo
				//	__int32							mSecondaryAmmoType;			//0x0688	* CZAmmo
				//	__int32							mEqSlot1AmmoType;			//0x068C	* CZAmmo
				//	__int32							mEqSlot2AmmoType;			//0x0690	* CZAmmo
				//	__int32							mEqSlot3AmmoType;			//0x0694	* CZAmmo
				//	char							pad_0698[100];				//0x0698
				//	__int32							mPrimaryMags[10];			//0x06FC
				//	__int32							mSecondaryMags[10];			//0x0724
				//	__int32							mEqSlot1Ammo;				//0x074C
				//	char							pad_0750[36];				//0x0750
				//	__int32							mEqSlot2Ammo;				//0x0774
				//	char							pad_0778[36];				//0x0778
				//	__int32							mEqSlot3Ammo;				//0x079C
				//	char							pad_07A0[1156];				//0x07A0
				//	Enums::EWEAPON_FIREMODE			mPrimaryFireType;			//0x0C24
				//	Enums::EWEAPON_FIREMODE			mSecondaryFireType;			//0x0C28
				//	char							pad_0C2C[272];				//0x0C2C
				//	__int32							mCurrentShotsFired;			//0x0D3C
				//	float							mFireCooldown;				//0x0D40
				//	Enums::EWEAPONEQUIP_INDEX				mCurrentWeaponIndex;		//0x0D44
				//	char							pad_0D48[4];				//0x0D48
				//	__int32							mMaxWeaponIndex;			//0x0D4C
				//	char							pad_0D50[308];				//0x0D50
				//	__int32							mWeaponReadyState;			//0x0E84

				bool m_first : 1;						
				bool m_reticuletypeChanged : 1;
				bool m_weaponinfoChanged : 1;
				bool m_retblocked : 1;
				bool m_nvg_enabled : 1;
				bool m_binocs_enabled : 1;
				bool m_lase_echo : 1;
				bool m_lase_deploy_echo : 1;
				bool m_lensfx_enable : 1;
				bool m_waiting_to_fire : 1;
				bool m_waiting_to_raise : 1;
				bool m_changeToRifle : 1;
				bool m_requested_item : 1;
				bool m_current_requested_ammo : 1;
				bool m_pad_bitfield : 1;
				bool m_heartbeat_enabled : 1;
				//	bool m_unused : 18;

				char pad_0002[22]; //0x0002
				Vec2 mRecoilPunch; //0x0018
				Vec2 mPrevRecoilPunch; //0x0020
				char pad_0028[8]; //0x0028
				Vec3 mRifleKick; //0x0030
				__int32 mFireRifleKickState; //0x003C
				__int32 mHeartbeatState; //0x0040
				Vec2 mHeartbeat; //0x0044
				__int32 mCurItemReticule; //0x004C
				Vec2 mScreenOffset; //0x0050
				char pad_0058[132]; //0x0058
				i32_t pWeapons[10]; //0x00DC	CZWeapon*
				char pad_0104[80]; //0x0104
				i32_t pAmmoTypes[10]; //0x0154	CZAmmo*
				char pad_017C[80]; //0x017C
				__int32 mPrimaryMags[10]; //0x01CC
				__int32 mSecondaryMags[10]; //0x01F4
				__int32 mEqSlot1Ammo; //0x021C
				char pad_0220[36]; //0x0220
				__int32 mEqSlot2Ammo; //0x0244
				char pad_0248[36]; //0x0248
				__int32 mEqSlot3Ammo; //0x026C
				char pad_0270[1036]; //0x0270
				__int32 PrimaryMagIndex; //0x067C
				__int32 SecondaryMagIndex; //0x0680
				char pad_0684[112]; //0x0684
				Enums::EWEAPON_FIREMODE mWeaponFireTypes[2]; //0x06F4
				char pad_06FC[272]; //0x06FC
				__int32 mWeaponFireCount; //0x080C
				float mWeaponFireDelta; //0x0810
				Enums::EWEAPONEQUIP_INDEX mCurrentWeaponIndex; //0x0814
				char pad_0818[4]; //0x0818
				__int32 mMaxWeaponIndex; //0x081C
				i32_t pSealBody; //0x0820	CZSealBody*
				char pad_0824[108]; //0x0824

				bool GetEquippedWeapon(i32_t& outWeapon);									//	attempts to retrieve equipped weapon, returns true if outWeapon != 0
				bool GetEquippedAmmo(i32_t& outAmmo);										//	attempts to retrieve equipped ammo type, returns true if outAmmo != 0
				bool GetWeaponAtIndex(const Enums::EWEAPONEQUIP_INDEX& index, i32_t& outWeapon);	//	attempts to retrieve weapon, returns true if outWeapon != 0
				bool GetAmmoAtIndex(const Enums::EWEAPONEQUIP_INDEX& index, i32_t& outAmmo);		//	attempts to retrieve ammo type, returns true if outAmmo != 0
				bool GetWeaponName(const Enums::EWEAPONEQUIP_INDEX& index, std::string& outName);	//	attempts to retrieve weapon name , returns true if size of string > 0
				bool GetAmmoName(const Enums::EWEAPONEQUIP_INDEX& index, std::string& outName);	//	attempts to retrieve ammo name , returns true if size of string > 0
				void SetHeartbeatEnabled(bool enabled);										//	sets heartbeat enabled state
				bool GetHeartbeatEnabled() const;											//	returns heartbeat enabled state
				std::string GetWeaponName(const Enums::EWEAPONEQUIP_INDEX& index);
				std::string GetAmmoName(const Enums::EWEAPONEQUIP_INDEX& index);
			};
		}
		
		enum EWeaponSlot : uint32_t
		{
			Primary,		// = 0x60C,
			Secondary,		// = 0x610,
			EqSlot1,		// = 0x614,
			EqSlot2,		// = 0x618,
			EqSlot3,		// = 0x61C,
		};
		/*
			static const char* AvailSlots[5] = 
			{ 
				"Primary", 
				"Secondary", 
				"Equipment 1", 
				"Equipment 2", 
				"Equipment 3" 
			};
		*/


		/*
		* KEY:
			- P = Primary
			- S = Secondary
			- EQ = Equipment
		*/
		enum class EWEAPON : __int32
		{
			// Assault Rifles
			EWeapon_M4A1_M203			= 0xCC4270,
			EWeapon_M4A1_SD			= 0xCC3F80,
			EWeapon_M16A2				= 0xCC36E0,
			EWeapon_P_AR_M16_M203			= 0xCC39C0,
			EWeapon_552				= 0xCC4550,
			EWeapon_P_AR_AK74				= 0xCC4850,
			EWeapon_AKS74				= 0xCC4B20,
			
			//	
			EWeapon_P_SMG_9MM				= 0xCC61F0,
			EWeapon_HK5				= 0xCC5970,
			EWeapon_HK5_SD			= 0xCC5C40, 
			
			//	
			EWeapon_M40A1			= 0xCC67A0,

			//	
			EWeapon_9MM			= 0xCC22D0,
			EWeapon_S_PISTOL_9MM_SD			= 0xCC2B60,
			EWeapon_MARK23			= 0xCC1A10,
			EWeapon_MARK23_SD		= 0xCC2880,
			EWeapon_S_PISTOL_226			= 0xCC25B0,
			EWeapon_F57			= 0xCC1CF0,
			EWeapon_DE50			= 0xCC1FD0,

			//	
			EWeapon_EQ_Flashbang			= 0xCC8A60,
			EWeapon_C4					= 0xCC9300,
			EWeapon_EQ_Claymore				= 0xCC9030,
			EWeapon_EQ_Satchel				= 0xCC8D50,
			EWeapon_M67					= 0xCC81A0,
			EWeapon_HE					= 0xCC8490,
			EWeapon_EQ_Smoke				= 0xCC8760,
			EWeapon_2XAMMO				= 0xCCB800,
			EWeapon_EQ_M203_HE				= 0xCC9B50,
			EWeapon_EQ_M203_FRAG			= 0xCC9E30,
			EWeapon_EQ_M203_SMOKE			= 0xCCA120,
		};
		const char* GetWeaponName(EWEAPON weapon);

		enum class EAmmoType : unsigned __int32
		{
			EAmmoType_556x45_SD				= 0xCC0ED0,			//	M4A1_SD , 
			EAmmoType_556x45				= 0xCC0F40,			//	M4A1, M16A2, 552 , 
			EAmmoType_762x39				= 0xCC1050,			//	AK47 , 
			EAmmoType_545x39				= 0xCC0E60,			//	AKS74
			EAmmoType_9x19p					= 0xCC0C90,			//	SMG_HK5, SMG_9MM, PISTOL_MODEL_18, PISTOL_9MM
			EAmmoType_9x19p_SD				= 0xCC0CD0,			//	SMG_HK5_SD, PISTOL_9MM_SD
			EAmmoType_45ACP					= 0xCC0DC0,			//	PISTOL_MK23
			EAmmoType_762x51				= 0xCC0F90,			//	M40A1 , 
			EAmmoType_50AE					= 0xCC0E10,			//	DE50 , 
			EAmmoType_57x28					= 0xCC0D20,			//	F57
			EAmmoType_2xAmmo				= 0x0,
			EAmmoType_Satchel				= 0xCC12C0,
			EAmmoType_Smoke					= 0xCC1210,
			EAmmoType_Claymore				= 0xCC1320,
			EAmmoType_C4					= 0xCC1380,
			EAmmoType_M203_HE				= 0xCC1420,
			EAmmoType_M203_FRAG				= 0xCC1490,
			EAmmoType_M203_SMOKE			= 0xCC1500,
		};
		const char* GetAmmoTypeName(EAmmoType weapon);
		/* 
			static const char* AmmoTypes[1] =
			{
				"NULL"							//	0
			};
		*/

		enum class EFireType : unsigned __int32
		{
			//	Single, Burst, Auto, SecondaryWeapon, EqSlot1, EqSlot2, EqSlot3
			EFireType_Single = 1,				//	
			EFireType_Burst = 2,				//	
			EFireType_Auto = 3,					//	
			EFireType_SecondaryWeapon = 4,		//	
			EFireType_EqSlot1 = 5, 				//	
			EFireType_EqSlot2 = 6,				//	
			EFireType_EqSlot3 = 7				//	
		};
		const char* GetFireTypeName(EAmmoType weapon);
		/*
			enum EPrimaryWeapon : uint32_t
			{
				AR_M4A1_SD	= 0xCC3F80,			
				AR_552		= 0xCC4550,			
				AR_AK74		= 0xCC4850,
				SMG_9MM		= 0x00CC61F0,
				SMG_HK5		= 0xCC5970,
				SMG_HK5_SD	= 0xCC5C40,
				abs1		= 0xCC6D90,			
			};

			enum ESecondaryWeapon : uint32_t
			{
				PISTOL_9MM	= 0xCC2B60,		
				PISTOL	= 0xCC2880,
				_abs		= 13402528,		
				_abs2		= 13401072,		
				_abs3		= 13395872,		
				_abs4		= 13377488,		
			};

			enum EEquipment : uint32_t
			{
				Flashbang = 0x0,
				EEquipment_Satchel	= 0xCC8D50,	//	satchel, flash, grenade
				EEquipment_M67		= 0xCC81A0,	//	
				EEquipment_FlashBang = 0xCC8A60	//	
			};
		*/

		enum class ETeam : unsigned __int32
		{
			SEALS		= 0x40000001,		//	Seal
			TERRORIST	= 0x80000100,		//	Terrorist
			TURRET		= 0x48000000,		//	Turret
			SPECTATOR	= 0x00010000,		//	Spectator

			// CAMPAIGN
			SP_ABLE		= 0x84000006,		//	Alpha Team
			SP_BRAVO	= 0x8400000A,		//	Bravo Team
			SP_ENEMY_A	= 0x40000050,		//	Iron Brother / Iron Leader
			SP_ENEMY_B	= 0x40000100,		//	
			SP_ENEMY_C	= 0x40000210,		//	
			SP_ENEMY_D	= 0x40000410,		//	
			SP_ENEMY_E	= 0x40000810,		//	
			SP_ENEMY_F	= 0x40001010,		//	
			SP_ENEMY_G	= 0x40002010,		//	
			SP_ENEMY_H	= 0x40004010,		//	
			SP_ENEMY_I	= 0x40021010,		//	
			NONE		= 0
		};
		const char* GetTeamName(ETeam team);
		/*
		
			static const char* TeamNames[5] =
			{
				"SEALS",			//	0
				"TERRORISTS",		//	1
				"SPECTATOR",		//	2
				"ABLE",				//	3
				"BRAVO",			//	4
			};
		*/

		enum class EMap : unsigned __int32
		{

		};
		const char* GetMapName(EMap map);
		/*
			static const char* MapNames[1] =
			{
				"NULL"
			};
		*/

		enum class EPlayerViewState : __int8
		{

		};

		enum class ECameraViewState : __int8
		{

		};

		//	
		struct FViewModel
		{
			Vec4 right;		//	Vector3 : right vector
			Vec4 up;		//	Vector3 : up vector
			Vec4 fwd;		//	Vector3 : look vector ( - is forward )
			Vec4 pos;		//	Vector3 : position
		};

		//	
		struct FViewCache
		{
			Vec3 m1;	//0x0000	//	
			Vec3 m2;	//0x000C	//	
			Vec3 m3;	//0x0018	//	
			Vec3 m4;	//0x0024	//	tilt 
			Vec3 m5;	//0x0030	//	z = camera distance from player
			Vec3 m6;	//0x003C
		};	//Size: 0x0048

		//	
		template<typename Z>
		struct ZArrayIterator
		{
		private:
			__int32 _next;		//	next item in the array, points to the next ZArrayIterator<Z>
			__int32 _prev;		//	previous item in the array, points to the previous ZArrayIterator<Z>
			__int32 _data;		//  pointer to data type
		
		public:
			
			ZArrayIterator()
			{
				_next = 0;
				_prev = 0;
				_data = 0;
			}
			
			ZArrayIterator(__int32 next, __int32 prev, __int32 data)
			{
				_next = next;
				_prev = prev;
				_data = data;
			}

			Z Data() const { return reinterpret_cast<Z>(PS2Memory::GetEEBase() + _data); }
			ZArrayIterator<Z> Next() const { return PS2Memory::ReadEE<ZArrayIterator<Z>>(_next); }
			ZArrayIterator<Z> Prev() const { return PS2Memory::ReadEE<ZArrayIterator<Z>>(_prev); }
		};

		template<typename Z>
		struct ZArray
		{
		private:
			__int32 _count;		//	number of elements in the array
			__int32 _begin;		//	first item in the array, points to the first ZArrayIterator<Z>
			__int32 _end;		//	last item in the array, points to the last ZArrayIterator<Z>
		
		public:
			ZArray()
			{
				_count = 0;
				_begin = 0;
				_end = 0;
			}

			ZArray(__int32 count, __int32 begin, __int32 end)
			{
				_count = count;
				_begin = begin;
				_end = end;
			}

			int Count() const { return _count; }
			bool IsValid() const { return false; }	//	check if count > 0 && if _begin & _end are <= 0
			ZArrayIterator<Z> GetIterator() const { return PS2Memory::ReadEE<ZArrayIterator<Z>>(_begin); }

			std::vector<Z> Data() const
			{
				std::vector<Z> result;	/* result container */

				if (_count > 0)
				{
					ZArrayIterator<Z> it = GetIterator();	/* get first item */
					ZArrayIterator<Z> end = it.Prev();		/* get last item */
					
					do
					{
						/* get the data */
						Z data = it.Data();

						/* populate result with data */
						result.push_back(data);

						/* move on to the next item */
						it = it.Next();

					} while (it.Data() != end.Data());	/* loop until the end */ 
				}

				return result;
			}
		};
	}

}
#pragma pack(pop)