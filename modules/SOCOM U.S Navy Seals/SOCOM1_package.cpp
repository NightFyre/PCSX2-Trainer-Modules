#pragma once
#include "SOCOM1_package.h"

/**
 * Name: PlayStation2 - PCSX2 :: SOCOM U.S NAVY SEALs
 * Version: 1.0.0
 * Author: NightFyre
*/

#pragma pack(push, 0x01)
namespace PlayStation2
{
	namespace SOCOM
	{

		i32_t GetWeaponByIndex(int index)
		{
			// index aligned with v_WeaponNames
			static const std::vector<Enums::EWEAPON> v_Weapons =
			{
				Enums::EWEAPON::EWeapon_EMPTY,
				Enums::EWEAPON::EWeapon_M4A1,
				Enums::EWEAPON::EWeapon_M4A1_SD,
				Enums::EWEAPON::EWeapon_M4A1_M203,
				Enums::EWEAPON::EWeapon_M16A2,
				Enums::EWEAPON::EWeapon_M16A2_M203,
				Enums::EWEAPON::EWeapon_552,
				Enums::EWEAPON::EWeapon_AK47,
				Enums::EWEAPON::EWeapon_AKS74,
				Enums::EWEAPON::EWeapon_M14,
				Enums::EWEAPON::EWeapon_M63A,
				Enums::EWEAPON::EWeapon_M60E3,
				Enums::EWEAPON::EWeapon_STONER63,
				Enums::EWEAPON::EWeapon_HK5,
				Enums::EWEAPON::EWeapon_HK5_SD,
				Enums::EWEAPON::EWeapon_UZI,
				Enums::EWEAPON::EWeapon_F90,
				Enums::EWEAPON::EWeapon_Remington870,
				Enums::EWEAPON::EWeapon_MK3_A2,
				Enums::EWEAPON::EWeapon_SR25,
				Enums::EWEAPON::EWeapon_SR25_SD,
				Enums::EWEAPON::EWeapon_M40A1,
				Enums::EWEAPON::EWeapon_M87ELR,
				Enums::EWEAPON::EWeapon_M82A1A,
				Enums::EWEAPON::EWeapon_MARK23,
				Enums::EWEAPON::EWeapon_MARK23_SD,
				Enums::EWEAPON::EWeapon_9MM,
				Enums::EWEAPON::EWeapon_M9,
				Enums::EWEAPON::EWeapon_P226,
				Enums::EWEAPON::EWeapon_F57,
				Enums::EWEAPON::EWeapon_DE50,
				Enums::EWEAPON::EWeapon_MODEL18,
				Enums::EWEAPON::EWeapon_M79,
				Enums::EWEAPON::EWeapon_MGL,
				Enums::EWEAPON::EWeapon_M203,
				Enums::EWEAPON::EWeapon_M67,
				Enums::EWEAPON::EWeapon_HE,
				Enums::EWEAPON::EWeapon_SMOKE,
				Enums::EWEAPON::EWeapon_FLASHBANG,
				Enums::EWEAPON::EWeapon_C4,
				Enums::EWEAPON::EWeapon_CLAYMORE,
				Enums::EWEAPON::EWeapon_SATCHEL,
				Enums::EWEAPON::EWeapon_2XAMMO,
				Enums::EWEAPON::EWeapon_M79_HE,
				Enums::EWEAPON::EWeapon_M79_FRAG,
				Enums::EWEAPON::EWeapon_M79_SMOKE,
				Enums::EWEAPON::EWeapon_M203_HE,
				Enums::EWEAPON::EWeapon_M203_FRAG,
				Enums::EWEAPON::EWeapon_M203_SMOKE,
				Enums::EWEAPON::EWeapon_KNIFE,
				Enums::EWEAPON::EWeapon_FLASHLIGHT,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_DETONATOR,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_BINOCULARS,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_RESTRAINTS,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_LASER_DESIGNATOR,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_KEVLAR_ARMOR,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_KEVLAR_ARMOR_INSERT,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_MPBOMB,		//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_ATG_MISSILE,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_ExplodingFuel,	//	unknown, not used in SOCOM 1
				Enums::EWEAPON::EWeapon_SATCHEL_EXPLOSION	//	unknown, not used in SOCOM 1
			};

			if (index >= 0 && index < v_Weapons.size())
				return (i32_t)v_Weapons[index];

			return 0; // Invalid index
		}

		i32_t GetAmmoTypeByIndex(int index)
		{
			// index aligned with v_AmmoNames
			static const std::vector<Enums::EAMMO> v_AmmoTypes =
			{
				Enums::EAMMO::EWeaponAmmo_EMPTY,
				Enums::EAMMO::EWeaponAmmo_M4A1,
				Enums::EAMMO::EWeaponAmmo_M4A1_SD,
				Enums::EAMMO::EWeaponAmmo_AK74,
				Enums::EAMMO::EWeaponAmmo_AKS74,
				Enums::EAMMO::EWeaponAmmo_M14,
				Enums::EAMMO::EWeaponAmmo_HK5,
				Enums::EAMMO::EWeaponAmmo_HK5_SD,
				Enums::EAMMO::EWeaponAmmo_F90,
				Enums::EAMMO::EWeaponAmmo_LONGRIFLE,
				Enums::EAMMO::EWeaponAmmo_MK23,
				Enums::EAMMO::EWeaponAmmo_DE50,
				Enums::EAMMO::EWeaponAmmo_SHOTGUN,
				Enums::EAMMO::EWeaponAmmo_M87ELR,
				Enums::EAMMO::EWeaponAmmo_M67,
				Enums::EAMMO::EWeaponAmmo_HE,
				Enums::EAMMO::EWeaponAmmo_Smoke,
				Enums::EAMMO::EWeaponAmmo_M141,
				Enums::EAMMO::EWeaponAmmo_Satchel,
				Enums::EAMMO::EWeaponAmmo_Claymore,
				Enums::EAMMO::EWeaponAmmo_C4,
				Enums::EAMMO::EWeaponAmmo_M203_HE,
				Enums::EAMMO::EWeaponAmmo_M203_FRAG,
				Enums::EAMMO::EWeaponAmmo_M203_SMOKE,
				Enums::EAMMO::EWeaponAmmo_M79_HE,
				Enums::EAMMO::EWeaponAmmo_M79_FRAG,
				Enums::EAMMO::EWeaponAmmo_M79_SMOKE,
				Enums::EAMMO::EWeaponAmmo_MP_BOMB,
				Enums::EAMMO::EWeaponAmmo_ATG_Missile,
				Enums::EAMMO::EWeaponAmmo_ExplosiveStuff
			};

			if (index >= 0 && index < v_AmmoTypes.size())
				return (i32_t)v_AmmoTypes[index];

			return 0; // Invalid index
		}

		i32_t GetTeamIDByIndex(int index)
		{
			static const std::vector<Enums::ESEAL_TEAMS> v_Teams =
			{
				Enums::ESEAL_TEAMS::ETeam_NONE,
				Enums::ESEAL_TEAMS::ETeam_SEALS,
				Enums::ESEAL_TEAMS::ETeam_TERRORIST,
				Enums::ESEAL_TEAMS::ETeam_SPECTATOR,
				Enums::ESEAL_TEAMS::ETeam_SP_ABLE,
				Enums::ESEAL_TEAMS::ETeam_SP_BRAVO,
				Enums::ESEAL_TEAMS::ETeam_SP_ENEMY_A,
				Enums::ESEAL_TEAMS::ETeam_TURRET,
				Enums::ESEAL_TEAMS::ETeam_GHOST
			};

			if (index >= 0 && index < v_Teams.size())
				return (i32_t)v_Teams[index];

			return 0; // Invalid index
		}

		bool GetBoneNameByIndex(int index, std::string& outResult)
		{
			if (index < 0 || index > v_BoneNames.size())
				return false;	//	invalid index

			outResult = v_BoneNames[index];
		
			return !outResult.empty();
		}

		namespace Dumper
		{
			void DumpMissionInfo()
			{
				/* get local seal object */
				CZSeal* pSealBody = CZSeal::GetDefaultInstance();
				if (!pSealBody)
					return;
			
				/* get reference to entity array */
				std::vector<CZSeal*> vSeals;
				if (!CZMatchData::GetEntities(&vSeals))
					return;	// failed to retrieve entities

				/* get reference to pickup array */
				std::vector<CPickup*> vPickups;
				CZMatchData::GetAllPickups(&vPickups);

				/* log entity count */
				Console::LogMsg("[+]Dumping Mission Info\n");
				Console::LogMsg("[+]Entity Count: %d\n", vSeals.size());
				Console::LogMsg("[+]Pickup Count: %d\n", vPickups.size());
				for (auto& pEntity : vSeals)
				{
					if (!pEntity)
						continue;	// skip null pointers

					/* log entity information */
					Console::LogMsg("- %s { ID: %d, Team: 0x%llX }\n", pEntity->GetName().c_str(), pEntity->GetEntityType(), pEntity->GetTeam());
				}

				//	for (auto& pPickup : vPickups)
				//	{
				//		if (!pPickup)
				//			continue;	// skip null pointers
				//		/* log pickup information */
				//		Console::LogMsg("- %s { ID: %d, Type: 0x%llX }\n", pPickup->GetName().c_str(), pPickup->GetType(), pPickup->GetEntityType());
				//	}

				Console::LogMsg("[+] finished dumping mission info\n\n");

			}

