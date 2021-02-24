# Requirements
CMake, conan
# How to configure
Supposed you have a multi configuration build system and you have repo cloned in the current directory you need to first run conan install for every configuration you want:

`conan install . -if <build_folder_path> -s build_type=<configuration>`

so e.g.

```
conan install . -if ../build -s build_type=Debug
conan install . -if ../build -s build_type=Release
```

This might work for single configuration systems as well, though it has been tested only under MSVC. Then run CMake as usual.