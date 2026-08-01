// Copyright <--\, Inc. All Rights Reserved.

#pragma once

#include "ContentBrowserFileDataSource.h"
#include "UObject/StrongObjectPtr.h"

class FBackupFileBrowser final
{
public:
	void Initialize();
	void Shutdown();

private:
	TStrongObjectPtr<UContentBrowserFileDataSource> DataSource;
};
