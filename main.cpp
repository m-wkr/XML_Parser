#include "lexer.hpp"


int main() {
  tokenizer("<testing>strange</testing>  <hey>< / hey> <there> <is/></there><></>");
  return 0;
}