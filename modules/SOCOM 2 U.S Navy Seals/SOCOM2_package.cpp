#pragma once
#include "SOCOM2_package.h"

/**
 * Name: SOCOM 2
 * Platform: PlayStation 2
 * PCSX2 Version: 1.7 beta
 * Author: NightFyre
*/

#pragma pack(push, 0x01)
namespace PlayStation2::SOCOM2
{

	//----------------------------------------------------------------------------------------------------
	//										GLOBALS
	//-----------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------------
	std::string GetWeaponName(i32_t Weapon)
	{
		switch (Weapon)
		{
			//	Primaries
		case EWeapon_P_M4A1:				return "M4A1";
		case EWeapon_P_M4A1_M203:			return "M4A1-M203";
		case EWeapon_P_M4A1_SD:				return "M4A1 SD";
		case EWeapon_P_M16A2:				return "M16A2";
		case EWeapon_P_M16A2_M203:			return "M16A2-M203";
		case EWeapon_P_IW80:				return "IW-80 A2";
		case EWeapon_P_OICW:				return "OICW";
		case EWeapon_P_HK5:					return "HK5";
		case EWeapon_P_HK5SD:				return "HK5SD";
		case EWeapon_P_HK5K:				return "HK5K";
		case EWeapon_P_SMG_9MMSUB:			return "9mm SUB";
		case EWeapon_P_F90:					return "F90";
		case EWeapon_P_M3_12Gauge:			return "M3 12-Guage";
		case EWeapon_P_M79:					return "M79";
		case EWeapon_P_MGL:					return "MGL";
		case EWeapon_P_M87ELR:				return "M87ELR";
		case EWeapon_P_M82A1A:				return "M82A1A";

			// Secondaries
		case EWeapon_S_DE50:				return "DE .50";
		case EWeapon_S_M11:					return "M11";
		case EWeapon_S_SP10:				return "SP-10";
		case EWeapon_S_Mark23:				return "Mark23";
		case EWeapon_S_Mark23_SD:			return "Mark23SD";
		case EWeapon_S_Pistol_226:			return "226";
		case EWeapon_S_Pistol_9MM:			return "9mm Pistol";
		case EWeapon_S_Model18:				return "Model 18";

			// Equipment
		case EWeapon_EQ_NONE:				return "NONE";
		case EWeapon_EQ_AmmoReserve:		return "2x Ammo";
		case EWeapon_EQ_Frag:				return "Frag";
		case EWeapon_EQ_HE:					return "HE";
		case EWeapon_EQ_Smoke:				return "AN-M8";
		case EWeapon_EQ_RedSmoke:			return "RED AN-M8";
		case EWeapon_EQ_Flashbang:			return "Flashbang";
		case EWeapon_EQ_Claymore:			return "Claymore";
		case EWeapon_EQ_PMN_Mine:			return "PMN";
		case EWeapon_EQ_AT4Heat:			return "AT4 Heat";
		case EWeapon_EQ_AT4Round:			return "AT4 Round";
		case EWeapon_EQ_RPG7:				return "RPG-7";
		case EWeapon_EQ_RPGRound:			return "RPG-7 Round";
		case EWeapon_EQ_Satchel:			return "Satchel";
		case EWeapon_EQ_Satchel_a:			return "Satchel A";
		case EWeapon_EQ_OICW_Frag:			return "OICW Frag";
		case EWeapon_EQ_OICW_HE:			return "OICW HE";
		case EWeapon_EQ_OICW_Smoke:			return "OICW Smoke";
		case EWeapon_EQ_M79_Frag:			return "M79 Frag";
		case EWeapon_EQ_M79_HE:				return "M79 HE";
		case EWeapon_EQ_M79_Smoke:			return "M79 Smoke";
		case EWeapon_EQ_MGL_Frag:			return "MGL Frag";
		case EWeapon_EQ_MGL_HE:				return "MGL HE";
		case EWeapon_EQ_MGL_Smoke:			return "MGL Smoke";
		case EWeapon_EQ_ThermalScope:		return "Thermal Scope";
		case EWeapon_EQ_Binoculars:			return "Binoculars";
		}

		//	char data[0x56];
		//	const char* data2 = "%08X";
		//	sprintf_s(data, data2, Weapon);
		return std::to_string(Weapon);
	}


	//---------------------------------------------------------------------------------------------------
	std::string GetAmmoTypeName(i32_t AmmoType)
	{
		switch (AmmoType)
		{
		case (AR_556):			return "5.56x45";
		case (SMG_9mm):			return "9x19";
		case (PISTOL_45ACP):	return ".45 ACP";
		case (M67_Round):		return "M67 FRAG";
		case (HE_Round):		return "HE FRAG";
		case (Flash_Round):		return "FLASHBANG";
		case (ANM8_Smoke):		return "AN-M8 SMOKE";
		case (C4_Round):		return "C4";
		case (RPG_Round):		return "RPG";
		case (M87ELR_Round):	return "";
		case (Unknown_Round1):	return "";
		}

		//	char data[0x56];
		//	const char* data2 = "%08X";
		//	sprintf_s(data, data2, AmmoType);
		return std::to_string(AmmoType);
	}

	std::string GetTeamNameByID(int teamid)
	{
		switch ((ETeam)teamid)
		{
		case ETeam::SEALS:			return	"SEAL";
		case ETeam::TERRORIST:		return	"TERRORIST";
		case ETeam::SPECTATOR:		return	"SPECTATOR";
		case ETeam::SP_ABLE:		return	"SEALS - ABLE TEAM";
		case ETeam::SP_BRAVO:		return	"SEALS - BRAVO TEAM";
		default:					return	"AI";
		}

		return "N/A";
	}

