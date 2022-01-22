#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "List.h"
using namespace std;

// NAO MEXA NESTA FUNCAO, ELA ESTA TERMINADA
int main() {

	vector<List*> listas;
	
	while(true) {

		// try catch para lidar com erros
		try{
			string comando;
			getline(cin, comando);
			std::stringstream ss{ comando };
			vector<string> tokens;
			string buffer;

			cout << "$" << ss.str() << endl;

			while(ss >> buffer) 
				tokens.push_back(buffer);

			// exit
			if(tokens[0] == "exit") {
				for(unsigned i = 0; i < listas.size(); i++)
					delete listas[i];
				listas.clear();
				break;
			}
			// create
			else if(tokens[0] == "create") {
				List *lst = new List;
				listas.push_back(lst);
			}
			// push_back x l
			else if(tokens[0] == "pushBack") {
				int x = std::stoi(tokens[1]);
				int l = std::stoi(tokens[2]);
				listas[l]->push_back(x);
			}// push_front x l
			else if(tokens[0] == "pushFront") {
				int x = std::stoi(tokens[1]);
				int l = std::stoi(tokens[2]);
				listas[l]->push_front(x);
			}// popfront l
			else if(tokens[0] == "popFront") {
				int l = std::stoi(tokens[1]);
				listas[l]->pop_front();
			}// popback l
			else if(tokens[0] == "popBack") {
				int l = std::stoi(tokens[1]);
				listas[l]->pop_back();
			}// insertAt 
			else if(tokens[0] == "insertAt") {
				int x = std::stoi(tokens[1]);
				int i = std::stoi(tokens[2]);
				int l = std::stoi(tokens[3]);
				listas[l]->insertAt(x, i);
			}
			// removeAll x l
			else if(tokens[0] == "removeAll") {
				int x = std::stoi(tokens[1]);
				int l = std::stoi(tokens[2]);
				listas[l]->removeAll(x);
			}
			//swap l1 l2
			else if(tokens[0] == "swap") {
				int l1 = std::stoi(tokens[1]);
				int l2 = std::stoi(tokens[2]);
				listas[l1]->swap(*listas[l2]);
			}
			// concat l1 l2
			else if(tokens[0] == "concat") {
				int l1 = std::stoi(tokens[1]);
				int l2 = std::stoi(tokens[2]);
				listas[l1]->concat(*listas[l2]);
			}
			// append l n a1... an
			else if(tokens[0] == "append") {
				int l = std::stoi(tokens[1]);
				int n = std::stoi(tokens[2]);
				int *v = new int[n];
				for(int i=0; i<n; i++) {
					v[i] = std::stoi(tokens[i+3]);
				}
				listas[l]->append(v, n);
			}
			// reverse l
			else if(tokens[0] == "reverse") {
				int l = std::stoi(tokens[1]);
				listas[l]->reverse();
			}
			// show
			else if(tokens[0] == "show") {
				for(unsigned i = 0; i < listas.size(); ++i) {
					cout << "lista " << i << ": " << *listas[i] << endl;
				}	
			}
			else {
				cout << "comando inexistente" << endl;
			}
			// clone l
			// else if(tokens[0] == "clone") {
			// 	int l = std::stoi(tokens[1]);
			// 	List *lcp = listas[l]->clone();
			// 	listas.push_back(lcp);
			// }
			// equals l1 l2 
			// else if(tokens[0] == "equals") {
			// 	int l1 = std::stoi(tokens[1]);
			// 	int l2 = std::stoi(tokens[2]);
			// 	if(listas[l1]->equals(*listas[l2])) cout << "listas iguais" << endl;
			// 	else cout << "listas diferentes" << endl;
			// }

		}catch(std::exception& e) {
			cout << "Erro: " << e.what() << endl;
		}

	}
	return 0;
}