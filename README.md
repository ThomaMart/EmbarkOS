<div align="center">

# 🚀 EmbarkOS

**A lightweight Embedded Linux BSP based on Buildroot**

![Buildroot](https://img.shields.io/badge/Buildroot-BSP-blue)
![Language](https://img.shields.io/badge/C-17-blue.svg)
![Platform](https://img.shields.io/badge/ARM64-AArch64-success)
![License](https://img.shields.io/badge/License-MIT-green)
![CI](https://img.shields.io/github/actions/workflow/status/ThomaMart/EmbarkOS/build.yml?branch=main)
![Status](https://img.shields.io/badge/Status-In%20Development-orange)

Designing a custom Linux Board Support Package (BSP) for embedded systems.

Current Version: **0.2.0**

</div>

---

# 📖 Overview

EmbarkOS is a personal embedded Linux project built around **Buildroot**.

The objective is to design a lightweight, modular and reusable Linux Board Support Package while following professional embedded Linux development practices.

The project focuses on:

- 🐧 Linux Embedded Development
- ⚙️ Buildroot BSP Design
- 💻 Cross-compilation (ARM64 / AArch64)
- 📦 Custom Buildroot Packages
- 🔌 Hardware Interfaces (UART / GPIO)
- 🛠️ Embedded System Utilities
- 🧪 QEMU Virtual Platform
- 🤖 Continuous Integration (GitHub Actions)

---

# ✨ Features

| Package | Description | Status |
|---------|-------------|:------:|
| ✅ embark-info | System information utility | ✔ |
| ✅ embark-uart | UART monitoring tool | ✔ |
| ✅ embark-monitor | System monitoring utility | ✔ |
| 🚧 embark-gpio | GPIO utility (libgpiod) | WIP |
| ⏳ embark-net | Network utilities | Planned |

---

# 🏗️ Development Tools

| Tool | Description | Status |
|------|-------------|:------:|
| ✅ Package Generator | Automatic Buildroot package creation | ✔ |
| ✅ QEMU Support | ARM64 virtual platform | ✔ |
| ✅ Raspberry Pi 3 Support | Native target platform | ✔ |
| ✅ GitHub Actions | Automatic build pipeline | ✔ |
| 🚧 Automated QEMU Tests | Smoke tests | WIP |

---

# 📁 Project Structure

```text
EmbarkOS
├── .github/
│   └── workflows/
├── configs/
├── docs/
├── external/
│   └── embarkos/
│       └── package/
│           ├── embark-info/
│           ├── embark-uart/
│           ├── embark-gpio/
│           ├── embark-monitor/
│           └── embark-net/
├── releases/
├── scripts/
│   ├── build-qemu.sh
│   ├── build-rpi.sh
│   ├── run-qemu.sh
│   ├── test-qemu.sh
│   ├── gen-package.sh
│   └── release.sh
├── buildroot/
└── output/
```

---

# 🛠️ Technologies

- C17
- GNU Make
- Buildroot
- Linux Kernel
- BusyBox
- libgpiod
- QEMU
- Raspberry Pi 3
- ARM64 / AArch64
- Git
- GitHub Actions

---

# 🚀 Build

## Raspberry Pi 3

```bash
./scripts/build-rpi.sh
```

## QEMU

```bash
./scripts/build-qemu.sh
```

## Run QEMU

```bash
./scripts/run-qemu.sh
```

---

# ⚡ Package Generator

Create a new Buildroot package in a few seconds.

```bash
./scripts/gen-package.sh embark-example
```

The generator automatically creates:

- Package skeleton
- Buildroot integration
- Source tree
- Header files
- Makefile
- README
- LICENSE

---

# 🤖 Continuous Integration

Every push automatically triggers:

- ✅ QEMU Build
- ✅ Raspberry Pi Build
- ✅ Artifact generation
- 🚧 Automated smoke tests

---

# 🎯 Roadmap

## v0.1

- ✅ BSP initialization
- ✅ Buildroot integration
- ✅ ARM64 toolchain
- ✅ Root filesystem
- ✅ embark-info

## v0.2

- ✅ embark-uart
- ✅ embark-monitor
- ✅ Package Generator
- ✅ QEMU Support
- ✅ GitHub Actions
- 🚧 embark-gpio

## v0.3

- ⏳ embark-net
- ⏳ I²C utilities
- ⏳ SPI utilities
- ⏳ Automated QEMU tests

## v1.0

- Stable BSP
- Complete embedded utilities
- Full documentation
- Automated testing
- Continuous Integration
- Raspberry Pi validation

---

# 🎓 Learning Objectives

This project is intended to demonstrate practical skills in:

- Linux Embedded Development
- Buildroot
- Board Support Package Design
- Cross Compilation
- Embedded C Programming
- Linux Userspace Development
- Hardware Interfaces
- BSP Architecture
- Continuous Integration
- Embedded Software Engineering

---

# 📄 License

MIT License

Copyright © 2026 Thomas Martin