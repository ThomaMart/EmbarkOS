# embark-monitor

EmbarkOS package monitor.

---

## Description

`embark-monitor` is a monitor used to create new native EmbarkOS utilities.

Generated packages follow the standard EmbarkOS package layout and integrate
directly with Buildroot.

---

## Directory Layout

```text
embark-monitor/

├── Config.in
├── LICENSE
├── README.md
├── Makefile
├── embark-monitor.mk
│
├── include/
│   └── monitor.h
│
└── src/
    ├── main.c
    └── monitor.c
```

---

## Build

The package is automatically built by Buildroot.

---

## License

MIT License