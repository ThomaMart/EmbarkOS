#!/usr/bin/env bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

BUILDROOT="$PROJECT_ROOT/buildroot"
EXTERNAL="$PROJECT_ROOT/external/embarkos"
OUTPUT="$PROJECT_ROOT/output/rpi3"

mkdir -p "$OUTPUT"

# Première configuration uniquement si elle n'existe pas
if [ ! -f "$OUTPUT/.config" ]; then
    echo "[INFO] Initial configuration..."
    make -C "$BUILDROOT" \
        BR2_EXTERNAL="$EXTERNAL" \
        O="$OUTPUT" \
        raspberrypi3_64_defconfig
fi

echo "[INFO] Building EmbarkOS..."

make -C "$BUILDROOT" \
    BR2_EXTERNAL="$EXTERNAL" \
    O="$OUTPUT"