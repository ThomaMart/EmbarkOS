# embark-info

## Description

`embark-info` is a lightweight utility included in EmbarkOS.

It displays useful information about the running embedded Linux system.

## Features

- Display EmbarkOS version
- Display hostname
- Display Linux kernel version
- Display target board
- Display architecture

## Usage

```bash
embark-info
```

Display complete system information.

```bash
embark-info --version
```

Display EmbarkOS version.

```bash
embark-info --hostname
```

Display system hostname.

```bash
embark-info --kernel
```

Display Linux kernel version.

```bash
embark-info --board
```

Display target board.

## Future improvements

- Automatic board detection
- Build date
- Git commit information
- CPU information
- Memory information