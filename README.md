# Welcome to My Tic-Tac-Toe Game Documentation!

This is a simple project where my intentions were more to play around with Doxygen, but also a little looking back on C programming and Makefiles. Yeah... I got pretty rusty.
Things you need to know:
* this was made in a rush
* it's Tic-Tac-Toe, rules are pretty simple, but will be printed when you start the game

## Setup
This section will explain how you can set up this simple project for your environment.

### Linux Setup
* Check if you have `gcc`, `make` and `Doxygen` already installed
```bash
gcc --version
make --version
doxygen --version
```
* If not, install them for your Linux distro

#### 1. Ubuntu / Debian / Linux Mint (APT-based)
Update:

```bash
sudo apt update
```
Install `gcc`, `make`, `doxygen`:

```bash
sudo apt install build-essential -y # Installs gcc, g++ and make
sudo apt install doxygen -y
```
Note: `build-essential` typically includes `gcc` and `make`, so you usually don't need to install them separately.

#### 2. Fedora / CentOS / RHEL (DNF/YUM-based)
Update:

```bash
sudo dnf check-update # Checks for updates
sudo dnf update -y    # Applies updates
# For older CentOS/RHEL versions using yum:\
# sudo yum check-update
# sudo yum update -y
```
Install `gcc`, `make`, `doxygen`:

```bash
sudo dnf install gcc make doxygen -y
# For older CentOS/RHEL versions using yum:
# sudo yum install gcc make doxygen -y
```

#### 3. Arch Linux / Manjaro (Pacman-based)
Update:

```bash
sudo pacman -Syu
```
Install `gcc`, `make`, `doxygen`:

```bash
sudo pacman -S gcc make doxygen
```

#### 4. openSUSE (Zypper-based)
Update:

```bash
sudo zypper refresh # Refreshes repositories
sudo zypper update  # Applies updates
```
Install `gcc`, `make`, `doxygen`:

```bash
sudo zypper install gcc make doxygen
```
#### 5. Gentoo (Portage/Emerge-based)
Update:

```bash
sudo emerge --sync  # Syncs the portage tree
sudo emerge --ask --update --deep --newuse @world # Updates all installed packages
```
Install `gcc`, `make`, `doxygen`:

```bash
sudo emerge --ask sys-devel/gcc sys-devel/make dev-util/doxygen
```

### Windows Setup
Yeahh, no, I'm a typical Windows/Mac hater (even though I'm using WSL, don't user Windows for programming...), find out on your own how to do this.

### Mac Setup
Check [Windows Setup](#windows-setup)

## Features:
* Two-player gameplay
* Console-based interface
* Win and tie detection

## Getting Started
To compile and run the game:
```bash
make game # compiles the game
./tictactoe # runs the game
```
* Press \<ENTER\> after reading the rules to start the game.
* When prompted to enter a coordinate, just type a number `0`, `1` or `2` and press \<ENTER\> to submit your move.

## Have fun!