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
	namespace SOCOM2
	{

		namespace Offsets
		{
			///	POINTERS
			//static const unsigned __int32 o_LocalSeal{ 0x44D648 };						//
			static const unsigned __int32 p_EntityArray{ 0x442CEC };					//
			static const unsigned __int32 p_WeaponPTR{ 0x4B8A60 };						//	

			/// VISUALS
			static const unsigned __int32 RenderFix{ 0x35A2F8 };						//	On = || Default = 
			static const unsigned __int32 RenderFix2{ 0x35A320 };						//	On = 00000000 || Default = 0x0C0D64C8 (202204360)
			static const unsigned __int32 NVGFilter{ 0x2169D8 };						//	On = 0 || Default = 0x0C065DD0 (201743824)
			static const unsigned __int32 fps1{ 0x40C638 };								//	On = || Default = 
			static const unsigned __int32 fps2{ 0x40C640 };								//	On = || Default = 
			static const unsigned __int32 Fog{ 0x4093D0 };								//	
			static const unsigned __int32 MapBrightness1{ 0x4B858C };					//	0x4B4D4C;
			static const unsigned __int32 MapBrightness2{ 0x4B859C };					//	0x4B4D5C;
			static const unsigned __int32 MapBrightness3{ 0x4B85AC };					//	0x4B4D6C;
			static const unsigned __int32 widescreen1{ 0x4A1DB0 };						//	On = || Default = 0x3F800000 (1)
			static const unsigned __int32 widescreen2{ 0x4A1DC0 };						//	On = || Default = 0x44D80000 (1728.0)
			static const unsigned __int32 widescreen3{ 0x4A1DC4 };						//	On = || Default = 0x44E40000 (1824.0)
			static const unsigned __int32 widescreen4{ 0x4A7CEC };						//	On = || Default = 0x3F800000 (1)
			static const unsigned __int32 CompassX{ 0x407688 };							//	On = || Default = 0x440D4000 (565.0)
			static const unsigned __int32 CompassY{ 0x40768C };							//	On = || Default = 0x42C80000 (100.0)
			static const unsigned __int32 crosshairR{ 0x407720 };						//	HEX Float
			static const unsigned __int32 crosshairG{ 0x407728 };						//	Hex Float
			static const unsigned __int32 crosshairB{ 0x407730 };						//	Hex Float
			static const unsigned __int32 playerEntityBrightness{ 0x40C6C0 };			//	

			///	MATCH DATA
			static const unsigned __int32 ForceStart{ 0x408868 };						//	0x0027E2B0  | DEFAULT: 0x0027DD00
			static const unsigned __int32 MatchTimer{ 0xC2E614 };						//	DEFAULT = 00124F80
			static const unsigned __int32 ROOM_NAME_ADDRESS{ 0x1FFBBE0 };				//	
			static const unsigned __int32 GAME_ENDED_ADDRESS{ 0x694C44 };				//	May need to reset this to 0 after it ends, it seems to persist till the next game and doesn't reset when the player loads i
			static const unsigned __int32 CURRENT_MAP_ADDRESS{ 0x4417C0 };				//	Text String of MapID, if not in a game then it is set to NONE
			static const unsigned __int32 SEAL_WIN_COUNTER_ADDRESS{ 0x695388 };			//
			static const unsigned __int32 TERRORIST_WIN_COUNTER_ADDRESS{ 0x69539C };	//

			//	CHEATS
			static const unsigned __int32 decAmmoCount{ 0x5C6288 };						//	
			static const unsigned __int32 decEquipmentCount{ 0x5C94B4 };				//	
			static const unsigned __int32 PerfectWeapon{ 0x5C5E20 };					//	
			static const unsigned __int32 RapidFire{ 0x5C81CC };						//	
			static const unsigned __int32 AimAssistBox{ 0x2175E8 };						//	
			static const unsigned __int32 wpnSpread{ 0x5BD4E4 };						//	
			static const unsigned __int32 wpnSpread2{ 0x5C2A0C };						//	
			static const unsigned __int32 wpnSpread3{ 0x5C36C4 };						//	
			static const unsigned __int32 wpnRecoil{ 0x5BF238 };						//	
			static const unsigned __int32 AimAssistBool{ 0x40A370 };					//	
			static const unsigned __int32 TargetLockDistance{ 0x5B0FF8 };				//	
			//static const unsigned __int32 ForceLaunch{ 0x408868 };						//	On = 0027E280 || Default = 0027DD00

			//	FUNCTIONS
			static const unsigned __int32 fnRegisterShotOnTarget{ 0x5AB5F0 };			//	
		}

		namespace Patches
		{
			static const Patch RFix(Offsets::RenderFix, 0x100000DB, 0x106000DB);
			static const Patch ForceMatch{ Offsets::ForceStart, 0x0027E280,  0x0027DD00 };
			static const Patch EndlessMatch{ Offsets::MatchTimer, 0xFFFFFFFF,  0x00124F80 };
			static const Patch NoFog{ Offsets::Fog, 0x0, 0x1 };
		}


		/* */

		class CNode
		{
		public:
			Mat4x4 mMatrix; //0x0000
			AABB mAABB; //0x0040
			char pad_0058[8]; //0x0058
			i32_t vfTable; //0x0060
			i32_t pParent; //0x0064	CNode*
			char pad_0068[40]; //0x0068
			i32_t pName; //0x0090
			i32_t pNodeEx; //0x0094	CNodeEx*
			char pad_0098[4]; //0x0098
			float mOpacity; //0x009C
			char pad_00A0[4]; //0x00A0
			int32_t mTickCount; //0x00A4
			char pad_00A8[12]; //0x00A8
			i32_t pModel; //0x00B4	CModel*
			i32_t pModelName; //0x00B8

		public:
			std::string GetName();
			CNode* GetParent();
			class CNodeEx* GetNodeExObject();
			class CModel* GetModelObject();
			class CEntity* GetEntityObject();
			bool IsVisible();
			void SetVisibility(float opacity);
			Vec3 GetWorldPos() const;
			void SetWorldPos(const Vec3& newPos);
			Mat4x4 GetWorldTM();
			void SetWorldTM(const Mat4x4& newTM);
			AABB GetLocalBounds() const;
			AABB GetWorldBounds() const;
			Vec3 GetRightVector() const;
			Vec3 GetUpVector() const;
			Vec3 GetForwardVector() const;
			float GetYawAngleRadians() const;
			float GetYawAngleDegrees() const;
		}; //Size: 0x00BC

		class CNodeEx
		{
		public:
			i32_t vfTable; //0x0000
			i32_t pEntity; //0x0004	CEntity*

		public:
			class CEntity* GetEntity();
		}; //Size: 0x0008

		class CAppCamera
		{
		private:
			i32_t vfTable; //0x0000
			char pad_0004[176]; //0x0004
			i32_t pCamera; //0x00B4	CZCamera*
			i32_t pNode; //0x00B8	CNode*
			i32_t pAttachedEntity; //0x00BC	CEntity*
			char pad_00C0[8]; //0x00C0
			i32_t pBodypart; //0x00C8	CZBodyPart*
			char pad_00CC[44]; //0x00CC

		public:
			static CAppCamera* GetDefaultInstance();
			bool IsValid();
			class CZCamera* GetCameraObject();
			CNode* GetNodeObject();
			class CEntity* GetAttachedEntity();
			class CZBodyPart* GetBodyPartObject();
			void SetAttachedEntity(CEntity* pEntity);
		}; //Size: 0x00F8

		class CTarget
		{
		public:
			i32_t pEntity; //0x0000	CEntity*
			Vec3 mOrigin; //0x0004
			float mDistanceSq; //0x0010
			float mDistance; //0x0014
			float mVisiblity; //0x0018
			float mAware; //0x001C : is -2.f if local player is not visible from the targets POV (eyes , not camera)
			int32_t mDiHandle; //0x0020
			char pad_0024[8]; //0x0024
			uint32_t mTargetBits; //0x002C

		public:
			class CEntity* GetEntity();
			bool GetOrigin(Vec3* out);
			float GetDistance() const;
			bool IsVisible() const;
			bool WasRecentlyVisible() const;
		}; //Size: 0x0030

		class CEntity
		{
		public:
			i32_t vfTable; //0x0000
			char pad_0004[12]; //0x0004
			Enums::EENTITY_TYPE mEntityType; //0x0010
			char pad_0011[3];//0x0011
			i32_t pName; //0x0014
			int32_t mUnitsSeenBy; //0x0018
			Vec3 mOrigin; //0x001C
			i32_t pNode; //0x0028	CNode*
			Vec3 mVel_M; //0x002C
			Vec3 mVel_W; //0x0038
			Vec3 mVel_R; //0x0044
			Vec4 mQuat; //0x0050
			Vec3 mNextVel_W; //0x0060
			char pad_006C[4]; //0x006C
			Vec4 mNextQuat; //0x0070
			Mat4x4 mMatrix; //0x0080
			i32_t pSealCtrl; //0x00C0	CZSealCtrl*
			char pad_00C4[4]; //0x00C4
			Enums::ESEAL_TEAMS mTeamID; //0x00C8
			float mMaxTargetRange; //0x00CC
			int32_t mMaxTargetCount; //0x00D0
			int32_t mTargetCount; //0x00D4
			i32_t pTargetArray; //0x00D8 CTarget*
			char pad_00DC[4]; //0x00DC
			uint32_t mEntityBits; //0x00E0
			char pad_00E4[284]; //0x00E4

		public:
			bool IsValid();
			Enums::EENTITY_TYPE GetEntityType();
			Vec3 GetOrigin();
			Mat4x4 GetTM();
			Enums::ESEAL_TEAMS GetTeamID();
			std::string GetName();
			bool GetTargets(std::vector<CTarget*> out);
			CNode* GetNodeObject();

			/* */
			bool GetWorldTM(Mat4x4* out);
			bool SetWorldPos(const Vec3& newPos);
			bool GetWorldPos(Vec3* out);
			bool GetLocalBounds(AABB* out);
			bool GetWorldBounds(AABB* out);
			bool GetForwardVector(Vec3* out);
			bool GetRightVector(Vec3* out);
			bool GetUpVector(Vec3* out);

			/* */
			float GetAngleDegrees();
			float GetAngleRadians();


		}; //Size: 0x0200

		class CZCamera
		{
		private:
			Mat4x4 mMatrix; //0x0000
			Vec3 mFogColor; //0x0040
			float mFOV_h; //0x004C
			float mFOV_v; //0x0050
			char pad_0054[236]; //0x0054
			float mZMin; //0x0140
			float mZMax; //0x0144
			float mZScale; //0x0148
			char pad_014C[4]; //0x014C
			Vec3 mFrustrum[3]; //0x0150
			Vec3 mFullFrustrum[6]; //0x0174
			int32_t mFullFrustrumPoints; //0x01BC
			Vec2 mSin; //0x01C0
			Vec2 mCos; //0x01C8
			Vec2 mTan; //0x01D0
			Vec2 mCot; //0x01D8
			char pad_01E0[272]; //0x01E0
			Mat4x4 mtxWorldToView; //0x02F0
			Mat4x4 mtxWorldToClip; //0x0330
			Mat4x4 mtxViewToClip; //0x0370
			Mat4x4 mtxViewToScreen; //0x03B0
			char pad_03F0[16]; //0x03F0
			Mat4x4 N00001225; //0x0400
			Mat4x4 N000012CF; //0x0440

		public:
			static CZCamera* GetDefaultInstance();
			bool IsValid();
			Mat4x4 GetWorldTM();
			Mat4x4 GetWorldToViewMatrix();
			Mat4x4 GetWorldToClipMatrix();
			Mat4x4 GetViewToClipMatrix();
			Mat4x4 GetViewToScreenMatrix();
			Vec3 GetOrigin();
			Vec3 GetFogColor();
			float GetFOV_h();
			float GetFOV_v();
			bool WorldToScreen(const Vec3& worldOrigin, const Vec2& szScreen, Vec2* screen2D);
		}; //Size: 0x0480

		class CZBodyPart
		{
		private:
			Vec3 mOrigin; //0x0000
			i32_t pNode; //0x000C	CNode*
			Vec3 mNextOrigin; //0x0010
			i32_t pParent; //0x001C	CZBodyPart*
			Vec4 mQuat; //0x0020
			Vec4 mNextQuat; //0x0030

		public:
			Vec3 GetOrigin() const;
			CNode* GetNode();
			CZBodyPart* GetParent();
			std::string GetName();
			bool GetLocalTM(Mat4x4* out);
			Vec3 GetLocalOrigin() const;
			Vec4 GetLocalRotation() const;
			bool GetWorldTM(const Mat4x4& model, Mat4x4* out);	// multiply by parent model to get world transform relative to model
		}; //Size: 0x0040

		class CZSealBody : public CEntity
		{
		public:
			int8_t mZoomIndex; //0x0200
			int8_t mLastZoomIndex; //0x0201
			char pad_0202[2]; //0x0202
			float mZoomModifier; //0x0204
			char pad_0208[224]; //0x0208
			i32_t mSkeleton[32]; //0x02E8	CZBodyPart*
			char pad_0368[12]; //0x0368
			Enums::ESEAL_STANCE mStance; //0x0374
			Enums::ESEAL_LEAN mLean; //0x0375
			char pad_0376[2]; //0x0376
			float mShoulderRecoil; //0x0378
			char pad_037C[68]; //0x037C
			Vec3 mAimWorldPos; //0x03C0
			char pad_03CC[4]; //0x03CC
			Vec3 mAimWorldAngles; //0x03D0
			char pad_03DC[68]; //0x03DC
			float mLifetime; //0x0420
			char pad_0424[184]; //0x0424
			Vec3 mRelativeRotation; //0x04DC
			char pad_04E8[60]; //0x04E8
			float mTimeSinceLastAnimation; //0x0524
			i32_t pAnimationSet; //0x0528	CAnimation*
			char pad_052C[8]; //0x052C
			int32_t mAnimationType; //0x0534	Ninja Jump State = 0x12B0140
			char pad_0538[84]; //0x0538
			int8_t mHeadshots; //0x058C
			char pad_058D[3]; //0x058D
			int8_t mShotsHit; //0x0590
			char pad_0591[3]; //0x0591
			int8_t mShotsFired; //0x0594
			char pad_0595[1]; //0x0595
			int8_t mWasFiredAt; //0x0596
			char pad_0597[5]; //0x0597
			int8_t mWasHit; //0x059C
			char pad_059D[1]; //0x059D
			int8_t mDeaths; //0x059E
			char pad_059F[23]; //0x059F
			int8_t mEquipmentUsed; //0x05B6
			char pad_05B7[1]; //0x05B7
			int8_t mCqCTakedowns; //0x05B8
			char pad_05B9[1]; //0x05B9
			int8_t mPrimaryShotsFired; //0x05BA
			char pad_05BB[1]; //0x05BB
			int8_t mSecondaryShotsFired; //0x05BC
			char pad_05BD[67]; //0x05BD
			Vec2 mRecoilPunch; //0x0600
			Vec2 mPrevRecoilPunch; //0x0608
			char pad_0610[8]; //0x0610
			Vec3 mRifleKick; //0x0618
			int32_t mFireRilfeKickState; //0x0624
			int32_t mHeartbeatState; //0x0628
			Vec2 mHeartbeat; //0x062C
			int32_t mCurItemReticule; //0x0634
			Vec2 mScreenOffset; //0x0638
			char pad_0640[132]; //0x0640
			i32_t pWeapons[10]; //0x06C4	CZWeapon*
			char pad_06EC[80]; //0x06EC
			i32_t pAmmoTypes[10]; //0x073C	CZAmmo*
			char pad_0764[120]; //0x0764
			int32_t mPrimaryMags[10]; //0x07DC
			int32_t mSecondaryMags[10]; //0x0804
			int32_t mEqSlot1Ammo; //0x082C
			char pad_0830[36]; //0x0830
			int32_t mEqSlot2Ammo; //0x0854
			char pad_0858[36]; //0x0858
			int32_t mEqSlot3Ammo; //0x087C
			char pad_0880[996]; //0x0880
			int32_t mPrimaryMagIndex; //0x0C64
			int32_t mSecondaryMagIndex; //0x0C68
			char pad_0C6C[112]; //0x0C6C
			int32_t mWeaponFireTypes[2]; //0x0CDC
			char pad_0CE4[276]; //0x0CE4
			int32_t mWeaponFireCount; //0x0DF8
			float mWeaponFireDelta; //0x0DFC
			char pad_0E00[4]; //0x0E00
			int32_t mCurrentWeaponIndex; //0x0E04
			char pad_0E08[4]; //0x0E08
			int32_t mMaxWeaponIndex; //0x0E0C
			i32_t pEntity; //0x0E10	CEntity*
			char pad_0E14[152]; //0x0E14
			i32_t pCarry; //0x0EAC	CEntity*
			char pad_0EB0[168]; //0x0EB0
			float mElevation; //0x0F58
			char pad_0F5C[232]; //0x0F5C
			float mHealth; //0x1044
			char pad_1048[1016]; //0x1048
			Vec3 mAimDir; //0x1440
			Vec3 mAimGoal; //0x144C
			Vec3 mAimPoint; //0x1458
			Vec3 mReticlePt; //0x1464
			Vec3 mAimNorm; //0x1470
			Vec3 mPrevAimPoint; //0x147C
			Vec3 mPrevAimNorm; //0x1488
			Vec3 mPrevReticlePt; //0x1494
			Vec3 mCurrAimPos; //0x14A0
			int32_t N000007EA; //0x14AC
			Vec3 mCurFirePos; //0x14B0
			int32_t N000007EC; //0x14BC
			Vec3 mSkeletonRoot; //0x14C0

		
		public:
			static CZSealBody* GetDefaultInstance();
			bool IsValidSeal();
			float GetHealth();
			bool IsAlive();
			Enums::ESEAL_STANCE GetStance();
			bool GetBoneByIndex(const int& boneIndex, CZBodyPart** out);
			bool GetBoneWorldTM(const int& boneIndex, Mat4x4* out);
			bool GetBoneLocationByIndex(const int& boneIndex, Vec3& outPosition);
			void SetAimPoint(const Vec3& newAim);
			bool SetAimTarget(CZSealBody* pTarget, bool bVisible = false, const Enums::ESEALBONES_INDEX& bone = Enums::ESEALBONES_head);
			bool SetAimTarget(const Vec3& location);
			CTarget* GetTargetEntity(CZSealBody* pTarget); // returns pointer to target struct if the passed entity is within the target array
		}; //Size: 0x1390

		/* */


		class CZWorld
		{
		private:
		public:
		};

		class CCamera
		{
		private:
			char								pad_0000[80];	//0x0000
			Vec3								Position;		//0x0050
			unsigned int						m_viewType;				//0x005C	//	0 = normal view : 2+ = zoom of sorts

		public:
			std::string LogData();

		public:
			CCamera* GetDefaultInstance();
		
			Vec3 GetPosition();
		};

		class CZSealObject
		{
		private:
			char								pad_0000[48];	//0x0000
			Vec3								m_absPosition;	//0x0030
			//	char								pad_003C[96];	//0x003C
			//	float								m_selfVisible;	//0x009C	//	255 = visible : 0 = invisible

		public:
			static CZSealObject*				GetDefaultInstance();
			Vec3								GetPosition();
			void								SetPosition(Vec3 in);

		};	//Size: 0x0100

		class CZSeal
		{
		public:
			i32_t								vfTable;					//0x0000	//	0x668B20
			char								pad_0004[12];				//0x0004
			__int32								m_ID;						//0x0010
			__int32								m_pName;					//0x0014
			char								pad_0018[4];				//0x0018
			Vec3								m_relativeLocation;			//0x001C
			unsigned __int32					m_pSealObj;					//0x0028		
			char								pad_002C[40];				//0x002C
			Vec3								rotation;					//0x0054 // x = right, z = left
			//	float								LookSpeedRight;				//0x0054
			//	char								pad_0058[4];				//0x0058
			//	float								LookSpeedLeft;				//0x005C
			char								pad_0060[60];				//0x0060
			float								m_sealAlpha;				//0x009C
			char								pad_00A0[28];				//0x00A0
			float								m_mapPos;					//0x00BC
			char								pad_00C0[8];				//0x00C0
			ETeam								m_teamID;					//0x00C8
			char								pad_00CC[20];				//0x00CC
			int									DeadOrAlive;				//0x00E0
			//char								pad_00E4[828];				//0x00E4
			char								pad_00E4[284];				//0x00E4
			__int32								m_CameraViewType;			//0x0200
			float								m_ZoomLevel;				//0x0204
			char								pad_0208[536];				//0x0208
			float								m_GameTime;					//0x0420
			char								pad_0424[256];				//0x0424
			float								m_TimeSinceLastAnimation;	//0x0524
			__int32								m_AnimationSet1;			//0x0528
			__int32								m_AnimationSet2;			//0x052C
			__int32								m_AnimationSet3;			//0x0530
			__int32								m_CurrentAnimation;			//0x0534
			char								pad_0538[8];				//0x0538
			__int32								m_UIChartType;				//0x0540
			char								pad_0544[76];				//0x0544
			__int32								m_shotsHit;					//0x0590
			__int32								m_shotsFired;				//0x0594
			__int32								m_totalKills;				//0x0598
			//	char								pad_059C[296];				//0x059C	//	BEGIN NEW
			char								pad_059C[60];				//0x059C
			Vec2								m_recoilParams;				//0x05D8
			char								pad_05E0[36];				//0x05E0
			float								m_Recoil;					//0x0604
			Vec2								m_scopeSwayParams;			//0x0608
			char								pad_0610[12];				//0x0610
			Vec2								m_scopeRecoilParams;		//0x061C
			char								pad_0624[160];				//0x0624	//	END NEW
			EWeapon								m_PrimaryWeapon;			//0x06C4
			EWeapon								m_SecondaryWeapon;			//0x06C8
			EWeapon								m_EqSlot1;					//0x06CC
			EWeapon								m_EqSlot2;					//0x06D0
			EWeapon								m_EqSlot3;					//0x06D4
			char								pad_06D8[100];				//0x06D8
			__int32								m_PrimaryAmmoType;			//0x073C
			__int32								m_SecondaryAmmoType;		//0x0740
			__int32								m_EqSlot1AmmoType;			//0x0744
			__int32								m_EqSlot2AmmoType;			//0x0748
			__int32								m_EqSlot3AmmoType;			//0x074C
			char								pad_0750[100];				//0x0750
			__int32								m_PrimaryMags[10];			//0x07B4
			__int32								m_SecondaryMags[10];		//0x07DC
			__int32								m_EqSlot1Ammo;				//0x0804
			char								pad_0808[36];				//0x0808
			__int32								m_EqSlot2Ammo;				//0x082C
			char								pad_0830[36];				//0x0830
			__int32								m_EqSlot3Ammo;				//0x0854
			char								pad_0858[1156];				//0x0858
			//char									pad_0858[28];			//0x0858
			//int									EQSlot2Mag;				//0x0874
			//char									pad_0878[36];			//0x0878
			//int									EQSlot3Mag;				//0x089C
			//char									pad_08A0[1084];			//0x08A0
			__int32								m_PrimaryFireType;			//0x0CDC
			__int32								m_SecondaryFireType;		//0x0CE0
			char								pad_0CE4[276];				//0x0CE4
			__int32								m_isTriggerPressed;			//0x0DF8
			__int32								m_fireCooldown;				//0x0DFC
			char								pad_0E00[44];				//0x0E00
			Vec2								m_xhairSpreadParams;		//0x0E2C
			//	float								m_xhairSpread;				//0x0E2C
			//	float								m_xhairBloom;				//0x0E30
			char								pad_0E34[84];				//0x0E34
			unsigned __int32					m_pObjectAtCrosshair;		//0x0E88
			//	char								m_pad_0E8C[308];			//0x0E8C
			char								pad_0E8C[232];				//0x0E8C
			int									m_GunHot_unk;				//0x0F74
			char								pad_0F78[72];				//0x0F78
			__int32								m_causeOfDeathWeaponID;		//0x0FC0
			char								pad_0FC4[8];				//0x0FC4
			__int32								m_respawn;					//0x0FCC
			char								pad_0FD0[116];				//0x0FD0
			float								m_health;					//0x1044
			char								pad_1048[4];				//0x1048
			__int32								m_shock;					//0x104C
			char								pad_1050[12];				//0x1050
			__int32								m_fallDamage;				//0x105C
			char								pad_1060[260];				//0x1060
			__int32								m_gunHot1;					//0x1164
			char								pad_1168[4];				//0x1168
			__int32								m_gunHot2;					//0x116C
			char								pad_1170[504];				//0x1170
			__int32								m_jumpHeight;				//0x1368

		public:
			static CZSeal*						GetDefaultInstance();
		
		public:
			bool								IsValid();
			CZSealObject*						GetSealObject();
			Vec3								GetPosition();
			Vec2								GetRotation();
			std::string							GetName();
			ETeam								GetTeam();
			float								GetHealth();
			bool								IsAlive();
			void								ChangeTeams(ETeam newTeamID);
			CZKit								GetKit();
			void								UpdateKit(CZKit newKit);
		};	//Size: 0x136C

		class CZWeapon
		{
		private:
			/*

				- Core
				-- GiveAmmo
				-- GiveWeapon
				-- GetLoadoutData | Primary, Secondary, Equipment & Ammo

				- Systems
				-- Weapon Manager | Slot -> Type -> Weapon : Send

			*/

		public:
			int32_t vfTable; //0x0000	vTable
			int32_t pName; //0x0004	char*
			int32_t pDisplayName; //0x0008	char*
			int32_t pTextureName; //0x000C	char*
			char pad_0010[4]; //0x0010
			int32_t pIconName; //0x0014	char*
			int32_t pGearName; //0x0018	char*
			int32_t pModelName; //0x001C	char*
			int32_t pBulletImpactName; //0x0020	char*
			Enums::EWEAPON_FIREMODE mMaxFireMode; //0x0024
			int32_t szMag; //0x0028
			int32_t defaultMags; //0x002C
			float mSoundRadius; //0x0030
			float mSoundRadiusSq; //0x0034
			Enums::EWEAPON_ENCUMBRANCE Encumbrance; //0x0038
			char pad_0039[3]; //0x0039
			float mMaxRange; //0x003C
			float mEffectiveRange; //0x0040
			float mMuzzleVelocity; //0x0044
			float mImpactRadius; //0x0048
			char pad_004C[4]; //0x004C
			float mFireWaitTime; //0x0050
			float mReloadTime; //0x0054
			char pad_0058[12]; //0x0058
			float mDamageModifier; //0x0064
			char pad_0068[20]; //0x0068
			int32_t mID; //0x007C
			char pad_0080[28]; //0x0080
			int32_t pName_ReloadAnim; //0x009C	char*
			char pad_00A0[4]; //0x00A0
			int32_t N000000DB; //0x00A4	char*
			int32_t pName_HitAnim; //0x00A8	char*
			int32_t pName_FireAnim; //0x00AC	char*
			int32_t pName_ZoomAnim; //0x00B0	char*
			int32_t pName_DefaultSpecialAnim; //0x00B4	char*
			char pad_00B8[12]; //0x00B8
			ZArray<class CZAmmo*> mLegalAmmoList; //0x00C4
			bool bHasFireMode[4]; //0x00D0
			char pad_00D4[36]; //0x00D4
			float mBloom; //0x00F8
			float mRecoilResetDelay; //0x00FC
			float mRecoil; //0x0100
			char pad_0104[44]; //0x0104
			float mBloomResetTimer; //0x0130
			char pad_0134[348]; //0x0134

		public:	//	static methods
			static CZWeapon*					GetDefaultInstance();

		public:	//	instance methods
			Vec3								GetBulletPos();
			void								SetBulletPos(Vec3 Pos);
		};	//Size:	0x0290

		class CZAmmo
		{
		public:
			i32_t pName; //0x0000	char*
			i32_t pDisplayName; //0x0004	char*
			i32_t pName2; //0x0008	char*
			float mImpactDmg; //0x000C
			float mStun; //0x0010
			float mPiercing; //0x0014
			float mExplosionDmg; //0x0018
			float mExplosionRadius; //0x001C
			char pad_0020[16]; //0x0020
			int32_t mID; //0x0030
			char pad_0034[28]; //0x0034

		}; //Size: 0x0048

		class ZListWeapons
		{
		public:
			class CZWeapon mList1[5]; //0x0000
			char pad_0CD0[32]; //0x0CD0
			class CZWeapon mList2[6]; //0x0CF0
			char pad_1C50[32]; //0x1C50
			class CZWeapon mList3[43]; //0x1C70
			char pad_8AA0[32]; //0x8AA0
			class CZWeapon mList4[25]; //0x8AC0
			char pad_CAD0[64]; //0xCAD0
			class CZWeapon mList5[7]; //0xCB10
		}; //Size: 0xDD00

		class CZMatchData
		{		
			/*
			* 
				NOTES
				Host
				- Force Start
				- 
				Match Info
				- Map
				- Round
				- Time
				- Players
				- Score
				- ForceHost
				- ForceStartMatch
				- ForceEndMatch
				- MatchNeverEnds
				- PlayerArray
				- GetLobbyInfo	| RoomName, MapName, Mode, #Players(Organized by team), Rounds Won/Current Round/Timer
			*/ 
		public:	//	OFFSETS
			const char*							roomName;
			const char*							currentMap;
			float								matchTime;
			int32_t								num_players;
			int32_t								num_alivePlayers;
			int32_t								num_spectators;
			int32_t								num_ai;
			int32_t								num_teams;
			int32_t								num_currentRound;
			CZSeal*								Host;
			CZSeal*								localPlayer;

		public: //	FUNCTIONS
			//bool isMatchEnded()
			//{
			//	Offsets offset;
			//	return (PS2Read<int>(offset.GameEndAddress) == NULL) ? TRUE : FALSE;
			//}
			static void							ForceStartMatch(bool bActive);
			static void							SetEndlessMatch(bool bActive);
			static bool							GetEntities(std::vector<CZSealBody*>* entities);
			//	static bool							GetPlayers(std::vector<CZSealBody*>* players);
			//	static std::vector<class CZSealBody*>	GetAlivePlayers();
			static void							EndCurrentRound();
			static std::vector<class CZSeal*>	GetPlayers();
			static bool							GetPlayers(std::vector<class CZSeal*>* out);
			static std::vector<class CZSeal*>	GetAlivePlayers();
			static std::string					LogData();
		};

		/*
		* 
			class Offsets_
			{
				//	RAW OFFSETS
			public:
				/// <summary>
				int p_Player				= 0x44D648;	//
				int p_EntityArray			= 0x442CEC;	//
				int p_WeaponPTR				= 0x4B8A60;	//	

				/// <summary>
				int RenderFix				= 0x35A2F8;	//	On = || Default = 
				int RenderFix2				= 0x35A320;	//	On = 00000000 || Default = 0x0C0D64C8 (202204360)
				int NVGFilter				= 0x2169D8;	//	On = 0 || Default = 0x0C065DD0 (201743824)
				int fps1					= 0x40C638;	//	On = || Default = 
				int fps2					= 0x40C640;	//	On = || Default = 
				int Fog						= 0x4093D0;
				int MapBrightness1			= 0x4B858C;	//0x4B4D4C;
				int MapBrightness2			= 0x4B859C;	//0x4B4D5C;
				int MapBrightness3			= 0x4B85AC;	//0x4B4D6C;
				int widescreen1				= 0x4A1DB0;	//	On = || Default = 0x3F800000 (1)
				int widescreen2				= 0x4A1DC0;	//	On = || Default = 0x44D80000 (1728.0)
				int widescreen3				= 0x4A1DC4;	//	On = || Default = 0x44E40000 (1824.0)
				int widescreen4				= 0x4A7CEC;	//	On = || Default = 0x3F800000 (1)
				int CompassX				= 0x407688;	//	On = || Default = 0x440D4000 (565.0)
				int CompassY				= 0x40768C;	//	On = || Default = 0x42C80000 (100.0)
				int crosshairR				= 0x407720;	//	HEX Float
				int crosshairG				= 0x407728;	//	Hex Float
				int crosshairB				= 0x407730;	//	Hex Float
				int playerEntityBrightness	= 0x40C6C0;

				///	<MatchData>
				int	ForceStart				= 0x408868;	//	0x0027E2B0  | DEFAULT: 0x0027DD00
				int MatchTimer				= 0xC2E614;	//	DEFAULT = 00124F80
				int ROOM_NAME_ADDRESS		= 0x1FFBBE0;
				int GAME_ENDED_ADDRESS		= 0x694C44;		// May need to reset this to 0 after it ends, it seems to persist till the next game and doesn't reset when the player loads i
				int CURRENT_MAP_ADDRESS		= 0x4417C0;		// Text String of MapID, if not in a game then it is set to NONE
				int SEAL_WIN_COUNTER_ADDRESS = 0x695388;
				int TERRORIST_WIN_COUNTER_ADDRESS =  0x69539C;

				//	CHEATS
				int decAmmoCount			= 0x5C6288;
				int decEquipmentCount		= 0x5C94B4;
				int PerfectWeapon			= 0x5C5E20;
				int RapidFire				= 0x5C81CC;
				int AimAssistBox			= 0x2175E8;
				int wpnSpread				= 0x5BD4E4;
				int wpnSpread2				= 0x5C2A0C;
				int wpnSpread3				= 0x5C36C4;
				int wpnRecoil				= 0x5BF238;
				int AimAssistBool			= 0x40A370;
				int TargetLockDistance		= 0x5B0FF8;
				int ForceLaunch				= 0x408868;	//	On = 0027E280 || Default = 0027DD00

				//	FUNCTIONS
				int fnRegisterShotOnTarget	= 0x5AB5F0;

				std::vector<int> OffsetArray = {
					//	Pointers
					0x44D648,		//	PlayerPointer
					0x442CEC,		//	EntityArrayPointer
					0x4B8A60,		//	WeaponPointer

					//	Environment
					0x35A2F8,		//	RenderFix1 
					0x35A320,		//	RenderFix2
					0x2169D8,		//	NVG
					0x40C638,		//	FPS
					0x40C640,		//	FPS2
					0x4093D0,		//	FOG
					0x4B858C,		//	MapBrightness1;
					0x4B859C,		//	MapBrightness2;
					0x4B85AC,		//	MapBrightness3;

					0x4A1DB0,		//	WideScreen(0)
					0x4A1DC0,		//	WideScreen(1)
					0x4A1DC4,		//	WideScreen(2)
					0x4A7CEC,		//	WideScreen(3)

					0x407688,		//	Compass(x)
					0x40768C,		//	Compass(y)

					0x407720,		//	Crosshair(r)
					0x407728,		//	Crosshair(g)
					0x407730,		//	Crosshair(b)

					// Cheats
					0x5C6288,		//	decAmmoCount
					0x5C94B4,		//	decEquipmentCount
					0x5C5E20,		//	PerfectWeapon
					0x5C81CC,		//	RapidFire
					0x2175E8,		//	AimAssistBox
					0x40A370,		//	AimAssistBool
					0x5B0FF8,		//	TargetLockDistance
					0x408868,		//	ForceLaunch
				};

				std::vector<std::string> names = {
					"PlayerPointer",
					"EntityArrayPointer",
					"WeaponPointer",
					"RenderFix1",
					"RenderFix2",
					"NVG",
					"FPS",
					"FPS2",
					"FOG",
					"MapBrightness1",
					"MapBrightness2",
					"MapBrightness3",
					"WideScreen(0)",
					"WideScreen(1)",
					"WideScreen(2)",
					"WideScreen(3)",
					"Compass(x)",
					"Compass(y)",
					"Crosshair(r)",
					"Crosshair(g)",
					"Crosshair(b)",
					"decAmmoCount",
					"decEquipmentCount",
					"PerfectWeapon",
					"RapidFire",
					"AimAssistBox",
					"AimAssistBool",
					"TargetLockDistance",
				};
				
			public:	// Auto Resolve List
				uintptr_t SEALPointer		= PS2Memory::GetAddr(p_Player);
				uintptr_t WEAPONPointer     = PS2Memory::GetAddr(p_WeaponPTR);
				uintptr_t EntityArray		= PS2Memory::GetAddr(p_EntityArray);
				uintptr_t FrameRate1		= PS2Memory::GetAddr(fps1);
				uintptr_t FrameRate2		= PS2Memory::GetAddr(fps2);

			public:	//	Functions
				std::string					LogData();
				class CPlayer*				GetSealObject() { return (CPlayer*)SEALPointer; }
				class CWeapon*				GetWeaponObject() {return (CWeapon*)WEAPONPointer; }
				std::vector<class CPlayer*>	GetEntityArray();

			};




			//	@NOTE: deprecated 4/20/24
			class CPlayerPhysics	//	CZSealBody ??
			{
			public:
				Vec3				unkVecA;		//0x0000
				char				pad_000C[4];	//0x000C
				Vec3				unkVecB;		//0x0010
				char				pad_001C[4];	//0x001C
				Vec3				unkVecC;		//0x0020
				char				pad_002C[4];	//0x002C
				Vec3				absPosition;	//0x0030		

			public:
				std::string LogData();
			};
			
			//	@NOTE: deprecated 4/20/24
			class CPlayer
			{
			public:	// NATIVE OFFSETS (DO NOT DISRUPT)
				int					ObjectBase;						//0x0000
				char				pad_0004[16];					//0x0004
				int					NamePTR;						//0x0014
				char				pad_0018[4];					//0x0018
				Vec3				Position;						//0x001C
				CPlayerPhysics*		PlayerMovement;					//0x0028
				char				pad_0030[36];					//0x0030
				Vec3				Rotation;						//0x0054
				char				pad_0060[104];					//0x0060
				int					TeamID;							//0x00C8
				char				pad_00CC[852];					//0x00CC
				float				GameTime;						//0x0420
				char				pad_0424[368];					//0x0424
				int					ShotsFired;						//0x0594
				char				pad_0598[64];					//0x0598
				float				WeaponBounce;					//0x05D8
				float				WeaponSpread;					//0x05DC
				char				pad_05E0[36];					//0x05E0
				float				WeaponRecoil;					//0x0604
				float				ScopeSway;						//0x0608
				float				ScopePulse;						//0x060C
				char				pad_0610[12];					//0x0610
				float				ScopeBounce;					//0x061C
				float				ScopeRecoil;					//0x0620
				char				pad_0624[160];					//0x0624
				int					PrimaryWeapon;					//0x06C4
				int					SecondaryWeapon;				//0x06C8
				int					Equipment1;						//0x06CC
				int					Equipment2;						//0x06D0
				int					Equipment3;						//0x06D4
				char				pad_06D8[100];					//0x06D8
				int					PrimaryAmmoType;				//0x073C
				int					SecondaryAmmoType;				//0x0740
				int					EquipmentType1;					//0x0744
				int					EquipmentType2;					//0x0748
				int					EquipmentType3;					//0x074C
				char				pad_0750[100];					//0x0750
				int					PrimaryMag[10];					//0x07B4
				int					SecondaryMag[10];				//0x07DC
				int					EquipmentSlot1;					//0x0804
				char				pad_0808[36];					//0x0808
				int					EquipmentSlot2;					//0x082C
				char				pad_0830[36];					//0x0830
				int					EquipmentSlot3;					//0x0854
				char				pad_0858[1440];					//0x0858
				int					weaponAUTO;						//0x0DF8
				int					weaponRAPID;					//0x0DFC
				char				pad_0E00[44];					//0x0E00
				float				CrosshairSpread;				//0x0E2C
				float				CrosshairBloom;					//0x0E30
				char				pad_0E34[320];					//0x0E34
				int					GunHot;							//0x0F74
				char				pad_0F78[204];					//0x0F78
				float				Health;							//0x1044

			public:	//	FUNCTIONS
				bool				IsValid();
				bool				IsAlive();
				CPlayerPhysics*		PlayerPhysicsPtr();
				std::string			GetPlayerName();
				std::string			GetTeamName();
				void				ChangeTeam(unsigned int newTeam);
				std::string			GetWeaponName(unsigned int Weapon);
				std::string			GetAmmoTypeName(unsigned int AmmoType);
				std::string			GetLoadoutInformation();
				void				GiveAmmo(int amount, int mags = {});
				void				GiveWeapon(unsigned int Slot, unsigned int Weapon);
				void				RemoveWeaponsandAmmo();
				void				Teleport(Vec3 Pos);
				std::string			LogData();
				Vec3				GetPosition()				{ return this->Position; }
				void				SetPosition(Vec3 in)		{ this->Position = in; }
				Vec2				GetRotation()				{ return Vec2(this->Rotation.x, this->Rotation.z); }
				void				SetPosition(Vec2 in)		{ Vec2(this->Rotation.x, this->Rotation.z) = in; }
				ETeam				GetTeam()					{ return (ETeam)this->TeamID; }
				float				GetHealth()					{ return (this->Health * 100.f); }
				EPrimaryWeapon		GetPrimaryWeapon()			{ return (EPrimaryWeapon)this->PrimaryWeapon; }
				ESecondaryWeapon	GetSecondaryWeapon()		{ return (ESecondaryWeapon)this->SecondaryWeapon; }
				EEquipment			GetEquipmentItem(char slot = 0);
				void				SetPrimaryWeapon(EPrimaryWeapon weapon)		{ this->PrimaryWeapon = weapon; }
				void				SetSecondaryWeapon(ESecondaryWeapon weapon) { this->SecondaryWeapon = weapon; }
				void				SetEquipment(EEquipment equipment, char slot = 0);
				bool				isFriendly(class CPlayer* otherEnt);

				//	Need to get helper functions to obtain primary ammo type and max ammo counts
				void				RefillPrimaryAmmo();
				void				RefillSecondaryAmmo();
				void				RefillEquipmentAmmo();
			};


			//class Patches : public Offsets
			//{
			//public:
			//	void					SetBrightness(float fLevel);
			//	void					GetBrightnessLevel(float& out);
			//	float					GetBrightnessLevel();
			//	void					ResetBrightness();
			//	void					SetFPS(int iFPS);
			//	void					GetCurrentFPS(int& out);
			//	int						GetCurrentFPS();
			//	void					ResetFPS();
			//	void					SetCrosshairColor();
			//	void					GetCurrentCrosshairColor(Vec3& out);
			//	Vec3					GetCurrentCrosshairColor();
			//	void					ResetCrosshairColor();
			//	void					ToggleAimAssist(bool iValue);
			//	bool					IsAimAssistEnabled();
			//	void					SetCompassPosition(Vector2 in);
			//	void					GetCompassPosition(Vector2& out);
			//	void					DisableEyeAdjustment();
			//	void					RestoreEyeAdjustment();
			//};
		
		*/
	}
}
#pragma pack(pop)