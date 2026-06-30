# EmbarkOS

> An educational Embedded Linux BSP built with Buildroot.

EmbarkOS is an open-source project whose goal is to learn and demonstrate modern Embedded Linux development practices used in the industry.

The project focuses on **Board Support Package (BSP)** development using **Buildroot**, with a clean architecture, custom packages and progressively more advanced low-level Linux topics.

---

## Project Goals

- Learn Buildroot from the ground up
- Build and maintain a custom BSP
- Develop embedded Linux utilities in C
- Understand Linux boot process
- Explore U-Boot and Device Tree
- Create a reusable embedded Linux development platform

---

## Current Features

- Buildroot based BSP
- BR2_EXTERNAL architecture
- Out-of-tree build support
- Raspberry Pi 3 target
- Custom root filesystem overlay
- Dropbear SSH
- ARM64 cross compilation
- Bootable SD card image generation
- Custom Buildroot packages
- `embark-info` utility written in C

---

## Repository Structure

```text
EmbarkOS/
├── buildroot/          # Official Buildroot source
├── external/
│   └── embarkos/
│       ├── board/
│       ├── configs/
│       ├── package/
│       ├── patches/
│       ├── Config.in
│       └── external.mk
├── docs/
├── output/
├── scripts/
└── README.md
```

---

## Current Packages

| Package | Description | Status |
|---------|-------------|--------|
| embark-info | Embedded system information utility | ✅ |

---

## Roadmap

### Foundation

- [x] Buildroot setup
- [x] BR2_EXTERNAL
- [x] Raspberry Pi BSP
- [x] Root filesystem overlay
- [x] Dropbear SSH
- [x] ARM64 cross compilation
- [x] Custom Buildroot package
- [x] Embedded utility written in C

### Embedded Utilities

- [ ] embark-uart
- [ ] embark-monitor
- [ ] embark-gpio

### BSP Development

- [ ] Device Tree customization
- [ ] Linux kernel configuration
- [ ] U-Boot customization
- [ ] Board initialization
- [ ] Custom board support

### Embedded Linux

- [ ] Custom init scripts
- [ ] System services
- [ ] Boot optimization
- [ ] Read-only root filesystem
- [ ] Package management improvements

### Tooling

- [ ] Automated testing
- [ ] GitHub Actions CI
- [ ] QEMU support
- [ ] Release automation

---

## Technologies

- C
- Buildroot
- Embedded Linux
- ARM64
- Bash
- Git
- Make
- Raspberry Pi

---

## Build

```bash
git clone --recursive https://github.com/ThomaMart/EmbarkOS.git

cd EmbarkOS

./scripts/build.sh
```

The generated images are available in:

```text
output/rpi3/images/
```

---

## Learning Objectives

EmbarkOS is intentionally developed step by step.

Each milestone introduces a new Embedded Linux concept:

- Buildroot
- Cross compilation
- Custom packages
- UART
- GPIO
- Device Tree
- Linux kernel
- U-Boot
- BSP development

The objective is not only to obtain a working Linux image but also to understand every component involved in an Embedded Linux system.

---

## Project Status

🚧 Active development

EmbarkOS is continuously evolving as new Embedded Linux features are implemented.

---

## License

MIT