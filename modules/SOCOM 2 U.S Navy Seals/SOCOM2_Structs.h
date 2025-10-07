#pragma once

/**
 * Name: SOCOM 2
 * Platform: PlayStation 2
 * PCSX2 Version: 1.7 beta
 * Author: NightFyre
*/

#pragma pack(push, 0x01)
namespace PlayStation2
{
	//	@TODO: include in CDK source
	struct Patch
	{
	public:
		unsigned __int32 dst;
		unsigned __int32 patch;
		unsigned __int32 original;

		Patch(unsigned __int32 d, unsigned __int32 p, unsigned __int32 o) : dst(d), patch(p), original(o) {};
	};

	namespace SOCOM2
	{

		namespace Offsets
		{
			/* */

			/* */
			static const i32_t o_LocalCAppCamera{ 0x4429B0 };				//
			static const i32_t o_LocalSeal{ 0x44D648 };						//
			static const i32_t o_pEntityArray{ 0x442CE8 };					//	ZArray<CEntity*>
		
			/* */
			static const i32_t p_WeaponManager{ WEAPON_MODEL_18 };			//	ZWeaponList
			static const i32_t p_AmmoManager{ AMMO_9x19P };					//	CZAmmo*[]
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
				ETeam_SEALS = 0x40000001,		//	Seal
				ETeam_TERRORIST = 0x80000100,		//	Terrorist
				ETeam_TURRET = 0x48000000,		//	Turret
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

			enum ESEALBONES_INDEX : int
			{
				ESEALBONES_skel_root = 0,
				ESEALBONES_aimnodes,
				ESEALBONES_lfoot,	// left knee
				ESEALBONES_rfoot,	//	right knee
				ESEALBONES_lhand,	//	left elbow
				ESEALBONES_spinelo,
				ESEALBONES_rhand,	// right elbow
				ESEALBONES_hips,
				ESEALBONES_head,	// upper neck
				ESEALBONES_neck,
				ESEALBONES_spinehi,
				ESEALBONES_lthigh,
				ESEALBONES_rthigh,
				ESEALBONES_rcalf,	// rhip
				ESEALBONES_rbicep,
				ESEALBONES_rforearm,
				ESEALBONES_lbicep,
				ESEALBONES_lforearm,
				ESEALBONES_lscap,
				ESEALBONES_rscap,
				ESEALBONES_lshoulder_wgt,
				ESEALBONES_rshoulder_wgt,
				ESEALBONES_lcalf,	//	left hip
				ESEALBONES_ltoe,	//	left heel
				ESEALBONES_rtoe,	//	right heel
				ESEALBONES_weapon,
				ESEALBONES_rifle,
				ESEALBONES_pistol,
				ESEALBONES_right_eyeball,
				ESEALBONES_left_eyeball,
				ESEALBONES_right_lid,
				ESEALBONES_left_lid,
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
				EWeapon_PKM = WEAPON_PKM,	//	unknown, not used in SOCOM 1
				EWeapon_Remington870 = WEAPON_REMINGTON_870,	//	unknown, not used in SOCOM 1
				EWeapon_MK3_A2 = WEAPON_MK3_A2_SHOTGUN,	//	unknown, not used in SOCOM 1	
				EWeapon_UZI = WEAPON_9MM_SUB,
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
				EWeapon_9MM = WEAPON_9MM_PISTOL,
				EWeapon_226 = WEAPON_226,
				EWeapon_F57 = WEAPON_F57,
				EWeapon_MODEL18 = WEAPON_MODEL_18,
				EWeapon_DE50 = WEAPON_DE50,
				EWeapon_MARK23 = WEAPON_MARK_23,
				EWeapon_MARK23_SD = WEAPON_MARK_23_SD,
				EWeapon_M67 = WEAPON_M67,
				EWeapon_HE = WEAPON_HE,
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
				EWeapon_DETONATOR = WEAPON_DETONATOR,	//	unknown, not used in SOCOM 1
				EWeapon_BINOCULARS = WEAPON_BINOCULARS,	//	unknown, not used in SOCOM 1
				EWeapon_KEVLAR_ARMOR = WEAPON_KEVLAR_ARMOR,	//	unknown, not used in SOCOM 1
				EWeapon_KEVLAR_ARMOR_INSERT = WEAPON_KEVLAR_ARMOR_INSERT,	//	unknown, not used in SOCOM 1
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

