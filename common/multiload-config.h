/*
 * Copyright (C) 2016 Mario Cianciolo <mr.udda@gmail.com>
 *                    The Free Software Foundation
 *
 * This file is part of multiload-ng.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */


#ifndef __MULTILOAD_CONFIG_H__
#define __MULTILOAD_CONFIG_H__

#include <glib.h>
#include <glib/gi18n-lib.h>

#include "multiload.h"


G_BEGIN_DECLS

typedef void (*LoadGraphDataFunc) (int, int [], LoadGraph *);

typedef struct _GraphType {
	const char *name;
	const char *label_interactive;
	const char *label_noninteractive;
	LoadGraphDataFunc get_data;
	guint num_colors;
	const struct {
		const char *label_interactive;
		const char *label_noninteractive;
		const char *default_value;
	} colors[MAX_COLORS];
} GraphType;


// global variable
GraphType graph_types[GRAPH_MAX];


G_GNUC_INTERNAL guint
multiload_config_get_num_colors(guint id);
G_GNUC_INTERNAL guint
multiload_config_get_num_data(guint id);
G_GNUC_INTERNAL void
multiload_config_init();

G_END_DECLS


#endif /* __MULTILOAD_CONFIG_H__ */
