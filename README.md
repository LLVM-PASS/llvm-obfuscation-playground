# LLVM Obfuscation Playground

There are *a lot* of LLVM-based obfuscators out in the wild. This repository makes it (far) easier to get them up and running, using out-of-tree LLVM compilation.

Supported LLVM versions:
- LLVM 16.0

## Usage
Out-of-tree LLVM compilation differs in that, instead of compiling the *entire* LLVM project, we only compile the code as objects that are loaded by respective LLVM tools.

1. Place the folder containing the LLVM passes into `lib`.
2. Rename all include paths. For instance, in-tree directories will place these header files in their respective directories.
```C
#include "llvm/Transforms/Obfuscation/AntiHook.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
```
Instead, since we got lazy and placed everything in the same place, we have:
```C
#include "AntiHook.h"
#include "CryptoUtils.h"
```

## StaticAnalyzer