	//	bool GetBoneNameByIndex(int index, std::string& outResult)
	//	{
	//		return false;
	//	}
	//	
	//	bool GetBoneTransformByIndex(int index, Mat4x4& outResult)
	//	{
	//		return false;
	//	}

	//----------------------------------------------------------------------------------------------------
	//										DUMPER
	//-----------------------------------------------------------------------------------
	namespace Dumper
	{
		void Dumper::DumpWeaponStats()
		{
			/* Get EEMem Base Address */
			const __int64& _EE = PS2Memory::GetEEBase();
			if (!_EE)
				return;

			/* get weapon pointers */
			//	ZListWeapons* weaponMan = reinterpret_cast<ZListWeapons*>(_EE + Offsets::p_WeaponManager);
			//	if (!weaponMan)
			//		return;

			/* read into local process memory */
			ZListWeapons weaponMan = PS2Memory::ReadEE<ZListWeapons>(Offsets::p_WeaponManager);

			int szArrays[] = { 5, 6, 43, 25, 7 };

			for (int i = 0; i < 5; i++)	/* iterate weapon lists in ZListWeapons */
			{
				for (int j = 0; j < szArrays[i]; j++)	/* iterate through size of each array */
				{
					CZWeapon* weapon = nullptr;
					switch (i)
					{
					case 0: weapon = &weaponMan.mList1[j]; break;
					case 1: weapon = &weaponMan.mList2[j]; break;
					case 2: weapon = &weaponMan.mList3[j]; break;
					case 3: weapon = &weaponMan.mList4[j]; break;
					case 4: weapon = &weaponMan.mList5[j]; break;
					}
					if (!weapon || weapon->vfTable != 0x434D30)	/* */
						continue;

					/* get names */
					std::string name = (char*)PS2Memory::GetEEAddr(weapon->pDisplayName);
					std::string name_internal = (char*)PS2Memory::GetEEAddr(weapon->pName);
					std::string name_icon = (char*)PS2Memory::GetEEAddr(weapon->pIconName);
					std::string name_bullet = (char*)PS2Memory::GetEEAddr(weapon->pBulletImpactName);
					std::string name_ammo = "N/A";

					/* Get Ammo Type */
					int szAmmo_types = weapon->mLegalAmmoList.Count();	/* log count of ammo types */
					std::vector<CZAmmo*> ammo = weapon->mLegalAmmoList.Data();
					if (szAmmo_types > 0 && ammo.size() > 0)
					{
						/* grab names from first ammo type index */
						name_ammo = (char*)PS2Memory::GetEEAddr(ammo[0]->pDisplayName);
					}

					/* |DisplayName| Internal Name| Icon| BulletMark| MaxHitDistance| MagazineAmmoAmount| FireRate| DamageModifier| Recoil| RecoilResetDelay| Bloom| BloomResetTimer| WeaponId| */
					//	Console::LogMsg("|%s| %s| %s| %s| %s| %.0f| %d| %.2f| %.2f| %.0f| %.0f| %.0f| %.0f| 0x%08X\n", 
					//		name.c_str(),					//	0x08	| char*
					//		name_internal.c_str(), 			//	0x04	| char*
					//		name_icon.c_str(),				//	0x14	| char*
					//		name_bullet.c_str(),			//	0x20	| char*
					//		name_ammo.c_str(),				//	0xC4	| ZArray<CZAmmo*>
					//		weapon->mMaxRange,				//	0x3C	| float
					//		weapon->szMag,					//	0x28	| __int32
					//		weapon->mFireWaitTime,			//	0x50	| float
					//		weapon->mDamageModifier,		//	0x64	| float
					//		weapon->mRecoil,				//	0x100	| float
					//		weapon->mRecoilResetDelay,		//	0xFC	| float
					//		weapon->mBloom,					//	0xF8	| float
					//		weapon->mBloomResetTimer,		//	0x130	| float
					//		weapon->mID						//	0x7C	| __int32
					//	);

					/* dump pointers */
					if (ammo.size() > 0)
						Console::LogMsg("%s: 0x%08X\n-\t%s: 0x%08X\n\n", name.c_str(), (weapon - _EE), name_ammo.c_str(), (ammo[0] - _EE));
					else
						Console::LogMsg("%s: 0x%08X\n\n", name.c_str(), (weapon - _EE));
				}
			}
		}

		void Dumper::DumpAmmoStats()
		{
			/* Get EEMem Base Address */
			const __int64& _EE = PS2Memory::GetEEBase();
			if (!_EE)
				return;

			/* Get Ammo Array Base Address "9x19mm" */
			__int64 pAmmoMan = _EE + Offsets::p_AmmoManager;
			if (!pAmmoMan)
				return;

			/* iterate through size of array */
			for (int i = 0; i < 39; i++)
			{
				/* get ammo object reference */
				CZAmmo* pAmmo = reinterpret_cast<CZAmmo*>(pAmmoMan + (i * sizeof(CZAmmo)));
				if (!pAmmo)
					continue;

				/* get names */
				std::string name = (char*)PS2Memory::GetEEAddr(pAmmo->pDisplayName);
				std::string name_internal = (char*)PS2Memory::GetEEAddr(pAmmo->pName);

				/* |DisplayName| Internal Name| ImpactDamage| Stun| Piercing| ExplosionDamage| ExplosionRadius| AmmoId| */
				//	Console::LogMsg("|%s| %s| %.0f| %.0f| %.0f| %.0f| %.0f| 0x%08X\n", 
				//		name.c_str(),					//	0x08	| char*
				//		name_internal.c_str(), 			//	0x04	| char*
				//		pAmmo->mImpactDmg,				//	0x0C	| float
				//		pAmmo->mStun,					//	0x10	| float
				//		pAmmo->mPiercing,				//	0x14	| float
				//		pAmmo->mExplosionDmg,			//	0x18	| float
				//		pAmmo->mExplosionRadius,		//	0x1C	| float
				//		pAmmo->mID						//	0x30	| __int32
				//	);

				/* dump pointers */
				Console::LogMsg("%s: 0x%08X\n", name.c_str(), (pAmmo - _EE));
			}
		}

