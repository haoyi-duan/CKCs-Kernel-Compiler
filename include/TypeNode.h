#ifndef _TYPE_NODE_H_
#define _TYPE_NODE_H_

#include "ASTNode.h"

class TypeNode : public ASTNode {

public:
	TypeNode(Type type) : ASTNode(), type(type) { }
	~TypeNode() {}

	Type GetType() { return type; }
	
	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen(CodeGenerator *generator) override;

private:
	Type type;

	virtual void PrintContentInLevel(int level) const override;

};

#endif