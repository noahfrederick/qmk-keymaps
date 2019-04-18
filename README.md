# QMK Firmware

[![Software License](https://img.shields.io/github/license/noahfrederick/qmk-keymaps.svg?style=flat-square)](LICENSE.txt)
[![Build Status](https://img.shields.io/travis/noahfrederick/qmk-keymaps/master.svg?style=flat-square)](https://travis-ci.org/noahfrederick/qmk-keymaps)

The [QMK firmware][qmk] powers my keyboards.
This is the source code for my keyboard layouts.

    .
    ├── README.md
    ├── Rakefile       # Tasks for managing QMK source
    ├── planck         # Keyboard/keymap-specific files
    │   ├── README.md
    │   ├── keymap.c   # Keymap implementation
    │   └── rules.mk   # Keymap make rules
    ├── ...
    └── user           # Keyboard/keymap-agnostic files
        ├── README.md
        ├── config.h   # Configuration applied across all keymaps
        ├── my.c       # Global implementation file
        ├── my.h       # Global header file
        └── rules.mk   # Global make rules

[qmk]: https://github.com/qmk/qmk_firmware

## Building

The `Rakefile` manages the QMK firmware source code:

    rake ci           # Build all keymaps for CI
    rake clean        # Remove build artifacts
    rake install      # Symlink keymap files into QMK source tree
    rake qmk:install  # Install QMK dependencies
    rake qmk:update   # Update QMK firmware
    rake uninstall    # Remove symlinks from QMK source tree
