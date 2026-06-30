#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "========================================="
echo "        🚀 Building EmbarkOS (QEMU)"
echo "========================================="

make -C "$ROOT/buildroot" \
    BR2_EXTERNAL="$ROOT/external/embarkos" \
    O="$ROOT/output/qemu"

echo
echo "✅ Build complete"