#include <iostream>
#include <vector>
using namespace std;

enum Hue {White, Black};

class Node {
public:
    Hue color;
    vector<int> children; //Will contain the indexes of its sons
    Node(){
        color = White;
    }
    void makeNodeWhite();
    void addSon(int index);
    void deleteRandomSon(int currentNodesIndex);
};

vector<Node> nodes(30);
int roots [3] = {0,1,2};
vector<int> occupiedNodes;


void Node::makeNodeWhite(){
    color = White;
}

void Node::addSon(int index){
    if (count(children.begin(), children.end(), index)) {
        std::cout << "Element found not adding it!" << endl;
    }
    children.push_back(index);
    occupiedNodes.push_back(index);
}

void Node::deleteRandomSon(int currentNodesIndex){
    int deletedIndex;
    if(children.size() == 0)
        return;
    if(children.size() == 1){
        deletedIndex = 0;
    }
    else{
        deletedIndex = rand() % (children.size()-1);
    }
    cout << "Deleting the node " << children.at(deletedIndex) << " from the " << currentNodesIndex << endl;

    for(int i = 0; i < occupiedNodes.size(); i++){
        if(children.at(deletedIndex) == occupiedNodes.at(i))
            occupiedNodes.erase(occupiedNodes.begin() + i);
    }

    children.erase(children.begin() + deletedIndex);
    cout << "success" << endl;
}

 
// Main() function: where the execution of program begins
int main()
{
    occupiedNodes.push_back(0);
    occupiedNodes.push_back(1);
    occupiedNodes.push_back(2);

    for(int i = 0; i < nodes.size(); i++){
        // cout << nodes.at(i).color << endl;
        int newSonIndex;
        int nodeIndex = occupiedNodes.at(i % (occupiedNodes.size()-1));
        do{
            newSonIndex = rand() % (nodes.size() - 1);
        }while(newSonIndex == nodeIndex);
        nodes.at(nodeIndex).addSon(newSonIndex);

        cout << newSonIndex << " added as a child to " << occupiedNodes.at(i % (occupiedNodes.size()-1)) << endl;
        
    }

    cout << "Starting the deletion" << endl;

    for(int i = 0; i < occupiedNodes.size(); i++){
        int randomIndex = rand() % (occupiedNodes.size()-1);
        nodes.at(occupiedNodes.at(randomIndex)).deleteRandomSon(occupiedNodes.at(randomIndex));
    }

    for(int i = 0; i < nodes.size(); i++){
         cout << i << "s children are: " << endl;
         for(int j = 0; j < nodes.at(i).children.size(); j++){
             cout << nodes.at(i).children.at(j) << endl;
         }
         cout << "End of this node!!" << endl << endl;
    }

    return 0;
}