#!/bin/sh

VERSION="0.1.0"
BOARD="Raspberry Pi 3"

show_help() {
    cat << EOF
EmbarkOS System Information

Usage:
    embark-info [OPTION]

Options:
    --version      Display EmbarkOS version
    --hostname     Display system hostname
    --kernel       Display Linux kernel version
    --board        Display target board
    --help         Display this help
EOF
}

show_info() {
    echo "========================================="
    echo "            EmbarkOS"
    echo "========================================="
    echo
    echo "Version      : $VERSION"
    echo "Hostname     : $(hostname)"
    echo "Kernel       : $(uname -r)"
    echo "Architecture : $(uname -m)"
    echo "Board        : $BOARD"
}

case "$1" in
    --version)
        echo "$VERSION"
        ;;
    --hostname)
        hostname
        ;;
    --kernel)
        uname -r
        ;;
    --board)
        echo "$BOARD"
        ;;
    --help)
        show_help
        ;;
    "")
        show_info
        ;;
    *)
        echo "Unknown option: $1"
        echo
        show_help
        exit 1
        ;;
esac