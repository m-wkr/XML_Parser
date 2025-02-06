#include <deque>
#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>


// <></> is deemed illegal to reduce complexity for now
int main() {
  std::deque<token> tokenQueue = tokenizer("<testing>strange</testing>  <hey>< / hey> <there> <is/></there>");
  node rootNode = node(nullptr);
  //error with parser
  node AST = formAST(rootNode,tokenQueue);
  preorderTraversal(AST);

  return 0;
}