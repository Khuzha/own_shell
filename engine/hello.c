#include "../headers/engine.h"

int	main(int argc, const char **argv)
{
	char str[210];
	int l;
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, TERM_TITLE);

	while(strcmp(str, "\4"))
	{
		tputs(save_cursor, 1, ft_putchar);
		do
		{
			l = read(0, str, 21);
			str[l] = '\0';
			if (!strcmp("\e[A", str))
			{
				tputs(restore_cursor, 1, ft_putchar);
				tputs(tigetstr("ed"), 1, ft_putchar);
				ft_putstr_fd("prev", 1);
			}
			else if (!strcmp("\e[B", str))
			{
				tputs(restore_cursor, 1, ft_putchar);
				tputs(tigetstr("ed"), 1, ft_putchar);
				ft_putstr_fd("next", 2);
			}
			else if (!strcmp(str, key_backspace) || !strcmp(str, "\177"))
			{
				tputs(cursor_left, 1, ft_putchar);
				tputs(tgetstr("dc", 0), 1, ft_putchar);
			}
			else
				write(1, str, l);
		} while(strcmp("\n", str) && strcmp("\4", str));
	}

	argc++;
	argv++;
	return 0;
}