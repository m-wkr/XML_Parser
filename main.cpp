#include "lexer.hpp"


int main() {
  tokenizer("shouldbeignored<testing>strange</testing>  <hey>< / hey> <there> <is/></there><></>shouldbeignoredtoo");
  return 0;
}