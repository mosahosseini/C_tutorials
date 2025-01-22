#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#define WORD_LENGTH 5

typedef struct g_node{
    int node_num;
    char * values; 
    Node neighbours; 
}G_node;


// Function to count frequency of characters in the last 4 characters of a word
void count_letters(const char *word, int freq[26] , int method) {
    /*
    method is a parameter 
    method = 0 , frequency of the fourd last letters
    method = 1 , frequency of all letters
    */
    if (method == 0){
        for (int i = 1; i < WORD_LENGTH; i++) {
            freq[word[ i] - 'a']++;
        }
    }
    else if (method == 1){
        for (int i = 0 ; i< WORD_LENGTH ; i++){
            freq[word[i]-'a']++;
        }
    }

}

// Function to determine if one word can reach another
int can_reach(const char *u, const char *v) {
    int u_freq[26] = {0};
    int v_freq[26] = {0};
    
    count_letters(u , u_freq , 0); // four last letters of u 
    count_letters(v , v_freq , 1); // frequency of all five letters of v

    // Check if all characters of u's last four letters are in v with equal or greater frequency
    for (int i = 0; i < 26; i++) {
        if (u_freq[i] > 0) {
            if (u_freq[i] != v_freq[i]){
                return 0;
            }
        }
    }
    return 1; // Edge from u to v exists
}

// Function to determine the edge type between two words
const char* determine_edge_type(const char *u, const char *v) {
    int u_to_v = can_reach(u, v);
    int v_to_u = can_reach(v, u);
    
    if (u_to_v && v_to_u) {
        return "double edge";
    } else if (u_to_v) {
        return "single edge";
    } else if (v_to_u) {
        return "single edge";
    } else {
        return "no edge";
    }
}




void add_neighbour(Node * start , int node_num , char* val){
    if (start == NULL){
        start =  init_node(val, node_num);
    }
    else {
        add(start , node_num , val);
    }

}





int main(){



}