// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SIS457_L01/SIS457_L01GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIS457_L01GameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SIS457_L01_API UClass* Z_Construct_UClass_ASIS457_L01GameMode();
SIS457_L01_API UClass* Z_Construct_UClass_ASIS457_L01GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SIS457_L01();
// End Cross Module References

// Begin Class ASIS457_L01GameMode
void ASIS457_L01GameMode::StaticRegisterNativesASIS457_L01GameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASIS457_L01GameMode);
UClass* Z_Construct_UClass_ASIS457_L01GameMode_NoRegister()
{
	return ASIS457_L01GameMode::StaticClass();
}
struct Z_Construct_UClass_ASIS457_L01GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SIS457_L01GameMode.h" },
		{ "ModuleRelativePath", "SIS457_L01GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASIS457_L01GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASIS457_L01GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SIS457_L01,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASIS457_L01GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASIS457_L01GameMode_Statics::ClassParams = {
	&ASIS457_L01GameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASIS457_L01GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASIS457_L01GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASIS457_L01GameMode()
{
	if (!Z_Registration_Info_UClass_ASIS457_L01GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASIS457_L01GameMode.OuterSingleton, Z_Construct_UClass_ASIS457_L01GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASIS457_L01GameMode.OuterSingleton;
}
template<> SIS457_L01_API UClass* StaticClass<ASIS457_L01GameMode>()
{
	return ASIS457_L01GameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASIS457_L01GameMode);
ASIS457_L01GameMode::~ASIS457_L01GameMode() {}
// End Class ASIS457_L01GameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_SIS457_L01GameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASIS457_L01GameMode, ASIS457_L01GameMode::StaticClass, TEXT("ASIS457_L01GameMode"), &Z_Registration_Info_UClass_ASIS457_L01GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASIS457_L01GameMode), 349690788U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_SIS457_L01GameMode_h_3960792320(TEXT("/Script/SIS457_L01"),
	Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_SIS457_L01GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_SIS457_L01GameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
