/*
 * Copyright (C) 2015 Jared Boone, ShareBrained Technology, Inc.
 *
 * This file is part of PortaPack.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __TPMS_APP_H__
#define __TPMS_APP_H__

#include "ui_console.hpp"
#include "message.hpp"

#include "manchester.hpp"
#include "log_file.hpp"

class TPMSModel {
public:
	TPMSModel();

	ManchesterFormatted on_packet(const TPMSPacketMessage& message);

private:
	LogFile log_file { "tpms.txt" };
};

namespace ui {

class TPMSAppView : public Console {
public:
	void on_show() override;
	void on_hide() override;

private:
	TPMSModel model;

	void log(const ManchesterFormatted& formatted);
};

} /* namespace ui */

#endif/*__TPMS_APP_H__*/
