/*
 * Copyright (c) 2012 Bjørn Forsman
 *
 * This file is part of fgui which is released under the MIT license. See
 * LICENSE.txt or go to http://www.opensource.org/licenses/MIT for full
 * license text.
 */

#include <stdint.h>
#include <string.h>

#include "fgui_label.h"
#include "fgui_font.h"

#define LABEL_TEXT_COLOR 0


int fgui_label_init(struct fgui_label *label, uint16_t x, uint16_t y, const
		const char *text, struct fgui_widget *parent)
{
	int ret;

	ret = fgui_widget_init((struct fgui_widget *)label, parent);
	if (ret != 0) {
		return -1;
	}

	label->base.focus_policy = FGUI_NO_FOCUS;
	label->base.x = x;
	label->base.y = y;
	fgui_label_set_text(label, text);
	return 0;
}

void fgui_label_set_text(struct fgui_label *label, const char *text)
{
	strncpy(label->text, text, sizeof label->text);
	label->text[sizeof label->text - 1] = '\0';
}

void fgui_label_draw(struct fgui_widget *widget)
{
	struct fgui_label *label = (struct fgui_label *)widget;
	fgui_draw_string(label->text, label->base.x, label->base.y, LABEL_TEXT_COLOR);
}