			void Dumper::DumpBoneNames()
			{
				std::vector<std::string> partNames;	//	bone names

				/* get local seal object */
				CZSeal* pSealBody = CZSeal::GetDefaultInstance();
				if (!pSealBody)
					return;

				/* get body part array */
				static const int szBodyParts = 0x21;
				for (int i = 0; i <= szBodyParts; i++)
				{
					/* get body part class instance */
					CZBodyPart* pBodyPart = nullptr;	// body part pointer
					if (!pSealBody->GetBoneByIndex(i, &pBodyPart))
						continue;	// skip null body part pointers

					/* get bone name */
					std::string partName = pBodyPart->GetName();
					if (partName.empty())
						continue; // skip empty names

					partNames.push_back(partName);	// add bone name to list
				}

				/* log bone names */
				Console::LogMsg("[+]Dumping Bone Names\n");
				DWORD index = -1;
				for (auto& name : partNames)
				{
					index++;

					Console::LogMsg("%s\n", name.c_str());
				}
				Console::LogMsg("[+] finished dumping bones with count %d\n", partNames.size());

				/* create enum list for bones */
				Console::LogMsg("enum ESEALBONES_INDEX : int\n{\n\tESEALBONES_MIN = 0,\n");
				for (auto& name : partNames)
					Console::LogMsg("\tESEALBONES_%s,\n", name.c_str());
				Console::LogMsg("\tESEALBONES_MAX = %s\n};\n\n", partNames[partNames.size() - 1]);
			}
		}

		namespace Structs
		{
			bool CZKit::GetEquippedWeapon(i32_t& outWeapon)
			{
				if (this->mCurrentWeaponIndex < 0 || this->mCurrentWeaponIndex > this->mMaxWeaponIndex)
					return false;

				return GetWeaponAtIndex(this->mCurrentWeaponIndex, outWeapon);
			}

			bool CZKit::GetEquippedAmmo(i32_t& outAmmo)
			{
				if (this->mCurrentWeaponIndex < 0 || this->mCurrentWeaponIndex > this->mMaxWeaponIndex)
					return false;

				return GetAmmoAtIndex(this->mCurrentWeaponIndex, outAmmo);
			}

			bool CZKit::GetWeaponAtIndex(const Enums::EWEAPONEQUIP_INDEX& index, i32_t& outWeapon)
			{
				const auto& iIndex = (__int32)index;
				if (iIndex < 0 || iIndex > this->mMaxWeaponIndex)
					return false;

				i32_t pWeapon = 0;
				//	switch (index)
				//	{
				//		case Enums::EWeaponIndex_Primary: pWeapon = this->mPrimaryWeapon; break;
				//		case Enums::EWeaponIndex_Secondary: pWeapon = this->mSecondaryWeapon; break;
				//		case Enums::EWeaponIndex_EqSlot1: pWeapon = this->mEqSlot1; break;
				//		case Enums::EWeaponIndex_EqSlot2: pWeapon = this->mEqSlot2; break;
				//		case Enums::EWeaponIndex_EqSlot3: pWeapon = this->mEqSlot3; break;
				//		default: return false;
				//	}

				pWeapon = this->pWeapons[index];

				if (!pWeapon)
					return false;

				outWeapon = pWeapon;

				return true;
			}

			bool CZKit::GetAmmoAtIndex(const Enums::EWEAPONEQUIP_INDEX& index, i32_t& outAmmo)
			{
				const auto& iIndex = (__int32)index;
				if (iIndex < 0 || iIndex > this->mMaxWeaponIndex)
					return false;

				i32_t pAmmo = 0;
				//	switch (index)
				//	{
				//	case Enums::EWeaponIndex_Primary: pAmmo = this->mPrimaryAmmoType; break;
				//	case Enums::EWeaponIndex_Secondary: pAmmo = this->mSecondaryAmmoType; break;
				//	case Enums::EWeaponIndex_EqSlot1: pAmmo = this->mEqSlot1AmmoType; break;
				//	case Enums::EWeaponIndex_EqSlot2: pAmmo = this->mEqSlot2AmmoType; break;
				//	case Enums::EWeaponIndex_EqSlot3: pAmmo = this->mEqSlot3AmmoType; break;
				//	default: return false;
				//	}

				pAmmo = this->pAmmoTypes[index];

				if (!pAmmo)
					return false;

				outAmmo = pAmmo;

				return true;
			}

			bool CZKit::GetWeaponName(const Enums::EWEAPONEQUIP_INDEX& index, std::string& outName)
			{
				outName = GetWeaponName(index);
				
				return outName.size() > 0;
			}

			bool CZKit::GetAmmoName(const Enums::EWEAPONEQUIP_INDEX& index, std::string& outName)
			{
				outName = GetAmmoName(index);

				return outName.size() > 0;
			}

			void CZKit::SetHeartbeatEnabled(bool enabled) { this->m_heartbeat_enabled = enabled; }

			bool CZKit::GetHeartbeatEnabled() const { return this->m_heartbeat_enabled; }

			std::string CZKit::GetWeaponName(const Enums::EWEAPONEQUIP_INDEX& index)
			{
				std::string result = ("ERROR");
				const auto& iIndex = (__int32)index;
				if (iIndex < 0 || iIndex > this->mMaxWeaponIndex)
					return result;

				i32_t pWeapon = 0;
				if (!GetWeaponAtIndex(index, pWeapon))
					return result;

				auto weapon = (CZWeapon*)PS2Memory::GetEEAddr(pWeapon);
				if (!weapon || !weapon->pName)
					return result;

				return (char*)PS2Memory::GetEEAddr(weapon->pName);
			}

			std::string CZKit::GetAmmoName(const Enums::EWEAPONEQUIP_INDEX& index)
			{
				std::string result = ("ERROR");
				const auto& iIndex = (__int32)index;
				if (iIndex < 0 || iIndex > this->mMaxWeaponIndex)
					return result;

				i32_t pWeapon = 0;
				if (!GetAmmoAtIndex(index, pWeapon))
					return result;

				auto ammo = (CZAmmo*)PS2Memory::GetEEAddr(pWeapon);
				if (!ammo)
					return result;

				i32_t pName = ammo->pDisplayName != 0 ? ammo->pDisplayName : ammo->pAmmoName;
				if (!pName)
					return result;

				return (char*)PS2Memory::GetEEAddr(pName);
			}
		}


		//----------------------------------------------------------------------------------------------------
		//										CZCAMERA
		// - CZCamera
		//-----------------------------------------------------------------------------------

		CZCamera* CZCamera::GetDefaultInstance()
		{
			CAppCamera* pAppCamera = CAppCamera::GetDefaultInstance();
			if (!pAppCamera)
				return nullptr;

			return pAppCamera->GetCamera();
		}

		float CZCamera::GetFOVTanHalf() { return this->mtxViewToClip.m[1][1]; }

		float CZCamera::GetFOV()
		{
			float fov = 2.0f * atanf(1.0f / GetFOVTanHalf());
			fov *= (180.0f / M_PI);	// degrees

			return fov;
		}

		unsigned __int16 CZCamera::GetViewMtxHash()
		{
			return this->mtxHash;
		}

		bool CZCamera::WorldToScreen(const Vec3& pos, const Vec2& szScreen, Vec2* screen2D)
		{
			static float fov{ 60.f };

			//  get camera view matrix

			Mat4x4 mtxModel = this->mModelMatrix;

			Vec3 cam_pos = mtxModel.Translation();
			Vec3 cam_look = Vec3(-mtxModel.m[2][0], -mtxModel.m[2][1], -mtxModel.m[2][2]);
			Vec3 cam_right = Vec3(mtxModel.m[0][0], mtxModel.m[0][1], mtxModel.m[0][2]);
			Vec3 cam_up = Vec3(mtxModel.m[1][0], mtxModel.m[1][1], mtxModel.m[1][2]);

			//  get direction or heading
			Vec3 heading = pos - cam_pos;
			float camX = heading.dot(cam_right);
			float camY = heading.dot(cam_up);
			float camZ = heading.dot(cam_look);

			//  check if object is behind the camera
			if (camZ <= 0.f)
				return false;

			//  apply perspective projection
			float aspect = szScreen.x / szScreen.y;
			float fov_radians = tan(fov * 0.5f * (M_PI / 180.f)); // Convert fov to radians and compute scaling factor

			float pX = camX / (camZ * fov_radians * aspect);
			float pY = camY / (camZ * fov_radians);

			Vec2 res =
			{
				(pX + 1.0f) * 0.5f * szScreen.x,
				(1.0f - pY) * 0.5f * szScreen.y // Invert Y because screen coordinates are top-down
			};

			if (res.x <= 0.f || res.y <= 0.0f)
				return false;

			if (res.x > szScreen.x || res.y > szScreen.y)
				return false;

			*screen2D = res;

			return true;

			CWorld* pWorld = CWorld::GetDefaultInstance();
			if (!pWorld || !screen2D)
				return false;

			Mat4x4 mtxWorldToView;
			if (!pWorld->GetViewMatrix(&mtxWorldToView))
				return false;

			{

				Vec4 viewPos = Vec4(pos.x, pos.y, pos.z, 1.f) * mtxWorldToView;

				Vec4 clipPos = viewPos * this->mtxViewToClip;
				if (clipPos.w <= 0.1f)
					return false; // behind the camera

				Vec4 ndc4 = clipPos / clipPos.w;

				return false;
			}


			const Mat4x4& mtxWorldToClip = this->mtxWorldToView * this->mtxViewToClip;	//	Model View Projection
			Vec4 clipSpaceOrigin = this->mtxWorldToClip * Vec4(pos.x, pos.y, pos.z, 1.f);
			if (clipSpaceOrigin.w <= 0.1f)
				return false; // behind the camera

			Vec4 ndc4 = clipSpaceOrigin / clipSpaceOrigin.w; // Normalize Device Coordinates (NDC)
			Vec4 screen = this->mtxViewToScreen * ndc4; // Convert to screen coordinates

			float x_ratio = (float)szScreen.x / (float)640.f;
			float y_ratio = (float)szScreen.y / (float)448.f;
			
			//	screen.x = (screen.x - 2048.0f) * x_ratio + szScreen.x / 2.0f;
			//	screen.y = (screen.y - 2048.0f) * y_ratio + szScreen.y / 2.0f;
			//	screen.x = (screen.x / 4096.0f) * szScreen.x;
			//	screen.y = (screen.y / 4096.0f) * szScreen.y;

			screen.x = (ndc4.x + 1.0f) * 0.5f * szScreen.x;
			screen.y = (1.0f - ndc4.y) * 0.5f * szScreen.y;
			
			//	screen.x = (ndc4.x + 1.0f) * 0.5f * szScreen.x;
			//	screen.y = (1.0f - ndc4.y) * 0.5f * szScreen.y;
			
			*screen2D = { screen.x, screen.y };
			
			return true;

			//	Vec3 ndc;
			//	ndc.x = clipSpaceOrigin.x / clipSpaceOrigin.w;
			//	ndc.y = clipSpaceOrigin.y / clipSpaceOrigin.w;
			//	ndc.z = clipSpaceOrigin.z / clipSpaceOrigin.w;
			//	
			//	// Convert NDC to screen coordinates
			//	*screen2D =
			//	{
			//		(szScreen.x / 2 * ndc.x) + (ndc.x + szScreen.x / 2),
			//		-(szScreen.y / 2 * ndc.y) + (ndc.y + szScreen.y / 2)
			//	};
			//	
			//	return true;
		}

