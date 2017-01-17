/*
 * Copyright 2017 Haiku, Inc.
 * Distributed under the terms of the MIT License.
 *
 * Author:
 *		Marcin 'Shard' Konicki
 *		Owen Pan <owen.pan@yahoo.com>
 */

#ifndef DEMO_VIEW_H
#define DEMO_VIEW_H

#include <Region.h>
#include <View.h>
#include <Window.h>

const int32 WMM_MSG_SET_RADIUS = 'WSrd';
const int32 WMM_MSG_SET_CIRCLES = 'WScr';
const int32 WMM_MSG_SET_LWIDTH = 'WSlw';
const int32 WMM_MSG_SET_LSPACE = 'WSls';
const int32 WMM_MSG_SET_PULSE = 'WSpl';

const int32 WMM_ALPHA_MIN = 55;

struct WMM_SETTINGS
{
	int32		radius;
	int32		circles;
	int32		lwidth;
	int32		lspace;
	int32		pulse;
	rgb_color	color;
};

class DemoView : public BView
{
	public:
						DemoView();
						~DemoView();
		void			AttachedToWindow();
		void			Draw(BRect updateRect);
		void			MessageReceived(BMessage *msg);
		void			Pulse();
		int32			radius() const { return Settings.radius; }
		int32			circles() const { return Settings.circles; }
		int32			lwidth() const { return Settings.lwidth; }
		int32			lspace() const { return Settings.lspace; }
		int32			pulse() const { return Settings.pulse; }
		rgb_color		color() const { return Settings.color; }

	private:
		rgb_color		fColor;
		int32			fCircle;
		int32			fRadius;
		int32			fAlphaMod;
		WMM_SETTINGS	Settings;

		void			ProcMsg(BMessage *msg, int32 &value, int32 factor = 1);
		void			RestartDemo();
		void			InitDemo();
};

void LoadSettings( WMM_SETTINGS *settings);
void SaveSettings( WMM_SETTINGS *settings);

#endif /* DEMO_VIEW_H */