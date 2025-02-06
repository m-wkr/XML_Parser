#pragma once

#include <string>
#include <vector>
#include "lexer.hpp"


class node {
  token* associatedTokenP;
  std::vector<node> children = {};

  public: 
  node(token* nTokenP) {
		associatedTokenP = nTokenP;
  };

	void addChild(node &child) {
		children.push_back(child);
	}

	void addChild(node &&child) {
		children.push_back(child);
	}

	tokenType getTokenType(){
		if (associatedTokenP) {
			return associatedTokenP->getTokenType();
		} else {
			return tokenType::NIL;
		}
	}

	std::string getTokenName() {
		return associatedTokenP->getTokenName();
	}

	std::vector<node> getChildren() {
		return children;
	}

};


node formAST(node rootNode,std::deque<token> &queue);

void preorderTraversal(node currentNode);