				EWeaponAmmo_M4A1 = AMMO_556x45mm,
				EWeaponAmmo_M4A1_M203 = AMMO_556x45mm,
				EWeaponAmmo_M4A1_SD = AMMO_556x45mm,
				EWeaponAmmo_M16A2 = AMMO_556x45mm,
				EWeaponAmmo_M16A2_M203 = AMMO_556x45mm,
				EWeaponAmmo_552 = AMMO_556x45mm,
				EWeaponAmmo_AK74 = AMMO_545x39mm_SOVIET,
				EWeaponAmmo_AKS74 = AMMO_545x39mm_SOVIET,
				EWeaponAmmo_M14 = AMMO_762x51mm,

				EWeaponAmmo_UZI = AMMO_9x19P,
				EWeaponAmmo_HK5 = AMMO_9x19P,
				EWeaponAmmo_HK5_SD = AMMO_9x19P,
				EWeaponAmmo_F90 = AMMO_57x28mm,

				EWeaponAmmo_M60E3 = AMMO_762x39mm_M1943,
				EWeaponAmmo_M63A = AMMO_556x45mm,

				EWeaponAmmo_SR25 = AMMO_762x51mm,
				EWeaponAmmo_SR25_SD = AMMO_762x51mm,
				EWeaponAmmo_M40A1 = AMMO_762x51mm,
				EWeaponAmmo_M82A1A = AMMO_50BMG,
				EWeaponAmmo_M87ELR = AMMO_50BMG,

				EWeaponAmmo_9MM = AMMO_9x19P,
				EWeaponAmmo_P226 = AMMO_9x19P,
				EWeaponAmmo_M18 = AMMO_9x19P,
				EWeaponAmmo_F57 = AMMO_57x28mm,
				EWeaponAmmo_DE50 = AMMO_50AE,
				EWeaponAmmo_MK23 = AMMO_45ACP,
				EWeaponAmmo_MK23_SD = AMMO_45ACP,

				EWeaponAmmo_M67 = AMMO_M67,
				EWeaponAmmo_HE = AMMO_HE,
				EWeaponAmmo_M141 = AMMO_FLASHBANG,
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
				EWeaponAmmo_LONGRIFLE = AMMO_LONG_RIFLE,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_SHOTGUN = AMMO_12GUAGE,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_MP_BOMB = AMMO_MPBOMB,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_ATG_Missile = AMMO_MISSILE,	//	unknown, not used in SOCOM 1
				EWeaponAmmo_ExplosiveStuff = AMMO_EXPLOSIVE_STUFF,	//	unknown, not used in SOCOM 1

				//	EWeaponAmmo_2xAmmo = AMMO_2xAmmo,
			};
		}

		namespace Structs
		{
			struct SSealStats
			{
				/* inside CZSealBody */
				//	int8_t mHeadshots; //0x058C
				//	char pad_058D[3]; //0x058D
				//	int8_t mShotsHit; //0x0590
				//	char pad_0591[3]; //0x0591
				//	int8_t mShotsFired; //0x0594
				//	char pad_0595[1]; //0x0595
				//	int8_t mWasFiredAt; //0x0596
				//	char pad_0597[5]; //0x0597
				//	int8_t mWasHit; //0x059C
				//	char pad_059D[1]; //0x059D
				//	int8_t mDeaths; //0x059E
				//	char pad_059F[23]; //0x059F
				//	int8_t mEquipmentUsed; //0x05B6
				//	char pad_05B7[1]; //0x05B7
				//	int8_t mCqCTakedowns; //0x05B8
				//	char pad_05B9[1]; //0x05B9
				//	int8_t mPrimaryShotsFired; //0x05BA
				//	char pad_05BB[1]; //0x05BB
				//	int8_t mSecondaryShotsFired; //0x05BC
			};

