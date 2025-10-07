#pragma once
#include <cstddef>

/**
 * Name: PlayStation2 - PCSX2 :: Sly Cooper and the Thievous Racoonus
 * Version: 0.0.2
 * Author: NightFyre

RESOURCES & CREDITS: Sly Cooper Modding Server
	https://github.com/zzamizz/weed-sheet
	https://docs.google.com/spreadsheets/d/1ISxw587iICRDdaLJfLaTvJUaYkjGBReH4NY-yKN-Ip0/edit#gid=0
	https://discord.com/invite/2GSXcEzPJA
*/

#pragma pack(push, 0x01)
namespace PlayStation2
{
	namespace SlyCooper 
	{
		namespace Classes
		{
			class JT
			{
			public:
				char pad_0000[20]; //0x0000
				int32_t pSW; //0x0014
				char pad_0018[232]; //0x0018
				Vec3 Origin; //0x0100
				char pad_010C[68]; //0x010C
				Vec3 Velocity; //0x0150
				char pad_015C[500]; //0x015C
				Vec3 Gravity; //0x0350
				char pad_035C[732]; //0x035C
				float mFacingAngle; //0x0638
				char pad_063C[108]; //0x063C
				float mJumpHeight; //0x06A8
				char pad_06AC[20]; //0x06AC
				int32_t pCollisionSource; //0x06C0
				char pad_06C4[7004]; //0x06C4
				Enums::JT_STATES_INDEX eState; //0x2220
				char pad_2224[4]; //0x2224
				Enums::JT_BODY_STATES_INDEX eBodyState; //0x2228
				char pad_222C[16]; //0x222C
				Enums::JT_CANE_STATES_INDEX eCaneState; //0x223C
				char pad_2240[40]; //0x2240
				int32_t mMomentumHalting; //0x2268
				char pad_226C[44]; //0x226C
				int32_t mJumpAddr; //0x2298
				char pad_229C[1052]; //0x229C
				int32_t mZAPComponent; //0x26B8
				char pad_26BC[104]; //0x26BC
				float mOpacity; //0x2724
				char pad_2728[31760]; //0x2728
				int8_t aBodyOutline[4]; //0xA338
				char pad_A33C[335468]; //0xA33C
				int8_t aCaneHandleOutline[4]; //0x5C1A8
				char pad_5C1AC[3420]; //0x5C1AC
				int8_t aCaneHookOutline[4]; //0x5CF08
				char pad_5CF0C[192076]; //0x5CF0C
				int8_t aLeftHandOutline[4]; //0x8BD58
				char pad_8BD5C[230044]; //0x8BD5C
				int8_t aHeadOutline[4]; //0xC3FF8
				char pad_C3FFC[23868]; //0xC3FFC
				int8_t aEarsOutline[4]; //0xC9D38
				char pad_C9D3C[23212]; //0xC9D3C
				int8_t aHatOutline[4]; //0xCF7E8
				char pad_CF7EC[38844]; //0xCF7EC
				int8_t aBackpackOutline[4]; //0xD8FA8

			}; //Size: 0xD8FAC

			class CM
			{
			public:
				char pad_0000[64]; //0x0000
				Vec3 mOrigin; //0x0040
				char pad_004C[100]; //0x004C
				float mObjectFadeDistance; //0x00B0
				char pad_00B4[48]; //0x00B4
				float mYawTilt; //0x00E4
				char pad_00E8[4]; //0x00E8
				float mPitchTilt; //0x00EC
				float mHorizontalOffset; //0x00F0
				float mVerticalOffset; //0x00F4
				float mRenderDistance; //0x00F8
				float mZoomLevel; //0x00FC
				char pad_0100[196]; //0x0100
				float mFOV; //0x01C4
				float mTargetFOV; //0x01C8
				char pad_01CC[44]; //0x01CC
				float mFogThreshold; //0x01F8
				char pad_01FC[4]; //0x01FC
				float mFogAmount; //0x0200
				int8_t aFogColor[4]; //0x0204
				char pad_0208[24]; //0x0208
				int32_t mResetCameraFlag; //0x0220
				char pad_0224[440]; //0x0224
				uint32_t pFocusEntity; //0x03DC
				char pad_03E0[328]; //0x03E0
				int32_t mCameraAngle; //0x0528
				float mYawAngleRadians; //0x052C
			}; //Size: 0x0530
			static_assert(sizeof(CM) == 0x530);

			class LS
			{
			public:
				Enums::FLS eLevelState; //0x0000
				float mPlayTimer; //0x0004
				char pad_0008[4]; //0x0008
				float mDifficulty; //0x000C
				char pad_0010[84]; //0x0010
				int32_t mBottlesCount; //0x0064
				uint32_t mBottleBitfield; //0x0068
				char pad_006C[12]; //0x006C
			}; //Size: 0x0078
			static_assert(sizeof(LS) == 0x78);

			class WS
			{
			public:
				class LS aLevelStates[9]; //0x0000
				int32_t mKeysCount; //0x0438
				int32_t mVaultsCount; //0x043C
				int32_t mMTSCount; //0x0440
				float mWorldPlayTimer; //0x0444
				Enums::FWS eWorldState; //0x0448
			}; //Size: 0x044C
			static_assert(sizeof(WS) == 0x44C);

			class GS
			{
			public:
				Enums::FGS eGameState; //0x0000
				int32_t nChecksum; //0x0004
				char pad_0008[4]; //0x0008
				float mTotalPlayTime; //0x000C
				class WS WorldSaves[6]; //0x0010
				int32_t mCurrentWorldID; //0x19D8
				int32_t mCurrentLevelID; //0x19DC
				int32_t mLivesCount; //0x19E0
				int32_t mCharmsCount; //0x19E4
				int32_t mCoinsCount; //0x19E8
				uint32_t btSettings; //0x19EC
				int32_t mUnlockedThiefMoves; //0x19F0
				int32_t mUnlockedMovies; //0x19F4
				int32_t mGameCompletionFlags; //0x19F8
				int32_t mLastThiefMove; //0x19FC
			}; //Size: 0x1A00
			static_assert(sizeof(GS) == 0x1A00);
		}
	}
}
#pragma pack(pop)