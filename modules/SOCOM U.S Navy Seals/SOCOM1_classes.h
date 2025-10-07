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
		class CNode
		{
		public:
			Mat4x4 mMatrix; //0x0000
			AABB mAABB; //0x0040
			int mType;	//0x0058
			bool m_active : 1;	//0x005C
			bool m_dynamic_motion : 1;
			bool m_dynamic_light : 1;
			bool m_landmark : 1;
			bool m_light : 1;
			bool m_prelight : 1;
			bool m_fog : 1;
			bool m_transparent : 1;
			bool m_facade : 1;
			bool m_reflective : 1;
			bool m_bumpmap : 1;
			bool m_hasDI : 1;
			bool m_region_shift : 1;
			bool m_has_visuals_prior_to_export : 1;
			bool m_shadow : 1;
			bool m_worldchild : 1;
			bool m_char_common : 1;
			bool m_NOTUSED : 1;
			bool m_hasVisuals : 1;
			bool m_hasMesh : 1;
			bool m_scrolling_texture : 1;
			bool m_light_dynamic : 1;
			bool m_light_static : 1;
			bool m_clutter : 1;
			bool m_mtx_is_identity : 1;
			bool m_use_parent_bbox : 1;
			bool m_apply_clip : 1;
			i32_t vfTable; //0x0060 
			i32_t pParent; //0x0064	CNode*
			char pad_0068[40]; //0x0068
			i32_t pName; //0x0090
			i32_t pNodeEx; //0x0094	CNodeEx*
			char mGlobalLighting; //0x0098
			char pad_0099[3]; //0x0099
			float mOpacity; //0x009C
			char pad_00A0[4]; //0x00A0
			int mTickCount; //0x00A4
			char pad_00A8[8]; //0x00A8
			i32_t pModel; //0x00B0	CModel*
			i32_t pModelName; //0x00B4	
			char pad_00B8[8]; //0x00B8

		public:
			CNode* GetParent();
			class CEntity* GetEntity();
			std::string GetName() const;
			Vec3 GetWorldPos() const;
			void SetWorldPos(const Vec3& newPos);
			Mat4x4 GetWorldTM() const;
			void SetWorldTM(const Mat4x4& newTM);
			AABB GetLocalBounds() const;
			AABB GetWorldBounds() const;
			Vec3 GetRightVector() const;
			Vec3 GetUpVector() const;
			Vec3 GetForwardVector() const;
			float GetYawAngleRadians() const;
			float GetYawAngleDegrees() const;
		}; //Size: 0x00B8

		class CNodeEx
		{
		public:
			i32_t vfTable; //0x0000
			i32_t pEntity; //0x0004	CZSealBody*
		};	//Size: 0x0008

		class CWorld : public CNode
		{
		public:
			i32_t pCamera; //0x00B8	CZCamera*
		
		public:
			static CWorld* GetDefaultInstance();
			bool GetViewMatrix(Mat4x4* out);
		};

		class CAppCamera
		{
		private:
			i32_t							vfTable;				//0x0000	
			char							pad_0004[48];			//0x0004
			i32_t							pCamera;				//0x0034	CZCamera*
			i32_t							pTransforms;			//0x0038	CNode*
			i32_t							pAttachedPlayer;		//0x003C	CZSealBody*
			i32_t							pSkeletonRoot;			//0x0040	CZBodyPart*
			char							pad_0044[12];			//0x0044
			Vec3							mOrigin;				//0x0050
			char							mCtrlView;				//0x005C
			char							pad_005D[51];			//0x005D
			char							mSavePeek;				//0x0090
			char							mSaveView;				//0x0091
			bool							bAutoDeathCam;			//0x0092
			bool							bAllowDeathCamControl;	//0x0093
			char							mCamDeathState;			//0x0094

		public:
			static CAppCamera*				GetDefaultInstance();
			class CZCamera*					GetCamera();
			class CZSeal*					GetAttachedPlayer();					//	returns attached player, if any
			void							Reset();							//	sets camera to local player & restores camera position 
			Vec3							GetPosition();
			bool							GetCameraMatrix(FViewModel* out);
			void							SetCamDistance(float dist);
			bool							GetLookVector(Vec3* out);
			bool							GetRightVector(Vec3* out);
			bool							GetUpVector(Vec3* out);
			bool							GetAttachedEntity(class CZSeal* out);
			void							SetAttachedEntity(class CZSeal* pEntity);
			bool							IsAttachedToLocalPlayer();

		};

		class CZCamera
		{
		private:		
			Mat4x4 mModelMatrix; //0x0000
			Vec4 mFogColor; //0x0040
			float mFOV_h; //0x0050
			float mFOV_v; //0x0054
			char pad_0058[232]; //0x0058
			float mZMin; //0x0140
			float mZMax; //0x0144
			float mZScale; //0x0148
			char pad_014C[4]; //0x014C
			Vec3 mFrustrum[3]; //0x0150
			Vec3 mFullFrustrum[6]; //0x0174
			int mFullFrustrumPoints; //0x01BC
			Vec2 mSin; //0x01C0
			Vec2 mCos; //0x01C8
			Vec2 mTan; //0x01D0
			Vec2 mCot; //0x01D8
			char pad_01E0[224]; //0x01E0
			Mat4x4 mtxWorldToView; //0x02C0
			Mat4x4 mtxWorldToClip; //0x0300
			Mat4x4 mtxViewToClip; //0x0340
			Mat4x4 mtxViewToScreen; //0x0380
			__int16 mtxHash; //0x03C0
			char pad_03C2[678]; //0x03C2

		public:
			static CZCamera* GetDefaultInstance();
			bool WorldToScreen(const Vec3& pos, const Vec2& szScreen, Vec2* screen2D);
			float GetFOVTanHalf();
			float GetFOV();
			unsigned __int16 GetViewMtxHash();
		};

		class CZSealObject
		{
		private:
			char							pad_0000[48];	//0x0000
			Vec3							m_absPosition;	//0x0030
			char							pad_003C[96];	//0x003C
			float							m_selfVisible;	//0x009C	//	255 = visible : 0 = invisible

		public:
			static CZSealObject*			GetDefaultInstance();
			Vec3							GetPosition();
			void							SetPosition(Vec3 in);

		};	//Size: 0x0100
		
		class CZSealCtrl
		{
		private:
			i32_t vfTable; //0x0000
			i32_t pEntity; //0x0004	CZSealBody* 
			float mThrottle[3]; //0x0008
			float mLookTimer; //0x0014
			Structs::RFloat mLookRate; //0x0018
			char pad_0020[4]; //0x0020
			Vec3 N00006878; //0x0024
			Vec3 N000035D9; //0x0030
			Vec3 N00006879; //0x003C
			int mLookFlags; //0x0048
			Structs::RFloat mScanAngle; //0x004C
			char pad_0054[284]; //0x0054

		};	//Size: 0x0180

		class CTarget
		{
		public:
			i32_t pEntity; //0x0000 CEntity*
			Vec3 mVec; //0x0004
			float mDistSq; //0x0010
			float mDist; //0x0014
			float mVisibility; //0x0018
			float mAware; //0x001C
			int mDiHandle; //0x0020
			bool m_d_computed : 1;
			bool m_known : 1;
			bool m_visible : 1;
			bool m_hostile : 1;
			bool m_targeted : 1;
			bool m_dirty_di : 1;
			bool m_unused : 2;
			char pad_0025[3]; //0x0025

		public:
			class CZSeal* GetEntity();
			bool WasRecentlyVisible() const;
			bool IsVisible() const;
			bool IsHostile() const;
		}; //Size: 0x0028

		class CZBodyPart
		{
		public:
			Vec3 mOrigin; //0x0000	// tends to be in local coordinates
			i32_t pNode; //0x000C	CNode*
			Vec4 mRotation; //0x0010
			i32_t pParent; //0x0020	CZBodyPart* 
			__int16 mID; //0x0024	
			char pad_0026[2]; //0x0026

		public:
			CZBodyPart* GetParent();
			CNode* GetNode();
			__int16 GetID() const;
			bool GetLocalTM(Mat4x4* out);
			Vec3 GetLocalOrigin() const;
			Vec4 GetLocalRotation() const;
			bool GetWorldTM(const Mat4x4& model, Mat4x4* out);	// multiply by parent model to get world transform relative to model
			std::string GetName();	// returns the name of the body part, if it has one
		};	//Size: 0x0028

		class CZAnim
		{
		public:
			char pad_0000[72]; //0x0000
		}; //Size: 0x0048
		static_assert(sizeof(CZAnim) == 0x48);

		class CSnd
		{
		public:
			i32_t vfTable; //0x0000
			char pad_0004[68]; //0x0004
		}; //Size: 0x0048

		class CPickup
		{
		public:
			float mLifetime; //0x0000
			i32_t pNode; //0x0004	CNode*
			i32_t pData; //0x0008	PickupType*
			Enums::EPICKUP_TYPE mType; //0x000C
			bool bLocked; //0x000D
			bool bSecondary; //0x000E
			char mUnused; //0x000F
			__int16 mID; //0x0010
			__int16 mNetID; //0x0012
			bool bVisibleByUnits; //0x0014

		public:
			CNode* GetPickupObject();
			std::string GetName();
			Vec3 GetWorldPos();
			AABB GetWorldBounds();
			Mat4x4 GetWorldTM();
			Vec3 GetForwardVector();
			Vec3 GetRightVector();
			Vec3 GetUpVector();
			float GetYawAngleDegrees();
		}; //Size: 0x0015

		class CZSeal
		{
		private:
			/* CEntity */
			i32_t vfTable; //0x0000
			char pad_0004[12]; //0x0004
			Enums::EENTITY_TYPE mEntityType; //0x0010
			char pad_0011[3]; //0x0011
			i32_t pName; //0x0014
			char pad_0018[4]; //0x0018
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
			Enums::ESEAL_TEAMS mTeamID; //0x00C4
			float mMaxTargetRange; //0x00C8
			int mMaxTargetCount; //0x00CC
			int mTargetCount; //0x00D0
			i32_t pTargetArray; //0x00D4	CTarget*
			int mAwareCounter; //0x00D8
			bool m_blink_eyes : 1; //0x00DC
			bool m_drip_blood : 1;
			bool m_animate_footsteps : 1;
			bool m_interpolate_animations : 1;
			bool m_lean_into_turns : 1;
			bool m_do_weapon_recoil : 1;
			bool m_check_player_collision : 1;
			bool m_get_new_altitude : 1;
			bool m_noshoot : 1;
			bool m_update_targetlist : 1;
			bool m_include_in_targetlist : 1;
			bool m_isAlive : 1;
			bool m_unused : 4;
			char pad_00E0[130]; //0x00DE

			/* CZSealBody */
			char mZoomIndex; //0x0160
			char mLastZoomIndex; //0x0161
			char pad_0162[2]; //0x0162
			float mZoomModifier; //0x0164
			char pad_0168[260]; //0x0168
			i32_t mSkeleton[33]; //0x026C	CZBodyPart*
			char pad_02F0[20]; //0x02F0
			Enums::ESEAL_STANCE mStance; //0x0304
			Enums::ESEAL_LEAN mLean; //0x0305
			char pad_0306[2]; //0x0306
			float mShoulderRecoil; //0x0308
			char pad_030C[20]; //0x030C
			Vec3 mAimOrigin; //0x0320
			char pad_032C[4]; //0x032C
			Vec3 mAimAngles; //0x0330
			char pad_033C[236]; //0x033C
			Vec3 mRelativeRotation; //0x0428
			char pad_0434[156]; //0x0434
			Structs::SSealStats mSealStats; //0x04D0
			char pad_0522[14]; //0x0522
			Structs::CZKit mKit; //0x0530
			char pad_0DC0[40]; //0x0DC0
			i32_t pCarry; //0x0DE8	CZSealBody*
			char pad_0DEC[220]; //0x0DEC
			float mElevation; //0x0EC8
			char pad_0ECC[4]; //0x0ECC
			float mHealth; //0x0ED0
			char pad_0ED4[80]; //0x0ED4
			Vec2 mHeadHealth; //0x0F24
			Vec2 mBodyHealth; //0x0F2C
			Vec2 mArmHealth_L; //0x0F34
			Vec2 mArmHealth_R; //0x0F3C
			Vec2 mLegHealth_L; //0x0F44
			Vec2 mLegHealth_R; //0x0F4C
			float mArmor[6]; //0x0F54
			char pad_0F6C[24]; //0x0F6C
			bool m_HudUpdateViewCone : 1; //0x0F84
			bool m_hudwashit : 1;
			bool m_aim_point_valid : 1;
			bool m_invincible : 1;
			bool m_invisible : 1;
			bool m_infiniteammo : 1;
			bool m_doPostTick : 1;
			bool m_restrainable : 1;
			char pad_0F85[347]; //0x0F85
			Vec3 mAimDir; //0x10E0
			Vec3 mAimGoal; //0x10EC
			Vec3 mAimPoint; //0x10F8
			Vec3 mReticlePt; //0x1104
			Vec3 mAimNorm; //0x1110
			Vec3 mPrevAimPoint; //0x111C
			Vec3 mPrevAimNorm; //0x1128
			Vec3 mPrevReticlePt; //0x1134
			Vec3 mCurrAimPos; //0x1140
			char pad_114C[4]; //0x114C
			Vec3 mCurFirePos; //0x1150
			char pad_115C[4]; //0x115C
			Vec3 mSkeletonRoot; //0x1160

		public:
			static CZSeal*					GetDefaultInstance();
			bool							IsValid();
			bool							IsPlayerEntity();
			CNode*							GetSealObject();
			Enums::EENTITY_TYPE				GetEntityType() const { return this->mEntityType; }	//	0x0010	/* @TODO: move to cpp */
			Structs::CZKit*					GetKit();
			Vec3							GetPosition();
			float							GetAngleDegrees();
			float							GetAngleRadians();
			bool							SetPosition(Vec3 in);
			std::string						GetName();
			Enums::ESEAL_TEAMS				GetTeam();
			Enums::ESEAL_STANCE				GetStance();
			void							SetTeam(const Enums::ESEAL_TEAMS& newTeam);
			float							GetHealth();
			bool							IsAlive();
			bool							IsVisible(CZSeal* pOther);
			bool							IsFriendly(CZSeal* pOther);
			bool							IsEnemy(CZSeal* pOther);
			bool							IsNonCombatant(CZSeal* pOther);
			bool							IsSpecialEnemy(CZSeal* pOther);
			void							SetInvincible(bool invincible) { this->m_invincible = invincible; }	//	0x0F85
			bool							IsInvincible() { return this->m_invincible; }	//	0x0F85
			void							SetInvisible(bool invisible) { this->m_invisible = invisible; }	//	0x0F85
			bool							IsInvisible() { return this->m_invisible; }	//	0x0F85
			void							SetInfiniteAmmo(bool infinite) { this->m_infiniteammo = infinite; }	//	0x0F85
			bool							IsInfiniteAmmo() { return this->m_infiniteammo; }	//	0x0F85
			bool							GetTargets(std::vector<CTarget*>& outTargets);

			/**/
			bool GetWorldTM(Mat4x4* out);
			bool SetWorldPos(const Vec3& newPos);
			bool GetWorldPos(Vec3* out);
			bool GetLocalBounds(AABB* out);
			bool GetWorldBounds(AABB* out);
			bool GetForwardVector(Vec3* out);
			bool GetRightVector(Vec3* out);
			bool GetUpVector(Vec3* out);

			//
			bool							GetBoneByIndex(int boneIndex, CZBodyPart** out);
			bool							GetBoneWorldTMByIndex(int boneIndex, Mat4x4* out);
			bool							GetBoneLocationByIndex(const int& boneIndex, Vec3& outPosition);
			bool							GetBoundingBox(AABB* outBounds);	//	creates a bounding box around the player, using the skeleton bones
			bool							GetEquippedWeapon(class CZWeapon& outWeapon);
			bool							SetEquippedWeapon(const Enums::EWEAPON& newWeapon);
			bool							SetEquipment(__int32 mPrimary, __int32 mSecondary, __int32 mEq1, __int32 mEq2, __int32 mEq3);
			bool							GetWeapon(const Enums::EWEAPONEQUIP_INDEX& mSlot, class CZWeapon& outWeapon);
			bool							SetWeapon(const Enums::EWEAPONEQUIP_INDEX& mSlot, const Enums::EWEAPON& newWeapon);
			bool							GetAmmoProperties(const Enums::EWEAPONEQUIP_INDEX& mSlot, class CZAmmo& outAmmo);
			bool							SetAmmoProperties(const Enums::EWEAPONEQUIP_INDEX& mSlot, const Enums::EAMMO& newAmmo);
			bool 							GiveWeapon(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newWeaponIndex);
			bool							GiveAmmoType(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newAmmoIndex);
			bool							GiveAmmo(const Enums::EWEAPONEQUIP_INDEX& mSlot, int amount = 0, int mags = 0);
			bool							GiveFireMode(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newFireModeIndex);
			bool							GiveLoadout(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newWeaponIndex, const int& newAmmoIndex, const int& newFireModeIndex, const int& ammo = 0, const int& mags = 0);
			bool							RefreshLoadout();	//	refills munitions for all slots
			void							SetAimPoint(const Vec3& newAim);
			bool							SetAimTarget(CZSeal* pTarget, bool bVisible = false, const Enums::ESEALBONES_INDEX& bone = Enums::ESEALBONES_head);
		};	//Size: 0x1370
		
		class CEntity : public CZSeal
		{
		
		};
		
		class CZSealBody : public CZSeal
		{
		
		};

		class CZWeapon
		{
		public:
			i32_t							vfTable;					//0x0000	//	vfTable
			i32_t							pName;						//0x0004
			i32_t							pDisplayName;				//0x0008
			i32_t							pTextureName;				//0x000C
			i32_t							pIconName;					//0x0010
			i32_t							pGearName;					//0x0014
			i32_t							pModelName;					//0x0018
			i32_t							pBulletImpactName;			//0x001C
			Enums::EWEAPON_FIREMODE			mMaxFireMode;				//0x0020
			__int32							szMag;						//0x0024
			__int32							defaultMags;				//0x0028
			float							mSoundRadius;				//0x002C
			float							mSoundRadiusSq;				//0x0030
			Enums::EWEAPON_ENCUMBRANCE		Encumbrance;				//0x0034
			char							pad_0035[3];				//0x0035
			float							mMaxRange;					//0x0038
			float							mEffectiveRange;			//0x003C
			float							mMuzzleVelocity;			//0x0040
			float							mImpactRadius;				//0x0044
			float							mFireWait;					//0x0048
			float							mReloadTime;				//0x004C
			bool							bReloadAfterShot;			//0x0050
			char pad_0051[3];
			unsigned int mBits; //0x0054
			float mRangeMin; //0x0058
			float mRangeMax; //0x005C
			int mItemID; //0x0060
			i32_t pHitAnim; //0x0064	CZAnim*
			i32_t pFireAnim; //0x0068	CZAnim*
			i32_t pZoomFireAnim; //0x006C	CZAnim*
			i32_t pDefaultSpecialAnim; //0x0070	CZAnim*
			i32_t pSpecialMaterialAnim; //0x0074	CZAnim*
			i32_t pSound_Reload; //0x0078	CSnd*
			i32_t pSoundName_Reload; //0x007C
			i32_t pAnimName_Hit; //0x0080
			i32_t pAnimName_Fire; //0x0084
			i32_t pAnimName_DefaultSpecial; //0x0088
			i32_t pAnimName_SpecialMaterial; //0x008C
			char pad_0090[12]; //0x0090
			ZArray<CZAmmo> mLegalAmmoList; //0x009C
			bool							bHasFireMode[4];			//0x00A8

		public:
			std::string GetName();
		};

		class CZAmmo
		{
		public:
			i32_t							pAmmoName;					//0x0000
			i32_t							pDisplayName;				//0x0004
			float							bulletImpactDmg;			//0x0008
			float							stun;						//0x000C
			float							piercing;					//0x0010
			float							explosionDamage;			//0x0014
			float							explosionRadius;			//0x0018
			char							pad_001C[4];				//0x001C

		public:
			std::string GetName();
		};

		class CZMatchData
		{
			
			
			//	- ForceHost
			//	- ForceStartMatch
			//	- ForceEndMatch
			//	- MatchNeverEnds
			//	- PlayerArray
			//	- GetLobbyInfo	| RoomName, MapName, Mode, #Players(Organized by team), Rounds Won/Current Round/Timer
		
		
			// NOTES
			// Host
			// - Force Start
			// - 
			// Match Info
			// - Map
			// - Round
			// - Time
			// - Players
			// - Score

			// SUB CLASSES
		public:

			//	OFFSETS
		public:
			//	const char*						roomName;
			//	const char*						currentMap;
			//	float							matchTime;
			//	int32_t							num_players;
			//	int32_t							num_alivePlayers;
			//	int32_t							num_spectators;
			//	int32_t							num_ai;
			//	int32_t							num_teams;
			//	int32_t							num_currentRound;
			//	class CZSealBody*				Host;
			//	class CZSealBody*				localPlayer;

			//	FUNCTIONS
		public:
			static bool						isMatchEnded();
			static void						ForceStartMatch();
			static bool						GetEntities(std::vector<CZSeal*>* entities);
			static bool						GetPlayers(std::vector<CZSeal*>* players);
			static std::vector<class CZSeal*>	GetAlivePlayers();
			static bool						GetAllPickups(std::vector<CPickup*>* pickups);
			static bool						GetWeaponPickups(std::vector<CPickup*>* pickups);
			static bool						GetAmmoPickups(std::vector<CPickup*>* pickups);
		};

		///	@TODO:	
		/*

			class CZWeapon
			{

				//	- Core
				//	-- GiveAmmo
				//	-- GiveWeapon
				//	-- GetLoadoutData | Primary, Secondary, Equipment & Ammo
				//	
				//	- Systems
				//	-- Weapon Manager | Slot -> Type -> Weapon : Send



			public:
				EWeaponSlot						e_selectedSlot;
				EPrimaryWeapon					e_selected_Primary;
				ESecondaryWeapon				e_selected_Secondary;
				EEquipment						e_selected_Equipment;

			public:
				Vec3							GetBulletPos();
				void							SetBulletPos(Vec3 Pos);
				void							GiveWeapon();
				void							GiveAmmo();
				void							GetLoadoutData();
				std::string						LogData();
			};

			class CZSealBody
			{
			public:	// NATIVE OFFSETS (DO NOT DISRUPT)
				char							pad_0000[20];		//0x0000
				int								NamePTR;			//0x0014
				char							pad_0018[4];		//0x0018
				Vec3							Position;			//0x001C
				class CZSealObject* CPlayerMovement;	//0x0028
				char							pad_0030[148];		//0x0030
				int								TeamID;				//0x00C4
				char							pad_00C8[1348];		//0x00C8
				EPrimaryWeapon					PrimaryWeapon;		//0x060C
				ESecondaryWeapon				SecondaryWeapon;	//0x0610
				EEquipment						EqSlot1;			//0x0614
				EEquipment						EqSlot2;			//0x0618
				EEquipment						EqSlot3;			//0x061C
				char							pad_0620[220];		//0x0620
				int								PrimaryMag[10];		//0x06FC
				int								SecondaryMag[10];	//0x0724
				int								EquipmentSlot1;		//0x074C
				char							pad_0750[36];		//0x0750
				int								EquipmentSlot2;		//0x0774
				char							pad_0778[36];		//0x0778
				int								EquipmentSlot3;		//0x079C
				char							pad_07A0[1840];		//0x07A0
				float							Health;				//0x0ED0

				//	FUNCTIONS
			public:
				bool							IsValid();
				bool							IsAlive();
				class CZSealObject* PlayerPhysicsPtr();
				std::string						GetPlayerName();
				std::string						GetTeamName();
				std::string						GetWeaponName(unsigned int Weapon);
				void							GiveAmmo(int amount, int mags = {});
				void							GiveWeapon(unsigned int Slot, unsigned int Weapon);
				void							RemoveWeaponsandAmmo();
				void							Teleport(Vec3 Pos);
				void							ChangeTeams(ETeam newTeam);
				void							SetHealth(float newHealth);
				std::string						LogData();

			};	//Size: 0x0ED4

			

		*/
	}
}
#pragma pack(pop)