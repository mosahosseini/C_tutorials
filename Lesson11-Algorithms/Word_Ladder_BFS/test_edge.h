#include "linked_list.h"
#include <string.h>

int finns_i_sjon(Node **root , char * ch , int ind ){
    if (*(root) == NULL){
        *(root) = init_node(ch ,ind);
        return 0;
    }
    else{
        Node * temp = *(root); 
        while (temp != NULL){
            char comp = *(temp->value);
            if ( comp  == *ch &&temp -> node_num == ind){
                return 1;
            }
            temp = temp->next;
        }
        add(root, ind , ch );
        return 0;
    }
}

int node_from_1_to_2( char * word_1 , char * word_2){
    Node * root = NULL;
    for (int i=1 ; i< 5 ; i++){
        char ch = word_1[i];
        for (int j = 0 ; j <5 ; j++){
            if (ch == word_2[j]){
 
               if (finns_i_sjon(&root ,&(word_2[j]) , j ) == 0){
                  break;
               }
                
            }
        }

    }

//    print_linked_list(root);

   int num_nodes = 0 ; 
   Node *temp = root ;
   while (temp != NULL){
      ++ num_nodes; 
      temp = temp -> next ;
   }

   if (num_nodes == 4){
        free_mem(root);
        return  1 ; 
   }else {
        free_mem(root);
        return 0; 
   }
   

//    printf("num nodes: %d" , num_nodes);


}
 

//  int main(){
//     // char a = 'a';
//     // char * b = &a;
//     // Node * root = init_node( b , 0);
//     // printf("char : %c node_num : %d" , *(root ->value) ,root ->node_num);



//     // printf( "size of root after freeing the mem is : %d " , sizeof(root));
//    //  char *w1 = malloc(6);
//    //  strcpy(w1, "where"); 
//    //  char *w2 = malloc(6);
//    //  strcpy(w2, "there"); 

//       char * w1 = "ellil";
//       char * w2 = "iwlle";
//    //  printf("sring1 : %s , string2: %s" , w1,w2);
//    printf("node from w1 to w2 %d " ,     node_from_1_to_2(w1 ,w2 ));

//   }