			struct CZKit
			{
				/* inside CZSealBody */
				//	Vec2 mRecoilPunch; //0x0600
				//	Vec2 mPrevRecoilPunch; //0x0608
				//	char pad_0610[8]; //0x0610
				//	Vec3 mRifleKick; //0x0618
				//	int32_t mFireRilfeKickState; //0x0624
				//	int32_t mHeartbeatState; //0x0628
				//	Vec2 mHeartbeat; //0x062C
				//	int32_t mCurItemReticule; //0x0634
				//	Vec2 mScreenOffset; //0x0638
				//	char pad_0640[132]; //0x0640
				//	i32_t pWeapons[10]; //0x06C4	CZWeapon*
				//	char pad_06EC[80]; //0x06EC
				//	i32_t pAmmoTypes[10]; //0x073C	CZAmmo*
				//	char pad_0764[120]; //0x0764
				//	int32_t mPrimaryMags[10]; //0x07DC
				//	int32_t mSecondaryMags[10]; //0x0804
				//	int32_t mEqSlot1Ammo; //0x082C
				//	char pad_0830[36]; //0x0830
				//	int32_t mEqSlot2Ammo; //0x0854
				//	char pad_0858[36]; //0x0858
				//	int32_t mEqSlot3Ammo; //0x087C
				//	char pad_0880[996]; //0x0880
				//	int32_t mPrimaryMagIndex; //0x0C64
				//	int32_t mSecondaryMagIndex; //0x0C68
				//	char pad_0C6C[112]; //0x0C6C
				//	int32_t mWeaponFireTypes[2]; //0x0CDC
				//	char pad_0CE4[276]; //0x0CE4
				//	int32_t mWeaponFireCount; //0x0DF8
				//	float mWeaponFireDelta; //0x0DFC
				//	char pad_0E00[4]; //0x0E00
				//	int32_t mCurrentWeaponIndex; //0x0E04
				//	char pad_0E08[4]; //0x0E08
				//	int32_t mMaxWeaponIndex; //0x0E0C
				//	i32_t pEntity; //0x0E10	CEntity*
				//	char pad_0E14[152]; //0x0E14
			};
		}

		struct BulletObject
		{
			char pad_0000[84];	//0x0000
			Vec2 bullet;	//0x0054
			char pad_0060[56];	//0x0060
		};	//Size: 0x0098

		enum EWeaponSlot : unsigned int
		{
			Primary,	// = 0x60C,
			Secondary,	// = 0x610,
			EqSlot1,	// = 0x614,
			EqSlot2,	// = 0x618,
			EqSlot3,	// = 0x61C,
		};
		static const char* AvailSlots[5] = { "Primary", "Secondary", "Equipment 1", "Equipment 2", "Equipment 3" };
		static const char* TeamNames[10] =
		{
			"SEALS",
			"TERRORISTS",
			"SPECTATOR",
			"ABLE",
			"BRAVO",
		};
		static const char* MapNames[50] =
		{
			"Blizzard",					//	0			
			"Blizzard Day",				//	1
			"Frost Fire",				//	2
			"Frostfire Day",			//	3
			"Abandoned",				//	4
			"Abandoned Day",			//	5
			"Sand Storm",				//	6
			"Sandstorm Day",			//	7
			"Night Stalker",			//	8
			"Nightstalker Day",			//	9
			"Desert Glory",				//	10
			"Desert Glory Night",		//	11
			"Seeding Chaos",			//	12
			"Terminal Transaction",		//	13
			"Upland Assault",			//	14
			"Urban Sweep",				//	15
			"Strangle Hold",			//	16
			"Hydro Electric",			//	17
			"Guardian Angels",			//	18
			"Protect and Serve",		//	19
			"Against the Tide",			//	20
			"Lockdown",					//	21
			"Guided Tour",				//	22
			"Doomsday Delivery",		//	23
			"",							//	24
			"Blood Lake",				//	25
			"Blood Lake Night",			//	26
			"Death Trap",				//	27
			"Death Trap Night",			//	28
			"The Ruins",				//	29
			"The Ruins Night",			//	30
			"Enowapi",					//	31
			"Rat's Nest",				//	32
			"Rat's Nest Day",			//	33
			"Fox Hunt",					//	34
			"Vigilance",				//	35
			"Bitter Jungle",			//	36
			"Bitter Jungle Night",		//	37
			"The Mixer",				//	38
			"The Mixer Night",			//	39
			"Fishhook",					//	40
			"Fish Hook Night"			//	41
			"Crossroads"				//	42
			"Crossroads Night"			//	43
			"Shadow Falls"				//	44
			"Shadowfalls Day"			//	45
			"Sujo"						//	46
			"Chain Reaction"			//	47
			"Guidanace"					//	48
			"Requim"					//	49
		};

		enum EWeapon : i32_t
		{

