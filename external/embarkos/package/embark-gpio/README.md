# Embark GPIO

Embark GPIO is a simple GPIO utility for Linux embedded systems.

It is part of the EmbarkOS BSP.

## Features

- List GPIO chips
- Display GPIO chip information
- Read GPIO value
- Set GPIO value

## Usage

List GPIO chips

```bash
embark-gpio list
```

Display GPIO information

```bash
embark-gpio info gpiochip0
```

Read GPIO line

```bash
embark-gpio get gpiochip0 17
```

Set GPIO line

```bash
embark-gpio set gpiochip0 17 1
```

## Buildroot

Enable:

```
Target packages
    ->
EmbarkOS
    ->
embark-gpio
```

## License

MIT