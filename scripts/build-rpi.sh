#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "========================================="
echo "     🚀 Building EmbarkOS (Raspberry Pi)"
echo "========================================="

if [ ! -f "$ROOT/output/rpi3/.config" ]; then

    echo "[INFO] Initializing Buildroot..."

    make -C "$ROOT/buildroot" \
        BR2_EXTERNAL="$ROOT/external/embarkos" \
        O="$ROOT/output/rpi3" \
        BR2_DEFCONFIG="$ROOT/configs/embarkos_rpi3_defconfig" \
        defconfig

fi

make -C "$ROOT/buildroot" \
    BR2_EXTERNAL="$ROOT/external/embarkos" \
    O="$ROOT/output/rpi3"

echo
echo "✅ Build complete"