		//----------------------------------------------------------------------------------------------------
		//										CAPPCAMERA
		// - CAppCamera
		//-----------------------------------------------------------------------------------

		CAppCamera* CAppCamera::GetDefaultInstance()
		{
			if (!Offsets::o_LocalCamera)
				return nullptr;

			return PS2Memory::GetPtrShort<CAppCamera*>(Offsets::o_LocalCamera);
		}

		CZCamera* CAppCamera::GetCamera() { return this->pCamera == 0 ? nullptr : (CZCamera*)PS2Memory::GetEEAddr(this->pCamera); }

		CZSeal* CAppCamera::GetAttachedPlayer() { return this->pAttachedPlayer == 0 ? nullptr : (CZSeal*)PS2Memory::GetEEAddr(this->pAttachedPlayer); }

		Vec3 CAppCamera::GetPosition() { return this->mOrigin; }

		bool CAppCamera::GetCameraMatrix(FViewModel* out)
		{
			auto res = PS2Memory::ReadEE<FViewModel>(this->pCamera);

			*out = res;

			return true;
		}

		bool CAppCamera::GetLookVector(Vec3* out)
		{
			FViewModel view;
			if (!GetCameraMatrix(&view))
				return false;

			*out = Vec3(-view.fwd.x, -view.fwd.y, -view.fwd.z);

			return true;
		}

		bool CAppCamera::GetRightVector(Vec3* out)
		{
			FViewModel view;
			if (!GetCameraMatrix(&view))
				return false;

			*out = Vec3(view.right.x, view.right.y, view.right.z);

			return true;
		}

		bool CAppCamera::GetUpVector(Vec3* out)
		{
			FViewModel view;
			if (!GetCameraMatrix(&view))
				return false;

			*out = Vec3(view.up.x, view.up.y, view.up.z);

			return true;
		}

		void CAppCamera::Reset()
		{
			CZSeal* localPlayer = CZSeal::GetDefaultInstance();
			if (!localPlayer)
				return;

			//	attach to local player if not already
			if (!IsAttachedToLocalPlayer())
				this->SetAttachedEntity(localPlayer);

			SetCamDistance(0.f);	//	restore camera position
		}

		bool CAppCamera::GetAttachedEntity(CZSeal* out)
		{
			auto res = this->pAttachedPlayer;
			if (!res)
				return false;

			out = (CZSeal*)PS2Memory::GetEEAddr(this->pAttachedPlayer);
			
			return out != nullptr;
		}

		void CAppCamera::SetAttachedEntity(CZSeal* pEntity)
		{
			auto addr = __int64(pEntity) - PS2Memory::GetEEBase();
			this->pAttachedPlayer = addr;
		}

		bool CAppCamera::IsAttachedToLocalPlayer()
		{
			CZSeal* localPlayer = CZSeal::GetDefaultInstance();
			if (!localPlayer)
				return false;

			auto res = this->pAttachedPlayer;
			if (!res)
				return false;

			if ((__int64(localPlayer) - PS2Memory::GetEEBase()) != res)
				return false;

			return true;
		}

		void CAppCamera::SetCamDistance(float dist)
		{
			auto res = PS2Memory::ReadEE<FViewCache*>(this->pTransforms);
			if (!res)
				return;

			res->m5.z = dist;
		}

		//----------------------------------------------------------------------------------------------------
		//										CZSealObject
		// - CPlayerPhysics
		//-----------------------------------------------------------------------------------

		CZSealObject* CZSealObject::GetDefaultInstance()
		{
			CZSeal* pLocalSeal =  CZSeal::GetDefaultInstance();

			if (!pLocalSeal)
				return nullptr;

			return reinterpret_cast<CZSealObject*>(pLocalSeal->GetSealObject());
		}

		Vec3 CZSealObject::GetPosition() { return this->m_absPosition; }

		void CZSealObject::SetPosition(Vec3 p) { this->m_absPosition = p; }


		//----------------------------------------------------------------------------------------------------
		//										CZSealCtrl
		// - CPlayer
		//-----------------------------------------------------------------------------------

		CNode* CNode::GetParent()
		{
			return (CNode*)PS2Memory::GetEEAddr(this->pParent);
		}

		CEntity* CNode::GetEntity()
		{
			auto pNode = (CNodeEx*)PS2Memory::GetEEAddr(this->pNodeEx);
			if (!pNode)
				return nullptr;

			return (CEntity*)PS2Memory::GetEEAddr(pNode->pEntity);
		}

		std::string CNode::GetName() const
		{
			std::string result{};
			if (!this->pName)
				return result;

			return (char*)PS2Memory::GetEEAddr(this->pName);
		}

		Vec3 CNode::GetWorldPos() const { return this->mMatrix.Translation(); }

		void CNode::SetWorldPos(const Vec3& newPos)
		{
			this->mMatrix.m[3][0] = newPos.x; 
			this->mMatrix.m[3][1] = newPos.y; 
			this->mMatrix.m[3][2] = newPos.z; 
		};

		Mat4x4 CNode::GetWorldTM() const { return this->mMatrix; }

		void CNode::SetWorldTM(const Mat4x4& newTM) { this->mMatrix = newTM; }

		AABB CNode::GetLocalBounds() const { return this->mAABB; }

		AABB CNode::GetWorldBounds() const
		{
			return this->mAABB + GetWorldPos();
		}

		Vec3 CNode::GetRightVector() const { return Vec3(mMatrix.m[0][0], mMatrix.m[0][1], mMatrix.m[0][2]); }
		
		Vec3 CNode::GetUpVector() const { return Vec3(mMatrix.m[1][0], mMatrix.m[1][1], mMatrix.m[1][2]); }
		
		Vec3 CNode::GetForwardVector() const { return Vec3(-mMatrix.m[2][0], -mMatrix.m[2][1], -mMatrix.m[2][2]); }

		float CNode::GetYawAngleRadians() const
		{
			Mat4x4 m = this->mMatrix;

			/* get radians */
			return atan2(-m.m[2][0], m.m[2][2]);
		}

		float CNode::GetYawAngleDegrees() const
		{
			float yawDeg = GetYawAngleRadians() * (180.f / M_PI);

			/* normalize 0-360 */
			if (yawDeg < 0.f)
				yawDeg += 360.f;

			return yawDeg;
		}

		CWorld* CWorld::GetDefaultInstance()
		{
			if (!Offsets::o_World)
				return nullptr;

			return PS2Memory::GetPtrShort<CWorld*>(Offsets::o_World);
		}

		bool CWorld::GetViewMatrix(Mat4x4* out)
		{
			/* sceVu0CopyMatrix((int)v53, *(_DWORD *)(*(_DWORD *)(zdb::CWorld::m_world + 0xC0) + 0x3C0) + 0x20); */

			/* validate camera */
			if (!this->pCamera)
				return false;

			/* get camera */
			CZCamera* pCamera = (CZCamera*)PS2Memory::GetEEAddr(this->pCamera);
			if (!pCamera)
				return false;

			/* get ScratchPad Offset */
			const auto& offset = pCamera->GetViewMtxHash();
			if (offset <= 0 || offset >= ((1024 * 1) * 16))
				return false;

			/* read view matrix head from scratchpad */
			const auto& mtx_base = PS2Memory::GetScratchPadBase() + offset;
			if (mtx_base == offset)
				return false;

			/* copy matrix */
			*out = *reinterpret_cast<Mat4x4*>(mtx_base + 0x20);

			return true;
		}


		class CZSeal* CTarget::GetEntity()
		{
			if (!this->pEntity)
				return nullptr;

			return (CZSeal*)PS2Memory::GetEEAddr(this->pEntity);
		}

		bool CTarget::WasRecentlyVisible() const { return IsVisible() && this->mVisibility >= 1.5 && this->mVisibility <= 1.8; }
		bool CTarget::IsVisible() const { return this->m_visible && this->mVisibility >= 2.0f; }
		bool CTarget::IsHostile() const { return this->m_hostile; }


		CZBodyPart* CZBodyPart::GetParent()
		{
			if (!this->pParent)
				return nullptr;

			return (CZBodyPart*)PS2Memory::GetEEAddr(this->pParent);
		}

		CNode* CZBodyPart::GetNode()
		{
			if (!this->pNode)
				return nullptr;

			return (CNode*)PS2Memory::GetEEAddr(this->pNode);
		}

		//----------------------------------------------------------------------------------------------------
		//										CZBODYPART
		// - CZBodyPart
		//-----------------------------------------------------------------------------------

		Vec3 CZBodyPart::GetLocalOrigin() const { return this->mOrigin;}
		Vec4 CZBodyPart::GetLocalRotation() const { return this->mRotation; }
		__int16 CZBodyPart::GetID() const { return this->mID; }

		bool CZBodyPart::GetLocalTM(Mat4x4* out)
		{
			if (!this->pNode)
				return false;

			CNode* pNode = (CNode*)PS2Memory::GetEEAddr(this->pNode);
			if (!pNode)
				return false;

			*out = pNode->mMatrix;
		
			return true;
		}
		
