/*
*	Operating System Lab
*	    Lab2 (Synchronization)
*	    Student id : 32163006 / 32164420
*	    Student name : 이건욱 / 조정민
*
*   lab2_bst.c :
*       - thread-safe bst code.
*       - coarse-grained, fine-grained lock code
*
*   Implement thread-safe bst for coarse-grained version and fine-grained version.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include "lab2_sync_types.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //mutex variable

/*
 * TODO
 *  Implement funtction which traverse BST in in-order
 *
 *  @param lab2_tree *tree  : bst to print in-order.
 *  @return                 : status (success or fail)
 */
int lab2_node_print_inorder(lab2_tree* tree) {
    // You need to implement lab2_node_print_inorder function.
    if (tree->root == NULL) {
        return LAB2_SUCCESS; // root가 비어 있는 경우 이를 반환 (재귀함수에서 사용)
    }

    else {
        lab2_tree* Templeft = (lab2_tree*)malloc(sizeof(lab2_tree));
        Templeft->root = tree->root->left; // 임시 트리를 구성, 재귀적 성격
        lab2_node_print_inorder(Templeft);

        //        printf(" %d ", tree->root->key);

        lab2_tree* Tempright = (lab2_tree*)malloc(sizeof(lab2_tree));
        Tempright->root = tree->root->right;
        lab2_node_print_inorder(Tempright);
    }
}

/*
 * TODO
 *  Implement function which creates struct lab2_tree
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_tree )
 *
 *  @return                 : bst which you created in this function.
 */
lab2_tree* lab2_tree_create() {
    // You need to implement lab2_tree_create function.
    lab2_tree* NewTree = (lab2_tree*)malloc(sizeof(lab2_tree));
    NewTree->root = NULL; //NewTree의 루트를 NULL로 초기화
    return NewTree;
}

/*
 * TODO
 *  Implement function which creates struct lab2_node
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_node )
 *
 *  @param int key          : bst node's key to creates
 *  @return                 : bst node which you created in this function.
 */
lab2_node* lab2_node_create(int key) {
    // You need to implement lab2_node_create function.
    lab2_node* NewNode = (lab2_node*)malloc(sizeof(lab2_node)); // 새로운 노드 동적할당 
    NewNode->key = key;
    NewNode->left = NULL;
    NewNode->right = NULL;          // 노드의 left, right를 NULL로 초기화
    pthread_mutex_init(&NewNode->mutex, NULL); //구조체의 변수들 초기화 
    return NewNode;
}

/*
 * TODO
 *  Implement a function which insert nodes from the BST.
 *
 *  @param lab2_tree *tree      : bst which you need to insert new node.
 *  @param lab2_node *new_node  : bst node which you need to insert.
 *  @return                 : satus (success or fail)
 */
int lab2_node_insert(lab2_tree* tree, lab2_node* new_node) {
    // You need to implement lab2_node_insert function.
    lab2_node* p = tree->root; // 부모노드를 루트로 초기화
    lab2_node* q = 0; // 부모의 부모 노드 

    if (p == NULL) {           // 루트가 비어있는 경우
        tree->root = new_node; // 새 노드를 루트에 삽입 
        return LAB2_SUCCESS;
    }

    else {
        while (p) { // 삽입해야할 위치 검사
            q = p;
            if (new_node->key == p->key) {
                return LAB2_ERROR;
            }
            else if (new_node->key < p->key) {
                p = p->left;
            }
            else {
                p = p->right;
            }
        } // p의 데이터와 new node의 데이터를 비교하며 검사

        // q가 단말노드, p가 NULL일 때
        if (new_node->key < q->key) {
            q->left = new_node;
        }  // new node의 데이터가 q노드의 데이터보다 작으면 q의 왼쪽자식에 노드를 추가
        else {
            q->right = new_node;
        }  // new node의 데이터가 q노드의 데이터보다 크면 q의 오른쪽자식에 노드를 추가
    }
    return LAB2_SUCCESS;
}

/*
 * TODO
 *  Implement a function which insert nodes from the BST in fine-garined manner.
 *
 *  @param lab2_tree *tree      : bst which you need to insert new node in fine-grained manner.
 *  @param lab2_node *new_node  : bst node which you need to insert.
 *  @return                     : status (success or fail)
 */
