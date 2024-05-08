#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"
#include "llvm/Support/raw_ostream.h"

using namespace clang;
using namespace ento;

namespace {
class MainCallChecker : public Checker<eval::Assume> {
  mutable std::unique_ptr<BugType> BT;

public:
  ProgramStateRef evalAssume(ProgramStateRef State, const SVal &Cond, bool Assumption) const;
};
} // end anonymous namespace

ProgramStateRef MainCallChecker::evalAssume(ProgramStateRef State, const SVal &Cond, bool Assumption) const {
  ConstraintManager &CMgr = State->getConstraintManager();
  llvm::errs() << "====================================\nConstraints is:" << Cond << "\n";
  State->dump();
  llvm::errs() << "\n";
  // State->
  // State->printJson();
  // const CFGBlock *BB = BBE->getBlock();
  // llvm::outs() << BB->getLabel() << "\n";
  // AnalysisManager &AMgr = State->getAnalysisManager();
  // ASTContext &ac = AMgr.getASTContext();
  // const Environment &en = State->getEnvironment();
  // for (auto it = en.begin(); it != en.end(); ++it) {
  //   EnvironmentEntry ee = it->first;
  //   const Stmt *stmt = ee.getStmt();
  //   stmt->dump();
  //   break;
  // }
  return State;
}

extern "C" void clang_registerCheckers(CheckerRegistry &registry) {
  registry.addChecker<MainCallChecker>(
      "example.MainCallChecker", "Disallows calls to functions called main",
      "");
}

extern "C" const char clang_analyzerAPIVersionString[] =
    CLANG_ANALYZER_API_VERSION_STRING;
