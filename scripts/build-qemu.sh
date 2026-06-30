#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "========================================="
echo "        🚀 Building EmbarkOS (QEMU)"
echo "========================================="

if [ ! -f "$ROOT/output/qemu/.config" ]; then
    echo "[INFO] Initializing Buildroot..."

    make -C "$ROOT/buildroot" \
        BR2_EXTERNAL="$ROOT/external/embarkos" \
        O="$ROOT/output/qemu" \
        BR2_DEFCONFIG="$ROOT/configs/embarkos_qemu_defconfig" \
        defconfig
fi

make -C "$ROOT/buildroot" \
    BR2_EXTERNAL="$ROOT/external/embarkos" \
    O="$ROOT/output/qemu"

echo
echo "✅ Build complete"