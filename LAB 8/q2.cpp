#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class combatant {
public:
    string name;
    int hp;
    int attackp;
    int key;

    combatant(string n = "", int ap = 0, int k = 0) {
        name = n;
        attackp = ap;
        key = k;
        hp = 100;
    }
};

struct Node {
    combatant c;
    Node* left;
    Node* right;
    Node(combatant com) {
        c = com;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, combatant com) {
        if (node == NULL)
            return new Node(com);
        if (com.key < node->c.key)
            node->left = insert(node->left, com);
        else if (com.key > node->c.key)
            node->right = insert(node->right, com);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == NULL) return node;
        if (key < node->c.key)
            node->left = deleteNode(node->left, key);
        else if (key > node->c.key)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->c = temp->c;
                node->right = deleteNode(node->right, temp->c.key);
            }
        }
        return node;
    }

    void inorder(Node* node) const {
        if (node != NULL) {
            inorder(node->left);
            cout << node->c.name << "(" << node->c.hp << ") ";
            inorder(node->right);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(combatant com) {
        root = insert(root, com);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool empty() {
        return root == NULL;
    }

    void display() const {
        inorder(root);
        cout << endl;
    }

    Node* getFrontline() {
        return findMin(root);
    }
};

void attack(BST &attackerTree, BST &defenderTree, bool playerTurn) {
    Node* attacker = attackerTree.getFrontline();
    Node* defender = defenderTree.getFrontline();

    if (!attacker || !defender)
        return;

    int random_bonus = rand() % 5;
    int damage = attacker->c.attackp + random_bonus;

    defender->c.hp -= damage;

    cout << (playerTurn ? "Player" : "Enemy") << " attack: "
         << attacker->c.name << " -> " << defender->c.name
         << " dmg=" << damage << endl;

    if (defender->c.hp <= 0) {
        cout << defender->c.name << " is defeated" << endl;
        defenderTree.remove(defender->c.key);
    }
}

int main() {
    srand(time(0));

    BST player, enemy;

    player.insert(combatant("Hero1", 15, 10));
    player.insert(combatant("Hero2", 18, 20));
    player.insert(combatant("Hero3", 12, 30));
    player.insert(combatant("Hero4", 14, 40));
    player.insert(combatant("Hero5", 16, 50));

    enemy.insert(combatant("Enemy1", 10, 5));
    enemy.insert(combatant("Enemy2", 13, 15));
    enemy.insert(combatant("Enemy3", 17, 25));
    enemy.insert(combatant("Enemy4", 19, 35));
    enemy.insert(combatant("Enemy5", 21, 45));

    int round = 1;

    cout << "BattleQuest: BST Arena started" << endl;

    while (!player.empty() && !enemy.empty()) {
        cout << "\nRound " << round << endl;

        cout << "Heroes: ";
        player.display();
        cout << "Enemies: ";
        enemy.display();

        attack(player, enemy, true);
        if (enemy.empty()) {
            cout << " Player wins." << endl;
            break;
        }

        attack(enemy, player, false);
        if (player.empty()) {
            cout << " Enemy wins." << endl;
            break;
        }

        round++;
    }

    cout << "Game over" << endl;
    return 0;
}
