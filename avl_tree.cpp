#include <stdio.h>
#include "avl_tree.h"

Node insert(Node node, int key){
    if (node == 0){
        Node newBst= create_node(int key);
        node = newBst;
    }

    if (key < get_key(node)){
        set_left(node, insert(get_left(node), key));
    } else if (key > get_key(node)){
        set_right(node, insert(get_right(node), key));
    } else {
        // no duplicate keys
        return node;
    }

    set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);

    int balance = get_balance(node);
    if (balance > 1 && key < get_key(get_left(node))){
        // LL
		printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
        return rotate_right(node);
    }
    if (balance < -1 && key > get_key(get_right(node))){
        // RR
        printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
            return rotate_right(node);
    }
    if (balance > 1 && key > get_key(get_left(node))){
        // LR
        set_left(node, rotate_left(get_left(node)));
        return rotate_right(node);
    }
    if (balance < -1 && key < get_key(get_right(node))){
        // RL
        set_right(node, rotate_right(get_right(node)));
        return rotate_left(node);
    }
    // balanced
    return node;
}

Node rotate_left(Node node){
    if (node == 0){
        return 0;
    }

    Node r = get_right(node);
    Node l = get_left(r);

    set_left(r, node);
    set_right(node, l);

    set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);
    set_height(r, max(get_height(get_left(r)), get_height(get_right(r))) + 1);

    return r;
}

Node rotate_left(Node node){
    if (node == 0){
        return 0;
    }

    Node l = get_left(r);
    Node r = get_right(node);

    set_right(node, l);
    set_left(r, node);

    set_height(r, max(get_height(get_left(r)), get_height(get_right(r))) + 1);
    set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);
    return l;
}

int 	get_balance(Node node);

void 	print_postorder (Node node){
  if(bst==0)
  {
    return 0;
  }
  print_postorder(node->left);
  print_postorder(node->right);
  printf("%d, ", node->data);
}

void 	unbalanced_insert (Node root, int key);

int max (int n1, int n2){
  if(n1<n2)
  {
    return n2;
  }
  return n1;
}
