#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")"/.. && pwd)"
cd "$ROOT_DIR"

OS="$(uname -s)"

case "$OS" in
  MINGW*|MSYS*|CYGWIN*) BIN="bin/StrikeFall.exe" ;;
  *) BIN="bin/StrikeFall" ;;
esac

if [[ ! -x "$BIN" ]]; then
  echo "Binary $BIN not found or not executable. Building first..."
  scripts/build.sh
fi

echo "Running $BIN"
"$BIN"

