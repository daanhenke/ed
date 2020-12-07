#!/bin/sh

# Cygwin - Use MinGW to compile a standalone Windows program
export CC=/usr/bin/x86_64-w64-mingw32-gcc.exe
export CXX=/usr/bin/x86_64-w64-mingw32-g++.exe

CYGWIN_LIBRARIES="libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll SDL2.dll iconv.dll"

SCRIPTS_DIR=$(readlink -f $(dirname "$0"))
. "$SCRIPTS_DIR/_common.sh"

log "Building ed..."

# Create build directory if it doesn't exist
[[ ! -d "$BUILD_DIR" ]] && mkdir "$BUILD_DIR"

# Initialize build files if they don't exist
[[ ! -f "$BUILD_DIR/Makefile" ]] && cd "$BUILD_DIR" && cmake ..

# Build the application
cd "$BUILD_DIR" && cmake --build .

# Cygwin only - Copy dll files to bin dir
for CYGWIN_LIB in $CYGWIN_LIBRARIES; do
    cp /usr/x86_64-w64-mingw32/sys-root/mingw/bin/$CYGWIN_LIB "$BUILD_DIR/bin"
done