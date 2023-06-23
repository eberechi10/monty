#include "monty.h"

#include <stdio.h>

/**
 * free_list - funct to free the linked list.
 *
 * @head: head of the list.
 *
 * Return: it returns nothing.
 */
void free_list(stack_t *head)
{
	stack_t *elm;

	while ((elm = head) != NULL)
	{
		head = head->next;
		free(elm);
	}
}


/**
 * add_last_node_stack - funct to add node to end of the link list.
 *
 * @head: the linked list head
 * @n: the node.
 *
 * Return: it returns the linked list.
 */
stack_t *add_last_node_stack(stack_t **head, const int n)
{
	stack_t *elm, *new;

	if (head == NULL)
		return (NULL);
	elm = malloc(sizeof(stack_t));
	if (!elm)
	{
		fprintf(stderr, "Error: malloc failed\n");
		reles_mtys();
		exit(EXIT_FAILURE);
	}
	elm->n = n;

	if (*head == NULL)
	{
		elm->next = *head;
		elm->prev = NULL;
		*head = elm;
		return (*head);
	}
	new = *head;
	while (new->next)
		new = new->next;
	elm->next = new->next;
	elm->prev = new;
	new->next = elm;
	return (new->next);
}

/**
 * add_start_node - funct to add node to start of the link list.
 *
 * @head: the start of linked list.
 * @n: the node.
 *
 * Return: it returns linked list.
 */
stack_t *add_start_node(stack_t **head, const int n)
{
	stack_t *elm;

	if (head == NULL)
		return (NULL);

	elm = malloc(sizeof(stack_t));
	if (!elm)
	{
		fprintf(stderr, "Error: malloc failed\n");
		reles_mtys();
		exit(EXIT_FAILURE);
	}
	elm->n = n;

	if (*head == NULL)
	{
		elm->next = *head;
		elm->prev = NULL;
		*head = elm;
		return (*head);
	}
	(*head)->prev = elm;
	elm->next = (*head);
	elm->prev = NULL;
	*head = elm;
	return (*head);
}

