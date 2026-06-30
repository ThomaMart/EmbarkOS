#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

LOG="$(mktemp)"

cleanup()
{
    if [ -n "${QEMU_PID:-}" ]; then
        kill "$QEMU_PID" >/dev/null 2>&1 || true
    fi

    rm -f "$LOG"
}

trap cleanup EXIT

echo "========================================="
echo "      🚀 EmbarkOS QEMU Smoke Test"
echo "========================================="

qemu-system-aarch64 \
    -machine virt \
    -cpu cortex-a53 \
    -m 1024 \
    -smp 2 \
    -nographic \
    -kernel "$ROOT/output/qemu/images/Image" \
    -append "console=ttyAMA0 root=/dev/vda rootwait rw" \
    -drive if=none,file="$ROOT/output/qemu/images/rootfs.ext2",format=raw,id=hd0 \
    -device virtio-blk-device,drive=hd0 \
    >"$LOG" 2>&1 &

QEMU_PID=$!

echo "[INFO] Waiting for boot..."

TIMEOUT=120

while [ $TIMEOUT -gt 0 ]
do
    if grep -q "buildroot login:" "$LOG"; then
        break
    fi

    sleep 1
    TIMEOUT=$((TIMEOUT - 1))
done

if [ $TIMEOUT -eq 0 ]; then
    echo
    echo "[FAIL] Boot timeout"
    cat "$LOG"
    exit 1
fi

echo
echo "[PASS] Kernel booted successfully"

kill "$QEMU_PID"

echo
echo "Smoke test passed."