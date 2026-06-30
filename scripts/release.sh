#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

VERSION="${1:-}"

if [ -z "$VERSION" ]; then
    echo "Usage:"
    echo
    echo "    ./scripts/release.sh v0.2.0"
    exit 1
fi

echo "========================================="
echo "      🚀 EmbarkOS Release Builder"
echo "========================================="
echo

echo "[1/6] Cleaning previous builds..."
rm -rf "$ROOT/output/qemu"
rm -rf "$ROOT/output/rpi3"

echo "[2/6] Building QEMU..."
"$ROOT/scripts/build-qemu.sh"

echo "[3/6] Building Raspberry Pi..."
"$ROOT/scripts/build-rpi.sh"

echo "[4/6] Creating release directory..."

mkdir -p "$ROOT/releases/$VERSION"

cp "$ROOT/output/qemu/images/Image" \
   "$ROOT/releases/$VERSION/embarkos-qemu-kernel"

cp "$ROOT/output/qemu/images/rootfs.ext2" \
   "$ROOT/releases/$VERSION/embarkos-qemu-rootfs.ext2"

cp "$ROOT/output/rpi3/images/sdcard.img" \
   "$ROOT/releases/$VERSION/embarkos-rpi3.img"

echo "[5/6] Creating SHA256..."

cd "$ROOT/releases/$VERSION"

sha256sum * > SHA256SUMS

echo "[6/6] Done."

echo
echo "Release created:"
echo
echo "    releases/$VERSION"
echo
echo "Next:"
echo
echo "    git tag $VERSION"
echo "    git push origin $VERSION"
echo
echo "🎉 Release ready."