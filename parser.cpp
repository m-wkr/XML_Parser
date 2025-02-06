#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include "lexer.hpp"
#include "parser.hpp"


// <testing></testing>  <hey>< / hey> <there> <is/></there><></>
//node ROOT = node(nullptr);


node formAST(node rootNode, std::deque<token> &queue) {
	std::stack<node> tokenStack;
	tokenStack.push(rootNode);

	while (!queue.empty()) {
		//Get the pointer of the current token
		token *currentTokenP = &(queue.front());
		queue.pop_front();


		tokenType currentTokenType = (*currentTokenP).getTokenType();

		node &parentNode = tokenStack.top();
		

		if (currentTokenType == S_TAG) {

			node newNode = node(currentTokenP);
			parentNode.addChild(newNode);
			tokenStack.push(newNode);

		} else if (currentTokenType == E_TAG) {
			
			if (parentNode.getTokenType() == S_TAG && parentNode.getTokenName() == currentTokenP->getTokenName()) {
				parentNode.addChild(nullptr);
				tokenStack.pop();
			} else {
				//raise error
			}

		} else if (currentTokenType == SE_TAG) {

			node newNode = node(currentTokenP);
			newNode.addChild(nullptr);
			parentNode.addChild(newNode);

		} else {
			//raise error
		}
	}

	return rootNode;

}

void preorderTraversal(node currentNode) {
	for (int i = 0; i < currentNode.getChildren().size(); i++) {
		if (currentNode.getChildren()[0].getTokenType() == NIL) {
			return;
		} 
			
		std::cout << currentNode.getTokenName() << "TESTING" << '\n';
		preorderTraversal(currentNode.getChildren()[0]);
		
	}
}