			//
			EWeapon_P_M4A1			= 0xC69920,
			EWeapon_P_M4A1_M203		= 0xC69E40,
			EWeapon_P_M4A1_SD		= 0xC69BB0,
			EWeapon_P_M16A2			= 0xC69690,
			EWeapon_P_M16A2_M203	= 0xC69400,
			EWeapon_P_IW80			= 0xC6B030,
			EWeapon_P_OICW			= 0xC6ADA0,
			EWeapon_P_HK5			= 0xC6BF90,
			EWeapon_P_HK5SD			= 0xC6C220,
			EWeapon_P_HK5K			= 0xC6CC60,
			EWeapon_P_SMG_9MMSUB	= 0xC6C740,
			EWeapon_P_F90			= 0xC6C4B0,
			EWeapon_P_M3_12Gauge	= 0xC68EE0,
			EWeapon_P_M79			= 0xC71BF0,
			EWeapon_P_MGL			= 0xC71960,
			EWeapon_P_M87ELR		= 0xC6D410,
			EWeapon_P_M82A1A		= 0xC6CEF0,

			//	
			EWeapon_S_DE50			= 0xC67790,
			EWeapon_S_M11			= 0xC68480,
			EWeapon_S_SP10			= 0xC68710,
			EWeapon_S_Mark23		= 0xC67270,
			EWeapon_S_Mark23_SD		= 0xC67F60,
			EWeapon_S_Pistol_226	= 0xC67CD0,
			EWeapon_S_Pistol_9MM	= 0xC681F0,
			EWeapon_S_Model18		= 0xC66FE0,

			//	
			EWeapon_EQ_NONE			= 0xC6E370,
			EWeapon_EQ_AmmoReserve	= 0xC73AF0,
			EWeapon_EQ_Frag			= 0xC6EB20,
			EWeapon_EQ_HE			= 0xC6EDB0,
			EWeapon_EQ_Smoke		= 0xC6F040,
			EWeapon_EQ_RedSmoke		= 0xC6F560,
			EWeapon_EQ_Flashbang	= 0xC6F7F0,
			EWeapon_EQ_Claymore		= 0xC6FD30,
			EWeapon_EQ_PMN_Mine		= 0xC6FFC0,
			EWeapon_EQ_C4			= 0xC70250,
			EWeapon_EQ_AT4Heat		= 0xC728C0,
			EWeapon_EQ_AT4Round		= 0xC72B50,
			EWeapon_EQ_RPG7			= 0xC72DE0,
			EWeapon_EQ_RPGRound		= 0xC73070,
			EWeapon_EQ_Satchel		= 0xC6FAA0,
			EWeapon_EQ_Satchel_a	= 0xC6E0E0,
			EWeapon_EQ_OICW_Frag	= 0xC71440,
			EWeapon_EQ_OICW_HE		= 0xC711B0,
			EWeapon_EQ_OICW_Smoke	= 0xC716D0,
			EWeapon_EQ_M79_Frag		= 0xC72110,
			EWeapon_EQ_M79_HE		= 0xC71E80,
			EWeapon_EQ_M79_Smoke	= 0xC723A0,
			EWeapon_EQ_MGL_Frag		= 0xC70C90,
			EWeapon_EQ_MGL_HE		= 0xC70A00,
			EWeapon_EQ_MGL_Smoke	= 0xC70F20,
			EWeapon_EQ_M203			= 0xC70770,
			//	EWeapon_EQ_M203_Frag	= MGL_Frag,
			//	EWeapon_EQ_M203_HE		= MGL_HE,
			//	EWeapon_EQ_M203_Smoke	= MGL_Smoke,
			EWeapon_EQ_ThermalScope = 0xC6E600,
			EWeapon_EQ_Binoculars	= 0xC6E890,

			EWeapon_EQ_EMPTYSlot = NULL,
		};

		enum EAmmoType : i32_t
		{
			AR_556 = 0xC665E0,			//	5.56x45mm
			SMG_9mm = 0xC663B0,			//	9x9P
			PISTOL_45ACP = 0xC664F0,			//	45ACP
			M67_Round = 0xC667C0,
			HE_Round = 0xC66810,
			Flash_Round = 0xC66950,
			ANM8_Smoke = 0xC66860,
			C4_Round = 0xC66A90,			//	
			RPG_Round = 0xC66EF0,			//	
			M87ELR_Round = 0xC66720,			//	M82A1A Round

