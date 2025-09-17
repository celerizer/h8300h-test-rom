# Stride

**Stride** is an SDK for developing custom programs targeting **H8/300H pedometer hardware**.

## Prerequisites

* Install the [GNU Development Tools for Renesas H8/300](https://h8300-hms.sourceforge.net/).

## Setup

1. Add Stride as a submodule in your project:

   ```bash
   git submodule add https://www.github.com/celerizer/stride
   git submodule update --init --recursive
   ```

2. In your project’s Makefile:

   * Add your program’s source files to the `SOURCES` variable.
   * Include the Stride Makefile at the end:

     ```make
     include stride/Makefile
     ```

## Notes on `main`

Your `main` function **must not return**, as returning can cause undefined behavior. This is intentional to save stack space. Design your application to either run indefinitely or enter a wait loop once it finishes.