int lab2_node_insert_fg(lab2_tree* tree, lab2_node* new_node) {
    // You need to implement lab2_node_insert_fg function.
    lab2_node* pp = NULL;        // 부모의 부모노드를 NULL로 초기화
    lab2_node* p = tree->root;   // 부모노드를 루트로 초기화
    
    if (p == NULL) {   // 트리가 비어있는 경우
        tree->root = new_node;  // new node를 루트에 삽입
        return LAB2_SUCCESS;
    }
    
    else {
        while (p)  // 삽입해야할 위치 검사
        {
            pp = p;
            if (new_node->key < p->key) {
                p = p->left;
            }

            else if (new_node->key == p->key)
            {
                return LAB2_ERROR;
            }

            else {
                p = p->right;
            }
        }
    } // p의 데이터와 new node의 데이터를 비교하며 검사
    // q가 단말노드, p가 NULL일 때

    pthread_mutex_lock(&mutex);  // new node를 삽입하는 과정에서 다른 노드가 삽입되지 않도록 lock
    if (new_node->key < pp->key) {
            pp->left = new_node;
    }  // new node의 데이터가 q노드의 데이터보다 작으면 q의 왼쪽자식에 노드를 추가
    else {
            pp->right = new_node;
    } // new node의 데이터가 q노드의 데이터보다 크면 q의 오른쪽자식에 노드를 추가

    pthread_mutex_unlock(&mutex);  // new node의 삽입이 끝났으므로 lock 해제
    return LAB2_SUCCESS;
}


/*
 * TODO
 *  Implement a function which insert nodes from the BST in coarse-garined manner.
 *
 *  @param lab2_tree *tree      : bst which you need to insert new node in coarse-grained manner.
 *  @param lab2_node *new_node  : bst node which you need to insert.
 *  @return                     : status (success or fail)
 */
int lab2_node_insert_cg(lab2_tree* tree, lab2_node* new_node) {
    // You need to implement lab2_node_insert_cg function.
    pthread_mutex_lock(&mutex); // lock의 범위를 함수 전체로 크게 지정
    lab2_node* pp = NULL;    // 부모의 부모노드를 NULL로 초기화
    lab2_node* p = tree->root; // 부모노드를 트리의 루트로 초기화

    if (p == NULL)  // 트리가 비어있는 경우
    {
        tree->root = new_node;  // new node를 트리의 루트로 지정한 후
        pthread_mutex_unlock(&mutex); // lock 해제
        return LAB2_SUCCESS;
    }

    else
    {
        while (p)  // 삽입해야할 위치 검사
        {
            pp = p;
            if (new_node->key < p->key)
            {
                p = p->left;
            }

            else if (new_node->key == p->key)
            {
                pthread_mutex_unlock(&mutex);  // 같은 데이터가 있는 경우 lock 해제
                return LAB2_ERROR;
            }

            else
            {
                p = p->right;
            }
        }   // p의 데이터와 new node의 데이터를 비교하며 검사
        // q가 단말노드, p가 NULL일 때

        if (new_node->key < pp->key)
        {
            pp->left = new_node;  // new node의 데이터가 q노드의 데이터보다 작으면 q의 왼쪽자식에 노드를 추가
        }

        else
        {
            pp->right = new_node;  // new node의 데이터가 q노드의 데이터보다 크면 q의 오른쪽자식에 노드를 추가
        }
    }
    pthread_mutex_unlock(&mutex); // 함수 마지막 lock 해제
    return LAB2_SUCCESS;
}


/*
 * TODO
 *  Implement a function which remove nodes from the BST.
 *
 *  @param lab2_tree *tree  : bst tha you need to remove node from bst which contains key.
 *  @param int key          : key value that you want to delete.
 *  @return                 : status (success or fail)
 */
