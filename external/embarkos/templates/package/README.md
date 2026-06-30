# embark-template

EmbarkOS package template.

---

## Description

`embark-template` is a template used to create new native EmbarkOS utilities.

Generated packages follow the standard EmbarkOS package layout and integrate
directly with Buildroot.

---

## Directory Layout

```text
embark-template/

├── Config.in
├── LICENSE
├── README.md
├── Makefile
├── embark-template.mk
│
├── include/
│   └── template.h
│
└── src/
    ├── main.c
    └── template.c
```

---

## Build

The package is automatically built by Buildroot.

---

## License

MIT License