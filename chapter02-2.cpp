#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include <vector>

using namespace llvm;

static LLVMContext Context;
static Module *ModuleOb = new Module("my compiler", Context);

Function *createFunc(IRBuilder<> &Builder, std::string Name) {
  FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(), false);
  Function *fooFunc = llvm::Function::Create(
    funcType, llvm::Function::ExternalLinkage, Name, ModuleOb);
  
  return fooFunc;
}

int main(int argc, char *argv[])
{
  //ModuleOb->dump();
  static IRBuilder<> Builder(Context);
  Function *fooFunc = createFunc(Builder, "foo");
  verifyFunction(*fooFunc);

  ModuleOb->print(llvm::outs(), nullptr);
  return 0;
}
