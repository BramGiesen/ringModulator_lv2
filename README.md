# Oscillator

A simple LV2 example in C++. Just for experiments.

## Build
```bash
$ mkdir build && cd build
$ cmake ..
$ make
```

To install, copy the bundle `osc.lv2` manually to the [standard
locations](http://lv2plug.in/pages/filesystem-hierarchy-standard.html)
or run

```
$ make install
```

to install it in `$PREFIX/lib/lv2/`. You could change the `$PREFIX` by running

```
$ cmake -D CMAKE_INSTALL_PREFIX=/your/path ..
```
above.