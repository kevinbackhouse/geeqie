/*
 * Copyright (C) 2004 John Ellis
 * Copyright (C) 2008 - 2016 The Geeqie Team
 *
 * Author: John Ellis
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
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef VIEW_FILE_VIEW_FILE_LIST_H
#define VIEW_FILE_VIEW_FILE_LIST_H

#include "filedata.h"

gboolean vflist_press_key_cb(GtkWidget *widget, GdkEventKey *event, gpointer data);
gboolean vflist_press_cb(GtkWidget *widget, GdkEventButton *bevent, gpointer data);
gboolean vflist_release_cb(GtkWidget *widget, GdkEventButton *bevent, gpointer data);

void vflist_dnd_init(ViewFile *vf);

void vflist_destroy_cb(GtkWidget *widget, gpointer data);
ViewFile *vflist_new(ViewFile *vf, FileData *dir_fd);

gboolean vflist_set_fd(ViewFile *vf, FileData *dir_fd);
gboolean vflist_refresh(ViewFile *vf);

void vflist_thumb_set(ViewFile *vf, gboolean enable);
void vflist_marks_set(ViewFile *vf, gboolean enable);
void vflist_star_rating_set(ViewFile *vf, gboolean enable);
void vflist_sort_set(ViewFile *vf, SortType type, gboolean ascend);

GList *vflist_selection_get_one(ViewFile *vf, FileData *fd);
GList *vflist_pop_menu_file_list(ViewFile *vf);
void vflist_pop_menu_view_cb(GtkWidget *widget, gpointer data);
void vflist_pop_menu_rename_cb(GtkWidget *widget, gpointer data);
void vflist_pop_menu_refresh_cb(GtkWidget *widget, gpointer data);
void vflist_popup_destroy_cb(GtkWidget *widget, gpointer data);
void vflist_pop_menu_thumbs_cb(GtkWidget *widget, gpointer data);

FileData *vflist_index_get_data(ViewFile *vf, gint row);
gint vflist_index_by_fd(ViewFile *vf, FileData *fd);
guint vflist_count(ViewFile *vf, gint64 *bytes);
GList *vflist_get_list(ViewFile *vf);

guint vflist_selection_count(ViewFile *vf, gint64 *bytes);
GList *vflist_selection_get_list(ViewFile *vf);
GList *vflist_selection_get_list_by_index(ViewFile *vf);

void vflist_select_all(ViewFile *vf);
void vflist_select_none(ViewFile *vf);
void vflist_select_invert(ViewFile *vf);
void vflist_select_by_fd(ViewFile *vf, FileData *fd);
void vflist_select_list(ViewFile *vf, GList *list);

void vflist_mark_to_selection(ViewFile *vf, gint mark, MarkToSelectionMode mode);
void vflist_selection_to_mark(ViewFile *vf, gint mark, SelectionToMarkMode mode);

void vflist_color_set(ViewFile *vf, FileData *fd, gboolean color_set);

void vflist_thumb_progress_count(GList *list, gint *count, gint *done);
void vflist_read_metadata_progress_count(GList *list, gint *count, gint *done);
void vflist_set_thumb_fd(ViewFile *vf, FileData *fd);
FileData *vflist_thumb_next_fd(ViewFile *vf);
void vflist_thumb_reset_all(ViewFile *vf);
void vflist_pop_menu_show_star_rating_cb(GtkWidget *widget, gpointer data);

FileData *vflist_star_next_fd(ViewFile *vf);
void vflist_set_star_fd(ViewFile *vf, FileData *fd);

#endif
/* vim: set shiftwidth=8 softtabstop=0 cindent cinoptions={1s: */
