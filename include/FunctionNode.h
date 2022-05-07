#ifndef _FUNCTION_NODE_H_
#define _FUNCTION_NODE_H_

#include <string>
#include <vector>
#include "ExpressionNode.h"

class FunctionNode : public ASTNode {

public:
	FunctionNode(IdentifierNode *name, TypeNode *returnType, ParameterListNode *parameters, CompoundStatementNode *body);
	~FunctionNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	TypeNode *returnType;
	IdentifierNode *name;
	ParameterListNode *parameters;
	CompoundStatementNode *body;

	virtual void PrintContentInLevel(int level) const override;

};

class ParameterListNode : public ASTNode {

public:
	ParameterListNode() : ASTNode(), parameters() {}
	~ParameterListNode();

	void AppendParameter(DeclarationNode *param);
	void GetParameterTypes(std::vector<Type> &types);
	void GetParameterNames(std::vector<std::string> &names);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;

private:
	std::vector<DeclarationNode*> parameters;

	virtual void PrintContentInLevel(int level) const override;

};

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(IdentifierNode *name, ArgumentListNode *arguments);
	~FunctionCallNode();

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;

private:
	IdentifierNode *name;
	ArgumentListNode *arguments;

	virtual void PrintContentInLevel(int level) const override;

};

class ArgumentListNode : public ASTNode {

public:
	ArgumentListNode() : ASTNode(), arguments() {}
	~ArgumentListNode();

	void AppendArgument(ExpressionNode *arg);
	void GetArgumentTypes(std::vector<Type> &types);

	virtual void AnalyzeSemantic(SymbolTable *intab) override;
	virtual llvm::Value *CodeGen() override;
	
private:
	std::vector<ExpressionNode*> arguments;

	virtual void PrintContentInLevel(int level) const override;

};

#endif