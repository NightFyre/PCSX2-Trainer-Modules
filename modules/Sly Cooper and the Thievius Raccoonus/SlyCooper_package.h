#pragma once

/**
 * Name: PlayStation2 - PCSX2 :: Sly Cooper and the Thievous Racoonus
 * Version: 0.0.1
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
		// --------------------------------------------------
		// # Forwards
		// --------------------------------------------------
		typedef int8_t		i8_t;
		typedef uint8_t		u8_t;
		typedef int16_t		i16_t;
		typedef uint16_t	u16_t;
		typedef int32_t		i32_t;
		typedef uint32_t	u32_t;
		typedef int64_t		i64_t;
		typedef uint64_t	u64_t;
		

		// --------------------------------------------------
		// # Global functions
		// --------------------------------------------------

		namespace Dumper
		{
			void DumpOffsets();
			void DumpClasses();
			void DumpFunctions();
			void DumpGlobals();
			void DumpAll();
		}
	}
}
#pragma pack(pop)
#include <PCSX2/CDK.h>
#include "SlyCooper_structs.h"
#include "SlyCooper_classes.h"