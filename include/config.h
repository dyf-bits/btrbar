/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmajustus <julmajustus@tutanota.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:25:41 by julmajustus       #+#    #+#             */
/*   Updated: 2025/08/08 20:51:22 by julmajustus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
#define CONFIG_H

#include "blocks.h"
// Bar dimensions 0 width = monitor width
#define BAR_WIDTH			0
#define BAR_HEIGHT			30

// convert RGBA to ARGB
#define RGBA(value) (((value & 0xff) << 24) | (value >> 8))

// charcoal colors
#define CHARC_DARK0 0x1b160dff
#define CHARC_DARK 0x120f09ff
#define CHARC_DARK2 0x1f1a0fff
#define CHARC_LIGHT1 0xd6b891ff
#define CHARC_LIGHT2 0xc0a179ff
#define CHARC_LIGHT3 0xa08561ff
#define CHARC_LIGHT4 0x66553fff

// Bar colors 0xARGB
//#define BG_COLOR			0xff0a0d0f
//#define FG_COLOR			0xffbbbbbb
//#define BG_COLOR			CHARC_DARK
//#define BG_COLOR			RGBA_TO_ARGB(0xff120f09)
#define BG_COLOR			RGBA(CHARC_DARK0)
#define FG_COLOR			RGBA(CHARC_LIGHT1)
#define L_GREEN				0xff82df94
#define GREEN				0xff00ff44
#define GREY				0xff343a40
#define CYAN				0xff9ee9ea
#define PURPLE				0xffe49186
#define PINK				0xffff22aa

// Enable builtin blocks
#define IPC					1
#define LAYOUT				1
#define TITLE				1
#define TAGS				1
#define TRAY				1

// Tags config
//#define TAG_FG_ACTIVE   	0xff9ee0ea
//#define TAG_FG_OCCUPIED 	0xffbbbbbb
//#define TAG_FG_EMPTY    	0xff343a40
#define TAG_FG_ACTIVE   	RGBA(CHARC_LIGHT1)
#define TAG_FG_OCCUPIED 	RGBA(CHARC_LIGHT2)
#define TAG_FG_EMPTY    	RGBA(CHARC_LIGHT4)
#define TAG_FG_URGENT   	0xffE49186
#define TAG_BG_COLOR    	0xff0a0d0f
#define TAG_ICON_PADDING	14
#define TAG_WIDTH			24

static const char * const tag_icons[] = {
	"1",
	"2",
	"3",
	"4",
	"5",
	"6"
};

// Tray config

#define TRAY_ICON_PADDING	6
#define TRAY_MENU_W			200
// center 0, top_left 1, top_right 3
#define TRAY_MENU_LOCATION	3
#define TRAY_MENU_BG_COLOR	0xff0a0d0f
#define TRAY_MENU_HOVER_BG_COLOR	0xff0a6f0f
#define TRAY_MENU_FG_COLOR	0xffbbbbbb
#define TRAY_MENU_DISABLED_FG_COLOR 0xffE49186

// Font
//#define FONT "/home/ad/.local/share/fonts/b/BitstromWeraNerdFont_Regular.ttf"
#define FONT "/usr/share/fonts/TTF/UbuntuNerdFont-Regular.ttf"
// Fontsize
#define F_SIZE				20

// Padding between blocks px
//#define BLOCK_PADDING		4
#define BLOCK_PADDING		8
// Screen edge padding px
#define EDGE_PADDING		8

/* Block config 
 * 
 * Order of the block's in the array equals the draw order.
 * Keep the block cfg order from top to bottom as LEFT -> CENTER -> RIGHT.*/
static const block_cfg_t blocks_cfg[] = {
	// Leftside
	{
		BLK_TAG,			/*type*/
		"",					/*cmd*/
		"",					/*prefix*/
		NULL,				/*builtin function*/
		0,					/*pfx color*/
		0,					/*fg color*/
		0,					/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_LEFT,			/*align*/
		0,					/*update interval s*/
	},

	{
		BLK_LAYOUT,			/*type*/
		"",					/*cmd*/
		"",					/*prefix*/
		NULL,				/*builtin function*/
		0,					/*pfx color*/
		RGBA(CHARC_LIGHT2),				/*fg color*/
		BG_COLOR,			/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_LEFT,			/*align*/
		0,					/*update interval s*/
	},

	{
		BLK_TITLE,			/*type*/
		"",					/*cmd*/
		"",					/*prefix*/
		NULL,				/*builtin function*/
		0,					/*pfx color*/
		RGBA(CHARC_LIGHT1),			/*fg color*/
		BG_COLOR,			/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_LEFT,			/*align*/
		0,					/*update interval s*/
	},
	// Center

	// Right side
	{
		BLK_FUNC,			/*type*/
		NULL,				/*cmd*/
		" ",				/*prefix*/
		cpu_usage,			/*builtin function*/
		RGBA(CHARC_LIGHT2),			/*pfx color*/
		FG_COLOR,			/*fg color*/
		BG_COLOR,			/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_RIGHT,		/*align*/
		1,	  				/*update interval s*/
	},

	{
		BLK_TEMP,			/*type*/
		"/sys/class/hwmon/hwmon5/temp1_input", /*cmd*/
		" ",				/*prefix*/
		NULL,				/*builtin function*/
		RGBA(CHARC_LIGHT3),			/*pfx color*/
		FG_COLOR,			/*fg color*/
		BG_COLOR,			/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_RIGHT,		/*align*/
		10,					/*update interval s*/
	},

	{
		BLK_FUNC,			/*type*/
		NULL,				/*cmd*/
		" ",				/*prefix*/
		mem_usage_simple,	/*builtin function*/
		RGBA(CHARC_LIGHT2),			/*pfx color*/
		FG_COLOR,			/*fg color*/
		BG_COLOR,			/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_RIGHT,		/*align*/
		60,					/*update interval s*/
	},

	{
    //for alsa, use this:
    //BLK_SCRIPT,
    //"amixer get Master | sed -n 's/.*\\[\\([0-9]\\+%*\\)\\].*/\\1/p' | head -n1",
		BLK_VOL,			/*type*/
		"wpctl get-volume @DEFAULT_AUDIO_SINK@ | tr -d 'Volume: '", /*cmd*/
		"  ",				/*prefix*/
		NULL,				/*builtin function*/
		RGBA(CHARC_LIGHT3),			/*pfx color*/
		FG_COLOR,			/*fg color*/
		BG_COLOR,			/*bg color*/
		vol_click,			/*on click*/
		vol_scroll,			/*on click*/
		ALIGN_RIGHT,		/*align*/
		50,					/*update interval s*/
	},

	{
		BLK_FUNC,			/*type*/
		NULL,				/*cmd*/
		" ",				/*prefix*/
		_clock,				/*builtin function*/
		RGBA(CHARC_LIGHT2),				/*pfx color*/
		FG_COLOR,			/*fg color*/
		BG_COLOR,			/*bg color*/
		clock_click,		/*on click*/
		NULL,				/*on scroll*/
		ALIGN_RIGHT,		/*align*/
		30,					/*update interval s*/
	},

	{
		BLK_TRAY,			/*type*/
		"",					/*cmd*/
		"",					/*prefix*/
		NULL,				/*builtin function*/
		0,					/*pfx color*/
		0,					/*fg color*/
		BG_COLOR,			/*bg color*/
		NULL,				/*on click*/
		NULL,				/*on scroll*/
		ALIGN_RIGHT,		/*align*/
		0,					/*update interval s*/
	},

};

#endif