		bool CZBodyPart::GetWorldTM(const Mat4x4& model, Mat4x4* out)
		{
			/* get body part matrix */
			Mat4x4 base_matrix;
			if (!GetLocalTM(&base_matrix))
				return false;
			
			if (!this->pParent)
			{
				*out = base_matrix * model;
				return true;
			}

			/* iterate body part tree */
			bool bFoundParents{ false };	// flag to check if parent body parts were found
			CZBodyPart* pBodyPart = this;	// set current body part as current body part
			do
			{
				/* get parent body part */
				CZBodyPart* pParentBodyPart = pBodyPart->GetParent();
				if (!pParentBodyPart)
				{
					bFoundParents = true;	// no parent found, exit loop
					break;
				}

				/* get parent body part matrix */
				Mat4x4 parentLocalMatrix;
				if (!pParentBodyPart->GetLocalTM(&parentLocalMatrix))
				{
					bFoundParents = true;	// no parent node found, exit loop
					break;
				}

				/* set pBodyPart to the parent & apply matrix transformation on the mtx buffer */
				pBodyPart = pParentBodyPart;	// set parent body part as current body part
				base_matrix = base_matrix * parentLocalMatrix;	// multiply parent matrix to temporary matrix

			} while (!bFoundParents);

			*out = base_matrix * model;

			return true;
		}

		std::string CZBodyPart::GetName()
		{
			CNode* pNode = GetNode(); return pNode == nullptr ? "" : pNode->GetName();
		}

		//----------------------------------------------------------------------------------------------------
		//										CPICKUP
		// - CPickup
		//-----------------------------------------------------------------------------------

		CNode* CPickup::GetPickupObject()
		{
			if (!this->pNode)
				return nullptr;

			return (CNode*)PS2Memory::GetEEAddr(this->pNode);
		}

		std::string CPickup::GetName()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return "";

			if (!pNode->pName)
				return "";

			return (char*)PS2Memory::GetEEAddr(pNode->pName);
		}
		
		Vec3 CPickup::GetWorldPos()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return Vec3(0.f, 0.f, 0.f);

			return pNode->GetWorldPos();
		}
		
		AABB CPickup::GetWorldBounds()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return AABB(Vec3(0.f, 0.f, 0.f), Vec3(0.f, 0.f, 0.f));
			
			return pNode->GetWorldBounds();
		}
		
		Mat4x4 CPickup::GetWorldTM()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return Mat4x4();

			return pNode->GetWorldTM();
		}
		
		Vec3 CPickup::GetForwardVector()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return Vec3(0.f, 0.f, 0.f);

			return pNode->GetForwardVector();
		}
		
		Vec3 CPickup::GetRightVector()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return Vec3(0.f, 0.f, 0.f);

			return pNode->GetRightVector();
		}
		
		Vec3 CPickup::GetUpVector()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return Vec3(0.f, 0.f, 0.f);

			return pNode->GetUpVector();
		}
		
		float CPickup::GetYawAngleDegrees()
		{
			CNode* pNode = this->GetPickupObject();
			if (!pNode)
				return -1.f;

			return pNode->GetYawAngleDegrees();
		}

		//----------------------------------------------------------------------------------------------------
		//										CZSeal
		// - CPlayer
		//-----------------------------------------------------------------------------------

		CZSeal* CZSeal::GetDefaultInstance()
		{
			if (!Offsets::o_LocalSeal)
				return nullptr;

			return PS2Memory::GetPtrShort<CZSeal*>(Offsets::o_LocalSeal);
		}

		bool CZSeal::IsValid()
		{
			return (this != nullptr && this->mEntityType >= 0 && this->pName > 0 && this->pNode > 0 /*&& this->mTeamID > Enums::ESEAL_TEAMS::ETeam_NONE*/);
		}

		bool CZSeal::IsPlayerEntity()
		{
			if (!this->IsValid())
				return false;

			return this->mEntityType == Enums::EENTITY_TYPE::ENT_TYPE_SEAL;
		}

		CNode* CZSeal::GetSealObject() 
		{ 
			if (!this->pNode)
				return nullptr;

			return (CNode*)PS2Memory::GetEEAddr(this->pNode);
		}

		Structs::CZKit* CZSeal::GetKit()
		{
			return (Structs::CZKit*)&this->mKit;
		}

		Vec3 CZSeal::GetPosition() { return this->mOrigin; }

		bool CZSeal::SetPosition(Vec3 p)
		{
			CZSealObject* pObj = reinterpret_cast<CZSealObject*>(this->GetSealObject());
			if (!pObj)
				return false;

			pObj->SetPosition(p);

			return true;
		}

		float CZSeal::GetAngleRadians()
		{
			return fmod(atan2(this->mQuat.y, this->mQuat.w), M_PI * 2.f) * 2;
		}

		float CZSeal::GetAngleDegrees()
		{
			return 0.f;
		}

		std::string CZSeal::GetName()
		{
			if (!this->IsValid())
				return "";
			
			return (char*)PS2Memory::GetEEAddr(this->pName);
		}

		Enums::ESEAL_TEAMS CZSeal::GetTeam() { return (Enums::ESEAL_TEAMS)this->mTeamID; }

		Enums::ESEAL_STANCE CZSeal::GetStance()
		{
			return this->mStance;
		}

		void CZSeal::SetTeam(const Enums::ESEAL_TEAMS& newTeam)
		{
			/* @TODO: prevent setting unrealistic id's */
			this->mTeamID = newTeam;
		}

		float CZSeal::GetHealth() { return this->mHealth * 100.f; }

		bool CZSeal::IsAlive() { return this->mHealth > 0.0f; }

		bool CZSeal::IsVisible(CZSeal* pOther)
		{
			if (!this->IsValid() || !pOther->IsValid() || this->mTargetCount <= 0 || this->mMaxTargetCount <= 0)
				return false;

			unsigned __int64 pTargetArray = PS2Memory::GetEEAddr(this->pTargetArray);
			if (!pTargetArray)
				return false;	//	no target array, cannot check visibility

			for (int i = 0; i < this->mTargetCount; i++)
			{
				CTarget* pTarget = (CTarget*)(pTargetArray + (i * sizeof(CTarget)));
				if (!pTarget)
					return false;

				CZSeal* pSeal = (CZSeal*)PS2Memory::GetEEAddr(pTarget->pEntity);
				if (pSeal == pOther)
					return pTarget->m_visible;
			}

			return false;
		}

		bool CZSeal::IsFriendly(CZSeal* pOther)
		{
			if (!pOther->IsValid())
				return false;

			auto& team = this->mTeamID;
			auto other_team = pOther->GetTeam();
			if (team == Enums::ESEAL_TEAMS::ETeam_SPECTATOR || other_team == Enums::ESEAL_TEAMS::ETeam_SPECTATOR || team == Enums::ESEAL_TEAMS::ETeam_TURRET || other_team == Enums::ESEAL_TEAMS::ETeam_TURRET)
				return false;

			if (team == other_team)
				return true;

			if (team == Enums::ESEAL_TEAMS::ETeam_SP_ABLE && other_team == Enums::ESEAL_TEAMS::ETeam_SP_BRAVO || team == Enums::ESEAL_TEAMS::ETeam_SP_BRAVO && other_team == Enums::ESEAL_TEAMS::ETeam_SP_ABLE)
				return true;

			//	std::vector<CTarget*> vTargets;
			//	if (!GetTargets(vTargets))
			//		return false;	//	no targets found, cannot check hostile state
			//	
			//	for (auto& ent : vTargets)
			//	{
			//		if (!ent)
			//			continue;
			//		
			//		CZSeal* pTargetSeal = ent->GetEntity();
			//		
			//		if (!pTargetSeal || !pTargetSeal->IsValid())
			//			continue;	//	skip invalid targets
			//		
			//		if (pTargetSeal != pOther)
			//			continue;
			//	
			//		return ent->IsHostile();
			//	}


			return false;	//	not caring to compare campaign terorist teams at this time, though special characters seem to have designated team id
		}

		bool CZSeal::IsEnemy(CZSeal* pOther)
		{
			if (!this->IsValid() || !pOther->IsValid())
				return false;

			if (this->mTeamID == pOther->mTeamID)
				return false;	//	same team, not an enemy

			return ((unsigned int)pOther->mTeamID & 0xFF000000) == 0x40000000;		//	0x40000000 is the bitmask for enemy teams, so if the team id matches this, it's an enemy
		}

		bool CZSeal::IsNonCombatant(CZSeal* pOther)
		{
			if (!this->IsValid() || !pOther->IsValid() || IsEnemy(pOther))
				return false;

			return (((unsigned int)pOther->mTeamID & 0xF0000000) == 0xC0000000) ||  //	0xC0000000 is the bitmask for non-combatant teams, so if the team id matches this, it's a non-combatant
				(((unsigned int)pOther->mTeamID & 0xF0000000) == 0xD0000000);		//	0xD0000000 is the bitmask for non-combatant teams, so if the team id matches this, it's a non-combatant
		}

		bool CZSeal::IsSpecialEnemy(CZSeal* pOther)
		{
			if (!this->IsValid() || !pOther->IsValid())
				return false;

			if (!this->IsEnemy(pOther))
				return false;

			uint32_t roleBits = (unsigned int)pOther->mTeamID & 0x0000FFFF;

			return roleBits <= 0x0200;
		}

		bool CZSeal::GetTargets(std::vector<CTarget*>& outTargets)
		{
			if (!this->IsValid() || this->mTargetCount <= 0 || this->mMaxTargetCount <= 0)
				return false;

			unsigned __int64 pTargetArray = PS2Memory::GetEEAddr(this->pTargetArray);
			if (!pTargetArray)
				return false;	//	no target array, cannot check visibility

			outTargets.clear();	//	clear output vector
			for (int i = 0; i < this->mTargetCount; i++)
			{
				CTarget* pTarget = (CTarget*)(pTargetArray + (i * sizeof(CTarget)));
				if (!pTarget)
					continue;

				outTargets.push_back(pTarget);	//	add target to output vector
			}

			return true;	// targets found
		}

		bool CZSeal::GetWorldTM(Mat4x4* out)
		{
			if (!this->IsValid())
				return false;
		
			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetWorldTM();

			return true;
		}

		bool CZSeal::SetWorldPos(const Vec3& newPos)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			pNode->SetWorldPos(newPos);
			
			return true;
		}

		bool CZSeal::GetWorldPos(Vec3* out)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetWorldPos();

			return true;
		}

		bool CZSeal::GetLocalBounds(AABB* out)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetLocalBounds();

			return true;
		}

		bool CZSeal::GetWorldBounds(AABB* out)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetWorldBounds();

			return true;
		}

		bool CZSeal::GetForwardVector(Vec3* out)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetForwardVector();

			return true;
		}

		bool CZSeal::GetRightVector(Vec3* out)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetRightVector();

			return true;
		}

		bool CZSeal::GetUpVector(Vec3* out)
		{
			if (!this->IsValid())
				return false;

			CNode* pNode = GetSealObject();
			if (!pNode)
				return false;

			*out = pNode->GetUpVector();
			
			return true;
		}



