



#ifndef DATASTRUCTLIST_H
    #define	DATASTRUCTLIST_H

        typedef struct node
        {
            unsigned char data;
            unsigned char index;
            struct node *next;
        }node;

        void add(node **head, unsigned char val, unsigned char index);
        void freelist(node **head);
        int search(node *head, unsigned char val);
        unsigned char searchIndex(node *head, unsigned char val);

#endif	

