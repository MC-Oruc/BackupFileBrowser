// Copyright <--\, Inc. All Rights Reserved.

#include "BackupFileBrowser.h"

#include "ContentBrowserDataSubsystem.h"
#include "ContentBrowserFileDataCore.h"
#include "Editor.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"
#include "UObject/UObjectGlobals.h"

#define LOCTEXT_NAMESPACE "BackupFileBrowser"

namespace
{
	bool CanRevealBackupFile(const FName, const FString& Filename, FText*)
	{
		return FPaths::FileExists(Filename);
	}

	bool RevealBackupFile(const FName, const FString& Filename)
	{
		FPlatformProcess::ExploreFolder(*Filename);
		return true;
	}
}

void FBackupFileBrowser::Initialize()
{
	if (DataSource.IsValid() || !GEditor)
	{
		return;
	}

	ContentBrowserFileData::FFileConfigData Config;
	ContentBrowserFileData::FDirectoryActions DirectoryActions;
	DirectoryActions.PassesFilter.BindStatic(&ContentBrowserFileData::FDefaultFileActions::ItemPassesFilter, false);
	DirectoryActions.GetAttribute.BindStatic(&ContentBrowserFileData::FDefaultFileActions::GetItemAttribute);
	Config.SetDirectoryActions(DirectoryActions);

	ContentBrowserFileData::FFileActions FileActions;
	FileActions.TypeExtension = TEXT("bak");
	FileActions.TypeName = FTopLevelAssetPath(TEXT("/Script/BackupFileBrowserEditor.BackupFile"));
	FileActions.TypeDisplayName = LOCTEXT("BackupFileTypeName", "Backup File");
	FileActions.TypeShortDescription = LOCTEXT("BackupFileShortDescription", "Project backup file");
	FileActions.TypeFullDescription = LOCTEXT("BackupFileFullDescription", "A recoverable project backup file");
	FileActions.TypeColor = FColor(145, 145, 145);
	FileActions.DefaultEditVerb = ELaunchVerb::Edit;
	FileActions.PassesFilter.BindStatic(&ContentBrowserFileData::FDefaultFileActions::ItemPassesFilter, true);
	FileActions.GetAttribute.BindStatic(&ContentBrowserFileData::FDefaultFileActions::GetItemAttribute);
	FileActions.CanEdit.BindStatic(&CanRevealBackupFile);
	FileActions.Edit.BindStatic(&RevealBackupFile);
	FileActions.CanPreview.BindStatic(&CanRevealBackupFile);
	FileActions.Preview.BindStatic(&RevealBackupFile);
	FileActions.CanDuplicate.BindLambda([](const FName, const FString&, FText*) { return true; });
	Config.RegisterFileActions(FileActions);

	DataSource.Reset(NewObject<UContentBrowserFileDataSource>(GetTransientPackage(), TEXT("BackupFileDataSource")));
	DataSource->Initialize(Config);

	FString ProjectContentPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
	FPaths::NormalizeDirectoryName(ProjectContentPath);
	DataSource->AddFileMount(TEXT("/Game"), ProjectContentPath);
	GEditor->GetEditorSubsystem<UContentBrowserDataSubsystem>()->ActivateDataSource(DataSource->GetFName());
}

void FBackupFileBrowser::Shutdown()
{
	if (UObjectInitialized() && GEditor && DataSource.IsValid())
	{
		GEditor->GetEditorSubsystem<UContentBrowserDataSubsystem>()->DeactivateDataSource(DataSource->GetFName());
	}
	DataSource.Reset();
}

#undef LOCTEXT_NAMESPACE
