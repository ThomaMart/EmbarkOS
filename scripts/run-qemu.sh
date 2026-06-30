#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
IMAGES="$ROOT/output/qemu/images"

KERNEL="$IMAGES/Image"
ROOTFS="$IMAGES/rootfs.ext2"

echo "========================================="
echo "        🚀 EmbarkOS QEMU Launcher"
echo "========================================="
echo

if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then
    echo "[ERROR] qemu-system-aarch64 is not installed."
    exit 1
fi

if [ ! -f "$KERNEL" ]; then
    echo "[ERROR] Missing kernel:"
    echo "        $KERNEL"
    exit 1
fi

if [ ! -f "$ROOTFS" ]; then
    echo "[ERROR] Missing root filesystem:"
    echo "        $ROOTFS"
    exit 1
fi

echo "[INFO] Kernel : $KERNEL"
echo "[INFO] RootFS : $ROOTFS"
echo
echo "[INFO] Starting QEMU..."
echo

exec qemu-system-aarch64 \
    -M virt \
    -cpu cortex-a53 \
    -m 1024 \
    -smp 2 \
    -nographic \
    -kernel "$KERNEL" \
    -append "console=ttyAMA0 root=/dev/vda rootwait rw" \
    -drive if=none,file="$ROOTFS",format=raw,id=hd0 \
    -device virtio-blk-device,drive=hd0 \
    -device virtio-net-device,netdev=net0 \
    -netdev user,id=net0