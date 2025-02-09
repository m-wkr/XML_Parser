#pragma once

#include <iostream>
#include <vector>
#include "token.hpp"
#include <memory>




class node {
  token associatedToken;
  std::vector<std::shared_ptr<node>> children = {};  //was node template type

  public: 
  node(token nToken) : associatedToken(nToken) { // check notes
		//associatedToken = nToken;
  }

  ~node() {
	/* FOR DEBUGGING PURPOSES */
    //std::cout << associatedToken.getTokenName() << " destroyed\n";
  }

	void addChild(std::shared_ptr<node> child) { //was node type
		children.push_back(child);
	}

	tokenType getTokenType(){
		return associatedToken.getTokenType();

	}

	std::string getTokenName() {
		return associatedToken.getTokenName();
	}

	std::vector<std::shared_ptr<node>> getChildren() { //was std::vector<node>
		return children;
	}

};

typedef std::shared_ptr<node> nodeSharedPtr;


nodeSharedPtr formAST(std::deque<token> &queue);

void preorderTraversal(nodeSharedPtr currentNode);