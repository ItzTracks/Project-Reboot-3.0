#pragma once

#include "Object.h"

#include "Map.h"

class UDataTable : public UObject
{
public:
	template <typename RowDataType = uint8_t>
	TMap<FName, RowDataType*>& GetRowMap()
	{
		static auto RowStructOffset = FindOffsetStruct("/Script/Engine.DataTable", "RowStruct");

		return *(TMap<FName, RowDataType*>*)(__int64(this) + (RowStructOffset + sizeof(UObject*))); // because after rowstruct is rowmap
	}
};

struct FDataTableRowHandle
{
	UDataTable* DataTable;                                                // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FName                                       RowName;                                                  // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
