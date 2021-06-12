# UDPSocketGUI

UDP Socket GUI cross-platform source

## Linux Setup

1. Download qt5 libraries

```bash
sudo apt-get install build-essential
sudo apt-get install qt5-default
```

2. Set export for UDPSOCKETGUI_BINARY_PATH in ~/.bashrc

```bash
cd ~
sudo vim .bashrc
```
add:

```vim
export UDPSOCKETGUI_BINARY_PATH=/path/to/UDPSocketGUI/target
```

## Linux Compilation

1. In Top directory after cloning, where CMakeLists.txt is:

```bash
cmake .
make
```

2. Executable in target\bin directory

```bash
cd target\bin
```

## Windows Setup

1. Download Qt ==>
[Qt-Source](https://www.qt.io/offline-installers)

2. Check box for Qt5.12.11 and include all MSVC Components
- MSVC 32-bit (x86) and 64-bit (x64)
- All Available Qt5.12.11 Components

3. Add to PATH system environmental variable, MSVC executable and Qt5 MSVC dlls
- C:\Program Files (x86)\Microsoft Visual Studio\Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86

- C:\Qt\Qt5.12.11\5.12.11\msvc2017\bin

4. Set environmental variable for UDPSOCKETGUI_BINARY_PATH in edit the system environmental variables

```cmd
Variable name: UDPSOCKETGUI_BINARY_PATH
Variable value: C:/path/to/UDPSocketGUI/target
```

## Windows Compilation

1. Open Developer Command Prompt for VS2019

2. In Top directory where CMakeLists.txt is:

```batch
cmake -G "NMake Makefiles"
nmake
```
3. Executable in target\bin directory

```bash
cd target\bin
```

## Note

The build has been tested on Windows 10 (MSVC) and Ubuntu 18.04.5
