/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MM1_VIEWS_ENH_YES_NO_H
#define MM1_VIEWS_ENH_YES_NO_H

#include "mm/mm1/views_enh/scroll_view.h"
#include "mm/shared/xeen/sprites.h"

namespace MM {
namespace MM1 {
namespace ViewsEnh {

class YesNoSubview : public ScrollView {
public:
	YesNoSubview();
	virtual ~YesNoSubview() {}

	bool msgKeypress(const KeypressMessage &msg) override;
};

class YesNo : public ScrollView {
private:
	YesNoSubview _subview;
	bool _subviewVisible = false;

protected:
	/**
	 * Start displaying the yes/no subview
	 */
	void openYesNo() {
		_subviewVisible = true;
		redraw();
	}

	/**
	 * Stop displaying the subview
	 */
	void closeYesNo() {
		_subviewVisible = false;
		redraw();
	}

public:
	YesNo(const Common::String &name) : ScrollView(name) {}
	virtual ~YesNo() {}

	void draw() override;
	bool msgMouseDown(const MouseDownMessage &msg) override;
	bool msgMouseUp(const MouseUpMessage &msg) override;
};

} // namespace ViewsEnh
} // namespace MM1
} // namespace MM

#endif
