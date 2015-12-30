@echo off
setlocal
: Update to match your installation
set MINGW_BASE_DIR=G:\MinGW
set AVR_TOOLCHAIN_BASE_DIR=G:\tests\Teensy\avr8-gnu-toolchain

: Internal definitions
set MINGW_BIN_DIR=%MINGW_BASE_DIR%\bin
set MSYS_BASE_DIR=%MINGW_BASE_DIR%\msys\1.0
set MSYS_BIN_DIR=%MSYS_BASE_DIR%\bin
set AVR_TOOLCHAIN_BIN_DIR=%AVR_TOOLCHAIN_BASE_DIR%\bin

set PATH=%PATH%;%MINGW_BIN_DIR%;%MSYS_BIN_DIR%;%AVR_TOOLCHAIN_BIN_DIR%

%MSYS_BIN_DIR%\make %*