#define sincos(radian, s, c) s = sin(radian); c = cos(radian)

		void RotatePoint(const Vec3& point, const Vec3& center, const float* angles, Vec3* result)
		{

			float sx, cx, sy, cy, sz, cz;
			sincos(angles[1], sx, cx);
			sincos(angles[2], sy, cy);
			sincos(angles[0], sz, cz);
			Vec3 rotatedPoint;
			Vec3 dir;

			dir = point - center;
			rotatedPoint.x = point.x;
			rotatedPoint.y = center.y + (dir.y * cz - dir.z * sz);
			rotatedPoint.z = center.z + (dir.y * sz + dir.z * cz);

			dir = rotatedPoint - center;
			rotatedPoint.x = center.x + (dir.x * cx + dir.z * sx);
			rotatedPoint.z = center.z + (dir.z * cx - dir.x * sx);

			dir = rotatedPoint - center;

			result->x = center.x + (dir.x * cy - dir.y * sy);
			result->y = center.y + (dir.x * sy + dir.y * cy);
			result->z = rotatedPoint.z;
		}
		
		bool CZSeal::GetBoneByIndex(int boneIndex, CZBodyPart** out)
		{
			if (!this->IsValid())
				return false;	// invalid seal body instance

			if (boneIndex < 0 || boneIndex > Enums::ESEALBONES_MAX)
				return false;	// invalid index

			i32_t boneOffset = this->mSkeleton[boneIndex];	// get bone offset from skeleton array
			if (boneOffset <= 0)
				return false;	// invalid bone pointer

			*out = (CZBodyPart*)PS2Memory::GetEEAddr(boneOffset);	// get bone index from skeleton arra

			return true;
		}

		bool CZSeal::GetBoneWorldTMByIndex(int boneIndex, Mat4x4* out)
		{

			/* get bone body part reference */
			CZBodyPart* pBodyPart = nullptr;
			if (!GetBoneByIndex(boneIndex, &pBodyPart))
				return false;

			/* return the results */
			return pBodyPart->GetWorldTM(this->mMatrix, out);


			/* declare math constants */
			const Mat4x4& modelWorldMatrix = this->mMatrix;
			const Vec3& modelWorldOrigin = modelWorldMatrix.Translation(); //	 Vec3(modelWorldMatrix.m[3][0], modelWorldMatrix.m[3][1], modelWorldMatrix.m[3][2]);

			/* get bone body part reference */
			//	CZBodyPart* pBodyPart = nullptr;
			//	if (!GetBoneByIndex(boneIndex, &pBodyPart))
			//		return false;

			/* get body part node */
			CNode* pBodyPartNode = pBodyPart->GetNode();
			if (!pBodyPartNode)
				return false;	// invalid body part node

			/* get bone world matrix */
			Mat4x4 bodyPartLocalMatrix = pBodyPartNode->GetWorldTM();

			Vec3 tempOrigin; // create temporary origin vector to store result
			Mat4x4 tempMatrix; // create temporary matrix to store result
			bool bFoundParents{ false };
			do
			{
				CZBodyPart* pParentBodyPart = pBodyPart->GetParent();
				if (!pParentBodyPart)
				{
					bFoundParents = true;	// no parent found, exit loop
					break;
				}
				/* get parent body part node */
				CNode* pParentBodyPartNode = pParentBodyPart->GetNode();
				if (!pParentBodyPartNode)
				{
					bFoundParents = true;	// no parent node found, exit loop
					break;
				}

				pBodyPart = pParentBodyPart;	// set parent body part as current body part

				/* get parent bone world matrix */
				Mat4x4 parentLocalMatrix = pParentBodyPartNode->GetWorldTM();
				Vec3 parentLocalOrigin = pParentBodyPartNode->GetWorldPos();

				tempOrigin += parentLocalOrigin;	// add parent origin to temporary origin
				tempMatrix = tempMatrix * parentLocalMatrix;	// multiply parent matrix to temporary matrix

			} while (!bFoundParents);

			*out = tempMatrix * modelWorldMatrix;

			return true;
		}

		bool CZSeal::GetBoneLocationByIndex(const int& boneIndex, Vec3& outPosition)
		{
			Mat4x4 boneWorldMX;
			if (!GetBoneWorldTMByIndex(boneIndex, &boneWorldMX))
				return false;	//	cannot get bone world matrix

			outPosition = boneWorldMX.Translation();	// get bone world position from matrix translation

			return true;
		}

		bool CZSeal::GetBoundingBox(AABB* outBounds)
		{
			if (!this->IsValid() || !this->pNode)
				return false;

			auto pNode = (CNode*)PS2Memory::GetEEAddr(this->pNode);
			if (!pNode)
				return false;

			Vec3 origin = pNode->GetWorldPos();
			AABB bounds = pNode->mAABB;
			bounds.m_min += origin;
			bounds.m_max += origin;

			*outBounds = bounds;

			return true;

			/* get bounds by bones */
			float fMIN = -100000.f;
			float fMAX = 100000.f;
			Vec3 mmin(fMAX, fMAX, fMAX);
			Vec3 mmax(fMIN, fMIN, fMIN);
			for (int i = 0; i < Enums::ESEALBONES_MAX; i++)
			{
				Vec3 bone;
				if (!GetBoneLocationByIndex(i, bone))
					continue;


				if (bone.x < mmin.x)
					mmin.x = bone.x;
				if (bone.y < mmin.y)
					mmin.y = bone.y;
				if (bone.z < mmin.z)
					mmin.z = bone.z;

				//	MAX
				if (bone.x > mmax.x)
					mmax.x = bone.x;
				if (bone.y > mmax.y)
					mmax.y = bone.y;
				if (bone.z > mmax.z)
					mmax.z = bone.z;
			}

			*outBounds = AABB(mmin, mmax);

			return true;
		}

		bool CZSeal::GetEquippedWeapon(CZWeapon& outWeapon)
		{
			/* Get CZKit , reference weapon index , return weapon at index */

			Structs::CZKit mKit = this->mKit;
			const auto& index = mKit.mCurrentWeaponIndex;
			const auto& szArray = mKit.mMaxWeaponIndex;
			if (index < 0 || index >= szArray)
				return false;	//	invalid weapon index


			i32_t pWeapon = 0;
			Enums::EWEAPONEQUIP_INDEX weaponIndex = (Enums::EWEAPONEQUIP_INDEX)index;
			//	switch (weaponIndex)
			//	{
			//		case Enums::EWeaponIndex_Primary: pWeapon = mKit.mPrimaryWeapon; break;
			//		case Enums::EWeaponIndex_Secondary: pWeapon = mKit.mSecondaryWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot1: pWeapon = mKit.mEqSlot1; break;
			//		case Enums::EWeaponIndex_EqSlot2: pWeapon = mKit.mEqSlot2; break;
			//		case Enums::EWeaponIndex_EqSlot3: pWeapon = mKit.mEqSlot3; break;
			//		default: return false;
			//	}

			pWeapon = mKit.pWeapons[weaponIndex];

			if (!pWeapon)
				return false;

			outWeapon = PS2Memory::ReadEE<CZWeapon>(pWeapon);

			return true;
		}

		bool CZSeal::SetEquippedWeapon(const Enums::EWEAPON& newWeapon)
		{
			Structs::CZKit& mKit = this->mKit;
			const auto& index = mKit.mCurrentWeaponIndex;
			const auto& szArray = mKit.mMaxWeaponIndex;
			if (index < 0 || index >= szArray)
				return false;	//	invalid weapon index

			Enums::EWEAPONEQUIP_INDEX weaponIndex = (Enums::EWEAPONEQUIP_INDEX)index;
			//	switch (weaponIndex)
			//	{
			//		case Enums::EWeaponIndex_Primary: mKit.mPrimaryWeapon = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_Secondary: mKit.mSecondaryWeapon = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot1: mKit.mEqSlot1 = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot2: mKit.mEqSlot2 = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot3: mKit.mEqSlot3 = (i32_t)newWeapon; break;
			//		default: return false;
			//	}

			mKit.pWeapons[weaponIndex] = (i32_t)newWeapon;
			
			return true;
		}

		bool CZSeal::SetEquipment(__int32 mPrimary, __int32 mSecondary, __int32 mEq1, __int32 mEq2, __int32 mEq3)
		{
			return false;
		}

		bool CZSeal::GetWeapon(const Enums::EWEAPONEQUIP_INDEX& mSlot, CZWeapon& outWeapon)
		{
			Structs::CZKit& mKit = this->mKit;
			const auto& index = mKit.mCurrentWeaponIndex;
			const auto& szArray = mKit.mMaxWeaponIndex;
			if (index < 0 || index >= szArray)
				return false;

			i32_t pWeapon = 0;
			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: pWeapon = mKit.mPrimaryWeapon; break;
			//		case Enums::EWeaponIndex_Secondary: pWeapon = mKit.mSecondaryWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot1: pWeapon = mKit.mEqSlot1; break;
			//		case Enums::EWeaponIndex_EqSlot2: pWeapon = mKit.mEqSlot2; break;
			//		case Enums::EWeaponIndex_EqSlot3: pWeapon = mKit.mEqSlot3; break;
			//		default: return false;	//	invalid weapon index
			//	}

			pWeapon = mKit.pWeapons[mSlot];
			if (!pWeapon)
				return false;

			outWeapon = PS2Memory::ReadEE<CZWeapon>(pWeapon);

			return true;
		}

		bool CZSeal::SetWeapon(const Enums::EWEAPONEQUIP_INDEX& mSlot, const Enums::EWEAPON& newWeapon)
		{
			Structs::CZKit& mKit = this->mKit;
			const auto& index = mKit.mCurrentWeaponIndex;
			const auto& szArray = mKit.mMaxWeaponIndex;
			if (index < 0 || index >= szArray)
				return false;

			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: mKit.mPrimaryWeapon = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_Secondary: mKit.mSecondaryWeapon = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot1: mKit.mEqSlot1 = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot2: mKit.mEqSlot2 = (i32_t)newWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot3: mKit.mEqSlot3 = (i32_t)newWeapon; break;
			//		default: return false;	//	invalid weapon index
			//	}

			mKit.pWeapons[mSlot] = (i32_t)newWeapon;
			return true;
		}

		bool CZSeal::GetAmmoProperties(const Enums::EWEAPONEQUIP_INDEX& mSlot, CZAmmo& outAmmo)
		{
			Structs::CZKit mKit = this->mKit;
			const auto& index = mKit.mCurrentWeaponIndex;
			const auto& szArray = mKit.mMaxWeaponIndex;
			if (index < 0 || index >= szArray)
				return false;

			i32_t pAmmo = 0;
			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: pAmmo = mKit.mPrimaryAmmoType; break;
			//		case Enums::EWeaponIndex_Secondary: pAmmo = mKit.mSecondaryAmmoType; break;
			//		case Enums::EWeaponIndex_EqSlot1: pAmmo = mKit.mEqSlot1Ammo; break;
			//		case Enums::EWeaponIndex_EqSlot2: pAmmo = mKit.mEqSlot2Ammo; break;
			//		case Enums::EWeaponIndex_EqSlot3: pAmmo = mKit.mEqSlot3Ammo; break;
			//		default: return false;	//	invalid weapon index
			//	}

			pAmmo = mKit.pAmmoTypes[mSlot];
			if (!pAmmo)
				return false;

			outAmmo = PS2Memory::ReadEE<CZAmmo>(pAmmo);

			return true;
		}

		bool CZSeal::SetAmmoProperties(const Enums::EWEAPONEQUIP_INDEX& mSlot, const Enums::EAMMO& newAmmo)
		{
			Structs::CZKit& mKit = this->mKit;
			const auto& index = mKit.mCurrentWeaponIndex;
			const auto& szArray = mKit.mMaxWeaponIndex;
			if (index < 0 || index >= szArray)
				return false;

			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: mKit.mPrimaryAmmoType = (i32_t)newAmmo; break;
			//		case Enums::EWeaponIndex_Secondary: mKit.mSecondaryAmmoType = (i32_t)newAmmo; break;
			//		case Enums::EWeaponIndex_EqSlot1: mKit.mEqSlot1Ammo = (i32_t)newAmmo; break;
			//		case Enums::EWeaponIndex_EqSlot2: mKit.mEqSlot2Ammo = (i32_t)newAmmo; break;
			//		case Enums::EWeaponIndex_EqSlot3: mKit.mEqSlot3Ammo = (i32_t)newAmmo; break;
			//		default: return false;	//	invalid weapon index
			//	}

			mKit.pAmmoTypes[mSlot] = (i32_t)newAmmo;
			
			return true;
		}

		bool CZSeal::GiveWeapon(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newWeaponIndex)
		{
			auto& kit = this->mKit;
			if (mSlot < 0 || mSlot >= kit.mMaxWeaponIndex)
				return false;	//	invalid weapon index


			const auto& weapon = GetWeaponByIndex(newWeaponIndex);
			if (!weapon)	//	check if weapon exists at index
				return false;
			
			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: kit.mPrimaryWeapon = weapon; break;
			//		case Enums::EWeaponIndex_Secondary: kit.mSecondaryWeapon = weapon; break;
			//		case Enums::EWeaponIndex_EqSlot1: kit.mEqSlot1 = weapon; break;
			//		case Enums::EWeaponIndex_EqSlot2: kit.mEqSlot2 = weapon; break;
			//		case Enums::EWeaponIndex_EqSlot3: kit.mEqSlot3 = weapon; break;
			//		default: return false;	//	invalid weapon index
			//	}

			kit.pWeapons[mSlot] = weapon;

			return true;
		}

		bool CZSeal::GiveAmmo(const Enums::EWEAPONEQUIP_INDEX& mSlot, int amount, int mags)
		{
			auto& kit = this->mKit;
			if (mSlot < 0 || mSlot >= kit.mMaxWeaponIndex)
				return false;	//	invalid weapon index

			/* get the current weapon */
			i32_t pWeapon = 0;
			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: pWeapon = kit.mPrimaryWeapon; break;
			//		case Enums::EWeaponIndex_Secondary: pWeapon = kit.mSecondaryWeapon; break;
			//		case Enums::EWeaponIndex_EqSlot1: pWeapon = kit.mEqSlot1; break;
			//		case Enums::EWeaponIndex_EqSlot2: pWeapon = kit.mEqSlot2; break;
			//		case Enums::EWeaponIndex_EqSlot3: pWeapon = kit.mEqSlot3; break;
			//		default: return false;	//	invalid weapon index
			//	}

			pWeapon = kit.pWeapons[mSlot];

			/* verify weapon */
			if (!pWeapon)
				return false;

			/* get weapon properties */
			const auto& weapon = PS2Memory::ReadEE<CZWeapon>(pWeapon);

			/* set ammo for weapons with magazines */
			if (mSlot <= 1)
			{
				for (int i = 0; i < (mags > 0 ? mags : weapon.defaultMags); i++)
				{
					switch (mSlot)
					{
					case Enums::EWeaponIndex_Primary: kit.mPrimaryMags[i] = amount > 0 ? amount : weapon.szMag; break;
					case Enums::EWeaponIndex_Secondary: kit.mSecondaryMags[i] = amount > 0 ? amount : weapon.szMag; break;
						//	case Enums::EWeaponIndex_EqSlot1: kit.mEqSlot1Ammo = amount > 0 ? amount : weapon.szMag; break;
						//	case Enums::EWeaponIndex_EqSlot2: kit.mEqSlot2Ammo = amount > 0 ? amount : weapon.szMag; break;
						//	case Enums::EWeaponIndex_EqSlot3: kit.mEqSlot3Ammo = amount > 0 ? amount : weapon.szMag; break;
					default: return false;	//	invalid weapon index
					}
				}

				/* exit */
				return true;
			}

			/*set ammo for equipment*/
			switch (mSlot)
			{
				case Enums::EWeaponIndex_EqSlot1: kit.mEqSlot1Ammo = amount > 0 ? amount : weapon.szMag; break;
				case Enums::EWeaponIndex_EqSlot2: kit.mEqSlot2Ammo = amount > 0 ? amount : weapon.szMag; break;
				case Enums::EWeaponIndex_EqSlot3: kit.mEqSlot3Ammo = amount > 0 ? amount : weapon.szMag; break;
				default: return false;	//	invalid weapon index
			}

			return true;
		}

		bool CZSeal::GiveFireMode(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newFireModeIndex)
		{
			auto& kit = this->mKit;
			if (mSlot < 0 || mSlot >= kit.mMaxWeaponIndex)
				return false;	//	invalid weapon index

			/* get the current weapon */
			i32_t pWeapon = 0;
			//	switch (mSlot)
			//	{
			//	case Enums::EWeaponIndex_Primary: pWeapon = kit.mPrimaryWeapon; break;
			//	case Enums::EWeaponIndex_Secondary: pWeapon = kit.mSecondaryWeapon; break;
			//	case Enums::EWeaponIndex_EqSlot1: pWeapon = kit.mEqSlot1; break;
			//	case Enums::EWeaponIndex_EqSlot2: pWeapon = kit.mEqSlot2; break;
			//	case Enums::EWeaponIndex_EqSlot3: pWeapon = kit.mEqSlot3; break;
			//	default: return false;	//	invalid weapon index
			//	}

			pWeapon = kit.pWeapons[mSlot];

			/* verify weapon */
			if (!pWeapon)
				return false;

			/* get weapon properties */
			auto weapon = (CZWeapon * )PS2Memory::GetEEAddr(pWeapon);
			if (!weapon)
				return false;

			if ((mSlot == Enums::EWeaponIndex_Primary || mSlot == Enums::EWeaponIndex_Secondary) && newFireModeIndex > 0)
				kit.mWeaponFireTypes[mSlot] = (Enums::EWEAPON_FIREMODE)newFireModeIndex;

			/* set weapon property 
			@ATTN: PERSISTENT*/
			weapon->bHasFireMode[newFireModeIndex] = true;	//	set fire mode at index
		}

		bool CZSeal::GiveAmmoType(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newAmmoIndex)
		{
			auto& kit = this->mKit;
			if (mSlot < 0 || mSlot >= kit.mMaxWeaponIndex)
				return false;	//	invalid weapon index

			const auto& ammo = GetAmmoTypeByIndex(newAmmoIndex);
			if (!ammo)
				return false;	//	check if ammo type exists at index

			//	switch (mSlot)
			//	{
			//		case Enums::EWeaponIndex_Primary: kit.mPrimaryAmmoType = ammo; break;
			//		case Enums::EWeaponIndex_Secondary: kit.mSecondaryAmmoType = ammo; break;
			//		case Enums::EWeaponIndex_EqSlot1: kit.mEqSlot1Ammo = ammo; break;
			//		case Enums::EWeaponIndex_EqSlot2: kit.mEqSlot2Ammo = ammo; break;
			//		case Enums::EWeaponIndex_EqSlot3: kit.mEqSlot3Ammo = ammo; break;
			//		default: return false;	//	invalid weapon index
			//	}

			kit.pAmmoTypes[mSlot] = ammo;

			return true;
		}

		bool CZSeal::GiveLoadout(const Enums::EWEAPONEQUIP_INDEX& mSlot, const int& newWeaponIndex, const int& newAmmoIndex, const int& newFireModeIndex, const int& ammo, const int& mags)
		{
			GiveWeapon(mSlot, newWeaponIndex);
			GiveAmmoType(mSlot, newAmmoIndex);
			GiveAmmo(mSlot, ammo, mags);
			GiveFireMode(mSlot, newFireModeIndex);
			return true;
		}

		bool CZSeal::RefreshLoadout()
		{
			auto& kit = this->mKit;

			for (int i = 0; i <= kit.mMaxWeaponIndex; i++)
				GiveAmmo((Enums::EWEAPONEQUIP_INDEX)i);

			return true;
		}

		void CZSeal::SetAimPoint(const Vec3& newAim)
		{
			this->mAimOrigin = newAim;			
			this->mAimPoint = newAim;			
			this->mPrevAimPoint = newAim;		
			this->mReticlePt = newAim;			
			this->mPrevReticlePt = newAim;		
			//	this->mAimDir = newDir;
			//	this->mAimAngles = newDir;
		}

		bool CZSeal::SetAimTarget(CZSeal* pTarget, bool bVisible, const Enums::ESEALBONES_INDEX& bone)
		{
			/* determine if target & source are valid */
			if (!this->IsValid() || !this->IsAlive() || !pTarget || !pTarget->IsValid() || !pTarget->IsAlive())
				return false;	// invalid source or target entity

			/* determine if target is visible */
			if (bVisible && !pTarget->IsVisible(pTarget))
				return false;	// target failed visibility check

			/* get target bone location */
			Vec3 targetAimPoint;
			if (!pTarget->GetBoneLocationByIndex(bone, targetAimPoint))
				return false;

			/* get direction */
			Vec3 dir = targetAimPoint - this->mAimOrigin;
			
			/* set aim point */
			SetAimPoint(targetAimPoint);

			return true;
		}


		//----------------------------------------------------------------------------------------------------
		//										CZWEAPON
		// - CZWeapon
		//-----------------------------------------------------------------------------------

		std::string CZWeapon::GetName()
		{
			std::string result{};
			i32_t pName = this->pName != 0 ? this->pName : this->pModelName;
			if (!pName || pName <= 0xCC0000)
				return result;

			return (char*)PS2Memory::GetEEAddr(pName);
		}


		//----------------------------------------------------------------------------------------------------
		//										CZWEAPON
		// - CZWeapon
		//-----------------------------------------------------------------------------------

		std::string CZAmmo::GetName()
		{
			std::string result{};
			i32_t pName = pDisplayName != 0 ? pDisplayName : pAmmoName;
			if (!pName || pName <= 0xCC0000)
				return result;

			return (char*)PS2Memory::GetEEAddr(pName);
		}

		//----------------------------------------------------------------------------------------------------
		//										MATCHDATA
		// - MatchData
		//-----------------------------------------------------------------------------------

		bool CZMatchData::isMatchEnded()
		{
			return (PS2Memory::ReadEE<int>(Offsets::o_GameEndAddr) == 0) ? true : false;
		}

		void CZMatchData::ForceStartMatch()
		{
			//
		}

		bool CZMatchData::GetEntities(std::vector<CZSeal*>* entities)
		{
			std::vector<CZSeal*> result{};

			const auto arr = PS2Memory::ReadEE<ZArray<CZSeal*>>(Offsets::o_SealArray).Data();

			for (auto ent : arr)
			{
				if (!ent->IsValid())
					continue;

				//	CNode* pNode = ent->GetSealObject();
				//	if (!pNode)
				//		continue;	//	invalid node, skip
				//	
				//	if (!pNode->m_hasVisuals)
				//		continue;

				result.push_back(ent);
			}

			*entities = result;

			return result.size() > 0;
		}

		bool CZMatchData::GetPlayers(std::vector<CZSeal*>* p)
		{
			std::vector<CZSeal*> entities{};
			if (!GetEntities(&entities))
				return false;

			std::vector<CZSeal*> players{};
			for (auto& ent : entities)
			{
				if (!ent->IsValid() || !ent->IsPlayerEntity())
					continue;
				players.push_back(ent);
			}

			*p = players;

			return players.size() > 0;
		}

		std::vector<CZSeal*> CZMatchData::GetAlivePlayers()
		{
			std::vector<CZSeal*> result;

			std::vector<CZSeal*> players;
			if (GetPlayers(&players))
			{
				for (auto& player : players)
				{
					if (!player->IsAlive())
						continue;

					result.push_back(player);
				}
			}

			return result;
		}

		bool CZMatchData::GetAllPickups(std::vector<CPickup*>* pickups)
		{
			std::vector<CPickup*> result{};

			const auto arr = PS2Memory::ReadEE<ZArray<CPickup*>>(Offsets::o_PickupArray).Data();
			if (arr.size() <= 0)
				return false;

			for (auto pickup : arr)
				result.push_back(pickup);

			*pickups = result;

			return result.size() > 0;
		}
		
		bool CZMatchData::GetWeaponPickups(std::vector<CPickup*>* pickups)
		{
			std::vector<CPickup*> result{};
			std::vector<CPickup*> pickups_buff{};

			if (!GetAllPickups(&pickups_buff))
				return false;

			for (const auto& pickup : pickups_buff)
			{
				if (pickup->mType != Enums::PICKUP_TYPE_WEAPON)
					continue;

				result.push_back(pickup);
			}

			*pickups = result;

			return result.size() > 0;
		}

		bool CZMatchData::GetAmmoPickups(std::vector<CPickup*>* pickups)
		{
			std::vector<CPickup*> result{};
			std::vector<CPickup*> pickups_buff{};

			if (!GetAllPickups(&pickups_buff))
				return false;

			for (const auto& pickup : pickups_buff)
			{
				if (pickup->mType != Enums::PICKUP_TYPE_AMMO)
					continue;

				result.push_back(pickup);
			}

			*pickups = result;

			return result.size() > 0;
		}
	}
}
#pragma pack(pop)




