#!/bin/sh

PROJECT_DIR=$(readlink -f "$SCRIPTS_DIR/..")
BUILD_DIR="$PROJECT_DIR/build"

log()
{
    printf "%s\n" "$@"
}