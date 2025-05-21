# h8300h-test-rom

An example ROM template for emulators targetting the NTR-032 hardware.

## Usage

- Add your C code to the project.
- Define any required interrupt handlers:
   * Write the function in C
   * Add its symbol to the appropriate location in `vectors.S`
- Ensure `main` does not return in your code, as it doing so causes undefined behavior. This is an intentional design choice to save some space on the stack. Either design your application to run indefinitely, or have it waitloop once it is finished.

## Building

- Install the [GNU Development Tools for Renesas H8/300](https://h8300-hms.sourceforge.net/)
- Run `make`
