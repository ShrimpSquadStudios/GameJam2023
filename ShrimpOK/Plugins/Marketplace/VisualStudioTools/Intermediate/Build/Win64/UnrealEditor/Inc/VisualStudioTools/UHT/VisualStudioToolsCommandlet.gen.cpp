// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VisualStudioTools/Private/VisualStudioToolsCommandlet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVisualStudioToolsCommandlet() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UCommandlet();
	UPackage* Z_Construct_UPackage__Script_VisualStudioTools();
	VISUALSTUDIOTOOLS_API UClass* Z_Construct_UClass_UVisualStudioToolsCommandlet();
	VISUALSTUDIOTOOLS_API UClass* Z_Construct_UClass_UVisualStudioToolsCommandlet_NoRegister();
// End Cross Module References
	void UVisualStudioToolsCommandlet::StaticRegisterNativesUVisualStudioToolsCommandlet()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVisualStudioToolsCommandlet);
	UClass* Z_Construct_UClass_UVisualStudioToolsCommandlet_NoRegister()
	{
		return UVisualStudioToolsCommandlet::StaticClass();
	}
	struct Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCommandlet,
		(UObject* (*)())Z_Construct_UPackage__Script_VisualStudioTools,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VisualStudioToolsCommandlet.h" },
		{ "ModuleRelativePath", "Private/VisualStudioToolsCommandlet.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVisualStudioToolsCommandlet>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::ClassParams = {
		&UVisualStudioToolsCommandlet::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVisualStudioToolsCommandlet()
	{
		if (!Z_Registration_Info_UClass_UVisualStudioToolsCommandlet.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVisualStudioToolsCommandlet.OuterSingleton, Z_Construct_UClass_UVisualStudioToolsCommandlet_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVisualStudioToolsCommandlet.OuterSingleton;
	}
	template<> VISUALSTUDIOTOOLS_API UClass* StaticClass<UVisualStudioToolsCommandlet>()
	{
		return UVisualStudioToolsCommandlet::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVisualStudioToolsCommandlet);
	UVisualStudioToolsCommandlet::~UVisualStudioToolsCommandlet() {}
	struct Z_CompiledInDeferFile_FID_Git_GameJam2023_ShrimpOK_Plugins_Marketplace_VisualStudioTools_Source_VisualStudioTools_Private_VisualStudioToolsCommandlet_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_GameJam2023_ShrimpOK_Plugins_Marketplace_VisualStudioTools_Source_VisualStudioTools_Private_VisualStudioToolsCommandlet_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVisualStudioToolsCommandlet, UVisualStudioToolsCommandlet::StaticClass, TEXT("UVisualStudioToolsCommandlet"), &Z_Registration_Info_UClass_UVisualStudioToolsCommandlet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVisualStudioToolsCommandlet), 3416474361U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_GameJam2023_ShrimpOK_Plugins_Marketplace_VisualStudioTools_Source_VisualStudioTools_Private_VisualStudioToolsCommandlet_h_1479869392(TEXT("/Script/VisualStudioTools"),
		Z_CompiledInDeferFile_FID_Git_GameJam2023_ShrimpOK_Plugins_Marketplace_VisualStudioTools_Source_VisualStudioTools_Private_VisualStudioToolsCommandlet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_GameJam2023_ShrimpOK_Plugins_Marketplace_VisualStudioTools_Source_VisualStudioTools_Private_VisualStudioToolsCommandlet_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
