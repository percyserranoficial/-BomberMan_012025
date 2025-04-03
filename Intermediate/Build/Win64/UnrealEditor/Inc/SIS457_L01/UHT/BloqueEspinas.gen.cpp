// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SIS457_L01/Public/BloqueEspinas.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueEspinas() {}

// Begin Cross Module References
SIS457_L01_API UClass* Z_Construct_UClass_ABloqueAcero();
SIS457_L01_API UClass* Z_Construct_UClass_ABloqueEspinas();
SIS457_L01_API UClass* Z_Construct_UClass_ABloqueEspinas_NoRegister();
UPackage* Z_Construct_UPackage__Script_SIS457_L01();
// End Cross Module References

// Begin Class ABloqueEspinas
void ABloqueEspinas::StaticRegisterNativesABloqueEspinas()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueEspinas);
UClass* Z_Construct_UClass_ABloqueEspinas_NoRegister()
{
	return ABloqueEspinas::StaticClass();
}
struct Z_Construct_UClass_ABloqueEspinas_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueEspinas.h" },
		{ "ModuleRelativePath", "Public/BloqueEspinas.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueEspinas>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueEspinas_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueAcero,
	(UObject* (*)())Z_Construct_UPackage__Script_SIS457_L01,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueEspinas_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueEspinas_Statics::ClassParams = {
	&ABloqueEspinas::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueEspinas_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueEspinas_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueEspinas()
{
	if (!Z_Registration_Info_UClass_ABloqueEspinas.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueEspinas.OuterSingleton, Z_Construct_UClass_ABloqueEspinas_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueEspinas.OuterSingleton;
}
template<> SIS457_L01_API UClass* StaticClass<ABloqueEspinas>()
{
	return ABloqueEspinas::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueEspinas);
ABloqueEspinas::~ABloqueEspinas() {}
// End Class ABloqueEspinas

// Begin Registration
struct Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_Public_BloqueEspinas_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueEspinas, ABloqueEspinas::StaticClass, TEXT("ABloqueEspinas"), &Z_Registration_Info_UClass_ABloqueEspinas, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueEspinas), 398281987U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_Public_BloqueEspinas_h_3630293083(TEXT("/Script/SIS457_L01"),
	Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_Public_BloqueEspinas_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SIS457_L01_Source_SIS457_L01_Public_BloqueEspinas_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
