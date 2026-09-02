# RAM-PUMPER2000

RAM-PUMPER2000 is a small Windows memory-pressure experiment. It reserves and
commits a user-selected number of gibibytes with `VirtualAlloc`, writes to every
byte, waits for a key press, and then releases the allocation.

> Warning: this program deliberately consumes large amounts of physical and
> virtual memory. Save your work first. Start with a small value. A large value
> can make Windows slow or unresponsive and can force other applications out of
> memory.

## Run the included executable

The repository contains a prebuilt Windows executable:

```powershell
git clone https://github.com/AbrarZShahriar/RAM-PUMPER2000.git
cd RAM-PUMPER2000
.\rampumper2000.exe
```

Enter a small positive whole number when prompted. The number is the allocation
size in GiB. Press any key after `DONE!` to release the memory and exit.

## Build from source

Install a Windows C++ compiler that provides `clang++`. You can then use the
included makefile or invoke the compiler directly:

```powershell
make
# or
clang++ -o rampumper2000.exe main.cpp
```

The source uses Windows APIs and does not currently support Linux or macOS.

## License

The project is released into the public domain under the [Unlicense](./LICENSE).
