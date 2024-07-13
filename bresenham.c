/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:01:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/12 20:47:05 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

void ft_put_line(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int e2;

    printf("Drawing line from (%d, %d) to (%d, %d):\n", x0, y0, x1, y1);
    printf("dx: %d, dy: %d, sx: %d, sy: %d, initial err: %d\n", dx, dy, sx, sy, err);

    while (1) {
        printf("Pixel: (%d, %d), err: %d\n", x0, y0, err);  // Print the current point and error
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main() {
    int x0, y0, x1, y1;

    // Example usage
    x0 = 0; y0 = 0; x1 = 8; y1 = 8;
    ft_put_line(x0, y0, x1, y1);

    return 0;
}

