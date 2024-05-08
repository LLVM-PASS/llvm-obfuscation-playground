clang-16 -S -emit-llvm main.c -o main.ll
# opt-16 -load-pass-plugin ./build/lib/Goron/libGoron.so main.ll -o main-obf.ll -passes=obfs
opt-16 -load-pass-plugin ./build/lib/Hikari/libHikari.so main.ll --enable-constenc --enable-funcwra -fw_prob=100 -fw_times=5 --passes="default<O0>,obfs" -o main-obf.ll -S
opt-16 -load-pass-plugin ./build/lib/Hikari/libHikari.so main-obf.ll --enable-constenc --enable-funcwra -fw_times=5 --passes="default<O0>,obfs" -o main-obf.ll -S
clang-16 main-obf.ll -o hikari.out -O0