		void Dumper::DumpBoneNames()
		{
			std::vector<std::string> partNames;	//	bone names

			/* get local seal object */
			CZSealBody* pSealBody = CZSealBody::GetDefaultInstance();
			if (!pSealBody)
				return;

			/* get body part array */
			static const int szBodyParts = 0x20;
			for (int i = 0; i < szBodyParts; i++)
			{
				/* get body part offset */
				i32_t iBodyPart = pSealBody->mSkeleton[i];
				if (iBodyPart == 0)
					continue; // skip null body parts

				/* get body part class instance */
				auto pBodyPart = (CZBodyPart*)PS2Memory::GetEEAddr(iBodyPart);
				if (!pBodyPart)
					continue; // skip null body part pointers

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
			
				Console::LogMsg("[%d] %s\n", index, name.c_str());
			}
			Console::LogMsg("[+] finished dumping bones with count %d\n", partNames.size());

			/* create enum list for bones */
			//	Console::LogMsg("enum ESEALBONES_INDEX : int\n{\n");
			//	for (auto& name : partNames)
			//		Console::LogMsg("\tESEALBONES_%s,\n", name.c_str());
			//	Console::LogMsg("};\n\n");
		}

		void DumpBoneHierarchy()
		{
			/*

				std::vector<std::pair<std::pair<std::string, Vec3> , std::vector<std::string, Vec3>>>

				[0]bone_name -> bone_origin
				[1]bone_name -> bone_origin
				- [0]parent_bone_name -> parent_bone_origin
				- - [1]parent_bone_name -> parent_bone_origin
				- - - [2]parent_bone_name -> parent_bone_origin
				- - - - [3]parent_bone_name -> parent_bone_origin
				[2]bone_name -> bone_origin
				- [0]parent_bone_name -> parent_bone_origin
				- - [1]parent_bone_name -> parent_bone_origin
				- - - [2]parent_bone_name -> parent_bone_origin
				[3]bone_name -> bone_origin




			*/

			std::vector<Mat4x4> vBoneMatrices;	//	bone matrices
			std::vector< std::pair <
				std::pair< std::string, Vec3 >, 	//	bone_name -> bone_origin
				std::vector< std::pair< std::string, Vec3 > >	// parent bones array of names and origins
			>	// ~std::pair
			> vParts;	//	bone_name -> bone_origin , 
			//	std::pair<std::vector<std::pair<std::string, Vec3>>, std::vector<std::pair<std::string, Vec3>>> parts;	// pair of part name and origins
			/* get local seal object */
			CZSealBody* pSealBody = CZSealBody::GetDefaultInstance();
			if (!pSealBody)
				return;

			Vec3 origin = pSealBody->GetOrigin();	// get seal body origin
			Console::LogMsg("Dumping Bone Names & Positions for Seal Body @ origin { %.2f, %.2f, %.2f }\n", origin.x, origin.y, origin.z);

			/* get body part array */
			static const int szBodyParts = 0x20;
			for (int i = 0; i < szBodyParts; i++)
			{
				/* define parts storage container  */
				std::pair<
					std::pair< std::string, Vec3 >,		// pair of part name and origin
					std::vector< std::pair< std::string, Vec3 > >	// parent bones array of names and origins
				> parts;

				/* get body part offset */
				i32_t iBodyPart = pSealBody->mSkeleton[i];
				if (iBodyPart == 0)
					continue; // skip null body parts

				/* get body part class instance */
				auto pBodyPart = (CZBodyPart*)PS2Memory::GetEEAddr(iBodyPart);
				if (!pBodyPart)
					continue; // skip null body part pointers

				/* get bone name */
				std::string partName = pBodyPart->GetName();
				if (partName.empty())
					continue; // skip empty names

				/* set first pair in parts storage container */
				parts.first =
				{
					partName,				// part name
					pBodyPart->GetOrigin()	// part origin
				};

				Mat4x4 boneMatrix;	// create bone matrix
				pBodyPart->GetLocalTM(&boneMatrix);
				vBoneMatrices.push_back(boneMatrix);

				/* get parent bones */
				bool bFoundParents{ false };
				do
				{
					/* get parent part */
					pBodyPart = pBodyPart->GetParent();
					if (!pBodyPart)
					{
						bFoundParents = true; // no parent found, exit loop
						break;
					}

					/* get parent name */

					parts.second.push_back(
						{
							pBodyPart->GetName(),		// get parent name
							pBodyPart->GetOrigin()		// get parent origin
						}
					);	// add parent data to list

				} while (!bFoundParents);

				// add to main parts list
				vParts.push_back(parts);
			}

			DWORD boneIndex = -1;
			for (auto& part : vParts)
			{
				/*
					std::pair <
						std::pair< std::string, Vec3 >, 	//	bone_name -> bone_origin
						std::vector< std::pair< std::string, Vec3 > >
				*/

				/*
				* part.first = base bone -> string, Vec3
					- part.first = base bone name
					- part.second = base bone origin

				* part.second = parent bone std::vector<string, Vec3>
				*/
				boneIndex++;

				Console::LogMsg(
					"[%d] %s\t-> localOrigin: { x: %.2f,\ty: %.2f,\tz: %.2f }\n",
					boneIndex,
					part.first.first.c_str(),
					part.first.second.x, part.first.second.y, part.first.second.z
				);

				DWORD parentIndex = -1;
				for (auto& parentPart : part.second)
				{
					parentIndex++;
					Console::LogMsg(
						"- parent[%d]: %s\t-> localOrigin: { x: %.2f,\ty: %.2f,\tz: %.2f }\n",
						parentIndex,
						parentPart.first.c_str(),
						parentPart.second.x, parentPart.second.y, parentPart.second.z
					);
				}

				Console::LogMsg(
					"- BoneMatrix:\n"
					"\t- [x]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n"
					"\t- [y]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n"
					"\t- [z]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n"
					"\t- [w]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n",
					vBoneMatrices[boneIndex].m[0][0], vBoneMatrices[boneIndex].m[0][1], vBoneMatrices[boneIndex].m[0][2], vBoneMatrices[boneIndex].m[0][3],
					vBoneMatrices[boneIndex].m[1][0], vBoneMatrices[boneIndex].m[1][1], vBoneMatrices[boneIndex].m[1][2], vBoneMatrices[boneIndex].m[1][3],
					vBoneMatrices[boneIndex].m[2][0], vBoneMatrices[boneIndex].m[2][1], vBoneMatrices[boneIndex].m[2][2], vBoneMatrices[boneIndex].m[2][3],
					vBoneMatrices[boneIndex].m[3][0], vBoneMatrices[boneIndex].m[3][1], vBoneMatrices[boneIndex].m[3][2], vBoneMatrices[boneIndex].m[3][3]
				);


				Mat4x4 boneWorldMatrix;
				if (pSealBody->GetBoneWorldTM(boneIndex, &boneWorldMatrix))
				{
					Console::LogMsg(
						"- BoneWorldMatrix:\n"
						"\t- [x]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n"
						"\t- [y]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n"
						"\t- [z]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n"
						"\t- [w]: { x: %.2f,\ty: %.2f,\tz: %.2f, w:\t%.2f }\n",
						boneWorldMatrix.m[0][0], boneWorldMatrix.m[0][1], boneWorldMatrix.m[0][2], boneWorldMatrix.m[0][3],
						boneWorldMatrix.m[1][0], boneWorldMatrix.m[1][1], boneWorldMatrix.m[1][2], boneWorldMatrix.m[1][3],
						boneWorldMatrix.m[2][0], boneWorldMatrix.m[2][1], boneWorldMatrix.m[2][2], boneWorldMatrix.m[2][3],
						boneWorldMatrix.m[3][0], boneWorldMatrix.m[3][1], boneWorldMatrix.m[3][2], boneWorldMatrix.m[3][3]
					);
				}
			}
		}
	
	}

