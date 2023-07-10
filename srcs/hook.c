#include "../includes/fractol.h"

int	key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 50) // Touche '2' pour modifier la couleur en 2050
		data->color = 2050;
	else if (keycode == 51) // Touche '3' pour modifier la couleur en 265
		data->color = 265;
	else if (keycode == 52)
		// Touche '4' pour activer/désactiver le mode "julia_mouse"
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 53)
		// Touche '5' pour activer/désactiver l'affichage du texte
		data->show_text = !data->show_text;
	return (0);
}

int	key_hook(int keycode, t_fractol *data)
{
	if (keycode == 27) // Touche 'Escape' pour quitter le programme
		exit(1);
	else if (keycode == 43)
		// Touche '+' pour augmenter la valeur de data->it_max de 50
		data->it_max += 50;
	else if (keycode == 110)
		// Touche '-' pour diminuer la valeur de data->it_max de 50
		data->it_max -= 50;
	else if (keycode == 39) // Touche '<-' pour déplacer data->x1 vers la gauche
		data->x1 -= 30 / data->zoom;
	else if (keycode == 37) // Touche '->' pour déplacer data->x1 vers la droite
		data->x1 += 30 / data->zoom;
	else if (keycode == 40)
		// Touche 'fleceh bas' pour déplacer data->y1 vers le bas
		data->y1 += 30 / data->zoom;
	else if (keycode == 38) // Touche '^' pour déplacer data->y1 vers le haut
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49) // Touche '1' pour réinitialiser le fractal
		fract_init(data);
	else if (keycode == 89) // Touche 'y' pour modifier la couleur en 1677216
		data->color = 1677216;
	key_hook2(keycode, data);
	fract_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, data);
	fract_calc(data);
	return (0);
}
