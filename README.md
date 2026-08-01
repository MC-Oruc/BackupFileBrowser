<h1 align="center">Backup File Browser</h1>

<p align="center">
  <a href="https://www.unrealengine.com/"><img src="https://img.shields.io/badge/Unreal%20Engine-5.7-blue.svg" alt="Unreal Engine 5.7"></a>
  <a href="https://github.com/MC-Oruc/BackupFileBrowser/releases"><img src="https://img.shields.io/github/v/release/MC-Oruc/BackupFileBrowser?label=Release" alt="Latest release"></a>
  <a href="LICENSE"><img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License MIT"></a>
</p>

An Unreal Engine editor plugin that exposes project `.bak` backup files in the Content Browser.

## What it does

- Shows `.bak` files below the project `/Game` mount.
- Presents them as **Backup File** entries in the Content Browser.
- Opens the selected backup file in Windows Explorer.
- Runs only in the Editor; it adds no runtime module or cooked content.

## One-command installation

Run this from the Unreal project root:

```powershell
git submodule add https://github.com/MC-Oruc/BackupFileBrowser.git Plugins/BackupFileBrowser
```

The plugin is enabled by default for Editor targets. Regenerate project files if your IDE requires it, build the Editor target, and restart Unreal Editor.

To retrieve it in a fresh clone:

```powershell
git clone --recurse-submodules <your-project-repository-url>
```

Or, for an existing clone:

```powershell
git submodule update --init --recursive
```

## Usage

Keep a file with the `.bak` extension under the project's `Content` directory. It appears in the Content Browser under `/Game`. Use its edit or preview action to reveal the file in Explorer.

## Requirements

- Unreal Engine 5.7.
- Windows editor target.
- The engine `ContentBrowserFileDataSource` plugin.

## Plugin packaging

```powershell
& "<UE_ROOT>/Engine/Build/BatchFiles/RunUAT.bat" BuildPlugin `
  -Plugin="<repo>/BackupFileBrowser.uplugin" `
  -Package="<repo>/BuildOutput/BackupFileBrowser" `
  -TargetPlatforms=Win64 `
  -StrictIncludes
```

## License

MIT. See [LICENSE](LICENSE).