	//----------------------------------------------------------------------------------------------------
	//										OFFSETS
	//-----------------------------------------------------------------------------------
	/*
		//---------------------------------------------------------------------------------------------------
		std::string Offsets::LogData()
		{

			char data[0x1024];
			const char* data2 = "%llX	0x%08X	:	%s\n";
			std::string result;
			for (int i = 0; i < OffsetArray.size(); i++) {
				sprintf_s(data, data2, PS2Memory::GetEEAddr(OffsetArray[i]),PS2Memory::ReadLong<int>(PS2Memory::GetEEAddr(OffsetArray[i])), names[i].c_str());
				result += data;
			}
			return (result += "\n");
		}

		//---------------------------------------------------------------------------------------------------
		std::vector<class CPlayer*> Offsets::GetEntityArray()
		{
			return CZMatchData::GetPlayers();
		}
	*/



	//----------------------------------------------------------------------------------------------------
	//										STRUCTS
	//-----------------------------------------------------------------------------------

#pragma region // STRUCTS

#pragma endregion

	//----------------------------------------------------------------------------------------------------
	//										CLASSES
	//-----------------------------------------------------------------------------------

#pragma region // CLASSES

	//----------------------------------------------------------------------------------------------------
	//										CNode
	std::string CNode::GetName() { return (char*)PS2Memory::GetEEAddr(this->pName); }
	CNode* CNode::GetParent() { return (CNode*)PS2Memory::GetEEAddr(this->pParent); }
	CNodeEx* CNode::GetNodeExObject() { return (CNodeEx*)PS2Memory::GetEEAddr(this->pNodeEx); }
	CModel* CNode::GetModelObject() { return (CModel*)PS2Memory::GetEEAddr(this->pModel); }
	CEntity* CNode::GetEntityObject() { CNodeEx* pNode = GetNodeExObject(); return pNode == nullptr ? nullptr : pNode->GetEntity(); }
	bool CNode::IsVisible() { return this->mOpacity > 0.0f; }
	void CNode::SetVisibility(float opacity) { this->mOpacity = opacity; }
	Vec3 CNode::GetWorldPos() const { return Vec3(this->mMatrix.m[3][0], this->mMatrix.m[3][1], this->mMatrix.m[3][2]); }
	void CNode::SetWorldPos(const Vec3& newPos) {}
	Mat4x4 CNode::GetWorldTM() { return this->mMatrix; }
	void CNode::SetWorldTM(const Mat4x4& newTM) { this->mMatrix = newTM; }
	AABB CNode::GetLocalBounds() const { return this->mAABB; }
	AABB CNode::GetWorldBounds() const { return this->mAABB + GetWorldPos(); }
	Vec3 CNode::GetRightVector() const { return Vec3(this->mMatrix.m[0][0], this->mMatrix.m[0][1], this->mMatrix.m[0][2]); }
	Vec3 CNode::GetUpVector() const { return Vec3(this->mMatrix.m[1][0], this->mMatrix.m[1][1], this->mMatrix.m[1][2]); }
	Vec3 CNode::GetForwardVector() const { return Vec3(this->mMatrix.m[2][0], this->mMatrix.m[2][1], this->mMatrix.m[2][2]); }
	float CNode::GetYawAngleRadians() const { return atan2(-this->mMatrix.m[2][0], this->mMatrix.m[2][2]); }
	float CNode::GetYawAngleDegrees() const { float yawAngle = GetYawAngleDegrees() * (180.f / M_PI); return yawAngle < 0.f ? yawAngle : yawAngle + 360.f; }


