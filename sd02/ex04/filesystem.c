#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

FSNode *create_node(const char *name, int size, NodeType type)
{
	FSNode* node= (FSNode *)malloc(sizeof(FSNode));
	node->name = strdup(name);
	node->size = size;
	node->type = type;
	node->parent = NULL;
	node->first_child = NULL;
	node->next_sibling = NULL;
	return node;
}


FSNode *create_file(const char *name, int size)
{
	return create_node(name, size, FILE_TYPE);
}

FSNode *create_folder(const char *name)
{
	return create_node(name, 0, FOLDER_TYPE);
}

void add_children(FSNode *parent, FSNode *child)
{
	if (parent == NULL || child == NULL)
		return ;
	child->parent = parent;
	if(parent->first_child == NULL)
		parent->first_child = child;
	else
	{
		FSNode *sibling = parent->first_child;
		while (sibling->next_sibling != NULL)
			sibling = sibling->next_sibling;
		sibling->next_sibling = child;
	}
}

FSNode *get_children(const FSNode *parent)
{
	if(parent == NULL)
		return NULL;
	return parent->next_sibling;
}

FSNode *get_sibiling(const FSNode *node)
{
	if (node == NULL)
		return NULL;
	return node->next_sibling;
}

//void free_node(FSNode* root)
//{
//	if (node == NULL)
//		return;
//	free(node->name);
//	free(node);
//}
//
//void free_tree(FSNode *root)
//{
//	if (root == NULL)
//		return;
//	FSNode *child = root->first_child;
//	while (child != NULL)
//	{
//		FSNode *next = child->next_sibling;
//		free_tree(child);
//		child = next;
//	}
//	free_node(root);
//}
