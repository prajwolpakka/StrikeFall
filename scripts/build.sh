#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")"/.. && pwd)"
cd "$ROOT_DIR"

mkdir -p bin

OS="$(uname -s)"
SRC=( src/*.cpp )

echo "Detected OS: $OS"
echo "Compiling sources: ${SRC[*]}"

case "$OS" in
  Linux)
    echo "Using Linux flags (-lGL -lGLU -lglut)"
    g++ -std=c++11 -O2 "${SRC[@]}" -Iinclude -Ithird_party -o bin/StrikeFall \
      -lGL -lGLU -lglut -lm
    ;;
  MINGW*|MSYS*|CYGWIN*)
    echo "Using MinGW/Cygwin flags (-lopengl32 -lglu32 -lfreeglut)"
    g++ -std=c++11 -O2 "${SRC[@]}" -Iinclude -Ithird_party -o bin/StrikeFall.exe \
      -lopengl32 -lglu32 -lfreeglut -lm
    ;;
  *)
    echo "Unsupported OS: $OS" >&2
    exit 1
    ;;
esac

echo "Build complete. Binary is in ./bin"
