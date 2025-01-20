#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character; 
    int freq;
    struct  node * next; 
} Node;

void add(Node**s , char bokstav) {
    if( (*s) == NULL ){
        (*s) =  (Node*) malloc(sizeof(Node));
        (*s)->character = bokstav ; 
        (*s)->freq =1;
        (*s)->next = NULL; 
        return;
    }
    else if ( (*s) -> character == bokstav){
        (*s) -> freq ++;  
        return ;
    }
    else {
        add( &(*s)->next, bokstav);

    }
}


int inner_loop(Node * n2 , char bokstav){
    if (n2 == NULL){
        return 0;
    }
    else if ( n2 ->character == bokstav){
        return 1 ; 
    }
    else {
        return inner_loop(n2 -> next  , bokstav);
    }
}

int compare( Node * n1 , Node *  n2) {
    int res = 1; 
    while (n1 != NULL){
        res = res * inner_loop(n2 , n1->character);
        n1 = n1 -> next; 
    }
    return res; 
}




void print_list (Node*s ){
    if (s->next == NULL){
        return ; 
    }
    print_list(s->next); 
    printf( "charachter: %c    frequency: %d\n" , s->character , s->freq);
}

int main(){
int res ; 
char * t1 = "there";
char * t2 = "where";

Node * s1 = NULL ;
Node * s2 = NULL ;

for ( int i = 1 ; i< strlen(t1) ; i++)
{
    add(&s1 , t1[i]);
    add(&s2 , t2[i]);
}
res = compare(s1,s2);

if (res == 0 ){
    add(&s1 , t1[0]);
    add(&s2 , t2[0]);
}
else if (res == 1 ){
    printf("there is an arc from (a -> b) and from (b -> a): %d " , res); 
}

res = compare(s1,s2);
if (res == 1 )
{
    printf("there is an arc from (a -> b) ");
}

res = compare(s2 , s1);
if (res == 1 )
{
    printf("there is an arc from (b -> a) ");
}


return 0 ;
}