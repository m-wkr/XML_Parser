
#include <stack>
#include <deque>
#include "parser.hpp"


nodeSharedPtr formAST(std::deque<token> &queue) {

	std::stack<nodeSharedPtr> tokenStack;

	nodeSharedPtr ROOT = std::make_shared<node>(token("ROOT"));
	nodeSharedPtr copyRoot = ROOT;

	tokenStack.push(copyRoot); 

	while (!queue.empty()) {

		//Get the current token
		token currentToken = queue.front();
		queue.pop_front();


		tokenType currentTokenType = currentToken.getTokenType();

		nodeSharedPtr parentNode = tokenStack.top();

		if (currentTokenType == S_TAG) {


			nodeSharedPtr newNode = std::make_shared<node>(currentToken);
			parentNode->addChild(newNode);

			tokenStack.push(newNode);

		} else if (currentTokenType == E_TAG) {
			
			if (parentNode->getTokenType() == S_TAG && parentNode->getTokenName() == currentToken.getTokenName()) {

				tokenStack.pop();
			} else {
				//raise error
			}

		} else if (currentTokenType == SE_TAG) {

			nodeSharedPtr newNode = std::make_shared<node>(currentToken);

			parentNode->addChild(newNode);


		} else {
			//raise error
		}
	}

	preorderTraversal(ROOT);
	return tokenStack.top();

}

void preorderTraversal(nodeSharedPtr currentNode) {

	std::cout << currentNode->getTokenName() << '\n';

	for (int i = 0; i < currentNode->getChildren().size(); i++) {

		preorderTraversal(currentNode->getChildren()[i]);
		
	}
}

