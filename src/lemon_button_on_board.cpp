#ifndef __HONEYLemon_BUTTON_ON_BOARD_CPP__
#define __HONEYLemon_BUTTON_ON_BOARD_CPP__

#include "HONEYLemon.h"

/* Button Function */
void HONEYLemon::onClick(voidCb_t cb) {
	this->_user_btn_on_click_cb = cb;
}
void HONEYLemon::onLongClick(voidCb_t cb) {
	this->_user_btn_on_long_click_cb = cb;
}
void HONEYLemon::onDoubleClick(voidCb_t cb) {
	this->_user_btn_on_double_click_cb = cb;
}

#endif