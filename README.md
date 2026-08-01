# Backup File Browser

Unreal Engine editor plugin that shows project `.bak` backup files in the Content Browser.

## Features

- Displays `.bak` files below the project `/Game` mount.
- Labels them as **Backup File** in the Content Browser.
- Opens the selected backup file in Windows Explorer.
- Keeps backup files editor-only; it adds no runtime module or cooked content.

## Requirements

- Unreal Engine 5.7 or newer.
- The engine `ContentBrowserFileDataSource` plugin enabled.
- A C++ Unreal project with an Editor target.

## Installation

### Git submodule

From the project root:

```powershell
git submodule add https://github.com/MC-Oruc/BackupFileBrowser.git Plugins/BackupFileBrowser
```

Enable the plugin in the project `.uproject` file:

```json
{
  "Name": "BackupFileBrowser",
  "Enabled": true,
  "TargetAllowList": ["Editor"]
}
```

Regenerate project files, build the Editor target, and restart Unreal Editor.

## Usage

Place or keep a file with the `.bak` extension under the project `Content` directory. It appears in the Content Browser under the `/Game` mount. Use the file's edit or preview action to reveal it in Explorer.

## Packaging validation

```powershell
& "<UE_ROOT>/Engine/Build/BatchFiles/RunUAT.bat" BuildPlugin `
  -Plugin="<repo>/BackupFileBrowser.uplugin" `
  -Package="<repo>/BuildOutput/BackupFileBrowser" `
  -TargetPlatforms=Win64 `
  -StrictIncludes
```

## License

MIT. See [LICENSE](LICENSE).
