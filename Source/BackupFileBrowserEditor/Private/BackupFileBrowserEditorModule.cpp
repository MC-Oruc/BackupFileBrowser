// Copyright <--\, Inc. All Rights Reserved.

#include "BackupFileBrowser.h"
#include "Modules/ModuleManager.h"

class FBackupFileBrowserEditorModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		BackupFileBrowser = MakeUnique<FBackupFileBrowser>();
		BackupFileBrowser->Initialize();
	}

	virtual void ShutdownModule() override
	{
		if (BackupFileBrowser)
		{
			BackupFileBrowser->Shutdown();
			BackupFileBrowser.Reset();
		}
	}

private:
	TUniquePtr<FBackupFileBrowser> BackupFileBrowser;
};

IMPLEMENT_MODULE(FBackupFileBrowserEditorModule, BackupFileBrowserEditor)