	//----------------------------------------------------------------------------------------------------
	//										CNodeEx
	CEntity* CNodeEx::GetEntity() { return (CEntity*)PS2Memory::GetEEAddr(this->pEntity); }

	//----------------------------------------------------------------------------------------------------
	//										CModel


	//----------------------------------------------------------------------------------------------------
	//										CTarget
	CEntity* CTarget::GetEntity() { return (CEntity*)PS2Memory::GetEEAddr(this->pEntity); }

	bool CTarget::GetOrigin(Vec3* out)
	{
		CEntity* pEntity = GetEntity();
		if (!pEntity)
			return false;

		*out = pEntity->GetOrigin();

		return true;
	}

	float CTarget::GetDistance() const { return this->mDistance; }
	bool CTarget::IsVisible() const { return this->mVisiblity >= 2.0f; }
	bool CTarget::WasRecentlyVisible() const { return this->mVisiblity != 2.0f && this->mVisiblity >= 1.7f; }


	//----------------------------------------------------------------------------------------------------
	//										CAppCamera
	CAppCamera* CAppCamera::GetDefaultInstance()
	{
		if (!Offsets::o_LocalCAppCamera)
			return nullptr;


		return PS2Memory::GetPtrShort<CAppCamera*>(Offsets::o_LocalCAppCamera);
	}

	CZCamera* CAppCamera::GetCameraObject() { return this->pCamera == 0 ? nullptr : (CZCamera*)PS2Memory::GetEEAddr(this->pCamera); }

	CEntity* CAppCamera::GetAttachedEntity() { return this->pAttachedEntity == 0 ? nullptr : (CEntity*)PS2Memory::GetEEAddr(this->pAttachedEntity); }


	//----------------------------------------------------------------------------------------------------
	//										CEntity
	bool CEntity::IsValid()
	{
		//	if (this->vfTable != 0x434D30) // CEntity vtable
		//		return false;
		if (this->mEntityType == Enums::EENTITY_TYPE::ENT_TYPE_UNKNOWN)
			return false;
		if (this->pName <= 0 || this->pNode <= 0)
			return false;
		if (this->mTeamID == Enums::ESEAL_TEAMS::ETeam_NONE)
			return false;
		return true;
	}

	Enums::EENTITY_TYPE CEntity::GetEntityType() { return this->mEntityType; }
	Vec3 CEntity::GetOrigin() { return this->mOrigin; }
	Mat4x4 CEntity::GetTM() { return this->mMatrix; }
	Enums::ESEAL_TEAMS CEntity::GetTeamID() { return this->mTeamID; }
	std::string CEntity::GetName() { if (!pName) return ""; return (char*)PS2Memory::GetEEAddr(this->pName); }
	CNode* CEntity::GetNodeObject() { if (!pNode) return nullptr; return (CNode*)PS2Memory::GetEEAddr(this->pNode); }
	
	bool CEntity::GetTargets(std::vector<CTarget*> out)
	{ 
		if (!this->IsValid() || this->mTargetCount <= 0 || this->mMaxTargetCount <= 0)
			return false;

		unsigned __int64 pTargetArray = PS2Memory::GetEEAddr(this->pTargetArray);
		if (!pTargetArray)
			return false;	//	no target array, cannot check visibility

		out.clear();	//	clear output vector
		for (int i = 0; i < this->mTargetCount; i++)
		{
			CTarget* pTarget = (CTarget*)(pTargetArray + (i * sizeof(CTarget)));
			if (!pTarget)
				continue;

			out.push_back(pTarget);	//	add target to output vector
		}

		return out.size() > 0;	// targets found
	}

	bool CEntity::GetWorldTM(Mat4x4* out) 
	{ 
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetWorldTM();

		return true;
	}

	bool CEntity::SetWorldPos(const Vec3& newPos)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		pNode->SetWorldPos(newPos);