/*

//----------------------------------------------------------------------------------------------------
//										CWEAPON
// - CWeapon
//-----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
//										CZSealBody
// - CPlayer
//-----------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Returns Class Pointer Status
bool CZSealBody::IsValid()
{
	return ((unsigned int)this->pad_0000 == 0x000000 || this->NamePTR == NULL || this->CPlayerMovement == nullptr || this->TeamID == NULL) ? FALSE : TRUE;
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Returns Players Alive State
bool CZSealBody::IsAlive()
{
	return (this->Health > 0.0f) ? TRUE : FALSE;
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Returns a Pointer to CPlayerPhysics Class
CZSealObject* CZSealBody::PlayerPhysicsPtr()
{
	return (CZSealObject*)((unsigned int)this->CPlayerMovement + g_PS2Mem->BasePS2MemorySpace);
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Returns Player Name
std::string CZSealBody::GetPlayerName()
{
	return (char*)(NamePTR + g_PS2Mem->BasePS2MemorySpace);
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Returns Player Team Name
std::string CZSealBody::GetTeamName()
{
	switch (this->TeamID)
	{
	case (SEALS):		return "SEAL";
	case (TERRORIST):	return "TERRORIST";
	case (SPECTATOR):	return "SPECTATOR";
	case (SP_ABLE):		return	"SEALS - ABLE Team";
	case (SP_BRAVO):	return	"SEALS - BRAVO Team";
	case (SP_ENEMY_A):	return	"Hostile";
	case (SP_ENEMY_B):	return	"Hostile";
	case (SP_ENEMY_C):	return	"Hostile";
	case (SP_ENEMY_D):	return	"Hostile";
	case (SP_ENEMY_E):	return	"Hostile";
	case (SP_ENEMY_F):	return	"Hostile";
	case (SP_ENEMY_G):	return	"Hostile";
	case (SP_ENEMY_H):	return	"Hostile";
	case (SP_ENEMY_I):	return	"Hostile";
	}
	return std::to_string(this->TeamID);
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Returns Weapon Name
std::string CZSealBody::GetWeaponName(unsigned int Weapon)
{
	switch (Weapon)
	{
		case(EPrimaryWeapon::AR_552):		return "552";
		case(EPrimaryWeapon::SMG_9MM):		return "9MM SUB";
		case(ESecondaryWeapon::PISTOL_9MM): return "9MM PISTOL";
	}

	char data[0x56];
	const char* data2 = "%08X";
	sprintf_s(data, data2, Weapon);
	return std::to_string(Weapon);
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
void CZSealBody::GiveAmmo(int amount, int mags)
{
	if (mags <= NULL || mags > 10)
		mags = 3;

	for (int i = NULL; i < mags; i++)
	{
		this->PrimaryMag[i] = amount;
		this->SecondaryMag[i] = amount;
	}
	this->EquipmentSlot1 = NULL;
	this->EquipmentSlot2 = NULL;
	this->EquipmentSlot3 = NULL;
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Replaces current weapon in slot with input Weapon
void CZSealBody::GiveWeapon(unsigned int Slot, unsigned int Weapon)
{
	// Intended usage
	switch (Slot)
	{
		case (EWeaponSlot::Primary):		this->PrimaryWeapon		= (EPrimaryWeapon)Weapon;	break;
		case (EWeaponSlot::Secondary):		this->SecondaryWeapon	= (ESecondaryWeapon)Weapon;	break;
		case (EWeaponSlot::EqSlot1):		this->EqSlot1			= (EEquipment)Weapon;	break;
		case (EWeaponSlot::EqSlot2):		this->EqSlot2			= (EEquipment)Weapon;	break;
		case (EWeaponSlot::EqSlot3):		this->EqSlot3			= (EEquipment)Weapon;	break;
	}
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
void CZSealBody::RemoveWeaponsandAmmo()
{
	this->PrimaryWeapon		= (EPrimaryWeapon)NULL;
	this->SecondaryWeapon	= (ESecondaryWeapon)NULL;
	this->EqSlot1			= (EEquipment)NULL;
	this->EqSlot2			= (EEquipment)NULL;
	this->EqSlot3			= (EEquipment)NULL;

	for (int i = NULL; i < 10; i++)
	{
		this->PrimaryMag[i] = NULL;
		this->SecondaryMag[i] = NULL;
	}
	this->EquipmentSlot1 = NULL;
	this->EquipmentSlot2 = NULL;
	this->EquipmentSlot3 = NULL;
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Teleports this entity to desired position
void CZSealBody::Teleport(Vec3 Pos)
{
	unsigned int test = (unsigned int)this->CPlayerMovement;
	auto offset = (test + g_PS2Mem->BasePS2MemorySpace);
	auto Movement = (CZSealObject*)offset;
	Movement->absPosition = Pos;
}


///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Changes this entity to team to desired team
void CZSealBody::ChangeTeams(ETeam newTeam)
{
	this->TeamID = newTeam;
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// Sets this entity health (value from 0 - 100)
void CZSealBody::SetHealth(float newHealth)
{
	if (newHealth > 100.f )
		newHealth = 100.0f;
	else if (newHealth < 1.0f)
		newHealth = 0.0f;
	this->Health = newHealth / 100.f;
}

///---------------------------------------------------------------------------------------------------
//	[CPLAYER]
// generates a log containing important player data
// NOTE: Ends with 2New Line
std::string CZSealBody::LogData()
{
	Offsets offsets;
	auto SEAL = (CZSealBody*)offsets.SEALPointer;
	float distance;
	if (SEAL != this)
		distance = g_PS2Mem->Tools->GetDistanceTo3DObject(SEAL->Position, this->Position);	//	@todo: Tools might be a nullptr here
	else
		distance = 0.0f;

	char data[0x256];
	const char* data2 = "PlayerObjectBase: %llX\nPlayerName: %s\nTeamName: %s\nPrimary Weapon: %s	|	PrimaryAmmo: %i\nSecondary Weapon: %s	|	SecondaryAmmo: %i\nHealth: %0.f\nPosition: { %f, %f, %f }\nDistance: { %f }\n\n";
	sprintf_s(data, data2, this, this->GetPlayerName().c_str(), this->GetTeamName().c_str(),
		GetWeaponName(this->PrimaryWeapon).c_str(), this->PrimaryMag[0],
		GetWeaponName(this->SecondaryWeapon).c_str(), this->SecondaryMag[0],
		(this->Health * 100.f),
		this->Position.x, this->Position.y, this->Position.z, distance);
	return data;
}

*/

