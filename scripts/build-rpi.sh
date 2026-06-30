#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "========================================="
echo "     🚀 Building EmbarkOS (Raspberry Pi)"
echo "========================================="

make -C "$ROOT/buildroot" \
    BR2_EXTERNAL="$ROOT/external/embarkos" \
    O="$ROOT/output/rpi3" \
    BR2_DEFCONFIG="$ROOT/configs/embarkos_rpi3_defconfig" \
    defconfig

make -C "$ROOT/buildroot" \
    BR2_EXTERNAL="$ROOT/external/embarkos" \
    O="$ROOT/output/rpi3"

echo
echo "✅ Build complete"