int lab2_node_remove(lab2_tree* tree, int key) {
    // You need to implement lab2_node_remove function.

    lab2_node* p = tree->root; //부모노드를 루트로 초기화 
    lab2_node* q = NULL; //부모의 부모노드를 NULL로 초기화

    if (p == NULL) {
        return LAB2_ERROR; // 트리가 비어있으면 에러 리턴
    }

    while (p != '\0' && p->key != key) { // 삭제 위치 탐색
        q = p;
        if (p->key < key) { // 찾는 데이터가 p의 데이터보다 큰 경우
            p = p->right;   // p는 p 노드의 오른쪽 자식노드로 이동
        }

        else if (p->key > key) { // 찾는 데이터가 p의 데이터보다 작은 경우 
            p = p->left;    // p는 p 노드의 왼쪽 자식노드로 이동
        }
    }

    if (p->left != '\0' && p->right != '\0') { // p의 자식이 둘 다 있을 경우
        lab2_node* s = p->left; // s노드를 왼쪽 자식으로
        lab2_node* ps = p; // ps를 p노드로

        while (s->right != '\0') { //왼쪽 서브트리의 최대값 찾기
            ps = s;
            s = s->right;
        }
        p->key = s->key;
        p = s;
        q = ps;
    }

    lab2_node* temp = (lab2_node*)malloc(sizeof(lab2_node)); // temp 노드 동적 할당

    if (p->left == '\0') { // p의 왼쪽 자식이 없는 경우
        temp = p->right; // p의 오른쪽 자식 노드를 temp로
    }
    else {
        temp = p->left;  // 반대 경우, p의 왼쪽 자식노드를 temp로
    }

    if (p == tree->root) { // p가 루트인 경우
        tree->root = temp;  // temp를 트리의 루트로
        lab2_node_delete(p); // p노드 삭제
    }
    else { // p가 루트가 아닌 경우
        if (p == q->left) {  // p가 q의 왼쪽자식인 경우
            q->left = temp;  // temp를 q의 왼쪽자식으로
            lab2_node_delete(p); // p노드 삭제
        }
        else { // 반대 경우
            q->right = temp;  // temp를 q의 오른쪽자식으로
            lab2_node_delete(p);  // p노드 삭제
        }
    }

    return LAB2_SUCCESS;
}


/*
 * TODO
 *  Implement a function which remove nodes from the BST in fine-grained manner.
 *
 *  @param lab2_tree *tree  : bst tha you need to remove node in fine-grained manner from bst which contains key.
 *  @param int key          : key value that you want to delete.
 *  @return                 : status (success or fail)
 */


int lab2_node_remove_fg(lab2_tree* tree, int key) {
    // You need to implement lab2_node_remove_fg function.
    
    lab2_node* pp = NULL;  // 부모의 부모노드를 NULL로 초기화
    lab2_node* p = tree->root; // p를 트리의 루트로 초기화

    if (p == NULL) {   // 빈 트리인 경우
        return LAB2_ERROR;  // 에러 리턴
    }

    while (p != '\0' && p->key != key) {  // 삭제 위치 탐색
        pp = p;
        if (p->key < key) {  // 탐색 데이터가 p의 데이터보다 큰 경우
            p = p->right;  // p는 p의 오른쪽 자식으로
        }

        else if (p->key > key) {  // 탐색 데이터가 p의 데이터보다 작은 경우
            p = p->left;  // p는 p의 왼쪽 자식으로
        }
    }

    pthread_mutex_lock(&mutex);  // 다른 삭제 노드 데이터가 들어오지 않도록 lock
    if (p->left != '\0' && p->right != '\0') {
        lab2_node* s = p->left;  // s를 p의 왼쪽자식으로
        lab2_node* ps = p;  // ps를 p 노드로

        while (s->right != '\0') {  // 왼쪽 서브트리의 최댓값 탐색
            ps = s;
            s = s->right;
        }
        p->key = s->key;
        p = s;
        pp = ps;
    }
    pthread_mutex_unlock(&mutex);

    lab2_node* temp = (lab2_node*)malloc(sizeof(lab2_node));  // temp노드 동적 할당
    
    pthread_mutex_lock(&mutex);
    if (p->left == '\0') {  // p의 왼쪽 자식이 없는 경우
        temp = p->right;  // p의 오른쪽 자식 노드를 temp로
    }

    else {  // 반대 경우
        temp = p->left; // p의 왼쪽 자식노드를 temp로
    }
    pthread_mutex_unlock(&mutex);

    pthread_mutex_lock(&mutex);
    if (p == tree->root) {  // p가 루트인 경우
        tree->root = temp;  // temp를 트리의 루트로
    }

    else {  //반대 경우
        if (p == pp->left){  // p가 pp의 왼쪽 노드와 같으면
            pp->left = temp;  // temp를 pp의 왼쪽노드로
        }
        // 반대 경우
        else pp->right = temp; // temp를 pp의 오른쪽노드로
    }
    lab2_node_delete(p);  // p 노드 삭제
    pthread_mutex_unlock(&mutex); // lock 해제
    return LAB2_SUCCESS;
}

