# h8300h-test-rom

An example ROM template for emulators targetting the NTR-032 hardware.

## Usage

- Add your C code to the project.
- Define any required interrupt handlers:
   * Write the function in C
   * Add its symbol to the appropriate location in `vectors.S`

## Building

- Install the [GNU Development Tools for Renesas H8/300](https://h8300-hms.sourceforge.net/)
- Run `make`
