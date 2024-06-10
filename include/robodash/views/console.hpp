/**
 * @file console.hpp
 * @brief Robodash Console
 * @ingroup console
 */

#pragma once
#include "robodash/api.h"
#include <sstream>
#include <string>

namespace rd {

/**
 * @defgroup console Console
 * @brief A console for debugging
 * @image html console.png
 *
 * A GUI console for debugging. Emulates a standard console output.
 */

/**
 * @brief Console class
 * @ingroup console
 */
class Console {
	/// @addtogroup console
	/// @{

	/// @name Console Functions
  private:
	rd_view_t *view;

	lv_obj_t *output;
	lv_obj_t *output_cont;
	std::ostringstream stream;

  public:
	/**
	 * @brief Create a new Console
	 *
	 * @param name Name to display on screen
	 */
	Console(std::string name = "Console");

	/**
	 * @brief Clear all console lines
	 */
	void clear();

	/**
	 * @brief Print to the console
	 *
	 * @param str String to print to console
	 */
	void print(std::string str);

	/**
	 * @brief Print to the console with a newline
	 *
	 * @param str String to print to console
	 */
	void println(std::string str);

	/**
	 * @brief Print a formatted string to the console
	 *
	 * @tparam Params
	 * @param fmt Format string
	 * @param args Args for format string
	 */
	template <typename... Params>
	void printf(std::string fmt, Params... args) {
		char fstr[sizeof(fmt) + sizeof...(args)];
		sprintf(fstr, fmt.c_str(), args...);
		print(fstr);
	}

	/**
	 * @brief Set this view to the active view
	 */
	void focus();

	/// @}
};

} // namespace rd