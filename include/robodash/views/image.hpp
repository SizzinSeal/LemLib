/**
 * @file image.hpp
 * @brief Robodash Image
 * @ingroup image
 */

#pragma once
#include "robodash/api.h"
#include <string>

namespace rd {

/**
 * @defgroup image Image
 * @brief An image display
 * @note All images must be converted using LVGL's online image converter
 * tool. (https://lvgl.io/tools/imageconverter)
 * @warning Images should be converted into an indexed color format for
 * performance. CF_INDEXED_4_BIT or CF_INDEXED_8_BIT is reccomended for
 * color images.
 *
 * @image html image.png
 *
 * Displays still images from an SD card or C array.
 */

/**
 * @brief Image class
 * @ingroup image
 */
class Image {
	/// @addtogroup image
	/// @{

	/// @name Image Functions
  private:
	rd_view_t *view;

  public:
	/**
	 * @brief Create a new Image
	 *
	 * @param path File path to the binary-formatted image on SD card
	 * @param name Name to display on screen
	 */
	Image(std::string path, std::string name = "Image");

	/**
	 * @brief Create a new Image
	 *
	 * @param image_dsc LVGL image descriptor object
	 * @param name Name to display on screen
	 */
	Image(lv_img_dsc_t image_dsc, std::string name = "Image");

	/**
	 * @brief Set this view to the active view
	 */
	void focus();

	/// @}
};

} // namespace rd
