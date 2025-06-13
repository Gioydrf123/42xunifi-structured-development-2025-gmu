#ifndef FILESYSTEM_H
#define FILESYSTEM_H

typedef enum {FILE_TYPE, FOLDER_TYPE} NodeType;

typedef struct FSNode
{
	char *name;
	int size;
	NodeType type;
	struct FSNode *parent;
	struct FSNode *first_child;
	struct FSNode *next_sibling;
} FSNode;

#endif
