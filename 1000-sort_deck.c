#include "deck.h"

int compe_str(const char *first, const char *second);
char accept_urg(deck_node_t *card);
void insert_sdk(deck_node_t **deck);
void insertion_sdk_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * compe_str - Compares two strings.
 * @first: The first string to be compared.
 * @second: The second string to be compared.
 * Return: Positive byte difference if first > second
 *         0 if first == second
 *         Negative byte difference if first < second
 */

int compe_str(const char *first, const char *second)
{
	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	if (*first != *second)
		return (*first - *second);
	return (0);
}

/**
 * accept_urg - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 * Return: The numerical value of the card.
 */

char accept_urg(deck_node_t *card)
{
	if (compe_str(card->card->value, "Ace") == 0)
		return (0);
	if (compe_str(card->card->value, "1") == 0)
		return (1);
	if (compe_str(card->card->value, "2") == 0)
		return (2);
	if (compe_str(card->card->value, "3") == 0)
		return (3);
	if (compe_str(card->card->value, "4") == 0)
		return (4);
	if (compe_str(card->card->value, "5") == 0)
		return (5);
	if (compe_str(card->card->value, "6") == 0)
		return (6);
	if (compe_str(card->card->value, "7") == 0)
		return (7);
	if (compe_str(card->card->value, "8") == 0)
		return (8);
	if (compe_str(card->card->value, "9") == 0)
		return (9);
	if (compe_str(card->card->value, "10") == 0)
		return (10);
	if (compe_str(card->card->value, "Jack") == 0)
		return (11);
	if (compe_str(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_sdk - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */

void insert_sdk(deck_node_t **deck)
{
	deck_node_t *inter, *inset, *holder;

	for (inter = (*deck)->next; inter != NULL; inter = holder)
	{
		holder = inter->next;
		inset = inter->prev;
		while (inset != NULL && inset->card->kind > inter->card->kind)
		{
			inset->next = inter->next;
			if (inter->next != NULL)
				inter->next->prev = inset;
			inter->prev = inset->prev;
			inter->next = inset;
			if (inset->prev != NULL)
				inset->prev->next = inter;
			else
				*deck = inter;
			inset->prev = inter;
			inset = inter->prev;
		}
	}
}

/**
 * insertion_sdk_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */

void insertion_sdk_value(deck_node_t **deck)
{
	deck_node_t *inter, *inset, *holder;

	for (inter = (*deck)->next; inter != NULL; inter = holder)
	{
		holder = inter->next;
		inset = inter->prev;
		while (inset != NULL &&
		       inset->card->kind == inter->card->kind &&
		       accept_urg(inset) > accept_urg(inter))
		{
			inset->next = inter->next;
			if (inter->next != NULL)
				inter->next->prev = inset;
			inter->prev = inset->prev;
			inter->next = inset;
			if (inset->prev != NULL)
				inset->prev->next = inter;
			else
				*deck = inter;
			inset->prev = inter;
			inset = inter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insert_sdk(deck);
	insertion_sdk_value(deck);
}