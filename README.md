## WAŻNE
plik powstał z zalążka Pana Kreczmera by skompilować należy w miejscu gdzie leży plik readme otworzyć terminal i
wpisać make natomiast dla testów make test
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```