			//	???
			Unknown_Round1 = 0x13001808,		//

		};

		enum EFireType : unsigned __int32
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

		struct CZKit
		{
			class CZSeal*						pEntity{ nullptr };
			EWeapon								Primary;
			__int32								PrimaryAmmo[10];
			EAmmoType							PrimaryAmmoType;
			EFireType							PrimaryFireType;
			EWeapon								Secondary;
			__int32								SecondaryAmmo[10];
			EAmmoType							SecondaryAmmoType;
			EFireType							SecondaryFireType;
			EWeapon								EqSlot1;
			__int32								Eq1Ammo;
			EAmmoType							Eq1AmmoType;
			EWeapon								EqSlot2;
			__int32								Eq2Ammo;
			EAmmoType							Eq2AmmoType;
			EWeapon								EqSlot3;
			__int32								Eq3Ammo;
			EAmmoType							Eq3AmmoType;
		
			void								GiveWeapon(EWeapon, EWeaponSlot, EAmmoType = {}, EFireType = {});
			void								GiveAmmo(EWeaponSlot, EAmmoType, __int32 count);
			std::string							ExportLoadoutInfo();
		};

		enum class ETeam : unsigned int
		{
			SEALS = 0x40000001,			//	Seal
			TERRORIST = 0x80000100,			//	Terrorist
			TURRET = 0x48000000,			//	Turret
			SPECTATOR = 0x00010000,			//	Spectator

			// CAMPAIGN
			SP_ABLE = 0x84000006,			//	Alpha Team
			SP_BRAVO = 0x8400000A,			//	Bravo Team
			SP_ENEMY_A = 0x40000050,			//	Iron Brother / Iron Leader
			SP_ENEMY_B = 0x40000100,			//	
			SP_ENEMY_C = 0x40000210,			//	
			SP_ENEMY_D = 0x40000410,			//	
			SP_ENEMY_E = 0x40000810,			//	
			SP_ENEMY_F = 0x40001010,			//	
			SP_ENEMY_G = 0x40002010,			//	
			SP_ENEMY_H = 0x40004010,			//	
			SP_ENEMY_I = 0x40021010,			//	
			NONE = 0
		};

		enum class ECameraViewType
		{
			ThirdPersonCamera = 0x100,
			FirstPersonCamera = 0x1,
			EquipmentCameraView = 0x103,
			Scope_8 = 0x305,
			Scope_16 = 0x506,
			Thermal = 0x10102,
		};

		enum EMaps : unsigned int
		{
			MP1 = 0,		//	0
			MP26,			//	1
			MP2,			//	2
			MP27,			//	3
			MP5,			//	4
			MP21,			//	5
			MP73,			//	6
			MP89,			//	7
			MP7,			//	8
			MP29,			//	9
			MP6,			//	10
			MP28,			//	11
			M51,			//	12
			M52,			//	13
			M53,			//	14
			M61,			//	15
			M62,			//	16
			M63,			//	17
			M71,			//	18
			M72,			//	19
			M73,			//	20
			M81,			//	21
			M82,			//	22
			MP_NONE,		//	23
			MP10,			//	24
			MP32,			//	25
			MP11,			//	26
			MP33,			//	27
			MP12,			//	28
			MP34,			//	29
			MP62,			//	30
			MP8,			//	31
			MP30,			//	32
			MP53,			//	33
			MP51,			//	34
			MP9,			//	35
			MP31,			//	36
			MP52,			//	37
			MP25,			//	38
			MP71,			//	39
			MP23,			//	40
			MP72,			//	41
			MP24,			//	42
			MP64,			//	43
			MP80,			//	44
			MP61,			//	45
			MP81,			//	46
			MP82,			//	47
			MP83,			//	48
		};

		template<typename Z>
		struct ZArrayIterator
		{
		private:
			__int32 _next;		//	might be start	??
			__int32 _prev;		//	first object in the array will point to the start.
			__int32 _data;		//	Z

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
			__int32 _count;
			__int32 _begin;
			__int32 _end;

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
			ZArrayIterator<Z> GetIterator() const
			{
				return PS2Memory::ReadEE<ZArrayIterator<Z>>(_begin);
			}

			std::vector<Z> Data() const
			{
				std::vector<Z> result;

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