///	EXAMPLE ImGui Project

	/*
	//	Debug Weapon Manager
	//	Will not work in this scope!
	//	Does not work in current state, enum values need to be passed but instead is passing enum positions
	CWeapon WeaponData;
	void WeaponManager(CPlayer* player)
	{
		ImGui::Spacing();
		ImGui::Separator();
		ImGui::TextCentered("[WEAPON MANAGER]", TRUE, ImColor(0, 255, 255, 200));
		ImGui::Separator();
		ImGui::SetNextItemWidth(100);
		ImGui::Combo("##jfhgjdflkhklsdh", (int*)&WeaponData.e_selectedSlot, WeaponData.AvailSlots, IM_ARRAYSIZE(WeaponData.AvailSlots));
		ImGui::SameLine();
		ImGui::SetNextItemWidth(100);
		switch (WeaponData.e_selectedSlot)
		{
			case(0): ImGui::Combo("##jfhgjdflkhklsdh1", (int*)&WeaponData.e_selected_Primary, WeaponData.PrimaryWeapons, IM_ARRAYSIZE(WeaponData.PrimaryWeapons)); break;
			case(1): ImGui::Combo("##kdgdsazhljfna", (int*)&WeaponData.e_selected_Secondary, WeaponData.SecondaryWeapons, IM_ARRAYSIZE(WeaponData.SecondaryWeapons)); break;
			case(2): ImGui::Combo("##zjdfhbadeh", (int*)&WeaponData.e_selected_Equipment, WeaponData.EquipmentWeapon, IM_ARRAYSIZE(WeaponData.EquipmentWeapon)); break;
			case(3): ImGui::Combo("##hsdfgjsytkiet", (int*)&WeaponData.e_selected_Equipment, WeaponData.EquipmentWeapon, IM_ARRAYSIZE(WeaponData.EquipmentWeapon)); break;
			case(4): ImGui::Combo("##gjnkdtoythmyuk", (int*)&WeaponData.e_selected_Equipment, WeaponData.EquipmentWeapon, IM_ARRAYSIZE(WeaponData.EquipmentWeapon)); break;
		}
		if (ImGui::Button("GIVE WEAPON", ImVec2(ImGui::GetContentRegionAvail().x, 0)))
		{
			switch (WeaponData.e_selectedSlot)
			{
				case 0:        player->GiveWeapon(WeaponData.e_selectedSlot, WeaponData.e_selected_Primary); break;
				case 1:        player->GiveWeapon(WeaponData.e_selectedSlot, WeaponData.e_selected_Secondary); break;
				case 2:        player->GiveWeapon(WeaponData.e_selectedSlot, WeaponData.e_selected_Equipment); break;
				case 3:        player->GiveWeapon(WeaponData.e_selectedSlot, WeaponData.e_selected_Equipment); break;
				case 4:        player->GiveWeapon(WeaponData.e_selectedSlot, WeaponData.e_selected_Equipment); break;
			}
		}
	}

	void test_debug_menu()
	{
		SOCOM1::Offsets offsets;
		SOCOM1::CPlayer* PLAYER = (CPlayer*)offsets.SEALPointer;
		SOCOM1::MatchData MATCH;

		if (ImGui::Button("Test Read Memory", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			auto address = offsets.FrameRate1;

			auto value = g_Engine->PS2Read<int>(offsets.FrameRate1);

			g_Console->printdbg("Test Read Memory:\nFrameRate1: [%08X]\nVALUE: [%i]\n\n", Console::Colors::blue, address, value);
		}

		if (ImGui::Button("Test Write Memory", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			g_Engine->PS2Write<int>(offsets.FrameRate1, 30);

			g_Engine->PS2Write<int>(offsets.FrameRate2, 30);

			g_Console->printdbg("Test Write Memory:\nFrameRate1: [%i]\nFrameRate2: [%i]\n\n", Console::Colors::blue, g_Engine->PS2Read<int>(offsets.FrameRate1), g_Engine->PS2Read<int>(offsets.FrameRate2));

		}

		if (ImGui::Button("Test ResolvePointer", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			if (PLAYER->IsValid()) {

				CPlayer::CPlayerPhysics* move = PLAYER->PlayerPhysicsPtr();

				g_Console->printdbg("%s", Console::Colors::DEFAULT, PLAYER->LogData().c_str());
			}
			else
				g_Console->printdbg("[!] INVALID PLAYER OBJECT\n", Console::Colors::red);
		}

		if (ImGui::Button("Display Offsets Data", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
			g_Console->printdbg("Dumping Offset Data:\n%s", Console::Colors::DEFAULT, offsets.LogData().c_str());

		if (ImGui::Button("Check isValid", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			bool result = PLAYER->IsValid();

			switch (result) {

			case (TRUE):	g_Console->printdbg("isValid: [%i]\n", Console::Colors::yellow, result); break;

			case (FALSE):	g_Console->printdbg("isValid: [%i]\n", Console::Colors::red, result); break;
			}
		}

		if (ImGui::Button("Dump Player Data", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			if (PLAYER->IsValid())
				g_Console->printdbg("%s", Console::Colors::DEFAULT, PLAYER->LogData().c_str());
			else
				g_Console->printdbg("[!] INVALID PLAYER OBJECT\n", Console::Colors::red);
		}

		if (ImGui::Button("Give 552", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			if (PLAYER->IsValid()) {
				//player->PrimaryWeapon = CPlayer::CWeapon::AR_552;
				PLAYER->PrimaryWeapon = CWeapon::AR_552;
				for (int i = 0; i < 10; i++)
					PLAYER->PrimaryMag[i] = 1337;
			}
			else
				g_Console->printdbg("[!] INVALID PLAYER OBJECT\n", Console::Colors::red);
		}

		if (ImGui::Button("Dump Entity Array", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			std::vector<SOCOM1::CPlayer*> ent = MATCH.GetPlayers();

			if (!ent.empty()) {

				for (int i = 0; i < ent.size(); i++)
					g_Console->printdbg("%s", Console::Colors::DEFAULT, ent[i]->LogData().c_str());

			}

		}

		if (ImGui::Button("Telpeort All Entities", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
		{
			if (PLAYER->IsValid())
			{
				std::vector<SOCOM1::CPlayer*> ent = MATCH.GetPlayers();

				if (!ent.empty()) {

					for (int i = 0; i < ent.size(); i++) {

						float distance = PLAYER->GetDistanceTo3DObject(PLAYER->Position, ent[i]->Position);
						g_Console->printdbg("Teleporting Entity:\n- Name: %s\n - Position: { %0.2f, %0.2f, %0.2f }\n - Distance: %0.0fm\n\n", Console::Colors::DEFAULT, ent[i]->GetPlayerName().c_str(), ent[i]->Position.x, ent[i]->Position.y, ent[i]->Position.z, distance);
						ent[i]->Teleport(PLAYER->Position);
					}
				}
			}
		}

		if (ImGui::Button("Dump Match Data", ImVec2(ImGui::GetWindowContentRegionWidth(), 20)))
			g_Console->printdbg("IsMatchEnded: [%i]\n\n", Console::Colors::yellow, MATCH.isMatchEnded());

		if (PLAYER->IsValid())
			WeaponManager(PLAYER);
	}
	*/