<div align="center">

# 🚀 EmbarkOS

**A lightweight Embedded Linux BSP based on Buildroot**

![Buildroot](https://img.shields.io/badge/Buildroot-BSP-blue)
![Language](https://img.shields.io/badge/C-17-blue.svg)
![Platform](https://img.shields.io/badge/ARM64-AArch64-success)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Status-In%20Development-orange)

Designing a custom Linux Board Support Package (BSP) for embedded systems.

Current Version: **0.1.0**

</div>

---

# 📖 Overview

EmbarkOS is a personal embedded Linux project built around **Buildroot**. 

The objective is to design a lightweight and modular Linux distribution while reproducing the workflow commonly used in embedded software engineering.

The project focuses on:

- 🐧 Linux Embedded Development
- ⚙️ Buildroot BSP Design
- 💻 Cross-compilation (ARM64)
- 📦 Custom Buildroot Packages
- 🔌 Hardware Interfaces (UART / GPIO)
- 🛠️ Embedded System Utilities

---

# ✨ Features

| Package | Description | Status |
|---------|-------------|:------:|
| ✅ embark-info | System information utility | ✔ |
| ✅ embark-uart | UART monitoring tool | ✔ |
| 🚧 embark-gpio | GPIO utility (libgpiod) | WIP |
| ⏳ embark-monitor | System monitoring | Planned |
| ⏳ embark-net | Network utilities | Planned |

---

# 📁 Project Structure

```text
EmbarkOS
├── board/
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
└── scripts/
```

---

# 🛠️ Technologies

- C
- GNU Make
- Buildroot
- Linux Kernel
- BusyBox
- libgpiod
- Raspberry Pi
- ARM64 / AArch64
- Git

---

# 🚀 Build

```bash
git clone https://github.com/<your-user>/EmbarkOS.git

cd EmbarkOS

./scripts/build.sh
```

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
- 🚧 embark-gpio

## v0.3

- ⏳ embark-monitor
- ⏳ embark-net

## v1.0

- Stable BSP
- Complete embedded utilities
- Documentation
- Automated builds

---

# 🎓 Learning Objectives

This project is intended to demonstrate practical skills in:

- Linux Embedded Development
- Buildroot
- Board Support Package design
- Cross Compilation
- Embedded C Programming
- Linux Userspace Development
- Hardware Interfaces
- Software Architecture

---

# 📄 License

MIT License

Copyright © 2026 Thomas Martin