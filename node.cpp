enum Hue {White, Black};

struct Node {
    Hue color;
    int sons[]; //Will contain the indexes of its sons
};

Node nodes[100];

