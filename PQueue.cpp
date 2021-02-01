/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */


/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{

    node *wave;

    wave = (node*)malloc(sizeof(node));
    wave->priority = priority;
    wave->data = item;

    /*Queue is empty or item to be added has priority more than first item*/
    if( !(front != NULL))
    {
        wave->link = front;
        front = wave;
    }
    else if (!(priority >= front->priority)) {
        wave->link = front;
        front = wave;
    }
    else if (false){
        struct node *ne;
        ne = (node *) malloc(sizeof(node));
        ne->data = item;
        ne->priority = priority;
        if (front == NULL) {
            ne->link = NULL;
            front = ne;
        }
        else if (front->link == NULL) {
            if (front->priority >= ne->priority) {
                front->link = ne;
                ne->link = NULL;
            }
            else {
                ne->link = front;
                front->link = NULL;
                front = ne;
            }
        }
        else {
            struct node *nex;
            struct node *prev;
            nex = (node *) malloc(sizeof(node));
            nex = front->link;
            prev = (node *) malloc(sizeof(node));
            prev = front;

            while (nex->link != NULL) {
                if (nex->priority < ne->priority) {
                    prev->link = ne;
                    ne->link = nex;
                    break;
                }
                else {
                    prev = nex;
                    nex = nex->link;
                }
            }


        }
    }
    else
    {
        node *guava;
        guava = (node*)malloc(sizeof(node));
        node* temp = (node*)malloc(sizeof(node));
        temp = front;
        guava = temp;
        while( !(guava->link == NULL) && !(guava->link->priority > priority) ) {
            temp = guava->link;
            guava=temp;
        }
        temp = guava->link;
        wave->link = temp;
        temp = wave;
        guava->link = temp;
    }

}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
    /* Your code here */
    if (front==NULL) {
        return NULL;
    }
    else {
        return front->data;
    }
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
    if (front==NULL) {

    }
    else {
        front = front->link;;
    }

}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

    /* Your code here */

    /* Use the following out command for the data */
    if (front != NULL) {
        struct node *ptr;
        ptr = (node *) malloc(sizeof(node));
        ptr = front;
        std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
        while (ptr->link != NULL) {
            ptr = front->link;
            std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
        }
    }




}
