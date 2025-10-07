#pragma once

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

		namespace Offsets
		{
			static const u32_t o_GameState = 0x2623C0;				//	GameState
			static const u32_t o_WorldState = 0x2623C4;				//  WorldState
			static const u32_t o_LevelState = 0x2623C8;				//  LevelState
			static const u32_t o_JT = 0x262E10;						//  SlyPointer
			static const u32_t oCM = 0x261990;						//  CameraPointer	
			static const u32_t o_CustomColors = 0x126A64;			//	CustomColors
			static const u32_t o_EntityOutlineColor = 0x2623E0;		//	EntityOutlineColor
		}

		namespace Enums
		{
			enum class JT_BODYPART_OUTLINE_INDEX : int32_t
			{
				Head = 0,
				Ears, 
				Hat,
				Backpack,
				Body,
				LeftHand,
				CaneHandle,
				CaneHook
			};

			enum class JT_STATES_INDEX : int32_t
			{
				JT_Stand = 0,			//	0
				JT_Run,					//	1
				JT_Jump,				//	2
				JT_Hang,				//	3
				JT_Zap,					//	4
				JT_SideStep,			//	5
				JT_Hide,				//	6
				JT_Pipe,				//	7
				JT_Edge,				//	8
				JT_Celebrate,			//	9
				JT_Rush,				//	10
				JT_Puppet,				//	11
				JT_Peek,				//	12
				JT_Ski,					//	13
				JT_Ball,				//	14
			};

			enum class JT_BODY_STATES_INDEX : int32_t
			{
				Jump_Init = 0,			//	0
				Jump_Rise,				//	1
				Jump_Fall,				//	2
				Jump_Boost,				//	3
				Jump_In,				//	4
				Jump_Out,				//	5
				Jump_Thrown,			//	6
				Jump_Smash,				//	7
				Jump_Dive,				//	8
				Jump_Target,			//	9
				Jump_Spire,				//	10
				Jump_Rail,				//	11
				Jump_Hshape,			//	12
				Jump_Hpnt,				//	13
				Hide_Stand,				//	14
				Hide_Sidestep,			//	15
				Hide_PeekLeft,			//	16
				Hide_PeekRight,			//	17
				Hide_Run,				//	18
				Hide_Spin,				//	19
				Pipe_Init,				//	20
				Pipe_Stay,				//	21
				Pipe_Up,				//	22
				Pipe_Down,				//	23
				Pipe_Spin,				//	24
				Celebrate_Key,			//	25
				Celebrate_Timed,		//	26
				Celebrate_UseKey,		//	27
				Rush_Attack,			//	28
				Rush_Bounce,			//	29
				Peek_Enter,				//	30
				Peek_Peek,				//	31
				Peek_Exit,				//	32
				Zap_Blunt,				//	33
				Zap_Electric,			//	34
				Zap_Fire,				//	35
				Zap_Water,				//	36
				Zap_Crush,				//	37
				Zap_Pit,				//	38
				Zap_Thrown,				//	39
				Zap_Dead,				//	40
				Zap_DeadFront,			//	41
				Zap_DeadInWater,		//	42
			};

			enum class JT_CANE_STATES_INDEX : int32_t
			{
				Reach,					//	0
				Hang,					//	1
				Pipe,					//	2
				SweepInit,				//	3
				SweepFore,				//	4
				SweepBack,				//	5
				StandingSweepFore,		//	6
				StandingSweepBack,		//	7
				Max,					//	8
			};

			enum class FGS : int32_t
			{
				FirstClue = 0
			};

			enum class FLS : int32_t
			{
				Visited = 0
			};

			enum class FWS : int32_t
			{
				Visited = 0
			};

		}

		namespace Structs
		{

		}
	}
}
#pragma pack(pop)