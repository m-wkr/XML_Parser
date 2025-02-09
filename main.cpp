#include <deque>
#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>
#include <memory>


// <></> is deemed illegal to reduce complexity for now
int main() {
  std::deque<token> tokenQueue = tokenizer("<testing><strange></strange></testing>  <hey>< / hey> <there> <is/></there>");
  std::shared_ptr<node> AST = formAST(tokenQueue);

  return 0;
}