		return true;
	}

	bool CEntity::GetWorldPos(Vec3* out)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetWorldPos();

		return true;
	}

	bool CEntity::GetLocalBounds(AABB* out)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetLocalBounds();

		return true;
	}

	bool CEntity::GetWorldBounds(AABB* out)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetWorldBounds();

		return true;
	}

	bool CEntity::GetForwardVector(Vec3* out)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetForwardVector();

		return true;
	}

	bool CEntity::GetRightVector(Vec3* out)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetRightVector();

		return true;
	}

	bool CEntity::GetUpVector(Vec3* out)
	{
		CNode* pNode = GetNodeObject();
		if (!pNode)
			return false;

		*out = pNode->GetUpVector();

		return true;
	}

	float CEntity::GetAngleRadians()
	{
		return fmod(atan2(this->mQuat.y, this->mQuat.w), M_PI * 2.f) * 2;
	}

	//----------------------------------------------------------------------------------------------------
	//										CZCamera
	CZCamera* CZCamera::GetDefaultInstance()
	{
		CAppCamera* pAppCamera = CAppCamera::GetDefaultInstance();
		if (!pAppCamera)
			return nullptr;

		return pAppCamera->GetCameraObject();
	}

	Vec3 CZCamera::GetOrigin() { return this->mMatrix.Translation(); }

	bool CZCamera::WorldToScreen(const Vec3& worldOrigin, const Vec2& szScreen, Vec2* screen2D)
	{
		//	const Mat4x4& mtxWorldToClip = this->mtxViewToClip * this->mtxWorldToView;	//	Model View Projection
		//	Vec4 clipSpaceOrigin = this->mtxWorldToClip * Vec4(worldOrigin.x, worldOrigin.y, worldOrigin.z, 1.f);
		//	if (clipSpaceOrigin.w <= 0.1f)
		//		return false; // behind the camera
		//	
		//	Vec4 ndc4 = clipSpaceOrigin / clipSpaceOrigin.w; // Normalize Device Coordinates (NDC)
		//	Vec4 screen = this->mtxViewToScreen * ndc4; // Convert to screen coordinates
		//	screen.x = (ndc4.x + 1.0f) * 0.5f * szScreen.x;
		//	screen.y = (1.0f - ndc4.y) * 0.5f * szScreen.y;
		//	
		//	*screen2D = { screen.x, screen.y };
		//	
		//	return true;

		static float fov{ 60.f };

		//  get camera view matrix

		Mat4x4 mtxModel = this->mMatrix;

		Vec3 cam_pos = mtxModel.Translation();
		Vec3 cam_look = Vec3(-mtxModel.m[2][0], -mtxModel.m[2][1], -mtxModel.m[2][2]);
		Vec3 cam_right = Vec3(mtxModel.m[0][0], mtxModel.m[0][1], mtxModel.m[0][2]);
		Vec3 cam_up = Vec3(mtxModel.m[1][0], mtxModel.m[1][1], mtxModel.m[1][2]);

		//  get direction or heading
		Vec3 heading = worldOrigin - cam_pos;
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
	}


	//----------------------------------------------------------------------------------------------------
	//										CZBodyPart
	Vec3 CZBodyPart::GetOrigin() const { return this->mOrigin; }
	CNode* CZBodyPart::GetNode() { return (CNode*)PS2Memory::GetEEAddr(this->pNode); }
	CZBodyPart* CZBodyPart::GetParent() { if (!pParent) return nullptr; return (CZBodyPart*)PS2Memory::GetEEAddr(this->pParent); }
	std::string CZBodyPart::GetName() { CNode* pNode = GetNode(); return pNode == nullptr ? "" : pNode->GetName(); }
	Vec3 CZBodyPart::GetLocalOrigin() const { return this->mOrigin; }
	Vec4 CZBodyPart::GetLocalRotation() const { return this->mQuat; }

	bool CZBodyPart::GetLocalTM(Mat4x4* out)
	{
		CNode* pNode = GetNode();
		if (!pNode)
			return false;

		*out = pNode->GetWorldTM();

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

	//----------------------------------------------------------------------------------------------------
	//										CZSealBody

	CZSealBody* CZSealBody::GetDefaultInstance()
	{
		if (!Offsets::o_LocalSeal)
			return nullptr;

		return PS2Memory::GetPtrShort<CZSealBody*>(Offsets::o_LocalSeal);
	}

	bool CZSealBody::IsValidSeal()
	{
		if (!this->IsValid())
			return false;

		return this->vfTable == 0x668B20;
	}

	float CZSealBody::GetHealth() { return this->mHealth * 100.f; }

	bool CZSealBody::IsAlive() { return this->mHealth > 0.0f; }

	Enums::ESEAL_STANCE CZSealBody::GetStance() { return this->mStance; }

	bool CZSealBody::GetBoneByIndex(const int& boneIndex, CZBodyPart** out)
	{
		if (!this->IsValidSeal())
			return false;	// invalid seal body instance

		if (boneIndex < 0 || boneIndex >= 0x20)
			return false;	// invalid index

		i32_t boneOffset = this->mSkeleton[boneIndex];	// get bone offset from skeleton array
		if (boneOffset <= 0)
			return false;	// invalid bone pointer

		*out = (CZBodyPart*)PS2Memory::GetEEAddr(boneOffset);	// get bone index from skeleton array

		return true;
	}

	bool CZSealBody::GetBoneWorldTM(const int& boneIndex, Mat4x4* out)
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

		//	/* get bone body part reference */
		//	CZBodyPart* pBodyPart = nullptr;
		//	if (!GetBoneByIndex(boneIndex, &pBodyPart))
		//		return false;

		/* get body part node */
		CNode* pBodyPartNode = pBodyPart->GetNode();
		if (!pBodyPartNode)
			return false;	// invalid body part node

		/* get bone world matrix */
		//	Mat4x4 bodyPartLocalMatrix = pBodyPartNode->GetWorldTM();
		//	Vec3 bodyPartLocalOrigin = pBodyPartNode->GetWorldPos();


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

	bool CZSealBody::GetBoneLocationByIndex(const int& boneIndex, Vec3& outPosition)
	{
		Mat4x4 boneWorldMX;
		if (!GetBoneWorldTM(boneIndex, &boneWorldMX))
			return false;	//	cannot get bone world matrix

		outPosition = boneWorldMX.Translation();	// get bone world position from matrix translation

		return true;
	}

	void CZSealBody::SetAimPoint(const Vec3& newAim)
	{
		this->mAimWorldPos = newAim;
		this->mAimPoint = newAim;
		this->mPrevAimPoint = newAim;
		this->mReticlePt = newAim;
		this->mPrevReticlePt = newAim;
	}

	bool CZSealBody::SetAimTarget(CZSealBody* pTarget, bool bVisible, const Enums::ESEALBONES_INDEX& bone)
	{
		if (!this->IsValid() || !this->IsAlive() || !pTarget || !pTarget->IsValid() || !pTarget->IsAlive())
			return false;

		Vec3 targetOrigin;
		if (!pTarget->GetBoneLocationByIndex(bone, targetOrigin))
			return false;

		/* get direction */
		Vec3 dir = targetOrigin - this->mAimWorldPos;

		return SetAimTarget(targetOrigin);
	}

	bool CZSealBody::SetAimTarget(const Vec3& location) { SetAimPoint(location); return true; }

	CTarget* CZSealBody::GetTargetEntity(CZSealBody* pTarget)
	{
		if (!this || !this->IsValid() || !this->IsAlive())
			return nullptr;

		std::vector<CTarget*> targets;
		if (!this->GetTargets(targets))
			return nullptr;

		for (const auto& target : targets)
		{
			CEntity* pEntity = reinterpret_cast<CEntity*>(PS2Memory::GetEEAddr(target->pEntity));
			if (!pEntity || !pTarget || !pTarget->IsValid())
				continue;

			if (pEntity == (CEntity*)pTarget)
				return target;
		}

		return nullptr;
	}

#pragma endregion

	//----------------------------------------------------------------------------------------------------
	//										CCAMERA
	//-----------------------------------------------------------------------------------


	//----------------------------------------------------------------------------------------------------
	//										CZSEALOBJECT
	//-----------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
	CZSealObject* CZSealObject::GetDefaultInstance()
	{
		auto pSeal = CZSeal::GetDefaultInstance();
		if (!pSeal)
			return nullptr;

		return pSeal->GetSealObject();
	}

	//---------------------------------------------------------------------------------------------------
	void CZSealObject::SetPosition(Vec3 pos) { this->m_absPosition = pos; }
	
	//----------------------------------------------------------------------------------------------------
	//										CZSEAL
	//-----------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
	CZSeal* CZSeal::GetDefaultInstance()
	{
		if (!Offsets::o_LocalSeal)
			return nullptr;

		return PS2Memory::GetPtrShort<CZSeal*>(Offsets::o_LocalSeal);
	}

	//---------------------------------------------------------------------------------------------------
	bool CZSeal::IsValid()
	{
		return (this->m_pName > 0 && this->m_pSealObj > 0 && this->m_teamID > ETeam::NONE);
	}

	//---------------------------------------------------------------------------------------------------
	CZSealObject* CZSeal::GetSealObject()
	{
		return reinterpret_cast<CZSealObject*>(PS2Memory::GetEEAddr(this->m_pSealObj));
	}

	//---------------------------------------------------------------------------------------------------
	Vec3 CZSeal::GetPosition() { return this->m_relativeLocation; }

	//---------------------------------------------------------------------------------------------------
	Vec2 CZSeal::GetRotation() { return Vec2(this->rotation.x, this->rotation.z); }

	//---------------------------------------------------------------------------------------------------
	std::string CZSeal::GetName() 
	{
		if (!this->IsValid())
			return "";

		return (char*)PS2Memory::GetEEAddr(this->m_pName);
	}

	//---------------------------------------------------------------------------------------------------
	ETeam CZSeal::GetTeam() { return this->m_teamID; }

	//---------------------------------------------------------------------------------------------------
	float CZSeal::GetHealth() { return this->m_health * 100.f; }

	//---------------------------------------------------------------------------------------------------
	bool CZSeal::IsAlive() { return this->m_health > 0.0f; }

	//---------------------------------------------------------------------------------------------------
	void CZSeal::ChangeTeams(ETeam id) { this->m_teamID = id; }

	//----------------------------------------------------------------------------------------------------
	//										CZWEAPON
	//-----------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
	Vec3 CZWeapon::GetBulletPos()
	{
		return Vec3(0, 0, 0);
	}

	//---------------------------------------------------------------------------------------------------
	void CZWeapon::SetBulletPos(Vec3 Pos)
	{

	}

	//----------------------------------------------------------------------------------------------------
	//										CZKIT
	//-----------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
	void CZKit::GiveWeapon(EWeapon w, EWeaponSlot s, EAmmoType a, EFireType f)
	{
		switch (s)
		{
			case EWeaponSlot::Primary:
			{
				this->Primary = w;
				this->PrimaryAmmoType = a;
				this->PrimaryFireType = f;
				break;
			}

			case EWeaponSlot::Secondary:
			{
				this->Secondary = w;
				this->SecondaryAmmoType = a;
				this->SecondaryFireType = f;
				break;
			}
			
			case EWeaponSlot::EqSlot1:
			{
				this->Eq1Ammo = w;
				this->Eq1AmmoType = a;
				break;
			}
			
			case EWeaponSlot::EqSlot2:
			{
				this->Eq2Ammo = w;
				this->Eq2AmmoType = a;
				break;
			}
			
			case EWeaponSlot::EqSlot3:
			{
				this->Eq3Ammo = w;
				this->Eq3AmmoType = a;
				break;
			}
		}
	}

	//---------------------------------------------------------------------------------------------------
	void CZKit::GiveAmmo(EWeaponSlot slot, EAmmoType type, __int32 count)
	{

		switch (slot)
		{
			case EWeaponSlot::Primary: 
			{
				this->PrimaryAmmoType = type;
				
				for (int i = 0; i < 10; i++)
					this->PrimaryAmmo[i] = count;

				break;
			}
			case EWeaponSlot::Secondary:
			{
				this->SecondaryAmmoType = type;

				for (int i = 0; i < 10; i++)
					this->SecondaryAmmo[i] = count;

				break;
			}
			case EWeaponSlot::EqSlot1:
			{
				this->SecondaryAmmoType = type;
				this->Eq1Ammo = type;

				break;
			}
			case EWeaponSlot::EqSlot2:
			{
				this->PrimaryAmmoType = type;
				this->Eq2Ammo = type;

				break;
			}
			case EWeaponSlot::EqSlot3:
			{
				this->PrimaryAmmoType = type;
				this->Eq3Ammo = type;

				break;
			}
		}
	}

	//---------------------------------------------------------------------------------------------------
	std::string CZKit::ExportLoadoutInfo()
	{
		char data[MAX_PATH];
		const char* data_ = "[LoadoutInfo: %s]\nPrimary: 0x%08X\nPrimary Ammo: 0x%08X\nPrimary Mag 0x%08X\nSecondary: 0x%08X\nSecondary Ammo: 0x%08X\nSecondary Mag1: 0x%08X\nEqSlot1: 0x%08X\nEqSlot1 Ammo Type: 0x%08X\nEq Slot1 Mag: 0x%08X\nEqSlot2: 0x%08X\nEqSlot2 Ammo Type: 0x%08X\nEq Slot2 Mag: 0x%08X\nEqSlot3: 0x%08X\nEqSlot3 Ammo Type: 0x%08X\nEq Slot3 Mag: 0x%08X\n\n";
		sprintf_s(data, data_,
			this->Primary,
			this->PrimaryAmmoType,
			this->PrimaryAmmo[0],
			this->Secondary,
			this->SecondaryAmmoType,
			this->SecondaryAmmo[0],
			this->EqSlot1,
			this->Eq1AmmoType,
			this->Eq1Ammo,
			this->EqSlot2,
			this->Eq2AmmoType,
			this->Eq2Ammo,
			this->EqSlot3,
			this->Eq3AmmoType,
			this->Eq3Ammo
		);
		return data;
	}
	

	//----------------------------------------------------------------------------------------------------
	//										CZMATCHDATA
	//-----------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------------
	void CZMatchData::ForceStartMatch(bool bActive)
	{
		unsigned int patch = 0x0;
		auto addr = PS2Memory::GetEEAddr(Patches::ForceMatch.dst);
		std::pair<unsigned int, unsigned int> pairs = { 0x0027E280, 0x0027DD00 };
		switch (bActive)
		{
			case TRUE:	patch = Patches::ForceMatch.patch; break;
			case FALSE: patch = Patches::ForceMatch.original; break;
		}
		PS2Memory::WriteLong<uint32_t>(addr, patch);
	}
	
	//---------------------------------------------------------------------------------------------------
	void CZMatchData::SetEndlessMatch(bool bActive)
	{
		unsigned int patch = 0x0;
		auto addr = PS2Memory::GetEEAddr(Patches::EndlessMatch.dst);
		std::pair<unsigned int, unsigned int> pairs = { 0xFFFFFFFF, 0x00124F80 };
		switch (bActive)
		{
			case TRUE:	patch = Patches::EndlessMatch.patch; break;
			case FALSE: patch = Patches::EndlessMatch.original; break;
		}
		PS2Memory::WriteLong<uint32_t>(addr, patch);
	}

	bool CZMatchData::GetEntities(std::vector<CZSealBody*>* entities)
	{
		std::vector<CZSealBody*> result{};

		const auto arr = PS2Memory::ReadEE<ZArray<CZSealBody*>>(Offsets::o_pEntityArray).Data();

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

	//---------------------------------------------------------------------------------------------------
	void CZMatchData::EndCurrentRound()
	{
		auto addr = PS2Memory::GetEEAddr(Offsets::MatchTimer);
		if (addr != NULL)
			PS2Memory::WriteLong<uint32_t>(addr, NULL);
	}

	//---------------------------------------------------------------------------------------------------
	std::vector<CZSeal*> CZMatchData::GetPlayers()
	{
		int count = NULL;
		std::vector<CZSeal*> ents{};

		//   Grab the first entityObjectPointer in the array
		auto entArray = PS2Memory::GetEEAddr(Offsets::p_EntityArray);
		if (entArray == NULL) 
			return ents;

		//   Store base address for later because the entity array loops back to the beginning
		auto baseEntity = entArray;

		size_t maxSize = 0x64;
		for (int i = 0; i <= maxSize; i++)
		{
			//	Cast entity object to CPlayer Class
			CZSeal* ent = (CZSeal*)((*(int32_t*)(entArray + 0x8)) + PS2Memory::GetEEBase());
			if (ent == NULL)
				break;

			if (!ent->IsValid())
			{
				// Get next entity in the array
				entArray = *(int32_t*)entArray + PS2Memory::GetEEBase();
				continue;
			}

			//	Push CPlayer Object into the vector array
			ents.push_back(ent);

			// Get next entity in the array
			entArray = *(int32_t*)entArray + PS2Memory::GetEEBase();

			if (entArray == baseEntity)
				break;
		}

		//	return array of players
		return ents;
	}


	//---------------------------------------------------------------------------------------------------
	bool CZMatchData::GetPlayers(std::vector<CZSeal*>* p)
	{
		std::vector<CZSeal*> result{};

		const auto arr = PS2Memory::ReadEE<ZArray<CZSeal*>>(Offsets::p_EntityArray).Data();

		for (auto ent : arr)
		{
			if (!ent->IsValid())
				continue;

			result.push_back(ent);
		}

		*p = result;

		return result.size() > 0;
	}

	//---------------------------------------------------------------------------------------------------
	std::vector<CZSeal*> CZMatchData::GetAlivePlayers()
	{
		auto _players = GetPlayers();

		std::vector<CZSeal*> _result;

		for (auto player : _players)
		{
			if (!player->IsAlive())
				continue;

			_result.push_back(player);
		}
		
		return _result;
	}

	//---------------------------------------------------------------------------------------------------
	std::string CZMatchData::LogData()
	{
		// Data
		// - Player Count
		// - Map Name
		// - Current Round
		// - Match Timer
		return "";
	}


}
#pragma pack(pop)