#include "shell.h"

/**
 * _myenv - print the current environment
 * @info: Structure containing important arguments. Which are used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_f *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - get value of the environ variable.
 * @info: Structure contains important arguments. Which are used to maintain constant var
 * @name: envi var name
 *
 * Return: the value
 */
char *_getenv(info_f *info, const char *name)
{
	list_f *node = info->env;
	char *c;

	while (node)
	{
		c = starts_with(node->str, name);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initializes the new environment variable,
 *             or modify existing ones
 * @info: Structure containing important arguments. Which are used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_f *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove environment variable
 * @info: Structure containing important arguments. Which are used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_f *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populate env linked list
 * @info: Structure containing important arguments. Which are used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_f *info)
{
	list_f *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}