/*
 * TODO
 *  Implement a function which remove nodes from the BST in coarse-grained manner.
 *
 *  @param lab2_tree *tree  : bst tha you need to remove node in coarse-grained manner from bst which contains key.
 *  @param int key          : key value that you want to delete.
 *  @return                 : status (success or fail)
 */
int lab2_node_remove_cg(lab2_tree* tree, int key) {
    // You need to implement lab2_node_remove_cg function.
    pthread_mutex_lock(&mutex); // lock 범위를 함수 전체로 지정
    lab2_node* pp = NULL;  // 부모의 부모노드를  NULL로 초기화
    lab2_node* p = tree->root; // 부모노드를 트리의 루트로 초기화

    if (p == NULL) {  // 빈 트리일 경우
        pthread_mutex_unlock(&mutex);  // lock 해제
        return LAB2_ERROR;  // 에러 리턴
    }

    while (p != '\0' && p->key != key) {  // 삭제 위치 탐색
        pp = p;
        if (p->key < key) {  // 탐색 데이터가 p의 데이터보다 큰 경우
            p = p->right; // p는 p의 오른쪽 자식으로
        }

        else if (p->key > key) {  // 탐색 데이터가 p의 데이터보다 작은 경우
            p = p->left;  // p는 p의 왼쪽 자식으로
        }
    }

    if (p->left != '\0' && p->right != '\0') {
        lab2_node* s = p->left;  // s를 p의 왼쪽자식으로
        lab2_node* ps = p;       // ps를 p 노드로

        while (s->right != '\0') {  // 왼쪽 서브트리의 최댓값 탐색
            ps = s;
            s = s->right;
        }
        p->key = s->key;
        p = s;
        pp = ps;
    }

    lab2_node* temp = (lab2_node*)malloc(sizeof(lab2_node));  // temp노드 동적 할당

    if (p->left == '\0') {  // p의 왼쪽 자식이 없는 경우
        temp = p->right;  // p의 오른쪽 자식을 temp으로
    }

    else {  // 반대 경우
        temp = p->left;  // p의 왼쪽 자식을 temp로
    }

    if (p == tree->root) { // p가 루트인 경우
        tree->root = temp; // temp를 트리의 루트로
    }

    else {  // 반대 경우
        if (p == pp->left) {  // p가 pp의 왼쪽노드와 같으면
            pp->left = temp;  // temp를 pp의 왼쪽노드로
        }

        else pp->right = temp;  // 반대경우, temp를 pp의 오른쪽 노드로
    }
    lab2_node_delete(p);  // p 노드 삭제
    pthread_mutex_unlock(&mutex); // lock 해제
    return LAB2_SUCCESS;
}


/*
 * TODO
 *  Implement function which delete struct lab2_tree
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_node )
 *
 *  @param lab2_tree *tree  : bst which you want to delete.
 *  @return                 : status(success or fail)
 */ 
void lab2_tree_delete(lab2_tree* tree) {
    // You need to implement lab2_tree_delete function.
    free(tree);
    tree->root = NULL;
    // tree의 동적할당 해제
}

/*
 * TODO
 *  Implement function which delete struct lab2_node
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_node )
 *
 *  @param lab2_tree *tree  : bst node which you want to remove.
 *  @return                 : status(success or fail)
 */
void lab2_node_delete(lab2_node* node) {
    // You need to implement lab2_node_delete function.
    free(node);
    node = NULL;
    // node의 동적할당 해제
}
