#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace llvm;

static LLVMContext Context;
static Module *ModuleOb = new Module("my compiler", Context);

int main(int argc, char *argv[])
{
  //ModuleOb->dump();
  ModuleOb->print(llvm::outs(), nullptr);
  return 0;
}
