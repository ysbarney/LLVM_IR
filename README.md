# LLVM_IR

build cpp like this:

clang++ *.cpp -O3 `llvm-config --cxxflag --ldflags --system-libs --libs core` -o *
